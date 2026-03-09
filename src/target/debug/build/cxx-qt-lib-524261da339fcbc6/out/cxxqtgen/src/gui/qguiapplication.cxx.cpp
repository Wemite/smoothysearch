#include "cxx-qt-lib/qbytearray.h"
#include "cxx-qt-lib/qstring.h"
#include "cxx-qt-lib/qstringlist.h"
#include "cxx-qt-lib/core/qvector/qvector_QByteArray.h"
#include "cxx-qt-lib/qfont.h"
#include "cxx-qt-lib/qcoreapplication.h"
#include "cxx-qt-lib/qcoreapplication.h"
#include <QtCore/QObject>
#include "cxx-qt/connection.h"
#include "private/src/gui/qguiapplication.cxxqt.h"
#include "cxx-qt-lib/qguiapplication.h"
#include <cstddef>
#include <cstdint>
#include <memory>
#include <new>
#include <type_traits>
#include <utility>

#ifdef __GNUC__
#pragma GCC diagnostic ignored "-Wmissing-declarations"
#ifdef __clang__
#pragma clang diagnostic ignored "-Wdollar-in-identifier-extension"
#endif // __clang__
#endif // __GNUC__

namespace rust {
inline namespace cxxbridge1 {
// #include "rust/cxx.h"

#ifndef CXXBRIDGE1_IS_COMPLETE
#define CXXBRIDGE1_IS_COMPLETE
namespace detail {
namespace {
template <typename T, typename = std::size_t>
struct is_complete : std::false_type {};
template <typename T>
struct is_complete<T, decltype(sizeof(T))> : std::true_type {};
} // namespace
} // namespace detail
#endif // CXXBRIDGE1_IS_COMPLETE

#ifndef CXXBRIDGE1_RELOCATABLE
#define CXXBRIDGE1_RELOCATABLE
namespace detail {
template <typename... Ts>
struct make_void {
  using type = void;
};

template <typename... Ts>
using void_t = typename make_void<Ts...>::type;

template <typename Void, template <typename...> class, typename...>
struct detect : std::false_type {};
template <template <typename...> class T, typename... A>
struct detect<void_t<T<A...>>, T, A...> : std::true_type {};

template <template <typename...> class T, typename... A>
using is_detected = detect<void, T, A...>;

template <typename T>
using detect_IsRelocatable = typename T::IsRelocatable;

template <typename T>
struct get_IsRelocatable
    : std::is_same<typename T::IsRelocatable, std::true_type> {};
} // namespace detail

template <typename T>
struct IsRelocatable
    : std::conditional<
          detail::is_detected<detail::detect_IsRelocatable, T>::value,
          detail::get_IsRelocatable<T>,
          std::integral_constant<
              bool, std::is_trivially_move_constructible<T>::value &&
                        std::is_trivially_destructible<T>::value>>::type {};
#endif // CXXBRIDGE1_RELOCATABLE

namespace {
template <bool> struct deleter_if {
  template <typename T> void operator()(T *) {}
};
template <> struct deleter_if<true> {
  template <typename T> void operator()(T *ptr) { ptr->~T(); }
};
} // namespace
} // namespace cxxbridge1
} // namespace rust

using QGuiApplication = ::QGuiApplication;

static_assert(
    ::rust::IsRelocatable<::QString>::value,
    "type QString should be trivially move constructible and trivially destructible in C++ to be used as a return value of `qguiapplication_application_name`, `qguiapplication_application_version`, `qguiapplication_organization_domain` in Rust");
static_assert(
    ::rust::IsRelocatable<::QStringList>::value,
    "type QStringList should be trivially move constructible and trivially destructible in C++ to be used as a return value of `qguiapplication_library_paths` in Rust");
static_assert(
    ::rust::IsRelocatable<::QFont>::value,
    "type QFont should be trivially move constructible and trivially destructible in C++ to be used as a return value of `qguiapplication_font` in Rust");
static_assert(
    ::rust::IsRelocatable<::Qt::KeyboardModifiers>::value,
    "type Qt::KeyboardModifiers should be trivially move constructible and trivially destructible in C++ to be used as a return value of `qguiapplication_keyboard_modifiers`, `qguiapplication_query_keyboard_modifiers` in Rust");
static_assert(
    ::rust::IsRelocatable<::Qt::MouseButtons>::value,
    "type Qt::MouseButtons should be trivially move constructible and trivially destructible in C++ to be used as a return value of `qguiapplication_mouse_buttons` in Rust");

