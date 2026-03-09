#include "cxx-qt-lib/qlinef.h"
#include "cxx-qt-lib/qline.h"
#include "cxx-qt-lib/qpointf.h"
#include "cxx-qt-lib/qstring.h"
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
    ::rust::IsRelocatable<::QLineF>::value,
    "type QLineF should be trivially move constructible and trivially destructible in C++ to be used as a return value of `normal_vector`, `translated`, `unit_vector` in Rust");
static_assert(
    ::rust::IsRelocatable<::QLine>::value,
    "type QLine should be trivially move constructible and trivially destructible in C++ to be used as a return value of `to_line` in Rust");
static_assert(
    ::rust::IsRelocatable<::QPointF>::value,
    "type QPointF should be trivially move constructible and trivially destructible in C++ to be used as an argument of `qlinef_new` or return value of `p1`, `p2`, `center` in Rust");
static_assert(
    ::rust::IsRelocatable<::QString>::value,
    "type QString should be trivially move constructible and trivially destructible in C++ to be used as a return value of `qlinef_to_debug_qstring` in Rust");

extern "C" {
double cxxbridge1$194$QLineF$angle(::QLineF const &self) noexcept {
  double (::QLineF::*angle$)() const = &::QLineF::angle;
  return (self.*angle$)();
}

double cxxbridge1$194$QLineF$angle_to(::QLineF const &self, ::QLineF const &line) noexcept {
  double (::QLineF::*angle_to$)(::QLineF const &) const = &::QLineF::angleTo;
  return (self.*angle_to$)(line);
}

void cxxbridge1$194$QLineF$p1(::QLineF const &self, ::QPointF *return$) noexcept {
  ::QPointF (::QLineF::*p1$)() const = &::QLineF::p1;
  new (return$) ::QPointF((self.*p1$)());
}

void cxxbridge1$194$QLineF$p2(::QLineF const &self, ::QPointF *return$) noexcept {
  ::QPointF (::QLineF::*p2$)() const = &::QLineF::p2;
  new (return$) ::QPointF((self.*p2$)());
}

double cxxbridge1$194$QLineF$x1(::QLineF const &self) noexcept {
  double (::QLineF::*x1$)() const = &::QLineF::x1;
  return (self.*x1$)();
}

double cxxbridge1$194$QLineF$x2(::QLineF const &self) noexcept {
  double (::QLineF::*x2$)() const = &::QLineF::x2;
  return (self.*x2$)();
}

double cxxbridge1$194$QLineF$y1(::QLineF const &self) noexcept {
  double (::QLineF::*y1$)() const = &::QLineF::y1;
  return (self.*y1$)();
}

double cxxbridge1$194$QLineF$y2(::QLineF const &self) noexcept {
  double (::QLineF::*y2$)() const = &::QLineF::y2;
  return (self.*y2$)();
}

void cxxbridge1$194$QLineF$center(::QLineF const &self, ::QPointF *return$) noexcept {
  ::QPointF (::QLineF::*center$)() const = &::QLineF::center;
  new (return$) ::QPointF((self.*center$)());
}

double cxxbridge1$194$QLineF$dx(::QLineF const &self) noexcept {
  double (::QLineF::*dx$)() const = &::QLineF::dx;
  return (self.*dx$)();
}

double cxxbridge1$194$QLineF$dy(::QLineF const &self) noexcept {
  double (::QLineF::*dy$)() const = &::QLineF::dy;
  return (self.*dy$)();
}

bool cxxbridge1$194$QLineF$is_null(::QLineF const &self) noexcept {
  bool (::QLineF::*is_null$)() const = &::QLineF::isNull;
  return (self.*is_null$)();
}

double cxxbridge1$194$QLineF$length(::QLineF const &self) noexcept {
  double (::QLineF::*length$)() const = &::QLineF::length;
  return (self.*length$)();
}

void cxxbridge1$194$QLineF$normal_vector(::QLineF const &self, ::QLineF *return$) noexcept {
  ::QLineF (::QLineF::*normal_vector$)() const = &::QLineF::normalVector;
  new (return$) ::QLineF((self.*normal_vector$)());
}

void cxxbridge1$194$QLineF$point_at(::QLineF const &self, double t, ::QPointF *return$) noexcept {
  ::QPointF (::QLineF::*point_at$)(double) const = &::QLineF::pointAt;
  new (return$) ::QPointF((self.*point_at$)(t));
}

void cxxbridge1$194$QLineF$set_angle(::QLineF &self, double angle) noexcept {
  void (::QLineF::*set_angle$)(double) = &::QLineF::setAngle;
  (self.*set_angle$)(angle);
}

void cxxbridge1$194$QLineF$set_length(::QLineF &self, double length) noexcept {
  void (::QLineF::*set_length$)(double) = &::QLineF::setLength;
  (self.*set_length$)(length);
}

void cxxbridge1$194$QLineF$set_p1(::QLineF &self, ::QPointF const &p1) noexcept {
  void (::QLineF::*set_p1$)(::QPointF const &) = &::QLineF::setP1;
  (self.*set_p1$)(p1);
}

void cxxbridge1$194$QLineF$set_p2(::QLineF &self, ::QPointF const &p1) noexcept {
  void (::QLineF::*set_p2$)(::QPointF const &) = &::QLineF::setP2;
  (self.*set_p2$)(p1);
}

void cxxbridge1$194$QLineF$set_line(::QLineF &self, double x1, double y1, double x2, double y2) noexcept {
  void (::QLineF::*set_line$)(double, double, double, double) = &::QLineF::setLine;
  (self.*set_line$)(x1, y1, x2, y2);
}

void cxxbridge1$194$QLineF$set_points(::QLineF &self, ::QPointF const &p1, ::QPointF const &p2) noexcept {
  void (::QLineF::*set_points$)(::QPointF const &, ::QPointF const &) = &::QLineF::setPoints;
  (self.*set_points$)(p1, p2);
}

void cxxbridge1$194$QLineF$to_line(::QLineF const &self, ::QLine *return$) noexcept {
  ::QLine (::QLineF::*to_line$)() const = &::QLineF::toLine;
  new (return$) ::QLine((self.*to_line$)());
}

void cxxbridge1$194$QLineF$translate(::QLineF &self, ::QPointF const &offset) noexcept {
  void (::QLineF::*translate$)(::QPointF const &) = &::QLineF::translate;
  (self.*translate$)(offset);
}

void cxxbridge1$194$QLineF$translated(::QLineF const &self, ::QPointF const &offset, ::QLineF *return$) noexcept {
  ::QLineF (::QLineF::*translated$)(::QPointF const &) const = &::QLineF::translated;
  new (return$) ::QLineF((self.*translated$)(offset));
}

void cxxbridge1$194$QLineF$unit_vector(::QLineF const &self, ::QLineF *return$) noexcept {
  ::QLineF (::QLineF::*unit_vector$)() const = &::QLineF::unitVector;
  new (return$) ::QLineF((self.*unit_vector$)());
}
} // extern "C"

