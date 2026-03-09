#include "cxx-qt-lib/qstring.h"
#include "cxx-qt-lib/qvariant.h"
#include "cxx-qt-lib/core/qmap/qmap_QString_QVariant.h"
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
    ::rust::IsRelocatable<::QVariant>::value,
    "type QVariant should be trivially move constructible and trivially destructible in C++ to be used as a return value of `get_or_default_QString_QVariant` in Rust");
static_assert(
    ::rust::IsRelocatable<::QMap_QString_QVariant>::value,
    "type QMap_QString_QVariant should be trivially move constructible and trivially destructible in C++ to be used as a return value of `qmap_clone_QString_QVariant`, `qmap_default_QString_QVariant` in Rust");

extern "C" {
void cxxbridge1$194$QMap_QString_QVariant$cxx_clear(::QMap_QString_QVariant &self) noexcept {
  void (::QMap_QString_QVariant::*cxx_clear$)() = &::QMap_QString_QVariant::clear;
  (self.*cxx_clear$)();
}

bool cxxbridge1$194$QMap_QString_QVariant$cxx_contains(::QMap_QString_QVariant const &self, ::QString const &key) noexcept {
  bool (::QMap_QString_QVariant::*cxx_contains$)(::QString const &) const = &::QMap_QString_QVariant::contains;
  return (self.*cxx_contains$)(key);
}
} // extern "C"

namespace rust {
namespace cxxqtlib1 {
extern "C" {
void rust$cxxqtlib1$cxxbridge1$194$qmap_clone_QString_QVariant(::QMap_QString_QVariant const &arg0, ::QMap_QString_QVariant *return$) noexcept {
  ::QMap_QString_QVariant (*qmap_clone_QString_QVariant$)(::QMap_QString_QVariant const &) = ::rust::cxxqtlib1::construct;
  new (return$) ::QMap_QString_QVariant(qmap_clone_QString_QVariant$(arg0));
}

void rust$cxxqtlib1$cxxbridge1$194$qmap_default_QString_QVariant(::QMap_QString_QVariant *return$) noexcept {
  ::QMap_QString_QVariant (*qmap_default_QString_QVariant$)() = ::rust::cxxqtlib1::construct;
  new (return$) ::QMap_QString_QVariant(qmap_default_QString_QVariant$());
}

void rust$cxxqtlib1$cxxbridge1$194$qmap_drop_QString_QVariant(::QMap_QString_QVariant &arg0) noexcept {
  void (*qmap_drop_QString_QVariant$)(::QMap_QString_QVariant &) = ::rust::cxxqtlib1::drop;
  qmap_drop_QString_QVariant$(arg0);
}
} // extern "C"

namespace qmap {
extern "C" {
void rust$cxxqtlib1$qmap$cxxbridge1$194$get_or_default_QString_QVariant(::QMap_QString_QVariant const &arg0, ::QString const &key, ::QVariant *return$) noexcept {
  ::QVariant (*get_or_default_QString_QVariant$)(::QMap_QString_QVariant const &, ::QString const &) = ::rust::cxxqtlib1::qmap::qmapGetOrDefault;
  new (return$) ::QVariant(get_or_default_QString_QVariant$(arg0, key));
}

::QString const *rust$cxxqtlib1$qmap$cxxbridge1$194$get_unchecked_key_QString_QVariant(::QMap_QString_QVariant const &arg0, ::rust::isize pos) noexcept {
  ::QString const &(*get_unchecked_key_QString_QVariant$)(::QMap_QString_QVariant const &, ::rust::isize) = ::rust::cxxqtlib1::qmap::qmapGetUncheckedKey;
  return &get_unchecked_key_QString_QVariant$(arg0, pos);
}

void rust$cxxqtlib1$qmap$cxxbridge1$194$get_unchecked_value_QString_QVariant(::QMap_QString_QVariant const &arg0, ::rust::isize pos, ::QVariant const **return$) noexcept {
  ::QVariant const &(*get_unchecked_value_QString_QVariant$)(::QMap_QString_QVariant const &, ::rust::isize) = ::rust::cxxqtlib1::qmap::qmapGetUncheckedValue;
  new (return$) ::QVariant const *(&get_unchecked_value_QString_QVariant$(arg0, pos));
}

void rust$cxxqtlib1$qmap$cxxbridge1$194$insert_QString_QVariant(::QMap_QString_QVariant &arg0, ::QString const &key, ::QVariant const &value) noexcept {
  void (*insert_QString_QVariant$)(::QMap_QString_QVariant &, ::QString const &, ::QVariant const &) = ::rust::cxxqtlib1::qmap::qmapInsert;
  insert_QString_QVariant$(arg0, key, value);
}

::rust::isize rust$cxxqtlib1$qmap$cxxbridge1$194$len_QString_QVariant(::QMap_QString_QVariant const &arg0) noexcept {
  ::rust::isize (*len_QString_QVariant$)(::QMap_QString_QVariant const &) = ::rust::cxxqtlib1::qmap::qmapLen;
  return len_QString_QVariant$(arg0);
}

bool rust$cxxqtlib1$qmap$cxxbridge1$194$remove_QString_QVariant(::QMap_QString_QVariant &arg0, ::QString const &key) noexcept {
  bool (*remove_QString_QVariant$)(::QMap_QString_QVariant &, ::QString const &) = ::rust::cxxqtlib1::qmap::qmapRemove;
  return remove_QString_QVariant$(arg0, key);
}
} // extern "C"
} // namespace qmap
} // namespace cxxqtlib1
} // namespace rust
