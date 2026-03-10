#include "cxx-qt-lib/qbytearray.h"
#include "cxx-qt-lib/qstring.h"
#include "cxx-qt-lib/qstringlist.h"
#include "cxx-qt-lib/qurl.h"
#include "cxx-qt-lib/common.h"
#include <cstdint>
#include <new>
#include <type_traits>

#ifdef __GNUC__
#pragma GCC diagnostic ignored "-Wmissing-declarations"
#ifdef __clang__
#pragma clang diagnostic ignored "-Wdollar-in-identifier-extension"
#endif // __clang__
#endif // __GNUC__

namespace rust {
inline namespace cxxbridge1 {
// #include "rust/cxx.h"

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
} // namespace cxxbridge1
} // namespace rust

static_assert(
    ::rust::IsRelocatable<::QByteArray>::value,
    "type QByteArray should be trivially move constructible and trivially destructible in C++ to be used as a return value of `qurl_to_encoded`, `qurl_to_percent_encoding` in Rust");
static_assert(
    ::rust::IsRelocatable<::QString>::value,
    "type QString should be trivially move constructible and trivially destructible in C++ to be used as a return value of `error_string`, `scheme_or_default`, `to_local_file_or_default` in Rust");
static_assert(
    ::rust::IsRelocatable<::QStringList>::value,
    "type QStringList should be trivially move constructible and trivially destructible in C++ to be used as a return value of `qurl_idn_whitelist` in Rust");
static_assert(
    ::rust::IsRelocatable<::QUrl>::value,
    "type QUrl should be trivially move constructible and trivially destructible in C++ to be used as a return value of `resolved`, `qurl_from_encoded`, `qurl_from_local_file` in Rust");

extern "C" {
void cxxbridge1$194$QUrl$clear(::QUrl &self) noexcept {
  void (::QUrl::*clear$)() = &::QUrl::clear;
  (self.*clear$)();
}

void cxxbridge1$194$QUrl$error_string(::QUrl const &self, ::QString *return$) noexcept {
  ::QString (::QUrl::*error_string$)() const = &::QUrl::errorString;
  new (return$) ::QString((self.*error_string$)());
}

bool cxxbridge1$194$QUrl$has_fragment(::QUrl const &self) noexcept {
  bool (::QUrl::*has_fragment$)() const = &::QUrl::hasFragment;
  return (self.*has_fragment$)();
}

bool cxxbridge1$194$QUrl$has_query(::QUrl const &self) noexcept {
  bool (::QUrl::*has_query$)() const = &::QUrl::hasQuery;
  return (self.*has_query$)();
}

bool cxxbridge1$194$QUrl$is_empty(::QUrl const &self) noexcept {
  bool (::QUrl::*is_empty$)() const = &::QUrl::isEmpty;
  return (self.*is_empty$)();
}

bool cxxbridge1$194$QUrl$is_local_file(::QUrl const &self) noexcept {
  bool (::QUrl::*is_local_file$)() const = &::QUrl::isLocalFile;
  return (self.*is_local_file$)();
}

bool cxxbridge1$194$QUrl$is_parent_of(::QUrl const &self, ::QUrl const &child_url) noexcept {
  bool (::QUrl::*is_parent_of$)(::QUrl const &) const = &::QUrl::isParentOf;
  return (self.*is_parent_of$)(child_url);
}

bool cxxbridge1$194$QUrl$is_relative(::QUrl const &self) noexcept {
  bool (::QUrl::*is_relative$)() const = &::QUrl::isRelative;
  return (self.*is_relative$)();
}

bool cxxbridge1$194$QUrl$is_valid(::QUrl const &self) noexcept {
  bool (::QUrl::*is_valid$)() const = &::QUrl::isValid;
  return (self.*is_valid$)();
}

::std::int32_t cxxbridge1$194$QUrl$port_or(::QUrl const &self, ::std::int32_t default_port) noexcept {
  ::std::int32_t (::QUrl::*port_or$)(::std::int32_t) const = &::QUrl::port;
  return (self.*port_or$)(default_port);
}

void cxxbridge1$194$QUrl$resolved(::QUrl const &self, ::QUrl const &relative, ::QUrl *return$) noexcept {
  ::QUrl (::QUrl::*resolved$)(::QUrl const &) const = &::QUrl::resolved;
  new (return$) ::QUrl((self.*resolved$)(relative));
}

void cxxbridge1$194$QUrl$scheme_or_default(::QUrl const &self, ::QString *return$) noexcept {
  ::QString (::QUrl::*scheme_or_default$)() const = &::QUrl::scheme;
  new (return$) ::QString((self.*scheme_or_default$)());
}

void cxxbridge1$194$QUrl$set_port(::QUrl &self, ::std::int32_t port) noexcept {
  void (::QUrl::*set_port$)(::std::int32_t) = &::QUrl::setPort;
  (self.*set_port$)(port);
}

void cxxbridge1$194$QUrl$to_local_file_or_default(::QUrl const &self, ::QString *return$) noexcept {
  ::QString (::QUrl::*to_local_file_or_default$)() const = &::QUrl::toLocalFile;
  new (return$) ::QString((self.*to_local_file_or_default$)());
}
} // extern "C"

