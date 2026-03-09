#include "cxx-qt/connection.h"
#include <cstdint>
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

namespace Qt {
  using ConnectionType = ::Qt::ConnectionType;
}

namespace Qt {
static_assert(::std::is_enum<ConnectionType>::value, "expected enum");
static_assert(sizeof(ConnectionType) == sizeof(::std::int32_t), "incorrect size");
static_assert(static_cast<::std::int32_t>(ConnectionType::AutoConnection) == 0, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(ConnectionType::DirectConnection) == 1, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(ConnectionType::QueuedConnection) == 2, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(ConnectionType::BlockingQueuedConnection) == 3, "disagrees with the value in #[cxx::bridge]");
} // namespace Qt

static_assert(
    ::rust::IsRelocatable<::rust::cxxqt1::QMetaObjectConnection>::value,
    "type rust::cxxqt1::QMetaObjectConnection should be trivially move constructible and trivially destructible in C++ to be used as a return value of `qmetaobjectconnection_default` in Rust");

namespace rust {
namespace cxxqt1 {
extern "C" {
void rust$cxxqt1$cxxbridge1$194$qmetaobjectconnection_default(::rust::cxxqt1::QMetaObjectConnection *return$) noexcept {
  ::rust::cxxqt1::QMetaObjectConnection (*qmetaobjectconnection_default$)() = ::rust::cxxqt1::qmetaobjectconnectionDefault;
  new (return$) ::rust::cxxqt1::QMetaObjectConnection(qmetaobjectconnection_default$());
}

bool rust$cxxqt1$cxxbridge1$194$qmetaobjectconnection_disconnect(::rust::cxxqt1::QMetaObjectConnection const &connection) noexcept {
  bool (*qmetaobjectconnection_disconnect$)(::rust::cxxqt1::QMetaObjectConnection const &) = ::rust::cxxqt1::qmetaobjectconnectionDisconnect;
  return qmetaobjectconnection_disconnect$(connection);
}

void rust$cxxqt1$cxxbridge1$194$qmetaobjectconnection_drop(::rust::cxxqt1::QMetaObjectConnection &connection) noexcept {
  void (*qmetaobjectconnection_drop$)(::rust::cxxqt1::QMetaObjectConnection &) = ::rust::cxxqt1::qmetaobjectconnectionDrop;
  qmetaobjectconnection_drop$(connection);
}
} // extern "C"
} // namespace cxxqt1
} // namespace rust
