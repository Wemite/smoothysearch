#include "smoothysearch/src/backend.cxxqt.h"

// Define namespace otherwise we hit a GCC bug
// https://gcc.gnu.org/bugzilla/show_bug.cgi?id=56480
namespace rust::cxxqt1 {
template <>
SignalHandler<::rust::cxxqtgen1::BackendCxxQtSignalParamscurrent_textChanged
                  *>::~SignalHandler() noexcept {
  if (data[0] == nullptr && data[1] == nullptr) {
    return;
  }

  drop_Backend_signal_handler_current_textChanged(::std::move(*this));
}

template <>
template <>
void SignalHandler<
    ::rust::cxxqtgen1::BackendCxxQtSignalParamscurrent_textChanged
        *>::operator()<Backend &>(Backend &self) {
  call_Backend_signal_handler_current_textChanged(*this, self);
}

static_assert(
    alignof(SignalHandler<::rust::cxxqtgen1::
                              BackendCxxQtSignalParamscurrent_textChanged *>) <=
        alignof(::std::size_t),
    "unexpected aligment");
static_assert(
    sizeof(SignalHandler<
           ::rust::cxxqtgen1::BackendCxxQtSignalParamscurrent_textChanged *>) ==
        sizeof(::std::size_t[2]),
    "unexpected size");
} // namespace rust::cxxqt1

namespace rust::cxxqtgen1 {
::QMetaObject::Connection Backend_current_textChangedConnect(
    Backend &self,
    ::rust::cxxqtgen1::BackendCxxQtSignalHandlercurrent_textChanged closure,
    ::Qt::ConnectionType type) {
  return ::QObject::connect(
      &self, &Backend::current_textChanged, &self,
      [&, closure = ::std::move(closure)]() mutable {
        closure.template operator()<Backend &>(self);
      },
      type);
}
} // namespace rust::cxxqtgen1

// Define namespace otherwise we hit a GCC bug
// https://gcc.gnu.org/bugzilla/show_bug.cgi?id=56480
namespace rust::cxxqt1 {
template <>
SignalHandler<::rust::cxxqtgen1::BackendCxxQtSignalParamsitemsChanged
                  *>::~SignalHandler() noexcept {
  if (data[0] == nullptr && data[1] == nullptr) {
    return;
  }

  drop_Backend_signal_handler_itemsChanged(::std::move(*this));
}

template <>
template <>
void SignalHandler<::rust::cxxqtgen1::BackendCxxQtSignalParamsitemsChanged
                       *>::operator()<Backend &>(Backend &self) {
  call_Backend_signal_handler_itemsChanged(*this, self);
}

static_assert(
    alignof(SignalHandler<
            ::rust::cxxqtgen1::BackendCxxQtSignalParamsitemsChanged *>) <=
        alignof(::std::size_t),
    "unexpected aligment");
static_assert(
    sizeof(SignalHandler<
           ::rust::cxxqtgen1::BackendCxxQtSignalParamsitemsChanged *>) ==
        sizeof(::std::size_t[2]),
    "unexpected size");
} // namespace rust::cxxqt1

namespace rust::cxxqtgen1 {
::QMetaObject::Connection Backend_itemsChangedConnect(
    Backend &self,
    ::rust::cxxqtgen1::BackendCxxQtSignalHandleritemsChanged closure,
    ::Qt::ConnectionType type) {
  return ::QObject::connect(
      &self, &Backend::itemsChanged, &self,
      [&, closure = ::std::move(closure)]() mutable {
        closure.template operator()<Backend &>(self);
      },
      type);
}
} // namespace rust::cxxqtgen1

// Define namespace otherwise we hit a GCC bug
// https://gcc.gnu.org/bugzilla/show_bug.cgi?id=56480
namespace rust::cxxqt1 {
template <>
SignalHandler<::rust::cxxqtgen1::BackendCxxQtSignalParamsicon_pathsChanged
                  *>::~SignalHandler() noexcept {
  if (data[0] == nullptr && data[1] == nullptr) {
    return;
  }

  drop_Backend_signal_handler_icon_pathsChanged(::std::move(*this));
}

template <>
template <>
void SignalHandler<::rust::cxxqtgen1::BackendCxxQtSignalParamsicon_pathsChanged
                       *>::operator()<Backend &>(Backend &self) {
  call_Backend_signal_handler_icon_pathsChanged(*this, self);
}

static_assert(
    alignof(SignalHandler<
            ::rust::cxxqtgen1::BackendCxxQtSignalParamsicon_pathsChanged *>) <=
        alignof(::std::size_t),
    "unexpected aligment");
static_assert(
    sizeof(SignalHandler<
           ::rust::cxxqtgen1::BackendCxxQtSignalParamsicon_pathsChanged *>) ==
        sizeof(::std::size_t[2]),
    "unexpected size");
} // namespace rust::cxxqt1

namespace rust::cxxqtgen1 {
::QMetaObject::Connection Backend_icon_pathsChangedConnect(
    Backend &self,
    ::rust::cxxqtgen1::BackendCxxQtSignalHandlericon_pathsChanged closure,
    ::Qt::ConnectionType type) {
  return ::QObject::connect(
      &self, &Backend::icon_pathsChanged, &self,
      [&, closure = ::std::move(closure)]() mutable {
        closure.template operator()<Backend &>(self);
      },
      type);
}
} // namespace rust::cxxqtgen1

