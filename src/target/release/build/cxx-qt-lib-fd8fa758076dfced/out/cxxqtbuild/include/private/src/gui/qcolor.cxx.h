#pragma once
#include "cxx-qt-lib/qcolor.h"
#include "cxx-qt-lib/qstring.h"
#include "cxx-qt-lib/qstringlist.h"
#include "cxx-qt-lib/common.h"
#include <cstdint>
#include <type_traits>

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
