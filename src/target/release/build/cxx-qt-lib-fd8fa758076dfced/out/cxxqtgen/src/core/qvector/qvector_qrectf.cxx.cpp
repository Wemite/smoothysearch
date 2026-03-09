#include "cxx-qt-lib/qrectf.h"
#include "cxx-qt-lib/core/qvector/qvector_QRectF.h"
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
    ::rust::IsRelocatable<::QVector_QRectF>::value,
    "type QVector_QRectF should be trivially move constructible and trivially destructible in C++ to be used as a return value of `qvector_clone_QRectF`, `qvector_default_QRectF` in Rust");

extern "C" {
void cxxbridge1$194$QVector_QRectF$cxx_clear(::QVector_QRectF &self) noexcept {
  void (::QVector_QRectF::*cxx_clear$)() = &::QVector_QRectF::clear;
  (self.*cxx_clear$)();
}

bool cxxbridge1$194$QVector_QRectF$cxx_contains(::QVector_QRectF const &self, ::QRectF const &arg0) noexcept {
  bool (::QVector_QRectF::*cxx_contains$)(::QRectF const &) const = &::QVector_QRectF::contains;
  return (self.*cxx_contains$)(arg0);
}
} // extern "C"

namespace rust {
namespace cxxqtlib1 {
extern "C" {
void rust$cxxqtlib1$cxxbridge1$194$qvector_clone_QRectF(::QVector_QRectF const &arg0, ::QVector_QRectF *return$) noexcept {
  ::QVector_QRectF (*qvector_clone_QRectF$)(::QVector_QRectF const &) = ::rust::cxxqtlib1::construct;
  new (return$) ::QVector_QRectF(qvector_clone_QRectF$(arg0));
}

void rust$cxxqtlib1$cxxbridge1$194$qvector_default_QRectF(::QVector_QRectF *return$) noexcept {
  ::QVector_QRectF (*qvector_default_QRectF$)() = ::rust::cxxqtlib1::construct;
  new (return$) ::QVector_QRectF(qvector_default_QRectF$());
}

void rust$cxxqtlib1$cxxbridge1$194$qvector_drop_QRectF(::QVector_QRectF &arg0) noexcept {
  void (*qvector_drop_QRectF$)(::QVector_QRectF &) = ::rust::cxxqtlib1::drop;
  qvector_drop_QRectF$(arg0);
}
} // extern "C"

namespace qvector {
extern "C" {
void rust$cxxqtlib1$qvector$cxxbridge1$194$reserve_QRectF(::QVector_QRectF &arg0, ::rust::isize size) noexcept {
  void (*reserve_QRectF$)(::QVector_QRectF &, ::rust::isize) = ::rust::cxxqtlib1::qvector::qvectorReserve;
  reserve_QRectF$(arg0, size);
}

void rust$cxxqtlib1$qvector$cxxbridge1$194$append_QRectF(::QVector_QRectF &arg0, ::QRectF const &arg1) noexcept {
  void (*append_QRectF$)(::QVector_QRectF &, ::QRectF const &) = ::rust::cxxqtlib1::qvector::qvectorAppend;
  append_QRectF$(arg0, arg1);
}

void rust$cxxqtlib1$qvector$cxxbridge1$194$get_unchecked_QRectF(::QVector_QRectF const &set, ::rust::isize pos, ::QRectF const **return$) noexcept {
  ::QRectF const &(*get_unchecked_QRectF$)(::QVector_QRectF const &, ::rust::isize) = ::rust::cxxqtlib1::qvector::qvectorGetUnchecked;
  new (return$) ::QRectF const *(&get_unchecked_QRectF$(set, pos));
}

::rust::isize rust$cxxqtlib1$qvector$cxxbridge1$194$index_of_QRectF(::QVector_QRectF const &arg0, ::QRectF const &arg1) noexcept {
  ::rust::isize (*index_of_QRectF$)(::QVector_QRectF const &, ::QRectF const &) = ::rust::cxxqtlib1::qvector::qvectorIndexOf;
  return index_of_QRectF$(arg0, arg1);
}

void rust$cxxqtlib1$qvector$cxxbridge1$194$insert_QRectF(::QVector_QRectF &arg0, ::rust::isize arg1, ::QRectF const &arg2) noexcept {
  void (*insert_QRectF$)(::QVector_QRectF &, ::rust::isize, ::QRectF const &) = ::rust::cxxqtlib1::qvector::qvectorInsert;
  insert_QRectF$(arg0, arg1, arg2);
}

void rust$cxxqtlib1$qvector$cxxbridge1$194$remove_QRectF(::QVector_QRectF &arg0, ::rust::isize arg1) noexcept {
  void (*remove_QRectF$)(::QVector_QRectF &, ::rust::isize) = ::rust::cxxqtlib1::qvector::qvectorRemove;
  remove_QRectF$(arg0, arg1);
}

::rust::isize rust$cxxqtlib1$qvector$cxxbridge1$194$len_QRectF(::QVector_QRectF const &arg0) noexcept {
  ::rust::isize (*len_QRectF$)(::QVector_QRectF const &) = ::rust::cxxqtlib1::qvector::qvectorLen;
  return len_QRectF$(arg0);
}
} // extern "C"
} // namespace qvector
} // namespace cxxqtlib1
} // namespace rust
