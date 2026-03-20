use super::*;
use crate::config::{config_path, load_config, parse_and_normalize_config_text, save_theme_preset};
use crate::theme::{all_theme_ids, ensure_sample_themes_file_exists};

impl ffi::Backend {
    pub(crate) fn apply_loaded_config(mut self: Pin<&mut Self>) {
        let config = load_config();
        let theme = get_theme_preset(&config.theme.preset);

        self.as_mut().set_window_width(config.window.width);
        self.as_mut().set_window_height(config.window.height);
        self.as_mut().set_ui_window_radius(config.ui.window_radius);
        self.as_mut()
            .set_ui_search_bar_radius(config.ui.search_bar_radius);
        self.as_mut()
            .set_ui_selector_radius(config.ui.selector_radius);
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

        if is_config {
            let raw_text = self.themes_file_text().to_string();
            let Ok((_cfg, normalized_text)) = parse_and_normalize_config_text(&raw_text) else {
                return;
            };

            if fs::write(&path, &normalized_text).is_err() {
                return;
            }

            self.as_mut()
                .set_themes_file_text(QString::from(normalized_text.as_str()));
            self.as_mut().apply_loaded_config();
            self.as_mut().load_themes_file();
            return;
        }

        let text = self.themes_file_text().to_string();
        if fs::write(&path, text).is_err() {
            return;
        }

        let current_query = self.current_text().to_string();
        let applied_theme_id = self.applied_theme_id().to_string();
        let applied_id_to_use = if all_theme_ids().iter().any(|id| id == &applied_theme_id) {
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

    pub fn save_selected_theme(self: Pin<&mut Self>) {
        let id = self.applied_theme_id().to_string();
        if !id.is_empty() {
            let _ = save_theme_preset(&id);
        }
    }

    pub fn set_editor_file(mut self: Pin<&mut Self>, is_config: bool) {
        self.as_mut().set_editor_is_config(is_config);
        self.as_mut().load_themes_file();
    }
}
