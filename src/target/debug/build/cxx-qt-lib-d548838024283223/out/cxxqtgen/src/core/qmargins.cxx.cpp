#include "cxx-qt-lib/qmargins.h"
#include "cxx-qt-lib/qstring.h"
#include "cxx-qt-lib/qmarginsf.h"
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
    ::rust::IsRelocatable<::QMargins>::value,
    "type QMargins should be trivially move constructible and trivially destructible in C++ to be used as a return value of `qmargins_default`, `qmargins_new`, `qmargins_plus` in Rust");
static_assert(
    ::rust::IsRelocatable<::QString>::value,
    "type QString should be trivially move constructible and trivially destructible in C++ to be used as a return value of `qmargins_to_debug_qstring` in Rust");
static_assert(
    ::rust::IsRelocatable<::QMarginsF>::value,
    "type QMarginsF should be trivially move constructible and trivially destructible in C++ to be used as a return value of `to_marginsf` in Rust");

extern "C" {
::std::int32_t cxxbridge1$194$QMargins$bottom(::QMargins const &self) noexcept {
  ::std::int32_t (::QMargins::*bottom$)() const = &::QMargins::bottom;
  return (self.*bottom$)();
}

bool cxxbridge1$194$QMargins$is_null(::QMargins const &self) noexcept {
  bool (::QMargins::*is_null$)() const = &::QMargins::isNull;
  return (self.*is_null$)();
}

::std::int32_t cxxbridge1$194$QMargins$left(::QMargins const &self) noexcept {
  ::std::int32_t (::QMargins::*left$)() const = &::QMargins::left;
  return (self.*left$)();
}

::std::int32_t cxxbridge1$194$QMargins$right(::QMargins const &self) noexcept {
  ::std::int32_t (::QMargins::*right$)() const = &::QMargins::right;
  return (self.*right$)();
}

void cxxbridge1$194$QMargins$set_bottom(::QMargins &self, ::std::int32_t bottom) noexcept {
  void (::QMargins::*set_bottom$)(::std::int32_t) = &::QMargins::setBottom;
  (self.*set_bottom$)(bottom);
}

void cxxbridge1$194$QMargins$set_left(::QMargins &self, ::std::int32_t left) noexcept {
  void (::QMargins::*set_left$)(::std::int32_t) = &::QMargins::setLeft;
  (self.*set_left$)(left);
}

void cxxbridge1$194$QMargins$set_right(::QMargins &self, ::std::int32_t right) noexcept {
  void (::QMargins::*set_right$)(::std::int32_t) = &::QMargins::setRight;
  (self.*set_right$)(right);
}

void cxxbridge1$194$QMargins$set_top(::QMargins &self, ::std::int32_t top) noexcept {
  void (::QMargins::*set_top$)(::std::int32_t) = &::QMargins::setTop;
  (self.*set_top$)(top);
}

void cxxbridge1$194$QMargins$to_marginsf(::QMargins const &self, ::QMarginsF *return$) noexcept {
  ::QMarginsF (::QMargins::*to_marginsf$)() const = &::QMargins::toMarginsF;
  new (return$) ::QMarginsF((self.*to_marginsf$)());
}

::std::int32_t cxxbridge1$194$QMargins$top(::QMargins const &self) noexcept {
  ::std::int32_t (::QMargins::*top$)() const = &::QMargins::top;
  return (self.*top$)();
}
} // extern "C"

