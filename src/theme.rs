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
    id = "my_theme_noir"
    name = "Noir"
    window_bg = "rgba(37, 37, 37, 1.0)"
    border = "rgba(48, 48, 48, 1.0)"
    input_bg = "rgba(64, 64, 64, 1.0)"
    text = "rgba(255, 255, 255, 1.0)"
    text_dim = "rgba(144, 144, 144, 1.0)"
    highlight = "rgba(144, 144, 144, 1.0)"
    highlight_text = "rgba(0, 0, 0, 1.0)"

[[theme]]
    id = "my_theme_catppuccin"
    name = "Catppuccin Mocha"
    window_bg = "rgba(30, 30, 46, 1.0)"
    border = "rgba(49, 50, 68, 1.0)"
    input_bg = "rgba(49, 50, 68, 1.0)"
    text = "rgba(205, 214, 244, 1.0)"
    text_dim = "rgba(166, 173, 200, 1.0)"
    highlight = "rgba(203, 166, 247, 1.0)"
    highlight_text = "rgba(17, 17, 27, 1.0)"

[[theme]]
    id = "my_theme_catppuccin_latte"
    name = "Catppuccin Latte"
    window_bg = "rgba(239, 241, 245, 1.0)"
    border = "rgba(204, 208, 218, 1.0)"
    input_bg = "rgba(220, 224, 232, 1.0)"
    text = "rgba(76, 79, 105, 1.0)"
    text_dim = "rgba(124, 127, 147, 1.0)"
    highlight = "rgba(136, 57, 239, 1.0)"
    highlight_text = "rgba(255, 255, 255, 1.0)"

[[theme]]
    id = "my_theme_catppuccin_frappe"
    name = "Catppuccin Frappe"
    window_bg = "rgba(48, 52, 70, 1.0)"
    border = "rgba(65, 69, 89, 1.0)"
    input_bg = "rgba(65, 69, 89, 1.0)"
    text = "rgba(198, 208, 245, 1.0)"
    text_dim = "rgba(165, 173, 206, 1.0)"
    highlight = "rgba(202, 158, 230, 1.0)"
    highlight_text = "rgba(35, 38, 52, 1.0)"

[[theme]]
    id = "my_theme_catppuccin_macchiato"
    name = "Catppuccin Macchiato"
    window_bg = "rgba(36, 39, 58, 1.0)"
    border = "rgba(54, 58, 79, 1.0)"
    input_bg = "rgba(54, 58, 79, 1.0)"
    text = "rgba(202, 211, 245, 1.0)"
    text_dim = "rgba(165, 173, 203, 1.0)"
    highlight = "rgba(198, 160, 246, 1.0)"
    highlight_text = "rgba(24, 25, 38, 1.0)"

[[theme]]
    id = "everforest_dark_soft"
    name = "Everforest Dark Soft"
    window_bg = "rgba(41, 49, 54, 1.0)"
    border = "rgba(60, 72, 65, 1.0)"
    input_bg = "rgba(47, 56, 62, 1.0)"
    text = "rgba(211, 198, 170, 1.0)"
    text_dim = "rgba(133, 146, 137, 1.0)"
    highlight = "rgba(167, 192, 128, 1.0)"
    highlight_text = "rgba(45, 53, 59, 1.0)"

[[theme]]
    id = "everforest_light_soft"
    name = "Everforest Light Soft"
    window_bg = "rgba(255, 241, 245, 0.96)"
    border = "rgba(220, 169, 188, 1.0)"
    input_bg = "rgba(247, 221, 230, 0.92)"
    text = "rgba(100, 75, 89, 1.0)"
    text_dim = "rgba(220, 169, 188, 1.0)"
    highlight = "rgba(217, 138, 173, 1.0)"
    highlight_text = "rgba(255, 241, 245, 1.0)"
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
                .filter(|t| !t.id.trim().is_empty() && !t.name.trim().is_empty())
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

fn normalize_hex_color(value: &str) -> Option<String> {
    let s = value.trim();
    let hex = s.strip_prefix('#')?;

    if !matches!(hex.len(), 6 | 8) || !hex.chars().all(|c| c.is_ascii_hexdigit()) {
        return None;
    }

    let upper = hex.to_ascii_uppercase();
    Some(if upper.len() == 6 {
        format!("#FF{upper}")
    } else {
        format!("#{upper}")
    })
}

