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
    "type QPoint should be trivially move constructible and trivially destructible in C++ to be used as an argument of `qvector3d_init_qpoint` or return value of `to_point` in Rust");
static_assert(
    ::rust::IsRelocatable<::QPointF>::value,
    "type QPointF should be trivially move constructible and trivially destructible in C++ to be used as an argument of `qvector3d_init_qpointf` or return value of `to_pointf` in Rust");
static_assert(
    ::rust::IsRelocatable<::QString>::value,
    "type QString should be trivially move constructible and trivially destructible in C++ to be used as a return value of `qvector3d_to_debug_qstring` in Rust");
static_assert(
    ::rust::IsRelocatable<::QVector2D>::value,
    "type QVector2D should be trivially move constructible and trivially destructible in C++ to be used as an argument of `qvector3d_init_qvector2d` or return value of `to_vector2d` in Rust");
static_assert(
    ::rust::IsRelocatable<::QVector3D>::value,
    "type QVector3D should be trivially move constructible and trivially destructible in C++ to be used as an argument of `qvector3d_distance_to_line`, `qvector3d_distance_to_plane`, `qvector3d_distance_to_point` or return value of `normalized`, `qvector3d_init_qvector4d`, `qvector3d_init_qvector2d` in Rust");
static_assert(
    ::rust::IsRelocatable<::QVector4D>::value,
    "type QVector4D should be trivially move constructible and trivially destructible in C++ to be used as an argument of `qvector3d_init_qvector4d` or return value of `to_vector4d` in Rust");

extern "C" {
bool cxxbridge1$194$QVector3D$is_null(::QVector3D const &self) noexcept {
  bool (::QVector3D::*is_null$)() const = &::QVector3D::isNull;
  return (self.*is_null$)();
}

float cxxbridge1$194$QVector3D$length(::QVector3D const &self) noexcept {
  float (::QVector3D::*length$)() const = &::QVector3D::length;
  return (self.*length$)();
}

float cxxbridge1$194$QVector3D$length_squared(::QVector3D const &self) noexcept {
  float (::QVector3D::*length_squared$)() const = &::QVector3D::lengthSquared;
  return (self.*length_squared$)();
}

void cxxbridge1$194$QVector3D$normalize(::QVector3D &self) noexcept {
  void (::QVector3D::*normalize$)() = &::QVector3D::normalize;
  (self.*normalize$)();
}

void cxxbridge1$194$QVector3D$normalized(::QVector3D const &self, ::QVector3D *return$) noexcept {
  ::QVector3D (::QVector3D::*normalized$)() const = &::QVector3D::normalized;
  new (return$) ::QVector3D((self.*normalized$)());
}

void cxxbridge1$194$QVector3D$set_x(::QVector3D &self, float x) noexcept {
  void (::QVector3D::*set_x$)(float) = &::QVector3D::setX;
  (self.*set_x$)(x);
}

void cxxbridge1$194$QVector3D$set_y(::QVector3D &self, float y) noexcept {
  void (::QVector3D::*set_y$)(float) = &::QVector3D::setY;
  (self.*set_y$)(y);
}

void cxxbridge1$194$QVector3D$set_z(::QVector3D &self, float z) noexcept {
  void (::QVector3D::*set_z$)(float) = &::QVector3D::setZ;
  (self.*set_z$)(z);
}

void cxxbridge1$194$QVector3D$to_point(::QVector3D const &self, ::QPoint *return$) noexcept {
  ::QPoint (::QVector3D::*to_point$)() const = &::QVector3D::toPoint;
  new (return$) ::QPoint((self.*to_point$)());
}

void cxxbridge1$194$QVector3D$to_pointf(::QVector3D const &self, ::QPointF *return$) noexcept {
  ::QPointF (::QVector3D::*to_pointf$)() const = &::QVector3D::toPointF;
  new (return$) ::QPointF((self.*to_pointf$)());
}

void cxxbridge1$194$QVector3D$to_vector2d(::QVector3D const &self, ::QVector2D *return$) noexcept {
  ::QVector2D (::QVector3D::*to_vector2d$)() const = &::QVector3D::toVector2D;
  new (return$) ::QVector2D((self.*to_vector2d$)());
}

void cxxbridge1$194$QVector3D$to_vector4d(::QVector3D const &self, ::QVector4D *return$) noexcept {
  ::QVector4D (::QVector3D::*to_vector4d$)() const = &::QVector3D::toVector4D;
  new (return$) ::QVector4D((self.*to_vector4d$)());
}

float cxxbridge1$194$QVector3D$x(::QVector3D const &self) noexcept {
  float (::QVector3D::*x$)() const = &::QVector3D::x;
  return (self.*x$)();
}

float cxxbridge1$194$QVector3D$y(::QVector3D const &self) noexcept {
  float (::QVector3D::*y$)() const = &::QVector3D::y;
  return (self.*y$)();
}

float cxxbridge1$194$QVector3D$z(::QVector3D const &self) noexcept {
  float (::QVector3D::*z$)() const = &::QVector3D::z;
  return (self.*z$)();
}
} // extern "C"

