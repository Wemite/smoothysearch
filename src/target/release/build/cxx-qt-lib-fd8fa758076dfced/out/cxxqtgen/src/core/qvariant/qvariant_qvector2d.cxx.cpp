#include "cxx-qt-lib/qvector2d.h"
#include "cxx-qt-lib/qvariant.h"
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
    ::rust::IsRelocatable<::QVector2D>::value,
    "type QVector2D should be trivially move constructible and trivially destructible in C++ to be used as a return value of `value_or_default_QVector2D` in Rust");
static_assert(
    ::rust::IsRelocatable<::QVariant>::value,
    "type QVariant should be trivially move constructible and trivially destructible in C++ to be used as a return value of `construct_QVector2D` in Rust");

namespace rust {
namespace cxxqtlib1 {
namespace qvariant {
extern "C" {
bool rust$cxxqtlib1$qvariant$cxxbridge1$194$can_convert_QVector2D(::QVariant const &variant) noexcept {
  bool (*can_convert_QVector2D$)(::QVariant const &) = ::rust::cxxqtlib1::qvariant::qvariantCanConvertQVector2D;
  return can_convert_QVector2D$(variant);
}

void rust$cxxqtlib1$qvariant$cxxbridge1$194$construct_QVector2D(::QVector2D const &value, ::QVariant *return$) noexcept {
  ::QVariant (*construct_QVector2D$)(::QVector2D const &) = ::rust::cxxqtlib1::qvariant::qvariantConstruct;
  new (return$) ::QVariant(construct_QVector2D$(value));
}

void rust$cxxqtlib1$qvariant$cxxbridge1$194$value_or_default_QVector2D(::QVariant const &variant, ::QVector2D *return$) noexcept {
  ::QVector2D (*value_or_default_QVector2D$)(::QVariant const &) = ::rust::cxxqtlib1::qvariant::qvariantValueOrDefault;
  new (return$) ::QVector2D(value_or_default_QVector2D$(variant));
}
} // extern "C"
} // namespace qvariant
} // namespace cxxqtlib1
} // namespace rust
