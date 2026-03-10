#include "cxx-qt-lib/qcolor.h"
#include "cxx-qt-lib/qstring.h"
#include "cxx-qt-lib/qstringlist.h"
#include "cxx-qt-lib/common.h"
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

namespace rust {
  namespace cxxqtlib1 {
    using QColorNameFormat = ::rust::cxxqtlib1::QColorNameFormat;
    using QColorSpec = ::rust::cxxqtlib1::QColorSpec;
  }
}

namespace rust {
namespace cxxqtlib1 {
static_assert(::std::is_enum<QColorNameFormat>::value, "expected enum");
static_assert(sizeof(QColorNameFormat) == sizeof(::std::int32_t), "incorrect size");
static_assert(static_cast<::std::int32_t>(QColorNameFormat::HexRgb) == 0, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QColorNameFormat::HexArgb) == 1, "disagrees with the value in #[cxx::bridge]");

static_assert(::std::is_enum<QColorSpec>::value, "expected enum");
static_assert(sizeof(QColorSpec) == sizeof(::std::int32_t), "incorrect size");
static_assert(static_cast<::std::int32_t>(QColorSpec::Invalid) == 0, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QColorSpec::Rgb) == 1, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QColorSpec::Hsv) == 2, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QColorSpec::Cmyk) == 3, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QColorSpec::Hsl) == 4, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QColorSpec::ExtendedRgb) == 5, "disagrees with the value in #[cxx::bridge]");
} // namespace cxxqtlib1
} // namespace rust

static_assert(
    ::rust::IsRelocatable<::QColor>::value,
    "type QColor should be trivially move constructible and trivially destructible in C++ to be used as a return value of `convert_to`, `darker`, `lighter` in Rust");
static_assert(
    ::rust::IsRelocatable<::QString>::value,
    "type QString should be trivially move constructible and trivially destructible in C++ to be used as a return value of `name` in Rust");
static_assert(
    ::rust::IsRelocatable<::QStringList>::value,
    "type QStringList should be trivially move constructible and trivially destructible in C++ to be used as a return value of `qcolor_color_names` in Rust");

