#pragma once
#include "cxx-qt-lib/qstring.h"
#include "cxx-qt-lib/qtlogging.h"
#include "cxx-qt-lib/common.h"
#include <cstdint>
#include <type_traits>

using QtMsgType = ::QtMsgType;

static_assert(::std::is_enum<QtMsgType>::value, "expected enum");
static_assert(sizeof(QtMsgType) == sizeof(::std::int32_t), "incorrect size");
static_assert(static_cast<::std::int32_t>(QtMsgType::QtDebugMsg) == 0, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QtMsgType::QtInfoMsg) == 4, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QtMsgType::QtWarningMsg) == 1, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QtMsgType::QtFatalMsg) == 3, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QtMsgType::QtCriticalMsg) == 2, "disagrees with the value in #[cxx::bridge]");
