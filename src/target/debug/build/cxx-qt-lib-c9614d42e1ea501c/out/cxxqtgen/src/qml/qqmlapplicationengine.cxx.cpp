#include "cxx-qt-lib/qbytearray.h"
#include "cxx-qt-lib/qmap.h"
#include "cxx-qt-lib/qstring.h"
#include "cxx-qt-lib/qstringlist.h"
#include "cxx-qt-lib/qurl.h"
#include "cxx-qt-lib/qqmlengine.h"
#include <QtCore/QObject>
#include "cxx-qt/connection.h"
#include "private/src/qml/qqmlapplicationengine.cxxqt.h"
#include "cxx-qt-lib/qqmlapplicationengine.h"
#include <cstddef>
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

using QQmlApplicationEngine = ::QQmlApplicationEngine;

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
    "type Qt::ConnectionType should be trivially move constructible and trivially destructible in C++ to be used as an argument of `QQmlApplicationEngine_connect_object_created`, `QQmlApplicationEngine_connect_object_creation_failed` in Rust");
static_assert(
    ::rust::IsRelocatable<::rust::cxxqt1::QMetaObjectConnection>::value,
    "type rust::cxxqt1::QMetaObjectConnection should be trivially move constructible and trivially destructible in C++ to be used as a return value of `QQmlApplicationEngine_connect_object_created`, `QQmlApplicationEngine_connect_object_creation_failed` in Rust");
static_assert(
    ::rust::IsRelocatable<::rust::cxxqtgen1::QQmlApplicationEngineCxxQtSignalHandlerobjectCreated>::value,
    "type rust::cxxqtgen1::QQmlApplicationEngineCxxQtSignalHandlerobjectCreated should be trivially move constructible and trivially destructible in C++ to be used as an argument of `QQmlApplicationEngine_connect_object_created`, `drop_QQmlApplicationEngine_signal_handler_objectCreated` in Rust");
static_assert(
    ::rust::IsRelocatable<::rust::cxxqtgen1::QQmlApplicationEngineCxxQtSignalHandlerobjectCreationFailed>::value,
    "type rust::cxxqtgen1::QQmlApplicationEngineCxxQtSignalHandlerobjectCreationFailed should be trivially move constructible and trivially destructible in C++ to be used as an argument of `QQmlApplicationEngine_connect_object_creation_failed`, `drop_QQmlApplicationEngine_signal_handler_objectCreationFailed` in Rust");

