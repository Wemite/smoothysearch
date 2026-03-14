use cxx_qt_build::{CppFile, CxxQtBuilder, QmlModule};

fn main() {
    CxxQtBuilder::new_qml_module(QmlModule::new("SmoothySearch").qml_file("qml/Main.qml"))
        .crate_include_root(Some("include".to_string()))
        .cpp_file(CppFile::from("src/qt_url_opener.cpp"))
        .files(["src/backend.rs"])
        .build();
}
