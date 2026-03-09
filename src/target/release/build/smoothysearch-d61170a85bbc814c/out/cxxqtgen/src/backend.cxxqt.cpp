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
SignalHandler<::rust::cxxqtgen1::BackendCxxQtSignalParamspreview_colorsChanged
                  *>::~SignalHandler() noexcept {
  if (data[0] == nullptr && data[1] == nullptr) {
    return;
  }

  drop_Backend_signal_handler_preview_colorsChanged(::std::move(*this));
}

template <>
template <>
void SignalHandler<
    ::rust::cxxqtgen1::BackendCxxQtSignalParamspreview_colorsChanged
        *>::operator()<Backend &>(Backend &self) {
  call_Backend_signal_handler_preview_colorsChanged(*this, self);
}

static_assert(
    alignof(SignalHandler<
            ::rust::cxxqtgen1::BackendCxxQtSignalParamspreview_colorsChanged
                *>) <= alignof(::std::size_t),
    "unexpected aligment");
static_assert(
    sizeof(SignalHandler<
           ::rust::cxxqtgen1::BackendCxxQtSignalParamspreview_colorsChanged
               *>) == sizeof(::std::size_t[2]),
    "unexpected size");
} // namespace rust::cxxqt1

namespace rust::cxxqtgen1 {
::QMetaObject::Connection Backend_preview_colorsChangedConnect(
    Backend &self,
    ::rust::cxxqtgen1::BackendCxxQtSignalHandlerpreview_colorsChanged closure,
    ::Qt::ConnectionType type) {
  return ::QObject::connect(
      &self, &Backend::preview_colorsChanged, &self,
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

// Define namespace otherwise we hit a GCC bug
// https://gcc.gnu.org/bugzilla/show_bug.cgi?id=56480
namespace rust::cxxqt1 {
template <>
SignalHandler<::rust::cxxqtgen1::BackendCxxQtSignalParamsis_themes_modeChanged
                  *>::~SignalHandler() noexcept {
  if (data[0] == nullptr && data[1] == nullptr) {
    return;
  }

  drop_Backend_signal_handler_is_themes_modeChanged(::std::move(*this));
}

template <>
template <>
void SignalHandler<
    ::rust::cxxqtgen1::BackendCxxQtSignalParamsis_themes_modeChanged
        *>::operator()<Backend &>(Backend &self) {
  call_Backend_signal_handler_is_themes_modeChanged(*this, self);
}

static_assert(
    alignof(SignalHandler<
            ::rust::cxxqtgen1::BackendCxxQtSignalParamsis_themes_modeChanged
                *>) <= alignof(::std::size_t),
    "unexpected aligment");
static_assert(
    sizeof(SignalHandler<
           ::rust::cxxqtgen1::BackendCxxQtSignalParamsis_themes_modeChanged
               *>) == sizeof(::std::size_t[2]),
    "unexpected size");
} // namespace rust::cxxqt1

namespace rust::cxxqtgen1 {
::QMetaObject::Connection Backend_is_themes_modeChangedConnect(
    Backend &self,
    ::rust::cxxqtgen1::BackendCxxQtSignalHandleris_themes_modeChanged closure,
    ::Qt::ConnectionType type) {
  return ::QObject::connect(
      &self, &Backend::is_themes_modeChanged, &self,
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
SignalHandler<::rust::cxxqtgen1::BackendCxxQtSignalParamstheme_window_bgChanged
                  *>::~SignalHandler() noexcept {
  if (data[0] == nullptr && data[1] == nullptr) {
    return;
  }

  drop_Backend_signal_handler_theme_window_bgChanged(::std::move(*this));
}

template <>
template <>
void SignalHandler<
    ::rust::cxxqtgen1::BackendCxxQtSignalParamstheme_window_bgChanged
        *>::operator()<Backend &>(Backend &self) {
  call_Backend_signal_handler_theme_window_bgChanged(*this, self);
}

static_assert(
    alignof(SignalHandler<
            ::rust::cxxqtgen1::BackendCxxQtSignalParamstheme_window_bgChanged
                *>) <= alignof(::std::size_t),
    "unexpected aligment");
static_assert(
    sizeof(SignalHandler<
           ::rust::cxxqtgen1::BackendCxxQtSignalParamstheme_window_bgChanged
               *>) == sizeof(::std::size_t[2]),
    "unexpected size");
} // namespace rust::cxxqt1

namespace rust::cxxqtgen1 {
::QMetaObject::Connection Backend_theme_window_bgChangedConnect(
    Backend &self,
    ::rust::cxxqtgen1::BackendCxxQtSignalHandlertheme_window_bgChanged closure,
    ::Qt::ConnectionType type) {
  return ::QObject::connect(
      &self, &Backend::theme_window_bgChanged, &self,
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
SignalHandler<::rust::cxxqtgen1::BackendCxxQtSignalParamstheme_borderChanged
                  *>::~SignalHandler() noexcept {
  if (data[0] == nullptr && data[1] == nullptr) {
    return;
  }

  drop_Backend_signal_handler_theme_borderChanged(::std::move(*this));
}

template <>
template <>
void SignalHandler<
    ::rust::cxxqtgen1::BackendCxxQtSignalParamstheme_borderChanged
        *>::operator()<Backend &>(Backend &self) {
  call_Backend_signal_handler_theme_borderChanged(*this, self);
}

static_assert(
    alignof(SignalHandler<::rust::cxxqtgen1::
                              BackendCxxQtSignalParamstheme_borderChanged *>) <=
        alignof(::std::size_t),
    "unexpected aligment");
static_assert(
    sizeof(SignalHandler<
           ::rust::cxxqtgen1::BackendCxxQtSignalParamstheme_borderChanged *>) ==
        sizeof(::std::size_t[2]),
    "unexpected size");
} // namespace rust::cxxqt1

namespace rust::cxxqtgen1 {
::QMetaObject::Connection Backend_theme_borderChangedConnect(
    Backend &self,
    ::rust::cxxqtgen1::BackendCxxQtSignalHandlertheme_borderChanged closure,
    ::Qt::ConnectionType type) {
  return ::QObject::connect(
      &self, &Backend::theme_borderChanged, &self,
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
SignalHandler<::rust::cxxqtgen1::BackendCxxQtSignalParamstheme_input_bgChanged
                  *>::~SignalHandler() noexcept {
  if (data[0] == nullptr && data[1] == nullptr) {
    return;
  }

  drop_Backend_signal_handler_theme_input_bgChanged(::std::move(*this));
}

template <>
template <>
void SignalHandler<
    ::rust::cxxqtgen1::BackendCxxQtSignalParamstheme_input_bgChanged
        *>::operator()<Backend &>(Backend &self) {
  call_Backend_signal_handler_theme_input_bgChanged(*this, self);
}

static_assert(
    alignof(SignalHandler<
            ::rust::cxxqtgen1::BackendCxxQtSignalParamstheme_input_bgChanged
                *>) <= alignof(::std::size_t),
    "unexpected aligment");
static_assert(
    sizeof(SignalHandler<
           ::rust::cxxqtgen1::BackendCxxQtSignalParamstheme_input_bgChanged
               *>) == sizeof(::std::size_t[2]),
    "unexpected size");
} // namespace rust::cxxqt1

namespace rust::cxxqtgen1 {
::QMetaObject::Connection Backend_theme_input_bgChangedConnect(
    Backend &self,
    ::rust::cxxqtgen1::BackendCxxQtSignalHandlertheme_input_bgChanged closure,
    ::Qt::ConnectionType type) {
  return ::QObject::connect(
      &self, &Backend::theme_input_bgChanged, &self,
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
SignalHandler<::rust::cxxqtgen1::BackendCxxQtSignalParamstheme_textChanged
                  *>::~SignalHandler() noexcept {
  if (data[0] == nullptr && data[1] == nullptr) {
    return;
  }

  drop_Backend_signal_handler_theme_textChanged(::std::move(*this));
}

template <>
template <>
void SignalHandler<::rust::cxxqtgen1::BackendCxxQtSignalParamstheme_textChanged
                       *>::operator()<Backend &>(Backend &self) {
  call_Backend_signal_handler_theme_textChanged(*this, self);
}

static_assert(
    alignof(SignalHandler<
            ::rust::cxxqtgen1::BackendCxxQtSignalParamstheme_textChanged *>) <=
        alignof(::std::size_t),
    "unexpected aligment");
static_assert(
    sizeof(SignalHandler<
           ::rust::cxxqtgen1::BackendCxxQtSignalParamstheme_textChanged *>) ==
        sizeof(::std::size_t[2]),
    "unexpected size");
} // namespace rust::cxxqt1

namespace rust::cxxqtgen1 {
::QMetaObject::Connection Backend_theme_textChangedConnect(
    Backend &self,
    ::rust::cxxqtgen1::BackendCxxQtSignalHandlertheme_textChanged closure,
    ::Qt::ConnectionType type) {
  return ::QObject::connect(
      &self, &Backend::theme_textChanged, &self,
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
SignalHandler<::rust::cxxqtgen1::BackendCxxQtSignalParamstheme_text_dimChanged
                  *>::~SignalHandler() noexcept {
  if (data[0] == nullptr && data[1] == nullptr) {
    return;
  }

  drop_Backend_signal_handler_theme_text_dimChanged(::std::move(*this));
}

template <>
template <>
void SignalHandler<
    ::rust::cxxqtgen1::BackendCxxQtSignalParamstheme_text_dimChanged
        *>::operator()<Backend &>(Backend &self) {
  call_Backend_signal_handler_theme_text_dimChanged(*this, self);
}

static_assert(
    alignof(SignalHandler<
            ::rust::cxxqtgen1::BackendCxxQtSignalParamstheme_text_dimChanged
                *>) <= alignof(::std::size_t),
    "unexpected aligment");
static_assert(
    sizeof(SignalHandler<
           ::rust::cxxqtgen1::BackendCxxQtSignalParamstheme_text_dimChanged
               *>) == sizeof(::std::size_t[2]),
    "unexpected size");
} // namespace rust::cxxqt1

namespace rust::cxxqtgen1 {
::QMetaObject::Connection Backend_theme_text_dimChangedConnect(
    Backend &self,
    ::rust::cxxqtgen1::BackendCxxQtSignalHandlertheme_text_dimChanged closure,
    ::Qt::ConnectionType type) {
  return ::QObject::connect(
      &self, &Backend::theme_text_dimChanged, &self,
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
SignalHandler<::rust::cxxqtgen1::BackendCxxQtSignalParamstheme_highlightChanged
                  *>::~SignalHandler() noexcept {
  if (data[0] == nullptr && data[1] == nullptr) {
    return;
  }

  drop_Backend_signal_handler_theme_highlightChanged(::std::move(*this));
}

template <>
template <>
void SignalHandler<
    ::rust::cxxqtgen1::BackendCxxQtSignalParamstheme_highlightChanged
        *>::operator()<Backend &>(Backend &self) {
  call_Backend_signal_handler_theme_highlightChanged(*this, self);
}

static_assert(
    alignof(SignalHandler<
            ::rust::cxxqtgen1::BackendCxxQtSignalParamstheme_highlightChanged
                *>) <= alignof(::std::size_t),
    "unexpected aligment");
static_assert(
    sizeof(SignalHandler<
           ::rust::cxxqtgen1::BackendCxxQtSignalParamstheme_highlightChanged
               *>) == sizeof(::std::size_t[2]),
    "unexpected size");
} // namespace rust::cxxqt1

namespace rust::cxxqtgen1 {
::QMetaObject::Connection Backend_theme_highlightChangedConnect(
    Backend &self,
    ::rust::cxxqtgen1::BackendCxxQtSignalHandlertheme_highlightChanged closure,
    ::Qt::ConnectionType type) {
  return ::QObject::connect(
      &self, &Backend::theme_highlightChanged, &self,
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
    ::rust::cxxqtgen1::BackendCxxQtSignalParamstheme_highlight_textChanged
        *>::~SignalHandler() noexcept {
  if (data[0] == nullptr && data[1] == nullptr) {
    return;
  }

  drop_Backend_signal_handler_theme_highlight_textChanged(::std::move(*this));
}

template <>
template <>
void SignalHandler<
    ::rust::cxxqtgen1::BackendCxxQtSignalParamstheme_highlight_textChanged
        *>::operator()<Backend &>(Backend &self) {
  call_Backend_signal_handler_theme_highlight_textChanged(*this, self);
}

static_assert(
    alignof(SignalHandler<
            ::rust::cxxqtgen1::
                BackendCxxQtSignalParamstheme_highlight_textChanged *>) <=
        alignof(::std::size_t),
    "unexpected aligment");
static_assert(
    sizeof(SignalHandler<
           ::rust::cxxqtgen1::
               BackendCxxQtSignalParamstheme_highlight_textChanged *>) ==
        sizeof(::std::size_t[2]),
    "unexpected size");
} // namespace rust::cxxqt1

namespace rust::cxxqtgen1 {
::QMetaObject::Connection Backend_theme_highlight_textChangedConnect(
    Backend &self,
    ::rust::cxxqtgen1::BackendCxxQtSignalHandlertheme_highlight_textChanged
        closure,
    ::Qt::ConnectionType type) {
  return ::QObject::connect(
      &self, &Backend::theme_highlight_textChanged, &self,
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
