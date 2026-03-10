#include "cxx-qt-lib/qstring.h"
#include "cxx-qt-lib/qstringlist.h"
#include "cxx-qt-lib/qurl.h"
#include <QtCore/QObject>
#include "cxx-qt/connection.h"
#include "private/src/qml/qqmlengine.cxxqt.h"
#include "cxx-qt-lib/qqmlengine.h"
#include <cstddef>
#include <cstdint>
#include <memory>
#include <new>
#include <type_traits>
#include <utility>

#ifdef __GNUC__
#pragma GCC diagnostic ignored "-Wmissing-declarations"
#pragma GCC diagnostic ignored "-Wshadow"
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

template <typename T>
union ManuallyDrop {
  T value;
  ManuallyDrop(T &&value) : value(::std::move(value)) {}
  ~ManuallyDrop() {}
};

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

using QQmlEngine = ::QQmlEngine;

static_assert(
    ::rust::IsRelocatable<::QString>::value,
    "type QString should be trivially move constructible and trivially destructible in C++ to be used as a return value of `offline_storage_path` in Rust");
static_assert(
    ::rust::IsRelocatable<::QStringList>::value,
    "type QStringList should be trivially move constructible and trivially destructible in C++ to be used as a return value of `import_path_list`, `plugin_path_list` in Rust");
static_assert(
    ::rust::IsRelocatable<::QUrl>::value,
    "type QUrl should be trivially move constructible and trivially destructible in C++ to be used as a return value of `base_url` in Rust");
static_assert(
    ::rust::IsRelocatable<::Qt::ConnectionType>::value,
    "type Qt::ConnectionType should be trivially move constructible and trivially destructible in C++ to be used as an argument of `QQmlEngine_connect_exit`, `QQmlEngine_connect_quit` in Rust");
static_assert(
    ::rust::IsRelocatable<::rust::cxxqt1::QMetaObjectConnection>::value,
    "type rust::cxxqt1::QMetaObjectConnection should be trivially move constructible and trivially destructible in C++ to be used as a return value of `QQmlEngine_connect_exit`, `QQmlEngine_connect_quit` in Rust");
static_assert(
    ::rust::IsRelocatable<::rust::cxxqtgen1::QQmlEngineCxxQtSignalHandlerexit>::value,
    "type rust::cxxqtgen1::QQmlEngineCxxQtSignalHandlerexit should be trivially move constructible and trivially destructible in C++ to be used as an argument of `QQmlEngine_connect_exit`, `drop_QQmlEngine_signal_handler_exit` in Rust");
static_assert(
    ::rust::IsRelocatable<::rust::cxxqtgen1::QQmlEngineCxxQtSignalHandlerquit>::value,
    "type rust::cxxqtgen1::QQmlEngineCxxQtSignalHandlerquit should be trivially move constructible and trivially destructible in C++ to be used as an argument of `QQmlEngine_connect_quit`, `drop_QQmlEngine_signal_handler_quit` in Rust");

extern "C" {
void cxxbridge1$194$QQmlEngine$add_import_path(::QQmlEngine &self, ::QString const &path) noexcept {
  void (::QQmlEngine::*add_import_path$)(::QString const &) = &::QQmlEngine::addImportPath;
  (self.*add_import_path$)(path);
}

void cxxbridge1$194$QQmlEngine$add_plugin_path(::QQmlEngine &self, ::QString const &path) noexcept {
  void (::QQmlEngine::*add_plugin_path$)(::QString const &) = &::QQmlEngine::addPluginPath;
  (self.*add_plugin_path$)(path);
}

void cxxbridge1$194$QQmlEngine$base_url(::QQmlEngine const &self, ::QUrl *return$) noexcept {
  ::QUrl (::QQmlEngine::*base_url$)() const = &::QQmlEngine::baseUrl;
  new (return$) ::QUrl((self.*base_url$)());
}

void cxxbridge1$194$QQmlEngine$import_path_list(::QQmlEngine const &self, ::QStringList *return$) noexcept {
  ::QStringList (::QQmlEngine::*import_path_list$)() const = &::QQmlEngine::importPathList;
  new (return$) ::QStringList((self.*import_path_list$)());
}

void cxxbridge1$194$QQmlEngine$offline_storage_path(::QQmlEngine const &self, ::QString *return$) noexcept {
  ::QString (::QQmlEngine::*offline_storage_path$)() const = &::QQmlEngine::offlineStoragePath;
  new (return$) ::QString((self.*offline_storage_path$)());
}

bool cxxbridge1$194$QQmlEngine$output_warnings_to_standard_error(::QQmlEngine const &self) noexcept {
  bool (::QQmlEngine::*output_warnings_to_standard_error$)() const = &::QQmlEngine::outputWarningsToStandardError;
  return (self.*output_warnings_to_standard_error$)();
}

void cxxbridge1$194$QQmlEngine$plugin_path_list(::QQmlEngine const &self, ::QStringList *return$) noexcept {
  ::QStringList (::QQmlEngine::*plugin_path_list$)() const = &::QQmlEngine::pluginPathList;
  new (return$) ::QStringList((self.*plugin_path_list$)());
}

void cxxbridge1$194$QQmlEngine$set_base_url(::QQmlEngine &self, ::QUrl const &url) noexcept {
  void (::QQmlEngine::*set_base_url$)(::QUrl const &) = &::QQmlEngine::setBaseUrl;
  (self.*set_base_url$)(url);
}

void cxxbridge1$194$QQmlEngine$set_import_path_list(::QQmlEngine &self, ::QStringList const &paths) noexcept {
  void (::QQmlEngine::*set_import_path_list$)(::QStringList const &) = &::QQmlEngine::setImportPathList;
  (self.*set_import_path_list$)(paths);
}

void cxxbridge1$194$QQmlEngine$set_offline_storage_path(::QQmlEngine &self, ::QString const &dir) noexcept {
  void (::QQmlEngine::*set_offline_storage_path$)(::QString const &) = &::QQmlEngine::setOfflineStoragePath;
  (self.*set_offline_storage_path$)(dir);
}

void cxxbridge1$194$QQmlEngine$set_output_warnings_to_standard_error(::QQmlEngine &self, bool enabled) noexcept {
  void (::QQmlEngine::*set_output_warnings_to_standard_error$)(bool) = &::QQmlEngine::setOutputWarningsToStandardError;
  (self.*set_output_warnings_to_standard_error$)(enabled);
}

void cxxbridge1$194$QQmlEngine$set_plugin_path_list(::QQmlEngine &self, ::QStringList const &paths) noexcept {
  void (::QQmlEngine::*set_plugin_path_list$)(::QStringList const &) = &::QQmlEngine::setPluginPathList;
  (self.*set_plugin_path_list$)(paths);
}
} // extern "C"

