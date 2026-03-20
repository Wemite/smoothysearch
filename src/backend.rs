mod apps;
mod editor;
mod resident;
mod themes;

#[cxx_qt::bridge]
mod ffi {
    unsafe extern "C++" {
        include!("cxx-qt-lib/qstring.h");
        type QString = cxx_qt_lib::QString;

        include!("smoothysearch/qt_url_opener.h");
        fn open_url_with_activation(url: &QString) -> bool;

        include!("smoothysearch/qt_window_effects.h");
        fn sync_plasma_blur_for_visible_windows(radius: i32) -> bool;

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
        #[qproperty(QString, themes_file_text)]
        #[qproperty(i32, window_width)]
        #[qproperty(i32, window_height)]
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
        fn is_theme_command_index(self: &Backend, index: i32) -> bool;

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

        #[qinvokable]
        fn enter_themes_mode(self: Pin<&mut Backend>);

        #[qinvokable]
        fn return_to_apps_mode(self: Pin<&mut Backend>);

        #[qinvokable]
        fn sync_window_blur(self: &Backend, radius: i32);
    }

    impl cxx_qt::Initialize for Backend {}
}

use crate::config::ensure_default_config_exists;
use crate::theme::{ensure_sample_themes_file_exists, get_theme_preset};
use cxx_qt::{CxxQtType, Initialize};
use cxx_qt_lib::{QString, QStringList};
use serde::{Deserialize, Serialize};
use std::collections::HashMap;
use std::fs;
use std::io::ErrorKind;
use std::os::unix::net::UnixStream;
use std::path::{Path, PathBuf};
use std::pin::Pin;
use std::process::{Command, Stdio};
use std::sync::OnceLock;
use std::thread;
use std::time::{Duration, SystemTime, UNIX_EPOCH};

#[derive(Clone, Copy, Debug, PartialEq, Eq)]
pub(crate) enum AppMode {
    Apps,
    Themes,
}

#[derive(Clone, Debug, Serialize, Deserialize)]
pub(crate) struct AppItem {
    name: String,
    name_lower: String,
    exec: String,
    #[serde(default)]
    launch_args: Vec<String>,
    terminal: bool,
    #[serde(default)]
    working_dir: Option<String>,
    icon_path: String,
}

#[derive(Clone, Debug)]
pub(crate) enum EntryItem {
    App(AppItem),
    Theme { id: String, name: String },
    OpenThemeEditor,
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
    themes_file_text: QString,
    editor_is_config: bool,

    window_width: i32,
    window_height: i32,
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
const SOCKET_ACCEPT_POLL_MS: u64 = 50;

impl BackendRust {
    fn preview_colors_to_qstringlist(entries: &[EntryItem]) -> QStringList {
        let mut list = QStringList::default();

        for entry in entries {
            match entry {
                EntryItem::App(_)
                | EntryItem::OpenThemeEditor
                | EntryItem::InternetSearch
                | EntryItem::ExecCommand => list.append(QString::from("")),
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

    fn themes_file_path() -> Option<PathBuf> {
        crate::theme::themes_path()
    }

    fn filter_entries(&self, query: &str) -> Vec<EntryItem> {
        match self.mode.unwrap_or(AppMode::Apps) {
            AppMode::Apps => {
                let apps = self.filter_apps(query);
                let mut entries = Vec::new();

                if apps.is_empty() && !query.trim().is_empty() {
                    entries.push(EntryItem::ExecCommand);
                    entries.push(EntryItem::InternetSearch);
                    entries.push(EntryItem::OpenThemeEditor);
                } else {
                    entries.extend(apps.into_iter().map(EntryItem::App));
                }

                entries
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
                EntryItem::OpenThemeEditor => list.append(QString::from("Switch theme")),
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
                EntryItem::Theme { .. }
                | EntryItem::OpenThemeEditor
                | EntryItem::InternetSearch
                | EntryItem::ExecCommand => list.append(QString::from("")),
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
}

pub fn invalidate_app_cache() {
    BackendRust::invalidate_app_cache();
}

pub fn app_dirs_for_watch() -> Vec<PathBuf> {
    BackendRust::app_dirs()
}

pub use resident::{
    acquire_resident_singleton, ensure_resident_service_running, request_resident_reload_config,
    request_resident_show,
};

impl ffi::Backend {
    pub(crate) fn switch_mode(mut self: Pin<&mut Self>, mode: AppMode, clear_query: bool) {
        let query = if clear_query {
            String::new()
        } else {
            self.current_text().to_string()
        };

        let (items, icon_paths, preview_colors, current_index) = {
            let mut rust = self.as_mut().rust_mut();
            rust.mode = Some(mode);
            rust.refresh_entries_for_current_mode(&query)
        };

        self.as_mut().set_is_themes_mode(mode == AppMode::Themes);
        self.as_mut().set_items(items);
        self.as_mut().set_icon_paths(icon_paths);
        self.as_mut().set_preview_colors(preview_colors);
        self.as_mut().set_current_index(current_index);
        self.as_mut()
            .set_current_text(QString::from(query.as_str()));
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

        let new_index = if !self.items().is_empty() { 0 } else { -1 };
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

        self.as_mut().set_current_index(index.clamp(0, len - 1));
    }

    pub fn launch_current(mut self: Pin<&mut Self>) {
        let current_query = self.current_text().to_string();
        let current_index = *self.current_index();

        let entry = {
            let binding = self.as_ref();
            let rust = binding.rust();

            if current_index >= 0 && (current_index as usize) < rust.filtered_entries.len() {
                rust.filtered_entries.get(current_index as usize).cloned()
            } else {
                rust.filtered_entries.first().cloned()
            }
        };

        let Some(entry) = entry else {
            return;
        };

        match entry {
            EntryItem::App(app) => {
                if app.terminal {
                    BackendRust::run_in_terminal_args(&app.launch_args, app.working_dir.as_deref());
                } else {
                    BackendRust::run_shell_args(&app.launch_args, app.working_dir.as_deref());
                }
            }
            EntryItem::Theme { id, .. } => {
                self.as_mut().apply_theme_properties(&id);
                self.as_mut()
                    .set_applied_theme_id(QString::from(id.as_str()));
            }
            EntryItem::OpenThemeEditor => self.as_mut().enter_themes_mode(),
            EntryItem::InternetSearch => {
                let query = current_query.trim().to_string();
                if !query.is_empty() {
                    BackendRust::open_search_in_browser(&query);
                }
            }
            EntryItem::ExecCommand => {
                let query = current_query.trim().to_string();
                if !query.is_empty() {
                    BackendRust::run_in_terminal(&query);
                }
            }
        }
    }
}

impl Initialize for ffi::Backend {
    fn initialize(mut self: Pin<&mut Self>) {
        ensure_default_config_exists();
        ensure_sample_themes_file_exists();

        let resident_mode = BackendRust::is_resident_mode();
        let mode = AppMode::Apps;
        let all_apps = BackendRust::load_desktop_apps();
        let filtered_entries = all_apps
            .iter()
            .cloned()
            .map(EntryItem::App)
            .collect::<Vec<_>>();

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

        self.as_mut().set_is_themes_mode(false);
        self.as_mut().set_resident_mode(resident_mode);
        self.as_mut().set_editor_is_config(false);
        self.as_mut().set_themes_file_text(QString::default());
        self.as_mut().apply_loaded_config();
        self.as_mut().set_items(items);
        self.as_mut().set_icon_paths(icon_paths);
        self.as_mut().set_preview_colors(preview_colors);

        let index = if !self.items().is_empty() { 0 } else { -1 };
        self.as_mut().set_current_index(index);
    }
}