extern "C" {
::std::int32_t cxxbridge1$194$QColor$alpha(::QColor const &self) noexcept {
  ::std::int32_t (::QColor::*alpha$)() const = &::QColor::alpha;
  return (self.*alpha$)();
}

::std::int32_t cxxbridge1$194$QColor$black(::QColor const &self) noexcept {
  ::std::int32_t (::QColor::*black$)() const = &::QColor::black;
  return (self.*black$)();
}

::std::int32_t cxxbridge1$194$QColor$blue(::QColor const &self) noexcept {
  ::std::int32_t (::QColor::*blue$)() const = &::QColor::blue;
  return (self.*blue$)();
}

void cxxbridge1$194$QColor$convert_to(::QColor const &self, ::rust::cxxqtlib1::QColorSpec color_spec, ::QColor *return$) noexcept {
  ::QColor (::QColor::*convert_to$)(::rust::cxxqtlib1::QColorSpec) const = &::QColor::convertTo;
  new (return$) ::QColor((self.*convert_to$)(color_spec));
}

::std::int32_t cxxbridge1$194$QColor$cyan(::QColor const &self) noexcept {
  ::std::int32_t (::QColor::*cyan$)() const = &::QColor::cyan;
  return (self.*cyan$)();
}

void cxxbridge1$194$QColor$darker(::QColor const &self, ::std::int32_t factor, ::QColor *return$) noexcept {
  ::QColor (::QColor::*darker$)(::std::int32_t) const = &::QColor::darker;
  new (return$) ::QColor((self.*darker$)(factor));
}

::std::int32_t cxxbridge1$194$QColor$green(::QColor const &self) noexcept {
  ::std::int32_t (::QColor::*green$)() const = &::QColor::green;
  return (self.*green$)();
}

::std::int32_t cxxbridge1$194$QColor$hsl_hue(::QColor const &self) noexcept {
  ::std::int32_t (::QColor::*hsl_hue$)() const = &::QColor::hslHue;
  return (self.*hsl_hue$)();
}

::std::int32_t cxxbridge1$194$QColor$hsl_saturation(::QColor const &self) noexcept {
  ::std::int32_t (::QColor::*hsl_saturation$)() const = &::QColor::hslSaturation;
  return (self.*hsl_saturation$)();
}

::std::int32_t cxxbridge1$194$QColor$hsv_hue(::QColor const &self) noexcept {
  ::std::int32_t (::QColor::*hsv_hue$)() const = &::QColor::hsvHue;
  return (self.*hsv_hue$)();
}

::std::int32_t cxxbridge1$194$QColor$hsv_saturation(::QColor const &self) noexcept {
  ::std::int32_t (::QColor::*hsv_saturation$)() const = &::QColor::hsvSaturation;
  return (self.*hsv_saturation$)();
}

::std::int32_t cxxbridge1$194$QColor$hue(::QColor const &self) noexcept {
  ::std::int32_t (::QColor::*hue$)() const = &::QColor::hue;
  return (self.*hue$)();
}

bool cxxbridge1$194$QColor$is_valid(::QColor const &self) noexcept {
  bool (::QColor::*is_valid$)() const = &::QColor::isValid;
  return (self.*is_valid$)();
}

void cxxbridge1$194$QColor$lighter(::QColor const &self, ::std::int32_t factor, ::QColor *return$) noexcept {
  ::QColor (::QColor::*lighter$)(::std::int32_t) const = &::QColor::lighter;
  new (return$) ::QColor((self.*lighter$)(factor));
}

::std::int32_t cxxbridge1$194$QColor$lightness(::QColor const &self) noexcept {
  ::std::int32_t (::QColor::*lightness$)() const = &::QColor::lightness;
  return (self.*lightness$)();
}

::std::int32_t cxxbridge1$194$QColor$magenta(::QColor const &self) noexcept {
  ::std::int32_t (::QColor::*magenta$)() const = &::QColor::magenta;
  return (self.*magenta$)();
}

void cxxbridge1$194$QColor$name(::QColor const &self, ::rust::cxxqtlib1::QColorNameFormat format, ::QString *return$) noexcept {
  ::QString (::QColor::*name$)(::rust::cxxqtlib1::QColorNameFormat) const = &::QColor::name;
  new (return$) ::QString((self.*name$)(format));
}

::std::int32_t cxxbridge1$194$QColor$red(::QColor const &self) noexcept {
  ::std::int32_t (::QColor::*red$)() const = &::QColor::red;
  return (self.*red$)();
}

::std::int32_t cxxbridge1$194$QColor$saturation(::QColor const &self) noexcept {
  ::std::int32_t (::QColor::*saturation$)() const = &::QColor::saturation;
  return (self.*saturation$)();
}

void cxxbridge1$194$QColor$set_alpha(::QColor &self, ::std::int32_t alpha) noexcept {
  void (::QColor::*set_alpha$)(::std::int32_t) = &::QColor::setAlpha;
  (self.*set_alpha$)(alpha);
}

void cxxbridge1$194$QColor$set_blue(::QColor &self, ::std::int32_t blue) noexcept {
  void (::QColor::*set_blue$)(::std::int32_t) = &::QColor::setBlue;
  (self.*set_blue$)(blue);
}

void cxxbridge1$194$QColor$set_cmyk(::QColor &self, ::std::int32_t c, ::std::int32_t m, ::std::int32_t y, ::std::int32_t k, ::std::int32_t a) noexcept {
  void (::QColor::*set_cmyk$)(::std::int32_t, ::std::int32_t, ::std::int32_t, ::std::int32_t, ::std::int32_t) = &::QColor::setCmyk;
  (self.*set_cmyk$)(c, m, y, k, a);
}

void cxxbridge1$194$QColor$set_green(::QColor &self, ::std::int32_t green) noexcept {
  void (::QColor::*set_green$)(::std::int32_t) = &::QColor::setGreen;
  (self.*set_green$)(green);
}

void cxxbridge1$194$QColor$set_hsl(::QColor &self, ::std::int32_t h, ::std::int32_t s, ::std::int32_t l, ::std::int32_t a) noexcept {
  void (::QColor::*set_hsl$)(::std::int32_t, ::std::int32_t, ::std::int32_t, ::std::int32_t) = &::QColor::setHsl;
  (self.*set_hsl$)(h, s, l, a);
}

void cxxbridge1$194$QColor$set_hsv(::QColor &self, ::std::int32_t h, ::std::int32_t s, ::std::int32_t v, ::std::int32_t a) noexcept {
  void (::QColor::*set_hsv$)(::std::int32_t, ::std::int32_t, ::std::int32_t, ::std::int32_t) = &::QColor::setHsv;
  (self.*set_hsv$)(h, s, v, a);
}

void cxxbridge1$194$QColor$set_red(::QColor &self, ::std::int32_t red) noexcept {
  void (::QColor::*set_red$)(::std::int32_t) = &::QColor::setRed;
  (self.*set_red$)(red);
}

void cxxbridge1$194$QColor$set_rgb(::QColor &self, ::std::int32_t r, ::std::int32_t g, ::std::int32_t b, ::std::int32_t a) noexcept {
  void (::QColor::*set_rgb$)(::std::int32_t, ::std::int32_t, ::std::int32_t, ::std::int32_t) = &::QColor::setRgb;
  (self.*set_rgb$)(r, g, b, a);
}

::rust::cxxqtlib1::QColorSpec cxxbridge1$194$QColor$spec(::QColor const &self) noexcept {
  ::rust::cxxqtlib1::QColorSpec (::QColor::*spec$)() const = &::QColor::spec;
  return (self.*spec$)();
}

void cxxbridge1$194$QColor$to_cmyk(::QColor const &self, ::QColor *return$) noexcept {
  ::QColor (::QColor::*to_cmyk$)() const = &::QColor::toCmyk;
  new (return$) ::QColor((self.*to_cmyk$)());
}

void cxxbridge1$194$QColor$to_extended_rgb(::QColor const &self, ::QColor *return$) noexcept {
  ::QColor (::QColor::*to_extended_rgb$)() const = &::QColor::toExtendedRgb;
  new (return$) ::QColor((self.*to_extended_rgb$)());
}

void cxxbridge1$194$QColor$to_hsl(::QColor const &self, ::QColor *return$) noexcept {
  ::QColor (::QColor::*to_hsl$)() const = &::QColor::toHsl;
  new (return$) ::QColor((self.*to_hsl$)());
}

void cxxbridge1$194$QColor$to_hsv(::QColor const &self, ::QColor *return$) noexcept {
  ::QColor (::QColor::*to_hsv$)() const = &::QColor::toHsv;
  new (return$) ::QColor((self.*to_hsv$)());
}

void cxxbridge1$194$QColor$to_rgb(::QColor const &self, ::QColor *return$) noexcept {
  ::QColor (::QColor::*to_rgb$)() const = &::QColor::toRgb;
  new (return$) ::QColor((self.*to_rgb$)());
}

::std::int32_t cxxbridge1$194$QColor$value(::QColor const &self) noexcept {
  ::std::int32_t (::QColor::*value$)() const = &::QColor::value;
  return (self.*value$)();
}

::std::int32_t cxxbridge1$194$QColor$yellow(::QColor const &self) noexcept {
  ::std::int32_t (::QColor::*yellow$)() const = &::QColor::yellow;
  return (self.*yellow$)();
}
} // extern "C"

