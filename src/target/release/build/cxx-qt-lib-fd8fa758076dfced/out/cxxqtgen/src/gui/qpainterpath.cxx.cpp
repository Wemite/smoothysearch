#include "cxx-qt-lib/qt.h"
#include "cxx-qt-lib/qpainterpath.h"
#include "cxx-qt-lib/qrectf.h"
#include "cxx-qt-lib/qpointf.h"
#include "cxx-qt-lib/qfont.h"
#include "cxx-qt-lib/qstring.h"
#include "cxx-qt-lib/qpolygonf.h"
#include "cxx-qt-lib/qregion.h"
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
    ::rust::IsRelocatable<::Qt::FillRule>::value,
    "type Qt::FillRule should be trivially move constructible and trivially destructible in C++ to be used as an argument of `set_fill_rule` or return value of `fill_rule` in Rust");
static_assert(
    ::rust::IsRelocatable<::Qt::SizeMode>::value,
    "type Qt::SizeMode should be trivially move constructible and trivially destructible in C++ to be used as an argument of `add_rounded_rect` in Rust");
static_assert(
    ::rust::IsRelocatable<::QPainterPath>::value,
    "type QPainterPath should be trivially move constructible and trivially destructible in C++ to be used as a return value of `intersected`, `simplified`, `subtracted` in Rust");
static_assert(
    ::rust::IsRelocatable<::QRectF>::value,
    "type QRectF should be trivially move constructible and trivially destructible in C++ to be used as a return value of `bounding_rect`, `control_point_rect` in Rust");
static_assert(
    ::rust::IsRelocatable<::QPointF>::value,
    "type QPointF should be trivially move constructible and trivially destructible in C++ to be used as a return value of `current_position` in Rust");
static_assert(
    ::rust::IsRelocatable<::QString>::value,
    "type QString should be trivially move constructible and trivially destructible in C++ to be used as a return value of `qpainterpath_to_debug_qstring` in Rust");

