#include "cxx-qt-lib/qmargins.h"
#include "cxx-qt-lib/core/qlist/qlist_QMargins.h"
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
    ::rust::IsRelocatable<::QList_QMargins>::value,
    "type QList_QMargins should be trivially move constructible and trivially destructible in C++ to be used as a return value of `qlist_clone_QMargins`, `qlist_default_QMargins` in Rust");

extern "C" {
void cxxbridge1$194$QList_QMargins$cxx_clear(::QList_QMargins &self) noexcept {
  void (::QList_QMargins::*cxx_clear$)() = &::QList_QMargins::clear;
  (self.*cxx_clear$)();
}

bool cxxbridge1$194$QList_QMargins$cxx_contains(::QList_QMargins const &self, ::QMargins const &arg0) noexcept {
  bool (::QList_QMargins::*cxx_contains$)(::QMargins const &) const = &::QList_QMargins::contains;
  return (self.*cxx_contains$)(arg0);
}
} // extern "C"

namespace rust {
namespace cxxqtlib1 {
extern "C" {
void rust$cxxqtlib1$cxxbridge1$194$qlist_clone_QMargins(::QList_QMargins const &arg0, ::QList_QMargins *return$) noexcept {
  ::QList_QMargins (*qlist_clone_QMargins$)(::QList_QMargins const &) = ::rust::cxxqtlib1::construct;
  new (return$) ::QList_QMargins(qlist_clone_QMargins$(arg0));
}

void rust$cxxqtlib1$cxxbridge1$194$qlist_default_QMargins(::QList_QMargins *return$) noexcept {
  ::QList_QMargins (*qlist_default_QMargins$)() = ::rust::cxxqtlib1::construct;
  new (return$) ::QList_QMargins(qlist_default_QMargins$());
}

void rust$cxxqtlib1$cxxbridge1$194$qlist_drop_QMargins(::QList_QMargins &arg0) noexcept {
  void (*qlist_drop_QMargins$)(::QList_QMargins &) = ::rust::cxxqtlib1::drop;
  qlist_drop_QMargins$(arg0);
}
} // extern "C"

namespace qlist {
extern "C" {
void rust$cxxqtlib1$qlist$cxxbridge1$194$reserve_QMargins(::QList_QMargins &arg0, ::rust::isize size) noexcept {
  void (*reserve_QMargins$)(::QList_QMargins &, ::rust::isize) = ::rust::cxxqtlib1::qlist::qlistReserve;
  reserve_QMargins$(arg0, size);
}

void rust$cxxqtlib1$qlist$cxxbridge1$194$append_QMargins(::QList_QMargins &arg0, ::QMargins const &arg1) noexcept {
  void (*append_QMargins$)(::QList_QMargins &, ::QMargins const &) = ::rust::cxxqtlib1::qlist::qlistAppend;
  append_QMargins$(arg0, arg1);
}

void rust$cxxqtlib1$qlist$cxxbridge1$194$get_unchecked_QMargins(::QList_QMargins const &set, ::rust::isize pos, ::QMargins const **return$) noexcept {
  ::QMargins const &(*get_unchecked_QMargins$)(::QList_QMargins const &, ::rust::isize) = ::rust::cxxqtlib1::qlist::qlistGetUnchecked;
  new (return$) ::QMargins const *(&get_unchecked_QMargins$(set, pos));
}

::rust::isize rust$cxxqtlib1$qlist$cxxbridge1$194$index_of_QMargins(::QList_QMargins const &arg0, ::QMargins const &arg1) noexcept {
  ::rust::isize (*index_of_QMargins$)(::QList_QMargins const &, ::QMargins const &) = ::rust::cxxqtlib1::qlist::qlistIndexOf;
  return index_of_QMargins$(arg0, arg1);
}

void rust$cxxqtlib1$qlist$cxxbridge1$194$insert_QMargins(::QList_QMargins &arg0, ::rust::isize arg1, ::QMargins const &arg2) noexcept {
  void (*insert_QMargins$)(::QList_QMargins &, ::rust::isize, ::QMargins const &) = ::rust::cxxqtlib1::qlist::qlistInsert;
  insert_QMargins$(arg0, arg1, arg2);
}

void rust$cxxqtlib1$qlist$cxxbridge1$194$remove_QMargins(::QList_QMargins &arg0, ::rust::isize arg1) noexcept {
  void (*remove_QMargins$)(::QList_QMargins &, ::rust::isize) = ::rust::cxxqtlib1::qlist::qlistRemove;
  remove_QMargins$(arg0, arg1);
}

::rust::isize rust$cxxqtlib1$qlist$cxxbridge1$194$len_QMargins(::QList_QMargins const &arg0) noexcept {
  ::rust::isize (*len_QMargins$)(::QList_QMargins const &) = ::rust::cxxqtlib1::qlist::qlistLen;
  return len_QMargins$(arg0);
}
} // extern "C"
} // namespace qlist
} // namespace cxxqtlib1
} // namespace rust
