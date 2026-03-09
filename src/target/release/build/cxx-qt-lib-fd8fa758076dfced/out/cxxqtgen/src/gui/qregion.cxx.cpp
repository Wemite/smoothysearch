#include "cxx-qt-lib/qregion.h"
#include "cxx-qt-lib/qrect.h"
#include "cxx-qt-lib/qpoint.h"
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
    ::rust::IsRelocatable<::QRegion>::value,
    "type QRegion should be trivially move constructible and trivially destructible in C++ to be used as a return value of `intersected`, `subtracted`, `translated` in Rust");
static_assert(
    ::rust::IsRelocatable<::QRect>::value,
    "type QRect should be trivially move constructible and trivially destructible in C++ to be used as a return value of `bounding_rect` in Rust");

extern "C" {
void cxxbridge1$194$QRegion$bounding_rect(::QRegion const &self, ::QRect *return$) noexcept {
  ::QRect (::QRegion::*bounding_rect$)() const = &::QRegion::boundingRect;
  new (return$) ::QRect((self.*bounding_rect$)());
}

bool cxxbridge1$194$QRegion$contains(::QRegion const &self, ::QRect const &r) noexcept {
  bool (::QRegion::*contains$)(::QRect const &) const = &::QRegion::contains;
  return (self.*contains$)(r);
}

void cxxbridge1$194$QRegion$intersected(::QRegion const &self, ::QRegion const &r, ::QRegion *return$) noexcept {
  ::QRegion (::QRegion::*intersected$)(::QRegion const &) const = &::QRegion::intersected;
  new (return$) ::QRegion((self.*intersected$)(r));
}

bool cxxbridge1$194$QRegion$is_empty(::QRegion const &self) noexcept {
  bool (::QRegion::*is_empty$)() const = &::QRegion::isEmpty;
  return (self.*is_empty$)();
}

bool cxxbridge1$194$QRegion$is_null(::QRegion const &self) noexcept {
  bool (::QRegion::*is_null$)() const = &::QRegion::isNull;
  return (self.*is_null$)();
}

::std::int32_t cxxbridge1$194$QRegion$rect_count(::QRegion const &self) noexcept {
  ::std::int32_t (::QRegion::*rect_count$)() const = &::QRegion::rectCount;
  return (self.*rect_count$)();
}

void cxxbridge1$194$QRegion$subtracted(::QRegion const &self, ::QRegion const &r, ::QRegion *return$) noexcept {
  ::QRegion (::QRegion::*subtracted$)(::QRegion const &) const = &::QRegion::subtracted;
  new (return$) ::QRegion((self.*subtracted$)(r));
}

void cxxbridge1$194$QRegion$translate(::QRegion &self, ::QPoint const &point) noexcept {
  void (::QRegion::*translate$)(::QPoint const &) = &::QRegion::translate;
  (self.*translate$)(point);
}

void cxxbridge1$194$QRegion$translated(::QRegion const &self, ::QPoint const &p, ::QRegion *return$) noexcept {
  ::QRegion (::QRegion::*translated$)(::QPoint const &) const = &::QRegion::translated;
  new (return$) ::QRegion((self.*translated$)(p));
}

void cxxbridge1$194$QRegion$united(::QRegion const &self, ::QRegion const &r, ::QRegion *return$) noexcept {
  ::QRegion (::QRegion::*united$)(::QRegion const &) const = &::QRegion::united;
  new (return$) ::QRegion((self.*united$)(r));
}

void cxxbridge1$194$QRegion$xored(::QRegion const &self, ::QRegion const &r, ::QRegion *return$) noexcept {
  ::QRegion (::QRegion::*xored$)(::QRegion const &) const = &::QRegion::xored;
  new (return$) ::QRegion((self.*xored$)(r));
}
} // extern "C"

namespace rust {
namespace cxxqtlib1 {
extern "C" {
void rust$cxxqtlib1$cxxbridge1$194$qregion_init_default(::QRegion *return$) noexcept {
  ::QRegion (*qregion_init_default$)() = ::rust::cxxqtlib1::construct;
  new (return$) ::QRegion(qregion_init_default$());
}

void rust$cxxqtlib1$cxxbridge1$194$qregion_drop(::QRegion &r) noexcept {
  void (*qregion_drop$)(::QRegion &) = ::rust::cxxqtlib1::drop;
  qregion_drop$(r);
}

void rust$cxxqtlib1$cxxbridge1$194$qregion_clone(::QRegion const &r, ::QRegion *return$) noexcept {
  ::QRegion (*qregion_clone$)(::QRegion const &) = ::rust::cxxqtlib1::construct;
  new (return$) ::QRegion(qregion_clone$(r));
}
} // extern "C"
} // namespace cxxqtlib1
} // namespace rust