namespace rust {
namespace cxxqtlib1 {
extern "C" {
void rust$cxxqtlib1$cxxbridge1$194$qmargins_default(::QMargins *return$) noexcept {
  ::QMargins (*qmargins_default$)() = ::rust::cxxqtlib1::construct;
  new (return$) ::QMargins(qmargins_default$());
}

void rust$cxxqtlib1$cxxbridge1$194$qmargins_new(::std::int32_t left, ::std::int32_t top, ::std::int32_t right, ::std::int32_t bottom, ::QMargins *return$) noexcept {
  ::QMargins (*qmargins_new$)(::std::int32_t, ::std::int32_t, ::std::int32_t, ::std::int32_t) = ::rust::cxxqtlib1::construct;
  new (return$) ::QMargins(qmargins_new$(left, top, right, bottom));
}

void rust$cxxqtlib1$cxxbridge1$194$qmargins_to_debug_qstring(::QMargins const &value, ::QString *return$) noexcept {
  ::QString (*qmargins_to_debug_qstring$)(::QMargins const &) = ::rust::cxxqtlib1::toDebugQString;
  new (return$) ::QString(qmargins_to_debug_qstring$(value));
}

void rust$cxxqtlib1$cxxbridge1$194$qmargins_plus(::QMargins const &a, ::QMargins const &b, ::QMargins *return$) noexcept {
  ::QMargins (*qmargins_plus$)(::QMargins const &, ::QMargins const &) = ::rust::cxxqtlib1::operatorPlus;
  new (return$) ::QMargins(qmargins_plus$(a, b));
}

void rust$cxxqtlib1$cxxbridge1$194$qmargins_plus_i32(::QMargins const &a, ::std::int32_t const &b, ::QMargins *return$) noexcept {
  ::QMargins (*qmargins_plus_i32$)(::QMargins const &, ::std::int32_t const &) = ::rust::cxxqtlib1::operatorPlus;
  new (return$) ::QMargins(qmargins_plus_i32$(a, b));
}

void rust$cxxqtlib1$cxxbridge1$194$qmargins_minus(::QMargins const &a, ::QMargins const &b, ::QMargins *return$) noexcept {
  ::QMargins (*qmargins_minus$)(::QMargins const &, ::QMargins const &) = ::rust::cxxqtlib1::operatorMinus;
  new (return$) ::QMargins(qmargins_minus$(a, b));
}

void rust$cxxqtlib1$cxxbridge1$194$qmargins_minus_i32(::QMargins const &a, ::std::int32_t const &b, ::QMargins *return$) noexcept {
  ::QMargins (*qmargins_minus_i32$)(::QMargins const &, ::std::int32_t const &) = ::rust::cxxqtlib1::operatorMinus;
  new (return$) ::QMargins(qmargins_minus_i32$(a, b));
}

void rust$cxxqtlib1$cxxbridge1$194$qmargins_mul_i32(::std::int32_t a, ::QMargins const &b, ::QMargins *return$) noexcept {
  ::QMargins (*qmargins_mul_i32$)(::std::int32_t, ::QMargins const &) = ::rust::cxxqtlib1::operatorMul;
  new (return$) ::QMargins(qmargins_mul_i32$(a, b));
}

void rust$cxxqtlib1$cxxbridge1$194$qmargins_mul_f64(double a, ::QMargins const &b, ::QMargins *return$) noexcept {
  ::QMargins (*qmargins_mul_f64$)(double, ::QMargins const &) = ::rust::cxxqtlib1::operatorMul;
  new (return$) ::QMargins(qmargins_mul_f64$(a, b));
}

void rust$cxxqtlib1$cxxbridge1$194$qmargins_div_i32(::std::int32_t a, ::QMargins const &b, ::QMargins *return$) noexcept {
  ::QMargins (*qmargins_div_i32$)(::std::int32_t, ::QMargins const &) = ::rust::cxxqtlib1::operatorDiv;
  new (return$) ::QMargins(qmargins_div_i32$(a, b));
}

void rust$cxxqtlib1$cxxbridge1$194$qmargins_div_f64(double a, ::QMargins const &b, ::QMargins *return$) noexcept {
  ::QMargins (*qmargins_div_f64$)(double, ::QMargins const &) = ::rust::cxxqtlib1::operatorDiv;
  new (return$) ::QMargins(qmargins_div_f64$(a, b));
}
} // extern "C"
} // namespace cxxqtlib1
} // namespace rust
