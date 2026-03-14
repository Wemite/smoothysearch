#[cxx_qt::bridge]
mod ffi {
    unsafe extern "C++" {
        include!("cxx-qt-lib/qstring.h");
        type QString = cxx_qt_lib::QString;

        include!("smoothysearch/qt_url_opener.h");
        fn open_url_with_activation(url: &QString) -> bool;

        include!("cxx-qt-lib/qstringlist.h");
        type QStringList = cxx_qt_lib::QStringList;
    }

    extern "RustQt" {
        #[qobject]
        #[qml_element]
        #[qproperty(QString, current_text)]
        #[qproperty(QStringList, items)]
        #[qproperty(QStringList, icon_paths)]
        #[qproperty(QStringList, preview_colors)]
        #[qproperty(i32, current_index)]
        #[qproperty(bool, is_themes_mode)]
        #[qproperty(QString, theme_window_bg)]
        #[qproperty(QString, theme_border)]
        #[qproperty(QString, theme_input_bg)]
        #[qproperty(QString, theme_text)]
        #[qproperty(QString, theme_text_dim)]
        #[qproperty(QString, theme_highlight)]
        #[qproperty(QString, theme_highlight_text)]
        #[qproperty(QString, applied_theme_id)]
        #[qproperty(bool, editor_open)]
        #[qproperty(QString, themes_file_text)]
        #[qproperty(i32, window_width)]
        #[qproperty(i32, window_height)]
        #[qproperty(i32, window_editor_width)]
        #[qproperty(i32, ui_window_radius)]
        #[qproperty(i32, ui_search_bar_radius)]
        #[qproperty(i32, ui_selector_radius)]
        #[qproperty(bool, resident_mode)]
        #[qproperty(bool, editor_is_config)]
        type Backend = super::BackendRust;

        #[qinvokable]
        fn set_query(self: Pin<&mut Backend>, value: QString);

        #[qinvokable]
        fn move_down(self: Pin<&mut Backend>);

        #[qinvokable]
        fn move_up(self: Pin<&mut Backend>);

        #[qinvokable]
        fn select_index(self: Pin<&mut Backend>, index: i32);

        #[qinvokable]
        fn launch_current(self: Pin<&mut Backend>);

        #[qinvokable]
        fn is_applied_theme_index(self: &Backend, index: i32) -> bool;

        #[qinvokable]
        fn is_search_index(self: &Backend, index: i32) -> bool;

        #[qinvokable]
        fn toggle_editor(self: Pin<&mut Backend>);

        #[qinvokable]
        fn load_themes_file(self: Pin<&mut Backend>);

        #[qinvokable]
        fn save_themes_file(self: Pin<&mut Backend>);

        #[qinvokable]
        fn poll_resident_command(self: Pin<&mut Backend>) -> i32;

        #[qinvokable]
        fn save_selected_theme(self: Pin<&mut Backend>);

        #[qinvokable]
        fn set_editor_file(self: Pin<&mut Backend>, is_config: bool);
    }

    impl cxx_qt::Initialize for Backend {}
}

use crate::config::{config_path, ensure_default_config_exists, load_config, save_theme_preset};
use crate::theme::{
    all_theme_ids, ensure_sample_themes_file_exists, get_theme_preset, load_custom_themes,
    theme_display_name, themes_path,
};
use cxx_qt::{CxxQtType, Initialize};
use cxx_qt_lib::{QString, QStringList};
use fuzzy_matcher::skim::SkimMatcherV2;
use fuzzy_matcher::FuzzyMatcher;
use serde::{Deserialize, Serialize};
use std::collections::HashMap;
use std::fs;
use std::os::unix::net::UnixStream;
use std::path::{Path, PathBuf};
use std::pin::Pin;
use std::process::{Command, Stdio};
use std::sync::OnceLock;
use std::thread;
use std::time::{Duration, SystemTime, UNIX_EPOCH};

#[derive(Clone, Copy, Debug, PartialEq, Eq)]
enum AppMode {
    Apps,
    Themes,
}

#[derive(Clone, Debug, Serialize, Deserialize)]
struct AppItem {
    name: String,
    name_lower: String,
    exec: String,
    terminal: bool,
    icon_path: String,
}

#[derive(Clone, Debug)]
enum EntryItem {
    App(AppItem),
    Theme { id: String, name: String },
    InternetSearch,
    ExecCommand,
}

#[derive(Clone, Debug, Serialize, Deserialize, PartialEq, Eq)]
struct FileSignature {
    path: String,
    mtime_ns: u128,
    size: u64,
}

#[derive(Debug, Serialize, Deserialize)]
struct CacheData {
    signatures: Vec<FileSignature>,
    apps: Vec<AppItem>,
}

#[derive(Default)]
pub struct BackendRust {
    current_text: QString,
    items: QStringList,
    icon_paths: QStringList,
    preview_colors: QStringList,
    current_index: i32,
    is_themes_mode: bool,
    theme_window_bg: QString,
    theme_border: QString,
    theme_input_bg: QString,
    theme_text: QString,
    theme_text_dim: QString,
    theme_highlight: QString,
    theme_highlight_text: QString,
    applied_theme_id: QString,
    editor_open: bool,
    themes_file_text: QString,
    editor_is_config: bool,

    window_width: i32,
    window_height: i32,
    window_editor_width: i32,

    ui_window_radius: i32,
    ui_search_bar_radius: i32,
    ui_selector_radius: i32,
    resident_mode: bool,

    mode: Option<AppMode>,
    all_apps: Vec<AppItem>,
    filtered_entries: Vec<EntryItem>,
    last_resident_command_mtime_ms: u128,
}

static RESIDENT_LOCK: OnceLock<std::os::unix::net::UnixListener> = OnceLock::new();

const SERVICE_KILL_RETRIES: u32 = 20;
const SERVICE_START_RETRIES: u32 = 40;
const SERVICE_RETRY_DELAY_MS: u64 = 50;

impl BackendRust {
    fn preview_colors_to_qstringlist(entries: &[EntryItem]) -> QStringList {
        let mut list = QStringList::default();

        for entry in entries {
            match entry {
                EntryItem::App(_) | EntryItem::InternetSearch | EntryItem::ExecCommand => {
                    list.append(QString::from(""))
                }
                EntryItem::Theme { id, .. } => {
                    let theme = get_theme_preset(id);
                    list.append(QString::from(theme.highlight.as_str()));
                }
            }
        }

        list
    }

