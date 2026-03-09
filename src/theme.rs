use serde::Deserialize;
use std::{fs, path::PathBuf};

#[allow(dead_code)]
#[derive(Clone, Debug)]
pub struct ThemePreset {
    pub id: String,
    pub name: String,
    pub window_bg: String,
    pub border: String,
    pub input_bg: String,
    pub text: String,
    pub text_dim: String,
    pub highlight: String,
    pub highlight_text: String,
}

#[derive(Clone, Debug, Deserialize)]
pub struct CustomThemePreset {
    pub id: String,
    pub name: String,
    pub window_bg: String,
    pub border: String,
    pub input_bg: String,
    pub text: String,
    pub text_dim: String,
    pub highlight: String,
    pub highlight_text: String,
}

#[derive(Debug, Deserialize, Default)]
struct CustomThemesFile {
    #[serde(default, rename = "theme")]
    pub themes: Vec<CustomThemePreset>,
}

fn built_in_theme_ids() -> Vec<&'static str> {
    vec![
        "violet_dark",
        "rose_dark",
        "blue_dark",
        "green_dark",
        "yellow_dark",
        "red_dark",
        "graphite_dark",
        "violet_light",
        "rose_light",
        "blue_light",
        "green_light",
        "yellow_light",
        "red_light",
        "graphite_light",
    ]
}

fn config_dir() -> Option<PathBuf> {
    let mut path = dirs::config_dir()?;
    path.push("smoothysearch");
    Some(path)
}

pub fn themes_path() -> Option<PathBuf> {
    let mut path = config_dir()?;
    path.push("themes.toml");
    Some(path)
}

pub fn ensure_sample_themes_file_exists() {
    let Some(path) = themes_path() else {
        return;
    };

    if path.exists() {
        return;
    }

    if let Some(parent) = path.parent() {
        let _ = fs::create_dir_all(parent);
    }

    let sample = r##"[[theme]]
    id = "my_theme_dark"
    name = "My Theme Dark"
    window_bg = "#1e1e2e"
    border = "#313244"
    input_bg = "#313244"
    text = "#cdd6f4"
    text_dim = "#a6adc8"
    highlight = "#a970ff"
    highlight_text = "#11111b"

    [[theme]]
    id = "my_theme_light"
    name = "My Theme Light"
    window_bg = "#f3e8ff"
    border = "#d9c4ff"
    input_bg = "#e6d5ff"
    text = "#2b1a44"
    text_dim = "#6a4f9c"
    highlight = "#a970ff"
    highlight_text = "#ffffff"
    "##;

    let _ = fs::write(path, sample);
}

pub fn load_custom_themes() -> Vec<CustomThemePreset> {
    let Some(path) = themes_path() else {
        return Vec::new();
    };

    let Ok(text) = fs::read_to_string(path) else {
        return Vec::new();
    };

    toml::from_str::<CustomThemesFile>(&text)
    .map(|f| {
        f.themes
        .into_iter()
        .filter(|t| {
            !t.id.trim().is_empty()
            && !t.name.trim().is_empty()
            && !t.window_bg.trim().is_empty()
            && !t.border.trim().is_empty()
            && !t.input_bg.trim().is_empty()
            && !t.text.trim().is_empty()
            && !t.text_dim.trim().is_empty()
            && !t.highlight.trim().is_empty()
            && !t.highlight_text.trim().is_empty()
        })
        .collect()
    })
    .unwrap_or_default()
}

fn custom_theme_to_preset(theme: &CustomThemePreset) -> ThemePreset {
    ThemePreset {
        id: theme.id.clone(),
        name: theme.name.clone(),
        window_bg: theme.window_bg.clone(),
        border: theme.border.clone(),
        input_bg: theme.input_bg.clone(),
        text: theme.text.clone(),
        text_dim: theme.text_dim.clone(),
        highlight: theme.highlight.clone(),
        highlight_text: theme.highlight_text.clone(),
    }
}