namespace rust {
namespace cxxqtlib1 {
extern "C" {
::QGuiApplication *rust$cxxqtlib1$cxxbridge1$194$qguiapplication_new(::QVector_QByteArray const &args) noexcept {
  ::std::unique_ptr<::QGuiApplication> (*qguiapplication_new$)(::QVector_QByteArray const &) = ::rust::cxxqtlib1::qguiapplicationNew;
  return qguiapplication_new$(args).release();
}

void rust$cxxqtlib1$cxxbridge1$194$qguiapplication_add_library_path(::QGuiApplication &app, ::QString const &path) noexcept {
  void (*qguiapplication_add_library_path$)(::QGuiApplication &, ::QString const &) = ::rust::cxxqtlib1::qapplicationAddLibraryPath;
  qguiapplication_add_library_path$(app, path);
}

void rust$cxxqtlib1$cxxbridge1$194$qguiapplication_application_name(::QGuiApplication const &app, ::QString *return$) noexcept {
  ::QString (*qguiapplication_application_name$)(::QGuiApplication const &) = ::rust::cxxqtlib1::qapplicationApplicationName;
  new (return$) ::QString(qguiapplication_application_name$(app));
}

void rust$cxxqtlib1$cxxbridge1$194$qguiapplication_remove_library_path(::QGuiApplication const &app, ::QString const &path) noexcept {
  void (*qguiapplication_remove_library_path$)(::QGuiApplication const &, ::QString const &) = ::rust::cxxqtlib1::qapplicationRemoveLibraryPath;
  qguiapplication_remove_library_path$(app, path);
}

void rust$cxxqtlib1$cxxbridge1$194$qguiapplication_application_version(::QGuiApplication const &app, ::QString *return$) noexcept {
  ::QString (*qguiapplication_application_version$)(::QGuiApplication const &) = ::rust::cxxqtlib1::qapplicationApplicationVersion;
  new (return$) ::QString(qguiapplication_application_version$(app));
}

::std::int32_t rust$cxxqtlib1$cxxbridge1$194$qguiapplication_exec(::QGuiApplication &app) noexcept {
  ::std::int32_t (*qguiapplication_exec$)(::QGuiApplication &) = ::rust::cxxqtlib1::qapplicationExec;
  return qguiapplication_exec$(app);
}

void rust$cxxqtlib1$cxxbridge1$194$qguiapplication_library_paths(::QGuiApplication const &app, ::QStringList *return$) noexcept {
  ::QStringList (*qguiapplication_library_paths$)(::QGuiApplication const &) = ::rust::cxxqtlib1::qapplicationLibraryPaths;
  new (return$) ::QStringList(qguiapplication_library_paths$(app));
}

void rust$cxxqtlib1$cxxbridge1$194$qguiapplication_organization_domain(::QGuiApplication const &app, ::QString *return$) noexcept {
  ::QString (*qguiapplication_organization_domain$)(::QGuiApplication const &) = ::rust::cxxqtlib1::qapplicationOrganizationDomain;
  new (return$) ::QString(qguiapplication_organization_domain$(app));
}

void rust$cxxqtlib1$cxxbridge1$194$qguiapplication_organization_name(::QGuiApplication const &app, ::QString *return$) noexcept {
  ::QString (*qguiapplication_organization_name$)(::QGuiApplication const &) = ::rust::cxxqtlib1::qapplicationOrganizationName;
  new (return$) ::QString(qguiapplication_organization_name$(app));
}

void rust$cxxqtlib1$cxxbridge1$194$qguiapplication_set_application_name(::QGuiApplication &app, ::QString const &name) noexcept {
  void (*qguiapplication_set_application_name$)(::QGuiApplication &, ::QString const &) = ::rust::cxxqtlib1::qapplicationSetApplicationName;
  qguiapplication_set_application_name$(app, name);
}

void rust$cxxqtlib1$cxxbridge1$194$qguiapplication_set_application_version(::QGuiApplication &app, ::QString const &version) noexcept {
  void (*qguiapplication_set_application_version$)(::QGuiApplication &, ::QString const &) = ::rust::cxxqtlib1::qapplicationSetApplicationVersion;
  qguiapplication_set_application_version$(app, version);
}

void rust$cxxqtlib1$cxxbridge1$194$qguiapplication_set_font(::QFont const &font) noexcept {
  void (*qguiapplication_set_font$)(::QFont const &) = ::rust::cxxqtlib1::qguiapplicationSetFont;
  qguiapplication_set_font$(font);
}

void rust$cxxqtlib1$cxxbridge1$194$qguiapplication_font(::QFont *return$) noexcept {
  ::QFont (*qguiapplication_font$)() = ::rust::cxxqtlib1::qguiapplicationFont;
  new (return$) ::QFont(qguiapplication_font$());
}

void rust$cxxqtlib1$cxxbridge1$194$qguiapplication_set_library_paths(::QGuiApplication &app, ::QStringList const &paths) noexcept {
  void (*qguiapplication_set_library_paths$)(::QGuiApplication &, ::QStringList const &) = ::rust::cxxqtlib1::qapplicationSetLibraryPaths;
  qguiapplication_set_library_paths$(app, paths);
}

void rust$cxxqtlib1$cxxbridge1$194$qguiapplication_set_organization_domain(::QGuiApplication &app, ::QString const &domain) noexcept {
  void (*qguiapplication_set_organization_domain$)(::QGuiApplication &, ::QString const &) = ::rust::cxxqtlib1::qapplicationSetOrganizationDomain;
  qguiapplication_set_organization_domain$(app, domain);
}

void rust$cxxqtlib1$cxxbridge1$194$qguiapplication_set_organization_name(::QGuiApplication &app, ::QString const &name) noexcept {
  void (*qguiapplication_set_organization_name$)(::QGuiApplication &, ::QString const &) = ::rust::cxxqtlib1::qapplicationSetOrganizationName;
  qguiapplication_set_organization_name$(app, name);
}

void rust$cxxqtlib1$cxxbridge1$194$qguiapplication_set_desktop_file_name(::QString const &name) noexcept {
  void (*qguiapplication_set_desktop_file_name$)(::QString const &) = ::rust::cxxqtlib1::qguiapplicationSetDesktopFileName;
  qguiapplication_set_desktop_file_name$(name);
}

void rust$cxxqtlib1$cxxbridge1$194$qguiapplication_desktop_file_name(::QString *return$) noexcept {
  ::QString (*qguiapplication_desktop_file_name$)() = ::rust::cxxqtlib1::qguiapplicationDesktopFileName;
  new (return$) ::QString(qguiapplication_desktop_file_name$());
}

void rust$cxxqtlib1$cxxbridge1$194$qguiapplication_keyboard_modifiers(::Qt::KeyboardModifiers *return$) noexcept {
  ::Qt::KeyboardModifiers (*qguiapplication_keyboard_modifiers$)() = ::rust::cxxqtlib1::qguiapplicationKeyboardModifiers;
  new (return$) ::Qt::KeyboardModifiers(qguiapplication_keyboard_modifiers$());
}

void rust$cxxqtlib1$cxxbridge1$194$qguiapplication_mouse_buttons(::Qt::MouseButtons *return$) noexcept {
  ::Qt::MouseButtons (*qguiapplication_mouse_buttons$)() = ::rust::cxxqtlib1::qguiapplicationMouseButtons;
  new (return$) ::Qt::MouseButtons(qguiapplication_mouse_buttons$());
}

void rust$cxxqtlib1$cxxbridge1$194$qguiapplication_query_keyboard_modifiers(::Qt::KeyboardModifiers *return$) noexcept {
  ::Qt::KeyboardModifiers (*qguiapplication_query_keyboard_modifiers$)() = ::rust::cxxqtlib1::qguiapplicationQueryKeyboardModifiers;
  new (return$) ::Qt::KeyboardModifiers(qguiapplication_query_keyboard_modifiers$());
}
} // extern "C"
} // namespace cxxqtlib1

namespace cxxqt1 {
extern "C" {
::QCoreApplication const *rust$cxxqt1$cxxbridge1$194$cxx_qt_ffi_QGuiApplication_upcastPtr(::QGuiApplication const *thiz) noexcept {
  ::QCoreApplication const *(*cxx_qt_ffi_QGuiApplication_upcastPtr$)(::QGuiApplication const *) = ::rust::cxxqt1::upcastPtr;
  return cxx_qt_ffi_QGuiApplication_upcastPtr$(thiz);
}

::QGuiApplication const *rust$cxxqt1$cxxbridge1$194$cxx_qt_ffi_QGuiApplication_downcastPtr(::QCoreApplication const *base) noexcept {
  ::QGuiApplication const *(*cxx_qt_ffi_QGuiApplication_downcastPtr$)(::QCoreApplication const *) = ::rust::cxxqt1::downcastPtr;
  return cxx_qt_ffi_QGuiApplication_downcastPtr$(base);
}
} // extern "C"
} // namespace cxxqt1
} // namespace rust

