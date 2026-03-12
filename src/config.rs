use serde::{Deserialize, Serialize};
use std::{fs, path::PathBuf};

#[derive(Debug, Clone, Deserialize, Serialize, Default)]
pub struct AppConfig {
    #[serde(default)]
    pub theme: ThemeConfig,

    #[serde(default)]
    pub window: WindowConfig,

    #[serde(default)]
    pub ui: UiConfig,
}

#[derive(Debug, Clone, Deserialize, Serialize)]
pub struct ThemeConfig {
    #[serde(default = "default_theme_preset")]
    pub preset: String,
}

impl Default for ThemeConfig {
    fn default() -> Self {
        Self {
            preset: default_theme_preset(),
        }
    }
}

#[derive(Debug, Clone, Deserialize, Serialize)]
pub struct WindowConfig {
    #[serde(default = "default_window_width")]
    pub width: i32,

    #[serde(default = "default_window_height")]
    pub height: i32,

    #[serde(default = "default_editor_width")]
    pub editor_width: i32,
}

impl Default for WindowConfig {
    fn default() -> Self {
        Self {
            width: default_window_width(),
            height: default_window_height(),
            editor_width: default_editor_width(),
        }
    }
}

#[derive(Debug, Clone, Deserialize, Serialize)]
pub struct UiConfig {
    #[serde(default = "default_window_radius")]
    pub window_radius: i32,

    #[serde(default = "default_search_bar_radius")]
    pub search_bar_radius: i32,

    #[serde(default = "default_selector_radius")]
    pub selector_radius: i32,
}

impl Default for UiConfig {
    fn default() -> Self {
        Self {
            window_radius: default_window_radius(),
            search_bar_radius: default_search_bar_radius(),
            selector_radius: default_selector_radius(),
        }
    }
}

fn default_theme_preset() -> String {
    "violet_dark".to_string()
}

fn default_window_width() -> i32 {
    480
}

fn default_window_height() -> i32 {
    360
}

fn default_editor_width() -> i32 {
    840
}

fn default_window_radius() -> i32 {
    24
}

fn default_search_bar_radius() -> i32 {
    16
}

fn default_selector_radius() -> i32 {
    6
}

fn clamp_window_width(value: i32) -> i32 {
    value.clamp(320, 1200)
}

fn clamp_window_height(value: i32) -> i32 {
    value.clamp(240, 900)
}

fn clamp_editor_width(value: i32) -> i32 {
    value.clamp(700, 2200)
}

fn clamp_window_radius(value: i32) -> i32 {
    value.clamp(0, 80)
}

fn clamp_search_bar_radius(value: i32) -> i32 {
    value.clamp(0, 80)
}

fn clamp_selector_radius(value: i32) -> i32 {
    value.clamp(0, 80)
}

pub fn config_path() -> Option<PathBuf> {
    let mut path = dirs::config_dir()?;
    path.push("smoothysearch");
    path.push("config.toml");
    Some(path)
}

pub fn load_config() -> AppConfig {
    let Some(path) = config_path() else {
        return AppConfig::default();
    };

    let mut cfg = match fs::read_to_string(&path) {
        Ok(text) => toml::from_str::<AppConfig>(&text).unwrap_or_default(),
        Err(_) => AppConfig::default(),
    };

    cfg.window.width = clamp_window_width(cfg.window.width);
    cfg.window.height = clamp_window_height(cfg.window.height);
    cfg.window.editor_width = clamp_editor_width(cfg.window.editor_width);

    cfg.ui.window_radius = clamp_window_radius(cfg.ui.window_radius);
    cfg.ui.search_bar_radius = clamp_search_bar_radius(cfg.ui.search_bar_radius);
    cfg.ui.selector_radius = clamp_selector_radius(cfg.ui.selector_radius);

    cfg
}

pub fn ensure_default_config_exists() {
    let Some(path) = config_path() else {
        return;
    };

    if path.exists() {
        return;
    }

    if let Some(parent) = path.parent() {
        let _ = fs::create_dir_all(parent);
    }

    let default_text = r#"[theme]
    preset = "graphite_dark"

    [window]
    width = 480
    height = 360
    editor_width = 840

    [ui]
    window_radius = 24
    search_bar_radius = 16
    selector_radius = 6
    "#;

    let _ = fs::write(path, default_text);
}

pub fn save_theme_preset(preset: &str) -> std::io::Result<()> {
    let Some(path) = config_path() else {
        return Ok(());
    };

    if let Some(parent) = path.parent() {
        fs::create_dir_all(parent)?;
    }

    let existing = load_config();

    let cfg = AppConfig {
        theme: ThemeConfig {
            preset: preset.to_string(),
        },
        window: existing.window,
        ui: existing.ui,
    };

    let text = toml::to_string(&cfg).unwrap_or_else(|_| {
        format!(
            "[theme]\npreset = \"{}\"\n\n[window]\nwidth = {}\nheight = {}\neditor_width = {}\n\n[ui]\nwindow_radius = {}\nsearch_bar_radius = {}\nselector_radius = {}\n",
            preset,
            cfg.window.width,
            cfg.window.height,
            cfg.window.editor_width,
            cfg.ui.window_radius,
            cfg.ui.search_bar_radius,
            cfg.ui.selector_radius
        )
    });

    fs::write(path, text)
}
