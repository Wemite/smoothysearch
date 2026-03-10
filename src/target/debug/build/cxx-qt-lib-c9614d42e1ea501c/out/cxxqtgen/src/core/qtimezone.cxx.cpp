#include "cxx-qt-lib/qbytearray.h"
#include "cxx-qt-lib/qdatetime.h"
#include "cxx-qt-lib/core/qlist/qlist_QByteArray.h"
#include "cxx-qt-lib/qstring.h"
#include "cxx-qt-lib/qtimezone.h"
#include "cxx-qt-lib/common.h"
#include <cstddef>
#include <cstdint>
#include <memory>
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

#ifndef CXXBRIDGE1_IS_COMPLETE
#define CXXBRIDGE1_IS_COMPLETE
namespace detail {
namespace {
template <typename T, typename = std::size_t>
struct is_complete : std::false_type {};
template <typename T>
struct is_complete<T, decltype(sizeof(T))> : std::true_type {};
} // namespace
} // namespace detail
#endif // CXXBRIDGE1_IS_COMPLETE

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

namespace {
template <bool> struct deleter_if {
  template <typename T> void operator()(T *) {}
};
template <> struct deleter_if<true> {
  template <typename T> void operator()(T *ptr) { ptr->~T(); }
};
} // namespace
} // namespace cxxbridge1
} // namespace rust

using QTimeZone = ::QTimeZone;
using QTimeZoneNameType = ::QTimeZoneNameType;
using QTimeZoneTimeType = ::QTimeZoneTimeType;

static_assert(::std::is_enum<QTimeZoneNameType>::value, "expected enum");
static_assert(sizeof(QTimeZoneNameType) == sizeof(::std::int32_t), "incorrect size");
static_assert(static_cast<::std::int32_t>(QTimeZoneNameType::DefaultName) == 0, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QTimeZoneNameType::LongName) == 1, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QTimeZoneNameType::ShortName) == 2, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QTimeZoneNameType::OffsetName) == 3, "disagrees with the value in #[cxx::bridge]");

static_assert(::std::is_enum<QTimeZoneTimeType>::value, "expected enum");
static_assert(sizeof(QTimeZoneTimeType) == sizeof(::std::int32_t), "incorrect size");
static_assert(static_cast<::std::int32_t>(QTimeZoneTimeType::StandardTime) == 0, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QTimeZoneTimeType::DaylightTime) == 1, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QTimeZoneTimeType::GenericTime) == 2, "disagrees with the value in #[cxx::bridge]");

static_assert(
    ::rust::IsRelocatable<::QByteArray>::value,
    "type QByteArray should be trivially move constructible and trivially destructible in C++ to be used as a return value of `id`, `qtimezone_system_time_zone_id` in Rust");
static_assert(
    ::rust::IsRelocatable<::QList_QByteArray>::value,
    "type QList_QByteArray should be trivially move constructible and trivially destructible in C++ to be used as a return value of `qtimezone_available_time_zone_ids` in Rust");
static_assert(
    ::rust::IsRelocatable<::QString>::value,
    "type QString should be trivially move constructible and trivially destructible in C++ to be used as a return value of `abbreviation`, `comment`, `qtimezone_display_name` in Rust");

