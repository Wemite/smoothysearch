#include "private/src/qml/qqmlengine.cxxqt.h"

// Define namespace otherwise we hit a GCC bug
// https://gcc.gnu.org/bugzilla/show_bug.cgi?id=56480
namespace rust::cxxqt1 {
template <>
SignalHandler<::rust::cxxqtgen1::QQmlEngineCxxQtSignalParamsexit
                  *>::~SignalHandler() noexcept {
  if (data[0] == nullptr && data[1] == nullptr) {
    return;
  }

  drop_QQmlEngine_signal_handler_exit(::std::move(*this));
}

template <>
template <>
void SignalHandler<::rust::cxxqtgen1::QQmlEngineCxxQtSignalParamsexit *>::
operator()<QQmlEngine &, ::std::int32_t>(QQmlEngine &self,
                                         ::std::int32_t ret_code) {
  call_QQmlEngine_signal_handler_exit(*this, self, ::std::move(ret_code));
}

static_assert(
    alignof(
        SignalHandler<::rust::cxxqtgen1::QQmlEngineCxxQtSignalParamsexit *>) <=
        alignof(::std::size_t),
    "unexpected aligment");
static_assert(
    sizeof(
        SignalHandler<::rust::cxxqtgen1::QQmlEngineCxxQtSignalParamsexit *>) ==
        sizeof(::std::size_t[2]),
    "unexpected size");
} // namespace rust::cxxqt1

namespace rust::cxxqtgen1 {
::QMetaObject::Connection QQmlEngine_exitConnect(
    QQmlEngine &self,
    ::rust::cxxqtgen1::QQmlEngineCxxQtSignalHandlerexit closure,
    ::Qt::ConnectionType type) {
  return ::QObject::connect(
      &self, &QQmlEngine::exit, &self,
      [&, closure = ::std::move(closure)](::std::int32_t ret_code) mutable {
        closure.template operator()<QQmlEngine &, ::std::int32_t>(
            self, ::std::move(ret_code));
      },
      type);
}
} // namespace rust::cxxqtgen1

// Define namespace otherwise we hit a GCC bug
// https://gcc.gnu.org/bugzilla/show_bug.cgi?id=56480
namespace rust::cxxqt1 {
template <>
SignalHandler<::rust::cxxqtgen1::QQmlEngineCxxQtSignalParamsquit
                  *>::~SignalHandler() noexcept {
  if (data[0] == nullptr && data[1] == nullptr) {
    return;
  }

  drop_QQmlEngine_signal_handler_quit(::std::move(*this));
}

template <>
template <>
void SignalHandler<::rust::cxxqtgen1::QQmlEngineCxxQtSignalParamsquit
                       *>::operator()<QQmlEngine &>(QQmlEngine &self) {
  call_QQmlEngine_signal_handler_quit(*this, self);
}

static_assert(
    alignof(
        SignalHandler<::rust::cxxqtgen1::QQmlEngineCxxQtSignalParamsquit *>) <=
        alignof(::std::size_t),
    "unexpected aligment");
static_assert(
    sizeof(
        SignalHandler<::rust::cxxqtgen1::QQmlEngineCxxQtSignalParamsquit *>) ==
        sizeof(::std::size_t[2]),
    "unexpected size");
} // namespace rust::cxxqt1

namespace rust::cxxqtgen1 {
::QMetaObject::Connection QQmlEngine_quitConnect(
    QQmlEngine &self,
    ::rust::cxxqtgen1::QQmlEngineCxxQtSignalHandlerquit closure,
    ::Qt::ConnectionType type) {
  return ::QObject::connect(
      &self, &QQmlEngine::quit, &self,
      [&, closure = ::std::move(closure)]() mutable {
        closure.template operator()<QQmlEngine &>(self);
      },
      type);
}
} // namespace rust::cxxqtgen1
