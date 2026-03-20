use super::*;

impl BackendRust {
    pub(crate) fn is_resident_mode() -> bool {
        std::env::args().any(|arg| arg == "--service")
    }

    fn current_exe_path() -> Option<PathBuf> {
        std::env::current_exe().ok()
    }

    fn file_mtime_ms(path: &Path) -> u128 {
        fs::metadata(path)
            .ok()
            .and_then(|meta| meta.modified().ok())
            .and_then(|time| time.duration_since(UNIX_EPOCH).ok())
            .map(|duration| duration.as_millis())
            .unwrap_or(0)
    }

    fn write_resident_command(command: &str) {
        let _ = fs::create_dir_all(Self::cache_dir());

        let exe_mtime = Self::current_exe_path()
            .map(|path| Self::file_mtime_ms(&path))
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
            Ok(value) => value,
            Err(_) => return false,
        };

        let mut lines = content.lines();
        let _ = lines.next();
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

    pub(crate) fn start_resident_socket_drain(listener: &std::os::unix::net::UnixListener) {
        let Ok(listener) = listener.try_clone() else {
            return;
        };

        thread::spawn(move || loop {
            match listener.accept() {
                Ok((stream, _)) => drop(stream),
                Err(err) if err.kind() == ErrorKind::WouldBlock => {
                    thread::sleep(Duration::from_millis(SOCKET_ACCEPT_POLL_MS));
                }
                Err(_) => break,
            }
        });
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
    let _ = fs::create_dir_all(BackendRust::cache_dir());

    let socket = BackendRust::resident_socket_file();
    if resident_service_running() {
        return false;
    }

    let listener = match std::os::unix::net::UnixListener::bind(&socket) {
        Ok(listener) => listener,
        Err(_) => return false,
    };

    let _ = listener.set_nonblocking(true);
    BackendRust::start_resident_socket_drain(&listener);

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

            for _ in 0..SERVICE_KILL_RETRIES {
                if !resident_service_running() {
                    break;
                }
                thread::sleep(Duration::from_millis(SERVICE_RETRY_DELAY_MS));
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

    for _ in 0..SERVICE_START_RETRIES {
        if resident_service_running() {
            return;
        }
        thread::sleep(Duration::from_millis(SERVICE_RETRY_DELAY_MS));
    }

    eprintln!(
        "[smoothysearch] service did not become ready after {}ms",
        SERVICE_START_RETRIES as u64 * SERVICE_RETRY_DELAY_MS
    );
}

pub fn request_resident_show() {
    BackendRust::write_resident_command("show");
}

pub fn request_resident_reload_config() {
    BackendRust::write_resident_command("reload-config");
}

impl ffi::Backend {
    pub fn poll_resident_command(mut self: Pin<&mut Self>) -> i32 {
        let (resident_mode, last_seen) = {
            let self_ref = self.as_ref();
            let rust = self_ref.rust();
            (rust.resident_mode, rust.last_resident_command_mtime_ms)
        };

        if !resident_mode {
            return 0;
        }

        let Some((mtime, command)) = BackendRust::read_resident_command(last_seen) else {
            return 0;
        };

        self.as_mut().rust_mut().last_resident_command_mtime_ms = mtime;

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
                }

                1
            }
            "reload-config" => {
                self.as_mut().apply_loaded_config();
                if *self.editor_is_config() {
                    self.as_mut().load_themes_file();
                }
                0
            }
            "hide" => 2,
            _ => 0,
        }
    }

    pub fn sync_window_blur(self: &ffi::Backend, radius: i32) {
        let _ = ffi::sync_plasma_blur_for_visible_windows(radius.max(0));
    }
}
