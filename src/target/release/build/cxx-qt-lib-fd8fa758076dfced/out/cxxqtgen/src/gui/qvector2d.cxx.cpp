#include "cxx-qt-lib/qpoint.h"
#include "cxx-qt-lib/qpointf.h"
#include "cxx-qt-lib/qstring.h"
#include "cxx-qt-lib/qvector2d.h"
#include "cxx-qt-lib/qvector3d.h"
#include "cxx-qt-lib/qvector4d.h"
#include "cxx-qt-lib/common.h"
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
    ::rust::IsRelocatable<::QPoint>::value,
    "type QPoint should be trivially move constructible and trivially destructible in C++ to be used as an argument of `qvector2d_init_qpoint` or return value of `to_point` in Rust");
static_assert(
    ::rust::IsRelocatable<::QPointF>::value,
    "type QPointF should be trivially move constructible and trivially destructible in C++ to be used as an argument of `qvector2d_init_qpointf` or return value of `to_pointf` in Rust");
static_assert(
    ::rust::IsRelocatable<::QString>::value,
    "type QString should be trivially move constructible and trivially destructible in C++ to be used as a return value of `qvector2d_to_debug_qstring` in Rust");
static_assert(
    ::rust::IsRelocatable<::QVector2D>::value,
    "type QVector2D should be trivially move constructible and trivially destructible in C++ to be used as an argument of `qvector2d_distance_to_line`, `qvector2d_distance_to_point` or return value of `normalized`, `qvector2d_init_qvector4d`, `qvector2d_init_qvector3d` in Rust");
static_assert(
    ::rust::IsRelocatable<::QVector3D>::value,
    "type QVector3D should be trivially move constructible and trivially destructible in C++ to be used as an argument of `qvector2d_init_qvector3d` in Rust");
static_assert(
    ::rust::IsRelocatable<::QVector4D>::value,
    "type QVector4D should be trivially move constructible and trivially destructible in C++ to be used as an argument of `qvector2d_init_qvector4d` in Rust");

extern "C" {
bool cxxbridge1$194$QVector2D$is_null(::QVector2D const &self) noexcept {
  bool (::QVector2D::*is_null$)() const = &::QVector2D::isNull;
  return (self.*is_null$)();
}

float cxxbridge1$194$QVector2D$length(::QVector2D const &self) noexcept {
  float (::QVector2D::*length$)() const = &::QVector2D::length;
  return (self.*length$)();
}

float cxxbridge1$194$QVector2D$length_squared(::QVector2D const &self) noexcept {
  float (::QVector2D::*length_squared$)() const = &::QVector2D::lengthSquared;
  return (self.*length_squared$)();
}

void cxxbridge1$194$QVector2D$normalize(::QVector2D &self) noexcept {
  void (::QVector2D::*normalize$)() = &::QVector2D::normalize;
  (self.*normalize$)();
}

void cxxbridge1$194$QVector2D$normalized(::QVector2D const &self, ::QVector2D *return$) noexcept {
  ::QVector2D (::QVector2D::*normalized$)() const = &::QVector2D::normalized;
  new (return$) ::QVector2D((self.*normalized$)());
}

void cxxbridge1$194$QVector2D$set_x(::QVector2D &self, float x) noexcept {
  void (::QVector2D::*set_x$)(float) = &::QVector2D::setX;
  (self.*set_x$)(x);
}

void cxxbridge1$194$QVector2D$set_y(::QVector2D &self, float y) noexcept {
  void (::QVector2D::*set_y$)(float) = &::QVector2D::setY;
  (self.*set_y$)(y);
}

void cxxbridge1$194$QVector2D$to_point(::QVector2D const &self, ::QPoint *return$) noexcept {
  ::QPoint (::QVector2D::*to_point$)() const = &::QVector2D::toPoint;
  new (return$) ::QPoint((self.*to_point$)());
}

void cxxbridge1$194$QVector2D$to_pointf(::QVector2D const &self, ::QPointF *return$) noexcept {
  ::QPointF (::QVector2D::*to_pointf$)() const = &::QVector2D::toPointF;
  new (return$) ::QPointF((self.*to_pointf$)());
}

float cxxbridge1$194$QVector2D$x(::QVector2D const &self) noexcept {
  float (::QVector2D::*x$)() const = &::QVector2D::x;
  return (self.*x$)();
}

float cxxbridge1$194$QVector2D$y(::QVector2D const &self) noexcept {
  float (::QVector2D::*y$)() const = &::QVector2D::y;
  return (self.*y$)();
}
} // extern "C"

