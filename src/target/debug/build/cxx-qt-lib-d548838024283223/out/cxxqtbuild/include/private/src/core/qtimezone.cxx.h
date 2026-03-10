#pragma once
#include "cxx-qt-lib/qbytearray.h"
#include "cxx-qt-lib/qdatetime.h"
#include "cxx-qt-lib/core/qlist/qlist_QByteArray.h"
#include "cxx-qt-lib/qstring.h"
#include "cxx-qt-lib/qtimezone.h"
#include "cxx-qt-lib/common.h"
#include <cstdint>
#include <memory>
#include <type_traits>

using QTimeZone = ::QTimeZone;
using QTimeZoneNameType = ::QTimeZoneNameType;
using QTimeZoneTimeType = ::QTimeZoneTimeType;

static_assert(::std::is_enum<QTimeZoneNameType>::value, "expected enum");
static_assert(sizeof(QTimeZoneNameType) == sizeof(::std::int32_t), "incorrect size");
static_assert(static_cast<::std::int32_t>(QTimeZoneNameType::DefaultName) == 0, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QTimeZoneNameType::LongName) == 1, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QTimeZoneNameType::ShortName) == 2, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QTimeZoneNameType::OffsetName) == 3, "disagrees with the value in #[cxx::bridge]");

static_assert(::std::is_enum<QTimeZoneTimeType>::value, "expected enum");
static_assert(sizeof(QTimeZoneTimeType) == sizeof(::std::int32_t), "incorrect size");
static_assert(static_cast<::std::int32_t>(QTimeZoneTimeType::StandardTime) == 0, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QTimeZoneTimeType::DaylightTime) == 1, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QTimeZoneTimeType::GenericTime) == 2, "disagrees with the value in #[cxx::bridge]");
