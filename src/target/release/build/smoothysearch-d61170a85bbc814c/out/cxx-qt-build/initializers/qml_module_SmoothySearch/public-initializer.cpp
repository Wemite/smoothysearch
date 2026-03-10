
#include <mutex>

#include <QtPlugin>
Q_IMPORT_PLUGIN(SmoothySearch_plugin);

static bool do_init() {
    static std::once_flag flag;
    std::call_once(flag, []() {
        
    });
    return true;
}

extern "C" bool cxx_qt_init_qml_module_SmoothySearch() {
    return do_init();
}
            