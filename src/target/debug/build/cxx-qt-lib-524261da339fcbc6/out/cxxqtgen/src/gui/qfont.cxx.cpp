#include "cxx-qt-lib/qfont.h"
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
    using QFontStyle = ::rust::cxxqtlib1::QFontStyle;
    using QFontHintingPreference = ::rust::cxxqtlib1::QFontHintingPreference;
    using QFontCapitalization = ::rust::cxxqtlib1::QFontCapitalization;
    using QFontSpacingType = ::rust::cxxqtlib1::QFontSpacingType;
    using QFontStyleStrategy = ::rust::cxxqtlib1::QFontStyleStrategy;
    using QFontStyleHint = ::rust::cxxqtlib1::QFontStyleHint;
  }
}

namespace rust {
namespace cxxqtlib1 {
static_assert(::std::is_enum<QFontStyle>::value, "expected enum");
static_assert(sizeof(QFontStyle) == sizeof(::std::int32_t), "incorrect size");
static_assert(static_cast<::std::int32_t>(QFontStyle::StyleNormal) == 0, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QFontStyle::StyleItalic) == 1, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QFontStyle::StyleOblique) == 2, "disagrees with the value in #[cxx::bridge]");

static_assert(::std::is_enum<QFontHintingPreference>::value, "expected enum");
static_assert(sizeof(QFontHintingPreference) == sizeof(::std::int32_t), "incorrect size");
static_assert(static_cast<::std::int32_t>(QFontHintingPreference::PreferDefaultHinting) == 0, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QFontHintingPreference::PreferNoHinting) == 1, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QFontHintingPreference::PreferVerticalHinting) == 2, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QFontHintingPreference::PreferFullHinting) == 3, "disagrees with the value in #[cxx::bridge]");

static_assert(::std::is_enum<QFontCapitalization>::value, "expected enum");
static_assert(sizeof(QFontCapitalization) == sizeof(::std::int32_t), "incorrect size");
static_assert(static_cast<::std::int32_t>(QFontCapitalization::MixedCase) == 0, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QFontCapitalization::AllUppercase) == 1, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QFontCapitalization::AllLowercase) == 2, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QFontCapitalization::SmallCaps) == 3, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QFontCapitalization::Capitalize) == 4, "disagrees with the value in #[cxx::bridge]");

static_assert(::std::is_enum<QFontSpacingType>::value, "expected enum");
static_assert(sizeof(QFontSpacingType) == sizeof(::std::int32_t), "incorrect size");
static_assert(static_cast<::std::int32_t>(QFontSpacingType::PercentageSpacing) == 0, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QFontSpacingType::AbsoluteSpacing) == 1, "disagrees with the value in #[cxx::bridge]");

static_assert(::std::is_enum<QFontStyleStrategy>::value, "expected enum");
static_assert(sizeof(QFontStyleStrategy) == sizeof(::std::int32_t), "incorrect size");
static_assert(static_cast<::std::int32_t>(QFontStyleStrategy::PreferDefault) == 1, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QFontStyleStrategy::PreferBitmap) == 2, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QFontStyleStrategy::PreferDevice) == 4, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QFontStyleStrategy::PreferOutline) == 8, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QFontStyleStrategy::ForceOutline) == 16, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QFontStyleStrategy::PreferAntialias) == 128, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QFontStyleStrategy::NoAntialias) == 256, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QFontStyleStrategy::NoSubpixelAntialias) == 2048, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QFontStyleStrategy::PreferNoShaping) == 4096, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QFontStyleStrategy::NoFontMerging) == 32768, "disagrees with the value in #[cxx::bridge]");

static_assert(::std::is_enum<QFontStyleHint>::value, "expected enum");
static_assert(sizeof(QFontStyleHint) == sizeof(::std::int32_t), "incorrect size");
static_assert(static_cast<::std::int32_t>(QFontStyleHint::Helvetica) == 0, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QFontStyleHint::Times) == 1, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QFontStyleHint::Courier) == 2, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QFontStyleHint::OldEnglish) == 3, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QFontStyleHint::System) == 4, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QFontStyleHint::AnyStyle) == 5, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QFontStyleHint::Cursive) == 6, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QFontStyleHint::Monospace) == 7, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QFontStyleHint::Fantasy) == 8, "disagrees with the value in #[cxx::bridge]");
} // namespace cxxqtlib1
} // namespace rust

static_assert(
    ::rust::IsRelocatable<::QFont>::value,
    "type QFont should be trivially move constructible and trivially destructible in C++ to be used as a return value of `resolve`, `qfont_init_default`, `qfont_clone` in Rust");
