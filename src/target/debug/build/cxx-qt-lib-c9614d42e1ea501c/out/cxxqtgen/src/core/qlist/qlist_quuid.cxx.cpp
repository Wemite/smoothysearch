#include "cxx-qt-lib/quuid.h"
#include "cxx-qt-lib/core/qlist/qlist_QUuid.h"
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
    ::rust::IsRelocatable<::QList_QUuid>::value,
    "type QList_QUuid should be trivially move constructible and trivially destructible in C++ to be used as a return value of `qlist_clone_QUuid`, `qlist_default_QUuid` in Rust");

extern "C" {
void cxxbridge1$194$QList_QUuid$cxx_clear(::QList_QUuid &self) noexcept {
  void (::QList_QUuid::*cxx_clear$)() = &::QList_QUuid::clear;
  (self.*cxx_clear$)();
}

bool cxxbridge1$194$QList_QUuid$cxx_contains(::QList_QUuid const &self, ::QUuid const &arg0) noexcept {
  bool (::QList_QUuid::*cxx_contains$)(::QUuid const &) const = &::QList_QUuid::contains;
  return (self.*cxx_contains$)(arg0);
}
} // extern "C"

namespace rust {
namespace cxxqtlib1 {
extern "C" {
void rust$cxxqtlib1$cxxbridge1$194$qlist_clone_QUuid(::QList_QUuid const &arg0, ::QList_QUuid *return$) noexcept {
  ::QList_QUuid (*qlist_clone_QUuid$)(::QList_QUuid const &) = ::rust::cxxqtlib1::construct;
  new (return$) ::QList_QUuid(qlist_clone_QUuid$(arg0));
}

void rust$cxxqtlib1$cxxbridge1$194$qlist_default_QUuid(::QList_QUuid *return$) noexcept {
  ::QList_QUuid (*qlist_default_QUuid$)() = ::rust::cxxqtlib1::construct;
  new (return$) ::QList_QUuid(qlist_default_QUuid$());
}

void rust$cxxqtlib1$cxxbridge1$194$qlist_drop_QUuid(::QList_QUuid &arg0) noexcept {
  void (*qlist_drop_QUuid$)(::QList_QUuid &) = ::rust::cxxqtlib1::drop;
  qlist_drop_QUuid$(arg0);
}
} // extern "C"

namespace qlist {
extern "C" {
void rust$cxxqtlib1$qlist$cxxbridge1$194$reserve_QUuid(::QList_QUuid &arg0, ::rust::isize size) noexcept {
  void (*reserve_QUuid$)(::QList_QUuid &, ::rust::isize) = ::rust::cxxqtlib1::qlist::qlistReserve;
  reserve_QUuid$(arg0, size);
}

void rust$cxxqtlib1$qlist$cxxbridge1$194$append_QUuid(::QList_QUuid &arg0, ::QUuid const &arg1) noexcept {
  void (*append_QUuid$)(::QList_QUuid &, ::QUuid const &) = ::rust::cxxqtlib1::qlist::qlistAppend;
  append_QUuid$(arg0, arg1);
}

void rust$cxxqtlib1$qlist$cxxbridge1$194$get_unchecked_QUuid(::QList_QUuid const &set, ::rust::isize pos, ::QUuid const **return$) noexcept {
  ::QUuid const &(*get_unchecked_QUuid$)(::QList_QUuid const &, ::rust::isize) = ::rust::cxxqtlib1::qlist::qlistGetUnchecked;
  new (return$) ::QUuid const *(&get_unchecked_QUuid$(set, pos));
}

::rust::isize rust$cxxqtlib1$qlist$cxxbridge1$194$index_of_QUuid(::QList_QUuid const &arg0, ::QUuid const &arg1) noexcept {
  ::rust::isize (*index_of_QUuid$)(::QList_QUuid const &, ::QUuid const &) = ::rust::cxxqtlib1::qlist::qlistIndexOf;
  return index_of_QUuid$(arg0, arg1);
}

void rust$cxxqtlib1$qlist$cxxbridge1$194$insert_QUuid(::QList_QUuid &arg0, ::rust::isize arg1, ::QUuid const &arg2) noexcept {
  void (*insert_QUuid$)(::QList_QUuid &, ::rust::isize, ::QUuid const &) = ::rust::cxxqtlib1::qlist::qlistInsert;
  insert_QUuid$(arg0, arg1, arg2);
}

void rust$cxxqtlib1$qlist$cxxbridge1$194$remove_QUuid(::QList_QUuid &arg0, ::rust::isize arg1) noexcept {
  void (*remove_QUuid$)(::QList_QUuid &, ::rust::isize) = ::rust::cxxqtlib1::qlist::qlistRemove;
  remove_QUuid$(arg0, arg1);
}

::rust::isize rust$cxxqtlib1$qlist$cxxbridge1$194$len_QUuid(::QList_QUuid const &arg0) noexcept {
  ::rust::isize (*len_QUuid$)(::QList_QUuid const &) = ::rust::cxxqtlib1::qlist::qlistLen;
  return len_QUuid$(arg0);
}
} // extern "C"
} // namespace qlist
} // namespace cxxqtlib1
} // namespace rust