    fn home_dir() -> String {
        std::env::var("HOME").unwrap_or_default()
    }

    fn app_dirs() -> Vec<PathBuf> {
        let home = Self::home_dir();
        vec![
            PathBuf::from(format!("{home}/.local/share/applications")),
            PathBuf::from("/usr/local/share/applications"),
            PathBuf::from("/usr/share/applications"),
            PathBuf::from("/var/lib/flatpak/exports/share/applications"),
            PathBuf::from(format!(
                "{home}/.local/share/flatpak/exports/share/applications"
            )),
        ]
    }

    fn cache_dir() -> PathBuf {
        let home = Self::home_dir();
        PathBuf::from(format!("{home}/.cache/smoothysearch"))
    }

    fn cache_file() -> PathBuf {
        Self::cache_dir().join("apps_cache.json")
    }

    fn resident_socket_file() -> PathBuf {
        Self::cache_dir().join("resident.sock")
    }

    fn resident_command_file() -> PathBuf {
        Self::cache_dir().join("resident_command.txt")
    }

    fn now_ms() -> u128 {
        SystemTime::now()
            .duration_since(UNIX_EPOCH)
            .map(|d| d.as_millis())
            .unwrap_or(0)
    }

    fn command_file_mtime_ms(path: &Path) -> u128 {
        fs::metadata(path)
            .ok()
            .and_then(|m| m.modified().ok())
            .and_then(|t| t.duration_since(UNIX_EPOCH).ok())
            .map(|d| d.as_millis())
            .unwrap_or(0)
    }

    fn is_resident_mode() -> bool {
        std::env::args().any(|arg| arg == "--service")
    }

    fn current_exe_path() -> Option<PathBuf> {
        std::env::current_exe().ok()
    }

    fn file_mtime_ms(path: &Path) -> u128 {
        fs::metadata(path)
            .ok()
            .and_then(|m| m.modified().ok())
            .and_then(|t| t.duration_since(UNIX_EPOCH).ok())
            .map(|d| d.as_millis())
            .unwrap_or(0)
    }

    fn write_resident_command(command: &str) {
        let dir = Self::cache_dir();
        let _ = fs::create_dir_all(&dir);

        let exe_mtime = Self::current_exe_path()
            .map(|p| Self::file_mtime_ms(&p))
            .unwrap_or(0);

        let payload = format!("{}\n{}\n{}\n", command, exe_mtime, Self::now_ms());
        let _ = fs::write(Self::resident_command_file(), payload);
    }

    fn service_binary_is_stale() -> bool {
        let Some(exe) = Self::current_exe_path() else {
            return false;
        };

        let exe_mtime = Self::file_mtime_ms(&exe);
        if exe_mtime == 0 {
            return false;
        }

        let content = match fs::read_to_string(Self::resident_command_file()) {
            Ok(v) => v,
            Err(_) => return false,
        };

        let mut lines = content.lines();
        let _command = lines.next();
        let Some(service_exe_mtime_line) = lines.next() else {
            return false;
        };

        let Ok(service_exe_mtime) = service_exe_mtime_line.trim().parse::<u128>() else {
            return false;
        };

        service_exe_mtime != exe_mtime
    }

    fn read_resident_command(last_seen_mtime_ms: u128) -> Option<(u128, String)> {
        let path = Self::resident_command_file();
        let mtime = Self::command_file_mtime_ms(&path);
        if mtime == 0 || mtime <= last_seen_mtime_ms {
            return None;
        }

        let content = fs::read_to_string(path).ok()?;
        let command = content.lines().next()?.trim().to_string();
        Some((mtime, command))
    }

    fn themes_file_path() -> Option<PathBuf> {
        themes_path()
    }

    fn clean_exec(exec: &str) -> String {
        let mut out = String::with_capacity(exec.len());
        let mut chars = exec.chars().peekable();

        while let Some(ch) = chars.next() {
            if ch == '%' {
                if let Some(next) = chars.peek().copied() {
                    match next {
                        'f' | 'F' | 'u' | 'U' | 'd' | 'D' | 'n' | 'N' | 'i' | 'c' | 'k' | 'v'
                        | 'm' => {
                            chars.next();
                            continue;
                        }
                        '%' => {
                            out.push('%');
                            chars.next();
                            continue;
                        }
                        _ => {}
                    }
                }
            }

            out.push(ch);
        }

        out.trim().to_string()
    }

    fn parse_bool(value: Option<&String>) -> bool {
        value
            .map(|v| v.trim().eq_ignore_ascii_case("true"))
            .unwrap_or(false)
    }

    fn parse_desktop_file(path: &Path) -> Option<AppItem> {
        let content = fs::read_to_string(path).ok()?;

        let mut in_desktop_entry = false;
        let mut map: HashMap<String, String> = HashMap::new();

        for raw_line in content.lines() {
            let line = raw_line.trim();

            if line.is_empty() || line.starts_with('#') {
                continue;
            }

            if line.starts_with('[') && line.ends_with(']') {
                in_desktop_entry = line == "[Desktop Entry]";
                continue;
            }

            if !in_desktop_entry {
                continue;
            }

            let Some((key, value)) = line.split_once('=') else {
                continue;
            };

            let key = key.trim();
            if key.contains('[') {
                continue;
            }

            map.insert(key.to_string(), value.trim().to_string());
        }

        if map.get("Type").map(|s| s.as_str()) != Some("Application") {
            return None;
        }

        if Self::parse_bool(map.get("NoDisplay")) || Self::parse_bool(map.get("Hidden")) {
            return None;
        }

        let name = map.get("Name")?.trim().to_string();
        let exec = Self::clean_exec(map.get("Exec")?.trim());

        if name.is_empty() || exec.is_empty() {
            return None;
        }

        let terminal = Self::parse_bool(map.get("Terminal"));
        let name_lower = name.to_lowercase();

        Some(AppItem {
            name,
            name_lower,
            exec,
            terminal,
            icon_path: String::new(),
        })
    }

