#include "cxx-qt-lib/qbytearray.h"
#include "cxx-qt-lib/qstring.h"
#include "cxx-qt-lib/qstringlist.h"
#include "cxx-qt-lib/core/qvector/qvector_QByteArray.h"
#include "cxx-qt-lib/qcoreapplication.h"
#include <QtCore/QObject>
#include "cxx-qt/connection.h"
#include "private/src/core/qcoreapplication.cxxqt.h"
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

using QCoreApplication = ::QCoreApplication;

static_assert(
    ::rust::IsRelocatable<::QString>::value,
    "type QString should be trivially move constructible and trivially destructible in C++ to be used as a return value of `qcoreapplication_application_name`, `qcoreapplication_application_version`, `qcoreapplication_organization_domain` in Rust");
static_assert(
    ::rust::IsRelocatable<::QStringList>::value,
    "type QStringList should be trivially move constructible and trivially destructible in C++ to be used as a return value of `qcoreapplication_library_paths` in Rust");
static_assert(
    ::rust::IsRelocatable<::Qt::ConnectionType>::value,
    "type Qt::ConnectionType should be trivially move constructible and trivially destructible in C++ to be used as an argument of `QCoreApplication_connect_about_to_quit` in Rust");
static_assert(
    ::rust::IsRelocatable<::rust::cxxqt1::QMetaObjectConnection>::value,
    "type rust::cxxqt1::QMetaObjectConnection should be trivially move constructible and trivially destructible in C++ to be used as a return value of `QCoreApplication_connect_about_to_quit` in Rust");
static_assert(
    ::rust::IsRelocatable<::rust::cxxqtgen1::QCoreApplicationCxxQtSignalHandleraboutToQuit>::value,
    "type rust::cxxqtgen1::QCoreApplicationCxxQtSignalHandleraboutToQuit should be trivially move constructible and trivially destructible in C++ to be used as an argument of `QCoreApplication_connect_about_to_quit`, `drop_QCoreApplication_signal_handler_aboutToQuit` in Rust");