fn built_in_theme(id: &str) -> Option<ThemePreset> {
    let preset = match id {
        "violet_dark" => ThemePreset {
            id: "violet_dark".to_string(),
            name: "Violet Dark".to_string(),
            window_bg: "#1e1e2e".to_string(),
            border: "#313244".to_string(),
            input_bg: "#313244".to_string(),
            text: "#cdd6f4".to_string(),
            text_dim: "#a6adc8".to_string(),
            highlight: "#a970ff".to_string(),
            highlight_text: "#11111b".to_string(),
        },

        "rose_dark" => ThemePreset {
            id: "rose_dark".to_string(),
            name: "Rose Dark".to_string(),
            window_bg: "#221b24".to_string(),
            border: "#3a2c3c".to_string(),
            input_bg: "#3a2c3c".to_string(),
            text: "#f2d9e6".to_string(),
            text_dim: "#c9a9bb".to_string(),
            highlight: "#ff79c6".to_string(),
            highlight_text: "#1a1018".to_string(),
        },

        "blue_dark" => ThemePreset {
            id: "blue_dark".to_string(),
            name: "Blue Dark".to_string(),
            window_bg: "#1b1f2b".to_string(),
            border: "#2f364a".to_string(),
            input_bg: "#2f364a".to_string(),
            text: "#d6e0ff".to_string(),
            text_dim: "#9aa6c8".to_string(),
            highlight: "#6aa9ff".to_string(),
            highlight_text: "#111521".to_string(),
        },

        "green_dark" => ThemePreset {
            id: "green_dark".to_string(),
            name: "Green Dark".to_string(),
            window_bg: "#1a231f".to_string(),
            border: "#2f3f38".to_string(),
            input_bg: "#2f3f38".to_string(),
            text: "#d9f2e4".to_string(),
            text_dim: "#9ec8b3".to_string(),
            highlight: "#6ee7a2".to_string(),
            highlight_text: "#0f1a15".to_string(),
        },

        "yellow_dark" => ThemePreset {
            id: "yellow_dark".to_string(),
            name: "Yellow Dark".to_string(),
            window_bg: "#262217".to_string(),
            border: "#403726".to_string(),
            input_bg: "#403726".to_string(),
            text: "#f2e9c9".to_string(),
            text_dim: "#c8b88e".to_string(),
            highlight: "#ffd166".to_string(),
            highlight_text: "#1a1508".to_string(),
        },

        "red_dark" => ThemePreset {
            id: "red_dark".to_string(),
            name: "Red Dark".to_string(),
            window_bg: "#26181a".to_string(),
            border: "#402628".to_string(),
            input_bg: "#402628".to_string(),
            text: "#f2d6d8".to_string(),
            text_dim: "#c89a9e".to_string(),
            highlight: "#ff6b6b".to_string(),
            highlight_text: "#1a0c0e".to_string(),
        },

        "graphite_dark" => ThemePreset {
            id: "graphite_dark".to_string(),
            name: "Graphite Dark".to_string(),
            window_bg: "#2e3440".to_string(),
            border: "#434c5e".to_string(),
            input_bg: "#3b4252".to_string(),
            text: "#eceff4".to_string(),
            text_dim: "#d8dee9".to_string(),
            highlight: "#88c0d0".to_string(),
            highlight_text: "#2e3440".to_string(),
        },

        "violet_light" => ThemePreset {
            id: "violet_light".to_string(),
            name: "Violet Light".to_string(),
            window_bg: "#f3e8ff".to_string(),
            border: "#d9c4ff".to_string(),
            input_bg: "#e6d5ff".to_string(),
            text: "#2b1a44".to_string(),
            text_dim: "#6a4f9c".to_string(),
            highlight: "#a970ff".to_string(),
            highlight_text: "#ffffff".to_string(),
        },

        "rose_light" => ThemePreset {
            id: "rose_light".to_string(),
            name: "Rose Light".to_string(),
            window_bg: "#fff0f6".to_string(),
            border: "#f3c4d9".to_string(),
            input_bg: "#f7d8e7".to_string(),
            text: "#3a1f2e".to_string(),
            text_dim: "#7c5a6a".to_string(),
            highlight: "#ff79c6".to_string(),
            highlight_text: "#ffffff".to_string(),
        },

        "blue_light" => ThemePreset {
            id: "blue_light".to_string(),
            name: "Blue Light".to_string(),
            window_bg: "#eef3ff".to_string(),
            border: "#cfd9ff".to_string(),
            input_bg: "#dde6ff".to_string(),
            text: "#1e2a44".to_string(),
            text_dim: "#5c6c99".to_string(),
            highlight: "#4f8cff".to_string(),
            highlight_text: "#ffffff".to_string(),
        },

        "green_light" => ThemePreset {
            id: "green_light".to_string(),
            name: "Green Light".to_string(),
            window_bg: "#ecfdf5".to_string(),
            border: "#b7e4d1".to_string(),
            input_bg: "#d4f5e7".to_string(),
            text: "#1d3b2f".to_string(),
            text_dim: "#4e7c69".to_string(),
            highlight: "#34d399".to_string(),
            highlight_text: "#ffffff".to_string(),
        },

        "yellow_light" => ThemePreset {
            id: "yellow_light".to_string(),
            name: "Yellow Light".to_string(),
            window_bg: "#fff8e6".to_string(),
            border: "#f3e2a9".to_string(),
            input_bg: "#f9efc8".to_string(),
            text: "#3b3213".to_string(),
            text_dim: "#7a6a2e".to_string(),
            highlight: "#ffc857".to_string(),
            highlight_text: "#ffffff".to_string(),
        },

        "red_light" => ThemePreset {
            id: "red_light".to_string(),
            name: "Red Light".to_string(),
            window_bg: "#fff1f2".to_string(),
            border: "#f7c5c8".to_string(),
            input_bg: "#ffd8db".to_string(),
            text: "#3d1c20".to_string(),
            text_dim: "#7f4a50".to_string(),
            highlight: "#ff5d5d".to_string(),
            highlight_text: "#ffffff".to_string(),
        },

        "graphite_light" => ThemePreset {
            id: "graphite_light".to_string(),
            name: "Graphite Light".to_string(),
            window_bg: "#eceff4".to_string(),
            border: "#d8dee9".to_string(),
            input_bg: "#e5e9f0".to_string(),
            text: "#2e3440".to_string(),
            text_dim: "#4c566a".to_string(),
            highlight: "#5e81ac".to_string(),
            highlight_text: "#ffffff".to_string(),
        },

        _ => return None,
    };

    Some(preset)
}

pub fn all_theme_ids() -> Vec<String> {
    let mut ids: Vec<String> = built_in_theme_ids()
    .into_iter()
    .map(|s| s.to_string())
    .collect();

    for custom in load_custom_themes() {
        if let Some(pos) = ids.iter().position(|id| id == &custom.id) {
            ids[pos] = custom.id;
        } else {
            ids.push(custom.id);
        }
    }

    ids
}

pub fn theme_display_name(id: &str) -> String {
    if let Some(custom) = load_custom_themes().into_iter().find(|t| t.id == id) {
        return custom.name;
    }

    built_in_theme(id)
    .map(|t| t.name)
    .unwrap_or_else(|| "Violet Dark".to_string())
}

pub fn get_theme_preset(id: &str) -> ThemePreset {
    if let Some(custom) = load_custom_themes().into_iter().find(|t| t.id == id) {
        return custom_theme_to_preset(&custom);
    }

    built_in_theme(id).unwrap_or_else(|| {
        built_in_theme("violet_dark").expect("built-in violet_dark theme must exist")
    })
}
