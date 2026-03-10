#include "cxx-qt-lib/qt.h"
#include "cxx-qt-lib/qmargins.h"
#include "cxx-qt-lib/qsize.h"
#include "cxx-qt-lib/qstring.h"
#include "cxx-qt-lib/qsizef.h"
#include "cxx-qt-lib/common.h"
#include <cstdint>
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
    ::rust::IsRelocatable<::Qt::AspectRatioMode>::value,
    "type Qt::AspectRatioMode should be trivially move constructible and trivially destructible in C++ to be used as an argument of `scale`, `scaled` in Rust");
static_assert(
    ::rust::IsRelocatable<::QMargins>::value,
    "type QMargins should be trivially move constructible and trivially destructible in C++ to be used as an argument of `grown_by`, `shrunk_by` in Rust");
static_assert(
    ::rust::IsRelocatable<::QSize>::value,
    "type QSize should be trivially move constructible and trivially destructible in C++ to be used as a return value of `bounded_to`, `expanded_to`, `grown_by` in Rust");
static_assert(
    ::rust::IsRelocatable<::QString>::value,
    "type QString should be trivially move constructible and trivially destructible in C++ to be used as a return value of `qsize_to_debug_qstring` in Rust");
static_assert(
    ::rust::IsRelocatable<::QSizeF>::value,
    "type QSizeF should be trivially move constructible and trivially destructible in C++ to be used as a return value of `to_sizef` in Rust");

extern "C" {
void cxxbridge1$194$QSize$bounded_to(::QSize const &self, ::QSize const &other_size, ::QSize *return$) noexcept {
  ::QSize (::QSize::*bounded_to$)(::QSize const &) const = &::QSize::boundedTo;
  new (return$) ::QSize((self.*bounded_to$)(other_size));
}

void cxxbridge1$194$QSize$expanded_to(::QSize const &self, ::QSize const &other_size, ::QSize *return$) noexcept {
  ::QSize (::QSize::*expanded_to$)(::QSize const &) const = &::QSize::expandedTo;
  new (return$) ::QSize((self.*expanded_to$)(other_size));
}

::std::int32_t cxxbridge1$194$QSize$height(::QSize const &self) noexcept {
  ::std::int32_t (::QSize::*height$)() const = &::QSize::height;
  return (self.*height$)();
}

bool cxxbridge1$194$QSize$is_empty(::QSize const &self) noexcept {
  bool (::QSize::*is_empty$)() const = &::QSize::isEmpty;
  return (self.*is_empty$)();
}

bool cxxbridge1$194$QSize$is_null(::QSize const &self) noexcept {
  bool (::QSize::*is_null$)() const = &::QSize::isNull;
  return (self.*is_null$)();
}

bool cxxbridge1$194$QSize$is_valid(::QSize const &self) noexcept {
  bool (::QSize::*is_valid$)() const = &::QSize::isValid;
  return (self.*is_valid$)();
}

void cxxbridge1$194$QSize$grown_by(::QSize const &self, ::QMargins *margins, ::QSize *return$) noexcept {
  ::QSize (::QSize::*grown_by$)(::QMargins) const = &::QSize::grownBy;
  new (return$) ::QSize((self.*grown_by$)(::std::move(*margins)));
}

void cxxbridge1$194$QSize$scale(::QSize &self, ::QSize const &size, ::Qt::AspectRatioMode *mode) noexcept {
  void (::QSize::*scale$)(::QSize const &, ::Qt::AspectRatioMode) = &::QSize::scale;
  (self.*scale$)(size, ::std::move(*mode));
}

void cxxbridge1$194$QSize$scaled(::QSize const &self, ::QSize const &s, ::Qt::AspectRatioMode *mode, ::QSize *return$) noexcept {
  ::QSize (::QSize::*scaled$)(::QSize const &, ::Qt::AspectRatioMode) const = &::QSize::scaled;
  new (return$) ::QSize((self.*scaled$)(s, ::std::move(*mode)));
}

void cxxbridge1$194$QSize$set_height(::QSize &self, ::std::int32_t height) noexcept {
  void (::QSize::*set_height$)(::std::int32_t) = &::QSize::setHeight;
  (self.*set_height$)(height);
}

void cxxbridge1$194$QSize$set_width(::QSize &self, ::std::int32_t width) noexcept {
  void (::QSize::*set_width$)(::std::int32_t) = &::QSize::setWidth;
  (self.*set_width$)(width);
}

void cxxbridge1$194$QSize$shrunk_by(::QSize const &self, ::QMargins *margins, ::QSize *return$) noexcept {
  ::QSize (::QSize::*shrunk_by$)(::QMargins) const = &::QSize::shrunkBy;
  new (return$) ::QSize((self.*shrunk_by$)(::std::move(*margins)));
}

void cxxbridge1$194$QSize$to_sizef(::QSize const &self, ::QSizeF *return$) noexcept {
  ::QSizeF (::QSize::*to_sizef$)() const = &::QSize::toSizeF;
  new (return$) ::QSizeF((self.*to_sizef$)());
}

void cxxbridge1$194$QSize$transpose(::QSize &self) noexcept {
  void (::QSize::*transpose$)() = &::QSize::transpose;
  (self.*transpose$)();
}

void cxxbridge1$194$QSize$transposed(::QSize const &self, ::QSize *return$) noexcept {
  ::QSize (::QSize::*transposed$)() const = &::QSize::transposed;
  new (return$) ::QSize((self.*transposed$)());
}

::std::int32_t cxxbridge1$194$QSize$width(::QSize const &self) noexcept {
  ::std::int32_t (::QSize::*width$)() const = &::QSize::width;
  return (self.*width$)();
}
} // extern "C"