    fn collect_desktop_signatures() -> Vec<FileSignature> {
        let mut signatures = Vec::new();

        for base in Self::app_dirs() {
            if !base.is_dir() {
                continue;
            }

            let Ok(entries) = fs::read_dir(&base) else {
                continue;
            };

            for entry in entries.flatten() {
                let path = entry.path();

                if path.extension().and_then(|e| e.to_str()) != Some("desktop") {
                    continue;
                }

                let Ok(meta) = entry.metadata() else {
                    continue;
                };

                let mtime_ns = meta
                    .modified()
                    .ok()
                    .and_then(|t| t.duration_since(std::time::UNIX_EPOCH).ok())
                    .map(|d| d.as_nanos())
                    .unwrap_or(0);

                signatures.push(FileSignature {
                    path: path.to_string_lossy().to_string(),
                    mtime_ns,
                    size: meta.len(),
                });
            }
        }

        signatures.sort_by(|a, b| a.path.cmp(&b.path));
        signatures
    }

    fn read_cache() -> Option<CacheData> {
        let path = Self::cache_file();
        let content = fs::read_to_string(path).ok()?;
        match serde_json::from_str(&content) {
            Ok(cache) => Some(cache),
            Err(e) => {
                eprintln!("[smoothysearch] app cache parse error: {e}, will rebuild");
                None
            }
        }
    }

    fn write_cache(signatures: Vec<FileSignature>, apps: &[AppItem]) {
        let cache = CacheData {
            signatures,
            apps: apps.to_vec(),
        };

        let Ok(json) = serde_json::to_string(&cache) else {
            return;
        };

        let dir = Self::cache_dir();
        let _ = fs::create_dir_all(&dir);
        let _ = fs::write(Self::cache_file(), json);
    }

    fn build_apps_from_desktop_files() -> Vec<AppItem> {
        let mut apps_by_name: HashMap<String, AppItem> = HashMap::new();
        let home = Self::home_dir();
        let home_prefix = format!("{home}/");

        for base in Self::app_dirs() {
            if !base.is_dir() {
                continue;
            }

            let Ok(entries) = fs::read_dir(&base) else {
                continue;
            };

            for entry in entries.flatten() {
                let path = entry.path();

                if path.extension().and_then(|e| e.to_str()) != Some("desktop") {
                    continue;
                }

                let Some(app) = Self::parse_desktop_file(&path) else {
                    continue;
                };

                if app.exec.contains("smoothysearch") && !app.exec.contains("--themes") {
                    continue;
                }

                let key = app.name.to_lowercase();
                let prefer_this = !apps_by_name.contains_key(&key)
                    || base.to_string_lossy().starts_with(&home_prefix);

                if prefer_this {
                    apps_by_name.insert(key, app);
                }
            }
        }

        let mut apps: Vec<AppItem> = apps_by_name.into_values().collect();
        apps.sort_by_key(|a| a.name.to_lowercase());
        apps
    }

    fn invalidate_app_cache() {
        let path = Self::cache_file();
        let _ = fs::remove_file(path);
    }

    fn load_desktop_apps() -> Vec<AppItem> {
        let signatures = Self::collect_desktop_signatures();

        if let Some(cache) = Self::read_cache() {
            if cache.signatures == signatures {
                return cache.apps;
            }
        }

        let apps = Self::build_apps_from_desktop_files();
        Self::write_cache(signatures, &apps);
        apps
    }

    fn filter_apps(&self, query: &str) -> Vec<AppItem> {
        let q = query.trim().to_lowercase();

        if q.is_empty() {
            return self.all_apps.clone();
        }

        let matcher = SkimMatcherV2::default();
        let mut scored: Vec<(i64, AppItem)> = Vec::new();

        for app in &self.all_apps {
            let name = &app.name_lower;

            let mut bonus = 0i64;

            if name == &q {
                bonus += 10_000;
            } else if name.starts_with(&q) {
                bonus += 5_000;
            } else if name.contains(&q) {
                bonus += 1_000;
            }

            if let Some(score) = matcher.fuzzy_match(name, &q) {
                scored.push((score + bonus, app.clone()));
            }
        }

        scored.sort_by(|a, b| {
            b.0.cmp(&a.0)
                .then_with(|| a.1.name_lower.cmp(&b.1.name_lower))
        });

        scored.into_iter().map(|(_, app)| app).collect()
    }

    fn filter_themes(&self, query: &str) -> Vec<EntryItem> {
        let q = query.trim().to_lowercase();
        let theme_ids = all_theme_ids();

        let custom_ids: std::collections::HashSet<String> =
            load_custom_themes().into_iter().map(|t| t.id).collect();

        if q.is_empty() {
            let mut items: Vec<EntryItem> = theme_ids
                .iter()
                .map(|id| EntryItem::Theme {
                    id: id.to_string(),
                    name: theme_display_name(id),
                })
                .collect();

            items.sort_by(|a, b| {
                let (a_id, a_name): (&str, &str) = match a {
                    EntryItem::Theme { id, name } => (id.as_str(), name.as_str()),
                    EntryItem::App(app) => (app.name.as_str(), app.name.as_str()),
                    EntryItem::InternetSearch | EntryItem::ExecCommand => ("", ""),
                };

                let (b_id, b_name): (&str, &str) = match b {
                    EntryItem::Theme { id, name } => (id.as_str(), name.as_str()),
                    EntryItem::App(app) => (app.name.as_str(), app.name.as_str()),
                    EntryItem::InternetSearch | EntryItem::ExecCommand => ("", ""),
                };

                let a_user = custom_ids.contains(a_id);
                let b_user = custom_ids.contains(b_id);

                b_user
                    .cmp(&a_user)
                    .then_with(|| a_name.to_lowercase().cmp(&b_name.to_lowercase()))
            });

            return items;
        }

        let matcher = SkimMatcherV2::default();
        let mut scored: Vec<(i64, bool, String, EntryItem)> = Vec::new();

        for id in &theme_ids {
            let display = theme_display_name(id);
            let id_lower = id.to_lowercase();
            let name_lower = display.to_lowercase();

            let mut bonus = 0i64;

            if id_lower == q || name_lower == q {
                bonus += 10_000;
            } else if id_lower.starts_with(&q) || name_lower.starts_with(&q) {
                bonus += 5_000;
            } else if id_lower.contains(&q) || name_lower.contains(&q) {
                bonus += 1_000;
            }

            let score_id = matcher.fuzzy_match(&id_lower, &q);
            let score_name = matcher.fuzzy_match(&name_lower, &q);

            let best_score = match (score_id, score_name) {
                (Some(a), Some(b)) => a.max(b),
                (Some(a), None) => a,
                (None, Some(b)) => b,
                (None, None) => continue,
            };

            let is_custom = custom_ids.contains(id);

            scored.push((
                best_score + bonus,
                is_custom,
                name_lower.clone(),
                EntryItem::Theme {
                    id: id.to_string(),
                    name: display,
                },
            ));
        }

        scored.sort_by(|a, b| {
            b.0.cmp(&a.0)
                .then_with(|| b.1.cmp(&a.1))
                .then_with(|| a.2.cmp(&b.2))
        });

        scored.into_iter().map(|(_, _, _, item)| item).collect()
    }

