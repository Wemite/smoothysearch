#pragma once

#include <cxx-qt/casting.h>
#include <cxx-qt/signalhandler.h>

namespace rust::cxxqtgen1 {
using QQmlEngineCxxQtSignalHandlerexit =
    ::rust::cxxqt1::SignalHandler<struct QQmlEngineCxxQtSignalParamsexit *>;
} // namespace rust::cxxqtgen1

namespace rust::cxxqtgen1 {
using QQmlEngineCxxQtSignalHandlerquit =
    ::rust::cxxqt1::SignalHandler<struct QQmlEngineCxxQtSignalParamsquit *>;
} // namespace rust::cxxqtgen1

#include "private/src/qml/qqmlengine.cxx.h"

namespace rust::cxxqtgen1 {
::QMetaObject::Connection QQmlEngine_exitConnect(
    QQmlEngine &self,
    ::rust::cxxqtgen1::QQmlEngineCxxQtSignalHandlerexit closure,
    ::Qt::ConnectionType type);
} // namespace rust::cxxqtgen1

namespace rust::cxxqtgen1 {
::QMetaObject::Connection QQmlEngine_quitConnect(
    QQmlEngine &self,
    ::rust::cxxqtgen1::QQmlEngineCxxQtSignalHandlerquit closure,
    ::Qt::ConnectionType type);
} // namespace rust::cxxqtgen1
