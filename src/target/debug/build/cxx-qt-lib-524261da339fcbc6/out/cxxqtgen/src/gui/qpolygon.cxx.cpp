#include "cxx-qt-lib/qt.h"
#include "cxx-qt-lib/core/qvector/qvector_QPoint.h"
#include "cxx-qt-lib/qpoint.h"
#include "cxx-qt-lib/qrect.h"
#include "cxx-qt-lib/qstring.h"
#include "cxx-qt-lib/qpolygonf.h"
#include "cxx-qt-lib/qpolygon.h"
#include "cxx-qt/casting.h"
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
    "type Qt::FillRule should be trivially move constructible and trivially destructible in C++ to be used as an argument of `contains_point` in Rust");
static_assert(
    ::rust::IsRelocatable<::QPoint>::value,
    "type QPoint should be trivially move constructible and trivially destructible in C++ to be used as a return value of `point` in Rust");
static_assert(
    ::rust::IsRelocatable<::QRect>::value,
    "type QRect should be trivially move constructible and trivially destructible in C++ to be used as a return value of `bounding_rect` in Rust");
static_assert(
    ::rust::IsRelocatable<::QString>::value,
    "type QString should be trivially move constructible and trivially destructible in C++ to be used as a return value of `qpolygon_to_debug_qstring` in Rust");
static_assert(
    ::rust::IsRelocatable<::QPolygonF>::value,
    "type QPolygonF should be trivially move constructible and trivially destructible in C++ to be used as a return value of `to_polygonf` in Rust");
static_assert(
    ::rust::IsRelocatable<::QPolygon>::value,
    "type QPolygon should be trivially move constructible and trivially destructible in C++ to be used as a return value of `intersected`, `subtracted`, `translated` in Rust");

extern "C" {
void cxxbridge1$194$QPolygon$bounding_rect(::QPolygon const &self, ::QRect *return$) noexcept {
  ::QRect (::QPolygon::*bounding_rect$)() const = &::QPolygon::boundingRect;
  new (return$) ::QRect((self.*bounding_rect$)());
}

bool cxxbridge1$194$QPolygon$contains_point(::QPolygon const &self, ::QPoint const &point, ::Qt::FillRule *fill_rule) noexcept {
  bool (::QPolygon::*contains_point$)(::QPoint const &, ::Qt::FillRule) const = &::QPolygon::containsPoint;
  return (self.*contains_point$)(point, ::std::move(*fill_rule));
}

void cxxbridge1$194$QPolygon$intersected(::QPolygon const &self, ::QPolygon const &r, ::QPolygon *return$) noexcept {
  ::QPolygon (::QPolygon::*intersected$)(::QPolygon const &) const = &::QPolygon::intersected;
  new (return$) ::QPolygon((self.*intersected$)(r));
}

bool cxxbridge1$194$QPolygon$intersects(::QPolygon const &self, ::QPolygon const &p) noexcept {
  bool (::QPolygon::*intersects$)(::QPolygon const &) const = &::QPolygon::intersects;
  return (self.*intersects$)(p);
}

void cxxbridge1$194$QPolygon$point(::QPolygon const &self, ::std::int32_t index, ::QPoint *return$) noexcept {
  ::QPoint (::QPolygon::*point$)(::std::int32_t) const = &::QPolygon::point;
  new (return$) ::QPoint((self.*point$)(index));
}

void cxxbridge1$194$QPolygon$set_point(::QPolygon &self, ::std::int32_t index, ::QPoint const &point) noexcept {
  void (::QPolygon::*set_point$)(::std::int32_t, ::QPoint const &) = &::QPolygon::setPoint;
  (self.*set_point$)(index, point);
}

void cxxbridge1$194$QPolygon$subtracted(::QPolygon const &self, ::QPolygon const &r, ::QPolygon *return$) noexcept {
  ::QPolygon (::QPolygon::*subtracted$)(::QPolygon const &) const = &::QPolygon::subtracted;
  new (return$) ::QPolygon((self.*subtracted$)(r));
}

void cxxbridge1$194$QPolygon$to_polygonf(::QPolygon const &self, ::QPolygonF *return$) noexcept {
  ::QPolygonF (::QPolygon::*to_polygonf$)() const = &::QPolygon::toPolygonF;
  new (return$) ::QPolygonF((self.*to_polygonf$)());
}

void cxxbridge1$194$QPolygon$translate(::QPolygon &self, ::std::int32_t dx, ::std::int32_t dy) noexcept {
  void (::QPolygon::*translate$)(::std::int32_t, ::std::int32_t) = &::QPolygon::translate;
  (self.*translate$)(dx, dy);
}

void cxxbridge1$194$QPolygon$translated(::QPolygon const &self, ::std::int32_t dx, ::std::int32_t dy, ::QPolygon *return$) noexcept {
  ::QPolygon (::QPolygon::*translated$)(::std::int32_t, ::std::int32_t) const = &::QPolygon::translated;
  new (return$) ::QPolygon((self.*translated$)(dx, dy));
}

void cxxbridge1$194$QPolygon$united(::QPolygon const &self, ::QPolygon const &r, ::QPolygon *return$) noexcept {
  ::QPolygon (::QPolygon::*united$)(::QPolygon const &) const = &::QPolygon::united;
  new (return$) ::QPolygon((self.*united$)(r));
}
} // extern "C"

