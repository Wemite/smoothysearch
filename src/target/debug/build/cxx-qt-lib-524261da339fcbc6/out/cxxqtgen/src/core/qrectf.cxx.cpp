#include "cxx-qt-lib/qmarginsf.h"
#include "cxx-qt-lib/qpointf.h"
#include "cxx-qt-lib/qrect.h"
#include "cxx-qt-lib/qrectf.h"
#include "cxx-qt-lib/qsizef.h"
#include "cxx-qt-lib/qstring.h"
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
    ::rust::IsRelocatable<::QPointF>::value,
    "type QPointF should be trivially move constructible and trivially destructible in C++ to be used as a return value of `bottom_left`, `bottom_right`, `center` in Rust");
static_assert(
    ::rust::IsRelocatable<::QRect>::value,
    "type QRect should be trivially move constructible and trivially destructible in C++ to be used as a return value of `to_aligned_rect`, `to_rect` in Rust");
static_assert(
    ::rust::IsRelocatable<::QRectF>::value,
    "type QRectF should be trivially move constructible and trivially destructible in C++ to be used as a return value of `adjusted`, `intersected`, `margins_added` in Rust");
static_assert(
    ::rust::IsRelocatable<::QSizeF>::value,
    "type QSizeF should be trivially move constructible and trivially destructible in C++ to be used as a return value of `size` in Rust");
static_assert(
    ::rust::IsRelocatable<::QString>::value,
    "type QString should be trivially move constructible and trivially destructible in C++ to be used as a return value of `qrectf_to_debug_qstring` in Rust");

