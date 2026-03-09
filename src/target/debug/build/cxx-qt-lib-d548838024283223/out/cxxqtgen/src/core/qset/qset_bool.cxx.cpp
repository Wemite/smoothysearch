#include "cxx-qt-lib/core/qset/qset_bool.h"
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
    ::rust::IsRelocatable<::QSet_bool>::value,
    "type QSet_bool should be trivially move constructible and trivially destructible in C++ to be used as a return value of `qset_clone_bool`, `qset_default_bool` in Rust");

extern "C" {
void cxxbridge1$194$QSet_bool$cxx_clear(::QSet_bool &self) noexcept {
  void (::QSet_bool::*cxx_clear$)() = &::QSet_bool::clear;
  (self.*cxx_clear$)();
}

bool cxxbridge1$194$QSet_bool$cxx_contains(::QSet_bool const &self, bool const &arg0) noexcept {
  bool (::QSet_bool::*cxx_contains$)(bool const &) const = &::QSet_bool::contains;
  return (self.*cxx_contains$)(arg0);
}

bool cxxbridge1$194$QSet_bool$cxx_remove(::QSet_bool &self, bool const &arg0) noexcept {
  bool (::QSet_bool::*cxx_remove$)(bool const &) = &::QSet_bool::remove;
  return (self.*cxx_remove$)(arg0);
}
} // extern "C"

namespace rust {
namespace cxxqtlib1 {
extern "C" {
void rust$cxxqtlib1$cxxbridge1$194$qset_clone_bool(::QSet_bool const &arg0, ::QSet_bool *return$) noexcept {
  ::QSet_bool (*qset_clone_bool$)(::QSet_bool const &) = ::rust::cxxqtlib1::construct;
  new (return$) ::QSet_bool(qset_clone_bool$(arg0));
}

void rust$cxxqtlib1$cxxbridge1$194$qset_default_bool(::QSet_bool *return$) noexcept {
  ::QSet_bool (*qset_default_bool$)() = ::rust::cxxqtlib1::construct;
  new (return$) ::QSet_bool(qset_default_bool$());
}

void rust$cxxqtlib1$cxxbridge1$194$qset_drop_bool(::QSet_bool &arg0) noexcept {
  void (*qset_drop_bool$)(::QSet_bool &) = ::rust::cxxqtlib1::drop;
  qset_drop_bool$(arg0);
}
} // extern "C"

namespace qset {
extern "C" {
bool const *rust$cxxqtlib1$qset$cxxbridge1$194$get_unchecked_bool(::QSet_bool const &set, ::rust::isize pos) noexcept {
  bool const &(*get_unchecked_bool$)(::QSet_bool const &, ::rust::isize) = ::rust::cxxqtlib1::qset::qsetGetUnchecked;
  return &get_unchecked_bool$(set, pos);
}

void rust$cxxqtlib1$qset$cxxbridge1$194$insert_bool(::QSet_bool &arg0, bool const &arg1) noexcept {
  void (*insert_bool$)(::QSet_bool &, bool const &) = ::rust::cxxqtlib1::qset::qsetInsert;
  insert_bool$(arg0, arg1);
}

::rust::isize rust$cxxqtlib1$qset$cxxbridge1$194$len_bool(::QSet_bool const &arg0) noexcept {
  ::rust::isize (*len_bool$)(::QSet_bool const &) = ::rust::cxxqtlib1::qset::qsetLen;
  return len_bool$(arg0);
}

void rust$cxxqtlib1$qset$cxxbridge1$194$reserve_bool(::QSet_bool &arg0, ::rust::isize size) noexcept {
  void (*reserve_bool$)(::QSet_bool &, ::rust::isize) = ::rust::cxxqtlib1::qset::qsetReserve;
  reserve_bool$(arg0, size);
}
} // extern "C"
} // namespace qset
} // namespace cxxqtlib1
} // namespace rust
