#include "cxx-qt-lib/qt.h"
#include "cxx-qt-lib/qpen.h"
#include "cxx-qt-lib/qcolor.h"
#include "cxx-qt-lib/qstring.h"
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
    ::rust::IsRelocatable<::Qt::PenStyle>::value,
    "type Qt::PenStyle should be trivially move constructible and trivially destructible in C++ to be used as an argument of `set_style` or return value of `style` in Rust");
static_assert(
    ::rust::IsRelocatable<::Qt::PenCapStyle>::value,
    "type Qt::PenCapStyle should be trivially move constructible and trivially destructible in C++ to be used as an argument of `set_cap_style` or return value of `cap_style` in Rust");
static_assert(
    ::rust::IsRelocatable<::Qt::PenJoinStyle>::value,
    "type Qt::PenJoinStyle should be trivially move constructible and trivially destructible in C++ to be used as an argument of `set_join_style` or return value of `join_style` in Rust");
static_assert(
    ::rust::IsRelocatable<::QPen>::value,
    "type QPen should be trivially move constructible and trivially destructible in C++ to be used as a return value of `qpen_init_default`, `qpen_init_from_qcolor`, `qpen_init_from_penstyle` in Rust");
static_assert(
    ::rust::IsRelocatable<::QColor>::value,
    "type QColor should be trivially move constructible and trivially destructible in C++ to be used as a return value of `color` in Rust");
static_assert(
    ::rust::IsRelocatable<::QString>::value,
    "type QString should be trivially move constructible and trivially destructible in C++ to be used as a return value of `qpen_to_debug_qstring` in Rust");

extern "C" {
void cxxbridge1$194$QPen$cap_style(::QPen const &self, ::Qt::PenCapStyle *return$) noexcept {
  ::Qt::PenCapStyle (::QPen::*cap_style$)() const = &::QPen::capStyle;
  new (return$) ::Qt::PenCapStyle((self.*cap_style$)());
}

void cxxbridge1$194$QPen$color(::QPen const &self, ::QColor *return$) noexcept {
  ::QColor (::QPen::*color$)() const = &::QPen::color;
  new (return$) ::QColor((self.*color$)());
}

double cxxbridge1$194$QPen$dash_offset(::QPen const &self) noexcept {
  double (::QPen::*dash_offset$)() const = &::QPen::dashOffset;
  return (self.*dash_offset$)();
}

bool cxxbridge1$194$QPen$is_comestic(::QPen const &self) noexcept {
  bool (::QPen::*is_comestic$)() const = &::QPen::isCosmetic;
  return (self.*is_comestic$)();
}

bool cxxbridge1$194$QPen$is_solid(::QPen const &self) noexcept {
  bool (::QPen::*is_solid$)() const = &::QPen::isSolid;
  return (self.*is_solid$)();
}

void cxxbridge1$194$QPen$join_style(::QPen const &self, ::Qt::PenJoinStyle *return$) noexcept {
  ::Qt::PenJoinStyle (::QPen::*join_style$)() const = &::QPen::joinStyle;
  new (return$) ::Qt::PenJoinStyle((self.*join_style$)());
}

double cxxbridge1$194$QPen$miter_limit(::QPen const &self) noexcept {
  double (::QPen::*miter_limit$)() const = &::QPen::miterLimit;
  return (self.*miter_limit$)();
}

void cxxbridge1$194$QPen$set_cap_style(::QPen &self, ::Qt::PenCapStyle *style) noexcept {
  void (::QPen::*set_cap_style$)(::Qt::PenCapStyle) = &::QPen::setCapStyle;
  (self.*set_cap_style$)(::std::move(*style));
}

void cxxbridge1$194$QPen$set_color(::QPen &self, ::QColor const &color) noexcept {
  void (::QPen::*set_color$)(::QColor const &) = &::QPen::setColor;
  (self.*set_color$)(color);
}

void cxxbridge1$194$QPen$set_cosmetic(::QPen &self, bool cosmetic) noexcept {
  void (::QPen::*set_cosmetic$)(bool) = &::QPen::setCosmetic;
  (self.*set_cosmetic$)(cosmetic);
}

void cxxbridge1$194$QPen$set_dash_offset(::QPen &self, double offset) noexcept {
  void (::QPen::*set_dash_offset$)(double) = &::QPen::setDashOffset;
  (self.*set_dash_offset$)(offset);
}

void cxxbridge1$194$QPen$set_join_style(::QPen &self, ::Qt::PenJoinStyle *style) noexcept {
  void (::QPen::*set_join_style$)(::Qt::PenJoinStyle) = &::QPen::setJoinStyle;
  (self.*set_join_style$)(::std::move(*style));
}

void cxxbridge1$194$QPen$set_style(::QPen &self, ::Qt::PenStyle *style) noexcept {
  void (::QPen::*set_style$)(::Qt::PenStyle) = &::QPen::setStyle;
  (self.*set_style$)(::std::move(*style));
}

void cxxbridge1$194$QPen$set_miter_limit(::QPen &self, double limit) noexcept {
  void (::QPen::*set_miter_limit$)(double) = &::QPen::setMiterLimit;
  (self.*set_miter_limit$)(limit);
}

void cxxbridge1$194$QPen$set_width(::QPen &self, ::std::int32_t width) noexcept {
  void (::QPen::*set_width$)(::std::int32_t) = &::QPen::setWidth;
  (self.*set_width$)(width);
}

void cxxbridge1$194$QPen$style(::QPen const &self, ::Qt::PenStyle *return$) noexcept {
  ::Qt::PenStyle (::QPen::*style$)() const = &::QPen::style;
  new (return$) ::Qt::PenStyle((self.*style$)());
}

::std::int32_t cxxbridge1$194$QPen$width(::QPen const &self) noexcept {
  ::std::int32_t (::QPen::*width$)() const = &::QPen::width;
  return (self.*width$)();
}
} // extern "C"

