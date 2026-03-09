#include "cxx-qt-lib/qdate.h"
#include "cxx-qt-lib/core/qvector/qvector_QDate.h"
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
    ::rust::IsRelocatable<::QVector_QDate>::value,
    "type QVector_QDate should be trivially move constructible and trivially destructible in C++ to be used as a return value of `qvector_clone_QDate`, `qvector_default_QDate` in Rust");

extern "C" {
void cxxbridge1$194$QVector_QDate$cxx_clear(::QVector_QDate &self) noexcept {
  void (::QVector_QDate::*cxx_clear$)() = &::QVector_QDate::clear;
  (self.*cxx_clear$)();
}

bool cxxbridge1$194$QVector_QDate$cxx_contains(::QVector_QDate const &self, ::QDate const &arg0) noexcept {
  bool (::QVector_QDate::*cxx_contains$)(::QDate const &) const = &::QVector_QDate::contains;
  return (self.*cxx_contains$)(arg0);
}
} // extern "C"

namespace rust {
namespace cxxqtlib1 {
extern "C" {
void rust$cxxqtlib1$cxxbridge1$194$qvector_clone_QDate(::QVector_QDate const &arg0, ::QVector_QDate *return$) noexcept {
  ::QVector_QDate (*qvector_clone_QDate$)(::QVector_QDate const &) = ::rust::cxxqtlib1::construct;
  new (return$) ::QVector_QDate(qvector_clone_QDate$(arg0));
}

void rust$cxxqtlib1$cxxbridge1$194$qvector_default_QDate(::QVector_QDate *return$) noexcept {
  ::QVector_QDate (*qvector_default_QDate$)() = ::rust::cxxqtlib1::construct;
  new (return$) ::QVector_QDate(qvector_default_QDate$());
}

void rust$cxxqtlib1$cxxbridge1$194$qvector_drop_QDate(::QVector_QDate &arg0) noexcept {
  void (*qvector_drop_QDate$)(::QVector_QDate &) = ::rust::cxxqtlib1::drop;
  qvector_drop_QDate$(arg0);
}
} // extern "C"

namespace qvector {
extern "C" {
void rust$cxxqtlib1$qvector$cxxbridge1$194$reserve_QDate(::QVector_QDate &arg0, ::rust::isize size) noexcept {
  void (*reserve_QDate$)(::QVector_QDate &, ::rust::isize) = ::rust::cxxqtlib1::qvector::qvectorReserve;
  reserve_QDate$(arg0, size);
}

void rust$cxxqtlib1$qvector$cxxbridge1$194$append_QDate(::QVector_QDate &arg0, ::QDate const &arg1) noexcept {
  void (*append_QDate$)(::QVector_QDate &, ::QDate const &) = ::rust::cxxqtlib1::qvector::qvectorAppend;
  append_QDate$(arg0, arg1);
}

void rust$cxxqtlib1$qvector$cxxbridge1$194$get_unchecked_QDate(::QVector_QDate const &set, ::rust::isize pos, ::QDate const **return$) noexcept {
  ::QDate const &(*get_unchecked_QDate$)(::QVector_QDate const &, ::rust::isize) = ::rust::cxxqtlib1::qvector::qvectorGetUnchecked;
  new (return$) ::QDate const *(&get_unchecked_QDate$(set, pos));
}

::rust::isize rust$cxxqtlib1$qvector$cxxbridge1$194$index_of_QDate(::QVector_QDate const &arg0, ::QDate const &arg1) noexcept {
  ::rust::isize (*index_of_QDate$)(::QVector_QDate const &, ::QDate const &) = ::rust::cxxqtlib1::qvector::qvectorIndexOf;
  return index_of_QDate$(arg0, arg1);
}

void rust$cxxqtlib1$qvector$cxxbridge1$194$insert_QDate(::QVector_QDate &arg0, ::rust::isize arg1, ::QDate const &arg2) noexcept {
  void (*insert_QDate$)(::QVector_QDate &, ::rust::isize, ::QDate const &) = ::rust::cxxqtlib1::qvector::qvectorInsert;
  insert_QDate$(arg0, arg1, arg2);
}

void rust$cxxqtlib1$qvector$cxxbridge1$194$remove_QDate(::QVector_QDate &arg0, ::rust::isize arg1) noexcept {
  void (*remove_QDate$)(::QVector_QDate &, ::rust::isize) = ::rust::cxxqtlib1::qvector::qvectorRemove;
  remove_QDate$(arg0, arg1);
}

::rust::isize rust$cxxqtlib1$qvector$cxxbridge1$194$len_QDate(::QVector_QDate const &arg0) noexcept {
  ::rust::isize (*len_QDate$)(::QVector_QDate const &) = ::rust::cxxqtlib1::qvector::qvectorLen;
  return len_QDate$(arg0);
}
} // extern "C"
} // namespace qvector
} // namespace cxxqtlib1
} // namespace rust
