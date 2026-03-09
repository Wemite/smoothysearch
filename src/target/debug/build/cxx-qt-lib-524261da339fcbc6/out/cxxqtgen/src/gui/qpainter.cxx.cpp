#include "cxx-qt-lib/qt.h"
#include "cxx-qt-lib/qpainter.h"
#include "cxx-qt-lib/qrect.h"
#include "cxx-qt-lib/qrectf.h"
#include "cxx-qt-lib/qpoint.h"
#include "cxx-qt-lib/qline.h"
#include "cxx-qt-lib/qlinef.h"
#include "cxx-qt-lib/qcolor.h"
#include "cxx-qt-lib/qimage.h"
#include "cxx-qt-lib/qstring.h"
#include "cxx-qt-lib/qpainterpath.h"
#include "cxx-qt-lib/qfont.h"
#include "cxx-qt-lib/qpen.h"
#include "cxx-qt-lib/qpolygon.h"
#include "cxx-qt-lib/qregion.h"
#include "cxx-qt-lib/core/qvector/qvector_QLine.h"
#include "cxx-qt-lib/core/qvector/qvector_QLineF.h"
#include "cxx-qt-lib/common.h"
#include <cstddef>
#include <cstdint>
#include <memory>
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

#ifndef CXXBRIDGE1_IS_COMPLETE
#define CXXBRIDGE1_IS_COMPLETE
namespace detail {
namespace {
template <typename T, typename = std::size_t>
struct is_complete : std::false_type {};
template <typename T>
struct is_complete<T, decltype(sizeof(T))> : std::true_type {};
} // namespace
} // namespace detail
#endif // CXXBRIDGE1_IS_COMPLETE

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

namespace {
template <bool> struct deleter_if {
  template <typename T> void operator()(T *) {}
};
template <> struct deleter_if<true> {
  template <typename T> void operator()(T *ptr) { ptr->~T(); }
};
} // namespace
} // namespace cxxbridge1
} // namespace rust

using QPainter = ::QPainter;
namespace rust {
  namespace cxxqtlib1 {
    using QPainterCompositionMode = ::rust::cxxqtlib1::QPainterCompositionMode;
    using QPainterRenderHint = ::rust::cxxqtlib1::QPainterRenderHint;
  }
}

namespace rust {
namespace cxxqtlib1 {
static_assert(::std::is_enum<QPainterCompositionMode>::value, "expected enum");
static_assert(sizeof(QPainterCompositionMode) == sizeof(::std::int32_t), "incorrect size");
static_assert(static_cast<::std::int32_t>(QPainterCompositionMode::CompositionMode_SourceOver) == 0, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QPainterCompositionMode::CompositionMode_DestinationOver) == 1, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QPainterCompositionMode::CompositionMode_Clear) == 2, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QPainterCompositionMode::CompositionMode_Source) == 3, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QPainterCompositionMode::CompositionMode_Destination) == 4, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QPainterCompositionMode::CompositionMode_SourceIn) == 5, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QPainterCompositionMode::CompositionMode_DestinationIn) == 6, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QPainterCompositionMode::CompositionMode_SourceOut) == 7, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QPainterCompositionMode::CompositionMode_DestinationOut) == 8, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QPainterCompositionMode::CompositionMode_SourceAtop) == 9, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QPainterCompositionMode::CompositionMode_DestinationAtop) == 10, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QPainterCompositionMode::CompositionMode_Xor) == 11, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QPainterCompositionMode::CompositionMode_Plus) == 12, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QPainterCompositionMode::CompositionMode_Multiply) == 13, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QPainterCompositionMode::CompositionMode_Screen) == 14, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QPainterCompositionMode::CompositionMode_Overlay) == 15, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QPainterCompositionMode::CompositionMode_Darken) == 16, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QPainterCompositionMode::CompositionMode_Lighten) == 17, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QPainterCompositionMode::CompositionMode_ColorDodge) == 18, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QPainterCompositionMode::CompositionMode_ColorBurn) == 19, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QPainterCompositionMode::CompositionMode_HardLight) == 20, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QPainterCompositionMode::CompositionMode_SoftLight) == 21, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QPainterCompositionMode::CompositionMode_Difference) == 22, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QPainterCompositionMode::CompositionMode_Exclusion) == 23, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QPainterCompositionMode::RasterOp_SourceOrDestination) == 24, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QPainterCompositionMode::RasterOp_SourceAndDestination) == 25, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QPainterCompositionMode::RasterOp_SourceXorDestination) == 26, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QPainterCompositionMode::RasterOp_NotSourceAndNotDestination) == 27, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QPainterCompositionMode::RasterOp_NotSourceOrNotDestination) == 28, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QPainterCompositionMode::RasterOp_NotSourceXorDestination) == 29, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QPainterCompositionMode::RasterOp_NotSource) == 30, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QPainterCompositionMode::RasterOp_NotSourceAndDestination) == 31, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QPainterCompositionMode::RasterOp_SourceAndNotDestination) == 32, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QPainterCompositionMode::RasterOp_NotSourceOrDestination) == 33, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QPainterCompositionMode::RasterOp_SourceOrNotDestination) == 34, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QPainterCompositionMode::RasterOp_ClearDestination) == 35, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QPainterCompositionMode::RasterOp_SetDestination) == 36, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QPainterCompositionMode::RasterOp_NotDestination) == 37, "disagrees with the value in #[cxx::bridge]");

