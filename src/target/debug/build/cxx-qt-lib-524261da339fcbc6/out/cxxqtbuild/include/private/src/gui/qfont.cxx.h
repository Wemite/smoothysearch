#pragma once
#include "cxx-qt-lib/qfont.h"
#include "cxx-qt-lib/qstring.h"
#include "cxx-qt-lib/qstringlist.h"
#include "cxx-qt-lib/common.h"
#include <cstdint>
#include <type_traits>

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
