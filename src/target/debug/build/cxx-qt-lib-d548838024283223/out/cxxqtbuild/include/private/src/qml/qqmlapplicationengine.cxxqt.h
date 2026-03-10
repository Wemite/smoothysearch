#pragma once

#include <cxx-qt/casting.h>
#include <cxx-qt/signalhandler.h>

namespace rust::cxxqtgen1 {
using QQmlApplicationEngineCxxQtSignalHandlerobjectCreated =
    ::rust::cxxqt1::SignalHandler<
        struct QQmlApplicationEngineCxxQtSignalParamsobjectCreated *>;
} // namespace rust::cxxqtgen1

namespace rust::cxxqtgen1 {
using QQmlApplicationEngineCxxQtSignalHandlerobjectCreationFailed =
    ::rust::cxxqt1::SignalHandler<
        struct QQmlApplicationEngineCxxQtSignalParamsobjectCreationFailed *>;
} // namespace rust::cxxqtgen1

#include "private/src/qml/qqmlapplicationengine.cxx.h"

namespace rust::cxxqtgen1 {
::QMetaObject::Connection QQmlApplicationEngine_objectCreatedConnect(
    QQmlApplicationEngine &self,
    ::rust::cxxqtgen1::QQmlApplicationEngineCxxQtSignalHandlerobjectCreated
        closure,
    ::Qt::ConnectionType type);
} // namespace rust::cxxqtgen1

namespace rust::cxxqtgen1 {
::QMetaObject::Connection QQmlApplicationEngine_objectCreationFailedConnect(
    QQmlApplicationEngine &self,
    ::rust::cxxqtgen1::
        QQmlApplicationEngineCxxQtSignalHandlerobjectCreationFailed closure,
    ::Qt::ConnectionType type);
} // namespace rust::cxxqtgen1
