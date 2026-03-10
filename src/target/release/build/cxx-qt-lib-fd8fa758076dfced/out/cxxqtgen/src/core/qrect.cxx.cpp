#include "cxx-qt-lib/qmargins.h"
#include "cxx-qt-lib/qpoint.h"
#include "cxx-qt-lib/qrect.h"
#include "cxx-qt-lib/qsize.h"
#include "cxx-qt-lib/qstring.h"
#include "cxx-qt-lib/qrectf.h"
#include "cxx-qt-lib/common.h"
#include <cstdint>
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
    "type QPoint should be trivially move constructible and trivially destructible in C++ to be used as a return value of `bottom_left`, `bottom_right`, `center` in Rust");
static_assert(
    ::rust::IsRelocatable<::QRect>::value,
    "type QRect should be trivially move constructible and trivially destructible in C++ to be used as a return value of `adjusted`, `intersected`, `margins_added` in Rust");
static_assert(
    ::rust::IsRelocatable<::QSize>::value,
    "type QSize should be trivially move constructible and trivially destructible in C++ to be used as a return value of `size` in Rust");
static_assert(
    ::rust::IsRelocatable<::QString>::value,
    "type QString should be trivially move constructible and trivially destructible in C++ to be used as a return value of `qrect_to_debug_qstring` in Rust");
static_assert(
    ::rust::IsRelocatable<::QRectF>::value,
    "type QRectF should be trivially move constructible and trivially destructible in C++ to be used as a return value of `to_rectf` in Rust");

