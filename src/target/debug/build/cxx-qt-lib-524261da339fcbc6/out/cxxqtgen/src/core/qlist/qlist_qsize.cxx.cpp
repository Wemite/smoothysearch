#include "cxx-qt-lib/qsize.h"
#include "cxx-qt-lib/core/qlist/qlist_QSize.h"
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
    ::rust::IsRelocatable<::QList_QSize>::value,
    "type QList_QSize should be trivially move constructible and trivially destructible in C++ to be used as a return value of `qlist_clone_QSize`, `qlist_default_QSize` in Rust");

extern "C" {
void cxxbridge1$194$QList_QSize$cxx_clear(::QList_QSize &self) noexcept {
  void (::QList_QSize::*cxx_clear$)() = &::QList_QSize::clear;
  (self.*cxx_clear$)();
}

bool cxxbridge1$194$QList_QSize$cxx_contains(::QList_QSize const &self, ::QSize const &arg0) noexcept {
  bool (::QList_QSize::*cxx_contains$)(::QSize const &) const = &::QList_QSize::contains;
  return (self.*cxx_contains$)(arg0);
}
} // extern "C"

namespace rust {
namespace cxxqtlib1 {
extern "C" {
void rust$cxxqtlib1$cxxbridge1$194$qlist_clone_QSize(::QList_QSize const &arg0, ::QList_QSize *return$) noexcept {
  ::QList_QSize (*qlist_clone_QSize$)(::QList_QSize const &) = ::rust::cxxqtlib1::construct;
  new (return$) ::QList_QSize(qlist_clone_QSize$(arg0));
}

void rust$cxxqtlib1$cxxbridge1$194$qlist_default_QSize(::QList_QSize *return$) noexcept {
  ::QList_QSize (*qlist_default_QSize$)() = ::rust::cxxqtlib1::construct;
  new (return$) ::QList_QSize(qlist_default_QSize$());
}

void rust$cxxqtlib1$cxxbridge1$194$qlist_drop_QSize(::QList_QSize &arg0) noexcept {
  void (*qlist_drop_QSize$)(::QList_QSize &) = ::rust::cxxqtlib1::drop;
  qlist_drop_QSize$(arg0);
}
} // extern "C"

namespace qlist {
extern "C" {
void rust$cxxqtlib1$qlist$cxxbridge1$194$reserve_QSize(::QList_QSize &arg0, ::rust::isize size) noexcept {
  void (*reserve_QSize$)(::QList_QSize &, ::rust::isize) = ::rust::cxxqtlib1::qlist::qlistReserve;
  reserve_QSize$(arg0, size);
}

void rust$cxxqtlib1$qlist$cxxbridge1$194$append_QSize(::QList_QSize &arg0, ::QSize const &arg1) noexcept {
  void (*append_QSize$)(::QList_QSize &, ::QSize const &) = ::rust::cxxqtlib1::qlist::qlistAppend;
  append_QSize$(arg0, arg1);
}

void rust$cxxqtlib1$qlist$cxxbridge1$194$get_unchecked_QSize(::QList_QSize const &set, ::rust::isize pos, ::QSize const **return$) noexcept {
  ::QSize const &(*get_unchecked_QSize$)(::QList_QSize const &, ::rust::isize) = ::rust::cxxqtlib1::qlist::qlistGetUnchecked;
  new (return$) ::QSize const *(&get_unchecked_QSize$(set, pos));
}

::rust::isize rust$cxxqtlib1$qlist$cxxbridge1$194$index_of_QSize(::QList_QSize const &arg0, ::QSize const &arg1) noexcept {
  ::rust::isize (*index_of_QSize$)(::QList_QSize const &, ::QSize const &) = ::rust::cxxqtlib1::qlist::qlistIndexOf;
  return index_of_QSize$(arg0, arg1);
}

void rust$cxxqtlib1$qlist$cxxbridge1$194$insert_QSize(::QList_QSize &arg0, ::rust::isize arg1, ::QSize const &arg2) noexcept {
  void (*insert_QSize$)(::QList_QSize &, ::rust::isize, ::QSize const &) = ::rust::cxxqtlib1::qlist::qlistInsert;
  insert_QSize$(arg0, arg1, arg2);
}

void rust$cxxqtlib1$qlist$cxxbridge1$194$remove_QSize(::QList_QSize &arg0, ::rust::isize arg1) noexcept {
  void (*remove_QSize$)(::QList_QSize &, ::rust::isize) = ::rust::cxxqtlib1::qlist::qlistRemove;
  remove_QSize$(arg0, arg1);
}

::rust::isize rust$cxxqtlib1$qlist$cxxbridge1$194$len_QSize(::QList_QSize const &arg0) noexcept {
  ::rust::isize (*len_QSize$)(::QList_QSize const &) = ::rust::cxxqtlib1::qlist::qlistLen;
  return len_QSize$(arg0);
}
} // extern "C"
} // namespace qlist
} // namespace cxxqtlib1
} // namespace rust