fn normalize_rgba_color(value: &str) -> Option<String> {
    let s = value.trim();
    let inner = s.strip_prefix("rgba(")?.strip_suffix(')')?;
    let parts = inner.split(',').map(str::trim).collect::<Vec<_>>();

    if parts.len() != 4 {
        return None;
    }

    let r = parts[0].parse::<u8>().ok()?;
    let g = parts[1].parse::<u8>().ok()?;
    let b = parts[2].parse::<u8>().ok()?;
    let alpha = parts[3].parse::<f32>().ok()?;

    if !(0.0..=1.0).contains(&alpha) {
        return None;
    }

    let a = (alpha * 255.0).round() as u8;
    Some(format!("#{a:02X}{r:02X}{g:02X}{b:02X}"))
}

fn normalize_color(value: &str) -> Option<String> {
    normalize_hex_color(value).or_else(|| normalize_rgba_color(value))
}

fn sanitize_color(value: &str, fallback: &str) -> String {
    normalize_color(value).unwrap_or_else(|| fallback.to_string())
}

fn normalize_theme(theme: ThemePreset) -> ThemePreset {
    ThemePreset {
        id: theme.id,
        name: theme.name,
        window_bg: normalize_color(&theme.window_bg).unwrap_or(theme.window_bg),
        border: normalize_color(&theme.border).unwrap_or(theme.border),
        input_bg: normalize_color(&theme.input_bg).unwrap_or(theme.input_bg),
        text: normalize_color(&theme.text).unwrap_or(theme.text),
        text_dim: normalize_color(&theme.text_dim).unwrap_or(theme.text_dim),
        highlight: normalize_color(&theme.highlight).unwrap_or(theme.highlight),
        highlight_text: normalize_color(&theme.highlight_text).unwrap_or(theme.highlight_text),
    }
}

fn fallback_theme_id_for(theme_id: &str) -> &'static str {
    if theme_id.ends_with("_light") {
        "graphite_light"
    } else {
        "graphite_dark"
    }
}

fn sanitize_theme(theme_id: &str, theme: ThemePreset) -> ThemePreset {
    let fallback = normalize_theme(
        built_in_theme(fallback_theme_id_for(theme_id)).expect("fallback theme must exist"),
    );

    ThemePreset {
        id: theme.id,
        name: theme.name,
        window_bg: sanitize_color(&theme.window_bg, &fallback.window_bg),
        border: sanitize_color(&theme.border, &fallback.border),
        input_bg: sanitize_color(&theme.input_bg, &fallback.input_bg),
        text: sanitize_color(&theme.text, &fallback.text),
        text_dim: sanitize_color(&theme.text_dim, &fallback.text_dim),
        highlight: sanitize_color(&theme.highlight, &fallback.highlight),
        highlight_text: sanitize_color(&theme.highlight_text, &fallback.highlight_text),
    }
}

