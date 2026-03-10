#include "cxx-qt-lib/qbytearray.h"
#include "cxx-qt-lib/qhash_i32_QByteArray.h"
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
    ::rust::IsRelocatable<::QByteArray>::value,
    "type QByteArray should be trivially move constructible and trivially destructible in C++ to be used as a return value of `get_or_default_i32_QByteArray` in Rust");
static_assert(
    ::rust::IsRelocatable<::QHash_i32_QByteArray>::value,
    "type QHash_i32_QByteArray should be trivially move constructible and trivially destructible in C++ to be used as a return value of `qhash_clone_i32_QByteArray`, `qhash_default_i32_QByteArray` in Rust");

extern "C" {
void cxxbridge1$194$QHash_i32_QByteArray$cxx_clear(::QHash_i32_QByteArray &self) noexcept {
  void (::QHash_i32_QByteArray::*cxx_clear$)() = &::QHash_i32_QByteArray::clear;
  (self.*cxx_clear$)();
}

bool cxxbridge1$194$QHash_i32_QByteArray$cxx_contains(::QHash_i32_QByteArray const &self, ::std::int32_t const &key) noexcept {
  bool (::QHash_i32_QByteArray::*cxx_contains$)(::std::int32_t const &) const = &::QHash_i32_QByteArray::contains;
  return (self.*cxx_contains$)(key);
}
} // extern "C"

namespace rust {
namespace cxxqtlib1 {
extern "C" {
void rust$cxxqtlib1$cxxbridge1$194$qhash_clone_i32_QByteArray(::QHash_i32_QByteArray const &arg0, ::QHash_i32_QByteArray *return$) noexcept {
  ::QHash_i32_QByteArray (*qhash_clone_i32_QByteArray$)(::QHash_i32_QByteArray const &) = ::rust::cxxqtlib1::construct;
  new (return$) ::QHash_i32_QByteArray(qhash_clone_i32_QByteArray$(arg0));
}

void rust$cxxqtlib1$cxxbridge1$194$qhash_default_i32_QByteArray(::QHash_i32_QByteArray *return$) noexcept {
  ::QHash_i32_QByteArray (*qhash_default_i32_QByteArray$)() = ::rust::cxxqtlib1::construct;
  new (return$) ::QHash_i32_QByteArray(qhash_default_i32_QByteArray$());
}

void rust$cxxqtlib1$cxxbridge1$194$qhash_drop_i32_QByteArray(::QHash_i32_QByteArray &arg0) noexcept {
  void (*qhash_drop_i32_QByteArray$)(::QHash_i32_QByteArray &) = ::rust::cxxqtlib1::drop;
  qhash_drop_i32_QByteArray$(arg0);
}
} // extern "C"

namespace qhash {
extern "C" {
void rust$cxxqtlib1$qhash$cxxbridge1$194$get_or_default_i32_QByteArray(::QHash_i32_QByteArray const &arg0, ::std::int32_t const &key, ::QByteArray *return$) noexcept {
  ::QByteArray (*get_or_default_i32_QByteArray$)(::QHash_i32_QByteArray const &, ::std::int32_t const &) = ::rust::cxxqtlib1::qhash::qhashGetOrDefault;
  new (return$) ::QByteArray(get_or_default_i32_QByteArray$(arg0, key));
}

::std::int32_t const *rust$cxxqtlib1$qhash$cxxbridge1$194$get_unchecked_key_i32_QByteArray(::QHash_i32_QByteArray const &arg0, ::rust::isize pos) noexcept {
  ::std::int32_t const &(*get_unchecked_key_i32_QByteArray$)(::QHash_i32_QByteArray const &, ::rust::isize) = ::rust::cxxqtlib1::qhash::qhashGetUncheckedKey;
  return &get_unchecked_key_i32_QByteArray$(arg0, pos);
}

void rust$cxxqtlib1$qhash$cxxbridge1$194$get_unchecked_value_i32_QByteArray(::QHash_i32_QByteArray const &arg0, ::rust::isize pos, ::QByteArray const **return$) noexcept {
  ::QByteArray const &(*get_unchecked_value_i32_QByteArray$)(::QHash_i32_QByteArray const &, ::rust::isize) = ::rust::cxxqtlib1::qhash::qhashGetUncheckedValue;
  new (return$) ::QByteArray const *(&get_unchecked_value_i32_QByteArray$(arg0, pos));
}

void rust$cxxqtlib1$qhash$cxxbridge1$194$insert_i32_QByteArray(::QHash_i32_QByteArray &arg0, ::std::int32_t const &key, ::QByteArray const &value) noexcept {
  void (*insert_i32_QByteArray$)(::QHash_i32_QByteArray &, ::std::int32_t const &, ::QByteArray const &) = ::rust::cxxqtlib1::qhash::qhashInsert;
  insert_i32_QByteArray$(arg0, key, value);
}

::rust::isize rust$cxxqtlib1$qhash$cxxbridge1$194$len_i32_QByteArray(::QHash_i32_QByteArray const &arg0) noexcept {
  ::rust::isize (*len_i32_QByteArray$)(::QHash_i32_QByteArray const &) = ::rust::cxxqtlib1::qhash::qhashLen;
  return len_i32_QByteArray$(arg0);
}

bool rust$cxxqtlib1$qhash$cxxbridge1$194$remove_i32_QByteArray(::QHash_i32_QByteArray &arg0, ::std::int32_t const &key) noexcept {
  bool (*remove_i32_QByteArray$)(::QHash_i32_QByteArray &, ::std::int32_t const &) = ::rust::cxxqtlib1::qhash::qhashRemove;
  return remove_i32_QByteArray$(arg0, key);
}
} // extern "C"
} // namespace qhash
} // namespace cxxqtlib1
} // namespace rust
