#include "cxx-qt-lib/qline.h"
#include "cxx-qt-lib/qpoint.h"
#include "cxx-qt-lib/qstring.h"
#include "cxx-qt-lib/qlinef.h"
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
    ::rust::IsRelocatable<::QLine>::value,
    "type QLine should be trivially move constructible and trivially destructible in C++ to be used as a return value of `translated`, `qline_default`, `qline_new` in Rust");
static_assert(
    ::rust::IsRelocatable<::QPoint>::value,
    "type QPoint should be trivially move constructible and trivially destructible in C++ to be used as an argument of `qline_new` or return value of `p1`, `p2`, `center` in Rust");
static_assert(
    ::rust::IsRelocatable<::QString>::value,
    "type QString should be trivially move constructible and trivially destructible in C++ to be used as a return value of `qline_to_debug_qstring` in Rust");
static_assert(
    ::rust::IsRelocatable<::QLineF>::value,
    "type QLineF should be trivially move constructible and trivially destructible in C++ to be used as a return value of `to_linef` in Rust");

extern "C" {
void cxxbridge1$194$QLine$p1(::QLine const &self, ::QPoint *return$) noexcept {
  ::QPoint (::QLine::*p1$)() const = &::QLine::p1;
  new (return$) ::QPoint((self.*p1$)());
}

void cxxbridge1$194$QLine$p2(::QLine const &self, ::QPoint *return$) noexcept {
  ::QPoint (::QLine::*p2$)() const = &::QLine::p2;
  new (return$) ::QPoint((self.*p2$)());
}

::std::int32_t cxxbridge1$194$QLine$x1(::QLine const &self) noexcept {
  ::std::int32_t (::QLine::*x1$)() const = &::QLine::x1;
  return (self.*x1$)();
}

::std::int32_t cxxbridge1$194$QLine$x2(::QLine const &self) noexcept {
  ::std::int32_t (::QLine::*x2$)() const = &::QLine::x2;
  return (self.*x2$)();
}

::std::int32_t cxxbridge1$194$QLine$y1(::QLine const &self) noexcept {
  ::std::int32_t (::QLine::*y1$)() const = &::QLine::y1;
  return (self.*y1$)();
}

::std::int32_t cxxbridge1$194$QLine$y2(::QLine const &self) noexcept {
  ::std::int32_t (::QLine::*y2$)() const = &::QLine::y2;
  return (self.*y2$)();
}

void cxxbridge1$194$QLine$center(::QLine const &self, ::QPoint *return$) noexcept {
  ::QPoint (::QLine::*center$)() const = &::QLine::center;
  new (return$) ::QPoint((self.*center$)());
}

::std::int32_t cxxbridge1$194$QLine$dx(::QLine const &self) noexcept {
  ::std::int32_t (::QLine::*dx$)() const = &::QLine::dx;
  return (self.*dx$)();
}

::std::int32_t cxxbridge1$194$QLine$dy(::QLine const &self) noexcept {
  ::std::int32_t (::QLine::*dy$)() const = &::QLine::dy;
  return (self.*dy$)();
}

bool cxxbridge1$194$QLine$is_null(::QLine const &self) noexcept {
  bool (::QLine::*is_null$)() const = &::QLine::isNull;
  return (self.*is_null$)();
}

void cxxbridge1$194$QLine$set_p1(::QLine &self, ::QPoint const &p1) noexcept {
  void (::QLine::*set_p1$)(::QPoint const &) = &::QLine::setP1;
  (self.*set_p1$)(p1);
}

void cxxbridge1$194$QLine$set_p2(::QLine &self, ::QPoint const &p1) noexcept {
  void (::QLine::*set_p2$)(::QPoint const &) = &::QLine::setP2;
  (self.*set_p2$)(p1);
}

void cxxbridge1$194$QLine$set_line(::QLine &self, ::std::int32_t x1, ::std::int32_t y1, ::std::int32_t x2, ::std::int32_t y2) noexcept {
  void (::QLine::*set_line$)(::std::int32_t, ::std::int32_t, ::std::int32_t, ::std::int32_t) = &::QLine::setLine;
  (self.*set_line$)(x1, y1, x2, y2);
}

void cxxbridge1$194$QLine$set_points(::QLine &self, ::QPoint const &p1, ::QPoint const &p2) noexcept {
  void (::QLine::*set_points$)(::QPoint const &, ::QPoint const &) = &::QLine::setPoints;
  (self.*set_points$)(p1, p2);
}

void cxxbridge1$194$QLine$to_linef(::QLine const &self, ::QLineF *return$) noexcept {
  ::QLineF (::QLine::*to_linef$)() const = &::QLine::toLineF;
  new (return$) ::QLineF((self.*to_linef$)());
}

void cxxbridge1$194$QLine$translate(::QLine &self, ::QPoint const &offset) noexcept {
  void (::QLine::*translate$)(::QPoint const &) = &::QLine::translate;
  (self.*translate$)(offset);
}

void cxxbridge1$194$QLine$translated(::QLine const &self, ::QPoint const &offset, ::QLine *return$) noexcept {
  ::QLine (::QLine::*translated$)(::QPoint const &) const = &::QLine::translated;
  new (return$) ::QLine((self.*translated$)(offset));
}
} // extern "C"

namespace rust {
namespace cxxqtlib1 {
extern "C" {
void rust$cxxqtlib1$cxxbridge1$194$qline_default(::QLine *return$) noexcept {
  ::QLine (*qline_default$)() = ::rust::cxxqtlib1::construct;
  new (return$) ::QLine(qline_default$());
}

void rust$cxxqtlib1$cxxbridge1$194$qline_new(::QPoint *pt1, ::QPoint *pt2, ::QLine *return$) noexcept {
  ::QLine (*qline_new$)(::QPoint, ::QPoint) = ::rust::cxxqtlib1::construct;
  new (return$) ::QLine(qline_new$(::std::move(*pt1), ::std::move(*pt2)));
}

void rust$cxxqtlib1$cxxbridge1$194$qline_to_debug_qstring(::QLine const &value, ::QString *return$) noexcept {
  ::QString (*qline_to_debug_qstring$)(::QLine const &) = ::rust::cxxqtlib1::toDebugQString;
  new (return$) ::QString(qline_to_debug_qstring$(value));
}
} // extern "C"
} // namespace cxxqtlib1
} // namespace rust