    fn filter_entries(&self, query: &str) -> Vec<EntryItem> {
        match self.mode.unwrap_or(AppMode::Apps) {
            AppMode::Apps => {
                let apps = self.filter_apps(query);
                if apps.is_empty() && !query.trim().is_empty() {
                    vec![EntryItem::ExecCommand, EntryItem::InternetSearch]
                } else {
                    apps.into_iter().map(EntryItem::App).collect()
                }
            }
            AppMode::Themes => self.filter_themes(query),
        }
    }

    fn entries_to_qstringlist(entries: &[EntryItem]) -> QStringList {
        let mut list = QStringList::default();

        for entry in entries {
            match entry {
                EntryItem::App(app) => list.append(QString::from(app.name.as_str())),
                EntryItem::Theme { name, .. } => list.append(QString::from(name.as_str())),
                EntryItem::InternetSearch => list.append(QString::from("Search")),
                EntryItem::ExecCommand => list.append(QString::from("Exec command")),
            }
        }

        list
    }

    fn icon_paths_to_qstringlist(entries: &[EntryItem]) -> QStringList {
        let mut list = QStringList::default();

        for entry in entries {
            match entry {
                EntryItem::App(app) => list.append(QString::from(app.icon_path.as_str())),
                EntryItem::Theme { .. } | EntryItem::InternetSearch | EntryItem::ExecCommand => {
                    list.append(QString::from(""))
                }
            }
        }

        list
    }

    fn refresh_entries_for_current_mode(
        &mut self,
        query: &str,
    ) -> (QStringList, QStringList, QStringList, i32) {
        let filtered = self.filter_entries(query);
        let items = Self::entries_to_qstringlist(&filtered);
        let icon_paths = Self::icon_paths_to_qstringlist(&filtered);
        let preview_colors = Self::preview_colors_to_qstringlist(&filtered);
        let current_index = if filtered.is_empty() { -1 } else { 0 };
        self.filtered_entries = filtered;
        (items, icon_paths, preview_colors, current_index)
    }

    fn parse_exec_args(exec: &str) -> Vec<String> {
        let mut args: Vec<String> = Vec::new();
        let mut current = String::new();
        let mut in_double_quotes = false;
        let mut chars = exec.chars().peekable();

        while let Some(ch) = chars.next() {
            match ch {
                '"' => in_double_quotes = !in_double_quotes,
                '\\' if in_double_quotes => {
                    if let Some(next) = chars.next() {
                        match next {
                            '"' | '\\' | '`' | '$' => current.push(next),
                            _ => {
                                current.push('\\');
                                current.push(next);
                            }
                        }
                    }
                }
                ' ' | '\t' if !in_double_quotes => {
                    if !current.is_empty() {
                        args.push(std::mem::take(&mut current));
                    }
                }
                _ => current.push(ch),
            }
        }

        if !current.is_empty() {
            args.push(current);
        }

        args
    }

    fn try_center_window_for_pid(pid: u32) {
        thread::spawn(move || {
            const POLL_MS: u64 = 100;
            const MAX_POLLS: u32 = 50;

            if Self::is_in_path("swaymsg") {
                for _ in 0..MAX_POLLS {
                    thread::sleep(Duration::from_millis(POLL_MS));
                    let ok = Command::new("swaymsg")
                        .arg(format!("[pid={}] move position center", pid))
                        .stdout(Stdio::null())
                        .stderr(Stdio::null())
                        .status()
                        .map(|s| s.success())
                        .unwrap_or(false);
                    if ok {
                        return;
                    }
                }
                return;
            }

            if Self::is_in_path("hyprctl") {
                for _ in 0..MAX_POLLS {
                    thread::sleep(Duration::from_millis(POLL_MS));
                    let focused = Command::new("hyprctl")
                        .args(["dispatch", "focuswindow", &format!("pid:{}", pid)])
                        .stdout(Stdio::null())
                        .stderr(Stdio::null())
                        .status()
                        .map(|s| s.success())
                        .unwrap_or(false);
                    if focused {
                        let _ = Command::new("hyprctl")
                            .args(["dispatch", "centerwindow"])
                            .stdout(Stdio::null())
                            .stderr(Stdio::null())
                            .spawn();
                        return;
                    }
                }
                return;
            }
        });
    }

    fn run_shell(command: &str) {
        let home = Self::home_dir();
        let args = Self::parse_exec_args(command);

        if args.is_empty() {
            eprintln!("[smoothysearch] run_shell: empty exec after parsing: {command:?}");
            return;
        }

        if let Ok(child) = Command::new(&args[0])
            .current_dir(&home)
            .args(&args[1..])
            .spawn()
        {
            Self::try_center_window_for_pid(child.id());
        }
    }

    fn is_in_path(name: &str) -> bool {
        if let Ok(path_var) = std::env::var("PATH") {
            for dir in path_var.split(':') {
                if PathBuf::from(dir).join(name).is_file() {
                    return true;
                }
            }
        }
        false
    }

    fn find_desktop_file(name: &str) -> Option<PathBuf> {
        let base = name.trim().trim_end_matches(".desktop");
        let with_ext = if name.ends_with(".desktop") {
            name.to_string()
        } else {
            format!("{}.desktop", base)
        };
        for dir in Self::app_dirs() {
            let path = dir.join(&with_ext);
            if path.is_file() {
                return Some(path);
            }
        }
        None
    }

    fn exec_from_desktop(path: &Path) -> Option<String> {
        let content = fs::read_to_string(path).ok()?;
        let exec_line = content
            .lines()
            .find(|l| l.starts_with("Exec="))?
            .strip_prefix("Exec=")?
            .trim();
        let mut tokens = exec_line.split_whitespace();
        while let Some(t) = tokens.next() {
            if t == "env" {
                continue;
            }
            if t.contains('=') {
                continue;
            }
            let exe = t.trim_matches('"');
            if exe.is_empty() {
                continue;
            }
            if Path::new(exe).is_absolute() {
                return Some(exe.to_string());
            }
            if Self::is_in_path(exe) {
                return Some(exe.to_string());
            }
            return Some(exe.to_string());
        }
        None
    }

