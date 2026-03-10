#pragma once
#include "cxx-qt-lib/qt.h"
#include "cxx-qt-lib/qpainter.h"
#include "cxx-qt-lib/qrect.h"
#include "cxx-qt-lib/qrectf.h"
#include "cxx-qt-lib/qpoint.h"
#include "cxx-qt-lib/qline.h"
#include "cxx-qt-lib/qlinef.h"
#include "cxx-qt-lib/qcolor.h"
#include "cxx-qt-lib/qimage.h"
#include "cxx-qt-lib/qstring.h"
#include "cxx-qt-lib/qpainterpath.h"
#include "cxx-qt-lib/qfont.h"
#include "cxx-qt-lib/qpen.h"
#include "cxx-qt-lib/qpolygon.h"
#include "cxx-qt-lib/qregion.h"
#include "cxx-qt-lib/core/qvector/qvector_QLine.h"
#include "cxx-qt-lib/core/qvector/qvector_QLineF.h"
#include "cxx-qt-lib/common.h"
#include <cstdint>
#include <memory>
#include <type_traits>

using QPainter = ::QPainter;
namespace rust {
  namespace cxxqtlib1 {
    using QPainterCompositionMode = ::rust::cxxqtlib1::QPainterCompositionMode;
    using QPainterRenderHint = ::rust::cxxqtlib1::QPainterRenderHint;
  }
}

namespace rust {
namespace cxxqtlib1 {
static_assert(::std::is_enum<QPainterCompositionMode>::value, "expected enum");
static_assert(sizeof(QPainterCompositionMode) == sizeof(::std::int32_t), "incorrect size");
static_assert(static_cast<::std::int32_t>(QPainterCompositionMode::CompositionMode_SourceOver) == 0, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QPainterCompositionMode::CompositionMode_DestinationOver) == 1, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QPainterCompositionMode::CompositionMode_Clear) == 2, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QPainterCompositionMode::CompositionMode_Source) == 3, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QPainterCompositionMode::CompositionMode_Destination) == 4, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QPainterCompositionMode::CompositionMode_SourceIn) == 5, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QPainterCompositionMode::CompositionMode_DestinationIn) == 6, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QPainterCompositionMode::CompositionMode_SourceOut) == 7, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QPainterCompositionMode::CompositionMode_DestinationOut) == 8, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QPainterCompositionMode::CompositionMode_SourceAtop) == 9, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QPainterCompositionMode::CompositionMode_DestinationAtop) == 10, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QPainterCompositionMode::CompositionMode_Xor) == 11, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QPainterCompositionMode::CompositionMode_Plus) == 12, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QPainterCompositionMode::CompositionMode_Multiply) == 13, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QPainterCompositionMode::CompositionMode_Screen) == 14, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QPainterCompositionMode::CompositionMode_Overlay) == 15, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QPainterCompositionMode::CompositionMode_Darken) == 16, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QPainterCompositionMode::CompositionMode_Lighten) == 17, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QPainterCompositionMode::CompositionMode_ColorDodge) == 18, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QPainterCompositionMode::CompositionMode_ColorBurn) == 19, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QPainterCompositionMode::CompositionMode_HardLight) == 20, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QPainterCompositionMode::CompositionMode_SoftLight) == 21, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QPainterCompositionMode::CompositionMode_Difference) == 22, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QPainterCompositionMode::CompositionMode_Exclusion) == 23, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QPainterCompositionMode::RasterOp_SourceOrDestination) == 24, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QPainterCompositionMode::RasterOp_SourceAndDestination) == 25, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QPainterCompositionMode::RasterOp_SourceXorDestination) == 26, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QPainterCompositionMode::RasterOp_NotSourceAndNotDestination) == 27, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QPainterCompositionMode::RasterOp_NotSourceOrNotDestination) == 28, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QPainterCompositionMode::RasterOp_NotSourceXorDestination) == 29, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QPainterCompositionMode::RasterOp_NotSource) == 30, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QPainterCompositionMode::RasterOp_NotSourceAndDestination) == 31, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QPainterCompositionMode::RasterOp_SourceAndNotDestination) == 32, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QPainterCompositionMode::RasterOp_NotSourceOrDestination) == 33, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QPainterCompositionMode::RasterOp_SourceOrNotDestination) == 34, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QPainterCompositionMode::RasterOp_ClearDestination) == 35, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QPainterCompositionMode::RasterOp_SetDestination) == 36, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QPainterCompositionMode::RasterOp_NotDestination) == 37, "disagrees with the value in #[cxx::bridge]");

static_assert(::std::is_enum<QPainterRenderHint>::value, "expected enum");
static_assert(sizeof(QPainterRenderHint) == sizeof(::std::int32_t), "incorrect size");
static_assert(static_cast<::std::int32_t>(QPainterRenderHint::Antialiasing) == 1, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QPainterRenderHint::TextAntialiasing) == 2, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QPainterRenderHint::SmoothPixmapTransform) == 4, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QPainterRenderHint::LosslessImageRendering) == 64, "disagrees with the value in #[cxx::bridge]");
} // namespace cxxqtlib1
} // namespace rust
