#include "cxx-qt-lib/qt.h"
#include "cxx-qt-lib/qtypes.h"
#include "cxx-qt-lib/qstring.h"
#include "cxx-qt-lib/qdate.h"
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
    "type Qt::DateFormat should be trivially move constructible and trivially destructible in C++ to be used as an argument of `format_enum`, `qdate_from_string_enum` in Rust");
static_assert(
    ::rust::IsRelocatable<::qint64>::value,
    "type qint64 should be trivially move constructible and trivially destructible in C++ to be used as an argument of `add_days_qint64` or return value of `qdate_days_to` in Rust");
static_assert(
    ::rust::IsRelocatable<::QString>::value,
    "type QString should be trivially move constructible and trivially destructible in C++ to be used as a return value of `format_enum`, `qdate_to_format`, `qdate_to_debug_qstring` in Rust");
static_assert(
    ::rust::IsRelocatable<::QDate>::value,
    "type QDate should be trivially move constructible and trivially destructible in C++ to be used as an argument of `qdate_days_to` or return value of `add_days_qint64`, `add_months`, `add_years` in Rust");

extern "C" {
void cxxbridge1$194$QDate$add_days_qint64(::QDate const &self, ::qint64 *ndays, ::QDate *return$) noexcept {
  ::QDate (::QDate::*add_days_qint64$)(::qint64) const = &::QDate::addDays;
  new (return$) ::QDate((self.*add_days_qint64$)(::std::move(*ndays)));
}

void cxxbridge1$194$QDate$add_months(::QDate const &self, ::std::int32_t nmonths, ::QDate *return$) noexcept {
  ::QDate (::QDate::*add_months$)(::std::int32_t) const = &::QDate::addMonths;
  new (return$) ::QDate((self.*add_months$)(nmonths));
}

void cxxbridge1$194$QDate$add_years(::QDate const &self, ::std::int32_t nyears, ::QDate *return$) noexcept {
  ::QDate (::QDate::*add_years$)(::std::int32_t) const = &::QDate::addYears;
  new (return$) ::QDate((self.*add_years$)(nyears));
}

::std::int32_t cxxbridge1$194$QDate$day(::QDate const &self) noexcept {
  ::std::int32_t (::QDate::*day$)() const = &::QDate::day;
  return (self.*day$)();
}

::std::int32_t cxxbridge1$194$QDate$day_of_week(::QDate const &self) noexcept {
  ::std::int32_t (::QDate::*day_of_week$)() const = &::QDate::dayOfWeek;
  return (self.*day_of_week$)();
}

::std::int32_t cxxbridge1$194$QDate$day_of_year(::QDate const &self) noexcept {
  ::std::int32_t (::QDate::*day_of_year$)() const = &::QDate::dayOfYear;
  return (self.*day_of_year$)();
}

::std::int32_t cxxbridge1$194$QDate$days_in_monyth(::QDate const &self) noexcept {
  ::std::int32_t (::QDate::*days_in_monyth$)() const = &::QDate::daysInMonth;
  return (self.*days_in_monyth$)();
}

::std::int32_t cxxbridge1$194$QDate$days_in_year(::QDate const &self) noexcept {
  ::std::int32_t (::QDate::*days_in_year$)() const = &::QDate::daysInYear;
  return (self.*days_in_year$)();
}

bool cxxbridge1$194$QDate$is_null(::QDate const &self) noexcept {
  bool (::QDate::*is_null$)() const = &::QDate::isNull;
  return (self.*is_null$)();
}

bool cxxbridge1$194$QDate$is_valid(::QDate const &self) noexcept {
  bool (::QDate::*is_valid$)() const = &::QDate::isValid;
  return (self.*is_valid$)();
}

::std::int32_t cxxbridge1$194$QDate$month(::QDate const &self) noexcept {
  ::std::int32_t (::QDate::*month$)() const = &::QDate::month;
  return (self.*month$)();
}

bool cxxbridge1$194$QDate$set_date(::QDate &self, ::std::int32_t y, ::std::int32_t m, ::std::int32_t d) noexcept {
  bool (::QDate::*set_date$)(::std::int32_t, ::std::int32_t, ::std::int32_t) = &::QDate::setDate;
  return (self.*set_date$)(y, m, d);
}

void cxxbridge1$194$QDate$format_enum(::QDate const &self, ::Qt::DateFormat *format, ::QString *return$) noexcept {
  ::QString (::QDate::*format_enum$)(::Qt::DateFormat) const = &::QDate::toString;
  new (return$) ::QString((self.*format_enum$)(::std::move(*format)));
}

::std::int32_t cxxbridge1$194$QDate$year(::QDate const &self) noexcept {
  ::std::int32_t (::QDate::*year$)() const = &::QDate::year;
  return (self.*year$)();
}
} // extern "C"

