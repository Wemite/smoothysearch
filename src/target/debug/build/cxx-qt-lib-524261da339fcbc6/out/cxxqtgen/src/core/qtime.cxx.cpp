#include "cxx-qt-lib/qt.h"
#include "cxx-qt-lib/qtime.h"
#include "cxx-qt-lib/qstring.h"
#include "cxx-qt-lib/common.h"
#include <cstdint>
#include <new>
#include <type_traits>
#include <utility>

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
    ::rust::IsRelocatable<::Qt::DateFormat>::value,
    "type Qt::DateFormat should be trivially move constructible and trivially destructible in C++ to be used as an argument of `format_enum`, `qtime_from_string_enum` in Rust");
static_assert(
    ::rust::IsRelocatable<::QTime>::value,
    "type QTime should be trivially move constructible and trivially destructible in C++ to be used as an argument of `qtime_msecs_to`, `qtime_secs_to` or return value of `add_msecs`, `add_secs`, `qtime_current_time` in Rust");
static_assert(
    ::rust::IsRelocatable<::QString>::value,
    "type QString should be trivially move constructible and trivially destructible in C++ to be used as a return value of `format`, `format_enum`, `qtime_to_debug_qstring` in Rust");

extern "C" {
void cxxbridge1$194$QTime$add_msecs(::QTime const &self, ::std::int32_t ms, ::QTime *return$) noexcept {
  ::QTime (::QTime::*add_msecs$)(::std::int32_t) const = &::QTime::addMSecs;
  new (return$) ::QTime((self.*add_msecs$)(ms));
}

void cxxbridge1$194$QTime$add_secs(::QTime const &self, ::std::int32_t s, ::QTime *return$) noexcept {
  ::QTime (::QTime::*add_secs$)(::std::int32_t) const = &::QTime::addSecs;
  new (return$) ::QTime((self.*add_secs$)(s));
}

::std::int32_t cxxbridge1$194$QTime$hour(::QTime const &self) noexcept {
  ::std::int32_t (::QTime::*hour$)() const = &::QTime::hour;
  return (self.*hour$)();
}

bool cxxbridge1$194$QTime$is_null(::QTime const &self) noexcept {
  bool (::QTime::*is_null$)() const = &::QTime::isNull;
  return (self.*is_null$)();
}

bool cxxbridge1$194$QTime$is_valid(::QTime const &self) noexcept {
  bool (::QTime::*is_valid$)() const = &::QTime::isValid;
  return (self.*is_valid$)();
}

::std::int32_t cxxbridge1$194$QTime$minute(::QTime const &self) noexcept {
  ::std::int32_t (::QTime::*minute$)() const = &::QTime::minute;
  return (self.*minute$)();
}

::std::int32_t cxxbridge1$194$QTime$msec(::QTime const &self) noexcept {
  ::std::int32_t (::QTime::*msec$)() const = &::QTime::msec;
  return (self.*msec$)();
}

::std::int32_t cxxbridge1$194$QTime$msecs_since_start_of_day(::QTime const &self) noexcept {
  ::std::int32_t (::QTime::*msecs_since_start_of_day$)() const = &::QTime::msecsSinceStartOfDay;
  return (self.*msecs_since_start_of_day$)();
}

::std::int32_t cxxbridge1$194$QTime$second(::QTime const &self) noexcept {
  ::std::int32_t (::QTime::*second$)() const = &::QTime::second;
  return (self.*second$)();
}

bool cxxbridge1$194$QTime$set_hms(::QTime &self, ::std::int32_t h, ::std::int32_t m, ::std::int32_t s, ::std::int32_t ms) noexcept {
  bool (::QTime::*set_hms$)(::std::int32_t, ::std::int32_t, ::std::int32_t, ::std::int32_t) = &::QTime::setHMS;
  return (self.*set_hms$)(h, m, s, ms);
}

void cxxbridge1$194$QTime$format(::QTime const &self, ::QString const &format, ::QString *return$) noexcept {
  ::QString (::QTime::*format$)(::QString const &) const = &::QTime::toString;
  new (return$) ::QString((self.*format$)(format));
}

void cxxbridge1$194$QTime$format_enum(::QTime const &self, ::Qt::DateFormat *format, ::QString *return$) noexcept {
  ::QString (::QTime::*format_enum$)(::Qt::DateFormat) const = &::QTime::toString;
  new (return$) ::QString((self.*format_enum$)(::std::move(*format)));
}
} // extern "C"