static_assert(::std::is_enum<QPainterRenderHint>::value, "expected enum");
static_assert(sizeof(QPainterRenderHint) == sizeof(::std::int32_t), "incorrect size");
static_assert(static_cast<::std::int32_t>(QPainterRenderHint::Antialiasing) == 1, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QPainterRenderHint::TextAntialiasing) == 2, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QPainterRenderHint::SmoothPixmapTransform) == 4, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QPainterRenderHint::LosslessImageRendering) == 64, "disagrees with the value in #[cxx::bridge]");
} // namespace cxxqtlib1
} // namespace rust

static_assert(
    ::rust::IsRelocatable<::Qt::LayoutDirection>::value,
    "type Qt::LayoutDirection should be trivially move constructible and trivially destructible in C++ to be used as an argument of `set_layout_direction` or return value of `layout_direction` in Rust");
static_assert(
    ::rust::IsRelocatable<::Qt::BGMode>::value,
    "type Qt::BGMode should be trivially move constructible and trivially destructible in C++ to be used as an argument of `set_background_mode` or return value of `background_mode` in Rust");
static_assert(
    ::rust::IsRelocatable<::Qt::ClipOperation>::value,
    "type Qt::ClipOperation should be trivially move constructible and trivially destructible in C++ to be used as an argument of `set_clip_path`, `set_clip_rect`, `set_clip_region` in Rust");
static_assert(
    ::rust::IsRelocatable<::Qt::FillRule>::value,
    "type Qt::FillRule should be trivially move constructible and trivially destructible in C++ to be used as an argument of `draw_polygon` in Rust");
static_assert(
    ::rust::IsRelocatable<::Qt::SizeMode>::value,
    "type Qt::SizeMode should be trivially move constructible and trivially destructible in C++ to be used as an argument of `draw_rounded_rect` in Rust");
static_assert(
    ::rust::IsRelocatable<::QRect>::value,
    "type QRect should be trivially move constructible and trivially destructible in C++ to be used as a return value of `viewport`, `window` in Rust");
static_assert(
    ::rust::IsRelocatable<::QRectF>::value,
    "type QRectF should be trivially move constructible and trivially destructible in C++ to be used as a return value of `clip_bounding_rect_or_empty` in Rust");
static_assert(
    ::rust::IsRelocatable<::QPoint>::value,
    "type QPoint should be trivially move constructible and trivially destructible in C++ to be used as a return value of `brush_origin` in Rust");
static_assert(
    ::rust::IsRelocatable<::QPainterPath>::value,
    "type QPainterPath should be trivially move constructible and trivially destructible in C++ to be used as a return value of `clip_path` in Rust");
static_assert(
    ::rust::IsRelocatable<::QRegion>::value,
    "type QRegion should be trivially move constructible and trivially destructible in C++ to be used as a return value of `clip_region` in Rust");

