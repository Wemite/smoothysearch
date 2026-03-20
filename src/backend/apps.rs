use super::*;
use crate::config::load_config;
use fuzzy_matcher::skim::SkimMatcherV2;
use fuzzy_matcher::FuzzyMatcher;

#[derive(Clone, Debug)]
enum DesktopExecFragment {
    Literal(String),
    Field(char),
}

impl BackendRust {
    fn push_pending_arg(args: &mut Vec<String>, current: &mut String) {
        if !current.is_empty() {
            args.push(std::mem::take(current));
        }
    }

    fn command_exists(command: &str) -> bool {
        let trimmed = command.trim();
        if trimmed.is_empty() {
            return false;
        }

        if Path::new(trimmed).is_absolute() {
            return Path::new(trimmed).is_file();
        }

        Self::is_in_path(trimmed)
    }

    fn parse_bool(value: Option<&String>) -> bool {
        value
            .map(|v| v.trim().eq_ignore_ascii_case("true"))
            .unwrap_or(false)
    }

    fn parse_desktop_entry_map(content: &str) -> HashMap<String, String> {
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

        map
    }

    fn push_desktop_exec_literal(fragments: &mut Vec<DesktopExecFragment>, ch: char) {
        if let Some(DesktopExecFragment::Literal(existing)) = fragments.last_mut() {
            existing.push(ch);
            return;
        }

        fragments.push(DesktopExecFragment::Literal(ch.to_string()));
    }

    fn resolve_desktop_exec_field(
        code: char,
        app_name: &str,
        icon: Option<&str>,
        desktop_path: &Path,
    ) -> Vec<String> {
        match code {
            'f' | 'F' | 'u' | 'U' | 'd' | 'D' | 'n' | 'N' | 'v' | 'm' => Vec::new(),
            'k' => desktop_path
                .to_str()
                .map(|value| vec![value.to_string()])
                .unwrap_or_default(),
            'i' => icon
                .filter(|value| !value.trim().is_empty())
                .map(|value| vec!["--icon".to_string(), value.trim().to_string()])
                .unwrap_or_default(),
            '%' => vec!["%".to_string()],
            'c' => (!app_name.is_empty())
                .then(|| app_name.to_string())
                .into_iter()
                .collect(),
            _ => {
                let mut value = String::from("%");
                value.push(code);
                vec![value]
            }
        }
    }

    fn flush_desktop_exec_fragments(
        args: &mut Vec<String>,
        fragments: &mut Vec<DesktopExecFragment>,
        app_name: &str,
        icon: Option<&str>,
        desktop_path: &Path,
    ) {
        if fragments.is_empty() {
            return;
        }

        if let [DesktopExecFragment::Field('i')] = fragments.as_slice() {
            args.extend(Self::resolve_desktop_exec_field(
                'i',
                app_name,
                icon,
                desktop_path,
            ));
            fragments.clear();
            return;
        }

        let mut current = String::new();
        for fragment in fragments.iter() {
            match fragment {
                DesktopExecFragment::Literal(value) => current.push_str(value),
                DesktopExecFragment::Field(code) => {
                    let replacement =
                        Self::resolve_desktop_exec_field(*code, app_name, icon, desktop_path);
                    if replacement.len() == 1 {
                        current.push_str(&replacement[0]);
                    }
                }
            }
        }

        if !current.is_empty() {
            args.push(current);
        }

        fragments.clear();
    }

