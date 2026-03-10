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
    }

    impl cxx_qt::Initialize for Backend {}
}

use crate::config::{ensure_default_config_exists, load_config, save_theme_preset};
use crate::theme::{
    all_theme_ids, ensure_sample_themes_file_exists, get_theme_preset, theme_display_name,
};
use cxx_qt::{CxxQtType, Initialize};
use cxx_qt_lib::{QString, QStringList};
use serde::{Deserialize, Serialize};
use std::collections::HashMap;
use std::fs;
use std::path::{Path, PathBuf};
use std::pin::Pin;
use std::process::Command;

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

    mode: Option<AppMode>,
    all_apps: Vec<AppItem>,
    filtered_entries: Vec<EntryItem>,
}

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
            let direct = theme_dir.join(format!("{icon}.{ext}"));
            if let Some(found) = Self::existing_icon_path(&direct) {
                return Some(found);
            }

            let direct_apps = theme_dir.join("apps").join(format!("{icon}.{ext}"));
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
                let candidate = size_dir.join("apps").join(format!("{icon}.{ext}"));
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
                let candidate = base.join(format!("{icon}.{ext}"));
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

        let mut starts_with_matches: Vec<AppItem> = Vec::new();
        let mut contains_matches: Vec<AppItem> = Vec::new();

        for app in &self.all_apps {
            if app.name_lower.starts_with(&q) {
                starts_with_matches.push(app.clone());
            } else if app.name_lower.contains(&q) {
                contains_matches.push(app.clone());
            }
        }

        starts_with_matches.sort_by_key(|a| a.name.to_lowercase());
        contains_matches.sort_by_key(|a| a.name.to_lowercase());

        starts_with_matches.extend(contains_matches);
        starts_with_matches
    }

    fn filter_themes(&self, query: &str) -> Vec<EntryItem> {
        let q = query.trim().to_lowercase();

        let theme_ids = all_theme_ids();

        let mut items: Vec<EntryItem> = theme_ids
        .iter()
        .filter_map(|id| {
            let display = theme_display_name(id);
            let id_lower = id.to_lowercase();
            let display_lower = display.to_lowercase();

            if q.is_empty() || id_lower.contains(&q) || display_lower.contains(&q) {
                Some(EntryItem::Theme {
                    id: id.to_string(),
                     name: display,
                })
            } else {
                None
            }
        })
        .collect();

        items.sort_by(|a, b| {
            let a_name = match a {
                EntryItem::Theme { name, .. } => name,
                EntryItem::App(app) => &app.name,
            };
            let b_name = match b {
                EntryItem::Theme { name, .. } => name,
                EntryItem::App(app) => &app.name,
            };
            a_name.cmp(b_name)
        });

        items
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

    fn run_shell(command: &str) {
        let _ = Command::new("bash").args(["-lc", command]).spawn();
    }

    fn run_in_terminal(command: &str) {
        let wrapped = format!(
            r#"{command}; status=$?; echo; echo "Exit code: $status"; read -rsp "Press Enter to close...""#
        );

        let _ = Command::new("konsole")
        .args(["-e", "bash", "-lc", wrapped.as_str()])
        .spawn();
    }

    fn quit_now() -> ! {
        std::process::exit(0);
    }
}

impl ffi::Backend {
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

    pub fn launch_current(self: Pin<&mut Self>) {
        let current_query = self.current_text().to_string();
        let current_index = *self.current_index();

        let binding = self.as_ref();
        let rust = binding.rust();

        let mode = rust.mode.unwrap_or(AppMode::Apps);

        if current_index >= 0 && (current_index as usize) < rust.filtered_entries.len() {
            match &rust.filtered_entries[current_index as usize] {
                EntryItem::App(app) => {
                    let app = app.clone();

                    if app.terminal {
                        BackendRust::run_in_terminal(&app.exec);
                    } else {
                        BackendRust::run_shell(&app.exec);
                    }

                    BackendRust::quit_now();
                }
                EntryItem::Theme { id, .. } => {
                    let _ = save_theme_preset(id);
                    BackendRust::quit_now();
                }
            }
        }

        if mode == AppMode::Themes {
            return;
        }

        let raw_query = current_query.trim().to_string();
        if raw_query.is_empty() {
            return;
        }

        BackendRust::run_in_terminal(&raw_query);
        BackendRust::quit_now();
    }
}

impl Initialize for ffi::Backend {
    fn initialize(mut self: Pin<&mut Self>) {
        ensure_default_config_exists();
        ensure_sample_themes_file_exists();

        let config = load_config();
        let theme = get_theme_preset(&config.theme.preset);

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
            AppMode::Apps => all_apps
            .iter()
            .cloned()
            .map(EntryItem::App)
            .collect(),
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
            rust.all_apps = all_apps;
            rust.filtered_entries = filtered_entries;
        }

        self.as_mut().set_is_themes_mode(mode == AppMode::Themes);

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

        self.as_mut().set_items(items);
        self.as_mut().set_icon_paths(icon_paths);
        self.as_mut().set_preview_colors(preview_colors);
        self.as_mut().set_show_command_hint(false);
        self.as_mut().set_command_preview(QString::default());

        let index = if self.items().len() > 0 { 0 } else { -1 };
        self.as_mut().set_current_index(index);
    }
}
