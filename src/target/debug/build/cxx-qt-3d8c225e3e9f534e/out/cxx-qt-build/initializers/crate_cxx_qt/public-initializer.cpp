
#include <mutex>

extern "C" bool init_cxx_qt_core();

static bool do_init() {
    static std::once_flag flag;
    std::call_once(flag, []() {
        init_cxx_qt_core();
    });
    return true;
}

extern "C" bool cxx_qt_init_crate_cxx_qt() {
    return do_init();
}
            