static_assert(
    ::rust::IsRelocatable<::QString>::value,
    "type QString should be trivially move constructible and trivially destructible in C++ to be used as a return value of `default_family`, `family_or_default`, `key` in Rust");
static_assert(
    ::rust::IsRelocatable<::QStringList>::value,
    "type QStringList should be trivially move constructible and trivially destructible in C++ to be used as a return value of `families` in Rust");

extern "C" {
bool cxxbridge1$194$QFont$bold(::QFont const &self) noexcept {
  bool (::QFont::*bold$)() const = &::QFont::bold;
  return (self.*bold$)();
}

::rust::cxxqtlib1::QFontCapitalization cxxbridge1$194$QFont$capitalization(::QFont const &self) noexcept {
  ::rust::cxxqtlib1::QFontCapitalization (::QFont::*capitalization$)() const = &::QFont::capitalization;
  return (self.*capitalization$)();
}

void cxxbridge1$194$QFont$default_family(::QFont const &self, ::QString *return$) noexcept {
  ::QString (::QFont::*default_family$)() const = &::QFont::defaultFamily;
  new (return$) ::QString((self.*default_family$)());
}

bool cxxbridge1$194$QFont$exact_match(::QFont const &self) noexcept {
  bool (::QFont::*exact_match$)() const = &::QFont::exactMatch;
  return (self.*exact_match$)();
}

void cxxbridge1$194$QFont$family_or_default(::QFont const &self, ::QString *return$) noexcept {
  ::QString (::QFont::*family_or_default$)() const = &::QFont::family;
  new (return$) ::QString((self.*family_or_default$)());
}

void cxxbridge1$194$QFont$families(::QFont const &self, ::QStringList *return$) noexcept {
  ::QStringList (::QFont::*families$)() const = &::QFont::families;
  new (return$) ::QStringList((self.*families$)());
}

bool cxxbridge1$194$QFont$fixed_pitch(::QFont const &self) noexcept {
  bool (::QFont::*fixed_pitch$)() const = &::QFont::fixedPitch;
  return (self.*fixed_pitch$)();
}

bool cxxbridge1$194$QFont$from_string(::QFont &self, ::QString const &descrip) noexcept {
  bool (::QFont::*from_string$)(::QString const &) = &::QFont::fromString;
  return (self.*from_string$)(descrip);
}

::rust::cxxqtlib1::QFontHintingPreference cxxbridge1$194$QFont$hinting_preference(::QFont const &self) noexcept {
  ::rust::cxxqtlib1::QFontHintingPreference (::QFont::*hinting_preference$)() const = &::QFont::hintingPreference;
  return (self.*hinting_preference$)();
}

bool cxxbridge1$194$QFont$is_copy_of(::QFont const &self, ::QFont const &font) noexcept {
  bool (::QFont::*is_copy_of$)(::QFont const &) const = &::QFont::isCopyOf;
  return (self.*is_copy_of$)(font);
}

bool cxxbridge1$194$QFont$italic(::QFont const &self) noexcept {
  bool (::QFont::*italic$)() const = &::QFont::italic;
  return (self.*italic$)();
}

bool cxxbridge1$194$QFont$kerning(::QFont const &self) noexcept {
  bool (::QFont::*kerning$)() const = &::QFont::kerning;
  return (self.*kerning$)();
}

void cxxbridge1$194$QFont$key(::QFont const &self, ::QString *return$) noexcept {
  ::QString (::QFont::*key$)() const = &::QFont::key;
  new (return$) ::QString((self.*key$)());
}

double cxxbridge1$194$QFont$letter_spacing(::QFont const &self) noexcept {
  double (::QFont::*letter_spacing$)() const = &::QFont::letterSpacing;
  return (self.*letter_spacing$)();
}

::rust::cxxqtlib1::QFontSpacingType cxxbridge1$194$QFont$letter_spacing_type(::QFont const &self) noexcept {
  ::rust::cxxqtlib1::QFontSpacingType (::QFont::*letter_spacing_type$)() const = &::QFont::letterSpacingType;
  return (self.*letter_spacing_type$)();
}

bool cxxbridge1$194$QFont$overline(::QFont const &self) noexcept {
  bool (::QFont::*overline$)() const = &::QFont::overline;
  return (self.*overline$)();
}

::std::int32_t cxxbridge1$194$QFont$pixel_size(::QFont const &self) noexcept {
  ::std::int32_t (::QFont::*pixel_size$)() const = &::QFont::pixelSize;
  return (self.*pixel_size$)();
}

::std::int32_t cxxbridge1$194$QFont$point_size(::QFont const &self) noexcept {
  ::std::int32_t (::QFont::*point_size$)() const = &::QFont::pointSize;
  return (self.*point_size$)();
}

void cxxbridge1$194$QFont$resolve(::QFont const &self, ::QFont const &other, ::QFont *return$) noexcept {
  ::QFont (::QFont::*resolve$)(::QFont const &) const = &::QFont::resolve;
  new (return$) ::QFont((self.*resolve$)(other));
}

void cxxbridge1$194$QFont$set_bold(::QFont &self, bool enable) noexcept {
  void (::QFont::*set_bold$)(bool) = &::QFont::setBold;
  (self.*set_bold$)(enable);
}

void cxxbridge1$194$QFont$set_capitalization(::QFont &self, ::rust::cxxqtlib1::QFontCapitalization caps) noexcept {
  void (::QFont::*set_capitalization$)(::rust::cxxqtlib1::QFontCapitalization) = &::QFont::setCapitalization;
  (self.*set_capitalization$)(caps);
}

void cxxbridge1$194$QFont$set_family(::QFont &self, ::QString const &family) noexcept {
  void (::QFont::*set_family$)(::QString const &) = &::QFont::setFamily;
  (self.*set_family$)(family);
}

void cxxbridge1$194$QFont$set_families(::QFont &self, ::QStringList const &families) noexcept {
  void (::QFont::*set_families$)(::QStringList const &) = &::QFont::setFamilies;
  (self.*set_families$)(families);
}

void cxxbridge1$194$QFont$set_fixed_pitch(::QFont &self, bool enable) noexcept {
  void (::QFont::*set_fixed_pitch$)(bool) = &::QFont::setFixedPitch;
  (self.*set_fixed_pitch$)(enable);
}

void cxxbridge1$194$QFont$set_style_strategy(::QFont &self, ::rust::cxxqtlib1::QFontStyleStrategy strategy) noexcept {
  void (::QFont::*set_style_strategy$)(::rust::cxxqtlib1::QFontStyleStrategy) = &::QFont::setStyleStrategy;
  (self.*set_style_strategy$)(strategy);
}

void cxxbridge1$194$QFont$set_hinting_preference(::QFont &self, ::rust::cxxqtlib1::QFontHintingPreference hinting_preference) noexcept {
  void (::QFont::*set_hinting_preference$)(::rust::cxxqtlib1::QFontHintingPreference) = &::QFont::setHintingPreference;
  (self.*set_hinting_preference$)(hinting_preference);
}

void cxxbridge1$194$QFont$set_italic(::QFont &self, bool enable) noexcept {
  void (::QFont::*set_italic$)(bool) = &::QFont::setItalic;
  (self.*set_italic$)(enable);
}

void cxxbridge1$194$QFont$set_kerning(::QFont &self, bool enable) noexcept {
  void (::QFont::*set_kerning$)(bool) = &::QFont::setKerning;
  (self.*set_kerning$)(enable);
}

void cxxbridge1$194$QFont$set_letter_spacing(::QFont &self, ::rust::cxxqtlib1::QFontSpacingType spacing_type, double spacing) noexcept {
  void (::QFont::*set_letter_spacing$)(::rust::cxxqtlib1::QFontSpacingType, double) = &::QFont::setLetterSpacing;
  (self.*set_letter_spacing$)(spacing_type, spacing);
}

void cxxbridge1$194$QFont$set_overline(::QFont &self, bool enable) noexcept {
  void (::QFont::*set_overline$)(bool) = &::QFont::setOverline;
  (self.*set_overline$)(enable);
}

void cxxbridge1$194$QFont$set_pixel_size(::QFont &self, ::std::int32_t pixel_size) noexcept {
  void (::QFont::*set_pixel_size$)(::std::int32_t) = &::QFont::setPixelSize;
  (self.*set_pixel_size$)(pixel_size);
}

void cxxbridge1$194$QFont$set_stretch(::QFont &self, ::std::int32_t factor) noexcept {
  void (::QFont::*set_stretch$)(::std::int32_t) = &::QFont::setStretch;
  (self.*set_stretch$)(factor);
}

void cxxbridge1$194$QFont$set_strikeout(::QFont &self, bool enable) noexcept {
  void (::QFont::*set_strikeout$)(bool) = &::QFont::setStrikeOut;
  (self.*set_strikeout$)(enable);
}

void cxxbridge1$194$QFont$set_style(::QFont &self, ::rust::cxxqtlib1::QFontStyle style) noexcept {
  void (::QFont::*set_style$)(::rust::cxxqtlib1::QFontStyle) = &::QFont::setStyle;
  (self.*set_style$)(style);
}

void cxxbridge1$194$QFont$set_style_hint(::QFont &self, ::rust::cxxqtlib1::QFontStyleHint hint, ::rust::cxxqtlib1::QFontStyleStrategy strategy) noexcept {
  void (::QFont::*set_style_hint$)(::rust::cxxqtlib1::QFontStyleHint, ::rust::cxxqtlib1::QFontStyleStrategy) = &::QFont::setStyleHint;
  (self.*set_style_hint$)(hint, strategy);
}

void cxxbridge1$194$QFont$set_style_name(::QFont &self, ::QString const &style_name) noexcept {
  void (::QFont::*set_style_name$)(::QString const &) = &::QFont::setStyleName;
  (self.*set_style_name$)(style_name);
}

void cxxbridge1$194$QFont$set_underline(::QFont &self, bool enable) noexcept {
  void (::QFont::*set_underline$)(bool) = &::QFont::setUnderline;
  (self.*set_underline$)(enable);
}

void cxxbridge1$194$QFont$set_word_spacing(::QFont &self, double spacing) noexcept {
  void (::QFont::*set_word_spacing$)(double) = &::QFont::setWordSpacing;
  (self.*set_word_spacing$)(spacing);
}

::std::int32_t cxxbridge1$194$QFont$stretch(::QFont const &self) noexcept {
  ::std::int32_t (::QFont::*stretch$)() const = &::QFont::stretch;
  return (self.*stretch$)();
}

bool cxxbridge1$194$QFont$strike_out(::QFont const &self) noexcept {
  bool (::QFont::*strike_out$)() const = &::QFont::strikeOut;
  return (self.*strike_out$)();
}

::rust::cxxqtlib1::QFontStyleHint cxxbridge1$194$QFont$style_hint(::QFont const &self) noexcept {
  ::rust::cxxqtlib1::QFontStyleHint (::QFont::*style_hint$)() const = &::QFont::styleHint;
  return (self.*style_hint$)();
}

void cxxbridge1$194$QFont$style_name(::QFont const &self, ::QString *return$) noexcept {
  ::QString (::QFont::*style_name$)() const = &::QFont::styleName;
  new (return$) ::QString((self.*style_name$)());
}

::rust::cxxqtlib1::QFontStyleStrategy cxxbridge1$194$QFont$style_strategy(::QFont const &self) noexcept {
  ::rust::cxxqtlib1::QFontStyleStrategy (::QFont::*style_strategy$)() const = &::QFont::styleStrategy;
  return (self.*style_strategy$)();
}

void cxxbridge1$194$QFont$to_qstring(::QFont const &self, ::QString *return$) noexcept {
  ::QString (::QFont::*to_qstring$)() const = &::QFont::toString;
  new (return$) ::QString((self.*to_qstring$)());
}

bool cxxbridge1$194$QFont$underline(::QFont const &self) noexcept {
  bool (::QFont::*underline$)() const = &::QFont::underline;
  return (self.*underline$)();
}

double cxxbridge1$194$QFont$word_spacing(::QFont const &self) noexcept {
  double (::QFont::*word_spacing$)() const = &::QFont::wordSpacing;
  return (self.*word_spacing$)();
}
} // extern "C"

namespace rust {
namespace cxxqtlib1 {
extern "C" {
void rust$cxxqtlib1$cxxbridge1$194$qfont_init_default(::QFont *return$) noexcept {
  ::QFont (*qfont_init_default$)() = ::rust::cxxqtlib1::construct;
  new (return$) ::QFont(qfont_init_default$());
}

void rust$cxxqtlib1$cxxbridge1$194$qfont_drop(::QFont &pen) noexcept {
  void (*qfont_drop$)(::QFont &) = ::rust::cxxqtlib1::drop;
  qfont_drop$(pen);
}

void rust$cxxqtlib1$cxxbridge1$194$qfont_clone(::QFont const &font, ::QFont *return$) noexcept {
  ::QFont (*qfont_clone$)(::QFont const &) = ::rust::cxxqtlib1::construct;
  new (return$) ::QFont(qfont_clone$(font));
}

bool rust$cxxqtlib1$cxxbridge1$194$qfont_eq(::QFont const &a, ::QFont const &b) noexcept {
  bool (*qfont_eq$)(::QFont const &, ::QFont const &) = ::rust::cxxqtlib1::operatorEq;
  return qfont_eq$(a, b);
}
} // extern "C"
} // namespace cxxqtlib1
} // namespace rust