extern "C" {
void cxxbridge1$194$QQmlApplicationEngine$add_import_path(::QQmlApplicationEngine &self, ::QString const &path) noexcept {
  void (::QQmlApplicationEngine::*add_import_path$)(::QString const &) = &::QQmlApplicationEngine::addImportPath;
  (self.*add_import_path$)(path);
}

void cxxbridge1$194$QQmlApplicationEngine$add_plugin_path(::QQmlApplicationEngine &self, ::QString const &path) noexcept {
  void (::QQmlApplicationEngine::*add_plugin_path$)(::QString const &) = &::QQmlApplicationEngine::addPluginPath;
  (self.*add_plugin_path$)(path);
}

void cxxbridge1$194$QQmlApplicationEngine$base_url(::QQmlApplicationEngine const &self, ::QUrl *return$) noexcept {
  ::QUrl (::QQmlApplicationEngine::*base_url$)() const = &::QQmlApplicationEngine::baseUrl;
  new (return$) ::QUrl((self.*base_url$)());
}

void cxxbridge1$194$QQmlApplicationEngine$import_path_list(::QQmlApplicationEngine const &self, ::QStringList *return$) noexcept {
  ::QStringList (::QQmlApplicationEngine::*import_path_list$)() const = &::QQmlApplicationEngine::importPathList;
  new (return$) ::QStringList((self.*import_path_list$)());
}

void cxxbridge1$194$QQmlApplicationEngine$load(::QQmlApplicationEngine &self, ::QUrl const &url) noexcept {
  void (::QQmlApplicationEngine::*load$)(::QUrl const &) = &::QQmlApplicationEngine::load;
  (self.*load$)(url);
}

void cxxbridge1$194$QQmlApplicationEngine$load_data(::QQmlApplicationEngine &self, ::QByteArray const &data, ::QUrl const &url) noexcept {
  void (::QQmlApplicationEngine::*load_data$)(::QByteArray const &, ::QUrl const &) = &::QQmlApplicationEngine::loadData;
  (self.*load_data$)(data, url);
}

void cxxbridge1$194$QQmlApplicationEngine$offline_storage_path(::QQmlApplicationEngine const &self, ::QString *return$) noexcept {
  ::QString (::QQmlApplicationEngine::*offline_storage_path$)() const = &::QQmlApplicationEngine::offlineStoragePath;
  new (return$) ::QString((self.*offline_storage_path$)());
}

void cxxbridge1$194$QQmlApplicationEngine$plugin_path_list(::QQmlApplicationEngine const &self, ::QStringList *return$) noexcept {
  ::QStringList (::QQmlApplicationEngine::*plugin_path_list$)() const = &::QQmlApplicationEngine::pluginPathList;
  new (return$) ::QStringList((self.*plugin_path_list$)());
}

void cxxbridge1$194$QQmlApplicationEngine$set_base_url(::QQmlApplicationEngine &self, ::QUrl const &url) noexcept {
  void (::QQmlApplicationEngine::*set_base_url$)(::QUrl const &) = &::QQmlApplicationEngine::setBaseUrl;
  (self.*set_base_url$)(url);
}

void cxxbridge1$194$QQmlApplicationEngine$set_import_path_list(::QQmlApplicationEngine &self, ::QStringList const &paths) noexcept {
  void (::QQmlApplicationEngine::*set_import_path_list$)(::QStringList const &) = &::QQmlApplicationEngine::setImportPathList;
  (self.*set_import_path_list$)(paths);
}

void cxxbridge1$194$QQmlApplicationEngine$set_initial_properties(::QQmlApplicationEngine &self, ::QMap_QString_QVariant const &properties) noexcept {
  void (::QQmlApplicationEngine::*set_initial_properties$)(::QMap_QString_QVariant const &) = &::QQmlApplicationEngine::setInitialProperties;
  (self.*set_initial_properties$)(properties);
}

void cxxbridge1$194$QQmlApplicationEngine$set_plugin_path_list(::QQmlApplicationEngine &self, ::QStringList const &paths) noexcept {
  void (::QQmlApplicationEngine::*set_plugin_path_list$)(::QStringList const &) = &::QQmlApplicationEngine::setPluginPathList;
  (self.*set_plugin_path_list$)(paths);
}

void cxxbridge1$194$QQmlApplicationEngine$set_offline_storage_path(::QQmlApplicationEngine &self, ::QString const &dir) noexcept {
  void (::QQmlApplicationEngine::*set_offline_storage_path$)(::QString const &) = &::QQmlApplicationEngine::setOfflineStoragePath;
  (self.*set_offline_storage_path$)(dir);
}
} // extern "C"

namespace rust {
namespace cxxqtlib1 {
extern "C" {
::QQmlApplicationEngine *rust$cxxqtlib1$cxxbridge1$194$qqmlapplicationengine_new() noexcept {
  ::std::unique_ptr<::QQmlApplicationEngine> (*qqmlapplicationengine_new$)() = ::rust::cxxqtlib1::qqmlapplicationengineNew;
  return qqmlapplicationengine_new$().release();
}
} // extern "C"
} // namespace cxxqtlib1

namespace cxxqt1 {
extern "C" {
::QQmlEngine const *rust$cxxqt1$cxxbridge1$194$cxx_qt_ffi_QQmlApplicationEngine_upcastPtr(::QQmlApplicationEngine const *thiz) noexcept {
  ::QQmlEngine const *(*cxx_qt_ffi_QQmlApplicationEngine_upcastPtr$)(::QQmlApplicationEngine const *) = ::rust::cxxqt1::upcastPtr;
  return cxx_qt_ffi_QQmlApplicationEngine_upcastPtr$(thiz);
}

::QQmlApplicationEngine const *rust$cxxqt1$cxxbridge1$194$cxx_qt_ffi_QQmlApplicationEngine_downcastPtr(::QQmlEngine const *base) noexcept {
  ::QQmlApplicationEngine const *(*cxx_qt_ffi_QQmlApplicationEngine_downcastPtr$)(::QQmlEngine const *) = ::rust::cxxqt1::downcastPtr;
  return cxx_qt_ffi_QQmlApplicationEngine_downcastPtr$(base);
}
} // extern "C"
} // namespace cxxqt1
} // namespace rust

