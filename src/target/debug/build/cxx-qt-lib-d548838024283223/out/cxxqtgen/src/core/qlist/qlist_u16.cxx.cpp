#include "cxx-qt-lib/core/qlist/qlist_u16.h"
#include "cxx-qt-lib/common.h"
#include <cstdint>
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
    ::rust::IsRelocatable<::QList_u16>::value,
    "type QList_u16 should be trivially move constructible and trivially destructible in C++ to be used as a return value of `qlist_clone_u16`, `qlist_default_u16` in Rust");

extern "C" {
void cxxbridge1$194$QList_u16$cxx_clear(::QList_u16 &self) noexcept {
  void (::QList_u16::*cxx_clear$)() = &::QList_u16::clear;
  (self.*cxx_clear$)();
}

bool cxxbridge1$194$QList_u16$cxx_contains(::QList_u16 const &self, ::std::uint16_t const &arg0) noexcept {
  bool (::QList_u16::*cxx_contains$)(::std::uint16_t const &) const = &::QList_u16::contains;
  return (self.*cxx_contains$)(arg0);
}
} // extern "C"

namespace rust {
namespace cxxqtlib1 {
extern "C" {
void rust$cxxqtlib1$cxxbridge1$194$qlist_clone_u16(::QList_u16 const &arg0, ::QList_u16 *return$) noexcept {
  ::QList_u16 (*qlist_clone_u16$)(::QList_u16 const &) = ::rust::cxxqtlib1::construct;
  new (return$) ::QList_u16(qlist_clone_u16$(arg0));
}

void rust$cxxqtlib1$cxxbridge1$194$qlist_default_u16(::QList_u16 *return$) noexcept {
  ::QList_u16 (*qlist_default_u16$)() = ::rust::cxxqtlib1::construct;
  new (return$) ::QList_u16(qlist_default_u16$());
}

void rust$cxxqtlib1$cxxbridge1$194$qlist_drop_u16(::QList_u16 &arg0) noexcept {
  void (*qlist_drop_u16$)(::QList_u16 &) = ::rust::cxxqtlib1::drop;
  qlist_drop_u16$(arg0);
}
} // extern "C"

namespace qlist {
extern "C" {
void rust$cxxqtlib1$qlist$cxxbridge1$194$reserve_u16(::QList_u16 &arg0, ::rust::isize size) noexcept {
  void (*reserve_u16$)(::QList_u16 &, ::rust::isize) = ::rust::cxxqtlib1::qlist::qlistReserve;
  reserve_u16$(arg0, size);
}

void rust$cxxqtlib1$qlist$cxxbridge1$194$append_u16(::QList_u16 &arg0, ::std::uint16_t const &arg1) noexcept {
  void (*append_u16$)(::QList_u16 &, ::std::uint16_t const &) = ::rust::cxxqtlib1::qlist::qlistAppend;
  append_u16$(arg0, arg1);
}

::std::uint16_t const *rust$cxxqtlib1$qlist$cxxbridge1$194$get_unchecked_u16(::QList_u16 const &set, ::rust::isize pos) noexcept {
  ::std::uint16_t const &(*get_unchecked_u16$)(::QList_u16 const &, ::rust::isize) = ::rust::cxxqtlib1::qlist::qlistGetUnchecked;
  return &get_unchecked_u16$(set, pos);
}

::rust::isize rust$cxxqtlib1$qlist$cxxbridge1$194$index_of_u16(::QList_u16 const &arg0, ::std::uint16_t const &arg1) noexcept {
  ::rust::isize (*index_of_u16$)(::QList_u16 const &, ::std::uint16_t const &) = ::rust::cxxqtlib1::qlist::qlistIndexOf;
  return index_of_u16$(arg0, arg1);
}

void rust$cxxqtlib1$qlist$cxxbridge1$194$insert_u16(::QList_u16 &arg0, ::rust::isize arg1, ::std::uint16_t const &arg2) noexcept {
  void (*insert_u16$)(::QList_u16 &, ::rust::isize, ::std::uint16_t const &) = ::rust::cxxqtlib1::qlist::qlistInsert;
  insert_u16$(arg0, arg1, arg2);
}

::rust::isize rust$cxxqtlib1$qlist$cxxbridge1$194$len_u16(::QList_u16 const &arg0) noexcept {
  ::rust::isize (*len_u16$)(::QList_u16 const &) = ::rust::cxxqtlib1::qlist::qlistLen;
  return len_u16$(arg0);
}

void rust$cxxqtlib1$qlist$cxxbridge1$194$remove_u16(::QList_u16 &arg0, ::rust::isize arg1) noexcept {
  void (*remove_u16$)(::QList_u16 &, ::rust::isize) = ::rust::cxxqtlib1::qlist::qlistRemove;
  remove_u16$(arg0, arg1);
}
} // extern "C"
} // namespace qlist
} // namespace cxxqtlib1
} // namespace rust
