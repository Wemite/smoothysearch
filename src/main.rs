mod backend;
mod config;
mod theme;

use cxx_qt_lib::{QGuiApplication, QQmlApplicationEngine, QUrl};
use notify::{EventKind, RecommendedWatcher, RecursiveMode, Watcher};
use std::sync::mpsc::channel;
use std::thread;

fn watch_config_for_restart() {
    thread::spawn(|| {
        let home = std::env::var("HOME").unwrap();
        let config_path = format!("{}/.config/smoothysearch/config.toml", home);
        let config_path_buf = std::path::PathBuf::from(&config_path);
        let watch_dir = config_path_buf
            .parent()
            .map(|p| p.to_path_buf())
            .unwrap_or_else(|| std::path::PathBuf::from(format!("{}/.config/smoothysearch", home)));

        let (tx, rx) = channel();

        let mut watcher = RecommendedWatcher::new(tx, notify::Config::default()).unwrap();

        watcher
            .watch(&watch_dir, RecursiveMode::NonRecursive)
            .unwrap();

        for res in rx {
            if let Ok(event) = res {
                let touched_config = event.paths.iter().any(|p| p == &config_path_buf);

                if !touched_config {
                    continue;
                }

                match event.kind {
                    EventKind::Modify(_)
                    | EventKind::Create(_)
                    | EventKind::Remove(_)
                    | EventKind::Any => {
                        println!("Config changed -> restarting service");

                        if let Ok(exe) = std::env::current_exe() {
                            let exe_str = exe.to_string_lossy().replace('\'', r"'\''");
                            let cmd = format!("sleep 0.2; '{}' --service", exe_str);

                            let _ = std::process::Command::new("sh")
                                .arg("-c")
                                .arg(cmd)
                                .stdin(std::process::Stdio::null())
                                .stdout(std::process::Stdio::null())
                                .stderr(std::process::Stdio::null())
                                .spawn();
                        }

                        std::process::exit(0);
                    }
                    _ => {}
                }
            }
        }
    });
}

fn watch_app_dirs_invalidate_cache() {
    thread::spawn(|| {
        let (tx, rx) = channel();
        let mut watcher = match RecommendedWatcher::new(tx, notify::Config::default()) {
            Ok(w) => w,
            Err(_) => return,
        };

        for dir in backend::app_dirs_for_watch() {
            if dir.is_dir() {
                let _ = watcher.watch(&dir, RecursiveMode::NonRecursive);
            }
        }

        for res in rx {
            if let Ok(event) = res {
                match event.kind {
                    EventKind::Create(_)
                    | EventKind::Remove(_)
                    | EventKind::Modify(_)
                    | EventKind::Any => {
                        backend::invalidate_app_cache();
                    }
                    _ => {}
                }
            }
        }
    });
}

fn run_gui() {
    let mut app = QGuiApplication::new();
    let mut engine = QQmlApplicationEngine::new();

    if let Some(engine) = engine.as_mut() {
        engine.load(&QUrl::from("qrc:/qt/qml/SmoothySearch/qml/Main.qml"));
    }

    if let Some(app) = app.as_mut() {
        app.exec();
    }
}

fn main() {
    let args: Vec<String> = std::env::args().collect();
    let is_service = args.iter().any(|arg| arg == "--service");
    let is_themes = args.iter().any(|arg| arg == "--themes");

    if is_service {
        watch_config_for_restart();
        watch_app_dirs_invalidate_cache();
    }

    if is_service {
        if !backend::acquire_resident_singleton() {
            return;
        }
        run_gui();
        return;
    }

    if is_themes {
        run_gui();
        return;
    }

    backend::ensure_resident_service_running();
    backend::request_resident_show();
}
