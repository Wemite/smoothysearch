#include "cxx-qt-lib/qstring.h"
#include "cxx-qt-lib/qgenericmatrix.h"
#include "cxx-qt-lib/qvector3d.h"
#include "cxx-qt-lib/qvector4d.h"
#include "cxx-qt-lib/qquaternion.h"
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
    ::rust::IsRelocatable<::QString>::value,
    "type QString should be trivially move constructible and trivially destructible in C++ to be used as a return value of `qquaternion_to_debug_qstring` in Rust");
static_assert(
    ::rust::IsRelocatable<::QMatrix3x3>::value,
    "type QMatrix3x3 should be trivially move constructible and trivially destructible in C++ to be used as a return value of `to_rotation_matrix` in Rust");
static_assert(
    ::rust::IsRelocatable<::QVector3D>::value,
    "type QVector3D should be trivially move constructible and trivially destructible in C++ to be used as a return value of `rotated_vector`, `to_euler_angles`, `vector` in Rust");
static_assert(
    ::rust::IsRelocatable<::QVector4D>::value,
    "type QVector4D should be trivially move constructible and trivially destructible in C++ to be used as a return value of `to_vector_4d` in Rust");
static_assert(
    ::rust::IsRelocatable<::QQuaternion>::value,
    "type QQuaternion should be trivially move constructible and trivially destructible in C++ to be used as a return value of `conjugated`, `inverted`, `normalized` in Rust");