extern "C" {
void cxxbridge1$194$QRect$adjust(::QRect &self, ::std::int32_t dx1, ::std::int32_t dy1, ::std::int32_t dx2, ::std::int32_t dy2) noexcept {
  void (::QRect::*adjust$)(::std::int32_t, ::std::int32_t, ::std::int32_t, ::std::int32_t) = &::QRect::adjust;
  (self.*adjust$)(dx1, dy1, dx2, dy2);
}

void cxxbridge1$194$QRect$adjusted(::QRect const &self, ::std::int32_t dx1, ::std::int32_t dy1, ::std::int32_t dx2, ::std::int32_t dy2, ::QRect *return$) noexcept {
  ::QRect (::QRect::*adjusted$)(::std::int32_t, ::std::int32_t, ::std::int32_t, ::std::int32_t) const = &::QRect::adjusted;
  new (return$) ::QRect((self.*adjusted$)(dx1, dy1, dx2, dy2));
}

::std::int32_t cxxbridge1$194$QRect$bottom(::QRect const &self) noexcept {
  ::std::int32_t (::QRect::*bottom$)() const = &::QRect::bottom;
  return (self.*bottom$)();
}

void cxxbridge1$194$QRect$bottom_left(::QRect const &self, ::QPoint *return$) noexcept {
  ::QPoint (::QRect::*bottom_left$)() const = &::QRect::bottomLeft;
  new (return$) ::QPoint((self.*bottom_left$)());
}

void cxxbridge1$194$QRect$bottom_right(::QRect const &self, ::QPoint *return$) noexcept {
  ::QPoint (::QRect::*bottom_right$)() const = &::QRect::bottomRight;
  new (return$) ::QPoint((self.*bottom_right$)());
}

void cxxbridge1$194$QRect$center(::QRect const &self, ::QPoint *return$) noexcept {
  ::QPoint (::QRect::*center$)() const = &::QRect::center;
  new (return$) ::QPoint((self.*center$)());
}

bool cxxbridge1$194$QRect$contains(::QRect const &self, ::QPoint const &point, bool proper) noexcept {
  bool (::QRect::*contains$)(::QPoint const &, bool) const = &::QRect::contains;
  return (self.*contains$)(point, proper);
}

::std::int32_t cxxbridge1$194$QRect$height(::QRect const &self) noexcept {
  ::std::int32_t (::QRect::*height$)() const = &::QRect::height;
  return (self.*height$)();
}

void cxxbridge1$194$QRect$intersected(::QRect const &self, ::QRect const &rectangle, ::QRect *return$) noexcept {
  ::QRect (::QRect::*intersected$)(::QRect const &) const = &::QRect::intersected;
  new (return$) ::QRect((self.*intersected$)(rectangle));
}

bool cxxbridge1$194$QRect$intersects(::QRect const &self, ::QRect const &rectangle) noexcept {
  bool (::QRect::*intersects$)(::QRect const &) const = &::QRect::intersects;
  return (self.*intersects$)(rectangle);
}

bool cxxbridge1$194$QRect$is_empty(::QRect const &self) noexcept {
  bool (::QRect::*is_empty$)() const = &::QRect::isEmpty;
  return (self.*is_empty$)();
}

bool cxxbridge1$194$QRect$is_null(::QRect const &self) noexcept {
  bool (::QRect::*is_null$)() const = &::QRect::isNull;
  return (self.*is_null$)();
}

bool cxxbridge1$194$QRect$is_valid(::QRect const &self) noexcept {
  bool (::QRect::*is_valid$)() const = &::QRect::isValid;
  return (self.*is_valid$)();
}

::std::int32_t cxxbridge1$194$QRect$left(::QRect const &self) noexcept {
  ::std::int32_t (::QRect::*left$)() const = &::QRect::left;
  return (self.*left$)();
}

void cxxbridge1$194$QRect$margins_added(::QRect const &self, ::QMargins const &margins, ::QRect *return$) noexcept {
  ::QRect (::QRect::*margins_added$)(::QMargins const &) const = &::QRect::marginsAdded;
  new (return$) ::QRect((self.*margins_added$)(margins));
}

void cxxbridge1$194$QRect$margins_removed(::QRect const &self, ::QMargins const &margins, ::QRect *return$) noexcept {
  ::QRect (::QRect::*margins_removed$)(::QMargins const &) const = &::QRect::marginsRemoved;
  new (return$) ::QRect((self.*margins_removed$)(margins));
}

void cxxbridge1$194$QRect$move_bottom(::QRect &self, ::std::int32_t y) noexcept {
  void (::QRect::*move_bottom$)(::std::int32_t) = &::QRect::moveBottom;
  (self.*move_bottom$)(y);
}

void cxxbridge1$194$QRect$move_bottom_left(::QRect &self, ::QPoint const &position) noexcept {
  void (::QRect::*move_bottom_left$)(::QPoint const &) = &::QRect::moveBottomLeft;
  (self.*move_bottom_left$)(position);
}

void cxxbridge1$194$QRect$move_bottom_right(::QRect &self, ::QPoint const &position) noexcept {
  void (::QRect::*move_bottom_right$)(::QPoint const &) = &::QRect::moveBottomRight;
  (self.*move_bottom_right$)(position);
}

void cxxbridge1$194$QRect$move_center(::QRect &self, ::QPoint const &position) noexcept {
  void (::QRect::*move_center$)(::QPoint const &) = &::QRect::moveCenter;
  (self.*move_center$)(position);
}

void cxxbridge1$194$QRect$move_left(::QRect &self, ::std::int32_t x) noexcept {
  void (::QRect::*move_left$)(::std::int32_t) = &::QRect::moveLeft;
  (self.*move_left$)(x);
}

void cxxbridge1$194$QRect$move_right(::QRect &self, ::std::int32_t x) noexcept {
  void (::QRect::*move_right$)(::std::int32_t) = &::QRect::moveRight;
  (self.*move_right$)(x);
}

void cxxbridge1$194$QRect$move_to(::QRect &self, ::QPoint const &position) noexcept {
  void (::QRect::*move_to$)(::QPoint const &) = &::QRect::moveTo;
  (self.*move_to$)(position);
}

void cxxbridge1$194$QRect$move_top(::QRect &self, ::std::int32_t y) noexcept {
  void (::QRect::*move_top$)(::std::int32_t) = &::QRect::moveTop;
  (self.*move_top$)(y);
}

void cxxbridge1$194$QRect$move_top_left(::QRect &self, ::QPoint const &position) noexcept {
  void (::QRect::*move_top_left$)(::QPoint const &) = &::QRect::moveTopLeft;
  (self.*move_top_left$)(position);
}

void cxxbridge1$194$QRect$move_top_right(::QRect &self, ::QPoint const &position) noexcept {
  void (::QRect::*move_top_right$)(::QPoint const &) = &::QRect::moveTopRight;
  (self.*move_top_right$)(position);
}

void cxxbridge1$194$QRect$normalized(::QRect const &self, ::QRect *return$) noexcept {
  ::QRect (::QRect::*normalized$)() const = &::QRect::normalized;
  new (return$) ::QRect((self.*normalized$)());
}

::std::int32_t cxxbridge1$194$QRect$right(::QRect const &self) noexcept {
  ::std::int32_t (::QRect::*right$)() const = &::QRect::right;
  return (self.*right$)();
}

void cxxbridge1$194$QRect$set_bottom(::QRect &self, ::std::int32_t y) noexcept {
  void (::QRect::*set_bottom$)(::std::int32_t) = &::QRect::setBottom;
  (self.*set_bottom$)(y);
}

void cxxbridge1$194$QRect$set_bottom_left(::QRect &self, ::QPoint const &position) noexcept {
  void (::QRect::*set_bottom_left$)(::QPoint const &) = &::QRect::setBottomLeft;
  (self.*set_bottom_left$)(position);
}

void cxxbridge1$194$QRect$set_bottom_right(::QRect &self, ::QPoint const &position) noexcept {
  void (::QRect::*set_bottom_right$)(::QPoint const &) = &::QRect::setBottomRight;
  (self.*set_bottom_right$)(position);
}

void cxxbridge1$194$QRect$set_coords(::QRect &self, ::std::int32_t x1, ::std::int32_t y1, ::std::int32_t x2, ::std::int32_t y2) noexcept {
  void (::QRect::*set_coords$)(::std::int32_t, ::std::int32_t, ::std::int32_t, ::std::int32_t) = &::QRect::setCoords;
  (self.*set_coords$)(x1, y1, x2, y2);
}

void cxxbridge1$194$QRect$set_height(::QRect &self, ::std::int32_t h) noexcept {
  void (::QRect::*set_height$)(::std::int32_t) = &::QRect::setHeight;
  (self.*set_height$)(h);
}

void cxxbridge1$194$QRect$set_left(::QRect &self, ::std::int32_t x) noexcept {
  void (::QRect::*set_left$)(::std::int32_t) = &::QRect::setLeft;
  (self.*set_left$)(x);
}

void cxxbridge1$194$QRect$set_rect(::QRect &self, ::std::int32_t x, ::std::int32_t y, ::std::int32_t width, ::std::int32_t height) noexcept {
  void (::QRect::*set_rect$)(::std::int32_t, ::std::int32_t, ::std::int32_t, ::std::int32_t) = &::QRect::setRect;
  (self.*set_rect$)(x, y, width, height);
}

void cxxbridge1$194$QRect$set_right(::QRect &self, ::std::int32_t x) noexcept {
  void (::QRect::*set_right$)(::std::int32_t) = &::QRect::setRight;
  (self.*set_right$)(x);
}

void cxxbridge1$194$QRect$set_size(::QRect &self, ::QSize const &size) noexcept {
  void (::QRect::*set_size$)(::QSize const &) = &::QRect::setSize;
  (self.*set_size$)(size);
}

void cxxbridge1$194$QRect$set_top(::QRect &self, ::std::int32_t y) noexcept {
  void (::QRect::*set_top$)(::std::int32_t) = &::QRect::setTop;
  (self.*set_top$)(y);
}

void cxxbridge1$194$QRect$set_top_left(::QRect &self, ::QPoint const &position) noexcept {
  void (::QRect::*set_top_left$)(::QPoint const &) = &::QRect::setTopLeft;
  (self.*set_top_left$)(position);
}

void cxxbridge1$194$QRect$set_top_right(::QRect &self, ::QPoint const &position) noexcept {
  void (::QRect::*set_top_right$)(::QPoint const &) = &::QRect::setTopRight;
  (self.*set_top_right$)(position);
}

void cxxbridge1$194$QRect$set_width(::QRect &self, ::std::int32_t w) noexcept {
  void (::QRect::*set_width$)(::std::int32_t) = &::QRect::setWidth;
  (self.*set_width$)(w);
}

void cxxbridge1$194$QRect$set_x(::QRect &self, ::std::int32_t x) noexcept {
  void (::QRect::*set_x$)(::std::int32_t) = &::QRect::setX;
  (self.*set_x$)(x);
}

void cxxbridge1$194$QRect$set_y(::QRect &self, ::std::int32_t y) noexcept {
  void (::QRect::*set_y$)(::std::int32_t) = &::QRect::setY;
  (self.*set_y$)(y);
}

void cxxbridge1$194$QRect$size(::QRect const &self, ::QSize *return$) noexcept {
  ::QSize (::QRect::*size$)() const = &::QRect::size;
  new (return$) ::QSize((self.*size$)());
}

void cxxbridge1$194$QRect$to_rectf(::QRect const &self, ::QRectF *return$) noexcept {
  ::QRectF (::QRect::*to_rectf$)() const = &::QRect::toRectF;
  new (return$) ::QRectF((self.*to_rectf$)());
}

::std::int32_t cxxbridge1$194$QRect$top(::QRect const &self) noexcept {
  ::std::int32_t (::QRect::*top$)() const = &::QRect::top;
  return (self.*top$)();
}

void cxxbridge1$194$QRect$top_left(::QRect const &self, ::QPoint *return$) noexcept {
  ::QPoint (::QRect::*top_left$)() const = &::QRect::topLeft;
  new (return$) ::QPoint((self.*top_left$)());
}

void cxxbridge1$194$QRect$top_right(::QRect const &self, ::QPoint *return$) noexcept {
  ::QPoint (::QRect::*top_right$)() const = &::QRect::topRight;
  new (return$) ::QPoint((self.*top_right$)());
}

void cxxbridge1$194$QRect$translate(::QRect &self, ::QPoint const &offset) noexcept {
  void (::QRect::*translate$)(::QPoint const &) = &::QRect::translate;
  (self.*translate$)(offset);
}

void cxxbridge1$194$QRect$translated(::QRect const &self, ::QPoint const &offset, ::QRect *return$) noexcept {
  ::QRect (::QRect::*translated$)(::QPoint const &) const = &::QRect::translated;
  new (return$) ::QRect((self.*translated$)(offset));
}

void cxxbridge1$194$QRect$transposed(::QRect const &self, ::QRect *return$) noexcept {
  ::QRect (::QRect::*transposed$)() const = &::QRect::transposed;
  new (return$) ::QRect((self.*transposed$)());
}

void cxxbridge1$194$QRect$united(::QRect const &self, ::QRect const &rectangle, ::QRect *return$) noexcept {
  ::QRect (::QRect::*united$)(::QRect const &) const = &::QRect::united;
  new (return$) ::QRect((self.*united$)(rectangle));
}

::std::int32_t cxxbridge1$194$QRect$width(::QRect const &self) noexcept {
  ::std::int32_t (::QRect::*width$)() const = &::QRect::width;
  return (self.*width$)();
}

::std::int32_t cxxbridge1$194$QRect$x(::QRect const &self) noexcept {
  ::std::int32_t (::QRect::*x$)() const = &::QRect::x;
  return (self.*x$)();
}

::std::int32_t cxxbridge1$194$QRect$y(::QRect const &self) noexcept {
  ::std::int32_t (::QRect::*y$)() const = &::QRect::y;
  return (self.*y$)();
}
} // extern "C"

