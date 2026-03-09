#include "cxx-qt-lib/core/qvector/qvector_u8.h"
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
    ::rust::IsRelocatable<::QVector_u8>::value,
    "type QVector_u8 should be trivially move constructible and trivially destructible in C++ to be used as a return value of `qvector_clone_u8`, `qvector_default_u8` in Rust");

extern "C" {
void cxxbridge1$194$QVector_u8$cxx_clear(::QVector_u8 &self) noexcept {
  void (::QVector_u8::*cxx_clear$)() = &::QVector_u8::clear;
  (self.*cxx_clear$)();
}

bool cxxbridge1$194$QVector_u8$cxx_contains(::QVector_u8 const &self, ::std::uint8_t const &arg0) noexcept {
  bool (::QVector_u8::*cxx_contains$)(::std::uint8_t const &) const = &::QVector_u8::contains;
  return (self.*cxx_contains$)(arg0);
}
} // extern "C"

namespace rust {
namespace cxxqtlib1 {
extern "C" {
void rust$cxxqtlib1$cxxbridge1$194$qvector_clone_u8(::QVector_u8 const &arg0, ::QVector_u8 *return$) noexcept {
  ::QVector_u8 (*qvector_clone_u8$)(::QVector_u8 const &) = ::rust::cxxqtlib1::construct;
  new (return$) ::QVector_u8(qvector_clone_u8$(arg0));
}

void rust$cxxqtlib1$cxxbridge1$194$qvector_default_u8(::QVector_u8 *return$) noexcept {
  ::QVector_u8 (*qvector_default_u8$)() = ::rust::cxxqtlib1::construct;
  new (return$) ::QVector_u8(qvector_default_u8$());
}

void rust$cxxqtlib1$cxxbridge1$194$qvector_drop_u8(::QVector_u8 &arg0) noexcept {
  void (*qvector_drop_u8$)(::QVector_u8 &) = ::rust::cxxqtlib1::drop;
  qvector_drop_u8$(arg0);
}
} // extern "C"

namespace qvector {
extern "C" {
void rust$cxxqtlib1$qvector$cxxbridge1$194$reserve_u8(::QVector_u8 &arg0, ::rust::isize size) noexcept {
  void (*reserve_u8$)(::QVector_u8 &, ::rust::isize) = ::rust::cxxqtlib1::qvector::qvectorReserve;
  reserve_u8$(arg0, size);
}

void rust$cxxqtlib1$qvector$cxxbridge1$194$append_u8(::QVector_u8 &arg0, ::std::uint8_t const &arg1) noexcept {
  void (*append_u8$)(::QVector_u8 &, ::std::uint8_t const &) = ::rust::cxxqtlib1::qvector::qvectorAppend;
  append_u8$(arg0, arg1);
}

::std::uint8_t const *rust$cxxqtlib1$qvector$cxxbridge1$194$get_unchecked_u8(::QVector_u8 const &set, ::rust::isize pos) noexcept {
  ::std::uint8_t const &(*get_unchecked_u8$)(::QVector_u8 const &, ::rust::isize) = ::rust::cxxqtlib1::qvector::qvectorGetUnchecked;
  return &get_unchecked_u8$(set, pos);
}

::rust::isize rust$cxxqtlib1$qvector$cxxbridge1$194$index_of_u8(::QVector_u8 const &arg0, ::std::uint8_t const &arg1) noexcept {
  ::rust::isize (*index_of_u8$)(::QVector_u8 const &, ::std::uint8_t const &) = ::rust::cxxqtlib1::qvector::qvectorIndexOf;
  return index_of_u8$(arg0, arg1);
}

void rust$cxxqtlib1$qvector$cxxbridge1$194$insert_u8(::QVector_u8 &arg0, ::rust::isize arg1, ::std::uint8_t const &arg2) noexcept {
  void (*insert_u8$)(::QVector_u8 &, ::rust::isize, ::std::uint8_t const &) = ::rust::cxxqtlib1::qvector::qvectorInsert;
  insert_u8$(arg0, arg1, arg2);
}

::rust::isize rust$cxxqtlib1$qvector$cxxbridge1$194$len_u8(::QVector_u8 const &arg0) noexcept {
  ::rust::isize (*len_u8$)(::QVector_u8 const &) = ::rust::cxxqtlib1::qvector::qvectorLen;
  return len_u8$(arg0);
}

void rust$cxxqtlib1$qvector$cxxbridge1$194$remove_u8(::QVector_u8 &arg0, ::rust::isize arg1) noexcept {
  void (*remove_u8$)(::QVector_u8 &, ::rust::isize) = ::rust::cxxqtlib1::qvector::qvectorRemove;
  remove_u8$(arg0, arg1);
}
} // extern "C"
} // namespace qvector
} // namespace cxxqtlib1
} // namespace rust
