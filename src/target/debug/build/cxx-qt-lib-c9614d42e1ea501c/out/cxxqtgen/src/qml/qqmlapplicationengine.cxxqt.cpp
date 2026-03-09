#include "private/src/qml/qqmlapplicationengine.cxxqt.h"

// Define namespace otherwise we hit a GCC bug
// https://gcc.gnu.org/bugzilla/show_bug.cgi?id=56480
namespace rust::cxxqt1 {
template <>
SignalHandler<
    ::rust::cxxqtgen1::QQmlApplicationEngineCxxQtSignalParamsobjectCreated
        *>::~SignalHandler() noexcept {
  if (data[0] == nullptr && data[1] == nullptr) {
    return;
  }

  drop_QQmlApplicationEngine_signal_handler_objectCreated(::std::move(*this));
}

template <>
template <>
void SignalHandler<
    ::rust::cxxqtgen1::QQmlApplicationEngineCxxQtSignalParamsobjectCreated *>::
operator()<QQmlApplicationEngine &, QObject *, QUrl const &>(
    QQmlApplicationEngine &self, QObject *qobject, QUrl const &url) {
  call_QQmlApplicationEngine_signal_handler_objectCreated(
      *this, self, ::std::move(qobject), ::std::move(url));
}

static_assert(
    alignof(SignalHandler<
            ::rust::cxxqtgen1::
                QQmlApplicationEngineCxxQtSignalParamsobjectCreated *>) <=
        alignof(::std::size_t),
    "unexpected aligment");
static_assert(
    sizeof(SignalHandler<
           ::rust::cxxqtgen1::
               QQmlApplicationEngineCxxQtSignalParamsobjectCreated *>) ==
        sizeof(::std::size_t[2]),
    "unexpected size");
} // namespace rust::cxxqt1

namespace rust::cxxqtgen1 {
::QMetaObject::Connection QQmlApplicationEngine_objectCreatedConnect(
    QQmlApplicationEngine &self,
    ::rust::cxxqtgen1::QQmlApplicationEngineCxxQtSignalHandlerobjectCreated
        closure,
    ::Qt::ConnectionType type) {
  return ::QObject::connect(
      &self, &QQmlApplicationEngine::objectCreated, &self,
      [&, closure = ::std::move(closure)](QObject *qobject,
                                          QUrl const &url) mutable {
        closure.template
        operator()<QQmlApplicationEngine &, QObject *, QUrl const &>(
            self, ::std::move(qobject), ::std::move(url));
      },
      type);
}
} // namespace rust::cxxqtgen1

// Define namespace otherwise we hit a GCC bug
// https://gcc.gnu.org/bugzilla/show_bug.cgi?id=56480
namespace rust::cxxqt1 {
template <>
SignalHandler<::rust::cxxqtgen1::
                  QQmlApplicationEngineCxxQtSignalParamsobjectCreationFailed
                      *>::~SignalHandler() noexcept {
  if (data[0] == nullptr && data[1] == nullptr) {
    return;
  }

  drop_QQmlApplicationEngine_signal_handler_objectCreationFailed(
      ::std::move(*this));
}

template <>
template <>
void SignalHandler<
    ::rust::cxxqtgen1::
        QQmlApplicationEngineCxxQtSignalParamsobjectCreationFailed *>::
operator()<QQmlApplicationEngine &, QUrl const &>(QQmlApplicationEngine &self,
                                                  QUrl const &url) {
  call_QQmlApplicationEngine_signal_handler_objectCreationFailed(
      *this, self, ::std::move(url));
}

static_assert(
    alignof(SignalHandler<
            ::rust::cxxqtgen1::
                QQmlApplicationEngineCxxQtSignalParamsobjectCreationFailed
                    *>) <= alignof(::std::size_t),
    "unexpected aligment");
static_assert(
    sizeof(SignalHandler<
           ::rust::cxxqtgen1::
               QQmlApplicationEngineCxxQtSignalParamsobjectCreationFailed *>) ==
        sizeof(::std::size_t[2]),
    "unexpected size");
} // namespace rust::cxxqt1

namespace rust::cxxqtgen1 {
::QMetaObject::Connection QQmlApplicationEngine_objectCreationFailedConnect(
    QQmlApplicationEngine &self,
    ::rust::cxxqtgen1::
        QQmlApplicationEngineCxxQtSignalHandlerobjectCreationFailed closure,
    ::Qt::ConnectionType type) {
  return ::QObject::connect(
      &self, &QQmlApplicationEngine::objectCreationFailed, &self,
      [&, closure = ::std::move(closure)](QUrl const &url) mutable {
        closure.template operator()<QQmlApplicationEngine &, QUrl const &>(
            self, ::std::move(url));
      },
      type);
}
} // namespace rust::cxxqtgen1
