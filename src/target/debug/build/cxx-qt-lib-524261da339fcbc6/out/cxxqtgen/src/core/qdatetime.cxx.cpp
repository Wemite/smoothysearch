#include "cxx-qt-lib/qt.h"
#include "cxx-qt-lib/qtypes.h"
#include "cxx-qt-lib/qdate.h"
#include "cxx-qt-lib/qdatetime.h"
#include "cxx-qt-lib/qtime.h"
#include "cxx-qt-lib/qstring.h"
#include "cxx-qt-lib/qtimezone.h"
#include "cxx-qt-lib/common.h"
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
    ::rust::IsRelocatable<::Qt::TimeSpec>::value,
    "type Qt::TimeSpec should be trivially move constructible and trivially destructible in C++ to be used as a return value of `time_spec` in Rust");
static_assert(
    ::rust::IsRelocatable<::Qt::DateFormat>::value,
    "type Qt::DateFormat should be trivially move constructible and trivially destructible in C++ to be used as an argument of `format_enum`, `qdatetime_from_string` in Rust");
static_assert(
    ::rust::IsRelocatable<::qint64>::value,
    "type qint64 should be trivially move constructible and trivially destructible in C++ to be used as an argument of `add_days_qint64`, `add_msecs_qint64`, `add_secs_qint64` or return value of `days_to_qint64`, `msecs_to_qint64`, `secs_to_qint64` in Rust");
static_assert(
    ::rust::IsRelocatable<::QDate>::value,
    "type QDate should be trivially move constructible and trivially destructible in C++ to be used as an argument of `qdatetime_set_date` or return value of `date` in Rust");
static_assert(
    ::rust::IsRelocatable<::QDateTime>::value,
    "type QDateTime should be trivially move constructible and trivially destructible in C++ to be used as a return value of `add_days_qint64`, `add_months`, `add_msecs_qint64` in Rust");
static_assert(
    ::rust::IsRelocatable<::QTime>::value,
    "type QTime should be trivially move constructible and trivially destructible in C++ to be used as an argument of `qdatetime_set_time` or return value of `time` in Rust");
static_assert(
    ::rust::IsRelocatable<::QString>::value,
    "type QString should be trivially move constructible and trivially destructible in C++ to be used as a return value of `time_zone_abbreviation`, `format_enum`, `qdatetime_to_debug_qstring` in Rust");