namespace rust {
namespace cxxqtlib1 {
extern "C" {
void rust$cxxqtlib1$cxxbridge1$194$qurl_authority(::QUrl const &url, ::QString *return$) noexcept {
  ::QString (*qurl_authority$)(::QUrl const &) = ::rust::cxxqtlib1::qurlAuthority;
  new (return$) ::QString(qurl_authority$(url));
}

void rust$cxxqtlib1$cxxbridge1$194$qurl_file_name(::QUrl const &url, ::QString *return$) noexcept {
  ::QString (*qurl_file_name$)(::QUrl const &) = ::rust::cxxqtlib1::qurlFileName;
  new (return$) ::QString(qurl_file_name$(url));
}

void rust$cxxqtlib1$cxxbridge1$194$qurl_fragment(::QUrl const &url, ::QString *return$) noexcept {
  ::QString (*qurl_fragment$)(::QUrl const &) = ::rust::cxxqtlib1::qurlFragment;
  new (return$) ::QString(qurl_fragment$(url));
}

void rust$cxxqtlib1$cxxbridge1$194$qurl_from_encoded(::QByteArray const &input, ::QUrl *return$) noexcept {
  ::QUrl (*qurl_from_encoded$)(::QByteArray const &) = ::rust::cxxqtlib1::qurlFromEncoded;
  new (return$) ::QUrl(qurl_from_encoded$(input));
}

void rust$cxxqtlib1$cxxbridge1$194$qurl_from_local_file(::QString const &local_file, ::QUrl *return$) noexcept {
  ::QUrl (*qurl_from_local_file$)(::QString const &) = ::rust::cxxqtlib1::qurlFromLocalFile;
  new (return$) ::QUrl(qurl_from_local_file$(local_file));
}

void rust$cxxqtlib1$cxxbridge1$194$qurl_from_percent_encoding(::QByteArray const &input, ::QString *return$) noexcept {
  ::QString (*qurl_from_percent_encoding$)(::QByteArray const &) = ::rust::cxxqtlib1::qurlFromPercentEncoding;
  new (return$) ::QString(qurl_from_percent_encoding$(input));
}

void rust$cxxqtlib1$cxxbridge1$194$qurl_from_user_input(::QString const &user_input, ::QString const &working_directory, ::QUrl *return$) noexcept {
  ::QUrl (*qurl_from_user_input$)(::QString const &, ::QString const &) = ::rust::cxxqtlib1::qurlFromUserInput;
  new (return$) ::QUrl(qurl_from_user_input$(user_input, working_directory));
}

void rust$cxxqtlib1$cxxbridge1$194$qurl_host(::QUrl const &url, ::QString *return$) noexcept {
  ::QString (*qurl_host$)(::QUrl const &) = ::rust::cxxqtlib1::qurlHost;
  new (return$) ::QString(qurl_host$(url));
}

void rust$cxxqtlib1$cxxbridge1$194$qurl_idn_whitelist(::QStringList *return$) noexcept {
  ::QStringList (*qurl_idn_whitelist$)() = ::rust::cxxqtlib1::qurlIdnWhitelist;
  new (return$) ::QStringList(qurl_idn_whitelist$());
}

void rust$cxxqtlib1$cxxbridge1$194$qurl_path(::QUrl const &url, ::QString *return$) noexcept {
  ::QString (*qurl_path$)(::QUrl const &) = ::rust::cxxqtlib1::qurlPath;
  new (return$) ::QString(qurl_path$(url));
}

void rust$cxxqtlib1$cxxbridge1$194$qurl_password(::QUrl const &url, ::QString *return$) noexcept {
  ::QString (*qurl_password$)(::QUrl const &) = ::rust::cxxqtlib1::qurlPassword;
  new (return$) ::QString(qurl_password$(url));
}

void rust$cxxqtlib1$cxxbridge1$194$qurl_query(::QUrl const &url, ::QString *return$) noexcept {
  ::QString (*qurl_query$)(::QUrl const &) = ::rust::cxxqtlib1::qurlQuery;
  new (return$) ::QString(qurl_query$(url));
}

void rust$cxxqtlib1$cxxbridge1$194$qurl_set_authority(::QUrl &url, ::QString const &authority) noexcept {
  void (*qurl_set_authority$)(::QUrl &, ::QString const &) = ::rust::cxxqtlib1::qurlSetAuthority;
  qurl_set_authority$(url, authority);
}

void rust$cxxqtlib1$cxxbridge1$194$qurl_set_fragment(::QUrl &url, ::QString const &fragment) noexcept {
  void (*qurl_set_fragment$)(::QUrl &, ::QString const &) = ::rust::cxxqtlib1::qurlSetFragment;
  qurl_set_fragment$(url, fragment);
}

void rust$cxxqtlib1$cxxbridge1$194$qurl_set_host(::QUrl &url, ::QString const &host) noexcept {
  void (*qurl_set_host$)(::QUrl &, ::QString const &) = ::rust::cxxqtlib1::qurlSetHost;
  qurl_set_host$(url, host);
}

void rust$cxxqtlib1$cxxbridge1$194$qurl_set_idn_whitelist(::QStringList const &list) noexcept {
  void (*qurl_set_idn_whitelist$)(::QStringList const &) = ::rust::cxxqtlib1::qurlSetIdnWhitelist;
  qurl_set_idn_whitelist$(list);
}

void rust$cxxqtlib1$cxxbridge1$194$qurl_set_password(::QUrl &url, ::QString const &password) noexcept {
  void (*qurl_set_password$)(::QUrl &, ::QString const &) = ::rust::cxxqtlib1::qurlSetPassword;
  qurl_set_password$(url, password);
}

void rust$cxxqtlib1$cxxbridge1$194$qurl_set_path(::QUrl &url, ::QString const &path) noexcept {
  void (*qurl_set_path$)(::QUrl &, ::QString const &) = ::rust::cxxqtlib1::qurlSetPath;
  qurl_set_path$(url, path);
}

void rust$cxxqtlib1$cxxbridge1$194$qurl_set_query(::QUrl &url, ::QString const &query) noexcept {
  void (*qurl_set_query$)(::QUrl &, ::QString const &) = ::rust::cxxqtlib1::qurlSetQuery;
  qurl_set_query$(url, query);
}

void rust$cxxqtlib1$cxxbridge1$194$qurl_set_scheme(::QUrl &url, ::QString const &scheme) noexcept {
  void (*qurl_set_scheme$)(::QUrl &, ::QString const &) = ::rust::cxxqtlib1::qurlSetScheme;
  qurl_set_scheme$(url, scheme);
}

void rust$cxxqtlib1$cxxbridge1$194$qurl_set_url(::QUrl &url, ::QString const &new_url) noexcept {
  void (*qurl_set_url$)(::QUrl &, ::QString const &) = ::rust::cxxqtlib1::qurlSetUrl;
  qurl_set_url$(url, new_url);
}

void rust$cxxqtlib1$cxxbridge1$194$qurl_set_user_info(::QUrl &url, ::QString const &user_info) noexcept {
  void (*qurl_set_user_info$)(::QUrl &, ::QString const &) = ::rust::cxxqtlib1::qurlSetUserInfo;
  qurl_set_user_info$(url, user_info);
}

void rust$cxxqtlib1$cxxbridge1$194$qurl_set_user_name(::QUrl &url, ::QString const &user_name) noexcept {
  void (*qurl_set_user_name$)(::QUrl &, ::QString const &) = ::rust::cxxqtlib1::qurlSetUserName;
  qurl_set_user_name$(url, user_name);
}

void rust$cxxqtlib1$cxxbridge1$194$qurl_to_display_string(::QUrl const &url, ::QString *return$) noexcept {
  ::QString (*qurl_to_display_string$)(::QUrl const &) = ::rust::cxxqtlib1::qurlToDisplayString;
  new (return$) ::QString(qurl_to_display_string$(url));
}

void rust$cxxqtlib1$cxxbridge1$194$qurl_to_encoded(::QUrl const &url, ::QByteArray *return$) noexcept {
  ::QByteArray (*qurl_to_encoded$)(::QUrl const &) = ::rust::cxxqtlib1::qurlToEncoded;
  new (return$) ::QByteArray(qurl_to_encoded$(url));
}

void rust$cxxqtlib1$cxxbridge1$194$qurl_to_qstring(::QUrl const &url, ::QString *return$) noexcept {
  ::QString (*qurl_to_qstring$)(::QUrl const &) = ::rust::cxxqtlib1::qurlToQString;
  new (return$) ::QString(qurl_to_qstring$(url));
}

void rust$cxxqtlib1$cxxbridge1$194$qurl_to_percent_encoding(::QString const &input, ::QByteArray const &exclude, ::QByteArray const &include, ::QByteArray *return$) noexcept {
  ::QByteArray (*qurl_to_percent_encoding$)(::QString const &, ::QByteArray const &, ::QByteArray const &) = ::rust::cxxqtlib1::qurlToPercentEncoding;
  new (return$) ::QByteArray(qurl_to_percent_encoding$(input, exclude, include));
}

void rust$cxxqtlib1$cxxbridge1$194$qurl_user_info(::QUrl const &url, ::QString *return$) noexcept {
  ::QString (*qurl_user_info$)(::QUrl const &) = ::rust::cxxqtlib1::qurlUserInfo;
  new (return$) ::QString(qurl_user_info$(url));
}

void rust$cxxqtlib1$cxxbridge1$194$qurl_user_name(::QUrl const &url, ::QString *return$) noexcept {
  ::QString (*qurl_user_name$)(::QUrl const &) = ::rust::cxxqtlib1::qurlUserName;
  new (return$) ::QString(qurl_user_name$(url));
}

void rust$cxxqtlib1$cxxbridge1$194$qurl_drop(::QUrl &url) noexcept {
  void (*qurl_drop$)(::QUrl &) = ::rust::cxxqtlib1::drop;
  qurl_drop$(url);
}

void rust$cxxqtlib1$cxxbridge1$194$qurl_init_default(::QUrl *return$) noexcept {
  ::QUrl (*qurl_init_default$)() = ::rust::cxxqtlib1::construct;
  new (return$) ::QUrl(qurl_init_default$());
}

void rust$cxxqtlib1$cxxbridge1$194$qurl_init_from_qstring(::QString const &string, ::QUrl *return$) noexcept {
  ::QUrl (*qurl_init_from_qstring$)(::QString const &) = ::rust::cxxqtlib1::construct;
  new (return$) ::QUrl(qurl_init_from_qstring$(string));
}

void rust$cxxqtlib1$cxxbridge1$194$qurl_init_from_qurl(::QUrl const &url, ::QUrl *return$) noexcept {
  ::QUrl (*qurl_init_from_qurl$)(::QUrl const &) = ::rust::cxxqtlib1::construct;
  new (return$) ::QUrl(qurl_init_from_qurl$(url));
}

bool rust$cxxqtlib1$cxxbridge1$194$qurl_eq(::QUrl const &a, ::QUrl const &b) noexcept {
  bool (*qurl_eq$)(::QUrl const &, ::QUrl const &) = ::rust::cxxqtlib1::operatorEq;
  return qurl_eq$(a, b);
}

void rust$cxxqtlib1$cxxbridge1$194$qurl_to_debug_qstring(::QUrl const &url, ::QString *return$) noexcept {
  ::QString (*qurl_to_debug_qstring$)(::QUrl const &) = ::rust::cxxqtlib1::toDebugQString;
  new (return$) ::QString(qurl_to_debug_qstring$(url));
}
} // extern "C"
} // namespace cxxqtlib1
} // namespace rust
