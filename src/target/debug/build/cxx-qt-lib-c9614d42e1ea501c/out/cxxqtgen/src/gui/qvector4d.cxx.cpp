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
    "type QPoint should be trivially move constructible and trivially destructible in C++ to be used as an argument of `qvector4d_init_qpoint` or return value of `to_point` in Rust");
static_assert(
    ::rust::IsRelocatable<::QPointF>::value,
    "type QPointF should be trivially move constructible and trivially destructible in C++ to be used as an argument of `qvector4d_init_qpointf` or return value of `to_pointf` in Rust");
static_assert(
    ::rust::IsRelocatable<::QString>::value,
    "type QString should be trivially move constructible and trivially destructible in C++ to be used as a return value of `qvector4d_to_debug_qstring` in Rust");
static_assert(
    ::rust::IsRelocatable<::QVector2D>::value,
    "type QVector2D should be trivially move constructible and trivially destructible in C++ to be used as an argument of `qvector4d_init_qvector2d` or return value of `to_vector_2d_affine` in Rust");
static_assert(
    ::rust::IsRelocatable<::QVector3D>::value,
    "type QVector3D should be trivially move constructible and trivially destructible in C++ to be used as an argument of `qvector4d_init_qvector3d` or return value of `to_vector_3d_affine` in Rust");
static_assert(
    ::rust::IsRelocatable<::QVector4D>::value,
    "type QVector4D should be trivially move constructible and trivially destructible in C++ to be used as a return value of `normalized`, `qvector4d_init_qvector3d`, `qvector4d_init_qvector2d` in Rust");

extern "C" {
bool cxxbridge1$194$QVector4D$is_null(::QVector4D const &self) noexcept {
  bool (::QVector4D::*is_null$)() const = &::QVector4D::isNull;
  return (self.*is_null$)();
}

float cxxbridge1$194$QVector4D$length(::QVector4D const &self) noexcept {
  float (::QVector4D::*length$)() const = &::QVector4D::length;
  return (self.*length$)();
}

float cxxbridge1$194$QVector4D$length_squared(::QVector4D const &self) noexcept {
  float (::QVector4D::*length_squared$)() const = &::QVector4D::lengthSquared;
  return (self.*length_squared$)();
}

void cxxbridge1$194$QVector4D$normalize(::QVector4D &self) noexcept {
  void (::QVector4D::*normalize$)() = &::QVector4D::normalize;
  (self.*normalize$)();
}

void cxxbridge1$194$QVector4D$normalized(::QVector4D const &self, ::QVector4D *return$) noexcept {
  ::QVector4D (::QVector4D::*normalized$)() const = &::QVector4D::normalized;
  new (return$) ::QVector4D((self.*normalized$)());
}

void cxxbridge1$194$QVector4D$set_w(::QVector4D &self, float w) noexcept {
  void (::QVector4D::*set_w$)(float) = &::QVector4D::setW;
  (self.*set_w$)(w);
}

void cxxbridge1$194$QVector4D$set_x(::QVector4D &self, float x) noexcept {
  void (::QVector4D::*set_x$)(float) = &::QVector4D::setX;
  (self.*set_x$)(x);
}

void cxxbridge1$194$QVector4D$set_y(::QVector4D &self, float y) noexcept {
  void (::QVector4D::*set_y$)(float) = &::QVector4D::setY;
  (self.*set_y$)(y);
}

void cxxbridge1$194$QVector4D$set_z(::QVector4D &self, float z) noexcept {
  void (::QVector4D::*set_z$)(float) = &::QVector4D::setZ;
  (self.*set_z$)(z);
}

void cxxbridge1$194$QVector4D$to_point(::QVector4D const &self, ::QPoint *return$) noexcept {
  ::QPoint (::QVector4D::*to_point$)() const = &::QVector4D::toPoint;
  new (return$) ::QPoint((self.*to_point$)());
}

void cxxbridge1$194$QVector4D$to_pointf(::QVector4D const &self, ::QPointF *return$) noexcept {
  ::QPointF (::QVector4D::*to_pointf$)() const = &::QVector4D::toPointF;
  new (return$) ::QPointF((self.*to_pointf$)());
}

void cxxbridge1$194$QVector4D$to_vector_2d_affine(::QVector4D const &self, ::QVector2D *return$) noexcept {
  ::QVector2D (::QVector4D::*to_vector_2d_affine$)() const = &::QVector4D::toVector2DAffine;
  new (return$) ::QVector2D((self.*to_vector_2d_affine$)());
}

void cxxbridge1$194$QVector4D$to_vector_3d_affine(::QVector4D const &self, ::QVector3D *return$) noexcept {
  ::QVector3D (::QVector4D::*to_vector_3d_affine$)() const = &::QVector4D::toVector3DAffine;
  new (return$) ::QVector3D((self.*to_vector_3d_affine$)());
}

float cxxbridge1$194$QVector4D$w(::QVector4D const &self) noexcept {
  float (::QVector4D::*w$)() const = &::QVector4D::w;
  return (self.*w$)();
}

float cxxbridge1$194$QVector4D$x(::QVector4D const &self) noexcept {
  float (::QVector4D::*x$)() const = &::QVector4D::x;
  return (self.*x$)();
}

float cxxbridge1$194$QVector4D$y(::QVector4D const &self) noexcept {
  float (::QVector4D::*y$)() const = &::QVector4D::y;
  return (self.*y$)();
}

float cxxbridge1$194$QVector4D$z(::QVector4D const &self) noexcept {
  float (::QVector4D::*z$)() const = &::QVector4D::z;
  return (self.*z$)();
}
} // extern "C"

