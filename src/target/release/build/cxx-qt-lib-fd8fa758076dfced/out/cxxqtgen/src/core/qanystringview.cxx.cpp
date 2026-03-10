#include "cxx-qt-lib/qanystringview.h"
#include "cxx-qt-lib/qbytearray.h"
#include "cxx-qt-lib/qstring.h"
#include "cxx-qt-lib/common.h"
#include <array>
#include <cstdint>
#include <new>
#include <string>
#include <type_traits>
#if defined(_WIN32)
#include <basetsd.h>
#else
#include <sys/types.h>
#endif
#if __cplusplus >= 201703L
#include <string_view>
#endif

#ifdef __GNUC__
#pragma GCC diagnostic ignored "-Wmissing-declarations"
#ifdef __clang__
#pragma clang diagnostic ignored "-Wdollar-in-identifier-extension"
#endif // __clang__
#endif // __GNUC__

namespace rust {
inline namespace cxxbridge1 {
// #include "rust/cxx.h"

namespace {
template <typename T>
class impl;
} // namespace

class String;

#ifndef CXXBRIDGE1_RUST_STR
#define CXXBRIDGE1_RUST_STR
class Str final {
public:
  Str() noexcept;
  Str(const String &) noexcept;
  Str(const std::string &);
  Str(const char *);
  Str(const char *, std::size_t);

  Str &operator=(const Str &) & noexcept = default;

  explicit operator std::string() const;
#if __cplusplus >= 201703L
  explicit operator std::string_view() const;
#endif

  const char *data() const noexcept;
  std::size_t size() const noexcept;
  std::size_t length() const noexcept;
  bool empty() const noexcept;

  Str(const Str &) noexcept = default;
  ~Str() noexcept = default;

  using iterator = const char *;
  using const_iterator = const char *;
  const_iterator begin() const noexcept;
  const_iterator end() const noexcept;
  const_iterator cbegin() const noexcept;
  const_iterator cend() const noexcept;

  bool operator==(const Str &) const noexcept;
  bool operator!=(const Str &) const noexcept;
  bool operator<(const Str &) const noexcept;
  bool operator<=(const Str &) const noexcept;
  bool operator>(const Str &) const noexcept;
  bool operator>=(const Str &) const noexcept;

  void swap(Str &) noexcept;

private:
  class uninit;
  Str(uninit) noexcept;
  friend impl<Str>;

  std::array<std::uintptr_t, 2> repr;
};
#endif // CXXBRIDGE1_RUST_STR

#ifndef CXXBRIDGE1_RUST_ISIZE
#define CXXBRIDGE1_RUST_ISIZE
#if defined(_WIN32)
using isize = SSIZE_T;
#else
using isize = ssize_t;
#endif
#endif // CXXBRIDGE1_RUST_ISIZE

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
    ::rust::IsRelocatable<::QAnyStringView>::value,
    "type QAnyStringView should be trivially move constructible and trivially destructible in C++ to be used as a return value of `QAnyStringView_init_default`, `QAnyStringView_init_from_rust_string`, `QAnyStringView_init_from_qbytearray` in Rust");
static_assert(
    ::rust::IsRelocatable<::QString>::value,
    "type QString should be trivially move constructible and trivially destructible in C++ to be used as a return value of `to_qstring` in Rust");

extern "C" {
bool cxxbridge1$194$QAnyStringView$is_empty(::QAnyStringView const &self) noexcept {
  bool (::QAnyStringView::*is_empty$)() const = &::QAnyStringView::isEmpty;
  return (self.*is_empty$)();
}

bool cxxbridge1$194$QAnyStringView$is_null(::QAnyStringView const &self) noexcept {
  bool (::QAnyStringView::*is_null$)() const = &::QAnyStringView::isNull;
  return (self.*is_null$)();
}

void cxxbridge1$194$QAnyStringView$to_qstring(::QAnyStringView const &self, ::QString *return$) noexcept {
  ::QString (::QAnyStringView::*to_qstring$)() const = &::QAnyStringView::toString;
  new (return$) ::QString((self.*to_qstring$)());
}
} // extern "C"

namespace rust {
namespace cxxqtlib1 {
extern "C" {
void rust$cxxqtlib1$cxxbridge1$194$QAnyStringView_init_default(::QAnyStringView *return$) noexcept {
  ::QAnyStringView (*QAnyStringView_init_default$)() = ::rust::cxxqtlib1::construct;
  new (return$) ::QAnyStringView(QAnyStringView_init_default$());
}

void rust$cxxqtlib1$cxxbridge1$194$QAnyStringView_init_from_rust_string(::rust::Str string, ::QAnyStringView *return$) noexcept {
  ::QAnyStringView (*QAnyStringView_init_from_rust_string$)(::rust::Str) = ::rust::cxxqtlib1::qanystringviewInitFromRustString;
  new (return$) ::QAnyStringView(QAnyStringView_init_from_rust_string$(string));
}

void rust$cxxqtlib1$cxxbridge1$194$QAnyStringView_init_from_qbytearray(::QByteArray const &bytes, ::QAnyStringView *return$) noexcept {
  ::QAnyStringView (*QAnyStringView_init_from_qbytearray$)(::QByteArray const &) = ::rust::cxxqtlib1::construct;
  new (return$) ::QAnyStringView(QAnyStringView_init_from_qbytearray$(bytes));
}

void rust$cxxqtlib1$cxxbridge1$194$QAnyStringView_init_from_qstring(::QString const &string, ::QAnyStringView *return$) noexcept {
  ::QAnyStringView (*QAnyStringView_init_from_qstring$)(::QString const &) = ::rust::cxxqtlib1::construct;
  new (return$) ::QAnyStringView(QAnyStringView_init_from_qstring$(string));
}

void rust$cxxqtlib1$cxxbridge1$194$QAnyStringView_init_from_QAnyStringView(::QAnyStringView const &string, ::QAnyStringView *return$) noexcept {
  ::QAnyStringView (*QAnyStringView_init_from_QAnyStringView$)(::QAnyStringView const &) = ::rust::cxxqtlib1::construct;
  new (return$) ::QAnyStringView(QAnyStringView_init_from_QAnyStringView$(string));
}

bool rust$cxxqtlib1$cxxbridge1$194$QAnyStringView_eq(::QAnyStringView const &a, ::QAnyStringView const &b) noexcept {
  bool (*QAnyStringView_eq$)(::QAnyStringView const &, ::QAnyStringView const &) = ::rust::cxxqtlib1::operatorEq;
  return QAnyStringView_eq$(a, b);
}

::rust::isize rust$cxxqtlib1$cxxbridge1$194$QAnyStringView_len(::QAnyStringView const &string) noexcept {
  ::rust::isize (*QAnyStringView_len$)(::QAnyStringView const &) = ::rust::cxxqtlib1::qanystringviewLen;
  return QAnyStringView_len$(string);
}
} // extern "C"
} // namespace cxxqtlib1
} // namespace rust