extern "C" {
void cxxbridge1$194$QTimeZone$abbreviation(::QTimeZone const &self, ::QDateTime const &at_date_time, ::QString *return$) noexcept {
  ::QString (::QTimeZone::*abbreviation$)(::QDateTime const &) const = &::QTimeZone::abbreviation;
  new (return$) ::QString((self.*abbreviation$)(at_date_time));
}

void cxxbridge1$194$QTimeZone$comment(::QTimeZone const &self, ::QString *return$) noexcept {
  ::QString (::QTimeZone::*comment$)() const = &::QTimeZone::comment;
  new (return$) ::QString((self.*comment$)());
}

::std::int32_t cxxbridge1$194$QTimeZone$daylight_time_offset(::QTimeZone const &self, ::QDateTime const &at_date_time) noexcept {
  ::std::int32_t (::QTimeZone::*daylight_time_offset$)(::QDateTime const &) const = &::QTimeZone::daylightTimeOffset;
  return (self.*daylight_time_offset$)(at_date_time);
}

bool cxxbridge1$194$QTimeZone$has_daylight_time(::QTimeZone const &self) noexcept {
  bool (::QTimeZone::*has_daylight_time$)() const = &::QTimeZone::hasDaylightTime;
  return (self.*has_daylight_time$)();
}

bool cxxbridge1$194$QTimeZone$has_transitions(::QTimeZone const &self) noexcept {
  bool (::QTimeZone::*has_transitions$)() const = &::QTimeZone::hasTransitions;
  return (self.*has_transitions$)();
}

void cxxbridge1$194$QTimeZone$id(::QTimeZone const &self, ::QByteArray *return$) noexcept {
  ::QByteArray (::QTimeZone::*id$)() const = &::QTimeZone::id;
  new (return$) ::QByteArray((self.*id$)());
}

bool cxxbridge1$194$QTimeZone$is_daylight_time(::QTimeZone const &self, ::QDateTime const &at_date_time) noexcept {
  bool (::QTimeZone::*is_daylight_time$)(::QDateTime const &) const = &::QTimeZone::isDaylightTime;
  return (self.*is_daylight_time$)(at_date_time);
}

bool cxxbridge1$194$QTimeZone$is_valid(::QTimeZone const &self) noexcept {
  bool (::QTimeZone::*is_valid$)() const = &::QTimeZone::isValid;
  return (self.*is_valid$)();
}

::std::int32_t cxxbridge1$194$QTimeZone$offset_from_utc(::QTimeZone const &self, ::QDateTime const &at_date_time) noexcept {
  ::std::int32_t (::QTimeZone::*offset_from_utc$)(::QDateTime const &) const = &::QTimeZone::offsetFromUtc;
  return (self.*offset_from_utc$)(at_date_time);
}

::std::int32_t cxxbridge1$194$QTimeZone$standard_time_offset(::QTimeZone const &self, ::QDateTime const &at_date_time) noexcept {
  ::std::int32_t (::QTimeZone::*standard_time_offset$)(::QDateTime const &) const = &::QTimeZone::standardTimeOffset;
  return (self.*standard_time_offset$)(at_date_time);
}
} // extern "C"