extern "C" {
static_assert(::rust::detail::is_complete<::std::remove_extent<::QGuiApplication>::type>::value, "definition of `::QGuiApplication` is required");
static_assert(sizeof(::std::unique_ptr<::QGuiApplication>) == sizeof(void *), "");
static_assert(alignof(::std::unique_ptr<::QGuiApplication>) == alignof(void *), "");
void cxxbridge1$unique_ptr$QGuiApplication$null(::std::unique_ptr<::QGuiApplication> *ptr) noexcept {
  ::new (ptr) ::std::unique_ptr<::QGuiApplication>();
}
void cxxbridge1$unique_ptr$QGuiApplication$raw(::std::unique_ptr<::QGuiApplication> *ptr, ::std::unique_ptr<::QGuiApplication>::pointer raw) noexcept {
  ::new (ptr) ::std::unique_ptr<::QGuiApplication>(raw);
}
::std::unique_ptr<::QGuiApplication>::element_type const *cxxbridge1$unique_ptr$QGuiApplication$get(::std::unique_ptr<::QGuiApplication> const &ptr) noexcept {
  return ptr.get();
}
::std::unique_ptr<::QGuiApplication>::pointer cxxbridge1$unique_ptr$QGuiApplication$release(::std::unique_ptr<::QGuiApplication> &ptr) noexcept {
  return ptr.release();
}
void cxxbridge1$unique_ptr$QGuiApplication$drop(::std::unique_ptr<::QGuiApplication> *ptr) noexcept {
  ::rust::deleter_if<::rust::detail::is_complete<::QGuiApplication>::value>{}(ptr);
}
} // extern "C"
