#include "cxx-qt-lib/qt.h"
#include "cxx-qt-lib/qmarginsf.h"
#include "cxx-qt-lib/qsize.h"
#include "cxx-qt-lib/qsizef.h"
#include "cxx-qt-lib/qstring.h"
#include "cxx-qt-lib/common.h"
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
    ::rust::IsRelocatable<::Qt::AspectRatioMode>::value,
    "type Qt::AspectRatioMode should be trivially move constructible and trivially destructible in C++ to be used as an argument of `scale`, `scaled` in Rust");
static_assert(
    ::rust::IsRelocatable<::QMarginsF>::value,
    "type QMarginsF should be trivially move constructible and trivially destructible in C++ to be used as an argument of `grown_by`, `shrunk_by` in Rust");
static_assert(
    ::rust::IsRelocatable<::QSize>::value,
    "type QSize should be trivially move constructible and trivially destructible in C++ to be used as a return value of `to_size` in Rust");
static_assert(
    ::rust::IsRelocatable<::QSizeF>::value,
    "type QSizeF should be trivially move constructible and trivially destructible in C++ to be used as a return value of `bounded_to`, `expanded_to`, `grown_by` in Rust");
static_assert(
    ::rust::IsRelocatable<::QString>::value,
    "type QString should be trivially move constructible and trivially destructible in C++ to be used as a return value of `qsizef_to_debug_qstring` in Rust");

extern "C" {
void cxxbridge1$194$QSizeF$bounded_to(::QSizeF const &self, ::QSizeF const &other_size, ::QSizeF *return$) noexcept {
  ::QSizeF (::QSizeF::*bounded_to$)(::QSizeF const &) const = &::QSizeF::boundedTo;
  new (return$) ::QSizeF((self.*bounded_to$)(other_size));
}

void cxxbridge1$194$QSizeF$expanded_to(::QSizeF const &self, ::QSizeF const &other_size, ::QSizeF *return$) noexcept {
  ::QSizeF (::QSizeF::*expanded_to$)(::QSizeF const &) const = &::QSizeF::expandedTo;
  new (return$) ::QSizeF((self.*expanded_to$)(other_size));
}

double cxxbridge1$194$QSizeF$height(::QSizeF const &self) noexcept {
  double (::QSizeF::*height$)() const = &::QSizeF::height;
  return (self.*height$)();
}

bool cxxbridge1$194$QSizeF$is_empty(::QSizeF const &self) noexcept {
  bool (::QSizeF::*is_empty$)() const = &::QSizeF::isEmpty;
  return (self.*is_empty$)();
}

bool cxxbridge1$194$QSizeF$is_null(::QSizeF const &self) noexcept {
  bool (::QSizeF::*is_null$)() const = &::QSizeF::isNull;
  return (self.*is_null$)();
}

bool cxxbridge1$194$QSizeF$is_valid(::QSizeF const &self) noexcept {
  bool (::QSizeF::*is_valid$)() const = &::QSizeF::isValid;
  return (self.*is_valid$)();
}

void cxxbridge1$194$QSizeF$grown_by(::QSizeF const &self, ::QMarginsF *margins, ::QSizeF *return$) noexcept {
  ::QSizeF (::QSizeF::*grown_by$)(::QMarginsF) const = &::QSizeF::grownBy;
  new (return$) ::QSizeF((self.*grown_by$)(::std::move(*margins)));
}

void cxxbridge1$194$QSizeF$scale(::QSizeF &self, ::QSizeF const &size, ::Qt::AspectRatioMode *mode) noexcept {
  void (::QSizeF::*scale$)(::QSizeF const &, ::Qt::AspectRatioMode) = &::QSizeF::scale;
  (self.*scale$)(size, ::std::move(*mode));
}

void cxxbridge1$194$QSizeF$scaled(::QSizeF const &self, ::QSizeF const &s, ::Qt::AspectRatioMode *mode, ::QSizeF *return$) noexcept {
  ::QSizeF (::QSizeF::*scaled$)(::QSizeF const &, ::Qt::AspectRatioMode) const = &::QSizeF::scaled;
  new (return$) ::QSizeF((self.*scaled$)(s, ::std::move(*mode)));
}

void cxxbridge1$194$QSizeF$set_height(::QSizeF &self, double height) noexcept {
  void (::QSizeF::*set_height$)(double) = &::QSizeF::setHeight;
  (self.*set_height$)(height);
}

void cxxbridge1$194$QSizeF$set_width(::QSizeF &self, double width) noexcept {
  void (::QSizeF::*set_width$)(double) = &::QSizeF::setWidth;
  (self.*set_width$)(width);
}

void cxxbridge1$194$QSizeF$shrunk_by(::QSizeF const &self, ::QMarginsF *margins, ::QSizeF *return$) noexcept {
  ::QSizeF (::QSizeF::*shrunk_by$)(::QMarginsF) const = &::QSizeF::shrunkBy;
  new (return$) ::QSizeF((self.*shrunk_by$)(::std::move(*margins)));
}

void cxxbridge1$194$QSizeF$to_size(::QSizeF const &self, ::QSize *return$) noexcept {
  ::QSize (::QSizeF::*to_size$)() const = &::QSizeF::toSize;
  new (return$) ::QSize((self.*to_size$)());
}

void cxxbridge1$194$QSizeF$transpose(::QSizeF &self) noexcept {
  void (::QSizeF::*transpose$)() = &::QSizeF::transpose;
  (self.*transpose$)();
}

void cxxbridge1$194$QSizeF$transposed(::QSizeF const &self, ::QSizeF *return$) noexcept {
  ::QSizeF (::QSizeF::*transposed$)() const = &::QSizeF::transposed;
  new (return$) ::QSizeF((self.*transposed$)());
}

double cxxbridge1$194$QSizeF$width(::QSizeF const &self) noexcept {
  double (::QSizeF::*width$)() const = &::QSizeF::width;
  return (self.*width$)();
}
} // extern "C"