namespace rust {
namespace cxxqtlib1 {
extern "C" {
void rust$cxxqtlib1$cxxbridge1$194$qvector2d_init_qvector4d(::QVector4D *vector, ::QVector2D *return$) noexcept {
  ::QVector2D (*qvector2d_init_qvector4d$)(::QVector4D) = ::rust::cxxqtlib1::construct;
  new (return$) ::QVector2D(qvector2d_init_qvector4d$(::std::move(*vector)));
}

void rust$cxxqtlib1$cxxbridge1$194$qvector2d_init_qvector3d(::QVector3D *vector, ::QVector2D *return$) noexcept {
  ::QVector2D (*qvector2d_init_qvector3d$)(::QVector3D) = ::rust::cxxqtlib1::construct;
  new (return$) ::QVector2D(qvector2d_init_qvector3d$(::std::move(*vector)));
}

void rust$cxxqtlib1$cxxbridge1$194$qvector2d_init_qpointf(::QPointF *point, ::QVector2D *return$) noexcept {
  ::QVector2D (*qvector2d_init_qpointf$)(::QPointF) = ::rust::cxxqtlib1::construct;
  new (return$) ::QVector2D(qvector2d_init_qpointf$(::std::move(*point)));
}

void rust$cxxqtlib1$cxxbridge1$194$qvector2d_init_qpoint(::QPoint *point, ::QVector2D *return$) noexcept {
  ::QVector2D (*qvector2d_init_qpoint$)(::QPoint) = ::rust::cxxqtlib1::construct;
  new (return$) ::QVector2D(qvector2d_init_qpoint$(::std::move(*point)));
}

void rust$cxxqtlib1$cxxbridge1$194$qvector2d_init(float x, float y, ::QVector2D *return$) noexcept {
  ::QVector2D (*qvector2d_init$)(float, float) = ::rust::cxxqtlib1::construct;
  new (return$) ::QVector2D(qvector2d_init$(x, y));
}

void rust$cxxqtlib1$cxxbridge1$194$qvector2d_init_default(::QVector2D *return$) noexcept {
  ::QVector2D (*qvector2d_init_default$)() = ::rust::cxxqtlib1::construct;
  new (return$) ::QVector2D(qvector2d_init_default$());
}

float rust$cxxqtlib1$cxxbridge1$194$qvector2d_distance_to_line(::QVector2D const &vector, ::QVector2D *point, ::QVector2D *direction) noexcept {
  float (*qvector2d_distance_to_line$)(::QVector2D const &, ::QVector2D, ::QVector2D) = ::rust::cxxqtlib1::qvector2DDistanceToLine;
  return qvector2d_distance_to_line$(vector, ::std::move(*point), ::std::move(*direction));
}

float rust$cxxqtlib1$cxxbridge1$194$qvector2d_distance_to_point(::QVector2D const &vector, ::QVector2D *point) noexcept {
  float (*qvector2d_distance_to_point$)(::QVector2D const &, ::QVector2D) = ::rust::cxxqtlib1::qvector2DDistanceToPoint;
  return qvector2d_distance_to_point$(vector, ::std::move(*point));
}

void rust$cxxqtlib1$cxxbridge1$194$qvector2d_to_debug_qstring(::QVector2D const &value, ::QString *return$) noexcept {
  ::QString (*qvector2d_to_debug_qstring$)(::QVector2D const &) = ::rust::cxxqtlib1::toDebugQString;
  new (return$) ::QString(qvector2d_to_debug_qstring$(value));
}

void rust$cxxqtlib1$cxxbridge1$194$qvector2d_plus(::QVector2D const &a, ::QVector2D const &b, ::QVector2D *return$) noexcept {
  ::QVector2D (*qvector2d_plus$)(::QVector2D const &, ::QVector2D const &) = ::rust::cxxqtlib1::operatorPlus;
  new (return$) ::QVector2D(qvector2d_plus$(a, b));
}

void rust$cxxqtlib1$cxxbridge1$194$qvector2d_minus(::QVector2D const &a, ::QVector2D const &b, ::QVector2D *return$) noexcept {
  ::QVector2D (*qvector2d_minus$)(::QVector2D const &, ::QVector2D const &) = ::rust::cxxqtlib1::operatorMinus;
  new (return$) ::QVector2D(qvector2d_minus$(a, b));
}

void rust$cxxqtlib1$cxxbridge1$194$qvector2d_mul(float a, ::QVector2D const &b, ::QVector2D *return$) noexcept {
  ::QVector2D (*qvector2d_mul$)(float, ::QVector2D const &) = ::rust::cxxqtlib1::operatorMul;
  new (return$) ::QVector2D(qvector2d_mul$(a, b));
}

void rust$cxxqtlib1$cxxbridge1$194$qvector2d_div(float a, ::QVector2D const &b, ::QVector2D *return$) noexcept {
  ::QVector2D (*qvector2d_div$)(float, ::QVector2D const &) = ::rust::cxxqtlib1::operatorDiv;
  new (return$) ::QVector2D(qvector2d_div$(a, b));
}
} // extern "C"
} // namespace cxxqtlib1
} // namespace rust
