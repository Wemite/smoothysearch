#include "cxx-qt-lib/qpoint.h"
#include "cxx-qt-lib/core/qvector/qvector_QPoint.h"
#include "cxx-qt-lib/common.h"
#include <new>
#include <type_traits>
#if defined(_WIN32)
#include <basetsd.h>
#else
#include <sys/types.h>
#endif

#ifdef __GNUC__
#pragma GCC diagnostic ignored "-Wmissing-declarations"
#ifdef __clang__
#pragma clang diagnostic ignored "-Wdollar-in-identifier-extension"
#endif // __clang__
#endif // __GNUC__

namespace rust {
inline namespace cxxbridge1 {
// #include "rust/cxx.h"

#ifndef CXXBRIDGE1_RUST_ISIZE
#define CXXBRIDGE1_RUST_ISIZE
#if defined(_WIN32)
using isize = SSIZE_T;
#else
using isize = ssize_t;
#endif
#endif // CXXBRIDGE1_RUST_ISIZE

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
    ::rust::IsRelocatable<::QVector_QPoint>::value,
    "type QVector_QPoint should be trivially move constructible and trivially destructible in C++ to be used as a return value of `qvector_clone_QPoint`, `qvector_default_QPoint` in Rust");

extern "C" {
void cxxbridge1$194$QVector_QPoint$cxx_clear(::QVector_QPoint &self) noexcept {
  void (::QVector_QPoint::*cxx_clear$)() = &::QVector_QPoint::clear;
  (self.*cxx_clear$)();
}

bool cxxbridge1$194$QVector_QPoint$cxx_contains(::QVector_QPoint const &self, ::QPoint const &arg0) noexcept {
  bool (::QVector_QPoint::*cxx_contains$)(::QPoint const &) const = &::QVector_QPoint::contains;
  return (self.*cxx_contains$)(arg0);
}
} // extern "C"

namespace rust {
namespace cxxqtlib1 {
extern "C" {
void rust$cxxqtlib1$cxxbridge1$194$qvector_clone_QPoint(::QVector_QPoint const &arg0, ::QVector_QPoint *return$) noexcept {
  ::QVector_QPoint (*qvector_clone_QPoint$)(::QVector_QPoint const &) = ::rust::cxxqtlib1::construct;
  new (return$) ::QVector_QPoint(qvector_clone_QPoint$(arg0));
}

void rust$cxxqtlib1$cxxbridge1$194$qvector_default_QPoint(::QVector_QPoint *return$) noexcept {
  ::QVector_QPoint (*qvector_default_QPoint$)() = ::rust::cxxqtlib1::construct;
  new (return$) ::QVector_QPoint(qvector_default_QPoint$());
}

void rust$cxxqtlib1$cxxbridge1$194$qvector_drop_QPoint(::QVector_QPoint &arg0) noexcept {
  void (*qvector_drop_QPoint$)(::QVector_QPoint &) = ::rust::cxxqtlib1::drop;
  qvector_drop_QPoint$(arg0);
}
} // extern "C"

namespace qvector {
extern "C" {
void rust$cxxqtlib1$qvector$cxxbridge1$194$reserve_QPoint(::QVector_QPoint &arg0, ::rust::isize size) noexcept {
  void (*reserve_QPoint$)(::QVector_QPoint &, ::rust::isize) = ::rust::cxxqtlib1::qvector::qvectorReserve;
  reserve_QPoint$(arg0, size);
}

void rust$cxxqtlib1$qvector$cxxbridge1$194$append_QPoint(::QVector_QPoint &arg0, ::QPoint const &arg1) noexcept {
  void (*append_QPoint$)(::QVector_QPoint &, ::QPoint const &) = ::rust::cxxqtlib1::qvector::qvectorAppend;
  append_QPoint$(arg0, arg1);
}

void rust$cxxqtlib1$qvector$cxxbridge1$194$get_unchecked_QPoint(::QVector_QPoint const &set, ::rust::isize pos, ::QPoint const **return$) noexcept {
  ::QPoint const &(*get_unchecked_QPoint$)(::QVector_QPoint const &, ::rust::isize) = ::rust::cxxqtlib1::qvector::qvectorGetUnchecked;
  new (return$) ::QPoint const *(&get_unchecked_QPoint$(set, pos));
}

::rust::isize rust$cxxqtlib1$qvector$cxxbridge1$194$index_of_QPoint(::QVector_QPoint const &arg0, ::QPoint const &arg1) noexcept {
  ::rust::isize (*index_of_QPoint$)(::QVector_QPoint const &, ::QPoint const &) = ::rust::cxxqtlib1::qvector::qvectorIndexOf;
  return index_of_QPoint$(arg0, arg1);
}

void rust$cxxqtlib1$qvector$cxxbridge1$194$insert_QPoint(::QVector_QPoint &arg0, ::rust::isize arg1, ::QPoint const &arg2) noexcept {
  void (*insert_QPoint$)(::QVector_QPoint &, ::rust::isize, ::QPoint const &) = ::rust::cxxqtlib1::qvector::qvectorInsert;
  insert_QPoint$(arg0, arg1, arg2);
}

void rust$cxxqtlib1$qvector$cxxbridge1$194$remove_QPoint(::QVector_QPoint &arg0, ::rust::isize arg1) noexcept {
  void (*remove_QPoint$)(::QVector_QPoint &, ::rust::isize) = ::rust::cxxqtlib1::qvector::qvectorRemove;
  remove_QPoint$(arg0, arg1);
}

::rust::isize rust$cxxqtlib1$qvector$cxxbridge1$194$len_QPoint(::QVector_QPoint const &arg0) noexcept {
  ::rust::isize (*len_QPoint$)(::QVector_QPoint const &) = ::rust::cxxqtlib1::qvector::qvectorLen;
  return len_QPoint$(arg0);
}
} // extern "C"
} // namespace qvector
} // namespace cxxqtlib1
} // namespace rust