namespace rust {
namespace cxxqtlib1 {
extern "C" {
::QCoreApplication *rust$cxxqtlib1$cxxbridge1$194$qcoreapplication_new(::QVector_QByteArray const &args) noexcept {
  ::std::unique_ptr<::QCoreApplication> (*qcoreapplication_new$)(::QVector_QByteArray const &) = ::rust::cxxqtlib1::qcoreapplicationNew;
  return qcoreapplication_new$(args).release();
}

void rust$cxxqtlib1$cxxbridge1$194$qcoreapplication_add_library_path(::QCoreApplication &app, ::QString const &path) noexcept {
  void (*qcoreapplication_add_library_path$)(::QCoreApplication &, ::QString const &) = ::rust::cxxqtlib1::qapplicationAddLibraryPath;
  qcoreapplication_add_library_path$(app, path);
}

void rust$cxxqtlib1$cxxbridge1$194$qcoreapplication_application_name(::QCoreApplication const &app, ::QString *return$) noexcept {
  ::QString (*qcoreapplication_application_name$)(::QCoreApplication const &) = ::rust::cxxqtlib1::qapplicationApplicationName;
  new (return$) ::QString(qcoreapplication_application_name$(app));
}

void rust$cxxqtlib1$cxxbridge1$194$qcoreapplication_application_version(::QCoreApplication const &app, ::QString *return$) noexcept {
  ::QString (*qcoreapplication_application_version$)(::QCoreApplication const &) = ::rust::cxxqtlib1::qapplicationApplicationVersion;
  new (return$) ::QString(qcoreapplication_application_version$(app));
}

::std::int32_t rust$cxxqtlib1$cxxbridge1$194$qcoreapplication_exec(::QCoreApplication &app) noexcept {
  ::std::int32_t (*qcoreapplication_exec$)(::QCoreApplication &) = ::rust::cxxqtlib1::qapplicationExec;
  return qcoreapplication_exec$(app);
}

void rust$cxxqtlib1$cxxbridge1$194$qcoreapplication_library_paths(::QCoreApplication const &app, ::QStringList *return$) noexcept {
  ::QStringList (*qcoreapplication_library_paths$)(::QCoreApplication const &) = ::rust::cxxqtlib1::qapplicationLibraryPaths;
  new (return$) ::QStringList(qcoreapplication_library_paths$(app));
}

void rust$cxxqtlib1$cxxbridge1$194$qcoreapplication_organization_domain(::QCoreApplication const &app, ::QString *return$) noexcept {
  ::QString (*qcoreapplication_organization_domain$)(::QCoreApplication const &) = ::rust::cxxqtlib1::qapplicationOrganizationDomain;
  new (return$) ::QString(qcoreapplication_organization_domain$(app));
}

void rust$cxxqtlib1$cxxbridge1$194$qcoreapplication_organization_name(::QCoreApplication const &app, ::QString *return$) noexcept {
  ::QString (*qcoreapplication_organization_name$)(::QCoreApplication const &) = ::rust::cxxqtlib1::qapplicationOrganizationName;
  new (return$) ::QString(qcoreapplication_organization_name$(app));
}

void rust$cxxqtlib1$cxxbridge1$194$qcoreapplication_remove_library_path(::QCoreApplication const &app, ::QString const &path) noexcept {
  void (*qcoreapplication_remove_library_path$)(::QCoreApplication const &, ::QString const &) = ::rust::cxxqtlib1::qapplicationRemoveLibraryPath;
  qcoreapplication_remove_library_path$(app, path);
}

void rust$cxxqtlib1$cxxbridge1$194$qcoreapplication_set_application_name(::QCoreApplication &app, ::QString const &name) noexcept {
  void (*qcoreapplication_set_application_name$)(::QCoreApplication &, ::QString const &) = ::rust::cxxqtlib1::qapplicationSetApplicationName;
  qcoreapplication_set_application_name$(app, name);
}

void rust$cxxqtlib1$cxxbridge1$194$qcoreapplication_set_application_version(::QCoreApplication &app, ::QString const &version) noexcept {
  void (*qcoreapplication_set_application_version$)(::QCoreApplication &, ::QString const &) = ::rust::cxxqtlib1::qapplicationSetApplicationVersion;
  qcoreapplication_set_application_version$(app, version);
}

void rust$cxxqtlib1$cxxbridge1$194$qcoreapplication_set_library_paths(::QCoreApplication &app, ::QStringList const &paths) noexcept {
  void (*qcoreapplication_set_library_paths$)(::QCoreApplication &, ::QStringList const &) = ::rust::cxxqtlib1::qapplicationSetLibraryPaths;
  qcoreapplication_set_library_paths$(app, paths);
}

void rust$cxxqtlib1$cxxbridge1$194$qcoreapplication_set_organization_domain(::QCoreApplication &app, ::QString const &domain) noexcept {
  void (*qcoreapplication_set_organization_domain$)(::QCoreApplication &, ::QString const &) = ::rust::cxxqtlib1::qapplicationSetOrganizationDomain;
  qcoreapplication_set_organization_domain$(app, domain);
}

void rust$cxxqtlib1$cxxbridge1$194$qcoreapplication_set_organization_name(::QCoreApplication &app, ::QString const &name) noexcept {
  void (*qcoreapplication_set_organization_name$)(::QCoreApplication &, ::QString const &) = ::rust::cxxqtlib1::qapplicationSetOrganizationName;
  qcoreapplication_set_organization_name$(app, name);
}
} // extern "C"
} // namespace cxxqtlib1

namespace cxxqtgen1 {
extern "C" {
void rust$cxxqtgen1$cxxbridge1$194$QCoreApplication_connect_about_to_quit(::QCoreApplication &self_value, ::rust::cxxqtgen1::QCoreApplicationCxxQtSignalHandleraboutToQuit *signal_handler, ::Qt::ConnectionType *conn_type, ::rust::cxxqt1::QMetaObjectConnection *return$) noexcept {
  ::rust::cxxqt1::QMetaObjectConnection (*QCoreApplication_connect_about_to_quit$)(::QCoreApplication &, ::rust::cxxqtgen1::QCoreApplicationCxxQtSignalHandleraboutToQuit, ::Qt::ConnectionType) = ::rust::cxxqtgen1::QCoreApplication_aboutToQuitConnect;
  new (return$) ::rust::cxxqt1::QMetaObjectConnection(QCoreApplication_connect_about_to_quit$(self_value, ::std::move(*signal_handler), ::std::move(*conn_type)));
}

void rust$cxxqtgen1$cxxbridge1$194$drop_QCoreApplication_signal_handler_aboutToQuit(::rust::cxxqtgen1::QCoreApplicationCxxQtSignalHandleraboutToQuit *handler) noexcept;

void rust$cxxqtgen1$cxxbridge1$194$call_QCoreApplication_signal_handler_aboutToQuit(::rust::cxxqtgen1::QCoreApplicationCxxQtSignalHandleraboutToQuit &handler, ::QCoreApplication &self_value) noexcept;
} // extern "C"

void drop_QCoreApplication_signal_handler_aboutToQuit(::rust::cxxqtgen1::QCoreApplicationCxxQtSignalHandleraboutToQuit handler) noexcept {
  ::rust::ManuallyDrop<::rust::cxxqtgen1::QCoreApplicationCxxQtSignalHandleraboutToQuit> handler$(::std::move(handler));
  rust$cxxqtgen1$cxxbridge1$194$drop_QCoreApplication_signal_handler_aboutToQuit(&handler$.value);
}

void call_QCoreApplication_signal_handler_aboutToQuit(::rust::cxxqtgen1::QCoreApplicationCxxQtSignalHandleraboutToQuit &handler, ::QCoreApplication &self_value) noexcept {
  rust$cxxqtgen1$cxxbridge1$194$call_QCoreApplication_signal_handler_aboutToQuit(handler, self_value);
}
} // namespace cxxqtgen1
} // namespace rust