extern "C" {
void cxxbridge1$194$QQuaternion$conjugated(::QQuaternion const &self, ::QQuaternion *return$) noexcept {
  ::QQuaternion (::QQuaternion::*conjugated$)() const = &::QQuaternion::conjugated;
  new (return$) ::QQuaternion((self.*conjugated$)());
}

void cxxbridge1$194$QQuaternion$get_axes_raw(::QQuaternion const &self, ::QVector3D *x_axis, ::QVector3D *y_axis, ::QVector3D *z_axis) noexcept {
  void (::QQuaternion::*get_axes_raw$)(::QVector3D *, ::QVector3D *, ::QVector3D *) const = &::QQuaternion::getAxes;
  (self.*get_axes_raw$)(x_axis, y_axis, z_axis);
}

void cxxbridge1$194$QQuaternion$get_axis_and_angle_raw(::QQuaternion const &self, float *x, float *y, float *z, float *angle) noexcept {
  void (::QQuaternion::*get_axis_and_angle_raw$)(float *, float *, float *, float *) const = &::QQuaternion::getAxisAndAngle;
  (self.*get_axis_and_angle_raw$)(x, y, z, angle);
}

void cxxbridge1$194$QQuaternion$get_euler_angles_raw(::QQuaternion const &self, float *pitch, float *yaw, float *roll) noexcept {
  void (::QQuaternion::*get_euler_angles_raw$)(float *, float *, float *) const = &::QQuaternion::getEulerAngles;
  (self.*get_euler_angles_raw$)(pitch, yaw, roll);
}

void cxxbridge1$194$QQuaternion$inverted(::QQuaternion const &self, ::QQuaternion *return$) noexcept {
  ::QQuaternion (::QQuaternion::*inverted$)() const = &::QQuaternion::inverted;
  new (return$) ::QQuaternion((self.*inverted$)());
}

bool cxxbridge1$194$QQuaternion$is_identity(::QQuaternion const &self) noexcept {
  bool (::QQuaternion::*is_identity$)() const = &::QQuaternion::isIdentity;
  return (self.*is_identity$)();
}

bool cxxbridge1$194$QQuaternion$is_null(::QQuaternion const &self) noexcept {
  bool (::QQuaternion::*is_null$)() const = &::QQuaternion::isNull;
  return (self.*is_null$)();
}

float cxxbridge1$194$QQuaternion$length(::QQuaternion const &self) noexcept {
  float (::QQuaternion::*length$)() const = &::QQuaternion::length;
  return (self.*length$)();
}

float cxxbridge1$194$QQuaternion$length_squared(::QQuaternion const &self) noexcept {
  float (::QQuaternion::*length_squared$)() const = &::QQuaternion::lengthSquared;
  return (self.*length_squared$)();
}

void cxxbridge1$194$QQuaternion$normalize(::QQuaternion &self) noexcept {
  void (::QQuaternion::*normalize$)() = &::QQuaternion::normalize;
  (self.*normalize$)();
}

void cxxbridge1$194$QQuaternion$normalized(::QQuaternion const &self, ::QQuaternion *return$) noexcept {
  ::QQuaternion (::QQuaternion::*normalized$)() const = &::QQuaternion::normalized;
  new (return$) ::QQuaternion((self.*normalized$)());
}

void cxxbridge1$194$QQuaternion$rotated_vector(::QQuaternion const &self, ::QVector3D const &vector, ::QVector3D *return$) noexcept {
  ::QVector3D (::QQuaternion::*rotated_vector$)(::QVector3D const &) const = &::QQuaternion::rotatedVector;
  new (return$) ::QVector3D((self.*rotated_vector$)(vector));
}

float cxxbridge1$194$QQuaternion$scalar(::QQuaternion const &self) noexcept {
  float (::QQuaternion::*scalar$)() const = &::QQuaternion::scalar;
  return (self.*scalar$)();
}

void cxxbridge1$194$QQuaternion$set_scalar(::QQuaternion &self, float scalar) noexcept {
  void (::QQuaternion::*set_scalar$)(float) = &::QQuaternion::setScalar;
  (self.*set_scalar$)(scalar);
}

void cxxbridge1$194$QQuaternion$set_vector(::QQuaternion &self, ::QVector3D const &vector) noexcept {
  void (::QQuaternion::*set_vector$)(::QVector3D const &) = &::QQuaternion::setVector;
  (self.*set_vector$)(vector);
}

void cxxbridge1$194$QQuaternion$set_x(::QQuaternion &self, float x) noexcept {
  void (::QQuaternion::*set_x$)(float) = &::QQuaternion::setX;
  (self.*set_x$)(x);
}

void cxxbridge1$194$QQuaternion$set_y(::QQuaternion &self, float y) noexcept {
  void (::QQuaternion::*set_y$)(float) = &::QQuaternion::setY;
  (self.*set_y$)(y);
}

void cxxbridge1$194$QQuaternion$set_z(::QQuaternion &self, float z) noexcept {
  void (::QQuaternion::*set_z$)(float) = &::QQuaternion::setZ;
  (self.*set_z$)(z);
}

void cxxbridge1$194$QQuaternion$to_euler_angles(::QQuaternion const &self, ::QVector3D *return$) noexcept {
  ::QVector3D (::QQuaternion::*to_euler_angles$)() const = &::QQuaternion::toEulerAngles;
  new (return$) ::QVector3D((self.*to_euler_angles$)());
}

void cxxbridge1$194$QQuaternion$to_rotation_matrix(::QQuaternion const &self, ::QMatrix3x3 *return$) noexcept {
  ::QMatrix3x3 (::QQuaternion::*to_rotation_matrix$)() const = &::QQuaternion::toRotationMatrix;
  new (return$) ::QMatrix3x3((self.*to_rotation_matrix$)());
}

void cxxbridge1$194$QQuaternion$to_vector_4d(::QQuaternion const &self, ::QVector4D *return$) noexcept {
  ::QVector4D (::QQuaternion::*to_vector_4d$)() const = &::QQuaternion::toVector4D;
  new (return$) ::QVector4D((self.*to_vector_4d$)());
}

void cxxbridge1$194$QQuaternion$vector(::QQuaternion const &self, ::QVector3D *return$) noexcept {
  ::QVector3D (::QQuaternion::*vector$)() const = &::QQuaternion::vector;
  new (return$) ::QVector3D((self.*vector$)());
}

float cxxbridge1$194$QQuaternion$x(::QQuaternion const &self) noexcept {
  float (::QQuaternion::*x$)() const = &::QQuaternion::x;
  return (self.*x$)();
}

float cxxbridge1$194$QQuaternion$y(::QQuaternion const &self) noexcept {
  float (::QQuaternion::*y$)() const = &::QQuaternion::y;
  return (self.*y$)();
}

float cxxbridge1$194$QQuaternion$z(::QQuaternion const &self) noexcept {
  float (::QQuaternion::*z$)() const = &::QQuaternion::z;
  return (self.*z$)();
}
} // extern "C"

