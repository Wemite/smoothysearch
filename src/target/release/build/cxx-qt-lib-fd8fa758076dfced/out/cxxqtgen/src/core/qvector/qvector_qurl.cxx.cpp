#include "cxx-qt-lib/qurl.h"
#include "cxx-qt-lib/core/qvector/qvector_QUrl.h"
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
    ::rust::IsRelocatable<::QVector_QUrl>::value,
    "type QVector_QUrl should be trivially move constructible and trivially destructible in C++ to be used as a return value of `qvector_clone_QUrl`, `qvector_default_QUrl` in Rust");

extern "C" {
void cxxbridge1$194$QVector_QUrl$cxx_clear(::QVector_QUrl &self) noexcept {
  void (::QVector_QUrl::*cxx_clear$)() = &::QVector_QUrl::clear;
  (self.*cxx_clear$)();
}

bool cxxbridge1$194$QVector_QUrl$cxx_contains(::QVector_QUrl const &self, ::QUrl const &arg0) noexcept {
  bool (::QVector_QUrl::*cxx_contains$)(::QUrl const &) const = &::QVector_QUrl::contains;
  return (self.*cxx_contains$)(arg0);
}
} // extern "C"

namespace rust {
namespace cxxqtlib1 {
extern "C" {
void rust$cxxqtlib1$cxxbridge1$194$qvector_clone_QUrl(::QVector_QUrl const &arg0, ::QVector_QUrl *return$) noexcept {
  ::QVector_QUrl (*qvector_clone_QUrl$)(::QVector_QUrl const &) = ::rust::cxxqtlib1::construct;
  new (return$) ::QVector_QUrl(qvector_clone_QUrl$(arg0));
}

void rust$cxxqtlib1$cxxbridge1$194$qvector_default_QUrl(::QVector_QUrl *return$) noexcept {
  ::QVector_QUrl (*qvector_default_QUrl$)() = ::rust::cxxqtlib1::construct;
  new (return$) ::QVector_QUrl(qvector_default_QUrl$());
}

void rust$cxxqtlib1$cxxbridge1$194$qvector_drop_QUrl(::QVector_QUrl &arg0) noexcept {
  void (*qvector_drop_QUrl$)(::QVector_QUrl &) = ::rust::cxxqtlib1::drop;
  qvector_drop_QUrl$(arg0);
}
} // extern "C"

namespace qvector {
extern "C" {
void rust$cxxqtlib1$qvector$cxxbridge1$194$reserve_QUrl(::QVector_QUrl &arg0, ::rust::isize size) noexcept {
  void (*reserve_QUrl$)(::QVector_QUrl &, ::rust::isize) = ::rust::cxxqtlib1::qvector::qvectorReserve;
  reserve_QUrl$(arg0, size);
}

void rust$cxxqtlib1$qvector$cxxbridge1$194$append_QUrl(::QVector_QUrl &arg0, ::QUrl const &arg1) noexcept {
  void (*append_QUrl$)(::QVector_QUrl &, ::QUrl const &) = ::rust::cxxqtlib1::qvector::qvectorAppend;
  append_QUrl$(arg0, arg1);
}

void rust$cxxqtlib1$qvector$cxxbridge1$194$get_unchecked_QUrl(::QVector_QUrl const &set, ::rust::isize pos, ::QUrl const **return$) noexcept {
  ::QUrl const &(*get_unchecked_QUrl$)(::QVector_QUrl const &, ::rust::isize) = ::rust::cxxqtlib1::qvector::qvectorGetUnchecked;
  new (return$) ::QUrl const *(&get_unchecked_QUrl$(set, pos));
}

::rust::isize rust$cxxqtlib1$qvector$cxxbridge1$194$index_of_QUrl(::QVector_QUrl const &arg0, ::QUrl const &arg1) noexcept {
  ::rust::isize (*index_of_QUrl$)(::QVector_QUrl const &, ::QUrl const &) = ::rust::cxxqtlib1::qvector::qvectorIndexOf;
  return index_of_QUrl$(arg0, arg1);
}

void rust$cxxqtlib1$qvector$cxxbridge1$194$insert_QUrl(::QVector_QUrl &arg0, ::rust::isize arg1, ::QUrl const &arg2) noexcept {
  void (*insert_QUrl$)(::QVector_QUrl &, ::rust::isize, ::QUrl const &) = ::rust::cxxqtlib1::qvector::qvectorInsert;
  insert_QUrl$(arg0, arg1, arg2);
}

void rust$cxxqtlib1$qvector$cxxbridge1$194$remove_QUrl(::QVector_QUrl &arg0, ::rust::isize arg1) noexcept {
  void (*remove_QUrl$)(::QVector_QUrl &, ::rust::isize) = ::rust::cxxqtlib1::qvector::qvectorRemove;
  remove_QUrl$(arg0, arg1);
}

::rust::isize rust$cxxqtlib1$qvector$cxxbridge1$194$len_QUrl(::QVector_QUrl const &arg0) noexcept {
  ::rust::isize (*len_QUrl$)(::QVector_QUrl const &) = ::rust::cxxqtlib1::qvector::qvectorLen;
  return len_QUrl$(arg0);
}
} // extern "C"
} // namespace qvector
} // namespace cxxqtlib1
} // namespace rust
