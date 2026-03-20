mod backend;
mod config;
mod theme;

use cxx_qt_lib::{QGuiApplication, QQmlApplicationEngine, QUrl};
use notify::{EventKind, RecommendedWatcher, RecursiveMode, Watcher};
use std::sync::mpsc::channel;
use std::thread;

fn watch_config_for_reload() {
    thread::spawn(|| {
        let Some(config_path_buf) = config::config_path() else {
            return;
        };
        let watch_dir = config_path_buf
            .parent()
            .map(|p| p.to_path_buf())
            .unwrap_or_else(|| {
                config::config_dir().unwrap_or_else(|| std::path::PathBuf::from("."))
            });
        let _ = std::fs::create_dir_all(&watch_dir);

        let (tx, rx) = channel();

        let mut watcher = match RecommendedWatcher::new(tx, notify::Config::default()) {
            Ok(watcher) => watcher,
            Err(_) => return,
        };

        if watcher
            .watch(&watch_dir, RecursiveMode::NonRecursive)
            .is_err()
        {
            return;
        }

        for event in rx.into_iter().flatten() {
            let touched_config = event.paths.iter().any(|p| p == &config_path_buf);

            if !touched_config {
                continue;
            }

            match event.kind {
                EventKind::Modify(_)
                | EventKind::Create(_)
                | EventKind::Remove(_)
                | EventKind::Any => {
                    backend::request_resident_reload_config();
                }
                _ => {}
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

        for event in rx.into_iter().flatten() {
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

    if is_service {
        watch_config_for_reload();
        watch_app_dirs_invalidate_cache();
    }

    if is_service {
        if !backend::acquire_resident_singleton() {
            return;
        }
        run_gui();
        return;
    }

    backend::ensure_resident_service_running();
    backend::request_resident_show();
}
