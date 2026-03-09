#pragma once
#include "cxx-qt-lib/qbytearray.h"
#include "cxx-qt-lib/qmap.h"
#include "cxx-qt-lib/qstring.h"
#include "cxx-qt-lib/qstringlist.h"
#include "cxx-qt-lib/qurl.h"
#include "cxx-qt-lib/qqmlengine.h"
#include <QtCore/QObject>
#include "cxx-qt/connection.h"
#include "private/src/qml/qqmlapplicationengine.cxxqt.h"
#include "cxx-qt-lib/qqmlapplicationengine.h"
#include <memory>

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdollar-in-identifier-extension"
#endif // __clang__

using QQmlApplicationEngine = ::QQmlApplicationEngine;

namespace rust {
namespace cxxqtgen1 {
void drop_QQmlApplicationEngine_signal_handler_objectCreated(::rust::cxxqtgen1::QQmlApplicationEngineCxxQtSignalHandlerobjectCreated handler) noexcept;

void call_QQmlApplicationEngine_signal_handler_objectCreated(::rust::cxxqtgen1::QQmlApplicationEngineCxxQtSignalHandlerobjectCreated &handler, ::QQmlApplicationEngine &self_value, ::QObject *qobject, ::QUrl const &url) noexcept;

void drop_QQmlApplicationEngine_signal_handler_objectCreationFailed(::rust::cxxqtgen1::QQmlApplicationEngineCxxQtSignalHandlerobjectCreationFailed handler) noexcept;

void call_QQmlApplicationEngine_signal_handler_objectCreationFailed(::rust::cxxqtgen1::QQmlApplicationEngineCxxQtSignalHandlerobjectCreationFailed &handler, ::QQmlApplicationEngine &self_value, ::QUrl const &url) noexcept;
} // namespace cxxqtgen1
} // namespace rust

#ifdef __clang__
#pragma clang diagnostic pop
#endif // __clang__
