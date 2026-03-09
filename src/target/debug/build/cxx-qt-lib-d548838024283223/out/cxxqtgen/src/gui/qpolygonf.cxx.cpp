#include "cxx-qt-lib/qt.h"
#include "cxx-qt-lib/core/qvector/qvector_QPointF.h"
#include "cxx-qt-lib/qpointf.h"
#include "cxx-qt-lib/qrectf.h"
#include "cxx-qt-lib/qpolygon.h"
#include "cxx-qt-lib/qstring.h"
#include "cxx-qt-lib/qpolygonf.h"
#include "cxx-qt/casting.h"
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
    ::rust::IsRelocatable<::Qt::FillRule>::value,
    "type Qt::FillRule should be trivially move constructible and trivially destructible in C++ to be used as an argument of `contains_point` in Rust");
static_assert(
    ::rust::IsRelocatable<::QRectF>::value,
    "type QRectF should be trivially move constructible and trivially destructible in C++ to be used as a return value of `bounding_rect` in Rust");
static_assert(
    ::rust::IsRelocatable<::QPolygon>::value,
    "type QPolygon should be trivially move constructible and trivially destructible in C++ to be used as a return value of `to_polygon` in Rust");
static_assert(
    ::rust::IsRelocatable<::QString>::value,
    "type QString should be trivially move constructible and trivially destructible in C++ to be used as a return value of `qpolygonf_to_debug_qstring` in Rust");
static_assert(
    ::rust::IsRelocatable<::QPolygonF>::value,
    "type QPolygonF should be trivially move constructible and trivially destructible in C++ to be used as a return value of `intersected`, `subtracted`, `translated` in Rust");

extern "C" {
void cxxbridge1$194$QPolygonF$bounding_rect(::QPolygonF const &self, ::QRectF *return$) noexcept {
  ::QRectF (::QPolygonF::*bounding_rect$)() const = &::QPolygonF::boundingRect;
  new (return$) ::QRectF((self.*bounding_rect$)());
}

bool cxxbridge1$194$QPolygonF$contains_point(::QPolygonF const &self, ::QPointF const &point, ::Qt::FillRule *fill_rule) noexcept {
  bool (::QPolygonF::*contains_point$)(::QPointF const &, ::Qt::FillRule) const = &::QPolygonF::containsPoint;
  return (self.*contains_point$)(point, ::std::move(*fill_rule));
}

void cxxbridge1$194$QPolygonF$intersected(::QPolygonF const &self, ::QPolygonF const &r, ::QPolygonF *return$) noexcept {
  ::QPolygonF (::QPolygonF::*intersected$)(::QPolygonF const &) const = &::QPolygonF::intersected;
  new (return$) ::QPolygonF((self.*intersected$)(r));
}

bool cxxbridge1$194$QPolygonF$intersects(::QPolygonF const &self, ::QPolygonF const &p) noexcept {
  bool (::QPolygonF::*intersects$)(::QPolygonF const &) const = &::QPolygonF::intersects;
  return (self.*intersects$)(p);
}

bool cxxbridge1$194$QPolygonF$is_closed(::QPolygonF const &self) noexcept {
  bool (::QPolygonF::*is_closed$)() const = &::QPolygonF::isClosed;
  return (self.*is_closed$)();
}

void cxxbridge1$194$QPolygonF$subtracted(::QPolygonF const &self, ::QPolygonF const &r, ::QPolygonF *return$) noexcept {
  ::QPolygonF (::QPolygonF::*subtracted$)(::QPolygonF const &) const = &::QPolygonF::subtracted;
  new (return$) ::QPolygonF((self.*subtracted$)(r));
}

void cxxbridge1$194$QPolygonF$to_polygon(::QPolygonF const &self, ::QPolygon *return$) noexcept {
  ::QPolygon (::QPolygonF::*to_polygon$)() const = &::QPolygonF::toPolygon;
  new (return$) ::QPolygon((self.*to_polygon$)());
}

void cxxbridge1$194$QPolygonF$translate(::QPolygonF &self, double dx, double dy) noexcept {
  void (::QPolygonF::*translate$)(double, double) = &::QPolygonF::translate;
  (self.*translate$)(dx, dy);
}

void cxxbridge1$194$QPolygonF$translated(::QPolygonF const &self, double dx, double dy, ::QPolygonF *return$) noexcept {
  ::QPolygonF (::QPolygonF::*translated$)(double, double) const = &::QPolygonF::translated;
  new (return$) ::QPolygonF((self.*translated$)(dx, dy));
}

void cxxbridge1$194$QPolygonF$united(::QPolygonF const &self, ::QPolygonF const &r, ::QPolygonF *return$) noexcept {
  ::QPolygonF (::QPolygonF::*united$)(::QPolygonF const &) const = &::QPolygonF::united;
  new (return$) ::QPolygonF((self.*united$)(r));
}
} // extern "C"

namespace rust {
namespace cxxqt1 {
extern "C" {
::QVector_QPointF const *rust$cxxqt1$cxxbridge1$194$upcast_qpolygonf(::QPolygonF const *thiz) noexcept {
  ::QVector_QPointF const *(*upcast_qpolygonf$)(::QPolygonF const *) = ::rust::cxxqt1::upcastPtr;
  return upcast_qpolygonf$(thiz);
}

::QPolygonF const *rust$cxxqt1$cxxbridge1$194$downcast_qvector_qpointf(::QVector_QPointF const *base) noexcept {
  ::QPolygonF const *(*downcast_qvector_qpointf$)(::QVector_QPointF const *) = ::rust::cxxqt1::downcastPtrStatic;
  return downcast_qvector_qpointf$(base);
}
} // extern "C"
} // namespace cxxqt1

namespace cxxqtlib1 {
extern "C" {
void rust$cxxqtlib1$cxxbridge1$194$qpolygonf_init_default(::QPolygonF *return$) noexcept {
  ::QPolygonF (*qpolygonf_init_default$)() = ::rust::cxxqtlib1::construct;
  new (return$) ::QPolygonF(qpolygonf_init_default$());
}

void rust$cxxqtlib1$cxxbridge1$194$qpolygonf_drop(::QPolygonF &pen) noexcept {
  void (*qpolygonf_drop$)(::QPolygonF &) = ::rust::cxxqtlib1::drop;
  qpolygonf_drop$(pen);
}

void rust$cxxqtlib1$cxxbridge1$194$qpolygonf_clone(::QPolygonF const &p, ::QPolygonF *return$) noexcept {
  ::QPolygonF (*qpolygonf_clone$)(::QPolygonF const &) = ::rust::cxxqtlib1::construct;
  new (return$) ::QPolygonF(qpolygonf_clone$(p));
}

bool rust$cxxqtlib1$cxxbridge1$194$qpolygonf_eq(::QPolygonF const &a, ::QPolygonF const &b) noexcept {
  bool (*qpolygonf_eq$)(::QPolygonF const &, ::QPolygonF const &) = ::rust::cxxqtlib1::operatorEq;
  return qpolygonf_eq$(a, b);
}

void rust$cxxqtlib1$cxxbridge1$194$qpolygonf_to_debug_qstring(::QPolygonF const &value, ::QString *return$) noexcept {
  ::QString (*qpolygonf_to_debug_qstring$)(::QPolygonF const &) = ::rust::cxxqtlib1::toDebugQString;
  new (return$) ::QString(qpolygonf_to_debug_qstring$(value));
}
} // extern "C"
} // namespace cxxqtlib1
} // namespace rust