    fn read_kdeglobals_terminal(path: &Path) -> Option<(Option<String>, Option<String>)> {
        let content = fs::read_to_string(path).ok()?;
        let mut in_general = false;
        let mut terminal_application = None;
        let mut terminal_service = None;
        for line in content.lines() {
            let line = line.trim();
            if line.starts_with('[') {
                in_general = line.eq_ignore_ascii_case("[General]");
                continue;
            }
            if !in_general {
                continue;
            }
            if let Some(rest) = line.strip_prefix("TerminalApplication=") {
                let v = rest.trim().trim_matches('"');
                if !v.is_empty() {
                    terminal_application = Some(v.to_string());
                }
            }
            if let Some(rest) = line.strip_prefix("TerminalService=") {
                let v = rest.trim().trim_matches('"');
                if !v.is_empty() {
                    terminal_service = Some(v.to_string());
                }
            }
        }
        if terminal_application.is_some() || terminal_service.is_some() {
            Some((terminal_application, terminal_service))
        } else {
            None
        }
    }

    fn default_terminal_kde_from_config() -> Option<String> {
        let home = Self::home_dir();
        let path = PathBuf::from(format!("{}/.config/kdeglobals", home));
        if !path.is_file() {
            return None;
        }
        let (term_app, term_service) = Self::read_kdeglobals_terminal(&path)?;
        if let Some(service) = term_service {
            let desktop_path = Self::find_desktop_file(&service);
            if let Some(ref p) = desktop_path {
                if let Some(exec) = Self::exec_from_desktop(p) {
                    return Some(exec);
                }
            }
        }
        if let Some(app) = term_app {
            let app = app.trim();
            if Path::new(app).is_absolute() {
                if Path::new(app).is_file() {
                    return Some(app.to_string());
                }
                return None;
            }
            if Self::is_in_path(app) {
                return Some(app.to_string());
            }
            return Some(app.to_string());
        }
        None
    }

    fn default_terminal_xdg_list() -> Option<String> {
        let home = Self::home_dir();
        let candidates = [
            format!("{}/.config/xdg-terminals.list", home),
            "/etc/xdg/xdg-terminals.list".to_string(),
        ];
        for path_str in candidates {
            let path = Path::new(&path_str);
            if !path.is_file() {
                continue;
            }
            let content = match fs::read_to_string(path) {
                Ok(c) => c,
                Err(_) => continue,
            };
            for line in content.lines() {
                let line = line.trim();
                if line.is_empty() || line.starts_with('#') {
                    continue;
                }
                let id = line.trim_start_matches('-');
                if let Some(desktop_path) = Self::find_desktop_file(id) {
                    if let Some(exec) = Self::exec_from_desktop(&desktop_path) {
                        return Some(exec);
                    }
                }
            }
        }
        None
    }

    fn default_terminal_gnome() -> Option<String> {
        let out = Command::new("gsettings")
            .args([
                "get",
                "org.gnome.desktop.default-applications.terminal",
                "exec",
            ])
            .output()
            .ok()?;
        if !out.status.success() {
            return None;
        }
        let s = String::from_utf8_lossy(&out.stdout);
        let s = s.trim().trim_matches('\'');
        let exec = s.split_whitespace().next()?;
        if exec.is_empty() {
            return None;
        }
        if Path::new(exec).is_absolute() {
            if Path::new(exec).is_file() {
                return Some(exec.to_string());
            }
            return None;
        }
        if Self::is_in_path(exec) {
            Some(exec.to_string())
        } else {
            None
        }
    }

    fn default_terminal_kde() -> Option<String> {
        for cmd in ["kreadconfig6", "kreadconfig"] {
            let out = Command::new(cmd)
                .args([
                    "--file",
                    "kdeglobals",
                    "--group",
                    "General",
                    "--key",
                    "TerminalApplication",
                ])
                .output()
                .ok()?;
            if !out.status.success() {
                continue;
            }
            let s = String::from_utf8_lossy(&out.stdout);
            let exec = s.trim();
            if exec.is_empty() {
                continue;
            }
            if Path::new(exec).is_absolute() {
                if Path::new(exec).is_file() {
                    return Some(exec.to_string());
                }
                continue;
            }
            if Self::is_in_path(exec) {
                return Some(exec.to_string());
            }
        }
        None
    }

    fn detect_terminal() -> Option<String> {
        if let Ok(term) = std::env::var("TERMINAL") {
            let term = term.trim().to_string();
            if !term.is_empty()
                && (term.contains('/') && Path::new(&term).is_file() || Self::is_in_path(&term))
            {
                return Some(term);
            }
        }

        if let Some(term) = Self::default_terminal_kde_from_config() {
            return Some(term);
        }
        if let Some(term) = Self::default_terminal_kde() {
            return Some(term);
        }
        if let Some(term) = Self::default_terminal_gnome() {
            return Some(term);
        }
        if let Some(term) = Self::default_terminal_xdg_list() {
            return Some(term);
        }
        if Self::is_in_path("xdg-terminal-exec") {
            return Some("xdg-terminal-exec".to_string());
        }
        if Self::is_in_path("x-terminal-emulator") {
            return Some("x-terminal-emulator".to_string());
        }

        let fallbacks = [
            "konsole",
            "gnome-terminal",
            "xfce4-terminal",
            "alacritty",
            "kitty",
            "foot",
            "wezterm",
            "tilix",
        ];
        for name in fallbacks {
            if Self::is_in_path(name) {
                return Some(name.to_string());
            }
        }

        None
    }

    fn terminal_launch_args(terminal: &str, cmd_args: &[String]) -> Vec<String> {
        let name = Path::new(terminal)
            .file_name()
            .and_then(|s| s.to_str())
            .unwrap_or(terminal);
        let mut args: Vec<String> = match name {
            "gnome-terminal" => vec!["--".to_string()],
            "wezterm" => vec!["start".to_string(), "--".to_string()],
            "konsole" => vec!["--hold".to_string(), "-e".to_string()],
            "xdg-terminal-exec" | "kitty" | "foot" => vec![],
            _ => vec!["-e".to_string()],
        };
        args.extend_from_slice(cmd_args);
        args
    }

