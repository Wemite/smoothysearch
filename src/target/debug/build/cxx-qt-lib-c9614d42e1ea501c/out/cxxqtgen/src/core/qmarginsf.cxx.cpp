#include "cxx-qt-lib/qmargins.h"
#include "cxx-qt-lib/qmarginsf.h"
#include "cxx-qt-lib/qstring.h"
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
    ::rust::IsRelocatable<::QMargins>::value,
    "type QMargins should be trivially move constructible and trivially destructible in C++ to be used as a return value of `to_margins` in Rust");
static_assert(
    ::rust::IsRelocatable<::QMarginsF>::value,
    "type QMarginsF should be trivially move constructible and trivially destructible in C++ to be used as a return value of `qmarginsf_default`, `qmarginsf_from_qmargin`, `qmarginsf_new` in Rust");
static_assert(
    ::rust::IsRelocatable<::QString>::value,
    "type QString should be trivially move constructible and trivially destructible in C++ to be used as a return value of `qmarginsf_to_debug_qstring` in Rust");

extern "C" {
double cxxbridge1$194$QMarginsF$bottom(::QMarginsF const &self) noexcept {
  double (::QMarginsF::*bottom$)() const = &::QMarginsF::bottom;
  return (self.*bottom$)();
}

bool cxxbridge1$194$QMarginsF$is_null(::QMarginsF const &self) noexcept {
  bool (::QMarginsF::*is_null$)() const = &::QMarginsF::isNull;
  return (self.*is_null$)();
}

double cxxbridge1$194$QMarginsF$left(::QMarginsF const &self) noexcept {
  double (::QMarginsF::*left$)() const = &::QMarginsF::left;
  return (self.*left$)();
}

double cxxbridge1$194$QMarginsF$right(::QMarginsF const &self) noexcept {
  double (::QMarginsF::*right$)() const = &::QMarginsF::right;
  return (self.*right$)();
}

void cxxbridge1$194$QMarginsF$set_bottom(::QMarginsF &self, double abottom) noexcept {
  void (::QMarginsF::*set_bottom$)(double) = &::QMarginsF::setBottom;
  (self.*set_bottom$)(abottom);
}

void cxxbridge1$194$QMarginsF$set_left(::QMarginsF &self, double aleft) noexcept {
  void (::QMarginsF::*set_left$)(double) = &::QMarginsF::setLeft;
  (self.*set_left$)(aleft);
}

void cxxbridge1$194$QMarginsF$set_right(::QMarginsF &self, double aright) noexcept {
  void (::QMarginsF::*set_right$)(double) = &::QMarginsF::setRight;
  (self.*set_right$)(aright);
}

void cxxbridge1$194$QMarginsF$set_top(::QMarginsF &self, double atop) noexcept {
  void (::QMarginsF::*set_top$)(double) = &::QMarginsF::setTop;
  (self.*set_top$)(atop);
}

void cxxbridge1$194$QMarginsF$to_margins(::QMarginsF const &self, ::QMargins *return$) noexcept {
  ::QMargins (::QMarginsF::*to_margins$)() const = &::QMarginsF::toMargins;
  new (return$) ::QMargins((self.*to_margins$)());
}

double cxxbridge1$194$QMarginsF$top(::QMarginsF const &self) noexcept {
  double (::QMarginsF::*top$)() const = &::QMarginsF::top;
  return (self.*top$)();
}
} // extern "C"

namespace rust {
namespace cxxqtlib1 {
extern "C" {
void rust$cxxqtlib1$cxxbridge1$194$qmarginsf_default(::QMarginsF *return$) noexcept {
  ::QMarginsF (*qmarginsf_default$)() = ::rust::cxxqtlib1::construct;
  new (return$) ::QMarginsF(qmarginsf_default$());
}

void rust$cxxqtlib1$cxxbridge1$194$qmarginsf_from_qmargin(::QMargins const &margins, ::QMarginsF *return$) noexcept {
  ::QMarginsF (*qmarginsf_from_qmargin$)(::QMargins const &) = ::rust::cxxqtlib1::construct;
  new (return$) ::QMarginsF(qmarginsf_from_qmargin$(margins));
}

void rust$cxxqtlib1$cxxbridge1$194$qmarginsf_new(double left, double top, double right, double bottom, ::QMarginsF *return$) noexcept {
  ::QMarginsF (*qmarginsf_new$)(double, double, double, double) = ::rust::cxxqtlib1::construct;
  new (return$) ::QMarginsF(qmarginsf_new$(left, top, right, bottom));
}

void rust$cxxqtlib1$cxxbridge1$194$qmarginsf_to_debug_qstring(::QMarginsF const &value, ::QString *return$) noexcept {
  ::QString (*qmarginsf_to_debug_qstring$)(::QMarginsF const &) = ::rust::cxxqtlib1::toDebugQString;
  new (return$) ::QString(qmarginsf_to_debug_qstring$(value));
}

void rust$cxxqtlib1$cxxbridge1$194$qmarginsf_plus(::QMarginsF const &a, ::QMarginsF const &b, ::QMarginsF *return$) noexcept {
  ::QMarginsF (*qmarginsf_plus$)(::QMarginsF const &, ::QMarginsF const &) = ::rust::cxxqtlib1::operatorPlus;
  new (return$) ::QMarginsF(qmarginsf_plus$(a, b));
}

void rust$cxxqtlib1$cxxbridge1$194$qmarginsf_plus_f64(::QMarginsF const &a, double const &b, ::QMarginsF *return$) noexcept {
  ::QMarginsF (*qmarginsf_plus_f64$)(::QMarginsF const &, double const &) = ::rust::cxxqtlib1::operatorPlus;
  new (return$) ::QMarginsF(qmarginsf_plus_f64$(a, b));
}

void rust$cxxqtlib1$cxxbridge1$194$qmarginsf_minus(::QMarginsF const &a, ::QMarginsF const &b, ::QMarginsF *return$) noexcept {
  ::QMarginsF (*qmarginsf_minus$)(::QMarginsF const &, ::QMarginsF const &) = ::rust::cxxqtlib1::operatorMinus;
  new (return$) ::QMarginsF(qmarginsf_minus$(a, b));
}

void rust$cxxqtlib1$cxxbridge1$194$qmarginsf_minus_f64(::QMarginsF const &a, double const &b, ::QMarginsF *return$) noexcept {
  ::QMarginsF (*qmarginsf_minus_f64$)(::QMarginsF const &, double const &) = ::rust::cxxqtlib1::operatorMinus;
  new (return$) ::QMarginsF(qmarginsf_minus_f64$(a, b));
}

void rust$cxxqtlib1$cxxbridge1$194$qmarginsf_mul(double a, ::QMarginsF const &b, ::QMarginsF *return$) noexcept {
  ::QMarginsF (*qmarginsf_mul$)(double, ::QMarginsF const &) = ::rust::cxxqtlib1::operatorMul;
  new (return$) ::QMarginsF(qmarginsf_mul$(a, b));
}

void rust$cxxqtlib1$cxxbridge1$194$qmarginsf_div(double a, ::QMarginsF const &b, ::QMarginsF *return$) noexcept {
  ::QMarginsF (*qmarginsf_div$)(double, ::QMarginsF const &) = ::rust::cxxqtlib1::operatorDiv;
  new (return$) ::QMarginsF(qmarginsf_div$(a, b));
}
} // extern "C"
} // namespace cxxqtlib1
} // namespace rust