extern "C" {
void cxxbridge1$194$QQmlApplicationEngine$object_created(::QQmlApplicationEngine &self, ::QObject *qobject, ::QUrl const &url) noexcept {
  void (::QQmlApplicationEngine::*object_created$)(::QObject *, ::QUrl const &) = &::QQmlApplicationEngine::objectCreated;
  (self.*object_created$)(qobject, url);
}
} // extern "C"

namespace rust {
namespace cxxqtgen1 {
extern "C" {
void rust$cxxqtgen1$cxxbridge1$194$QQmlApplicationEngine_connect_object_created(::QQmlApplicationEngine &self_value, ::rust::cxxqtgen1::QQmlApplicationEngineCxxQtSignalHandlerobjectCreated *signal_handler, ::Qt::ConnectionType *conn_type, ::rust::cxxqt1::QMetaObjectConnection *return$) noexcept {
  ::rust::cxxqt1::QMetaObjectConnection (*QQmlApplicationEngine_connect_object_created$)(::QQmlApplicationEngine &, ::rust::cxxqtgen1::QQmlApplicationEngineCxxQtSignalHandlerobjectCreated, ::Qt::ConnectionType) = ::rust::cxxqtgen1::QQmlApplicationEngine_objectCreatedConnect;
  new (return$) ::rust::cxxqt1::QMetaObjectConnection(QQmlApplicationEngine_connect_object_created$(self_value, ::std::move(*signal_handler), ::std::move(*conn_type)));
}

void rust$cxxqtgen1$cxxbridge1$194$drop_QQmlApplicationEngine_signal_handler_objectCreated(::rust::cxxqtgen1::QQmlApplicationEngineCxxQtSignalHandlerobjectCreated *handler) noexcept;

void rust$cxxqtgen1$cxxbridge1$194$call_QQmlApplicationEngine_signal_handler_objectCreated(::rust::cxxqtgen1::QQmlApplicationEngineCxxQtSignalHandlerobjectCreated &handler, ::QQmlApplicationEngine &self_value, ::QObject *qobject, ::QUrl const &url) noexcept;
} // extern "C"
} // namespace cxxqtgen1
} // namespace rust

extern "C" {
void cxxbridge1$194$QQmlApplicationEngine$object_creation_failed(::QQmlApplicationEngine &self, ::QUrl const &url) noexcept {
  void (::QQmlApplicationEngine::*object_creation_failed$)(::QUrl const &) = &::QQmlApplicationEngine::objectCreationFailed;
  (self.*object_creation_failed$)(url);
}
} // extern "C"