    fn url_encode_query(s: &str) -> String {
        let mut out = String::with_capacity(s.len());
        for b in s.as_bytes() {
            match *b {
                b'A'..=b'Z' | b'a'..=b'z' | b'0'..=b'9' | b'-' | b'_' | b'.' | b'~' => {
                    out.push(*b as char)
                }
                b' ' => out.push('+'),
                _ => {
                    out.push('%');
                    for &hex in &[b >> 4, b & 15] {
                        out.push(if hex < 10 {
                            b'0' + hex
                        } else {
                            b'A' + hex - 10
                        } as char);
                    }
                }
            }
        }
        out
    }

    fn search_url_for_template(template: &str, encoded_query: &str) -> Option<String> {
        let trimmed = template.trim();
        if trimmed.is_empty() {
            return None;
        }

        if trimmed.contains("%s")
            && (trimmed.starts_with("https://") || trimmed.starts_with("http://"))
        {
            return Some(trimmed.replacen("%s", encoded_query, 1));
        }

        let base = if trimmed.starts_with("https://") || trimmed.starts_with("http://") {
            trimmed.to_string()
        } else {
            format!("https://{}", trimmed)
        };

        let normalized = if base.ends_with('/') {
            base
        } else {
            format!("{}/", base)
        };

        let host = normalized
            .split("://")
            .nth(1)
            .and_then(|rest| rest.split('/').next())
            .map(|value| value.to_ascii_lowercase())?;

        let mapped = if host == "duckduckgo.com" || host.ends_with(".duckduckgo.com") {
            format!("{}?q={}", normalized, encoded_query)
        } else if host == "google.com"
            || host.ends_with(".google.com")
            || host == "google.ru"
            || host.ends_with(".google.ru")
        {
            format!("{}search?q={}", normalized, encoded_query)
        } else if host == "bing.com" || host.ends_with(".bing.com") {
            format!("{}search?q={}", normalized, encoded_query)
        } else if host == "search.brave.com" {
            format!("{}search?q={}", normalized, encoded_query)
        } else if host == "ecosia.org" || host.ends_with(".ecosia.org") {
            format!("{}search?q={}", normalized, encoded_query)
        } else if host == "startpage.com" || host.ends_with(".startpage.com") {
            format!("{}sp/search?query={}", normalized, encoded_query)
        } else if host == "search.yahoo.com" || host.ends_with(".search.yahoo.com") {
            format!("{}search?p={}", normalized, encoded_query)
        } else if host == "yahoo.com" || host.ends_with(".yahoo.com") {
            format!("{}search?p={}", normalized, encoded_query)
        } else if host == "yandex.ru"
            || host.ends_with(".yandex.ru")
            || host == "yandex.com"
            || host.ends_with(".yandex.com")
            || host == "ya.ru"
            || host.ends_with(".ya.ru")
        {
            format!("{}search/?text={}", normalized, encoded_query)
        } else {
            format!("{}?q={}", normalized, encoded_query)
        };

        Some(mapped)
    }

    fn open_search_in_browser(query: &str) {
        let query = query.trim();
        if query.is_empty() {
            return;
        }
        let encoded = Self::url_encode_query(query);
        let cfg = load_config();
        let url = Self::search_url_for_template(&cfg.search.url_template, &encoded)
            .unwrap_or_else(|| format!("https://duckduckgo.com/?q={}", encoded));
        if url.starts_with("https://") || url.starts_with("http://") {
            let url = QString::from(url.as_str());
            let _ = ffi::open_url_with_activation(&url);
        }
    }

    fn run_in_terminal(command: &str) {
        let home = Self::home_dir();
        let cmd_args = Self::parse_exec_args(command);

        if cmd_args.is_empty() {
            eprintln!("[smoothysearch] run_in_terminal: empty exec after parsing: {command:?}");
            return;
        }

        let Some(terminal) = Self::detect_terminal() else {
            eprintln!("[smoothysearch] run_in_terminal: no terminal emulator found");
            return;
        };

        let mut run_args = vec![
            "bash".to_string(),
            "--noprofile".to_string(),
            "--norc".to_string(),
            "-c".to_string(),
            "\"$@\"; exec bash --noprofile --norc -i".to_string(),
            "--".to_string(),
        ];
        run_args.extend(cmd_args);

        let args = Self::terminal_launch_args(&terminal, &run_args);

        let _ = Command::new(&terminal)
            .current_dir(&home)
            .args(&args)
            .spawn();
    }
}

pub fn resident_service_running() -> bool {
    let socket = BackendRust::resident_socket_file();

    if UnixStream::connect(&socket).is_ok() {
        return true;
    }

    if socket.exists() {
        let _ = fs::remove_file(socket);
    }

    false
}

pub fn acquire_resident_singleton() -> bool {
    let dir = BackendRust::cache_dir();
    let _ = fs::create_dir_all(&dir);

    let socket = BackendRust::resident_socket_file();
    if resident_service_running() {
        return false;
    }

    let listener = match std::os::unix::net::UnixListener::bind(&socket) {
        Ok(listener) => listener,
        Err(_) => return false,
    };

    let _ = listener.set_nonblocking(true);

    if RESIDENT_LOCK.set(listener).is_err() {
        return false;
    }

    true
}

pub fn ensure_resident_service_running() {
    if resident_service_running() {
        if BackendRust::service_binary_is_stale() {
            let _ = Command::new("pkill")
                .args(["-f", "smoothysearch --service"])
                .stdin(Stdio::null())
                .stdout(Stdio::null())
                .stderr(Stdio::null())
                .spawn();

            for _ in 0..SERVICE_KILL_RETRIES {
                if !resident_service_running() {
                    break;
                }
                thread::sleep(Duration::from_millis(SERVICE_RETRY_DELAY_MS));
            }
        } else {
            return;
        }
    }

    let Ok(exe) = std::env::current_exe() else {
        return;
    };

    let _ = Command::new(exe)
        .arg("--service")
        .stdin(Stdio::null())
        .stdout(Stdio::null())
        .stderr(Stdio::null())
        .spawn();

    for _ in 0..SERVICE_START_RETRIES {
        if resident_service_running() {
            return;
        }
        thread::sleep(Duration::from_millis(SERVICE_RETRY_DELAY_MS));
    }

    eprintln!(
        "[smoothysearch] service did not become ready after {}ms",
        SERVICE_START_RETRIES as u64 * SERVICE_RETRY_DELAY_MS
    );
}