extern "C" {
static_assert(::rust::detail::is_complete<::std::remove_extent<::QCoreApplication>::type>::value, "definition of `::QCoreApplication` is required");
static_assert(sizeof(::std::unique_ptr<::QCoreApplication>) == sizeof(void *), "");
static_assert(alignof(::std::unique_ptr<::QCoreApplication>) == alignof(void *), "");
void cxxbridge1$unique_ptr$QCoreApplication$null(::std::unique_ptr<::QCoreApplication> *ptr) noexcept {
  ::new (ptr) ::std::unique_ptr<::QCoreApplication>();
}
void cxxbridge1$unique_ptr$QCoreApplication$raw(::std::unique_ptr<::QCoreApplication> *ptr, ::std::unique_ptr<::QCoreApplication>::pointer raw) noexcept {
  ::new (ptr) ::std::unique_ptr<::QCoreApplication>(raw);
}
::std::unique_ptr<::QCoreApplication>::element_type const *cxxbridge1$unique_ptr$QCoreApplication$get(::std::unique_ptr<::QCoreApplication> const &ptr) noexcept {
  return ptr.get();
}
::std::unique_ptr<::QCoreApplication>::pointer cxxbridge1$unique_ptr$QCoreApplication$release(::std::unique_ptr<::QCoreApplication> &ptr) noexcept {
  return ptr.release();
}
void cxxbridge1$unique_ptr$QCoreApplication$drop(::std::unique_ptr<::QCoreApplication> *ptr) noexcept {
  ::rust::deleter_if<::rust::detail::is_complete<::QCoreApplication>::value>{}(ptr);
}
} // extern "C"
