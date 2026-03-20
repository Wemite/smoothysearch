use cxx_qt_build::{CppFile, CxxQtBuilder, QmlModule};
use std::process::Command;

fn kde_blur_include_paths() -> Option<Vec<String>> {
    let output = Command::new("pkg-config")
        .args(["--cflags", "KF6WindowSystem"])
        .output()
        .ok()?;

    if !output.status.success() {
        return None;
    }

    let stdout = String::from_utf8(output.stdout).ok()?;
    let includes = stdout
        .split_whitespace()
        .filter_map(|flag| flag.strip_prefix("-I").map(str::to_string))
        .collect::<Vec<_>>();

    if includes.is_empty() {
        None
    } else {
        Some(includes)
    }
}

fn main() {
    let include_paths = kde_blur_include_paths();
    let mut builder = CxxQtBuilder::new_qml_module(
        QmlModule::new("SmoothySearch")
            .qml_file("qml/Main.qml")
            .qml_file("qml/SearchBar.qml")
            .qml_file("qml/EntryList.qml")
            .qml_file("qml/ThemeEditorPane.qml"),
    )
    .crate_include_root(Some("include".to_string()))
    .cpp_file(CppFile::from("src/qt_url_opener.cpp"))
    .cpp_file(CppFile::from("src/qt_window_effects.cpp"))
    .files(["src/backend.rs"]);

    if let Some(include_paths) = include_paths {
        println!("cargo:rustc-link-lib=KF6WindowSystem");
        unsafe {
            builder = builder.cc_builder(|cc| {
                cc.define("SMOOTHYSEARCH_HAS_KWINDOWSYSTEM", Some("1"));
                for include in &include_paths {
                    cc.include(include);
                }
            });
        }
    } else {
        unsafe {
            builder = builder.cc_builder(|cc| {
                cc.define("SMOOTHYSEARCH_HAS_KWINDOWSYSTEM", Some("0"));
            });
        }
    }

    builder.build();
}