namespace rust {
namespace cxxqtlib1 {
extern "C" {
void rust$cxxqtlib1$cxxbridge1$194$qvector3d_init_qvector4d(::QVector4D *vector, ::QVector3D *return$) noexcept {
  ::QVector3D (*qvector3d_init_qvector4d$)(::QVector4D) = ::rust::cxxqtlib1::construct;
  new (return$) ::QVector3D(qvector3d_init_qvector4d$(::std::move(*vector)));
}

void rust$cxxqtlib1$cxxbridge1$194$qvector3d_init_qvector2d(::QVector2D *vector, ::QVector3D *return$) noexcept {
  ::QVector3D (*qvector3d_init_qvector2d$)(::QVector2D) = ::rust::cxxqtlib1::construct;
  new (return$) ::QVector3D(qvector3d_init_qvector2d$(::std::move(*vector)));
}

void rust$cxxqtlib1$cxxbridge1$194$qvector3d_init_qpointf(::QPointF *point, ::QVector3D *return$) noexcept {
  ::QVector3D (*qvector3d_init_qpointf$)(::QPointF) = ::rust::cxxqtlib1::construct;
  new (return$) ::QVector3D(qvector3d_init_qpointf$(::std::move(*point)));
}

void rust$cxxqtlib1$cxxbridge1$194$qvector3d_init_qpoint(::QPoint *point, ::QVector3D *return$) noexcept {
  ::QVector3D (*qvector3d_init_qpoint$)(::QPoint) = ::rust::cxxqtlib1::construct;
  new (return$) ::QVector3D(qvector3d_init_qpoint$(::std::move(*point)));
}

void rust$cxxqtlib1$cxxbridge1$194$qvector3d_init(float x, float y, float z, ::QVector3D *return$) noexcept {
  ::QVector3D (*qvector3d_init$)(float, float, float) = ::rust::cxxqtlib1::construct;
  new (return$) ::QVector3D(qvector3d_init$(x, y, z));
}

void rust$cxxqtlib1$cxxbridge1$194$qvector3d_init_default(::QVector3D *return$) noexcept {
  ::QVector3D (*qvector3d_init_default$)() = ::rust::cxxqtlib1::construct;
  new (return$) ::QVector3D(qvector3d_init_default$());
}

float rust$cxxqtlib1$cxxbridge1$194$qvector3d_distance_to_line(::QVector3D const &vector, ::QVector3D *point, ::QVector3D *direction) noexcept {
  float (*qvector3d_distance_to_line$)(::QVector3D const &, ::QVector3D, ::QVector3D) = ::rust::cxxqtlib1::qvector3DDistanceToLine;
  return qvector3d_distance_to_line$(vector, ::std::move(*point), ::std::move(*direction));
}

float rust$cxxqtlib1$cxxbridge1$194$qvector3d_distance_to_plane(::QVector3D const &vector, ::QVector3D *point, ::QVector3D *normal) noexcept {
  float (*qvector3d_distance_to_plane$)(::QVector3D const &, ::QVector3D, ::QVector3D) = ::rust::cxxqtlib1::qvector3DDistanceToPlane;
  return qvector3d_distance_to_plane$(vector, ::std::move(*point), ::std::move(*normal));
}

float rust$cxxqtlib1$cxxbridge1$194$qvector3d_distance_to_point(::QVector3D const &vector, ::QVector3D *point) noexcept {
  float (*qvector3d_distance_to_point$)(::QVector3D const &, ::QVector3D) = ::rust::cxxqtlib1::qvector3DDistanceToPoint;
  return qvector3d_distance_to_point$(vector, ::std::move(*point));
}

void rust$cxxqtlib1$cxxbridge1$194$qvector3d_to_debug_qstring(::QVector3D const &value, ::QString *return$) noexcept {
  ::QString (*qvector3d_to_debug_qstring$)(::QVector3D const &) = ::rust::cxxqtlib1::toDebugQString;
  new (return$) ::QString(qvector3d_to_debug_qstring$(value));
}

void rust$cxxqtlib1$cxxbridge1$194$qvector3d_plus(::QVector3D const &a, ::QVector3D const &b, ::QVector3D *return$) noexcept {
  ::QVector3D (*qvector3d_plus$)(::QVector3D const &, ::QVector3D const &) = ::rust::cxxqtlib1::operatorPlus;
  new (return$) ::QVector3D(qvector3d_plus$(a, b));
}

void rust$cxxqtlib1$cxxbridge1$194$qvector3d_minus(::QVector3D const &a, ::QVector3D const &b, ::QVector3D *return$) noexcept {
  ::QVector3D (*qvector3d_minus$)(::QVector3D const &, ::QVector3D const &) = ::rust::cxxqtlib1::operatorMinus;
  new (return$) ::QVector3D(qvector3d_minus$(a, b));
}

void rust$cxxqtlib1$cxxbridge1$194$qvector3d_mul(float a, ::QVector3D const &b, ::QVector3D *return$) noexcept {
  ::QVector3D (*qvector3d_mul$)(float, ::QVector3D const &) = ::rust::cxxqtlib1::operatorMul;
  new (return$) ::QVector3D(qvector3d_mul$(a, b));
}

void rust$cxxqtlib1$cxxbridge1$194$qvector3d_div(float a, ::QVector3D const &b, ::QVector3D *return$) noexcept {
  ::QVector3D (*qvector3d_div$)(float, ::QVector3D const &) = ::rust::cxxqtlib1::operatorDiv;
  new (return$) ::QVector3D(qvector3d_div$(a, b));
}
} // extern "C"
} // namespace cxxqtlib1
} // namespace rust