namespace rust {
namespace cxxqt1 {
extern "C" {
::QVector_QPoint const *rust$cxxqt1$cxxbridge1$194$upcast_qpolygon(::QPolygon const *thiz) noexcept {
  ::QVector_QPoint const *(*upcast_qpolygon$)(::QPolygon const *) = ::rust::cxxqt1::upcastPtr;
  return upcast_qpolygon$(thiz);
}

::QPolygon const *rust$cxxqt1$cxxbridge1$194$downcast_qvector_qpoint(::QVector_QPoint const *base) noexcept {
  ::QPolygon const *(*downcast_qvector_qpoint$)(::QVector_QPoint const *) = ::rust::cxxqt1::downcastPtrStatic;
  return downcast_qvector_qpoint$(base);
}
} // extern "C"
} // namespace cxxqt1

namespace cxxqtlib1 {
extern "C" {
void rust$cxxqtlib1$cxxbridge1$194$qpolygon_init_default(::QPolygon *return$) noexcept {
  ::QPolygon (*qpolygon_init_default$)() = ::rust::cxxqtlib1::construct;
  new (return$) ::QPolygon(qpolygon_init_default$());
}

void rust$cxxqtlib1$cxxbridge1$194$qpolygon_init_qrect(::QRect const &rect, bool closed, ::QPolygon *return$) noexcept {
  ::QPolygon (*qpolygon_init_qrect$)(::QRect const &, bool) = ::rust::cxxqtlib1::construct;
  new (return$) ::QPolygon(qpolygon_init_qrect$(rect, closed));
}

void rust$cxxqtlib1$cxxbridge1$194$qpolygon_drop(::QPolygon &pen) noexcept {
  void (*qpolygon_drop$)(::QPolygon &) = ::rust::cxxqtlib1::drop;
  qpolygon_drop$(pen);
}

void rust$cxxqtlib1$cxxbridge1$194$qpolygon_clone(::QPolygon const &p, ::QPolygon *return$) noexcept {
  ::QPolygon (*qpolygon_clone$)(::QPolygon const &) = ::rust::cxxqtlib1::construct;
  new (return$) ::QPolygon(qpolygon_clone$(p));
}

bool rust$cxxqtlib1$cxxbridge1$194$qpolygon_eq(::QPolygon const &a, ::QPolygon const &b) noexcept {
  bool (*qpolygon_eq$)(::QPolygon const &, ::QPolygon const &) = ::rust::cxxqtlib1::operatorEq;
  return qpolygon_eq$(a, b);
}

void rust$cxxqtlib1$cxxbridge1$194$qpolygon_to_debug_qstring(::QPolygon const &value, ::QString *return$) noexcept {
  ::QString (*qpolygon_to_debug_qstring$)(::QPolygon const &) = ::rust::cxxqtlib1::toDebugQString;
  new (return$) ::QString(qpolygon_to_debug_qstring$(value));
}
} // extern "C"
} // namespace cxxqtlib1
} // namespace rust