fn built_in_theme(id: &str) -> Option<ThemePreset> {
    let preset = match id {
        "violet_dark" => ThemePreset {
            id: "violet_dark".to_string(),
            name: "Violet Dark".to_string(),
            window_bg: "rgba(30, 30, 46, 1.0)".to_string(),
            border: "rgba(49, 50, 68, 1.0)".to_string(),
            input_bg: "rgba(49, 50, 68, 1.0)".to_string(),
            text: "rgba(205, 214, 244, 1.0)".to_string(),
            text_dim: "rgba(166, 173, 200, 1.0)".to_string(),
            highlight: "rgba(169, 112, 255, 1.0)".to_string(),
            highlight_text: "rgba(0, 0, 0, 1.0)".to_string(),
        },

        "rose_dark" => ThemePreset {
            id: "rose_dark".to_string(),
            name: "Rose Dark".to_string(),
            window_bg: "rgba(34, 27, 36, 1.0)".to_string(),
            border: "rgba(58, 44, 60, 1.0)".to_string(),
            input_bg: "rgba(58, 44, 60, 1.0)".to_string(),
            text: "rgba(242, 217, 230, 1.0)".to_string(),
            text_dim: "rgba(201, 169, 187, 1.0)".to_string(),
            highlight: "rgba(255, 121, 198, 1.0)".to_string(),
            highlight_text: "rgba(0, 0, 0, 1.0)".to_string(),
        },

        "blue_dark" => ThemePreset {
            id: "blue_dark".to_string(),
            name: "Blue Dark".to_string(),
            window_bg: "rgba(27, 31, 43, 1.0)".to_string(),
            border: "rgba(47, 54, 74, 1.0)".to_string(),
            input_bg: "rgba(47, 54, 74, 1.0)".to_string(),
            text: "rgba(214, 224, 255, 1.0)".to_string(),
            text_dim: "rgba(154, 166, 200, 1.0)".to_string(),
            highlight: "rgba(106, 169, 255, 1.0)".to_string(),
            highlight_text: "rgba(0, 0, 0, 1.0)".to_string(),
        },

        "green_dark" => ThemePreset {
            id: "green_dark".to_string(),
            name: "Green Dark".to_string(),
            window_bg: "rgba(26, 35, 31, 1.0)".to_string(),
            border: "rgba(47, 63, 56, 1.0)".to_string(),
            input_bg: "rgba(47, 63, 56, 1.0)".to_string(),
            text: "rgba(217, 242, 228, 1.0)".to_string(),
            text_dim: "rgba(158, 200, 179, 1.0)".to_string(),
            highlight: "rgba(110, 231, 162, 1.0)".to_string(),
            highlight_text: "rgba(17, 17, 27, 1.0)".to_string(),
        },

        "yellow_dark" => ThemePreset {
            id: "yellow_dark".to_string(),
            name: "Yellow Dark".to_string(),
            window_bg: "rgba(38, 34, 23, 1.0)".to_string(),
            border: "rgba(64, 55, 38, 1.0)".to_string(),
            input_bg: "rgba(64, 55, 38, 1.0)".to_string(),
            text: "rgba(242, 233, 201, 1.0)".to_string(),
            text_dim: "rgba(200, 184, 142, 1.0)".to_string(),
            highlight: "rgba(255, 209, 102, 1.0)".to_string(),
            highlight_text: "rgba(17, 17, 27, 1.0)".to_string(),
        },

        "red_dark" => ThemePreset {
            id: "red_dark".to_string(),
            name: "Red Dark".to_string(),
            window_bg: "rgba(38, 24, 26, 1.0)".to_string(),
            border: "rgba(64, 38, 40, 1.0)".to_string(),
            input_bg: "rgba(64, 38, 40, 1.0)".to_string(),
            text: "rgba(242, 214, 216, 1.0)".to_string(),
            text_dim: "rgba(200, 154, 158, 1.0)".to_string(),
            highlight: "rgba(255, 107, 107, 1.0)".to_string(),
            highlight_text: "rgba(17, 17, 27, 1.0)".to_string(),
        },

        "graphite_dark" => ThemePreset {
            id: "graphite_dark".to_string(),
            name: "Graphite Dark".to_string(),
            window_bg: "rgba(46, 52, 64, 1.0)".to_string(),
            border: "rgba(67, 76, 94, 1.0)".to_string(),
            input_bg: "rgba(59, 66, 82, 1.0)".to_string(),
            text: "rgba(236, 239, 244, 1.0)".to_string(),
            text_dim: "rgba(216, 222, 233, 1.0)".to_string(),
            highlight: "rgba(136, 192, 208, 1.0)".to_string(),
            highlight_text: "rgba(46, 52, 64, 1.0)".to_string(),
        },

        "violet_light" => ThemePreset {
            id: "violet_light".to_string(),
            name: "Violet Light".to_string(),
            window_bg: "rgba(243, 232, 255, 1.0)".to_string(),
            border: "rgba(217, 196, 255, 1.0)".to_string(),
            input_bg: "rgba(230, 213, 255, 1.0)".to_string(),
            text: "rgba(43, 26, 68, 1.0)".to_string(),
            text_dim: "rgba(106, 79, 156, 1.0)".to_string(),
            highlight: "rgba(169, 112, 255, 1.0)".to_string(),
            highlight_text: "rgba(255, 255, 255, 1.0)".to_string(),
        },

        "rose_light" => ThemePreset {
            id: "rose_light".to_string(),
            name: "Rose Light".to_string(),
            window_bg: "rgba(255, 240, 246, 1.0)".to_string(),
            border: "rgba(243, 196, 217, 1.0)".to_string(),
            input_bg: "rgba(247, 216, 231, 1.0)".to_string(),
            text: "rgba(58, 31, 46, 1.0)".to_string(),
            text_dim: "rgba(124, 90, 106, 1.0)".to_string(),
            highlight: "rgba(255, 121, 198, 1.0)".to_string(),
            highlight_text: "rgba(46, 52, 64, 1.0)".to_string(),
        },

        "blue_light" => ThemePreset {
            id: "blue_light".to_string(),
            name: "Blue Light".to_string(),
            window_bg: "rgba(238, 243, 255, 1.0)".to_string(),
            border: "rgba(207, 217, 255, 1.0)".to_string(),
            input_bg: "rgba(221, 230, 255, 1.0)".to_string(),
            text: "rgba(30, 42, 68, 1.0)".to_string(),
            text_dim: "rgba(92, 108, 153, 1.0)".to_string(),
            highlight: "rgba(79, 140, 255, 1.0)".to_string(),
            highlight_text: "rgba(255, 255, 255, 1.0)".to_string(),
        },

        "green_light" => ThemePreset {
            id: "green_light".to_string(),
            name: "Green Light".to_string(),
            window_bg: "rgba(236, 253, 245, 1.0)".to_string(),
            border: "rgba(183, 228, 209, 1.0)".to_string(),
            input_bg: "rgba(212, 245, 231, 1.0)".to_string(),
            text: "rgba(29, 59, 47, 1.0)".to_string(),
            text_dim: "rgba(78, 124, 105, 1.0)".to_string(),
            highlight: "rgba(52, 211, 153, 1.0)".to_string(),
            highlight_text: "rgba(46, 52, 64, 1.0)".to_string(),
        },

        "yellow_light" => ThemePreset {
            id: "yellow_light".to_string(),
            name: "Yellow Light".to_string(),
            window_bg: "rgba(255, 248, 230, 1.0)".to_string(),
            border: "rgba(243, 226, 169, 1.0)".to_string(),
            input_bg: "rgba(249, 239, 200, 1.0)".to_string(),
            text: "rgba(59, 50, 19, 1.0)".to_string(),
            text_dim: "rgba(122, 106, 46, 1.0)".to_string(),
            highlight: "rgba(255, 200, 87, 1.0)".to_string(),
            highlight_text: "rgba(46, 52, 64, 1.0)".to_string(),
        },

        "red_light" => ThemePreset {
            id: "red_light".to_string(),
            name: "Red Light".to_string(),
            window_bg: "rgba(255, 241, 242, 1.0)".to_string(),
            border: "rgba(247, 197, 200, 1.0)".to_string(),
            input_bg: "rgba(255, 216, 219, 1.0)".to_string(),
            text: "rgba(61, 28, 32, 1.0)".to_string(),
            text_dim: "rgba(127, 74, 80, 1.0)".to_string(),
            highlight: "rgba(255, 93, 93, 1.0)".to_string(),
            highlight_text: "rgba(46, 52, 64, 1.0)".to_string(),
        },

        "graphite_light" => ThemePreset {
            id: "graphite_light".to_string(),
            name: "Graphite Light".to_string(),
            window_bg: "rgba(236, 239, 244, 1.0)".to_string(),
            border: "rgba(216, 222, 233, 1.0)".to_string(),
            input_bg: "rgba(229, 233, 240, 1.0)".to_string(),
            text: "rgba(46, 52, 64, 1.0)".to_string(),
            text_dim: "rgba(76, 86, 106, 1.0)".to_string(),
            highlight: "rgba(94, 129, 172, 1.0)".to_string(),
            highlight_text: "rgba(255, 255, 255, 1.0)".to_string(),
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
        .unwrap_or_else(|| "Graphite Dark".to_string())
}

pub fn get_theme_preset(id: &str) -> ThemePreset {
    if let Some(custom) = load_custom_themes().into_iter().find(|t| t.id == id) {
        let preset = custom_theme_to_preset(&custom);
        return sanitize_theme(id, preset);
    }

    built_in_theme(id).map(normalize_theme).unwrap_or_else(|| {
        normalize_theme(
            built_in_theme("violet_dark").expect("built-in violet_dark theme must exist"),
        )
    })
}