namespace rust {
namespace cxxqtlib1 {
extern "C" {
void rust$cxxqtlib1$cxxbridge1$194$qtime_current_time(::QTime *return$) noexcept {
  ::QTime (*qtime_current_time$)() = ::rust::cxxqtlib1::qtimeCurrentTime;
  new (return$) ::QTime(qtime_current_time$());
}

void rust$cxxqtlib1$cxxbridge1$194$qtime_from_msecs_since_start_of_day(::std::int32_t msecs, ::QTime *return$) noexcept {
  ::QTime (*qtime_from_msecs_since_start_of_day$)(::std::int32_t) = ::rust::cxxqtlib1::qtimeFromMSecsSinceStartOfDay;
  new (return$) ::QTime(qtime_from_msecs_since_start_of_day$(msecs));
}

void rust$cxxqtlib1$cxxbridge1$194$qtime_from_string(::QString const &string, ::QString const &format, ::QTime *return$) noexcept {
  ::QTime (*qtime_from_string$)(::QString const &, ::QString const &) = ::rust::cxxqtlib1::qtimeFromString;
  new (return$) ::QTime(qtime_from_string$(string, format));
}

void rust$cxxqtlib1$cxxbridge1$194$qtime_from_string_enum(::QString const &string, ::Qt::DateFormat *format, ::QTime *return$) noexcept {
  ::QTime (*qtime_from_string_enum$)(::QString const &, ::Qt::DateFormat) = ::rust::cxxqtlib1::qtimeFromString;
  new (return$) ::QTime(qtime_from_string_enum$(string, ::std::move(*format)));
}

::std::int32_t rust$cxxqtlib1$cxxbridge1$194$qtime_msecs_to(::QTime const &time, ::QTime *t) noexcept {
  ::std::int32_t (*qtime_msecs_to$)(::QTime const &, ::QTime) = ::rust::cxxqtlib1::qtimeMSecsTo;
  return qtime_msecs_to$(time, ::std::move(*t));
}

::std::int32_t rust$cxxqtlib1$cxxbridge1$194$qtime_secs_to(::QTime const &time, ::QTime *t) noexcept {
  ::std::int32_t (*qtime_secs_to$)(::QTime const &, ::QTime) = ::rust::cxxqtlib1::qtimeSecsTo;
  return qtime_secs_to$(time, ::std::move(*t));
}

bool rust$cxxqtlib1$cxxbridge1$194$qtime_is_valid(::std::int32_t h, ::std::int32_t m, ::std::int32_t s, ::std::int32_t ms) noexcept {
  bool (*qtime_is_valid$)(::std::int32_t, ::std::int32_t, ::std::int32_t, ::std::int32_t) = ::rust::cxxqtlib1::qtimeIsValid;
  return qtime_is_valid$(h, m, s, ms);
}

void rust$cxxqtlib1$cxxbridge1$194$qtime_init_default(::QTime *return$) noexcept {
  ::QTime (*qtime_init_default$)() = ::rust::cxxqtlib1::construct;
  new (return$) ::QTime(qtime_init_default$());
}

void rust$cxxqtlib1$cxxbridge1$194$qtime_init(::std::int32_t h, ::std::int32_t m, ::std::int32_t s, ::std::int32_t ms, ::QTime *return$) noexcept {
  ::QTime (*qtime_init$)(::std::int32_t, ::std::int32_t, ::std::int32_t, ::std::int32_t) = ::rust::cxxqtlib1::construct;
  new (return$) ::QTime(qtime_init$(h, m, s, ms));
}

void rust$cxxqtlib1$cxxbridge1$194$qtime_to_debug_qstring(::QTime const &value, ::QString *return$) noexcept {
  ::QString (*qtime_to_debug_qstring$)(::QTime const &) = ::rust::cxxqtlib1::toDebugQString;
  new (return$) ::QString(qtime_to_debug_qstring$(value));
}
} // extern "C"
} // namespace cxxqtlib1
} // namespace rust