namespace rust {
namespace cxxqtlib1 {
extern "C" {
::QQmlEngine *rust$cxxqtlib1$cxxbridge1$194$qqmlengine_new() noexcept {
  ::std::unique_ptr<::QQmlEngine> (*qqmlengine_new$)() = ::rust::cxxqtlib1::qqmlengineNew;
  return qqmlengine_new$().release();
}
} // extern "C"
} // namespace cxxqtlib1

namespace cxxqt1 {
extern "C" {
::QObject const *rust$cxxqt1$cxxbridge1$194$cxx_qt_ffi_QQmlEngine_upcastPtr(::QQmlEngine const *thiz) noexcept {
  ::QObject const *(*cxx_qt_ffi_QQmlEngine_upcastPtr$)(::QQmlEngine const *) = ::rust::cxxqt1::upcastPtr;
  return cxx_qt_ffi_QQmlEngine_upcastPtr$(thiz);
}

::QQmlEngine const *rust$cxxqt1$cxxbridge1$194$cxx_qt_ffi_QQmlEngine_downcastPtr(::QObject const *base) noexcept {
  ::QQmlEngine const *(*cxx_qt_ffi_QQmlEngine_downcastPtr$)(::QObject const *) = ::rust::cxxqt1::downcastPtr;
  return cxx_qt_ffi_QQmlEngine_downcastPtr$(base);
}
} // extern "C"
} // namespace cxxqt1
} // namespace rust

extern "C" {
void cxxbridge1$194$QQmlEngine$exit(::QQmlEngine &self, ::std::int32_t ret_code) noexcept {
  void (::QQmlEngine::*exit$)(::std::int32_t) = &::QQmlEngine::exit;
  (self.*exit$)(ret_code);
}
} // extern "C"

namespace rust {
namespace cxxqtgen1 {
extern "C" {
void rust$cxxqtgen1$cxxbridge1$194$QQmlEngine_connect_exit(::QQmlEngine &self_value, ::rust::cxxqtgen1::QQmlEngineCxxQtSignalHandlerexit *signal_handler, ::Qt::ConnectionType *conn_type, ::rust::cxxqt1::QMetaObjectConnection *return$) noexcept {
  ::rust::cxxqt1::QMetaObjectConnection (*QQmlEngine_connect_exit$)(::QQmlEngine &, ::rust::cxxqtgen1::QQmlEngineCxxQtSignalHandlerexit, ::Qt::ConnectionType) = ::rust::cxxqtgen1::QQmlEngine_exitConnect;
  new (return$) ::rust::cxxqt1::QMetaObjectConnection(QQmlEngine_connect_exit$(self_value, ::std::move(*signal_handler), ::std::move(*conn_type)));
}

void rust$cxxqtgen1$cxxbridge1$194$drop_QQmlEngine_signal_handler_exit(::rust::cxxqtgen1::QQmlEngineCxxQtSignalHandlerexit *handler) noexcept;

void rust$cxxqtgen1$cxxbridge1$194$call_QQmlEngine_signal_handler_exit(::rust::cxxqtgen1::QQmlEngineCxxQtSignalHandlerexit &handler, ::QQmlEngine &self_value, ::std::int32_t ret_code) noexcept;
} // extern "C"
} // namespace cxxqtgen1
} // namespace rust