pub fn request_resident_show() {
    BackendRust::write_resident_command("show");
}

pub fn invalidate_app_cache() {
    BackendRust::invalidate_app_cache();
}

pub fn app_dirs_for_watch() -> Vec<PathBuf> {
    let home = std::env::var("HOME").unwrap_or_default();
    vec![
        PathBuf::from(format!("{}/.local/share/applications", home)),
        PathBuf::from("/usr/local/share/applications"),
        PathBuf::from("/usr/share/applications"),
        PathBuf::from("/var/lib/flatpak/exports/share/applications"),
        PathBuf::from(format!(
            "{}/.local/share/flatpak/exports/share/applications",
            home
        )),
    ]
}

impl ffi::Backend {
    pub fn is_applied_theme_index(self: &ffi::Backend, index: i32) -> bool {
        if index < 0 {
            return false;
        }

        let rust = self.rust();

        match rust.filtered_entries.get(index as usize) {
            Some(EntryItem::Theme { id, .. }) => id == &self.applied_theme_id().to_string(),
            _ => false,
        }
    }

    pub fn is_search_index(self: &ffi::Backend, index: i32) -> bool {
        if index < 0 {
            return false;
        }

        let rust = self.rust();
        matches!(
            rust.filtered_entries.get(index as usize),
            Some(EntryItem::InternetSearch)
        )
    }

    pub fn poll_resident_command(mut self: Pin<&mut Self>) -> i32 {
        let self_ref = self.as_ref();
        let (resident_mode, last_seen) = {
            let rust = self_ref.rust();
            (rust.resident_mode, rust.last_resident_command_mtime_ms)
        };

        if !resident_mode {
            return 0;
        }

        let Some((mtime, command)) = BackendRust::read_resident_command(last_seen) else {
            return 0;
        };

        {
            let mut rust = self.as_mut().rust_mut();
            rust.last_resident_command_mtime_ms = mtime;
        }

        match command.as_str() {
            "show" => {
                let mode = {
                    let self_ref = self.as_ref();
                    let rust = self_ref.rust();
                    rust.mode.unwrap_or(AppMode::Apps)
                };

                if mode == AppMode::Apps {
                    let current_query = self.current_text().to_string();
                    let new_apps = BackendRust::load_desktop_apps();

                    let (items, icon_paths, preview_colors, current_index) = {
                        let mut rust = self.as_mut().rust_mut();
                        rust.all_apps = new_apps;
                        rust.refresh_entries_for_current_mode(&current_query)
                    };
                    self.as_mut().set_items(items);
                    self.as_mut().set_icon_paths(icon_paths);
                    self.as_mut().set_preview_colors(preview_colors);
                    self.as_mut().set_current_index(current_index);
                }

                1
            }
            "hide" => 2,
            _ => 0,
        }
    }

    pub fn set_query(mut self: Pin<&mut Self>, value: QString) {
        let query = value.to_string();

        let filtered = {
            let binding = self.as_ref();
            let rust = binding.rust();
            rust.filter_entries(&query)
        };

        let items = BackendRust::entries_to_qstringlist(&filtered);
        let icon_paths = BackendRust::icon_paths_to_qstringlist(&filtered);
        let preview_colors = BackendRust::preview_colors_to_qstringlist(&filtered);

        {
            let mut rust = self.as_mut().rust_mut();
            rust.filtered_entries = filtered;
        }

        self.as_mut().set_current_text(value);
        self.as_mut().set_items(items);
        self.as_mut().set_icon_paths(icon_paths);
        self.as_mut().set_preview_colors(preview_colors);

        let has_items = self.items().len() > 0;
        let new_index = if has_items { 0 } else { -1 };
        self.as_mut().set_current_index(new_index);
    }

    pub fn move_down(mut self: Pin<&mut Self>) {
        let len = self.items().len() as i32;
        if len <= 0 {
            return;
        }

        let next = (*self.current_index() + 1).min(len - 1);
        self.as_mut().set_current_index(next);
    }

    pub fn move_up(mut self: Pin<&mut Self>) {
        let len = self.items().len() as i32;
        if len <= 0 {
            return;
        }

        let next = (*self.current_index() - 1).max(0);
        self.as_mut().set_current_index(next);
    }

    pub fn select_index(mut self: Pin<&mut Self>, index: i32) {
        let len = self.items().len() as i32;
        if len <= 0 {
            self.as_mut().set_current_index(-1);
            return;
        }

        let clamped = index.clamp(0, len - 1);
        self.as_mut().set_current_index(clamped);
    }

    pub fn toggle_editor(mut self: Pin<&mut Self>) {
        if !*self.is_themes_mode() {
            return;
        }

        let next = !*self.editor_open();
        self.as_mut().set_editor_open(next);

        if next {
            self.as_mut().load_themes_file();
        }
    }

    pub fn load_themes_file(mut self: Pin<&mut Self>) {
        let text = if *self.editor_is_config() {
            config_path()
                .and_then(|path| fs::read_to_string(path).ok())
                .unwrap_or_default()
        } else {
            ensure_sample_themes_file_exists();
            BackendRust::themes_file_path()
                .and_then(|path| fs::read_to_string(path).ok())
                .unwrap_or_default()
        };

        self.as_mut()
            .set_themes_file_text(QString::from(text.as_str()));
    }

    pub fn save_themes_file(mut self: Pin<&mut Self>) {
        let is_config = *self.editor_is_config();

        let Some(path) = (if is_config {
            config_path()
        } else {
            BackendRust::themes_file_path()
        }) else {
            return;
        };

        if let Some(parent) = path.parent() {
            let _ = fs::create_dir_all(parent);
        }

        let text = self.themes_file_text().to_string();
        if fs::write(&path, text).is_err() {
            return;
        }

        if is_config {
            self.as_mut().load_themes_file();
        } else {
            let current_query = self.current_text().to_string();
            let applied_theme_id = self.applied_theme_id().to_string();
            let applied_still_exists = all_theme_ids().iter().any(|id| id == &applied_theme_id);
            let applied_id_to_use = if applied_still_exists {
                applied_theme_id
            } else {
                String::from("graphite_dark")
            };

            let (items, icon_paths, preview_colors, current_index) = {
                let mut rust = self.as_mut().rust_mut();
                rust.refresh_entries_for_current_mode(&current_query)
            };

            self.as_mut().set_items(items);
            self.as_mut().set_icon_paths(icon_paths);
            self.as_mut().set_preview_colors(preview_colors);
            self.as_mut().set_current_index(current_index);
            self.as_mut()
                .set_applied_theme_id(QString::from(applied_id_to_use.as_str()));
            self.as_mut().apply_theme_properties(&applied_id_to_use);
            self.as_mut().load_themes_file();
        }
    }

