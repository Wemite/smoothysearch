
#include <mutex>

extern "C" bool cxx_qt_init_crate_cxx_qt();
extern "C" bool init_cxx_qt_lib_core();
extern "C" bool init_cxx_qt_lib_gui();

static bool do_init() {
    static std::once_flag flag;
    std::call_once(flag, []() {
        cxx_qt_init_crate_cxx_qt();
init_cxx_qt_lib_core();
init_cxx_qt_lib_gui();
    });
    return true;
}

extern "C" bool cxx_qt_init_crate_cxx_qt_lib() {
    return do_init();
}
            