namespace rust {
namespace cxxqtlib1 {
extern "C" {
void rust$cxxqtlib1$cxxbridge1$194$qdate_current_date(::QDate *return$) noexcept {
  ::QDate (*qdate_current_date$)() = ::rust::cxxqtlib1::qdateCurrentDate;
  new (return$) ::QDate(qdate_current_date$());
}

void rust$cxxqtlib1$cxxbridge1$194$qdate_days_to(::QDate const &date, ::QDate *d, ::qint64 *return$) noexcept {
  ::qint64 (*qdate_days_to$)(::QDate const &, ::QDate) = ::rust::cxxqtlib1::qdateDaysTo;
  new (return$) ::qint64(qdate_days_to$(date, ::std::move(*d)));
}

void rust$cxxqtlib1$cxxbridge1$194$qdate_from_string(::QString const &string, ::QString const &format, ::QDate *return$) noexcept {
  ::QDate (*qdate_from_string$)(::QString const &, ::QString const &) = ::rust::cxxqtlib1::qdateFromString;
  new (return$) ::QDate(qdate_from_string$(string, format));
}

void rust$cxxqtlib1$cxxbridge1$194$qdate_from_string_enum(::QString const &string, ::Qt::DateFormat *format, ::QDate *return$) noexcept {
  ::QDate (*qdate_from_string_enum$)(::QString const &, ::Qt::DateFormat) = ::rust::cxxqtlib1::qdateFromString;
  new (return$) ::QDate(qdate_from_string_enum$(string, ::std::move(*format)));
}

bool rust$cxxqtlib1$cxxbridge1$194$qdate_is_leap_year(::std::int32_t year) noexcept {
  bool (*qdate_is_leap_year$)(::std::int32_t) = ::rust::cxxqtlib1::qdateIsLeapYear;
  return qdate_is_leap_year$(year);
}

void rust$cxxqtlib1$cxxbridge1$194$qdate_to_format(::QDate const &date, ::QString const &format, ::QString *return$) noexcept {
  ::QString (*qdate_to_format$)(::QDate const &, ::QString const &) = ::rust::cxxqtlib1::qdateToFormat;
  new (return$) ::QString(qdate_to_format$(date, format));
}

void rust$cxxqtlib1$cxxbridge1$194$qdate_init_default(::QDate *return$) noexcept {
  ::QDate (*qdate_init_default$)() = ::rust::cxxqtlib1::construct;
  new (return$) ::QDate(qdate_init_default$());
}

void rust$cxxqtlib1$cxxbridge1$194$qdate_init(::std::int32_t y, ::std::int32_t m, ::std::int32_t d, ::QDate *return$) noexcept {
  ::QDate (*qdate_init$)(::std::int32_t, ::std::int32_t, ::std::int32_t) = ::rust::cxxqtlib1::construct;
  new (return$) ::QDate(qdate_init$(y, m, d));
}

void rust$cxxqtlib1$cxxbridge1$194$qdate_to_debug_qstring(::QDate const &value, ::QString *return$) noexcept {
  ::QString (*qdate_to_debug_qstring$)(::QDate const &) = ::rust::cxxqtlib1::toDebugQString;
  new (return$) ::QString(qdate_to_debug_qstring$(value));
}
} // extern "C"
} // namespace cxxqtlib1
} // namespace rust
