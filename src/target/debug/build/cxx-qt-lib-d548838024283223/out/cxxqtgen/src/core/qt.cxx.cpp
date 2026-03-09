#include "cxx-qt-lib/qt.h"
#include <cstdint>
#include <type_traits>

namespace Qt {
  using AspectRatioMode = ::Qt::AspectRatioMode;
  using CaseSensitivity = ::Qt::CaseSensitivity;
  using DateFormat = ::Qt::DateFormat;
  using SplitBehaviorFlags = ::Qt::SplitBehaviorFlags;
  using TimeSpec = ::Qt::TimeSpec;
  using TransformationMode = ::Qt::TransformationMode;
  using PenStyle = ::Qt::PenStyle;
  using PenCapStyle = ::Qt::PenCapStyle;
  using PenJoinStyle = ::Qt::PenJoinStyle;
  using FillRule = ::Qt::FillRule;
  using LayoutDirection = ::Qt::LayoutDirection;
  using BGMode = ::Qt::BGMode;
  using ClipOperation = ::Qt::ClipOperation;
  using SizeMode = ::Qt::SizeMode;
  using MouseButton = ::Qt::MouseButton;
  using KeyboardModifier = ::Qt::KeyboardModifier;
  using Orientation = ::Qt::Orientation;
}

namespace Qt {
static_assert(::std::is_enum<AspectRatioMode>::value, "expected enum");
static_assert(sizeof(AspectRatioMode) == sizeof(::std::int32_t), "incorrect size");
static_assert(static_cast<::std::int32_t>(AspectRatioMode::IgnoreAspectRatio) == 0, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(AspectRatioMode::KeepAspectRatio) == 1, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(AspectRatioMode::KeepAspectRatioByExpanding) == 2, "disagrees with the value in #[cxx::bridge]");

static_assert(::std::is_enum<CaseSensitivity>::value, "expected enum");
static_assert(sizeof(CaseSensitivity) == sizeof(::std::int32_t), "incorrect size");
static_assert(static_cast<::std::int32_t>(CaseSensitivity::CaseInsensitive) == 0, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(CaseSensitivity::CaseSensitive) == 1, "disagrees with the value in #[cxx::bridge]");

static_assert(::std::is_enum<DateFormat>::value, "expected enum");
static_assert(sizeof(DateFormat) == sizeof(::std::int32_t), "incorrect size");
static_assert(static_cast<::std::int32_t>(DateFormat::TextDate) == 0, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(DateFormat::ISODateWithMs) == 9, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(DateFormat::ISODate) == 1, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(DateFormat::RFC2822Date) == 8, "disagrees with the value in #[cxx::bridge]");

static_assert(::std::is_enum<SplitBehaviorFlags>::value, "expected enum");
static_assert(sizeof(SplitBehaviorFlags) == sizeof(::std::int32_t), "incorrect size");
static_assert(static_cast<::std::int32_t>(SplitBehaviorFlags::KeepEmptyParts) == 0, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(SplitBehaviorFlags::SkipEmptyParts) == 1, "disagrees with the value in #[cxx::bridge]");

static_assert(::std::is_enum<TimeSpec>::value, "expected enum");
static_assert(sizeof(TimeSpec) == sizeof(::std::int32_t), "incorrect size");
static_assert(static_cast<::std::int32_t>(TimeSpec::LocalTime) == 0, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(TimeSpec::UTC) == 1, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(TimeSpec::OffsetFromUTC) == 2, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(TimeSpec::TimeZone) == 3, "disagrees with the value in #[cxx::bridge]");

static_assert(::std::is_enum<TransformationMode>::value, "expected enum");
static_assert(sizeof(TransformationMode) == sizeof(::std::int32_t), "incorrect size");
static_assert(static_cast<::std::int32_t>(TransformationMode::FastTransformation) == 0, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(TransformationMode::SmoothTransformation) == 1, "disagrees with the value in #[cxx::bridge]");

static_assert(::std::is_enum<PenStyle>::value, "expected enum");
static_assert(sizeof(PenStyle) == sizeof(::std::int32_t), "incorrect size");
static_assert(static_cast<::std::int32_t>(PenStyle::NoPen) == 0, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(PenStyle::SolidLine) == 1, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(PenStyle::DashLine) == 2, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(PenStyle::DotLine) == 3, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(PenStyle::DashDotLine) == 4, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(PenStyle::DashDotDotLine) == 5, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(PenStyle::CustomDashLine) == 6, "disagrees with the value in #[cxx::bridge]");

static_assert(::std::is_enum<PenCapStyle>::value, "expected enum");
static_assert(sizeof(PenCapStyle) == sizeof(::std::int32_t), "incorrect size");
static_assert(static_cast<::std::int32_t>(PenCapStyle::FlatCap) == 0, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(PenCapStyle::SquareCap) == 16, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(PenCapStyle::RoundCap) == 32, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(PenCapStyle::MPenCapStyle) == 48, "disagrees with the value in #[cxx::bridge]");

static_assert(::std::is_enum<PenJoinStyle>::value, "expected enum");
static_assert(sizeof(PenJoinStyle) == sizeof(::std::int32_t), "incorrect size");
static_assert(static_cast<::std::int32_t>(PenJoinStyle::MiterJoin) == 0, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(PenJoinStyle::BevelJoin) == 64, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(PenJoinStyle::RoundJoin) == 128, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(PenJoinStyle::SvgMiterJoin) == 256, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(PenJoinStyle::MPenJoinStyle) == 448, "disagrees with the value in #[cxx::bridge]");

static_assert(::std::is_enum<FillRule>::value, "expected enum");
static_assert(sizeof(FillRule) == sizeof(::std::int32_t), "incorrect size");
static_assert(static_cast<::std::int32_t>(FillRule::OddEvenFill) == 0, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(FillRule::WindingFill) == 1, "disagrees with the value in #[cxx::bridge]");

static_assert(::std::is_enum<LayoutDirection>::value, "expected enum");
static_assert(sizeof(LayoutDirection) == sizeof(::std::int32_t), "incorrect size");
static_assert(static_cast<::std::int32_t>(LayoutDirection::LeftToRight) == 0, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(LayoutDirection::RightToLeft) == 1, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(LayoutDirection::LayoutDirectionAuto) == 2, "disagrees with the value in #[cxx::bridge]");

static_assert(::std::is_enum<BGMode>::value, "expected enum");
static_assert(sizeof(BGMode) == sizeof(::std::int32_t), "incorrect size");
static_assert(static_cast<::std::int32_t>(BGMode::TransparentMode) == 0, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(BGMode::OpaqueMode) == 1, "disagrees with the value in #[cxx::bridge]");

static_assert(::std::is_enum<ClipOperation>::value, "expected enum");
static_assert(sizeof(ClipOperation) == sizeof(::std::int32_t), "incorrect size");
static_assert(static_cast<::std::int32_t>(ClipOperation::NoClip) == 0, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(ClipOperation::ReplaceClip) == 1, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(ClipOperation::IntersectClip) == 2, "disagrees with the value in #[cxx::bridge]");

static_assert(::std::is_enum<SizeMode>::value, "expected enum");
static_assert(sizeof(SizeMode) == sizeof(::std::int32_t), "incorrect size");
static_assert(static_cast<::std::int32_t>(SizeMode::AbsoluteSize) == 0, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(SizeMode::RelativeSize) == 1, "disagrees with the value in #[cxx::bridge]");

static_assert(::std::is_enum<KeyboardModifier>::value, "expected enum");
static_assert(sizeof(KeyboardModifier) == sizeof(::std::uint32_t), "incorrect size");
static_assert(static_cast<::std::uint32_t>(KeyboardModifier::NoModifier) == 0, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::uint32_t>(KeyboardModifier::ShiftModifier) == 33554432, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::uint32_t>(KeyboardModifier::ControlModifier) == 67108864, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::uint32_t>(KeyboardModifier::AltModifier) == 134217728, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::uint32_t>(KeyboardModifier::MetaModifier) == 268435456, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::uint32_t>(KeyboardModifier::KeypadModifier) == 536870912, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::uint32_t>(KeyboardModifier::GroupSwitchModifier) == 1073741824, "disagrees with the value in #[cxx::bridge]");

static_assert(::std::is_enum<MouseButton>::value, "expected enum");
static_assert(sizeof(MouseButton) == sizeof(::std::uint32_t), "incorrect size");
static_assert(static_cast<::std::uint32_t>(MouseButton::NoButton) == 0, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::uint32_t>(MouseButton::AllButtons) == 134217727, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::uint32_t>(MouseButton::LeftButton) == 1, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::uint32_t>(MouseButton::RightButton) == 2, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::uint32_t>(MouseButton::MiddleButton) == 4, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::uint32_t>(MouseButton::BackButton) == 8, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::uint32_t>(MouseButton::ForwardButton) == 16, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::uint32_t>(MouseButton::TaskButton) == 32, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::uint32_t>(MouseButton::ExtraButton4) == 64, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::uint32_t>(MouseButton::ExtraButton5) == 128, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::uint32_t>(MouseButton::ExtraButton6) == 256, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::uint32_t>(MouseButton::ExtraButton7) == 512, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::uint32_t>(MouseButton::ExtraButton8) == 1024, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::uint32_t>(MouseButton::ExtraButton9) == 2048, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::uint32_t>(MouseButton::ExtraButton10) == 4096, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::uint32_t>(MouseButton::ExtraButton11) == 8192, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::uint32_t>(MouseButton::ExtraButton12) == 16384, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::uint32_t>(MouseButton::ExtraButton13) == 32768, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::uint32_t>(MouseButton::ExtraButton14) == 65536, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::uint32_t>(MouseButton::ExtraButton15) == 131072, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::uint32_t>(MouseButton::ExtraButton16) == 262144, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::uint32_t>(MouseButton::ExtraButton17) == 524288, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::uint32_t>(MouseButton::ExtraButton18) == 1048576, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::uint32_t>(MouseButton::ExtraButton19) == 2097152, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::uint32_t>(MouseButton::ExtraButton20) == 4194304, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::uint32_t>(MouseButton::ExtraButton21) == 8388608, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::uint32_t>(MouseButton::ExtraButton22) == 16777216, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::uint32_t>(MouseButton::ExtraButton23) == 33554432, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::uint32_t>(MouseButton::ExtraButton24) == 67108864, "disagrees with the value in #[cxx::bridge]");

static_assert(::std::is_enum<Orientation>::value, "expected enum");
static_assert(sizeof(Orientation) == sizeof(::std::uint32_t), "incorrect size");
static_assert(static_cast<::std::uint32_t>(Orientation::Horizontal) == 1, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::uint32_t>(Orientation::Vertical) == 2, "disagrees with the value in #[cxx::bridge]");
} // namespace Qt