extern "C" {
void cxxbridge1$194$QDateTime$add_days_qint64(::QDateTime const &self, ::qint64 *ndays, ::QDateTime *return$) noexcept {
  ::QDateTime (::QDateTime::*add_days_qint64$)(::qint64) const = &::QDateTime::addDays;
  new (return$) ::QDateTime((self.*add_days_qint64$)(::std::move(*ndays)));
}

void cxxbridge1$194$QDateTime$add_months(::QDateTime const &self, ::std::int32_t nmonths, ::QDateTime *return$) noexcept {
  ::QDateTime (::QDateTime::*add_months$)(::std::int32_t) const = &::QDateTime::addMonths;
  new (return$) ::QDateTime((self.*add_months$)(nmonths));
}

void cxxbridge1$194$QDateTime$add_msecs_qint64(::QDateTime const &self, ::qint64 *msecs, ::QDateTime *return$) noexcept {
  ::QDateTime (::QDateTime::*add_msecs_qint64$)(::qint64) const = &::QDateTime::addMSecs;
  new (return$) ::QDateTime((self.*add_msecs_qint64$)(::std::move(*msecs)));
}

void cxxbridge1$194$QDateTime$add_secs_qint64(::QDateTime const &self, ::qint64 *secs, ::QDateTime *return$) noexcept {
  ::QDateTime (::QDateTime::*add_secs_qint64$)(::qint64) const = &::QDateTime::addSecs;
  new (return$) ::QDateTime((self.*add_secs_qint64$)(::std::move(*secs)));
}

void cxxbridge1$194$QDateTime$add_years(::QDateTime const &self, ::std::int32_t nyears, ::QDateTime *return$) noexcept {
  ::QDateTime (::QDateTime::*add_years$)(::std::int32_t) const = &::QDateTime::addYears;
  new (return$) ::QDateTime((self.*add_years$)(nyears));
}

void cxxbridge1$194$QDateTime$date(::QDateTime const &self, ::QDate *return$) noexcept {
  ::QDate (::QDateTime::*date$)() const = &::QDateTime::date;
  new (return$) ::QDate((self.*date$)());
}

void cxxbridge1$194$QDateTime$days_to_qint64(::QDateTime const &self, ::QDateTime const &other, ::qint64 *return$) noexcept {
  ::qint64 (::QDateTime::*days_to_qint64$)(::QDateTime const &) const = &::QDateTime::daysTo;
  new (return$) ::qint64((self.*days_to_qint64$)(other));
}

bool cxxbridge1$194$QDateTime$is_daylight_time(::QDateTime const &self) noexcept {
  bool (::QDateTime::*is_daylight_time$)() const = &::QDateTime::isDaylightTime;
  return (self.*is_daylight_time$)();
}

bool cxxbridge1$194$QDateTime$is_null(::QDateTime const &self) noexcept {
  bool (::QDateTime::*is_null$)() const = &::QDateTime::isNull;
  return (self.*is_null$)();
}

bool cxxbridge1$194$QDateTime$is_valid(::QDateTime const &self) noexcept {
  bool (::QDateTime::*is_valid$)() const = &::QDateTime::isValid;
  return (self.*is_valid$)();
}

::std::int32_t cxxbridge1$194$QDateTime$offset_from_utc(::QDateTime const &self) noexcept {
  ::std::int32_t (::QDateTime::*offset_from_utc$)() const = &::QDateTime::offsetFromUtc;
  return (self.*offset_from_utc$)();
}

void cxxbridge1$194$QDateTime$msecs_to_qint64(::QDateTime const &self, ::QDateTime const &other, ::qint64 *return$) noexcept {
  ::qint64 (::QDateTime::*msecs_to_qint64$)(::QDateTime const &) const = &::QDateTime::msecsTo;
  new (return$) ::qint64((self.*msecs_to_qint64$)(other));
}

void cxxbridge1$194$QDateTime$secs_to_qint64(::QDateTime const &self, ::QDateTime const &other, ::qint64 *return$) noexcept {
  ::qint64 (::QDateTime::*secs_to_qint64$)(::QDateTime const &) const = &::QDateTime::secsTo;
  new (return$) ::qint64((self.*secs_to_qint64$)(other));
}

void cxxbridge1$194$QDateTime$set_msecs_since_epoch_qint64(::QDateTime &self, ::qint64 *msecs) noexcept {
  void (::QDateTime::*set_msecs_since_epoch_qint64$)(::qint64) = &::QDateTime::setMSecsSinceEpoch;
  (self.*set_msecs_since_epoch_qint64$)(::std::move(*msecs));
}

void cxxbridge1$194$QDateTime$set_secs_since_epoch_qint64(::QDateTime &self, ::qint64 *secs) noexcept {
  void (::QDateTime::*set_secs_since_epoch_qint64$)(::qint64) = &::QDateTime::setSecsSinceEpoch;
  (self.*set_secs_since_epoch_qint64$)(::std::move(*secs));
}

void cxxbridge1$194$QDateTime$time(::QDateTime const &self, ::QTime *return$) noexcept {
  ::QTime (::QDateTime::*time$)() const = &::QDateTime::time;
  new (return$) ::QTime((self.*time$)());
}

void cxxbridge1$194$QDateTime$time_spec(::QDateTime const &self, ::Qt::TimeSpec *return$) noexcept {
  ::Qt::TimeSpec (::QDateTime::*time_spec$)() const = &::QDateTime::timeSpec;
  new (return$) ::Qt::TimeSpec((self.*time_spec$)());
}

void cxxbridge1$194$QDateTime$time_zone_abbreviation(::QDateTime const &self, ::QString *return$) noexcept {
  ::QString (::QDateTime::*time_zone_abbreviation$)() const = &::QDateTime::timeZoneAbbreviation;
  new (return$) ::QString((self.*time_zone_abbreviation$)());
}

void cxxbridge1$194$QDateTime$to_local_time(::QDateTime const &self, ::QDateTime *return$) noexcept {
  ::QDateTime (::QDateTime::*to_local_time$)() const = &::QDateTime::toLocalTime;
  new (return$) ::QDateTime((self.*to_local_time$)());
}

void cxxbridge1$194$QDateTime$to_msecs_since_epoch_qint64(::QDateTime const &self, ::qint64 *return$) noexcept {
  ::qint64 (::QDateTime::*to_msecs_since_epoch_qint64$)() const = &::QDateTime::toMSecsSinceEpoch;
  new (return$) ::qint64((self.*to_msecs_since_epoch_qint64$)());
}

void cxxbridge1$194$QDateTime$to_offset_from_utc(::QDateTime const &self, ::std::int32_t offset_seconds, ::QDateTime *return$) noexcept {
  ::QDateTime (::QDateTime::*to_offset_from_utc$)(::std::int32_t) const = &::QDateTime::toOffsetFromUtc;
  new (return$) ::QDateTime((self.*to_offset_from_utc$)(offset_seconds));
}

void cxxbridge1$194$QDateTime$to_secs_since_epoch_qint64(::QDateTime const &self, ::qint64 *return$) noexcept {
  ::qint64 (::QDateTime::*to_secs_since_epoch_qint64$)() const = &::QDateTime::toSecsSinceEpoch;
  new (return$) ::qint64((self.*to_secs_since_epoch_qint64$)());
}

void cxxbridge1$194$QDateTime$format_enum(::QDateTime const &self, ::Qt::DateFormat *format, ::QString *return$) noexcept {
  ::QString (::QDateTime::*format_enum$)(::Qt::DateFormat) const = &::QDateTime::toString;
  new (return$) ::QString((self.*format_enum$)(::std::move(*format)));
}

void cxxbridge1$194$QDateTime$to_time_zone(::QDateTime const &self, ::QTimeZone const &time_zone, ::QDateTime *return$) noexcept {
  ::QDateTime (::QDateTime::*to_time_zone$)(::QTimeZone const &) const = &::QDateTime::toTimeZone;
  new (return$) ::QDateTime((self.*to_time_zone$)(time_zone));
}

void cxxbridge1$194$QDateTime$to_utc(::QDateTime const &self, ::QDateTime *return$) noexcept {
  ::QDateTime (::QDateTime::*to_utc$)() const = &::QDateTime::toUTC;
  new (return$) ::QDateTime((self.*to_utc$)());
}
} // extern "C"

