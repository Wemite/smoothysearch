use serde::{Deserialize, Serialize};
use std::{fs, path::PathBuf};

#[derive(Debug, Clone, Deserialize, Serialize, Default)]
pub struct AppConfig {
    #[serde(default)]
    pub theme: ThemeConfig,
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

fn default_theme_preset() -> String {
    "violet_dark".to_string()
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

    match fs::read_to_string(&path) {
        Ok(text) => toml::from_str::<AppConfig>(&text).unwrap_or_default(),
        Err(_) => AppConfig::default(),
    }
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

    let default_text = "[theme]\npreset = \"violet_dark\"\n";
    let _ = fs::write(path, default_text);
}

pub fn save_theme_preset(preset: &str) -> std::io::Result<()> {
    let Some(path) = config_path() else {
        return Ok(());
    };

    if let Some(parent) = path.parent() {
        fs::create_dir_all(parent)?;
    }

    let cfg = AppConfig {
        theme: ThemeConfig {
            preset: preset.to_string(),
        },
    };

    let text = toml::to_string(&cfg)
    .unwrap_or_else(|_| format!("[theme]\npreset = \"{}\"\n", preset));

    fs::write(path, text)
}