namespace rust {
namespace cxxqtlib1 {
extern "C" {
void rust$cxxqtlib1$cxxbridge1$194$qvector4d_init_qvector3d(::QVector3D *vector, ::QVector4D *return$) noexcept {
  ::QVector4D (*qvector4d_init_qvector3d$)(::QVector3D) = ::rust::cxxqtlib1::construct;
  new (return$) ::QVector4D(qvector4d_init_qvector3d$(::std::move(*vector)));
}

void rust$cxxqtlib1$cxxbridge1$194$qvector4d_init_qvector2d(::QVector2D *vector, ::QVector4D *return$) noexcept {
  ::QVector4D (*qvector4d_init_qvector2d$)(::QVector2D) = ::rust::cxxqtlib1::construct;
  new (return$) ::QVector4D(qvector4d_init_qvector2d$(::std::move(*vector)));
}

void rust$cxxqtlib1$cxxbridge1$194$qvector4d_init_qpointf(::QPointF *point, ::QVector4D *return$) noexcept {
  ::QVector4D (*qvector4d_init_qpointf$)(::QPointF) = ::rust::cxxqtlib1::construct;
  new (return$) ::QVector4D(qvector4d_init_qpointf$(::std::move(*point)));
}

void rust$cxxqtlib1$cxxbridge1$194$qvector4d_init_qpoint(::QPoint *point, ::QVector4D *return$) noexcept {
  ::QVector4D (*qvector4d_init_qpoint$)(::QPoint) = ::rust::cxxqtlib1::construct;
  new (return$) ::QVector4D(qvector4d_init_qpoint$(::std::move(*point)));
}

void rust$cxxqtlib1$cxxbridge1$194$qvector4d_init(float x, float y, float z, float w, ::QVector4D *return$) noexcept {
  ::QVector4D (*qvector4d_init$)(float, float, float, float) = ::rust::cxxqtlib1::construct;
  new (return$) ::QVector4D(qvector4d_init$(x, y, z, w));
}

void rust$cxxqtlib1$cxxbridge1$194$qvector4d_init_default(::QVector4D *return$) noexcept {
  ::QVector4D (*qvector4d_init_default$)() = ::rust::cxxqtlib1::construct;
  new (return$) ::QVector4D(qvector4d_init_default$());
}

void rust$cxxqtlib1$cxxbridge1$194$qvector4d_to_debug_qstring(::QVector4D const &value, ::QString *return$) noexcept {
  ::QString (*qvector4d_to_debug_qstring$)(::QVector4D const &) = ::rust::cxxqtlib1::toDebugQString;
  new (return$) ::QString(qvector4d_to_debug_qstring$(value));
}

void rust$cxxqtlib1$cxxbridge1$194$qvector4d_plus(::QVector4D const &a, ::QVector4D const &b, ::QVector4D *return$) noexcept {
  ::QVector4D (*qvector4d_plus$)(::QVector4D const &, ::QVector4D const &) = ::rust::cxxqtlib1::operatorPlus;
  new (return$) ::QVector4D(qvector4d_plus$(a, b));
}

void rust$cxxqtlib1$cxxbridge1$194$qvector4d_minus(::QVector4D const &a, ::QVector4D const &b, ::QVector4D *return$) noexcept {
  ::QVector4D (*qvector4d_minus$)(::QVector4D const &, ::QVector4D const &) = ::rust::cxxqtlib1::operatorMinus;
  new (return$) ::QVector4D(qvector4d_minus$(a, b));
}

void rust$cxxqtlib1$cxxbridge1$194$qvector4d_mul(float a, ::QVector4D const &b, ::QVector4D *return$) noexcept {
  ::QVector4D (*qvector4d_mul$)(float, ::QVector4D const &) = ::rust::cxxqtlib1::operatorMul;
  new (return$) ::QVector4D(qvector4d_mul$(a, b));
}

void rust$cxxqtlib1$cxxbridge1$194$qvector4d_div(float a, ::QVector4D const &b, ::QVector4D *return$) noexcept {
  ::QVector4D (*qvector4d_div$)(float, ::QVector4D const &) = ::rust::cxxqtlib1::operatorDiv;
  new (return$) ::QVector4D(qvector4d_div$(a, b));
}
} // extern "C"
} // namespace cxxqtlib1
} // namespace rust