namespace rust {
namespace cxxqtlib1 {
extern "C" {
void rust$cxxqtlib1$cxxbridge1$194$qdatetime_current_date_time(::QDateTime *return$) noexcept {
  ::QDateTime (*qdatetime_current_date_time$)() = ::rust::cxxqtlib1::qdatetimeCurrentDateTime;
  new (return$) ::QDateTime(qdatetime_current_date_time$());
}

void rust$cxxqtlib1$cxxbridge1$194$qdatetime_current_date_time_utc(::QDateTime *return$) noexcept {
  ::QDateTime (*qdatetime_current_date_time_utc$)() = ::rust::cxxqtlib1::qdatetimeCurrentDateTimeUtc;
  new (return$) ::QDateTime(qdatetime_current_date_time_utc$());
}

void rust$cxxqtlib1$cxxbridge1$194$qdatetime_current_msecs_since_epoch(::qint64 *return$) noexcept {
  ::qint64 (*qdatetime_current_msecs_since_epoch$)() = ::rust::cxxqtlib1::qdatetimeCurrentMSecsSinceEpoch;
  new (return$) ::qint64(qdatetime_current_msecs_since_epoch$());
}

void rust$cxxqtlib1$cxxbridge1$194$qdatetime_current_secs_since_epoch(::qint64 *return$) noexcept {
  ::qint64 (*qdatetime_current_secs_since_epoch$)() = ::rust::cxxqtlib1::qdatetimeCurrentSecsSinceEpoch;
  new (return$) ::qint64(qdatetime_current_secs_since_epoch$());
}

void rust$cxxqtlib1$cxxbridge1$194$qdatetime_from_msecs_since_epoch(::qint64 *msecs, ::QTimeZone const &time_zone, ::QDateTime *return$) noexcept {
  ::QDateTime (*qdatetime_from_msecs_since_epoch$)(::qint64, ::QTimeZone const &) = ::rust::cxxqtlib1::qdatetimeFromMSecsSinceEpoch;
  new (return$) ::QDateTime(qdatetime_from_msecs_since_epoch$(::std::move(*msecs), time_zone));
}

void rust$cxxqtlib1$cxxbridge1$194$qdatetime_from_secs_since_epoch(::qint64 *secs, ::QTimeZone const &time_zone, ::QDateTime *return$) noexcept {
  ::QDateTime (*qdatetime_from_secs_since_epoch$)(::qint64, ::QTimeZone const &) = ::rust::cxxqtlib1::qdatetimeFromSecsSinceEpoch;
  new (return$) ::QDateTime(qdatetime_from_secs_since_epoch$(::std::move(*secs), time_zone));
}

void rust$cxxqtlib1$cxxbridge1$194$qdatetime_set_date(::QDateTime &datetime, ::QDate *date) noexcept {
  void (*qdatetime_set_date$)(::QDateTime &, ::QDate) = ::rust::cxxqtlib1::qdatetimeSetDate;
  qdatetime_set_date$(datetime, ::std::move(*date));
}

void rust$cxxqtlib1$cxxbridge1$194$qdatetime_set_time(::QDateTime &datetime, ::QTime *time) noexcept {
  void (*qdatetime_set_time$)(::QDateTime &, ::QTime) = ::rust::cxxqtlib1::qdatetimeSetTime;
  qdatetime_set_time$(datetime, ::std::move(*time));
}

::QTimeZone *rust$cxxqtlib1$cxxbridge1$194$qdatetime_time_zone(::QDateTime const &datetime) noexcept {
  ::std::unique_ptr<::QTimeZone> (*qdatetime_time_zone$)(::QDateTime const &) = ::rust::cxxqtlib1::qdatetimeTimeZone;
  return qdatetime_time_zone$(datetime).release();
}

void rust$cxxqtlib1$cxxbridge1$194$qdatetime_settimezone(::QDateTime &datetime, ::QTimeZone const &time_zone) noexcept {
  void (*qdatetime_settimezone$)(::QDateTime &, ::QTimeZone const &) = ::rust::cxxqtlib1::qdatetimeSetTimeZone;
  qdatetime_settimezone$(datetime, time_zone);
}

void rust$cxxqtlib1$cxxbridge1$194$qdatetime_from_string(::QString const &string, ::Qt::DateFormat *format, ::QDateTime *return$) noexcept {
  ::QDateTime (*qdatetime_from_string$)(::QString const &, ::Qt::DateFormat) = ::rust::cxxqtlib1::qdatetimeFromQString;
  new (return$) ::QDateTime(qdatetime_from_string$(string, ::std::move(*format)));
}

void rust$cxxqtlib1$cxxbridge1$194$qdatetime_drop(::QDateTime &datetime) noexcept {
  void (*qdatetime_drop$)(::QDateTime &) = ::rust::cxxqtlib1::drop;
  qdatetime_drop$(datetime);
}

void rust$cxxqtlib1$cxxbridge1$194$qdatetime_init_default(::QDateTime *return$) noexcept {
  ::QDateTime (*qdatetime_init_default$)() = ::rust::cxxqtlib1::construct;
  new (return$) ::QDateTime(qdatetime_init_default$());
}

void rust$cxxqtlib1$cxxbridge1$194$qdatetime_init_from_date_and_time_time_zone(::QDate const &date, ::QTime const &time, ::QTimeZone const &time_zone, ::QDateTime *return$) noexcept {
  ::QDateTime (*qdatetime_init_from_date_and_time_time_zone$)(::QDate const &, ::QTime const &, ::QTimeZone const &) = ::rust::cxxqtlib1::construct;
  new (return$) ::QDateTime(qdatetime_init_from_date_and_time_time_zone$(date, time, time_zone));
}

void rust$cxxqtlib1$cxxbridge1$194$qdatetime_init_from_qdatetime(::QDateTime const &datetime, ::QDateTime *return$) noexcept {
  ::QDateTime (*qdatetime_init_from_qdatetime$)(::QDateTime const &) = ::rust::cxxqtlib1::construct;
  new (return$) ::QDateTime(qdatetime_init_from_qdatetime$(datetime));
}

bool rust$cxxqtlib1$cxxbridge1$194$qdatetime_eq(::QDateTime const &a, ::QDateTime const &b) noexcept {
  bool (*qdatetime_eq$)(::QDateTime const &, ::QDateTime const &) = ::rust::cxxqtlib1::operatorEq;
  return qdatetime_eq$(a, b);
}

::std::int8_t rust$cxxqtlib1$cxxbridge1$194$qdatetime_cmp(::QDateTime const &a, ::QDateTime const &b) noexcept {
  ::std::int8_t (*qdatetime_cmp$)(::QDateTime const &, ::QDateTime const &) = ::rust::cxxqtlib1::operatorCmp;
  return qdatetime_cmp$(a, b);
}

void rust$cxxqtlib1$cxxbridge1$194$qdatetime_to_debug_qstring(::QDateTime const &value, ::QString *return$) noexcept {
  ::QString (*qdatetime_to_debug_qstring$)(::QDateTime const &) = ::rust::cxxqtlib1::toDebugQString;
  new (return$) ::QString(qdatetime_to_debug_qstring$(value));
}
} // extern "C"
} // namespace cxxqtlib1
} // namespace rust