extern "C" {
void cxxbridge1$194$QPainterPath$add_ellipse(::QPainterPath &self, ::QRectF const &bounding_rectangle) noexcept {
  void (::QPainterPath::*add_ellipse$)(::QRectF const &) = &::QPainterPath::addEllipse;
  (self.*add_ellipse$)(bounding_rectangle);
}

void cxxbridge1$194$QPainterPath$add_path(::QPainterPath &self, ::QPainterPath const &path) noexcept {
  void (::QPainterPath::*add_path$)(::QPainterPath const &) = &::QPainterPath::addPath;
  (self.*add_path$)(path);
}

void cxxbridge1$194$QPainterPath$add_polygon(::QPainterPath &self, ::QPolygonF const &polygon) noexcept {
  void (::QPainterPath::*add_polygon$)(::QPolygonF const &) = &::QPainterPath::addPolygon;
  (self.*add_polygon$)(polygon);
}

void cxxbridge1$194$QPainterPath$add_rect(::QPainterPath &self, ::QRectF const &rectangle) noexcept {
  void (::QPainterPath::*add_rect$)(::QRectF const &) = &::QPainterPath::addRect;
  (self.*add_rect$)(rectangle);
}

void cxxbridge1$194$QPainterPath$add_region(::QPainterPath &self, ::QRegion const &region) noexcept {
  void (::QPainterPath::*add_region$)(::QRegion const &) = &::QPainterPath::addRegion;
  (self.*add_region$)(region);
}

void cxxbridge1$194$QPainterPath$add_rounded_rect(::QPainterPath &self, ::QRectF const &rect, double x_radius, double y_radius, ::Qt::SizeMode *mode) noexcept {
  void (::QPainterPath::*add_rounded_rect$)(::QRectF const &, double, double, ::Qt::SizeMode) = &::QPainterPath::addRoundedRect;
  (self.*add_rounded_rect$)(rect, x_radius, y_radius, ::std::move(*mode));
}

void cxxbridge1$194$QPainterPath$arc_move_to(::QPainterPath &self, ::QRectF const &rectangle, double angle) noexcept {
  void (::QPainterPath::*arc_move_to$)(::QRectF const &, double) = &::QPainterPath::arcMoveTo;
  (self.*arc_move_to$)(rectangle, angle);
}

void cxxbridge1$194$QPainterPath$add_text(::QPainterPath &self, ::QPointF const &point, ::QFont const &font, ::QString const &text) noexcept {
  void (::QPainterPath::*add_text$)(::QPointF const &, ::QFont const &, ::QString const &) = &::QPainterPath::addText;
  (self.*add_text$)(point, font, text);
}

void cxxbridge1$194$QPainterPath$arc_to(::QPainterPath &self, ::QRectF const &rectangle, double start_angle, double sweep_length) noexcept {
  void (::QPainterPath::*arc_to$)(::QRectF const &, double, double) = &::QPainterPath::arcTo;
  (self.*arc_to$)(rectangle, start_angle, sweep_length);
}

void cxxbridge1$194$QPainterPath$bounding_rect(::QPainterPath const &self, ::QRectF *return$) noexcept {
  ::QRectF (::QPainterPath::*bounding_rect$)() const = &::QPainterPath::boundingRect;
  new (return$) ::QRectF((self.*bounding_rect$)());
}

::std::int32_t cxxbridge1$194$QPainterPath$capacity(::QPainterPath const &self) noexcept {
  ::std::int32_t (::QPainterPath::*capacity$)() const = &::QPainterPath::capacity;
  return (self.*capacity$)();
}

void cxxbridge1$194$QPainterPath$clear(::QPainterPath &self) noexcept {
  void (::QPainterPath::*clear$)() = &::QPainterPath::clear;
  (self.*clear$)();
}

void cxxbridge1$194$QPainterPath$close_subpath(::QPainterPath &self) noexcept {
  void (::QPainterPath::*close_subpath$)() = &::QPainterPath::closeSubpath;
  (self.*close_subpath$)();
}

void cxxbridge1$194$QPainterPath$connect_path(::QPainterPath &self, ::QPainterPath const &path) noexcept {
  void (::QPainterPath::*connect_path$)(::QPainterPath const &) = &::QPainterPath::connectPath;
  (self.*connect_path$)(path);
}

bool cxxbridge1$194$QPainterPath$contains(::QPainterPath const &self, ::QPointF const &point) noexcept {
  bool (::QPainterPath::*contains$)(::QPointF const &) const = &::QPainterPath::contains;
  return (self.*contains$)(point);
}

void cxxbridge1$194$QPainterPath$control_point_rect(::QPainterPath const &self, ::QRectF *return$) noexcept {
  ::QRectF (::QPainterPath::*control_point_rect$)() const = &::QPainterPath::controlPointRect;
  new (return$) ::QRectF((self.*control_point_rect$)());
}

void cxxbridge1$194$QPainterPath$cubic_to(::QPainterPath &self, ::QPointF const &c1, ::QPointF const &c2, ::QPointF const &end_point) noexcept {
  void (::QPainterPath::*cubic_to$)(::QPointF const &, ::QPointF const &, ::QPointF const &) = &::QPainterPath::cubicTo;
  (self.*cubic_to$)(c1, c2, end_point);
}

void cxxbridge1$194$QPainterPath$current_position(::QPainterPath const &self, ::QPointF *return$) noexcept {
  ::QPointF (::QPainterPath::*current_position$)() const = &::QPainterPath::currentPosition;
  new (return$) ::QPointF((self.*current_position$)());
}

::std::int32_t cxxbridge1$194$QPainterPath$element_count(::QPainterPath const &self) noexcept {
  ::std::int32_t (::QPainterPath::*element_count$)() const = &::QPainterPath::elementCount;
  return (self.*element_count$)();
}

void cxxbridge1$194$QPainterPath$fill_rule(::QPainterPath const &self, ::Qt::FillRule *return$) noexcept {
  ::Qt::FillRule (::QPainterPath::*fill_rule$)() const = &::QPainterPath::fillRule;
  new (return$) ::Qt::FillRule((self.*fill_rule$)());
}

void cxxbridge1$194$QPainterPath$intersected(::QPainterPath const &self, ::QPainterPath const &p, ::QPainterPath *return$) noexcept {
  ::QPainterPath (::QPainterPath::*intersected$)(::QPainterPath const &) const = &::QPainterPath::intersected;
  new (return$) ::QPainterPath((self.*intersected$)(p));
}

bool cxxbridge1$194$QPainterPath$intersects(::QPainterPath const &self, ::QPainterPath const &p) noexcept {
  bool (::QPainterPath::*intersects$)(::QPainterPath const &) const = &::QPainterPath::intersects;
  return (self.*intersects$)(p);
}

bool cxxbridge1$194$QPainterPath$is_empty(::QPainterPath const &self) noexcept {
  bool (::QPainterPath::*is_empty$)() const = &::QPainterPath::isEmpty;
  return (self.*is_empty$)();
}

double cxxbridge1$194$QPainterPath$length(::QPainterPath const &self) noexcept {
  double (::QPainterPath::*length$)() const = &::QPainterPath::length;
  return (self.*length$)();
}

void cxxbridge1$194$QPainterPath$line_to(::QPainterPath &self, ::QPointF const &end_point) noexcept {
  void (::QPainterPath::*line_to$)(::QPointF const &) = &::QPainterPath::lineTo;
  (self.*line_to$)(end_point);
}

void cxxbridge1$194$QPainterPath$quad_to(::QPainterPath &self, ::QPointF const &c, ::QPointF const &endPoint) noexcept {
  void (::QPainterPath::*quad_to$)(::QPointF const &, ::QPointF const &) = &::QPainterPath::quadTo;
  (self.*quad_to$)(c, endPoint);
}

void cxxbridge1$194$QPainterPath$reserve(::QPainterPath &self, ::std::int32_t size) noexcept {
  void (::QPainterPath::*reserve$)(::std::int32_t) = &::QPainterPath::reserve;
  (self.*reserve$)(size);
}

void cxxbridge1$194$QPainterPath$set_fill_rule(::QPainterPath &self, ::Qt::FillRule *fill_rule) noexcept {
  void (::QPainterPath::*set_fill_rule$)(::Qt::FillRule) = &::QPainterPath::setFillRule;
  (self.*set_fill_rule$)(::std::move(*fill_rule));
}

void cxxbridge1$194$QPainterPath$simplified(::QPainterPath const &self, ::QPainterPath *return$) noexcept {
  ::QPainterPath (::QPainterPath::*simplified$)() const = &::QPainterPath::simplified;
  new (return$) ::QPainterPath((self.*simplified$)());
}

void cxxbridge1$194$QPainterPath$subtracted(::QPainterPath const &self, ::QPainterPath const &painterpath, ::QPainterPath *return$) noexcept {
  ::QPainterPath (::QPainterPath::*subtracted$)(::QPainterPath const &) const = &::QPainterPath::subtracted;
  new (return$) ::QPainterPath((self.*subtracted$)(painterpath));
}

void cxxbridge1$194$QPainterPath$translate(::QPainterPath &self, double dx, double dy) noexcept {
  void (::QPainterPath::*translate$)(double, double) = &::QPainterPath::translate;
  (self.*translate$)(dx, dy);
}

void cxxbridge1$194$QPainterPath$translated(::QPainterPath const &self, ::QPointF const &offset, ::QPainterPath *return$) noexcept {
  ::QPainterPath (::QPainterPath::*translated$)(::QPointF const &) const = &::QPainterPath::translated;
  new (return$) ::QPainterPath((self.*translated$)(offset));
}

void cxxbridge1$194$QPainterPath$to_reversed(::QPainterPath const &self, ::QPainterPath *return$) noexcept {
  ::QPainterPath (::QPainterPath::*to_reversed$)() const = &::QPainterPath::toReversed;
  new (return$) ::QPainterPath((self.*to_reversed$)());
}

void cxxbridge1$194$QPainterPath$united(::QPainterPath const &self, ::QPainterPath const &p, ::QPainterPath *return$) noexcept {
  ::QPainterPath (::QPainterPath::*united$)(::QPainterPath const &) const = &::QPainterPath::united;
  new (return$) ::QPainterPath((self.*united$)(p));
}
} // extern "C"

