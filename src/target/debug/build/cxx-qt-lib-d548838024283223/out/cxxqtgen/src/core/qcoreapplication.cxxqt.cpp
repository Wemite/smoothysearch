#include "private/src/core/qcoreapplication.cxxqt.h"

// Define namespace otherwise we hit a GCC bug
// https://gcc.gnu.org/bugzilla/show_bug.cgi?id=56480
namespace rust::cxxqt1 {
template <>
SignalHandler<::rust::cxxqtgen1::QCoreApplicationCxxQtSignalParamsaboutToQuit
                  *>::~SignalHandler() noexcept {
  if (data[0] == nullptr && data[1] == nullptr) {
    return;
  }

  drop_QCoreApplication_signal_handler_aboutToQuit(::std::move(*this));
}

template <>
template <>
void SignalHandler<
    ::rust::cxxqtgen1::QCoreApplicationCxxQtSignalParamsaboutToQuit
        *>::operator()<QCoreApplication &>(QCoreApplication &self) {
  call_QCoreApplication_signal_handler_aboutToQuit(*this, self);
}

static_assert(
    alignof(SignalHandler<
            ::rust::cxxqtgen1::QCoreApplicationCxxQtSignalParamsaboutToQuit
                *>) <= alignof(::std::size_t),
    "unexpected aligment");
static_assert(
    sizeof(SignalHandler<::rust::cxxqtgen1::
                             QCoreApplicationCxxQtSignalParamsaboutToQuit *>) ==
        sizeof(::std::size_t[2]),
    "unexpected size");
} // namespace rust::cxxqt1

namespace rust::cxxqtgen1 {
::QMetaObject::Connection QCoreApplication_aboutToQuitConnect(
    QCoreApplication &self,
    ::rust::cxxqtgen1::QCoreApplicationCxxQtSignalHandleraboutToQuit closure,
    ::Qt::ConnectionType type) {
  return ::QObject::connect(
      &self, &QCoreApplication::aboutToQuit, &self,
      [&, closure = ::std::move(closure)]() mutable {
        closure.template operator()<QCoreApplication &>(self);
      },
      type);
}
} // namespace rust::cxxqtgen1