namespace rust {
namespace cxxqtlib1 {
extern "C" {
void rust$cxxqtlib1$cxxbridge1$194$qcolor_color_names(::QStringList *return$) noexcept {
  ::QStringList (*qcolor_color_names$)() = ::rust::cxxqtlib1::qcolorColorNames;
  new (return$) ::QStringList(qcolor_color_names$());
}

void rust$cxxqtlib1$cxxbridge1$194$qcolor_init_from_cmyk(::std::int32_t c, ::std::int32_t m, ::std::int32_t y, ::std::int32_t k, ::std::int32_t a, ::QColor *return$) noexcept {
  ::QColor (*qcolor_init_from_cmyk$)(::std::int32_t, ::std::int32_t, ::std::int32_t, ::std::int32_t, ::std::int32_t) = ::rust::cxxqtlib1::qcolorInitFromCmyk;
  new (return$) ::QColor(qcolor_init_from_cmyk$(c, m, y, k, a));
}

void rust$cxxqtlib1$cxxbridge1$194$qcolor_init_from_cmyk_f(float c, float m, float y, float k, float a, ::QColor *return$) noexcept {
  ::QColor (*qcolor_init_from_cmyk_f$)(float, float, float, float, float) = ::rust::cxxqtlib1::qcolorInitFromCmykF;
  new (return$) ::QColor(qcolor_init_from_cmyk_f$(c, m, y, k, a));
}

void rust$cxxqtlib1$cxxbridge1$194$qcolor_init_from_hsl(::std::int32_t h, ::std::int32_t s, ::std::int32_t l, ::std::int32_t a, ::QColor *return$) noexcept {
  ::QColor (*qcolor_init_from_hsl$)(::std::int32_t, ::std::int32_t, ::std::int32_t, ::std::int32_t) = ::rust::cxxqtlib1::qcolorInitFromHsl;
  new (return$) ::QColor(qcolor_init_from_hsl$(h, s, l, a));
}

void rust$cxxqtlib1$cxxbridge1$194$qcolor_init_from_hsl_f(float h, float s, float l, float a, ::QColor *return$) noexcept {
  ::QColor (*qcolor_init_from_hsl_f$)(float, float, float, float) = ::rust::cxxqtlib1::qcolorInitFromHslF;
  new (return$) ::QColor(qcolor_init_from_hsl_f$(h, s, l, a));
}

void rust$cxxqtlib1$cxxbridge1$194$qcolor_init_from_hsv(::std::int32_t h, ::std::int32_t s, ::std::int32_t v, ::std::int32_t a, ::QColor *return$) noexcept {
  ::QColor (*qcolor_init_from_hsv$)(::std::int32_t, ::std::int32_t, ::std::int32_t, ::std::int32_t) = ::rust::cxxqtlib1::qcolorInitFromHsv;
  new (return$) ::QColor(qcolor_init_from_hsv$(h, s, v, a));
}

void rust$cxxqtlib1$cxxbridge1$194$qcolor_init_from_hsv_f(float h, float s, float v, float a, ::QColor *return$) noexcept {
  ::QColor (*qcolor_init_from_hsv_f$)(float, float, float, float) = ::rust::cxxqtlib1::qcolorInitFromHsvF;
  new (return$) ::QColor(qcolor_init_from_hsv_f$(h, s, v, a));
}

void rust$cxxqtlib1$cxxbridge1$194$qcolor_init_from_rgb(::std::int32_t red, ::std::int32_t green, ::std::int32_t blue, ::std::int32_t alpha, ::QColor *return$) noexcept {
  ::QColor (*qcolor_init_from_rgb$)(::std::int32_t, ::std::int32_t, ::std::int32_t, ::std::int32_t) = ::rust::cxxqtlib1::qcolorInitFromRgb;
  new (return$) ::QColor(qcolor_init_from_rgb$(red, green, blue, alpha));
}

void rust$cxxqtlib1$cxxbridge1$194$qcolor_init_from_rgb_f(float red, float green, float blue, float alpha, ::QColor *return$) noexcept {
  ::QColor (*qcolor_init_from_rgb_f$)(float, float, float, float) = ::rust::cxxqtlib1::qcolorInitFromRgbF;
  new (return$) ::QColor(qcolor_init_from_rgb_f$(red, green, blue, alpha));
}

float rust$cxxqtlib1$cxxbridge1$194$qcolor_alpha_f(::QColor const &color) noexcept {
  float (*qcolor_alpha_f$)(::QColor const &) = ::rust::cxxqtlib1::qcolorAlphaF;
  return qcolor_alpha_f$(color);
}

float rust$cxxqtlib1$cxxbridge1$194$qcolor_black_f(::QColor const &color) noexcept {
  float (*qcolor_black_f$)(::QColor const &) = ::rust::cxxqtlib1::qcolorBlackF;
  return qcolor_black_f$(color);
}

float rust$cxxqtlib1$cxxbridge1$194$qcolor_blue_f(::QColor const &color) noexcept {
  float (*qcolor_blue_f$)(::QColor const &) = ::rust::cxxqtlib1::qcolorBlueF;
  return qcolor_blue_f$(color);
}

float rust$cxxqtlib1$cxxbridge1$194$qcolor_cyan_f(::QColor const &color) noexcept {
  float (*qcolor_cyan_f$)(::QColor const &) = ::rust::cxxqtlib1::qcolorCyanF;
  return qcolor_cyan_f$(color);
}

float rust$cxxqtlib1$cxxbridge1$194$qcolor_green_f(::QColor const &color) noexcept {
  float (*qcolor_green_f$)(::QColor const &) = ::rust::cxxqtlib1::qcolorGreenF;
  return qcolor_green_f$(color);
}

float rust$cxxqtlib1$cxxbridge1$194$qcolor_hsl_hue_f(::QColor const &color) noexcept {
  float (*qcolor_hsl_hue_f$)(::QColor const &) = ::rust::cxxqtlib1::qcolorHslHueF;
  return qcolor_hsl_hue_f$(color);
}

float rust$cxxqtlib1$cxxbridge1$194$qcolor_hsl_saturation_f(::QColor const &color) noexcept {
  float (*qcolor_hsl_saturation_f$)(::QColor const &) = ::rust::cxxqtlib1::qcolorHslSaturationF;
  return qcolor_hsl_saturation_f$(color);
}

float rust$cxxqtlib1$cxxbridge1$194$qcolor_hsv_hue_f(::QColor const &color) noexcept {
  float (*qcolor_hsv_hue_f$)(::QColor const &) = ::rust::cxxqtlib1::qcolorHsvHueF;
  return qcolor_hsv_hue_f$(color);
}

float rust$cxxqtlib1$cxxbridge1$194$qcolor_hsv_saturation_f(::QColor const &color) noexcept {
  float (*qcolor_hsv_saturation_f$)(::QColor const &) = ::rust::cxxqtlib1::qcolorHsvSaturationF;
  return qcolor_hsv_saturation_f$(color);
}

float rust$cxxqtlib1$cxxbridge1$194$qcolor_hue_f(::QColor const &color) noexcept {
  float (*qcolor_hue_f$)(::QColor const &) = ::rust::cxxqtlib1::qcolorHueF;
  return qcolor_hue_f$(color);
}

float rust$cxxqtlib1$cxxbridge1$194$qcolor_lightness_f(::QColor const &color) noexcept {
  float (*qcolor_lightness_f$)(::QColor const &) = ::rust::cxxqtlib1::qcolorLightnessF;
  return qcolor_lightness_f$(color);
}

float rust$cxxqtlib1$cxxbridge1$194$qcolor_magenta_f(::QColor const &color) noexcept {
  float (*qcolor_magenta_f$)(::QColor const &) = ::rust::cxxqtlib1::qcolorMagentaF;
  return qcolor_magenta_f$(color);
}

float rust$cxxqtlib1$cxxbridge1$194$qcolor_red_f(::QColor const &color) noexcept {
  float (*qcolor_red_f$)(::QColor const &) = ::rust::cxxqtlib1::qcolorRedF;
  return qcolor_red_f$(color);
}

float rust$cxxqtlib1$cxxbridge1$194$qcolor_saturation_f(::QColor const &color) noexcept {
  float (*qcolor_saturation_f$)(::QColor const &) = ::rust::cxxqtlib1::qcolorSaturationF;
  return qcolor_saturation_f$(color);
}

void rust$cxxqtlib1$cxxbridge1$194$qcolor_set_alpha_f(::QColor &color, float alpha) noexcept {
  void (*qcolor_set_alpha_f$)(::QColor &, float) = ::rust::cxxqtlib1::qcolorSetAlphaF;
  qcolor_set_alpha_f$(color, alpha);
}

void rust$cxxqtlib1$cxxbridge1$194$qcolor_set_blue_f(::QColor &color, float blue) noexcept {
  void (*qcolor_set_blue_f$)(::QColor &, float) = ::rust::cxxqtlib1::qcolorSetBlueF;
  qcolor_set_blue_f$(color, blue);
}

void rust$cxxqtlib1$cxxbridge1$194$qcolor_set_cmyk_f(::QColor &color, float c, float m, float y, float k, float a) noexcept {
  void (*qcolor_set_cmyk_f$)(::QColor &, float, float, float, float, float) = ::rust::cxxqtlib1::qcolorSetCmykF;
  qcolor_set_cmyk_f$(color, c, m, y, k, a);
}

void rust$cxxqtlib1$cxxbridge1$194$qcolor_set_green_f(::QColor &color, float green) noexcept {
  void (*qcolor_set_green_f$)(::QColor &, float) = ::rust::cxxqtlib1::qcolorSetGreenF;
  qcolor_set_green_f$(color, green);
}

void rust$cxxqtlib1$cxxbridge1$194$qcolor_set_hsl_f(::QColor &color, float h, float s, float l, float a) noexcept {
  void (*qcolor_set_hsl_f$)(::QColor &, float, float, float, float) = ::rust::cxxqtlib1::qcolorSetHslF;
  qcolor_set_hsl_f$(color, h, s, l, a);
}

void rust$cxxqtlib1$cxxbridge1$194$qcolor_set_hsv_f(::QColor &color, float h, float s, float v, float a) noexcept {
  void (*qcolor_set_hsv_f$)(::QColor &, float, float, float, float) = ::rust::cxxqtlib1::qcolorSetHsvF;
  qcolor_set_hsv_f$(color, h, s, v, a);
}

void rust$cxxqtlib1$cxxbridge1$194$qcolor_set_red_f(::QColor &color, float red) noexcept {
  void (*qcolor_set_red_f$)(::QColor &, float) = ::rust::cxxqtlib1::qcolorSetRedF;
  qcolor_set_red_f$(color, red);
}

void rust$cxxqtlib1$cxxbridge1$194$qcolor_set_rgb_f(::QColor &color, float r, float g, float b, float a) noexcept {
  void (*qcolor_set_rgb_f$)(::QColor &, float, float, float, float) = ::rust::cxxqtlib1::qcolorSetRgbF;
  qcolor_set_rgb_f$(color, r, g, b, a);
}

float rust$cxxqtlib1$cxxbridge1$194$qcolor_value_f(::QColor const &color) noexcept {
  float (*qcolor_value_f$)(::QColor const &) = ::rust::cxxqtlib1::qcolorValueF;
  return qcolor_value_f$(color);
}

float rust$cxxqtlib1$cxxbridge1$194$qcolor_yellow_f(::QColor const &color) noexcept {
  float (*qcolor_yellow_f$)(::QColor const &) = ::rust::cxxqtlib1::qcolorYellowF;
  return qcolor_yellow_f$(color);
}

void rust$cxxqtlib1$cxxbridge1$194$qcolor_init_default(::QColor *return$) noexcept {
  ::QColor (*qcolor_init_default$)() = ::rust::cxxqtlib1::construct;
  new (return$) ::QColor(qcolor_init_default$());
}

void rust$cxxqtlib1$cxxbridge1$194$qcolor_init_from_qstring(::QString const &name, ::QColor *return$) noexcept {
  ::QColor (*qcolor_init_from_qstring$)(::QString const &) = ::rust::cxxqtlib1::construct;
  new (return$) ::QColor(qcolor_init_from_qstring$(name));
}

bool rust$cxxqtlib1$cxxbridge1$194$qcolor_eq(::QColor const &a, ::QColor const &b) noexcept {
  bool (*qcolor_eq$)(::QColor const &, ::QColor const &) = ::rust::cxxqtlib1::operatorEq;
  return qcolor_eq$(a, b);
}
} // extern "C"
} // namespace cxxqtlib1
} // namespace rust
