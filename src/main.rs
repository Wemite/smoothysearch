mod backend;
mod config;
mod theme;

use cxx_qt_lib::{QGuiApplication, QQmlApplicationEngine, QUrl};

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
