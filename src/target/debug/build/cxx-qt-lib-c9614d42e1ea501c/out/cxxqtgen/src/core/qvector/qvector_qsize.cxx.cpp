#include "cxx-qt-lib/qsize.h"
#include "cxx-qt-lib/core/qvector/qvector_QSize.h"
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
    ::rust::IsRelocatable<::QVector_QSize>::value,
    "type QVector_QSize should be trivially move constructible and trivially destructible in C++ to be used as a return value of `qvector_clone_QSize`, `qvector_default_QSize` in Rust");

extern "C" {
void cxxbridge1$194$QVector_QSize$cxx_clear(::QVector_QSize &self) noexcept {
  void (::QVector_QSize::*cxx_clear$)() = &::QVector_QSize::clear;
  (self.*cxx_clear$)();
}

bool cxxbridge1$194$QVector_QSize$cxx_contains(::QVector_QSize const &self, ::QSize const &arg0) noexcept {
  bool (::QVector_QSize::*cxx_contains$)(::QSize const &) const = &::QVector_QSize::contains;
  return (self.*cxx_contains$)(arg0);
}
} // extern "C"

namespace rust {
namespace cxxqtlib1 {
extern "C" {
void rust$cxxqtlib1$cxxbridge1$194$qvector_clone_QSize(::QVector_QSize const &arg0, ::QVector_QSize *return$) noexcept {
  ::QVector_QSize (*qvector_clone_QSize$)(::QVector_QSize const &) = ::rust::cxxqtlib1::construct;
  new (return$) ::QVector_QSize(qvector_clone_QSize$(arg0));
}

void rust$cxxqtlib1$cxxbridge1$194$qvector_default_QSize(::QVector_QSize *return$) noexcept {
  ::QVector_QSize (*qvector_default_QSize$)() = ::rust::cxxqtlib1::construct;
  new (return$) ::QVector_QSize(qvector_default_QSize$());
}

void rust$cxxqtlib1$cxxbridge1$194$qvector_drop_QSize(::QVector_QSize &arg0) noexcept {
  void (*qvector_drop_QSize$)(::QVector_QSize &) = ::rust::cxxqtlib1::drop;
  qvector_drop_QSize$(arg0);
}
} // extern "C"

namespace qvector {
extern "C" {
void rust$cxxqtlib1$qvector$cxxbridge1$194$reserve_QSize(::QVector_QSize &arg0, ::rust::isize size) noexcept {
  void (*reserve_QSize$)(::QVector_QSize &, ::rust::isize) = ::rust::cxxqtlib1::qvector::qvectorReserve;
  reserve_QSize$(arg0, size);
}

void rust$cxxqtlib1$qvector$cxxbridge1$194$append_QSize(::QVector_QSize &arg0, ::QSize const &arg1) noexcept {
  void (*append_QSize$)(::QVector_QSize &, ::QSize const &) = ::rust::cxxqtlib1::qvector::qvectorAppend;
  append_QSize$(arg0, arg1);
}

void rust$cxxqtlib1$qvector$cxxbridge1$194$get_unchecked_QSize(::QVector_QSize const &set, ::rust::isize pos, ::QSize const **return$) noexcept {
  ::QSize const &(*get_unchecked_QSize$)(::QVector_QSize const &, ::rust::isize) = ::rust::cxxqtlib1::qvector::qvectorGetUnchecked;
  new (return$) ::QSize const *(&get_unchecked_QSize$(set, pos));
}

::rust::isize rust$cxxqtlib1$qvector$cxxbridge1$194$index_of_QSize(::QVector_QSize const &arg0, ::QSize const &arg1) noexcept {
  ::rust::isize (*index_of_QSize$)(::QVector_QSize const &, ::QSize const &) = ::rust::cxxqtlib1::qvector::qvectorIndexOf;
  return index_of_QSize$(arg0, arg1);
}

void rust$cxxqtlib1$qvector$cxxbridge1$194$insert_QSize(::QVector_QSize &arg0, ::rust::isize arg1, ::QSize const &arg2) noexcept {
  void (*insert_QSize$)(::QVector_QSize &, ::rust::isize, ::QSize const &) = ::rust::cxxqtlib1::qvector::qvectorInsert;
  insert_QSize$(arg0, arg1, arg2);
}

void rust$cxxqtlib1$qvector$cxxbridge1$194$remove_QSize(::QVector_QSize &arg0, ::rust::isize arg1) noexcept {
  void (*remove_QSize$)(::QVector_QSize &, ::rust::isize) = ::rust::cxxqtlib1::qvector::qvectorRemove;
  remove_QSize$(arg0, arg1);
}

::rust::isize rust$cxxqtlib1$qvector$cxxbridge1$194$len_QSize(::QVector_QSize const &arg0) noexcept {
  ::rust::isize (*len_QSize$)(::QVector_QSize const &) = ::rust::cxxqtlib1::qvector::qvectorLen;
  return len_QSize$(arg0);
}
} // extern "C"
} // namespace qvector
} // namespace cxxqtlib1
} // namespace rust