extern "C" {
void cxxbridge1$194$QRectF$adjust(::QRectF &self, double dx1, double dy1, double dx2, double dy2) noexcept {
  void (::QRectF::*adjust$)(double, double, double, double) = &::QRectF::adjust;
  (self.*adjust$)(dx1, dy1, dx2, dy2);
}

void cxxbridge1$194$QRectF$adjusted(::QRectF const &self, double dx1, double dy1, double dx2, double dy2, ::QRectF *return$) noexcept {
  ::QRectF (::QRectF::*adjusted$)(double, double, double, double) const = &::QRectF::adjusted;
  new (return$) ::QRectF((self.*adjusted$)(dx1, dy1, dx2, dy2));
}

double cxxbridge1$194$QRectF$bottom(::QRectF const &self) noexcept {
  double (::QRectF::*bottom$)() const = &::QRectF::bottom;
  return (self.*bottom$)();
}

void cxxbridge1$194$QRectF$bottom_left(::QRectF const &self, ::QPointF *return$) noexcept {
  ::QPointF (::QRectF::*bottom_left$)() const = &::QRectF::bottomLeft;
  new (return$) ::QPointF((self.*bottom_left$)());
}

void cxxbridge1$194$QRectF$bottom_right(::QRectF const &self, ::QPointF *return$) noexcept {
  ::QPointF (::QRectF::*bottom_right$)() const = &::QRectF::bottomRight;
  new (return$) ::QPointF((self.*bottom_right$)());
}

void cxxbridge1$194$QRectF$center(::QRectF const &self, ::QPointF *return$) noexcept {
  ::QPointF (::QRectF::*center$)() const = &::QRectF::center;
  new (return$) ::QPointF((self.*center$)());
}

bool cxxbridge1$194$QRectF$contains(::QRectF const &self, ::QPointF const &point) noexcept {
  bool (::QRectF::*contains$)(::QPointF const &) const = &::QRectF::contains;
  return (self.*contains$)(point);
}

double cxxbridge1$194$QRectF$height(::QRectF const &self) noexcept {
  double (::QRectF::*height$)() const = &::QRectF::height;
  return (self.*height$)();
}

void cxxbridge1$194$QRectF$intersected(::QRectF const &self, ::QRectF const &rectangle, ::QRectF *return$) noexcept {
  ::QRectF (::QRectF::*intersected$)(::QRectF const &) const = &::QRectF::intersected;
  new (return$) ::QRectF((self.*intersected$)(rectangle));
}

bool cxxbridge1$194$QRectF$intersects(::QRectF const &self, ::QRectF const &rectangle) noexcept {
  bool (::QRectF::*intersects$)(::QRectF const &) const = &::QRectF::intersects;
  return (self.*intersects$)(rectangle);
}

bool cxxbridge1$194$QRectF$is_empty(::QRectF const &self) noexcept {
  bool (::QRectF::*is_empty$)() const = &::QRectF::isEmpty;
  return (self.*is_empty$)();
}

bool cxxbridge1$194$QRectF$is_null(::QRectF const &self) noexcept {
  bool (::QRectF::*is_null$)() const = &::QRectF::isNull;
  return (self.*is_null$)();
}

bool cxxbridge1$194$QRectF$is_valid(::QRectF const &self) noexcept {
  bool (::QRectF::*is_valid$)() const = &::QRectF::isValid;
  return (self.*is_valid$)();
}

double cxxbridge1$194$QRectF$left(::QRectF const &self) noexcept {
  double (::QRectF::*left$)() const = &::QRectF::left;
  return (self.*left$)();
}

void cxxbridge1$194$QRectF$margins_added(::QRectF const &self, ::QMarginsF const &margins, ::QRectF *return$) noexcept {
  ::QRectF (::QRectF::*margins_added$)(::QMarginsF const &) const = &::QRectF::marginsAdded;
  new (return$) ::QRectF((self.*margins_added$)(margins));
}

void cxxbridge1$194$QRectF$margins_removed(::QRectF const &self, ::QMarginsF const &margins, ::QRectF *return$) noexcept {
  ::QRectF (::QRectF::*margins_removed$)(::QMarginsF const &) const = &::QRectF::marginsRemoved;
  new (return$) ::QRectF((self.*margins_removed$)(margins));
}

void cxxbridge1$194$QRectF$move_bottom(::QRectF &self, double y) noexcept {
  void (::QRectF::*move_bottom$)(double) = &::QRectF::moveBottom;
  (self.*move_bottom$)(y);
}

void cxxbridge1$194$QRectF$move_bottom_left(::QRectF &self, ::QPointF const &position) noexcept {
  void (::QRectF::*move_bottom_left$)(::QPointF const &) = &::QRectF::moveBottomLeft;
  (self.*move_bottom_left$)(position);
}

void cxxbridge1$194$QRectF$move_bottom_right(::QRectF &self, ::QPointF const &position) noexcept {
  void (::QRectF::*move_bottom_right$)(::QPointF const &) = &::QRectF::moveBottomRight;
  (self.*move_bottom_right$)(position);
}

void cxxbridge1$194$QRectF$move_center(::QRectF &self, ::QPointF const &position) noexcept {
  void (::QRectF::*move_center$)(::QPointF const &) = &::QRectF::moveCenter;
  (self.*move_center$)(position);
}

void cxxbridge1$194$QRectF$move_left(::QRectF &self, double x) noexcept {
  void (::QRectF::*move_left$)(double) = &::QRectF::moveLeft;
  (self.*move_left$)(x);
}

void cxxbridge1$194$QRectF$move_right(::QRectF &self, double x) noexcept {
  void (::QRectF::*move_right$)(double) = &::QRectF::moveRight;
  (self.*move_right$)(x);
}

void cxxbridge1$194$QRectF$move_to(::QRectF &self, ::QPointF const &position) noexcept {
  void (::QRectF::*move_to$)(::QPointF const &) = &::QRectF::moveTo;
  (self.*move_to$)(position);
}

void cxxbridge1$194$QRectF$move_top(::QRectF &self, double y) noexcept {
  void (::QRectF::*move_top$)(double) = &::QRectF::moveTop;
  (self.*move_top$)(y);
}

void cxxbridge1$194$QRectF$move_top_left(::QRectF &self, ::QPointF const &position) noexcept {
  void (::QRectF::*move_top_left$)(::QPointF const &) = &::QRectF::moveTopLeft;
  (self.*move_top_left$)(position);
}

void cxxbridge1$194$QRectF$move_top_right(::QRectF &self, ::QPointF const &position) noexcept {
  void (::QRectF::*move_top_right$)(::QPointF const &) = &::QRectF::moveTopRight;
  (self.*move_top_right$)(position);
}

void cxxbridge1$194$QRectF$normalized(::QRectF const &self, ::QRectF *return$) noexcept {
  ::QRectF (::QRectF::*normalized$)() const = &::QRectF::normalized;
  new (return$) ::QRectF((self.*normalized$)());
}

double cxxbridge1$194$QRectF$right(::QRectF const &self) noexcept {
  double (::QRectF::*right$)() const = &::QRectF::right;
  return (self.*right$)();
}

void cxxbridge1$194$QRectF$set_bottom(::QRectF &self, double y) noexcept {
  void (::QRectF::*set_bottom$)(double) = &::QRectF::setBottom;
  (self.*set_bottom$)(y);
}

void cxxbridge1$194$QRectF$set_bottom_left(::QRectF &self, ::QPointF const &position) noexcept {
  void (::QRectF::*set_bottom_left$)(::QPointF const &) = &::QRectF::setBottomLeft;
  (self.*set_bottom_left$)(position);
}

void cxxbridge1$194$QRectF$set_bottom_right(::QRectF &self, ::QPointF const &position) noexcept {
  void (::QRectF::*set_bottom_right$)(::QPointF const &) = &::QRectF::setBottomRight;
  (self.*set_bottom_right$)(position);
}

void cxxbridge1$194$QRectF$set_coords(::QRectF &self, double x1, double y1, double x2, double y2) noexcept {
  void (::QRectF::*set_coords$)(double, double, double, double) = &::QRectF::setCoords;
  (self.*set_coords$)(x1, y1, x2, y2);
}

void cxxbridge1$194$QRectF$set_height(::QRectF &self, double h) noexcept {
  void (::QRectF::*set_height$)(double) = &::QRectF::setHeight;
  (self.*set_height$)(h);
}

void cxxbridge1$194$QRectF$set_left(::QRectF &self, double x) noexcept {
  void (::QRectF::*set_left$)(double) = &::QRectF::setLeft;
  (self.*set_left$)(x);
}

void cxxbridge1$194$QRectF$set_rect(::QRectF &self, double x, double y, double width, double height) noexcept {
  void (::QRectF::*set_rect$)(double, double, double, double) = &::QRectF::setRect;
  (self.*set_rect$)(x, y, width, height);
}

void cxxbridge1$194$QRectF$set_right(::QRectF &self, double x) noexcept {
  void (::QRectF::*set_right$)(double) = &::QRectF::setRight;
  (self.*set_right$)(x);
}

void cxxbridge1$194$QRectF$set_size(::QRectF &self, ::QSizeF const &size) noexcept {
  void (::QRectF::*set_size$)(::QSizeF const &) = &::QRectF::setSize;
  (self.*set_size$)(size);
}

void cxxbridge1$194$QRectF$set_top(::QRectF &self, double y) noexcept {
  void (::QRectF::*set_top$)(double) = &::QRectF::setTop;
  (self.*set_top$)(y);
}

void cxxbridge1$194$QRectF$set_top_left(::QRectF &self, ::QPointF const &position) noexcept {
  void (::QRectF::*set_top_left$)(::QPointF const &) = &::QRectF::setTopLeft;
  (self.*set_top_left$)(position);
}

void cxxbridge1$194$QRectF$set_top_right(::QRectF &self, ::QPointF const &position) noexcept {
  void (::QRectF::*set_top_right$)(::QPointF const &) = &::QRectF::setTopRight;
  (self.*set_top_right$)(position);
}

void cxxbridge1$194$QRectF$set_width(::QRectF &self, double w) noexcept {
  void (::QRectF::*set_width$)(double) = &::QRectF::setWidth;
  (self.*set_width$)(w);
}

void cxxbridge1$194$QRectF$set_x(::QRectF &self, double x) noexcept {
  void (::QRectF::*set_x$)(double) = &::QRectF::setX;
  (self.*set_x$)(x);
}

void cxxbridge1$194$QRectF$set_y(::QRectF &self, double y) noexcept {
  void (::QRectF::*set_y$)(double) = &::QRectF::setY;
  (self.*set_y$)(y);
}

void cxxbridge1$194$QRectF$size(::QRectF const &self, ::QSizeF *return$) noexcept {
  ::QSizeF (::QRectF::*size$)() const = &::QRectF::size;
  new (return$) ::QSizeF((self.*size$)());
}

void cxxbridge1$194$QRectF$to_aligned_rect(::QRectF const &self, ::QRect *return$) noexcept {
  ::QRect (::QRectF::*to_aligned_rect$)() const = &::QRectF::toAlignedRect;
  new (return$) ::QRect((self.*to_aligned_rect$)());
}

void cxxbridge1$194$QRectF$to_rect(::QRectF const &self, ::QRect *return$) noexcept {
  ::QRect (::QRectF::*to_rect$)() const = &::QRectF::toRect;
  new (return$) ::QRect((self.*to_rect$)());
}

double cxxbridge1$194$QRectF$top(::QRectF const &self) noexcept {
  double (::QRectF::*top$)() const = &::QRectF::top;
  return (self.*top$)();
}

void cxxbridge1$194$QRectF$top_left(::QRectF const &self, ::QPointF *return$) noexcept {
  ::QPointF (::QRectF::*top_left$)() const = &::QRectF::topLeft;
  new (return$) ::QPointF((self.*top_left$)());
}

void cxxbridge1$194$QRectF$top_right(::QRectF const &self, ::QPointF *return$) noexcept {
  ::QPointF (::QRectF::*top_right$)() const = &::QRectF::topRight;
  new (return$) ::QPointF((self.*top_right$)());
}

void cxxbridge1$194$QRectF$translate(::QRectF &self, ::QPointF const &offset) noexcept {
  void (::QRectF::*translate$)(::QPointF const &) = &::QRectF::translate;
  (self.*translate$)(offset);
}

void cxxbridge1$194$QRectF$translated(::QRectF const &self, ::QPointF const &offset, ::QRectF *return$) noexcept {
  ::QRectF (::QRectF::*translated$)(::QPointF const &) const = &::QRectF::translated;
  new (return$) ::QRectF((self.*translated$)(offset));
}

void cxxbridge1$194$QRectF$transposed(::QRectF const &self, ::QRectF *return$) noexcept {
  ::QRectF (::QRectF::*transposed$)() const = &::QRectF::transposed;
  new (return$) ::QRectF((self.*transposed$)());
}

void cxxbridge1$194$QRectF$united(::QRectF const &self, ::QRectF const &rectangle, ::QRectF *return$) noexcept {
  ::QRectF (::QRectF::*united$)(::QRectF const &) const = &::QRectF::united;
  new (return$) ::QRectF((self.*united$)(rectangle));
}

double cxxbridge1$194$QRectF$width(::QRectF const &self) noexcept {
  double (::QRectF::*width$)() const = &::QRectF::width;
  return (self.*width$)();
}

double cxxbridge1$194$QRectF$x(::QRectF const &self) noexcept {
  double (::QRectF::*x$)() const = &::QRectF::x;
  return (self.*x$)();
}

double cxxbridge1$194$QRectF$y(::QRectF const &self) noexcept {
  double (::QRectF::*y$)() const = &::QRectF::y;
  return (self.*y$)();
}
} // extern "C"