namespace rust {
namespace cxxqtgen1 {
extern "C" {
void rust$cxxqtgen1$cxxbridge1$194$QQmlApplicationEngine_connect_object_creation_failed(::QQmlApplicationEngine &self_value, ::rust::cxxqtgen1::QQmlApplicationEngineCxxQtSignalHandlerobjectCreationFailed *signal_handler, ::Qt::ConnectionType *conn_type, ::rust::cxxqt1::QMetaObjectConnection *return$) noexcept {
  ::rust::cxxqt1::QMetaObjectConnection (*QQmlApplicationEngine_connect_object_creation_failed$)(::QQmlApplicationEngine &, ::rust::cxxqtgen1::QQmlApplicationEngineCxxQtSignalHandlerobjectCreationFailed, ::Qt::ConnectionType) = ::rust::cxxqtgen1::QQmlApplicationEngine_objectCreationFailedConnect;
  new (return$) ::rust::cxxqt1::QMetaObjectConnection(QQmlApplicationEngine_connect_object_creation_failed$(self_value, ::std::move(*signal_handler), ::std::move(*conn_type)));
}

void rust$cxxqtgen1$cxxbridge1$194$drop_QQmlApplicationEngine_signal_handler_objectCreationFailed(::rust::cxxqtgen1::QQmlApplicationEngineCxxQtSignalHandlerobjectCreationFailed *handler) noexcept;

void rust$cxxqtgen1$cxxbridge1$194$call_QQmlApplicationEngine_signal_handler_objectCreationFailed(::rust::cxxqtgen1::QQmlApplicationEngineCxxQtSignalHandlerobjectCreationFailed &handler, ::QQmlApplicationEngine &self_value, ::QUrl const &url) noexcept;
} // extern "C"

void drop_QQmlApplicationEngine_signal_handler_objectCreated(::rust::cxxqtgen1::QQmlApplicationEngineCxxQtSignalHandlerobjectCreated handler) noexcept {
  ::rust::ManuallyDrop<::rust::cxxqtgen1::QQmlApplicationEngineCxxQtSignalHandlerobjectCreated> handler$(::std::move(handler));
  rust$cxxqtgen1$cxxbridge1$194$drop_QQmlApplicationEngine_signal_handler_objectCreated(&handler$.value);
}

void call_QQmlApplicationEngine_signal_handler_objectCreated(::rust::cxxqtgen1::QQmlApplicationEngineCxxQtSignalHandlerobjectCreated &handler, ::QQmlApplicationEngine &self_value, ::QObject *qobject, ::QUrl const &url) noexcept {
  rust$cxxqtgen1$cxxbridge1$194$call_QQmlApplicationEngine_signal_handler_objectCreated(handler, self_value, qobject, url);
}

void drop_QQmlApplicationEngine_signal_handler_objectCreationFailed(::rust::cxxqtgen1::QQmlApplicationEngineCxxQtSignalHandlerobjectCreationFailed handler) noexcept {
  ::rust::ManuallyDrop<::rust::cxxqtgen1::QQmlApplicationEngineCxxQtSignalHandlerobjectCreationFailed> handler$(::std::move(handler));
  rust$cxxqtgen1$cxxbridge1$194$drop_QQmlApplicationEngine_signal_handler_objectCreationFailed(&handler$.value);
}

void call_QQmlApplicationEngine_signal_handler_objectCreationFailed(::rust::cxxqtgen1::QQmlApplicationEngineCxxQtSignalHandlerobjectCreationFailed &handler, ::QQmlApplicationEngine &self_value, ::QUrl const &url) noexcept {
  rust$cxxqtgen1$cxxbridge1$194$call_QQmlApplicationEngine_signal_handler_objectCreationFailed(handler, self_value, url);
}
} // namespace cxxqtgen1
} // namespace rust

extern "C" {
static_assert(::rust::detail::is_complete<::std::remove_extent<::QQmlApplicationEngine>::type>::value, "definition of `::QQmlApplicationEngine` is required");
static_assert(sizeof(::std::unique_ptr<::QQmlApplicationEngine>) == sizeof(void *), "");
static_assert(alignof(::std::unique_ptr<::QQmlApplicationEngine>) == alignof(void *), "");
void cxxbridge1$unique_ptr$QQmlApplicationEngine$null(::std::unique_ptr<::QQmlApplicationEngine> *ptr) noexcept {
  ::new (ptr) ::std::unique_ptr<::QQmlApplicationEngine>();
}
void cxxbridge1$unique_ptr$QQmlApplicationEngine$raw(::std::unique_ptr<::QQmlApplicationEngine> *ptr, ::std::unique_ptr<::QQmlApplicationEngine>::pointer raw) noexcept {
  ::new (ptr) ::std::unique_ptr<::QQmlApplicationEngine>(raw);
}
::std::unique_ptr<::QQmlApplicationEngine>::element_type const *cxxbridge1$unique_ptr$QQmlApplicationEngine$get(::std::unique_ptr<::QQmlApplicationEngine> const &ptr) noexcept {
  return ptr.get();
}
::std::unique_ptr<::QQmlApplicationEngine>::pointer cxxbridge1$unique_ptr$QQmlApplicationEngine$release(::std::unique_ptr<::QQmlApplicationEngine> &ptr) noexcept {
  return ptr.release();
}
void cxxbridge1$unique_ptr$QQmlApplicationEngine$drop(::std::unique_ptr<::QQmlApplicationEngine> *ptr) noexcept {
  ::rust::deleter_if<::rust::detail::is_complete<::QQmlApplicationEngine>::value>{}(ptr);
}
} // extern "C"