namespace rust {
namespace cxxqtlib1 {
extern "C" {
void rust$cxxqtlib1$cxxbridge1$194$qsize_init_default(::QSize *return$) noexcept {
  ::QSize (*qsize_init_default$)() = ::rust::cxxqtlib1::construct;
  new (return$) ::QSize(qsize_init_default$());
}

void rust$cxxqtlib1$cxxbridge1$194$qsize_init(::std::int32_t w, ::std::int32_t h, ::QSize *return$) noexcept {
  ::QSize (*qsize_init$)(::std::int32_t, ::std::int32_t) = ::rust::cxxqtlib1::construct;
  new (return$) ::QSize(qsize_init$(w, h));
}

void rust$cxxqtlib1$cxxbridge1$194$qsize_to_debug_qstring(::QSize const &value, ::QString *return$) noexcept {
  ::QString (*qsize_to_debug_qstring$)(::QSize const &) = ::rust::cxxqtlib1::toDebugQString;
  new (return$) ::QString(qsize_to_debug_qstring$(value));
}

void rust$cxxqtlib1$cxxbridge1$194$qsize_plus(::QSize const &a, ::QSize const &b, ::QSize *return$) noexcept {
  ::QSize (*qsize_plus$)(::QSize const &, ::QSize const &) = ::rust::cxxqtlib1::operatorPlus;
  new (return$) ::QSize(qsize_plus$(a, b));
}

void rust$cxxqtlib1$cxxbridge1$194$qsize_minus(::QSize const &a, ::QSize const &b, ::QSize *return$) noexcept {
  ::QSize (*qsize_minus$)(::QSize const &, ::QSize const &) = ::rust::cxxqtlib1::operatorMinus;
  new (return$) ::QSize(qsize_minus$(a, b));
}

void rust$cxxqtlib1$cxxbridge1$194$qsize_mul(double a, ::QSize const &b, ::QSize *return$) noexcept {
  ::QSize (*qsize_mul$)(double, ::QSize const &) = ::rust::cxxqtlib1::operatorMul;
  new (return$) ::QSize(qsize_mul$(a, b));
}

void rust$cxxqtlib1$cxxbridge1$194$qsize_div(double a, ::QSize const &b, ::QSize *return$) noexcept {
  ::QSize (*qsize_div$)(double, ::QSize const &) = ::rust::cxxqtlib1::operatorDiv;
  new (return$) ::QSize(qsize_div$(a, b));
}
} // extern "C"
} // namespace cxxqtlib1
} // namespace rust
