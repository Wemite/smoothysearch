#include "cxx-qt-lib/qpoint.h"
#include "cxx-qt-lib/qpointf.h"
#include "cxx-qt-lib/qstring.h"
#include "cxx-qt-lib/common.h"
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
    "type QPoint should be trivially move constructible and trivially destructible in C++ to be used as a return value of `to_point` in Rust");
static_assert(
    ::rust::IsRelocatable<::QPointF>::value,
    "type QPointF should be trivially move constructible and trivially destructible in C++ to be used as a return value of `transposed`, `qpointf_init_default`, `qpointf_init` in Rust");
static_assert(
    ::rust::IsRelocatable<::QString>::value,
    "type QString should be trivially move constructible and trivially destructible in C++ to be used as a return value of `qpointf_to_debug_qstring` in Rust");

extern "C" {
bool cxxbridge1$194$QPointF$is_null(::QPointF const &self) noexcept {
  bool (::QPointF::*is_null$)() const = &::QPointF::isNull;
  return (self.*is_null$)();
}

double cxxbridge1$194$QPointF$manhattan_length(::QPointF const &self) noexcept {
  double (::QPointF::*manhattan_length$)() const = &::QPointF::manhattanLength;
  return (self.*manhattan_length$)();
}

void cxxbridge1$194$QPointF$set_x(::QPointF &self, double x) noexcept {
  void (::QPointF::*set_x$)(double) = &::QPointF::setX;
  (self.*set_x$)(x);
}

void cxxbridge1$194$QPointF$set_y(::QPointF &self, double y) noexcept {
  void (::QPointF::*set_y$)(double) = &::QPointF::setY;
  (self.*set_y$)(y);
}

void cxxbridge1$194$QPointF$to_point(::QPointF const &self, ::QPoint *return$) noexcept {
  ::QPoint (::QPointF::*to_point$)() const = &::QPointF::toPoint;
  new (return$) ::QPoint((self.*to_point$)());
}

void cxxbridge1$194$QPointF$transposed(::QPointF const &self, ::QPointF *return$) noexcept {
  ::QPointF (::QPointF::*transposed$)() const = &::QPointF::transposed;
  new (return$) ::QPointF((self.*transposed$)());
}

double cxxbridge1$194$QPointF$x(::QPointF const &self) noexcept {
  double (::QPointF::*x$)() const = &::QPointF::x;
  return (self.*x$)();
}

double cxxbridge1$194$QPointF$y(::QPointF const &self) noexcept {
  double (::QPointF::*y$)() const = &::QPointF::y;
  return (self.*y$)();
}
} // extern "C"

namespace rust {
namespace cxxqtlib1 {
extern "C" {
double rust$cxxqtlib1$cxxbridge1$194$qpointf_dot_product(::QPointF const &p1, ::QPointF const &p2) noexcept {
  double (*qpointf_dot_product$)(::QPointF const &, ::QPointF const &) = ::rust::cxxqtlib1::qpointfDotProduct;
  return qpointf_dot_product$(p1, p2);
}

void rust$cxxqtlib1$cxxbridge1$194$qpointf_init_default(::QPointF *return$) noexcept {
  ::QPointF (*qpointf_init_default$)() = ::rust::cxxqtlib1::construct;
  new (return$) ::QPointF(qpointf_init_default$());
}

void rust$cxxqtlib1$cxxbridge1$194$qpointf_init(double x, double y, ::QPointF *return$) noexcept {
  ::QPointF (*qpointf_init$)(double, double) = ::rust::cxxqtlib1::construct;
  new (return$) ::QPointF(qpointf_init$(x, y));
}

void rust$cxxqtlib1$cxxbridge1$194$qpointf_from_qpoint(::QPoint const &point, ::QPointF *return$) noexcept {
  ::QPointF (*qpointf_from_qpoint$)(::QPoint const &) = ::rust::cxxqtlib1::construct;
  new (return$) ::QPointF(qpointf_from_qpoint$(point));
}

void rust$cxxqtlib1$cxxbridge1$194$qpointf_to_debug_qstring(::QPointF const &value, ::QString *return$) noexcept {
  ::QString (*qpointf_to_debug_qstring$)(::QPointF const &) = ::rust::cxxqtlib1::toDebugQString;
  new (return$) ::QString(qpointf_to_debug_qstring$(value));
}

void rust$cxxqtlib1$cxxbridge1$194$qpointf_plus(::QPointF const &a, ::QPointF const &b, ::QPointF *return$) noexcept {
  ::QPointF (*qpointf_plus$)(::QPointF const &, ::QPointF const &) = ::rust::cxxqtlib1::operatorPlus;
  new (return$) ::QPointF(qpointf_plus$(a, b));
}

void rust$cxxqtlib1$cxxbridge1$194$qpointf_minus(::QPointF const &a, ::QPointF const &b, ::QPointF *return$) noexcept {
  ::QPointF (*qpointf_minus$)(::QPointF const &, ::QPointF const &) = ::rust::cxxqtlib1::operatorMinus;
  new (return$) ::QPointF(qpointf_minus$(a, b));
}

void rust$cxxqtlib1$cxxbridge1$194$qpointf_mul(double a, ::QPointF const &b, ::QPointF *return$) noexcept {
  ::QPointF (*qpointf_mul$)(double, ::QPointF const &) = ::rust::cxxqtlib1::operatorMul;
  new (return$) ::QPointF(qpointf_mul$(a, b));
}

void rust$cxxqtlib1$cxxbridge1$194$qpointf_div(double a, ::QPointF const &b, ::QPointF *return$) noexcept {
  ::QPointF (*qpointf_div$)(double, ::QPointF const &) = ::rust::cxxqtlib1::operatorDiv;
  new (return$) ::QPointF(qpointf_div$(a, b));
}
} // extern "C"
} // namespace cxxqtlib1
} // namespace rust
