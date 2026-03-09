#pragma once
#include "cxx-qt/connection.h"
#include <cstdint>
#include <type_traits>

namespace Qt {
  using ConnectionType = ::Qt::ConnectionType;
}

namespace Qt {
static_assert(::std::is_enum<ConnectionType>::value, "expected enum");
static_assert(sizeof(ConnectionType) == sizeof(::std::int32_t), "incorrect size");
static_assert(static_cast<::std::int32_t>(ConnectionType::AutoConnection) == 0, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(ConnectionType::DirectConnection) == 1, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(ConnectionType::QueuedConnection) == 2, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(ConnectionType::BlockingQueuedConnection) == 3, "disagrees with the value in #[cxx::bridge]");
} // namespace Qt