    fn parse_desktop_exec_args(
        exec: &str,
        app_name: &str,
        icon: Option<&str>,
        desktop_path: &Path,
    ) -> Vec<String> {
        let mut args = Vec::new();
        let mut fragments = Vec::new();
        let mut in_single_quotes = false;
        let mut in_double_quotes = false;
        let mut chars = exec.chars().peekable();

        while let Some(ch) = chars.next() {
            match ch {
                '\'' if !in_double_quotes => in_single_quotes = !in_single_quotes,
                '"' if !in_single_quotes => in_double_quotes = !in_double_quotes,
                '\\' if in_single_quotes => Self::push_desktop_exec_literal(&mut fragments, ch),
                '\\' => {
                    if let Some(next) = chars.next() {
                        if in_double_quotes {
                            match next {
                                '"' | '\\' | '`' | '$' => {
                                    Self::push_desktop_exec_literal(&mut fragments, next)
                                }
                                '\n' => {}
                                _ => {
                                    Self::push_desktop_exec_literal(&mut fragments, '\\');
                                    Self::push_desktop_exec_literal(&mut fragments, next);
                                }
                            }
                        } else {
                            Self::push_desktop_exec_literal(&mut fragments, next);
                        }
                    } else {
                        Self::push_desktop_exec_literal(&mut fragments, '\\');
                    }
                }
                '%' => {
                    if let Some(next) = chars.peek().copied() {
                        match next {
                            'f' | 'F' | 'u' | 'U' | 'd' | 'D' | 'n' | 'N' | 'i' | 'c' | 'k'
                            | 'v' | 'm' | '%' => {
                                chars.next();
                                fragments.push(DesktopExecFragment::Field(next));
                            }
                            _ => Self::push_desktop_exec_literal(&mut fragments, '%'),
                        }
                    } else {
                        Self::push_desktop_exec_literal(&mut fragments, '%');
                    }
                }
                ' ' | '\t' | '\n' if !in_single_quotes && !in_double_quotes => {
                    Self::flush_desktop_exec_fragments(
                        &mut args,
                        &mut fragments,
                        app_name,
                        icon,
                        desktop_path,
                    )
                }
                _ => Self::push_desktop_exec_literal(&mut fragments, ch),
            }
        }

        Self::flush_desktop_exec_fragments(&mut args, &mut fragments, app_name, icon, desktop_path);
        args
    }

    fn launch_args_look_like_self(args: &[String]) -> bool {
        let Some(command) = args.first() else {
            return false;
        };

        let Some(command_name) = Path::new(command)
            .file_name()
            .and_then(|value| value.to_str())
        else {
            return false;
        };

        command_name == "smoothysearch"
    }

    fn effective_working_dir(working_dir: Option<&str>) -> PathBuf {
        let home = Self::home_dir();
        let fallback = PathBuf::from(home);

        let Some(value) = working_dir.map(str::trim).filter(|value| !value.is_empty()) else {
            return fallback;
        };

        let path = PathBuf::from(value);
        if path.is_dir() {
            path
        } else {
            fallback
        }
    }

    pub(crate) fn run_shell_args(args: &[String], working_dir: Option<&str>) {
        if args.is_empty() {
            eprintln!("[smoothysearch] run_shell_args: empty exec args");
            return;
        }

        let working_dir = Self::effective_working_dir(working_dir);

        if let Ok(child) = Command::new(&args[0])
            .current_dir(&working_dir)
            .args(&args[1..])
            .spawn()
        {
            Self::try_center_window_for_pid(child.id());
        }
    }

    fn terminal_command_args(command_args: &[String]) -> Vec<String> {
        let mut run_args = vec![
            "bash".to_string(),
            "--noprofile".to_string(),
            "--norc".to_string(),
            "-c".to_string(),
            "\"$@\"; exec bash --noprofile --norc -i".to_string(),
            "--".to_string(),
        ];
        run_args.extend_from_slice(command_args);
        run_args
    }

    pub(crate) fn run_in_terminal_args(command_args: &[String], working_dir: Option<&str>) {
        if command_args.is_empty() {
            eprintln!("[smoothysearch] run_in_terminal_args: empty exec args");
            return;
        }

        let Some(terminal) = Self::detect_terminal() else {
            eprintln!("[smoothysearch] run_in_terminal: no terminal emulator found");
            return;
        };

        let args =
            Self::terminal_launch_args(&terminal, &Self::terminal_command_args(command_args));
        let working_dir = Self::effective_working_dir(working_dir);
        let _ = Command::new(&terminal)
            .current_dir(&working_dir)
            .args(&args)
            .spawn();
    }

