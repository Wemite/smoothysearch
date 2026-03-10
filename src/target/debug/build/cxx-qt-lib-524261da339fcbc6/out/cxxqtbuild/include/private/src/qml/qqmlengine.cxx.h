#pragma once
#include "cxx-qt-lib/qstring.h"
#include "cxx-qt-lib/qstringlist.h"
#include "cxx-qt-lib/qurl.h"
#include <QtCore/QObject>
#include "cxx-qt/connection.h"
#include "private/src/qml/qqmlengine.cxxqt.h"
#include "cxx-qt-lib/qqmlengine.h"
#include <cstdint>
#include <memory>

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdollar-in-identifier-extension"
#endif // __clang__

using QQmlEngine = ::QQmlEngine;

namespace rust {
namespace cxxqtgen1 {
void drop_QQmlEngine_signal_handler_exit(::rust::cxxqtgen1::QQmlEngineCxxQtSignalHandlerexit handler) noexcept;

void call_QQmlEngine_signal_handler_exit(::rust::cxxqtgen1::QQmlEngineCxxQtSignalHandlerexit &handler, ::QQmlEngine &self_value, ::std::int32_t ret_code) noexcept;

void drop_QQmlEngine_signal_handler_quit(::rust::cxxqtgen1::QQmlEngineCxxQtSignalHandlerquit handler) noexcept;

void call_QQmlEngine_signal_handler_quit(::rust::cxxqtgen1::QQmlEngineCxxQtSignalHandlerquit &handler, ::QQmlEngine &self_value) noexcept;
} // namespace cxxqtgen1
} // namespace rust

#ifdef __clang__
#pragma clang diagnostic pop
#endif // __clang__
