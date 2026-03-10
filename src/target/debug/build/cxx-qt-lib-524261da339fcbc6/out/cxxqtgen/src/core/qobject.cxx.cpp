#include "cxx-qt-lib/qstring.h"
#include "cxx-qt-lib/qobject.h"
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

using QObject = ::QObject;

static_assert(
    ::rust::IsRelocatable<::QString>::value,
    "type QString should be trivially move constructible and trivially destructible in C++ to be used as a return value of `object_name` in Rust");

extern "C" {
bool cxxbridge1$194$QObject$block_signals(::QObject &self, bool block) noexcept {
  bool (::QObject::*block_signals$)(bool) = &::QObject::blockSignals;
  return (self.*block_signals$)(block);
}

bool cxxbridge1$194$QObject$signals_blocked(::QObject const &self) noexcept {
  bool (::QObject::*signals_blocked$)() const = &::QObject::signalsBlocked;
  return (self.*signals_blocked$)();
}

void cxxbridge1$194$QObject$set_object_name(::QObject &self, ::QString const &name) noexcept {
  void (::QObject::*set_object_name$)(::QString const &) = &::QObject::setObjectName;
  (self.*set_object_name$)(name);
}

void cxxbridge1$194$QObject$object_name(::QObject const &self, ::QString *return$) noexcept {
  ::QString (::QObject::*object_name$)() const = &::QObject::objectName;
  new (return$) ::QString((self.*object_name$)());
}

::QObject *cxxbridge1$194$QObject$parent(::QObject const &self) noexcept {
  ::QObject *(::QObject::*parent$)() const = &::QObject::parent;
  return (self.*parent$)();
}

void cxxbridge1$194$QObject$set_parent(::QObject &self, ::QObject *parent) noexcept {
  void (::QObject::*set_parent$)(::QObject *) = &::QObject::setParent;
  (self.*set_parent$)(parent);
}
} // extern "C"