namespace rust {
namespace cxxqtlib1 {
extern "C" {
float rust$cxxqtlib1$cxxbridge1$194$qquaternion_dot_product(::QQuaternion const &q1, ::QQuaternion const &q2) noexcept {
  float (*qquaternion_dot_product$)(::QQuaternion const &, ::QQuaternion const &) = ::rust::cxxqtlib1::qquaternionDotProduct;
  return qquaternion_dot_product$(q1, q2);
}

void rust$cxxqtlib1$cxxbridge1$194$qquaternion_from_axes(::QVector3D const &x_axis, ::QVector3D const &y_axis, ::QVector3D const &z_axis, ::QQuaternion *return$) noexcept {
  ::QQuaternion (*qquaternion_from_axes$)(::QVector3D const &, ::QVector3D const &, ::QVector3D const &) = ::rust::cxxqtlib1::qquaternionFromAxes;
  new (return$) ::QQuaternion(qquaternion_from_axes$(x_axis, y_axis, z_axis));
}

void rust$cxxqtlib1$cxxbridge1$194$qquaternion_from_axis_and_angle(float x, float y, float z, float angle, ::QQuaternion *return$) noexcept {
  ::QQuaternion (*qquaternion_from_axis_and_angle$)(float, float, float, float) = ::rust::cxxqtlib1::qquaternionFromAxisAndAngle;
  new (return$) ::QQuaternion(qquaternion_from_axis_and_angle$(x, y, z, angle));
}

void rust$cxxqtlib1$cxxbridge1$194$qquaternion_from_euler_angles(float pitch, float yaw, float roll, ::QQuaternion *return$) noexcept {
  ::QQuaternion (*qquaternion_from_euler_angles$)(float, float, float) = ::rust::cxxqtlib1::qquaternionFromEulerAngles;
  new (return$) ::QQuaternion(qquaternion_from_euler_angles$(pitch, yaw, roll));
}

void rust$cxxqtlib1$cxxbridge1$194$qquaternion_from_rotation_matrix(::QMatrix3x3 const &rot3x3, ::QQuaternion *return$) noexcept {
  ::QQuaternion (*qquaternion_from_rotation_matrix$)(::QMatrix3x3 const &) = ::rust::cxxqtlib1::qquaternionFromRotationMatrix;
  new (return$) ::QQuaternion(qquaternion_from_rotation_matrix$(rot3x3));
}

void rust$cxxqtlib1$cxxbridge1$194$qquaternion_nlerp(::QQuaternion const &q1, ::QQuaternion const &q2, float t, ::QQuaternion *return$) noexcept {
  ::QQuaternion (*qquaternion_nlerp$)(::QQuaternion const &, ::QQuaternion const &, float) = ::rust::cxxqtlib1::qquaternionNlerp;
  new (return$) ::QQuaternion(qquaternion_nlerp$(q1, q2, t));
}

void rust$cxxqtlib1$cxxbridge1$194$qquaternion_slerp(::QQuaternion const &q1, ::QQuaternion const &q2, float t, ::QQuaternion *return$) noexcept {
  ::QQuaternion (*qquaternion_slerp$)(::QQuaternion const &, ::QQuaternion const &, float) = ::rust::cxxqtlib1::qquaternionSlerp;
  new (return$) ::QQuaternion(qquaternion_slerp$(q1, q2, t));
}

void rust$cxxqtlib1$cxxbridge1$194$qquaternion_rotation_to(::QVector3D const &from, ::QVector3D const &to, ::QQuaternion *return$) noexcept {
  ::QQuaternion (*qquaternion_rotation_to$)(::QVector3D const &, ::QVector3D const &) = ::rust::cxxqtlib1::qquaternionRotationTo;
  new (return$) ::QQuaternion(qquaternion_rotation_to$(from, to));
}

void rust$cxxqtlib1$cxxbridge1$194$qquaternion_init_qvector4d(::QVector4D const &vector, ::QQuaternion *return$) noexcept {
  ::QQuaternion (*qquaternion_init_qvector4d$)(::QVector4D const &) = ::rust::cxxqtlib1::construct;
  new (return$) ::QQuaternion(qquaternion_init_qvector4d$(vector));
}

void rust$cxxqtlib1$cxxbridge1$194$qquaternion_init_float_qvector3d(float scalar, ::QVector3D const &vector, ::QQuaternion *return$) noexcept {
  ::QQuaternion (*qquaternion_init_float_qvector3d$)(float, ::QVector3D const &) = ::rust::cxxqtlib1::construct;
  new (return$) ::QQuaternion(qquaternion_init_float_qvector3d$(scalar, vector));
}

void rust$cxxqtlib1$cxxbridge1$194$qquaternion_init_default(::QQuaternion *return$) noexcept {
  ::QQuaternion (*qquaternion_init_default$)() = ::rust::cxxqtlib1::construct;
  new (return$) ::QQuaternion(qquaternion_init_default$());
}

void rust$cxxqtlib1$cxxbridge1$194$qquaternion_to_debug_qstring(::QQuaternion const &value, ::QString *return$) noexcept {
  ::QString (*qquaternion_to_debug_qstring$)(::QQuaternion const &) = ::rust::cxxqtlib1::toDebugQString;
  new (return$) ::QString(qquaternion_to_debug_qstring$(value));
}

void rust$cxxqtlib1$cxxbridge1$194$qquaternion_plus(::QQuaternion const &a, ::QQuaternion const &b, ::QQuaternion *return$) noexcept {
  ::QQuaternion (*qquaternion_plus$)(::QQuaternion const &, ::QQuaternion const &) = ::rust::cxxqtlib1::operatorPlus;
  new (return$) ::QQuaternion(qquaternion_plus$(a, b));
}

void rust$cxxqtlib1$cxxbridge1$194$qquaternion_minus(::QQuaternion const &a, ::QQuaternion const &b, ::QQuaternion *return$) noexcept {
  ::QQuaternion (*qquaternion_minus$)(::QQuaternion const &, ::QQuaternion const &) = ::rust::cxxqtlib1::operatorMinus;
  new (return$) ::QQuaternion(qquaternion_minus$(a, b));
}

void rust$cxxqtlib1$cxxbridge1$194$qquaternion_mul(float a, ::QQuaternion const &b, ::QQuaternion *return$) noexcept {
  ::QQuaternion (*qquaternion_mul$)(float, ::QQuaternion const &) = ::rust::cxxqtlib1::operatorMul;
  new (return$) ::QQuaternion(qquaternion_mul$(a, b));
}

void rust$cxxqtlib1$cxxbridge1$194$qquaternion_div(float a, ::QQuaternion const &b, ::QQuaternion *return$) noexcept {
  ::QQuaternion (*qquaternion_div$)(float, ::QQuaternion const &) = ::rust::cxxqtlib1::operatorDiv;
  new (return$) ::QQuaternion(qquaternion_div$(a, b));
}

void rust$cxxqtlib1$cxxbridge1$194$qquaternion_neg(::QQuaternion const &a, ::QQuaternion *return$) noexcept {
  ::QQuaternion (*qquaternion_neg$)(::QQuaternion const &) = ::rust::cxxqtlib1::operatorNeg;
  new (return$) ::QQuaternion(qquaternion_neg$(a));
}
} // extern "C"
} // namespace cxxqtlib1
} // namespace rust