extern "C" {
void cxxbridge1$194$QPainter$background_mode(::QPainter const &self, ::Qt::BGMode *return$) noexcept {
  ::Qt::BGMode (::QPainter::*background_mode$)() const = &::QPainter::backgroundMode;
  new (return$) ::Qt::BGMode((self.*background_mode$)());
}

void cxxbridge1$194$QPainter$brush_origin(::QPainter const &self, ::QPoint *return$) noexcept {
  ::QPoint (::QPainter::*brush_origin$)() const = &::QPainter::brushOrigin;
  new (return$) ::QPoint((self.*brush_origin$)());
}

void cxxbridge1$194$QPainter$clip_bounding_rect_or_empty(::QPainter const &self, ::QRectF *return$) noexcept {
  ::QRectF (::QPainter::*clip_bounding_rect_or_empty$)() const = &::QPainter::clipBoundingRect;
  new (return$) ::QRectF((self.*clip_bounding_rect_or_empty$)());
}

void cxxbridge1$194$QPainter$clip_path(::QPainter const &self, ::QPainterPath *return$) noexcept {
  ::QPainterPath (::QPainter::*clip_path$)() const = &::QPainter::clipPath;
  new (return$) ::QPainterPath((self.*clip_path$)());
}

void cxxbridge1$194$QPainter$clip_region(::QPainter const &self, ::QRegion *return$) noexcept {
  ::QRegion (::QPainter::*clip_region$)() const = &::QPainter::clipRegion;
  new (return$) ::QRegion((self.*clip_region$)());
}

::rust::cxxqtlib1::QPainterCompositionMode cxxbridge1$194$QPainter$composition_mode(::QPainter const &self) noexcept {
  ::rust::cxxqtlib1::QPainterCompositionMode (::QPainter::*composition_mode$)() const = &::QPainter::compositionMode;
  return (self.*composition_mode$)();
}

void cxxbridge1$194$QPainter$draw_arc(::QPainter &self, ::std::int32_t x, ::std::int32_t y, ::std::int32_t width, ::std::int32_t height, ::std::int32_t start_angle, ::std::int32_t span_angle) noexcept {
  void (::QPainter::*draw_arc$)(::std::int32_t, ::std::int32_t, ::std::int32_t, ::std::int32_t, ::std::int32_t, ::std::int32_t) = &::QPainter::drawArc;
  (self.*draw_arc$)(x, y, width, height, start_angle, span_angle);
}

void cxxbridge1$194$QPainter$draw_chord(::QPainter &self, ::QRect const &rectangle, ::std::int32_t start_angle, ::std::int32_t span_angle) noexcept {
  void (::QPainter::*draw_chord$)(::QRect const &, ::std::int32_t, ::std::int32_t) = &::QPainter::drawChord;
  (self.*draw_chord$)(rectangle, start_angle, span_angle);
}

void cxxbridge1$194$QPainter$draw_convex_polygon(::QPainter &self, ::QPolygon const &polygon) noexcept {
  void (::QPainter::*draw_convex_polygon$)(::QPolygon const &) = &::QPainter::drawConvexPolygon;
  (self.*draw_convex_polygon$)(polygon);
}

void cxxbridge1$194$QPainter$draw_ellipse(::QPainter &self, ::QRect const &rectangle) noexcept {
  void (::QPainter::*draw_ellipse$)(::QRect const &) = &::QPainter::drawEllipse;
  (self.*draw_ellipse$)(rectangle);
}

void cxxbridge1$194$QPainter$draw_image(::QPainter &self, ::QRect const &rectangle, ::QImage const &image) noexcept {
  void (::QPainter::*draw_image$)(::QRect const &, ::QImage const &) = &::QPainter::drawImage;
  (self.*draw_image$)(rectangle, image);
}

void cxxbridge1$194$QPainter$draw_line(::QPainter &self, ::QLine const &line) noexcept {
  void (::QPainter::*draw_line$)(::QLine const &) = &::QPainter::drawLine;
  (self.*draw_line$)(line);
}

void cxxbridge1$194$QPainter$draw_linef(::QPainter &self, ::QLineF const &line) noexcept {
  void (::QPainter::*draw_linef$)(::QLineF const &) = &::QPainter::drawLine;
  (self.*draw_linef$)(line);
}

void cxxbridge1$194$QPainter$draw_lines(::QPainter &self, ::QVector_QLine const &lines) noexcept {
  void (::QPainter::*draw_lines$)(::QVector_QLine const &) = &::QPainter::drawLines;
  (self.*draw_lines$)(lines);
}

void cxxbridge1$194$QPainter$draw_linefs(::QPainter &self, ::QVector_QLineF const &lines) noexcept {
  void (::QPainter::*draw_linefs$)(::QVector_QLineF const &) = &::QPainter::drawLines;
  (self.*draw_linefs$)(lines);
}

void cxxbridge1$194$QPainter$draw_path(::QPainter &self, ::QPainterPath const &path) noexcept {
  void (::QPainter::*draw_path$)(::QPainterPath const &) = &::QPainter::drawPath;
  (self.*draw_path$)(path);
}

void cxxbridge1$194$QPainter$draw_pie(::QPainter &self, ::QRectF const &rectangle, ::std::int32_t start_angle, ::std::int32_t span_angle) noexcept {
  void (::QPainter::*draw_pie$)(::QRectF const &, ::std::int32_t, ::std::int32_t) = &::QPainter::drawPie;
  (self.*draw_pie$)(rectangle, start_angle, span_angle);
}

void cxxbridge1$194$QPainter$draw_point(::QPainter &self, ::QPoint const &point) noexcept {
  void (::QPainter::*draw_point$)(::QPoint const &) = &::QPainter::drawPoint;
  (self.*draw_point$)(point);
}

void cxxbridge1$194$QPainter$draw_points(::QPainter &self, ::QPolygon const &points) noexcept {
  void (::QPainter::*draw_points$)(::QPolygon const &) = &::QPainter::drawPoints;
  (self.*draw_points$)(points);
}

void cxxbridge1$194$QPainter$draw_polygon(::QPainter &self, ::QPolygon const &points, ::Qt::FillRule *fill_rule) noexcept {
  void (::QPainter::*draw_polygon$)(::QPolygon const &, ::Qt::FillRule) = &::QPainter::drawPolygon;
  (self.*draw_polygon$)(points, ::std::move(*fill_rule));
}

void cxxbridge1$194$QPainter$draw_polyline(::QPainter &self, ::QPolygon const &points) noexcept {
  void (::QPainter::*draw_polyline$)(::QPolygon const &) = &::QPainter::drawPolyline;
  (self.*draw_polyline$)(points);
}

void cxxbridge1$194$QPainter$draw_rect_f(::QPainter &self, ::QRectF const &rectangle) noexcept {
  void (::QPainter::*draw_rect_f$)(::QRectF const &) = &::QPainter::drawRect;
  (self.*draw_rect_f$)(rectangle);
}

void cxxbridge1$194$QPainter$draw_rounded_rect(::QPainter &self, ::QRectF const &rect, double x_radiu, double y_radius, ::Qt::SizeMode *mode) noexcept {
  void (::QPainter::*draw_rounded_rect$)(::QRectF const &, double, double, ::Qt::SizeMode) = &::QPainter::drawRoundedRect;
  (self.*draw_rounded_rect$)(rect, x_radiu, y_radius, ::std::move(*mode));
}

void cxxbridge1$194$QPainter$draw_text(::QPainter &self, ::QPoint const &position, ::QString const &text) noexcept {
  void (::QPainter::*draw_text$)(::QPoint const &, ::QString const &) = &::QPainter::drawText;
  (self.*draw_text$)(position, text);
}

void cxxbridge1$194$QPainter$erase_rect(::QPainter &self, ::QRectF const &rectangle) noexcept {
  void (::QPainter::*erase_rect$)(::QRectF const &) = &::QPainter::eraseRect;
  (self.*erase_rect$)(rectangle);
}

void cxxbridge1$194$QPainter$fill_rect(::QPainter &self, ::QRectF const &rectangle, ::QColor const &color) noexcept {
  void (::QPainter::*fill_rect$)(::QRectF const &, ::QColor const &) = &::QPainter::fillRect;
  (self.*fill_rect$)(rectangle, color);
}

void cxxbridge1$194$QPainter$font(::QPainter const &self, ::QFont const **return$) noexcept {
  ::QFont const &(::QPainter::*font$)() const = &::QPainter::font;
  new (return$) ::QFont const *(&(self.*font$)());
}

bool cxxbridge1$194$QPainter$has_clipping(::QPainter const &self) noexcept {
  bool (::QPainter::*has_clipping$)() const = &::QPainter::hasClipping;
  return (self.*has_clipping$)();
}

bool cxxbridge1$194$QPainter$is_active(::QPainter const &self) noexcept {
  bool (::QPainter::*is_active$)() const = &::QPainter::isActive;
  return (self.*is_active$)();
}

void cxxbridge1$194$QPainter$layout_direction(::QPainter const &self, ::Qt::LayoutDirection *return$) noexcept {
  ::Qt::LayoutDirection (::QPainter::*layout_direction$)() const = &::QPainter::layoutDirection;
  new (return$) ::Qt::LayoutDirection((self.*layout_direction$)());
}

double cxxbridge1$194$QPainter$opacity(::QPainter const &self) noexcept {
  double (::QPainter::*opacity$)() const = &::QPainter::opacity;
  return (self.*opacity$)();
}

void cxxbridge1$194$QPainter$pen(::QPainter const &self, ::QPen const **return$) noexcept {
  ::QPen const &(::QPainter::*pen$)() const = &::QPainter::pen;
  new (return$) ::QPen const *(&(self.*pen$)());
}

void cxxbridge1$194$QPainter$save(::QPainter &self) noexcept {
  void (::QPainter::*save$)() = &::QPainter::save;
  (self.*save$)();
}

void cxxbridge1$194$QPainter$set_background_mode(::QPainter &self, ::Qt::BGMode *mode) noexcept {
  void (::QPainter::*set_background_mode$)(::Qt::BGMode) = &::QPainter::setBackgroundMode;
  (self.*set_background_mode$)(::std::move(*mode));
}

void cxxbridge1$194$QPainter$set_clipping(::QPainter &self, bool enable) noexcept {
  void (::QPainter::*set_clipping$)(bool) = &::QPainter::setClipping;
  (self.*set_clipping$)(enable);
}

void cxxbridge1$194$QPainter$set_clip_path(::QPainter &self, ::QPainterPath const &path, ::Qt::ClipOperation *operation) noexcept {
  void (::QPainter::*set_clip_path$)(::QPainterPath const &, ::Qt::ClipOperation) = &::QPainter::setClipPath;
  (self.*set_clip_path$)(path, ::std::move(*operation));
}

void cxxbridge1$194$QPainter$set_clip_rect(::QPainter &self, ::QRect const &rectangle, ::Qt::ClipOperation *operation) noexcept {
  void (::QPainter::*set_clip_rect$)(::QRect const &, ::Qt::ClipOperation) = &::QPainter::setClipRect;
  (self.*set_clip_rect$)(rectangle, ::std::move(*operation));
}

void cxxbridge1$194$QPainter$set_clip_region(::QPainter &self, ::QRegion const &region, ::Qt::ClipOperation *operation) noexcept {
  void (::QPainter::*set_clip_region$)(::QRegion const &, ::Qt::ClipOperation) = &::QPainter::setClipRegion;
  (self.*set_clip_region$)(region, ::std::move(*operation));
}

void cxxbridge1$194$QPainter$set_composition_mode(::QPainter &self, ::rust::cxxqtlib1::QPainterCompositionMode mode) noexcept {
  void (::QPainter::*set_composition_mode$)(::rust::cxxqtlib1::QPainterCompositionMode) = &::QPainter::setCompositionMode;
  (self.*set_composition_mode$)(mode);
}

void cxxbridge1$194$QPainter$set_font(::QPainter &self, ::QFont const &font) noexcept {
  void (::QPainter::*set_font$)(::QFont const &) = &::QPainter::setFont;
  (self.*set_font$)(font);
}

void cxxbridge1$194$QPainter$set_layout_direction(::QPainter &self, ::Qt::LayoutDirection *direction) noexcept {
  void (::QPainter::*set_layout_direction$)(::Qt::LayoutDirection) = &::QPainter::setLayoutDirection;
  (self.*set_layout_direction$)(::std::move(*direction));
}

void cxxbridge1$194$QPainter$set_opacity(::QPainter &self, double opacity) noexcept {
  void (::QPainter::*set_opacity$)(double) = &::QPainter::setOpacity;
  (self.*set_opacity$)(opacity);
}

void cxxbridge1$194$QPainter$set_pen(::QPainter &self, ::QPen const &pen) noexcept {
  void (::QPainter::*set_pen$)(::QPen const &) = &::QPainter::setPen;
  (self.*set_pen$)(pen);
}

void cxxbridge1$194$QPainter$set_render_hint(::QPainter &self, ::rust::cxxqtlib1::QPainterRenderHint hint, bool on) noexcept {
  void (::QPainter::*set_render_hint$)(::rust::cxxqtlib1::QPainterRenderHint, bool) = &::QPainter::setRenderHint;
  (self.*set_render_hint$)(hint, on);
}

void cxxbridge1$194$QPainter$set_viewport(::QPainter &self, ::QRect const &rectangle) noexcept {
  void (::QPainter::*set_viewport$)(::QRect const &) = &::QPainter::setViewport;
  (self.*set_viewport$)(rectangle);
}

void cxxbridge1$194$QPainter$set_window(::QPainter &self, ::QRect const &rectangle) noexcept {
  void (::QPainter::*set_window$)(::QRect const &) = &::QPainter::setWindow;
  (self.*set_window$)(rectangle);
}

void cxxbridge1$194$QPainter$stroke_path(::QPainter &self, ::QPainterPath const &path, ::QPen const &pen) noexcept {
  void (::QPainter::*stroke_path$)(::QPainterPath const &, ::QPen const &) = &::QPainter::strokePath;
  (self.*stroke_path$)(path, pen);
}

bool cxxbridge1$194$QPainter$test_render_hint(::QPainter const &self, ::rust::cxxqtlib1::QPainterRenderHint hint) noexcept {
  bool (::QPainter::*test_render_hint$)(::rust::cxxqtlib1::QPainterRenderHint) const = &::QPainter::testRenderHint;
  return (self.*test_render_hint$)(hint);
}

void cxxbridge1$194$QPainter$restore(::QPainter &self) noexcept {
  void (::QPainter::*restore$)() = &::QPainter::restore;
  (self.*restore$)();
}

void cxxbridge1$194$QPainter$rotate(::QPainter &self, double angle) noexcept {
  void (::QPainter::*rotate$)(double) = &::QPainter::rotate;
  (self.*rotate$)(angle);
}

void cxxbridge1$194$QPainter$translate(::QPainter &self, ::QPoint const &offset) noexcept {
  void (::QPainter::*translate$)(::QPoint const &) = &::QPainter::translate;
  (self.*translate$)(offset);
}

bool cxxbridge1$194$QPainter$view_transform_enabled(::QPainter const &self) noexcept {
  bool (::QPainter::*view_transform_enabled$)() const = &::QPainter::viewTransformEnabled;
  return (self.*view_transform_enabled$)();
}

void cxxbridge1$194$QPainter$viewport(::QPainter const &self, ::QRect *return$) noexcept {
  ::QRect (::QPainter::*viewport$)() const = &::QPainter::viewport;
  new (return$) ::QRect((self.*viewport$)());
}

void cxxbridge1$194$QPainter$window(::QPainter const &self, ::QRect *return$) noexcept {
  ::QRect (::QPainter::*window$)() const = &::QPainter::window;
  new (return$) ::QRect((self.*window$)());
}
} // extern "C"