namespace rust {
namespace cxxqtlib1 {
extern "C" {
void rust$cxxqtlib1$cxxbridge1$194$qpen_init_default(::QPen *return$) noexcept {
  ::QPen (*qpen_init_default$)() = ::rust::cxxqtlib1::construct;
  new (return$) ::QPen(qpen_init_default$());
}

void rust$cxxqtlib1$cxxbridge1$194$qpen_init_from_qcolor(::QColor const &color, ::QPen *return$) noexcept {
  ::QPen (*qpen_init_from_qcolor$)(::QColor const &) = ::rust::cxxqtlib1::construct;
  new (return$) ::QPen(qpen_init_from_qcolor$(color));
}

void rust$cxxqtlib1$cxxbridge1$194$qpen_init_from_penstyle(::Qt::PenStyle const &penstyle, ::QPen *return$) noexcept {
  ::QPen (*qpen_init_from_penstyle$)(::Qt::PenStyle const &) = ::rust::cxxqtlib1::construct;
  new (return$) ::QPen(qpen_init_from_penstyle$(penstyle));
}

void rust$cxxqtlib1$cxxbridge1$194$qpen_drop(::QPen &pen) noexcept {
  void (*qpen_drop$)(::QPen &) = ::rust::cxxqtlib1::drop;
  qpen_drop$(pen);
}

void rust$cxxqtlib1$cxxbridge1$194$qpen_clone(::QPen const &pen, ::QPen *return$) noexcept {
  ::QPen (*qpen_clone$)(::QPen const &) = ::rust::cxxqtlib1::construct;
  new (return$) ::QPen(qpen_clone$(pen));
}

bool rust$cxxqtlib1$cxxbridge1$194$qpen_eq(::QPen const &a, ::QPen const &b) noexcept {
  bool (*qpen_eq$)(::QPen const &, ::QPen const &) = ::rust::cxxqtlib1::operatorEq;
  return qpen_eq$(a, b);
}

void rust$cxxqtlib1$cxxbridge1$194$qpen_to_debug_qstring(::QPen const &value, ::QString *return$) noexcept {
  ::QString (*qpen_to_debug_qstring$)(::QPen const &) = ::rust::cxxqtlib1::toDebugQString;
  new (return$) ::QString(qpen_to_debug_qstring$(value));
}
} // extern "C"
} // namespace cxxqtlib1
} // namespace rust