    fn parse_desktop_file(path: &Path) -> Option<AppItem> {
        let content = fs::read_to_string(path).ok()?;
        let map = Self::parse_desktop_entry_map(&content);

        if map.get("Type").map(|s| s.as_str()) != Some("Application") {
            return None;
        }

        if Self::parse_bool(map.get("NoDisplay")) || Self::parse_bool(map.get("Hidden")) {
            return None;
        }

        let name = map.get("Name")?.trim().to_string();
        let exec = map.get("Exec")?.trim().to_string();
        let icon = map.get("Icon").map(String::as_str);
        let launch_args = Self::parse_desktop_exec_args(&exec, &name, icon, path);
        let try_exec = map
            .get("TryExec")
            .map(|value| value.trim())
            .unwrap_or_default();

        if name.is_empty() || exec.is_empty() || launch_args.is_empty() {
            return None;
        }

        if !try_exec.is_empty() && !Self::command_exists(try_exec) {
            return None;
        }

        let terminal = Self::parse_bool(map.get("Terminal"));
        let name_lower = name.to_lowercase();
        let working_dir = map
            .get("Path")
            .map(|value| value.trim())
            .filter(|value| !value.is_empty())
            .map(str::to_string);

        Some(AppItem {
            name,
            name_lower,
            exec,
            launch_args,
            terminal,
            working_dir,
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
                    .and_then(|t| t.duration_since(UNIX_EPOCH).ok())
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
        let content = fs::read_to_string(Self::cache_file()).ok()?;
        match serde_json::from_str(&content) {
            Ok(cache) => Some(cache),
            Err(err) => {
                eprintln!("[smoothysearch] app cache parse error: {err}, will rebuild");
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

        let _ = fs::create_dir_all(Self::cache_dir());
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

                if Self::launch_args_look_like_self(&app.launch_args) {
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
        apps.sort_by_key(|app| app.name.to_lowercase());
        apps
    }

    pub(crate) fn invalidate_app_cache() {
        let _ = fs::remove_file(Self::cache_file());
    }

    pub(crate) fn load_desktop_apps() -> Vec<AppItem> {
        let signatures = Self::collect_desktop_signatures();

        if let Some(cache) = Self::read_cache() {
            if cache.signatures == signatures
                && cache.apps.iter().all(|app| !app.launch_args.is_empty())
            {
                return cache.apps;
            }
        }

        let apps = Self::build_apps_from_desktop_files();
        Self::write_cache(signatures, &apps);
        apps
    }

    pub(crate) fn filter_apps(&self, query: &str) -> Vec<AppItem> {
        let q = query.trim().to_lowercase();

        if q.is_empty() {
            return self.all_apps.clone();
        }

        let matcher = SkimMatcherV2::default();
        let mut scored = Vec::new();

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

    fn parse_exec_args(exec: &str) -> Vec<String> {
        let mut args = Vec::new();
        let mut current = String::new();
        let mut in_single_quotes = false;
        let mut in_double_quotes = false;
        let mut chars = exec.chars().peekable();

        while let Some(ch) = chars.next() {
            match ch {
                '\'' if !in_double_quotes => in_single_quotes = !in_single_quotes,
                '"' if !in_single_quotes => in_double_quotes = !in_double_quotes,
                '\\' if in_single_quotes => current.push(ch),
                '\\' => {
                    if let Some(next) = chars.next() {
                        if in_double_quotes {
                            match next {
                                '"' | '\\' | '`' | '$' => current.push(next),
                                '\n' => {}
                                _ => {
                                    current.push('\\');
                                    current.push(next);
                                }
                            }
                        } else {
                            current.push(next);
                        }
                    } else {
                        current.push('\\');
                    }
                }
                ' ' | '\t' | '\n' if !in_single_quotes && !in_double_quotes => {
                    Self::push_pending_arg(&mut args, &mut current)
                }
                _ => current.push(ch),
            }
        }

        Self::push_pending_arg(&mut args, &mut current);

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
                        .map(|status| status.success())
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
                        .args(["dispatch", "focuswindow", &format!("pid:{pid}")])
                        .stdout(Stdio::null())
                        .stderr(Stdio::null())
                        .status()
                        .map(|status| status.success())
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
            }
        });
    }

    fn is_in_path(name: &str) -> bool {
        std::env::var("PATH")
            .ok()
            .map(|path_var| {
                path_var
                    .split(':')
                    .any(|dir| PathBuf::from(dir).join(name).is_file())
            })
            .unwrap_or(false)
    }

    fn find_desktop_file(name: &str) -> Option<PathBuf> {
        let base = name.trim().trim_end_matches(".desktop");
        let with_ext = if name.ends_with(".desktop") {
            name.to_string()
        } else {
            format!("{base}.desktop")
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
        let map = Self::parse_desktop_entry_map(&content);
        let name = map.get("Name").map(String::as_str).unwrap_or_default();
        let exec_line = map.get("Exec")?.trim();
        let icon = map.get("Icon").map(String::as_str);
        let args = Self::parse_desktop_exec_args(exec_line, name, icon, path);

        for token in args {
            if token == "env" || token.contains('=') {
                continue;
            }

            let exe = token.trim();
            if exe.is_empty() {
                continue;
            }

            if Path::new(exe).is_absolute() || Self::is_in_path(exe) {
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
                let value = rest.trim().trim_matches('"');
                if !value.is_empty() {
                    terminal_application = Some(value.to_string());
                }
            }
            if let Some(rest) = line.strip_prefix("TerminalService=") {
                let value = rest.trim().trim_matches('"');
                if !value.is_empty() {
                    terminal_service = Some(value.to_string());
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
        let path = PathBuf::from(format!("{}/.config/kdeglobals", Self::home_dir()));
        if !path.is_file() {
            return None;
        }

        let (term_app, term_service) = Self::read_kdeglobals_terminal(&path)?;
        if let Some(service) = term_service {
            if let Some(desktop_path) = Self::find_desktop_file(&service) {
                if let Some(exec) = Self::exec_from_desktop(&desktop_path) {
                    return Some(exec);
                }
            }
        }

        if let Some(app) = term_app {
            let app = app.trim();
            if Path::new(app).is_absolute() {
                return Path::new(app).is_file().then(|| app.to_string());
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
            format!("{home}/.config/xdg-terminals.list"),
            "/etc/xdg/xdg-terminals.list".to_string(),
        ];

        for path_str in candidates {
            let path = Path::new(&path_str);
            if !path.is_file() {
                continue;
            }

            let content = match fs::read_to_string(path) {
                Ok(content) => content,
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
        let output = Command::new("gsettings")
            .args([
                "get",
                "org.gnome.desktop.default-applications.terminal",
                "exec",
            ])
            .output()
            .ok()?;

        if !output.status.success() {
            return None;
        }

        let value = String::from_utf8_lossy(&output.stdout);
        let exec = value.trim().trim_matches('\'').split_whitespace().next()?;

        if exec.is_empty() {
            return None;
        }
        if Path::new(exec).is_absolute() {
            return Path::new(exec).is_file().then(|| exec.to_string());
        }
        Self::is_in_path(exec).then(|| exec.to_string())
    }

    fn default_terminal_kde() -> Option<String> {
        for cmd in ["kreadconfig6", "kreadconfig"] {
            let output = Command::new(cmd)
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

            if !output.status.success() {
                continue;
            }

            let exec = String::from_utf8_lossy(&output.stdout).trim().to_string();
            if exec.is_empty() {
                continue;
            }
            if Path::new(&exec).is_absolute() {
                if Path::new(&exec).is_file() {
                    return Some(exec);
                }
                continue;
            }
            if Self::is_in_path(&exec) {
                return Some(exec);
            }
        }

        None
    }

    fn detect_terminal() -> Option<String> {
        if let Ok(term) = std::env::var("TERMINAL") {
            let term = term.trim().to_string();
            if !term.is_empty()
                && ((term.contains('/') && Path::new(&term).is_file()) || Self::is_in_path(&term))
            {
                return Some(term);
            }
        }

        Self::default_terminal_kde_from_config()
            .or_else(Self::default_terminal_kde)
            .or_else(Self::default_terminal_gnome)
            .or_else(Self::default_terminal_xdg_list)
            .or_else(|| Self::is_in_path("xdg-terminal-exec").then(|| "xdg-terminal-exec".into()))
            .or_else(|| {
                Self::is_in_path("x-terminal-emulator").then(|| "x-terminal-emulator".into())
            })
            .or_else(|| {
                [
                    "konsole",
                    "gnome-terminal",
                    "xfce4-terminal",
                    "alacritty",
                    "kitty",
                    "foot",
                    "wezterm",
                    "tilix",
                ]
                .into_iter()
                .find(|name| Self::is_in_path(name))
                .map(str::to_string)
            })
    }

    fn terminal_launch_args(terminal: &str, cmd_args: &[String]) -> Vec<String> {
        let name = Path::new(terminal)
            .file_name()
            .and_then(|value| value.to_str())
            .unwrap_or(terminal);

        let mut args = match name {
            "gnome-terminal" => vec!["--".to_string()],
            "wezterm" => vec!["start".to_string(), "--".to_string()],
            "konsole" => vec!["--hold".to_string(), "-e".to_string()],
            "xdg-terminal-exec" | "kitty" | "foot" => vec![],
            _ => vec!["-e".to_string()],
        };
        args.extend_from_slice(cmd_args);
        args
    }

    fn url_encode_query(text: &str) -> String {
        let mut out = String::with_capacity(text.len());

        for byte in text.as_bytes() {
            match *byte {
                b'A'..=b'Z' | b'a'..=b'z' | b'0'..=b'9' | b'-' | b'_' | b'.' | b'~' => {
                    out.push(*byte as char)
                }
                b' ' => out.push('+'),
                _ => {
                    out.push('%');
                    for &hex in &[byte >> 4, byte & 15] {
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
            format!("https://{trimmed}")
        };

        let normalized = if base.ends_with('/') {
            base
        } else {
            format!("{base}/")
        };

        let host = normalized
            .split("://")
            .nth(1)
            .and_then(|rest| rest.split('/').next())
            .map(|value| value.to_ascii_lowercase())?;

        Some(
            if host == "duckduckgo.com" || host.ends_with(".duckduckgo.com") {
                format!("{normalized}?q={encoded_query}")
            } else if host == "google.com"
                || host.ends_with(".google.com")
                || host == "google.ru"
                || host.ends_with(".google.ru")
                || host == "bing.com"
                || host.ends_with(".bing.com")
                || host == "search.brave.com"
                || host == "ecosia.org"
                || host.ends_with(".ecosia.org")
            {
                format!("{normalized}search?q={encoded_query}")
            } else if host == "startpage.com" || host.ends_with(".startpage.com") {
                format!("{normalized}sp/search?query={encoded_query}")
            } else if host == "search.yahoo.com"
                || host.ends_with(".search.yahoo.com")
                || host == "yahoo.com"
                || host.ends_with(".yahoo.com")
            {
                format!("{normalized}search?p={encoded_query}")
            } else if host == "yandex.ru"
                || host.ends_with(".yandex.ru")
                || host == "yandex.com"
                || host.ends_with(".yandex.com")
                || host == "ya.ru"
                || host.ends_with(".ya.ru")
            {
                format!("{normalized}search/?text={encoded_query}")
            } else {
                format!("{normalized}?q={encoded_query}")
            },
        )
    }

    pub(crate) fn open_search_in_browser(query: &str) {
        let query = query.trim();
        if query.is_empty() {
            return;
        }

        let encoded = Self::url_encode_query(query);
        let cfg = load_config();
        let url = Self::search_url_for_template(&cfg.search.url_template, &encoded)
            .unwrap_or_else(|| format!("https://duckduckgo.com/?q={encoded}"));

        if url.starts_with("https://") || url.starts_with("http://") {
            let url = QString::from(url.as_str());
            let _ = ffi::open_url_with_activation(&url);
        }
    }

    pub(crate) fn run_in_terminal(command: &str) {
        let cmd_args = Self::parse_exec_args(command);

        if cmd_args.is_empty() {
            eprintln!("[smoothysearch] run_in_terminal: empty exec after parsing: {command:?}");
            return;
        }

        Self::run_in_terminal_args(&cmd_args, None);
    }
}

impl ffi::Backend {
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
}

#[cfg(test)]
mod tests {
    use super::BackendRust;
    use std::fs;
    use std::path::PathBuf;
    use std::time::{SystemTime, UNIX_EPOCH};

    fn temp_desktop_file(name: &str, content: &str) -> PathBuf {
        let unique = SystemTime::now()
            .duration_since(UNIX_EPOCH)
            .unwrap()
            .as_nanos();
        let path = std::env::temp_dir().join(format!("smoothysearch-{name}-{unique}.desktop"));
        fs::write(&path, content).unwrap();
        path
    }

    #[test]
    fn parse_exec_args_supports_single_quotes() {
        let args = BackendRust::parse_exec_args("sh -c 'echo hello world'");
        assert_eq!(args, vec!["sh", "-c", "echo hello world"]);
    }

    #[test]
    fn parse_exec_args_supports_escaped_spaces() {
        let args = BackendRust::parse_exec_args(r#"env FOO=1 my\ app --title "hello world""#);
        assert_eq!(
            args,
            vec!["env", "FOO=1", "my app", "--title", "hello world"]
        );
    }

    #[test]
    fn parse_exec_args_supports_double_quote_escapes() {
        let args = BackendRust::parse_exec_args(r#"bash -lc "printf \"%s\" \"$HOME\"""#);
        assert_eq!(args, vec!["bash", "-lc", r#"printf "%s" "$HOME""#]);
    }

    #[test]
    fn parse_desktop_exec_args_expands_known_field_codes() {
        let desktop_path = PathBuf::from("/tmp/example.desktop");
        let args = BackendRust::parse_desktop_exec_args(
            r#"env FOO=1 app --title %c --from %k %i %% "#,
            "My App",
            Some("app-icon"),
            &desktop_path,
        );

        assert_eq!(
            args,
            vec![
                "env",
                "FOO=1",
                "app",
                "--title",
                "My App",
                "--from",
                "/tmp/example.desktop",
                "--icon",
                "app-icon",
                "%",
            ]
        );
    }

    #[test]
    fn parse_desktop_file_skips_missing_try_exec() {
        let path = temp_desktop_file(
            "tryexec-missing",
            "[Desktop Entry]\nType=Application\nName=Missing\nExec=missing-binary\nTryExec=/definitely/not/here\n",
        );

        let parsed = BackendRust::parse_desktop_file(&path);
        let _ = fs::remove_file(path);

        assert!(parsed.is_none());
    }

    #[test]
    fn parse_desktop_file_keeps_working_dir_and_launch_args() {
        let path = temp_desktop_file(
            "working-dir",
            "[Desktop Entry]\nType=Application\nName=Editor\nExec=sh -c 'printf %c' -- %k\nPath=/tmp\n",
        );
        let expected_path = path.to_string_lossy().to_string();

        let parsed = BackendRust::parse_desktop_file(&path).unwrap();
        let _ = fs::remove_file(path);

        assert_eq!(parsed.working_dir.as_deref(), Some("/tmp"));
        assert_eq!(
            parsed.launch_args,
            vec![
                "sh".to_string(),
                "-c".to_string(),
                "printf Editor".to_string(),
                "--".to_string(),
                expected_path,
            ]
        );
    }
}