namespace rust {
namespace cxxqtlib1 {
extern "C" {
::QPainter *rust$cxxqtlib1$cxxbridge1$194$qpainter_init_default() noexcept {
  ::std::unique_ptr<::QPainter> (*qpainter_init_default$)() = ::rust::cxxqtlib1::make_unique;
  return qpainter_init_default$().release();
}
} // extern "C"
} // namespace cxxqtlib1
} // namespace rust

extern "C" {
static_assert(::rust::detail::is_complete<::std::remove_extent<::QPainter>::type>::value, "definition of `::QPainter` is required");
static_assert(sizeof(::std::unique_ptr<::QPainter>) == sizeof(void *), "");
static_assert(alignof(::std::unique_ptr<::QPainter>) == alignof(void *), "");
void cxxbridge1$unique_ptr$QPainter$null(::std::unique_ptr<::QPainter> *ptr) noexcept {
  ::new (ptr) ::std::unique_ptr<::QPainter>();
}
void cxxbridge1$unique_ptr$QPainter$raw(::std::unique_ptr<::QPainter> *ptr, ::std::unique_ptr<::QPainter>::pointer raw) noexcept {
  ::new (ptr) ::std::unique_ptr<::QPainter>(raw);
}
::std::unique_ptr<::QPainter>::element_type const *cxxbridge1$unique_ptr$QPainter$get(::std::unique_ptr<::QPainter> const &ptr) noexcept {
  return ptr.get();
}
::std::unique_ptr<::QPainter>::pointer cxxbridge1$unique_ptr$QPainter$release(::std::unique_ptr<::QPainter> &ptr) noexcept {
  return ptr.release();
}
void cxxbridge1$unique_ptr$QPainter$drop(::std::unique_ptr<::QPainter> *ptr) noexcept {
  ::rust::deleter_if<::rust::detail::is_complete<::QPainter>::value>{}(ptr);
}
} // extern "C"