extern "C" {
void cxxbridge1$194$QQmlEngine$quit(::QQmlEngine &self) noexcept {
  void (::QQmlEngine::*quit$)() = &::QQmlEngine::quit;
  (self.*quit$)();
}
} // extern "C"

namespace rust {
namespace cxxqtgen1 {
extern "C" {
void rust$cxxqtgen1$cxxbridge1$194$QQmlEngine_connect_quit(::QQmlEngine &self_value, ::rust::cxxqtgen1::QQmlEngineCxxQtSignalHandlerquit *signal_handler, ::Qt::ConnectionType *conn_type, ::rust::cxxqt1::QMetaObjectConnection *return$) noexcept {
  ::rust::cxxqt1::QMetaObjectConnection (*QQmlEngine_connect_quit$)(::QQmlEngine &, ::rust::cxxqtgen1::QQmlEngineCxxQtSignalHandlerquit, ::Qt::ConnectionType) = ::rust::cxxqtgen1::QQmlEngine_quitConnect;
  new (return$) ::rust::cxxqt1::QMetaObjectConnection(QQmlEngine_connect_quit$(self_value, ::std::move(*signal_handler), ::std::move(*conn_type)));
}

void rust$cxxqtgen1$cxxbridge1$194$drop_QQmlEngine_signal_handler_quit(::rust::cxxqtgen1::QQmlEngineCxxQtSignalHandlerquit *handler) noexcept;

void rust$cxxqtgen1$cxxbridge1$194$call_QQmlEngine_signal_handler_quit(::rust::cxxqtgen1::QQmlEngineCxxQtSignalHandlerquit &handler, ::QQmlEngine &self_value) noexcept;
} // extern "C"

void drop_QQmlEngine_signal_handler_exit(::rust::cxxqtgen1::QQmlEngineCxxQtSignalHandlerexit handler) noexcept {
  ::rust::ManuallyDrop<::rust::cxxqtgen1::QQmlEngineCxxQtSignalHandlerexit> handler$(::std::move(handler));
  rust$cxxqtgen1$cxxbridge1$194$drop_QQmlEngine_signal_handler_exit(&handler$.value);
}

void call_QQmlEngine_signal_handler_exit(::rust::cxxqtgen1::QQmlEngineCxxQtSignalHandlerexit &handler, ::QQmlEngine &self_value, ::std::int32_t ret_code) noexcept {
  rust$cxxqtgen1$cxxbridge1$194$call_QQmlEngine_signal_handler_exit(handler, self_value, ret_code);
}

void drop_QQmlEngine_signal_handler_quit(::rust::cxxqtgen1::QQmlEngineCxxQtSignalHandlerquit handler) noexcept {
  ::rust::ManuallyDrop<::rust::cxxqtgen1::QQmlEngineCxxQtSignalHandlerquit> handler$(::std::move(handler));
  rust$cxxqtgen1$cxxbridge1$194$drop_QQmlEngine_signal_handler_quit(&handler$.value);
}

void call_QQmlEngine_signal_handler_quit(::rust::cxxqtgen1::QQmlEngineCxxQtSignalHandlerquit &handler, ::QQmlEngine &self_value) noexcept {
  rust$cxxqtgen1$cxxbridge1$194$call_QQmlEngine_signal_handler_quit(handler, self_value);
}
} // namespace cxxqtgen1
} // namespace rust

extern "C" {
static_assert(::rust::detail::is_complete<::std::remove_extent<::QQmlEngine>::type>::value, "definition of `::QQmlEngine` is required");
static_assert(sizeof(::std::unique_ptr<::QQmlEngine>) == sizeof(void *), "");
static_assert(alignof(::std::unique_ptr<::QQmlEngine>) == alignof(void *), "");
void cxxbridge1$unique_ptr$QQmlEngine$null(::std::unique_ptr<::QQmlEngine> *ptr) noexcept {
  ::new (ptr) ::std::unique_ptr<::QQmlEngine>();
}
void cxxbridge1$unique_ptr$QQmlEngine$raw(::std::unique_ptr<::QQmlEngine> *ptr, ::std::unique_ptr<::QQmlEngine>::pointer raw) noexcept {
  ::new (ptr) ::std::unique_ptr<::QQmlEngine>(raw);
}
::std::unique_ptr<::QQmlEngine>::element_type const *cxxbridge1$unique_ptr$QQmlEngine$get(::std::unique_ptr<::QQmlEngine> const &ptr) noexcept {
  return ptr.get();
}
::std::unique_ptr<::QQmlEngine>::pointer cxxbridge1$unique_ptr$QQmlEngine$release(::std::unique_ptr<::QQmlEngine> &ptr) noexcept {
  return ptr.release();
}
void cxxbridge1$unique_ptr$QQmlEngine$drop(::std::unique_ptr<::QQmlEngine> *ptr) noexcept {
  ::rust::deleter_if<::rust::detail::is_complete<::QQmlEngine>::value>{}(ptr);
}
} // extern "C"
