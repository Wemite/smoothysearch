#pragma once
#include "cxx-qt-lib/qbytearray.h"
#include "cxx-qt-lib/qstring.h"
#include "cxx-qt-lib/qstringlist.h"
#include "cxx-qt-lib/core/qvector/qvector_QByteArray.h"
#include "cxx-qt-lib/qcoreapplication.h"
#include <QtCore/QObject>
#include "cxx-qt/connection.h"
#include "private/src/core/qcoreapplication.cxxqt.h"
#include <cstdint>
#include <memory>

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdollar-in-identifier-extension"
#endif // __clang__

using QCoreApplication = ::QCoreApplication;

namespace rust {
namespace cxxqtgen1 {
void drop_QCoreApplication_signal_handler_aboutToQuit(::rust::cxxqtgen1::QCoreApplicationCxxQtSignalHandleraboutToQuit handler) noexcept;

void call_QCoreApplication_signal_handler_aboutToQuit(::rust::cxxqtgen1::QCoreApplicationCxxQtSignalHandleraboutToQuit &handler, ::QCoreApplication &self_value) noexcept;
} // namespace cxxqtgen1
} // namespace rust

#ifdef __clang__
#pragma clang diagnostic pop
#endif // __clang__
