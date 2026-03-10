#pragma once

#include <cxx-qt/casting.h>
#include <cxx-qt/signalhandler.h>

namespace rust::cxxqtgen1 {
using QCoreApplicationCxxQtSignalHandleraboutToQuit =
    ::rust::cxxqt1::SignalHandler<
        struct QCoreApplicationCxxQtSignalParamsaboutToQuit *>;
} // namespace rust::cxxqtgen1

#include "private/src/core/qcoreapplication.cxx.h"

namespace rust::cxxqtgen1 {
::QMetaObject::Connection QCoreApplication_aboutToQuitConnect(
    QCoreApplication &self,
    ::rust::cxxqtgen1::QCoreApplicationCxxQtSignalHandleraboutToQuit closure,
    ::Qt::ConnectionType type);
} // namespace rust::cxxqtgen1
