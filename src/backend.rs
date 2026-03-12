#[cxx_qt::bridge]
mod ffi {
    unsafe extern "C++" {
        include!("cxx-qt-lib/qstring.h");
        type QString = cxx_qt_lib::QString;

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
        #[qproperty(bool, show_command_hint)]
        #[qproperty(QString, command_preview)]
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
        fn toggle_editor(self: Pin<&mut Backend>);

        #[qinvokable]
        fn load_themes_file(self: Pin<&mut Backend>);

        #[qinvokable]
        fn save_themes_file(self: Pin<&mut Backend>);

        #[qinvokable]
        fn poll_resident_command(self: Pin<&mut Backend>) -> i32;
    }

    impl cxx_qt::Initialize for Backend {}
}

use crate::config::{ensure_default_config_exists, load_config, save_theme_preset};
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
    show_command_hint: bool,
    command_preview: QString,

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

impl BackendRust {
    fn preview_colors_to_qstringlist(entries: &[EntryItem]) -> QStringList {
        let mut list = QStringList::default();

        for entry in entries {
            match entry {
                EntryItem::App(_) => list.append(QString::from("")),
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
            PathBuf::from("/usr/share/applications"),
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

    fn icon_extensions() -> [&'static str; 3] {
        ["png", "svg", "xpm"]
    }

    fn existing_icon_path(path: &Path) -> Option<String> {
        if path.is_file() {
            Some(path.to_string_lossy().to_string())
        } else {
            None
        }
    }

    fn resolve_explicit_icon_path(icon: &str) -> Option<String> {
        let path = PathBuf::from(icon);

        if let Some(found) = Self::existing_icon_path(&path) {
            return Some(found);
        }

        if path.extension().is_none() {
            for ext in Self::icon_extensions() {
                let candidate = path.with_extension(ext);
                if let Some(found) = Self::existing_icon_path(&candidate) {
                    return Some(found);
                }
            }
        }

        None
    }

    fn search_in_theme_dir(theme_dir: &Path, icon: &str) -> Option<String> {
        for ext in Self::icon_extensions() {
            let direct = theme_dir.join(format!("{}.{}", icon, ext));
            if let Some(found) = Self::existing_icon_path(&direct) {
                return Some(found);
            }

            let direct_apps = theme_dir.join("apps").join(format!("{}.{}", icon, ext));
            if let Some(found) = Self::existing_icon_path(&direct_apps) {
                return Some(found);
            }
        }

        let entries = fs::read_dir(theme_dir).ok()?;
        for entry in entries.flatten() {
            let size_dir = entry.path();
            if !size_dir.is_dir() {
                continue;
            }

            for ext in Self::icon_extensions() {
                let candidate = size_dir.join("apps").join(format!("{}.{}", icon, ext));
                if let Some(found) = Self::existing_icon_path(&candidate) {
                    return Some(found);
                }
            }
        }

        None
    }

    fn search_icon_by_name(icon: &str) -> Option<String> {
        let home = Self::home_dir();

        let icon_bases = vec![
            PathBuf::from(format!("{home}/.local/share/icons")),
            PathBuf::from(format!("{home}/.icons")),
            PathBuf::from("/usr/share/icons"),
        ];

        for base in icon_bases {
            if !base.is_dir() {
                continue;
            }

            let Ok(entries) = fs::read_dir(&base) else {
                continue;
            };

            for entry in entries.flatten() {
                let theme_dir = entry.path();
                if !theme_dir.is_dir() {
                    continue;
                }

                if let Some(found) = Self::search_in_theme_dir(&theme_dir, icon) {
                    return Some(found);
                }
            }
        }

        let pixmaps = vec![
            PathBuf::from("/usr/share/pixmaps"),
            PathBuf::from(format!("{home}/.local/share/pixmaps")),
        ];

        for base in pixmaps {
            if !base.is_dir() {
                continue;
            }

            for ext in Self::icon_extensions() {
                let candidate = base.join(format!("{}.{}", icon, ext));
                if let Some(found) = Self::existing_icon_path(&candidate) {
                    return Some(found);
                }
            }
        }

        None
    }

    fn resolve_icon_path(icon_value: Option<&String>) -> String {
        let Some(icon) = icon_value.map(|s| s.trim()).filter(|s| !s.is_empty()) else {
            return String::new();
        };

        if icon.contains('/') {
            return Self::resolve_explicit_icon_path(icon).unwrap_or_default();
        }

        Self::search_icon_by_name(icon).unwrap_or_default()
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
        let icon_path = Self::resolve_icon_path(map.get("Icon"));
        let name_lower = name.to_lowercase();

        Some(AppItem {
            name,
            name_lower,
            exec,
            terminal,
            icon_path,
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
        serde_json::from_str(&content).ok()
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
        let local_apps_dir = format!("{home}/.local/share/applications");

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
                || base.to_string_lossy().starts_with(&local_apps_dir);

                if prefer_this {
                    apps_by_name.insert(key, app);
                }
            }
        }

        let mut apps: Vec<AppItem> = apps_by_name.into_values().collect();
        apps.sort_by_key(|a| a.name.to_lowercase());
        apps
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

        scored.sort_by(|a, b| b.0.cmp(&a.0).then_with(|| a.1.name_lower.cmp(&b.1.name_lower)));

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
                };

                let (b_id, b_name): (&str, &str) = match b {
                    EntryItem::Theme { id, name } => (id.as_str(), name.as_str()),
                          EntryItem::App(app) => (app.name.as_str(), app.name.as_str()),
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

        scored.sort_by(|a, b| b.0.cmp(&a.0).then_with(|| b.1.cmp(&a.1)).then_with(|| a.2.cmp(&b.2)));

        scored.into_iter().map(|(_, _, _, item)| item).collect()
    }

    fn filter_entries(&self, query: &str) -> Vec<EntryItem> {
        match self.mode.unwrap_or(AppMode::Apps) {
            AppMode::Apps => self.filter_apps(query).into_iter().map(EntryItem::App).collect(),
            AppMode::Themes => self.filter_themes(query),
        }
    }

    fn entries_to_qstringlist(entries: &[EntryItem]) -> QStringList {
        let mut list = QStringList::default();

        for entry in entries {
            match entry {
                EntryItem::App(app) => list.append(QString::from(app.name.as_str())),
                EntryItem::Theme { name, .. } => list.append(QString::from(name.as_str())),
            }
        }

        list
    }

    fn icon_paths_to_qstringlist(entries: &[EntryItem]) -> QStringList {
        let mut list = QStringList::default();

        for entry in entries {
            match entry {
                EntryItem::App(app) => list.append(QString::from(app.icon_path.as_str())),
                EntryItem::Theme { .. } => list.append(QString::from("")),
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

    fn run_shell(command: &str) {
        let home = Self::home_dir();

        let _ = Command::new("bash")
        .current_dir(&home)
        .args(["-lc", command])
        .spawn();
    }

    fn run_in_terminal(command: &str) {
        let home = Self::home_dir();
        let wrapped = format!(r#"{command}; exec bash"#);

        let _ = Command::new("konsole")
        .current_dir(&home)
        .args(["-e", "bash", "-lc", wrapped.as_str()])
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

            for _ in 0..20 {
                if !resident_service_running() {
                    break;
                }
                thread::sleep(Duration::from_millis(50));
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

    for _ in 0..40 {
        if resident_service_running() {
            return;
        }
        thread::sleep(Duration::from_millis(50));
    }
}

pub fn request_resident_show() {
    BackendRust::write_resident_command("show");
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

                    let trimmed = current_query.trim().to_string();
                    let has_items = self.items().len() > 0;

                    self.as_mut()
                    .set_show_command_hint(!trimmed.is_empty() && !has_items);
                    self.as_mut()
                    .set_command_preview(QString::from(trimmed.as_str()));
                }

                1
            }
            "hide" => 2,
            _ => 0,
        }
    }

    pub fn set_query(mut self: Pin<&mut Self>, value: QString) {
        let query = value.to_string();
        let trimmed = query.trim().to_string();

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
        self.as_mut().set_show_command_hint(false);
        self.as_mut().set_command_preview(QString::default());

        let is_themes_mode = *self.is_themes_mode();
        let has_items = self.items().len() > 0;

        if is_themes_mode {
            self.as_mut().set_show_command_hint(false);
            self.as_mut().set_command_preview(QString::default());
        } else {
            self.as_mut()
            .set_show_command_hint(!trimmed.is_empty() && !has_items);
            self.as_mut()
            .set_command_preview(QString::from(trimmed.as_str()));
        }

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
        ensure_sample_themes_file_exists();

        let text = BackendRust::themes_file_path()
        .and_then(|path| fs::read_to_string(path).ok())
        .unwrap_or_default();

        self.as_mut().set_themes_file_text(QString::from(text.as_str()));
    }

    pub fn save_themes_file(mut self: Pin<&mut Self>) {
        let Some(path) = BackendRust::themes_file_path() else {
            return;
        };

        if let Some(parent) = path.parent() {
            let _ = fs::create_dir_all(parent);
        }

        let text = self.themes_file_text().to_string();
        if fs::write(&path, text).is_err() {
            return;
        }

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

    pub fn launch_current(mut self: Pin<&mut Self>) {
        let current_query = self.current_text().to_string();
        let current_index = *self.current_index();

        let selected_entry = {
            let binding = self.as_ref();
            let rust = binding.rust();
            let mode = rust.mode.unwrap_or(AppMode::Apps);

            let has_entries = !rust.filtered_entries.is_empty();

            let entry = if current_index >= 0 && (current_index as usize) < rust.filtered_entries.len()
            {
                rust.filtered_entries.get(current_index as usize).cloned()
            } else if has_entries {
                rust.filtered_entries.first().cloned()
            } else {
                None
            };

            (mode, has_entries, entry)
        };

        let (mode, has_entries, entry) = selected_entry;

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
                    let _ = save_theme_preset(&id);
                    self.as_mut().apply_theme_properties(&id);
                    self.as_mut().set_applied_theme_id(QString::from(id.as_str()));
                    return;
                }
            }
        }

        if mode == AppMode::Themes {
            return;
        }

        if has_entries {
            return;
        }

        let raw_query = current_query.trim().to_string();
        if raw_query.is_empty() {
            return;
        }

        BackendRust::run_in_terminal(&raw_query);
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

        self.as_mut()
        .set_ui_window_radius(config.ui.window_radius);
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
        self.as_mut().set_show_command_hint(false);
        self.as_mut().set_command_preview(QString::default());

        let index = if self.items().len() > 0 { 0 } else { -1 };
        self.as_mut().set_current_index(index);
    }
}