// Define namespace otherwise we hit a GCC bug
// https://gcc.gnu.org/bugzilla/show_bug.cgi?id=56480
namespace rust::cxxqt1 {
template <>
SignalHandler<::rust::cxxqtgen1::BackendCxxQtSignalParamscurrent_indexChanged
                  *>::~SignalHandler() noexcept {
  if (data[0] == nullptr && data[1] == nullptr) {
    return;
  }

  drop_Backend_signal_handler_current_indexChanged(::std::move(*this));
}

template <>
template <>
void SignalHandler<
    ::rust::cxxqtgen1::BackendCxxQtSignalParamscurrent_indexChanged
        *>::operator()<Backend &>(Backend &self) {
  call_Backend_signal_handler_current_indexChanged(*this, self);
}

static_assert(
    alignof(SignalHandler<
            ::rust::cxxqtgen1::BackendCxxQtSignalParamscurrent_indexChanged
                *>) <= alignof(::std::size_t),
    "unexpected aligment");
static_assert(
    sizeof(SignalHandler<::rust::cxxqtgen1::
                             BackendCxxQtSignalParamscurrent_indexChanged *>) ==
        sizeof(::std::size_t[2]),
    "unexpected size");
} // namespace rust::cxxqt1

namespace rust::cxxqtgen1 {
::QMetaObject::Connection Backend_current_indexChangedConnect(
    Backend &self,
    ::rust::cxxqtgen1::BackendCxxQtSignalHandlercurrent_indexChanged closure,
    ::Qt::ConnectionType type) {
  return ::QObject::connect(
      &self, &Backend::current_indexChanged, &self,
      [&, closure = ::std::move(closure)]() mutable {
        closure.template operator()<Backend &>(self);
      },
      type);
}
} // namespace rust::cxxqtgen1

// Define namespace otherwise we hit a GCC bug
// https://gcc.gnu.org/bugzilla/show_bug.cgi?id=56480
namespace rust::cxxqt1 {
template <>
SignalHandler<
    ::rust::cxxqtgen1::BackendCxxQtSignalParamsshow_command_hintChanged
        *>::~SignalHandler() noexcept {
  if (data[0] == nullptr && data[1] == nullptr) {
    return;
  }

  drop_Backend_signal_handler_show_command_hintChanged(::std::move(*this));
}

template <>
template <>
void SignalHandler<
    ::rust::cxxqtgen1::BackendCxxQtSignalParamsshow_command_hintChanged
        *>::operator()<Backend &>(Backend &self) {
  call_Backend_signal_handler_show_command_hintChanged(*this, self);
}

static_assert(
    alignof(SignalHandler<
            ::rust::cxxqtgen1::BackendCxxQtSignalParamsshow_command_hintChanged
                *>) <= alignof(::std::size_t),
    "unexpected aligment");
static_assert(
    sizeof(SignalHandler<
           ::rust::cxxqtgen1::BackendCxxQtSignalParamsshow_command_hintChanged
               *>) == sizeof(::std::size_t[2]),
    "unexpected size");
} // namespace rust::cxxqt1

namespace rust::cxxqtgen1 {
::QMetaObject::Connection Backend_show_command_hintChangedConnect(
    Backend &self,
    ::rust::cxxqtgen1::BackendCxxQtSignalHandlershow_command_hintChanged
        closure,
    ::Qt::ConnectionType type) {
  return ::QObject::connect(
      &self, &Backend::show_command_hintChanged, &self,
      [&, closure = ::std::move(closure)]() mutable {
        closure.template operator()<Backend &>(self);
      },
      type);
}
} // namespace rust::cxxqtgen1

// Define namespace otherwise we hit a GCC bug
// https://gcc.gnu.org/bugzilla/show_bug.cgi?id=56480
namespace rust::cxxqt1 {
template <>
SignalHandler<::rust::cxxqtgen1::BackendCxxQtSignalParamscommand_previewChanged
                  *>::~SignalHandler() noexcept {
  if (data[0] == nullptr && data[1] == nullptr) {
    return;
  }

  drop_Backend_signal_handler_command_previewChanged(::std::move(*this));
}

template <>
template <>
void SignalHandler<
    ::rust::cxxqtgen1::BackendCxxQtSignalParamscommand_previewChanged
        *>::operator()<Backend &>(Backend &self) {
  call_Backend_signal_handler_command_previewChanged(*this, self);
}

static_assert(
    alignof(SignalHandler<
            ::rust::cxxqtgen1::BackendCxxQtSignalParamscommand_previewChanged
                *>) <= alignof(::std::size_t),
    "unexpected aligment");
static_assert(
    sizeof(SignalHandler<
           ::rust::cxxqtgen1::BackendCxxQtSignalParamscommand_previewChanged
               *>) == sizeof(::std::size_t[2]),
    "unexpected size");
} // namespace rust::cxxqt1

namespace rust::cxxqtgen1 {
::QMetaObject::Connection Backend_command_previewChangedConnect(
    Backend &self,
    ::rust::cxxqtgen1::BackendCxxQtSignalHandlercommand_previewChanged closure,
    ::Qt::ConnectionType type) {
  return ::QObject::connect(
      &self, &Backend::command_previewChanged, &self,
      [&, closure = ::std::move(closure)]() mutable {
        closure.template operator()<Backend &>(self);
      },
      type);
}
} // namespace rust::cxxqtgen1

Backend::Backend() : Backend(::cxx_qt_Backend::routeArguments0()) {}

Backend::Backend(::cxx_qt_Backend::CxxQtConstructorArguments0 &&args)
    : QObject(), ::rust::cxxqt1::CxxQtType<BackendRust>(
                     ::cxx_qt_Backend::newRs0(::std::move(args.new_))) {
  ::cxx_qt_Backend::initialize0(*this, ::std::move(args.initialize));
}
