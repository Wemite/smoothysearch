#include "cxx-qt-lib/qpoint.h"
#include "cxx-qt-lib/qstring.h"
#include "cxx-qt-lib/qpointf.h"
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
    ::rust::IsRelocatable<::QPoint>::value,
    "type QPoint should be trivially move constructible and trivially destructible in C++ to be used as a return value of `transposed`, `qpoint_init_default`, `qpoint_init` in Rust");
static_assert(
    ::rust::IsRelocatable<::QString>::value,
    "type QString should be trivially move constructible and trivially destructible in C++ to be used as a return value of `qpoint_to_debug_qstring` in Rust");
static_assert(
    ::rust::IsRelocatable<::QPointF>::value,
    "type QPointF should be trivially move constructible and trivially destructible in C++ to be used as a return value of `to_pointf` in Rust");

extern "C" {
bool cxxbridge1$194$QPoint$is_null(::QPoint const &self) noexcept {
  bool (::QPoint::*is_null$)() const = &::QPoint::isNull;
  return (self.*is_null$)();
}

::std::int32_t cxxbridge1$194$QPoint$manhattan_length(::QPoint const &self) noexcept {
  ::std::int32_t (::QPoint::*manhattan_length$)() const = &::QPoint::manhattanLength;
  return (self.*manhattan_length$)();
}

void cxxbridge1$194$QPoint$set_x(::QPoint &self, ::std::int32_t x) noexcept {
  void (::QPoint::*set_x$)(::std::int32_t) = &::QPoint::setX;
  (self.*set_x$)(x);
}

void cxxbridge1$194$QPoint$set_y(::QPoint &self, ::std::int32_t y) noexcept {
  void (::QPoint::*set_y$)(::std::int32_t) = &::QPoint::setY;
  (self.*set_y$)(y);
}

void cxxbridge1$194$QPoint$to_pointf(::QPoint const &self, ::QPointF *return$) noexcept {
  ::QPointF (::QPoint::*to_pointf$)() const = &::QPoint::toPointF;
  new (return$) ::QPointF((self.*to_pointf$)());
}

void cxxbridge1$194$QPoint$transposed(::QPoint const &self, ::QPoint *return$) noexcept {
  ::QPoint (::QPoint::*transposed$)() const = &::QPoint::transposed;
  new (return$) ::QPoint((self.*transposed$)());
}

::std::int32_t cxxbridge1$194$QPoint$x(::QPoint const &self) noexcept {
  ::std::int32_t (::QPoint::*x$)() const = &::QPoint::x;
  return (self.*x$)();
}

::std::int32_t cxxbridge1$194$QPoint$y(::QPoint const &self) noexcept {
  ::std::int32_t (::QPoint::*y$)() const = &::QPoint::y;
  return (self.*y$)();
}
} // extern "C"

namespace rust {
namespace cxxqtlib1 {
extern "C" {
::std::int32_t rust$cxxqtlib1$cxxbridge1$194$qpoint_dot_product(::QPoint const &p1, ::QPoint const &p2) noexcept {
  ::std::int32_t (*qpoint_dot_product$)(::QPoint const &, ::QPoint const &) = ::rust::cxxqtlib1::qpointDotProduct;
  return qpoint_dot_product$(p1, p2);
}

void rust$cxxqtlib1$cxxbridge1$194$qpoint_init_default(::QPoint *return$) noexcept {
  ::QPoint (*qpoint_init_default$)() = ::rust::cxxqtlib1::construct;
  new (return$) ::QPoint(qpoint_init_default$());
}

void rust$cxxqtlib1$cxxbridge1$194$qpoint_init(::std::int32_t x, ::std::int32_t y, ::QPoint *return$) noexcept {
  ::QPoint (*qpoint_init$)(::std::int32_t, ::std::int32_t) = ::rust::cxxqtlib1::construct;
  new (return$) ::QPoint(qpoint_init$(x, y));
}

void rust$cxxqtlib1$cxxbridge1$194$qpoint_to_debug_qstring(::QPoint const &value, ::QString *return$) noexcept {
  ::QString (*qpoint_to_debug_qstring$)(::QPoint const &) = ::rust::cxxqtlib1::toDebugQString;
  new (return$) ::QString(qpoint_to_debug_qstring$(value));
}

void rust$cxxqtlib1$cxxbridge1$194$qpoint_plus(::QPoint const &a, ::QPoint const &b, ::QPoint *return$) noexcept {
  ::QPoint (*qpoint_plus$)(::QPoint const &, ::QPoint const &) = ::rust::cxxqtlib1::operatorPlus;
  new (return$) ::QPoint(qpoint_plus$(a, b));
}

void rust$cxxqtlib1$cxxbridge1$194$qpoint_minus(::QPoint const &a, ::QPoint const &b, ::QPoint *return$) noexcept {
  ::QPoint (*qpoint_minus$)(::QPoint const &, ::QPoint const &) = ::rust::cxxqtlib1::operatorMinus;
  new (return$) ::QPoint(qpoint_minus$(a, b));
}

void rust$cxxqtlib1$cxxbridge1$194$qpoint_mul_f32(float a, ::QPoint const &b, ::QPoint *return$) noexcept {
  ::QPoint (*qpoint_mul_f32$)(float, ::QPoint const &) = ::rust::cxxqtlib1::operatorMul;
  new (return$) ::QPoint(qpoint_mul_f32$(a, b));
}

void rust$cxxqtlib1$cxxbridge1$194$qpoint_mul_f64(double a, ::QPoint const &b, ::QPoint *return$) noexcept {
  ::QPoint (*qpoint_mul_f64$)(double, ::QPoint const &) = ::rust::cxxqtlib1::operatorMul;
  new (return$) ::QPoint(qpoint_mul_f64$(a, b));
}

void rust$cxxqtlib1$cxxbridge1$194$qpoint_mul_i32(::std::int32_t a, ::QPoint const &b, ::QPoint *return$) noexcept {
  ::QPoint (*qpoint_mul_i32$)(::std::int32_t, ::QPoint const &) = ::rust::cxxqtlib1::operatorMul;
  new (return$) ::QPoint(qpoint_mul_i32$(a, b));
}

void rust$cxxqtlib1$cxxbridge1$194$qpoint_div(double a, ::QPoint const &b, ::QPoint *return$) noexcept {
  ::QPoint (*qpoint_div$)(double, ::QPoint const &) = ::rust::cxxqtlib1::operatorDiv;
  new (return$) ::QPoint(qpoint_div$(a, b));
}
} // extern "C"
} // namespace cxxqtlib1
} // namespace rust