    fn apply_theme_properties(mut self: Pin<&mut Self>, theme_id: &str) {
        let theme = get_theme_preset(theme_id);

        self.as_mut()
            .set_theme_window_bg(QString::from(theme.window_bg.as_str()));
        self.as_mut()
            .set_theme_border(QString::from(theme.border.as_str()));
        self.as_mut()
            .set_theme_input_bg(QString::from(theme.input_bg.as_str()));
        self.as_mut()
            .set_theme_text(QString::from(theme.text.as_str()));
        self.as_mut()
            .set_theme_text_dim(QString::from(theme.text_dim.as_str()));
        self.as_mut()
            .set_theme_highlight(QString::from(theme.highlight.as_str()));
        self.as_mut()
            .set_theme_highlight_text(QString::from(theme.highlight_text.as_str()));
    }

    pub fn save_selected_theme(self: Pin<&mut Self>) {
        let id = self.applied_theme_id().to_string();
        if !id.is_empty() {
            let _ = save_theme_preset(&id);
        }
        BackendRust::invalidate_app_cache();
    }

    pub fn set_editor_file(mut self: Pin<&mut Self>, is_config: bool) {
        self.as_mut().set_editor_is_config(is_config);
        self.as_mut().load_themes_file();
    }

    pub fn launch_current(mut self: Pin<&mut Self>) {
        let current_query = self.current_text().to_string();
        let current_index = *self.current_index();

        let selected_entry = {
            let binding = self.as_ref();
            let rust = binding.rust();
            let mode = rust.mode.unwrap_or(AppMode::Apps);

            let has_entries = !rust.filtered_entries.is_empty();

            let entry =
                if current_index >= 0 && (current_index as usize) < rust.filtered_entries.len() {
                    rust.filtered_entries.get(current_index as usize).cloned()
                } else if has_entries {
                    rust.filtered_entries.first().cloned()
                } else {
                    None
                };

            (mode, has_entries, entry)
        };

        let (_, _, entry) = selected_entry;

        if let Some(entry) = entry {
            match entry {
                EntryItem::App(app) => {
                    if app.terminal {
                        BackendRust::run_in_terminal(&app.exec);
                    } else {
                        BackendRust::run_shell(&app.exec);
                    }

                    return;
                }
                EntryItem::Theme { id, .. } => {
                    self.as_mut().apply_theme_properties(&id);
                    self.as_mut()
                        .set_applied_theme_id(QString::from(id.as_str()));
                    return;
                }
                EntryItem::InternetSearch => {
                    let query = current_query.trim().to_string();
                    if !query.is_empty() {
                        BackendRust::open_search_in_browser(&query);
                    }
                    return;
                }
                EntryItem::ExecCommand => {
                    let query = current_query.trim().to_string();
                    if !query.is_empty() {
                        BackendRust::run_in_terminal(&query);
                    }
                    return;
                }
            }
        }
    }
}

impl Initialize for ffi::Backend {
    fn initialize(mut self: Pin<&mut Self>) {
        ensure_default_config_exists();
        ensure_sample_themes_file_exists();

        let config = load_config();
        self.as_mut().set_window_width(config.window.width);
        self.as_mut().set_window_height(config.window.height);
        self.as_mut()
            .set_window_editor_width(config.window.editor_width);

        self.as_mut().set_ui_window_radius(config.ui.window_radius);
        self.as_mut()
            .set_ui_search_bar_radius(config.ui.search_bar_radius);
        self.as_mut()
            .set_ui_selector_radius(config.ui.selector_radius);

        let theme = get_theme_preset(&config.theme.preset);

        let resident_mode = BackendRust::is_resident_mode();

        let mode = if std::env::args().any(|arg| arg == "--themes") {
            AppMode::Themes
        } else {
            AppMode::Apps
        };

        let all_apps = if mode == AppMode::Apps {
            BackendRust::load_desktop_apps()
        } else {
            Vec::new()
        };

        let filtered_entries = match mode {
            AppMode::Apps => all_apps.iter().cloned().map(EntryItem::App).collect(),
            AppMode::Themes => {
                let temp = BackendRust::default();
                temp.filter_themes("")
            }
        };

        let items = BackendRust::entries_to_qstringlist(&filtered_entries);
        let icon_paths = BackendRust::icon_paths_to_qstringlist(&filtered_entries);
        let preview_colors = BackendRust::preview_colors_to_qstringlist(&filtered_entries);

        {
            let mut rust = self.as_mut().rust_mut();
            rust.mode = Some(mode);
            rust.resident_mode = resident_mode;
            rust.all_apps = all_apps;
            rust.filtered_entries = filtered_entries;
            rust.last_resident_command_mtime_ms = 0;
        }

        self.as_mut().set_is_themes_mode(mode == AppMode::Themes);
        self.as_mut().set_resident_mode(resident_mode);
        self.as_mut().set_editor_open(false);
        self.as_mut().set_editor_is_config(false);
        self.as_mut().set_themes_file_text(QString::default());

        self.as_mut()
            .set_theme_window_bg(QString::from(theme.window_bg.as_str()));
        self.as_mut()
            .set_theme_border(QString::from(theme.border.as_str()));
        self.as_mut()
            .set_theme_input_bg(QString::from(theme.input_bg.as_str()));
        self.as_mut()
            .set_theme_text(QString::from(theme.text.as_str()));
        self.as_mut()
            .set_theme_text_dim(QString::from(theme.text_dim.as_str()));
        self.as_mut()
            .set_theme_highlight(QString::from(theme.highlight.as_str()));
        self.as_mut()
            .set_theme_highlight_text(QString::from(theme.highlight_text.as_str()));

        self.as_mut()
            .set_applied_theme_id(QString::from(config.theme.preset.as_str()));

        self.as_mut().set_items(items);
        self.as_mut().set_icon_paths(icon_paths);
        self.as_mut().set_preview_colors(preview_colors);

        let index = if self.items().len() > 0 { 0 } else { -1 };
        self.as_mut().set_current_index(index);
    }
}