namespace rust {
namespace cxxqtlib1 {
extern "C" {
void rust$cxxqtlib1$cxxbridge1$194$qlinef_default(::QLineF *return$) noexcept {
  ::QLineF (*qlinef_default$)() = ::rust::cxxqtlib1::construct;
  new (return$) ::QLineF(qlinef_default$());
}

void rust$cxxqtlib1$cxxbridge1$194$qlinef_new(::QPointF *pt1, ::QPointF *pt2, ::QLineF *return$) noexcept {
  ::QLineF (*qlinef_new$)(::QPointF, ::QPointF) = ::rust::cxxqtlib1::construct;
  new (return$) ::QLineF(qlinef_new$(::std::move(*pt1), ::std::move(*pt2)));
}

void rust$cxxqtlib1$cxxbridge1$194$qlinef_from_qline(::QLine const &line, ::QLineF *return$) noexcept {
  ::QLineF (*qlinef_from_qline$)(::QLine const &) = ::rust::cxxqtlib1::construct;
  new (return$) ::QLineF(qlinef_from_qline$(line));
}

void rust$cxxqtlib1$cxxbridge1$194$qlinef_to_debug_qstring(::QLineF const &value, ::QString *return$) noexcept {
  ::QString (*qlinef_to_debug_qstring$)(::QLineF const &) = ::rust::cxxqtlib1::toDebugQString;
  new (return$) ::QString(qlinef_to_debug_qstring$(value));
}
} // extern "C"
} // namespace cxxqtlib1
} // namespace rust
