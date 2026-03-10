#include "cxx-qt-lib/quuid.h"
#include "cxx-qt-lib/core/qset/qset_QUuid.h"
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
    ::rust::IsRelocatable<::QSet_QUuid>::value,
    "type QSet_QUuid should be trivially move constructible and trivially destructible in C++ to be used as a return value of `qset_clone_QUuid`, `qset_default_QUuid` in Rust");

extern "C" {
void cxxbridge1$194$QSet_QUuid$cxx_clear(::QSet_QUuid &self) noexcept {
  void (::QSet_QUuid::*cxx_clear$)() = &::QSet_QUuid::clear;
  (self.*cxx_clear$)();
}

bool cxxbridge1$194$QSet_QUuid$cxx_contains(::QSet_QUuid const &self, ::QUuid const &arg0) noexcept {
  bool (::QSet_QUuid::*cxx_contains$)(::QUuid const &) const = &::QSet_QUuid::contains;
  return (self.*cxx_contains$)(arg0);
}

bool cxxbridge1$194$QSet_QUuid$cxx_remove(::QSet_QUuid &self, ::QUuid const &arg0) noexcept {
  bool (::QSet_QUuid::*cxx_remove$)(::QUuid const &) = &::QSet_QUuid::remove;
  return (self.*cxx_remove$)(arg0);
}
} // extern "C"

namespace rust {
namespace cxxqtlib1 {
extern "C" {
void rust$cxxqtlib1$cxxbridge1$194$qset_clone_QUuid(::QSet_QUuid const &arg0, ::QSet_QUuid *return$) noexcept {
  ::QSet_QUuid (*qset_clone_QUuid$)(::QSet_QUuid const &) = ::rust::cxxqtlib1::construct;
  new (return$) ::QSet_QUuid(qset_clone_QUuid$(arg0));
}

void rust$cxxqtlib1$cxxbridge1$194$qset_default_QUuid(::QSet_QUuid *return$) noexcept {
  ::QSet_QUuid (*qset_default_QUuid$)() = ::rust::cxxqtlib1::construct;
  new (return$) ::QSet_QUuid(qset_default_QUuid$());
}

void rust$cxxqtlib1$cxxbridge1$194$qset_drop_QUuid(::QSet_QUuid &arg0) noexcept {
  void (*qset_drop_QUuid$)(::QSet_QUuid &) = ::rust::cxxqtlib1::drop;
  qset_drop_QUuid$(arg0);
}
} // extern "C"

namespace qset {
extern "C" {
void rust$cxxqtlib1$qset$cxxbridge1$194$get_unchecked_QUuid(::QSet_QUuid const &set, ::rust::isize pos, ::QUuid const **return$) noexcept {
  ::QUuid const &(*get_unchecked_QUuid$)(::QSet_QUuid const &, ::rust::isize) = ::rust::cxxqtlib1::qset::qsetGetUnchecked;
  new (return$) ::QUuid const *(&get_unchecked_QUuid$(set, pos));
}

void rust$cxxqtlib1$qset$cxxbridge1$194$insert_QUuid(::QSet_QUuid &arg0, ::QUuid const &arg1) noexcept {
  void (*insert_QUuid$)(::QSet_QUuid &, ::QUuid const &) = ::rust::cxxqtlib1::qset::qsetInsert;
  insert_QUuid$(arg0, arg1);
}

::rust::isize rust$cxxqtlib1$qset$cxxbridge1$194$len_QUuid(::QSet_QUuid const &arg0) noexcept {
  ::rust::isize (*len_QUuid$)(::QSet_QUuid const &) = ::rust::cxxqtlib1::qset::qsetLen;
  return len_QUuid$(arg0);
}

void rust$cxxqtlib1$qset$cxxbridge1$194$reserve_QUuid(::QSet_QUuid &arg0, ::rust::isize size) noexcept {
  void (*reserve_QUuid$)(::QSet_QUuid &, ::rust::isize) = ::rust::cxxqtlib1::qset::qsetReserve;
  reserve_QUuid$(arg0, size);
}
} // extern "C"
} // namespace qset
} // namespace cxxqtlib1
} // namespace rust
