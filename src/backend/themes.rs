use super::*;
use crate::theme::{all_theme_ids, get_theme_preset, load_custom_themes, theme_display_name};
use fuzzy_matcher::skim::SkimMatcherV2;
use fuzzy_matcher::FuzzyMatcher;

impl BackendRust {
    pub(crate) fn filter_themes(&self, query: &str) -> Vec<EntryItem> {
        let q = query.trim().to_lowercase();
        let theme_ids = all_theme_ids();
        let custom_ids: std::collections::HashSet<String> = load_custom_themes()
            .into_iter()
            .map(|theme| theme.id)
            .collect();

        if q.is_empty() {
            let mut items: Vec<_> = theme_ids
                .iter()
                .map(|id| EntryItem::Theme {
                    id: id.to_string(),
                    name: theme_display_name(id),
                })
                .collect();

            items.sort_by(|a, b| {
                let (a_id, a_name) = match a {
                    EntryItem::Theme { id, name } => (id.as_str(), name.as_str()),
                    _ => ("", ""),
                };
                let (b_id, b_name) = match b {
                    EntryItem::Theme { id, name } => (id.as_str(), name.as_str()),
                    _ => ("", ""),
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
        let mut scored = Vec::new();

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

            scored.push((
                best_score + bonus,
                custom_ids.contains(id),
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

    pub fn is_theme_command_index(self: &ffi::Backend, index: i32) -> bool {
        if index < 0 {
            return false;
        }

        let rust = self.rust();
        matches!(
            rust.filtered_entries.get(index as usize),
            Some(EntryItem::OpenThemeEditor)
        )
    }

    pub(crate) fn apply_theme_properties(mut self: Pin<&mut Self>, theme_id: &str) {
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

    pub fn enter_themes_mode(mut self: Pin<&mut Self>) {
        self.as_mut().set_editor_is_config(false);
        self.as_mut().load_themes_file();
        self.as_mut().switch_mode(AppMode::Themes, true);
    }

    pub fn return_to_apps_mode(mut self: Pin<&mut Self>) {
        self.as_mut().switch_mode(AppMode::Apps, true);
    }
}