namespace rust {
namespace cxxqtlib1 {
extern "C" {
void rust$cxxqtlib1$cxxbridge1$194$qpainterpath_init_default(::QPainterPath *return$) noexcept {
  ::QPainterPath (*qpainterpath_init_default$)() = ::rust::cxxqtlib1::construct;
  new (return$) ::QPainterPath(qpainterpath_init_default$());
}

void rust$cxxqtlib1$cxxbridge1$194$qpainterpath_clone(::QPainterPath const &path, ::QPainterPath *return$) noexcept {
  ::QPainterPath (*qpainterpath_clone$)(::QPainterPath const &) = ::rust::cxxqtlib1::construct;
  new (return$) ::QPainterPath(qpainterpath_clone$(path));
}

void rust$cxxqtlib1$cxxbridge1$194$qpainterpath_from_qpointf(::QPointF const &point, ::QPainterPath *return$) noexcept {
  ::QPainterPath (*qpainterpath_from_qpointf$)(::QPointF const &) = ::rust::cxxqtlib1::construct;
  new (return$) ::QPainterPath(qpainterpath_from_qpointf$(point));
}

void rust$cxxqtlib1$cxxbridge1$194$qpainterpath_drop(::QPainterPath &painterPath) noexcept {
  void (*qpainterpath_drop$)(::QPainterPath &) = ::rust::cxxqtlib1::drop;
  qpainterpath_drop$(painterPath);
}

bool rust$cxxqtlib1$cxxbridge1$194$qpainterpath_eq(::QPainterPath const &a, ::QPainterPath const &b) noexcept {
  bool (*qpainterpath_eq$)(::QPainterPath const &, ::QPainterPath const &) = ::rust::cxxqtlib1::operatorEq;
  return qpainterpath_eq$(a, b);
}

void rust$cxxqtlib1$cxxbridge1$194$qpainterpath_to_debug_qstring(::QPainterPath const &value, ::QString *return$) noexcept {
  ::QString (*qpainterpath_to_debug_qstring$)(::QPainterPath const &) = ::rust::cxxqtlib1::toDebugQString;
  new (return$) ::QString(qpainterpath_to_debug_qstring$(value));
}
} // extern "C"
} // namespace cxxqtlib1
} // namespace rust