namespace rust {
namespace cxxqtlib1 {
extern "C" {
void rust$cxxqtlib1$cxxbridge1$194$qrect_init_default(::QRect *return$) noexcept {
  ::QRect (*qrect_init_default$)() = ::rust::cxxqtlib1::construct;
  new (return$) ::QRect(qrect_init_default$());
}

void rust$cxxqtlib1$cxxbridge1$194$qrect_init(::std::int32_t x, ::std::int32_t y, ::std::int32_t width, ::std::int32_t height, ::QRect *return$) noexcept {
  ::QRect (*qrect_init$)(::std::int32_t, ::std::int32_t, ::std::int32_t, ::std::int32_t) = ::rust::cxxqtlib1::construct;
  new (return$) ::QRect(qrect_init$(x, y, width, height));
}

void rust$cxxqtlib1$cxxbridge1$194$qrect_to_debug_qstring(::QRect const &value, ::QString *return$) noexcept {
  ::QString (*qrect_to_debug_qstring$)(::QRect const &) = ::rust::cxxqtlib1::toDebugQString;
  new (return$) ::QString(qrect_to_debug_qstring$(value));
}

void rust$cxxqtlib1$cxxbridge1$194$qrect_plus(::QRect const &a, ::QMargins const &b, ::QRect *return$) noexcept {
  ::QRect (*qrect_plus$)(::QRect const &, ::QMargins const &) = ::rust::cxxqtlib1::operatorPlus;
  new (return$) ::QRect(qrect_plus$(a, b));
}

void rust$cxxqtlib1$cxxbridge1$194$qrect_minus(::QRect const &a, ::QMargins const &b, ::QRect *return$) noexcept {
  ::QRect (*qrect_minus$)(::QRect const &, ::QMargins const &) = ::rust::cxxqtlib1::operatorMinus;
  new (return$) ::QRect(qrect_minus$(a, b));
}
} // extern "C"
} // namespace cxxqtlib1
} // namespace rust