namespace rust {
namespace cxxqtlib1 {
extern "C" {
void rust$cxxqtlib1$cxxbridge1$194$qrectf_init_default(::QRectF *return$) noexcept {
  ::QRectF (*qrectf_init_default$)() = ::rust::cxxqtlib1::construct;
  new (return$) ::QRectF(qrectf_init_default$());
}

void rust$cxxqtlib1$cxxbridge1$194$qrectf_init(double x, double y, double width, double height, ::QRectF *return$) noexcept {
  ::QRectF (*qrectf_init$)(double, double, double, double) = ::rust::cxxqtlib1::construct;
  new (return$) ::QRectF(qrectf_init$(x, y, width, height));
}

void rust$cxxqtlib1$cxxbridge1$194$qrectf_from_qrect(::QRect const &rectangle, ::QRectF *return$) noexcept {
  ::QRectF (*qrectf_from_qrect$)(::QRect const &) = ::rust::cxxqtlib1::construct;
  new (return$) ::QRectF(qrectf_from_qrect$(rectangle));
}

void rust$cxxqtlib1$cxxbridge1$194$qrectf_to_debug_qstring(::QRectF const &value, ::QString *return$) noexcept {
  ::QString (*qrectf_to_debug_qstring$)(::QRectF const &) = ::rust::cxxqtlib1::toDebugQString;
  new (return$) ::QString(qrectf_to_debug_qstring$(value));
}

void rust$cxxqtlib1$cxxbridge1$194$qrectf_plus(::QRectF const &a, ::QMarginsF const &b, ::QRectF *return$) noexcept {
  ::QRectF (*qrectf_plus$)(::QRectF const &, ::QMarginsF const &) = ::rust::cxxqtlib1::operatorPlus;
  new (return$) ::QRectF(qrectf_plus$(a, b));
}

void rust$cxxqtlib1$cxxbridge1$194$qrectf_minus(::QRectF const &a, ::QMarginsF const &b, ::QRectF *return$) noexcept {
  ::QRectF (*qrectf_minus$)(::QRectF const &, ::QMarginsF const &) = ::rust::cxxqtlib1::operatorMinus;
  new (return$) ::QRectF(qrectf_minus$(a, b));
}
} // extern "C"
} // namespace cxxqtlib1
} // namespace rust
