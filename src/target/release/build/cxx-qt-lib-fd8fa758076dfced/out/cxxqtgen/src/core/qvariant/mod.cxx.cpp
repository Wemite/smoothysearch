#include "cxx-qt-lib/qstring.h"
#include "cxx-qt-lib/qvariant.h"
#include "cxx-qt-lib/common.h"
#include <new>
#include <type_traits>

#ifdef __GNUC__
#pragma GCC diagnostic ignored "-Wmissing-declarations"
#ifdef __clang__
#pragma clang diagnostic ignored "-Wdollar-in-identifier-extension"
#endif // __clang__
#endif // __GNUC__

namespace rust {
inline namespace cxxbridge1 {
// #include "rust/cxx.h"

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
    ::rust::IsRelocatable<::QString>::value,
    "type QString should be trivially move constructible and trivially destructible in C++ to be used as a return value of `qvariant_to_debug_qstring` in Rust");
static_assert(
    ::rust::IsRelocatable<::QVariant>::value,
    "type QVariant should be trivially move constructible and trivially destructible in C++ to be used as a return value of `qvariant_default`, `qvariant_clone` in Rust");

extern "C" {
void cxxbridge1$194$QVariant$clear(::QVariant &self) noexcept {
  void (::QVariant::*clear$)() = &::QVariant::clear;
  (self.*clear$)();
}

bool cxxbridge1$194$QVariant$is_null(::QVariant const &self) noexcept {
  bool (::QVariant::*is_null$)() const = &::QVariant::isNull;
  return (self.*is_null$)();
}

bool cxxbridge1$194$QVariant$is_valid(::QVariant const &self) noexcept {
  bool (::QVariant::*is_valid$)() const = &::QVariant::isValid;
  return (self.*is_valid$)();
}
} // extern "C"

namespace rust {
namespace cxxqtlib1 {
extern "C" {
void rust$cxxqtlib1$cxxbridge1$194$qvariant_drop(::QVariant &variant) noexcept {
  void (*qvariant_drop$)(::QVariant &) = ::rust::cxxqtlib1::drop;
  qvariant_drop$(variant);
}

void rust$cxxqtlib1$cxxbridge1$194$qvariant_default(::QVariant *return$) noexcept {
  ::QVariant (*qvariant_default$)() = ::rust::cxxqtlib1::construct;
  new (return$) ::QVariant(qvariant_default$());
}

void rust$cxxqtlib1$cxxbridge1$194$qvariant_clone(::QVariant const &variant, ::QVariant *return$) noexcept {
  ::QVariant (*qvariant_clone$)(::QVariant const &) = ::rust::cxxqtlib1::construct;
  new (return$) ::QVariant(qvariant_clone$(variant));
}

bool rust$cxxqtlib1$cxxbridge1$194$qvariant_eq(::QVariant const &a, ::QVariant const &b) noexcept {
  bool (*qvariant_eq$)(::QVariant const &, ::QVariant const &) = ::rust::cxxqtlib1::operatorEq;
  return qvariant_eq$(a, b);
}

void rust$cxxqtlib1$cxxbridge1$194$qvariant_to_debug_qstring(::QVariant const &variant, ::QString *return$) noexcept {
  ::QString (*qvariant_to_debug_qstring$)(::QVariant const &) = ::rust::cxxqtlib1::toDebugQString;
  new (return$) ::QString(qvariant_to_debug_qstring$(variant));
}
} // extern "C"
} // namespace cxxqtlib1
} // namespace rust