namespace rust {
namespace cxxqtlib1 {
extern "C" {
void rust$cxxqtlib1$cxxbridge1$194$qsizef_init_default(::QSizeF *return$) noexcept {
  ::QSizeF (*qsizef_init_default$)() = ::rust::cxxqtlib1::construct;
  new (return$) ::QSizeF(qsizef_init_default$());
}

void rust$cxxqtlib1$cxxbridge1$194$qsizef_init(double w, double h, ::QSizeF *return$) noexcept {
  ::QSizeF (*qsizef_init$)(double, double) = ::rust::cxxqtlib1::construct;
  new (return$) ::QSizeF(qsizef_init$(w, h));
}

void rust$cxxqtlib1$cxxbridge1$194$qsizef_from_qsize(::QSize const &size, ::QSizeF *return$) noexcept {
  ::QSizeF (*qsizef_from_qsize$)(::QSize const &) = ::rust::cxxqtlib1::construct;
  new (return$) ::QSizeF(qsizef_from_qsize$(size));
}

void rust$cxxqtlib1$cxxbridge1$194$qsizef_to_debug_qstring(::QSizeF const &value, ::QString *return$) noexcept {
  ::QString (*qsizef_to_debug_qstring$)(::QSizeF const &) = ::rust::cxxqtlib1::toDebugQString;
  new (return$) ::QString(qsizef_to_debug_qstring$(value));
}

void rust$cxxqtlib1$cxxbridge1$194$qsizef_plus(::QSizeF const &a, ::QSizeF const &b, ::QSizeF *return$) noexcept {
  ::QSizeF (*qsizef_plus$)(::QSizeF const &, ::QSizeF const &) = ::rust::cxxqtlib1::operatorPlus;
  new (return$) ::QSizeF(qsizef_plus$(a, b));
}

void rust$cxxqtlib1$cxxbridge1$194$qsizef_minus(::QSizeF const &a, ::QSizeF const &b, ::QSizeF *return$) noexcept {
  ::QSizeF (*qsizef_minus$)(::QSizeF const &, ::QSizeF const &) = ::rust::cxxqtlib1::operatorMinus;
  new (return$) ::QSizeF(qsizef_minus$(a, b));
}

void rust$cxxqtlib1$cxxbridge1$194$qsizef_mul(double a, ::QSizeF const &b, ::QSizeF *return$) noexcept {
  ::QSizeF (*qsizef_mul$)(double, ::QSizeF const &) = ::rust::cxxqtlib1::operatorMul;
  new (return$) ::QSizeF(qsizef_mul$(a, b));
}

void rust$cxxqtlib1$cxxbridge1$194$qsizef_div(double a, ::QSizeF const &b, ::QSizeF *return$) noexcept {
  ::QSizeF (*qsizef_div$)(double, ::QSizeF const &) = ::rust::cxxqtlib1::operatorDiv;
  new (return$) ::QSizeF(qsizef_div$(a, b));
}
} // extern "C"
} // namespace cxxqtlib1
} // namespace rust