namespace rust {
namespace cxxqtlib1 {
extern "C" {
void rust$cxxqtlib1$cxxbridge1$194$qtimezone_available_time_zone_ids(::QList_QByteArray *return$) noexcept {
  ::QList_QByteArray (*qtimezone_available_time_zone_ids$)() = ::rust::cxxqtlib1::qtimezoneAvailableTimeZoneIds;
  new (return$) ::QList_QByteArray(qtimezone_available_time_zone_ids$());
}

::QTimeZone *rust$cxxqtlib1$cxxbridge1$194$qtimezone_clone(::QTimeZone const &timezone) noexcept {
  ::std::unique_ptr<::QTimeZone> (*qtimezone_clone$)(::QTimeZone const &) = ::rust::cxxqtlib1::qtimezoneClone;
  return qtimezone_clone$(timezone).release();
}

::QTimeZone *rust$cxxqtlib1$cxxbridge1$194$qtimezone_default() noexcept {
  ::std::unique_ptr<::QTimeZone> (*qtimezone_default$)() = ::rust::cxxqtlib1::qtimezoneDefault;
  return qtimezone_default$().release();
}

void rust$cxxqtlib1$cxxbridge1$194$qtimezone_display_name(::QTimeZone const &timezone, ::QTimeZoneTimeType time_type, ::QTimeZoneNameType name_type, ::QString *return$) noexcept {
  ::QString (*qtimezone_display_name$)(::QTimeZone const &, ::QTimeZoneTimeType, ::QTimeZoneNameType) = ::rust::cxxqtlib1::qtimezoneDisplayName;
  new (return$) ::QString(qtimezone_display_name$(timezone, time_type, name_type));
}

::QTimeZone *rust$cxxqtlib1$cxxbridge1$194$qtimezone_from_offset_seconds(::std::int32_t offset_seconds) noexcept {
  ::std::unique_ptr<::QTimeZone> (*qtimezone_from_offset_seconds$)(::std::int32_t) = ::rust::cxxqtlib1::qtimezoneFromOffsetSeconds;
  return qtimezone_from_offset_seconds$(offset_seconds).release();
}

::QTimeZone *rust$cxxqtlib1$cxxbridge1$194$qtimezone_from_iana(::QByteArray const &iana_id) noexcept {
  ::std::unique_ptr<::QTimeZone> (*qtimezone_from_iana$)(::QByteArray const &) = ::rust::cxxqtlib1::qtimezoneFromIana;
  return qtimezone_from_iana$(iana_id).release();
}

::QTimeZone *rust$cxxqtlib1$cxxbridge1$194$qtimezone_system_time_zone() noexcept {
  ::std::unique_ptr<::QTimeZone> (*qtimezone_system_time_zone$)() = ::rust::cxxqtlib1::qtimezoneSystemTimeZone;
  return qtimezone_system_time_zone$().release();
}

void rust$cxxqtlib1$cxxbridge1$194$qtimezone_system_time_zone_id(::QByteArray *return$) noexcept {
  ::QByteArray (*qtimezone_system_time_zone_id$)() = ::rust::cxxqtlib1::qtimezoneSystemTimeZoneId;
  new (return$) ::QByteArray(qtimezone_system_time_zone_id$());
}

::QTimeZone *rust$cxxqtlib1$cxxbridge1$194$qtimezone_utc() noexcept {
  ::std::unique_ptr<::QTimeZone> (*qtimezone_utc$)() = ::rust::cxxqtlib1::qtimezoneUtc;
  return qtimezone_utc$().release();
}

bool rust$cxxqtlib1$cxxbridge1$194$qtimezone_eq(::QTimeZone const &a, ::QTimeZone const &b) noexcept {
  bool (*qtimezone_eq$)(::QTimeZone const &, ::QTimeZone const &) = ::rust::cxxqtlib1::operatorEq;
  return qtimezone_eq$(a, b);
}

void rust$cxxqtlib1$cxxbridge1$194$qtimezone_to_debug_qstring(::QTimeZone const &value, ::QString *return$) noexcept {
  ::QString (*qtimezone_to_debug_qstring$)(::QTimeZone const &) = ::rust::cxxqtlib1::toDebugQString;
  new (return$) ::QString(qtimezone_to_debug_qstring$(value));
}
} // extern "C"
} // namespace cxxqtlib1
} // namespace rust

extern "C" {
static_assert(::rust::detail::is_complete<::std::remove_extent<::QTimeZone>::type>::value, "definition of `::QTimeZone` is required");
static_assert(sizeof(::std::unique_ptr<::QTimeZone>) == sizeof(void *), "");
static_assert(alignof(::std::unique_ptr<::QTimeZone>) == alignof(void *), "");
void cxxbridge1$unique_ptr$QTimeZone$null(::std::unique_ptr<::QTimeZone> *ptr) noexcept {
  ::new (ptr) ::std::unique_ptr<::QTimeZone>();
}
void cxxbridge1$unique_ptr$QTimeZone$raw(::std::unique_ptr<::QTimeZone> *ptr, ::std::unique_ptr<::QTimeZone>::pointer raw) noexcept {
  ::new (ptr) ::std::unique_ptr<::QTimeZone>(raw);
}
::std::unique_ptr<::QTimeZone>::element_type const *cxxbridge1$unique_ptr$QTimeZone$get(::std::unique_ptr<::QTimeZone> const &ptr) noexcept {
  return ptr.get();
}
::std::unique_ptr<::QTimeZone>::pointer cxxbridge1$unique_ptr$QTimeZone$release(::std::unique_ptr<::QTimeZone> &ptr) noexcept {
  return ptr.release();
}
void cxxbridge1$unique_ptr$QTimeZone$drop(::std::unique_ptr<::QTimeZone> *ptr) noexcept {
  ::rust::deleter_if<::rust::detail::is_complete<::QTimeZone>::value>{}(ptr);
}
} // extern "C"
