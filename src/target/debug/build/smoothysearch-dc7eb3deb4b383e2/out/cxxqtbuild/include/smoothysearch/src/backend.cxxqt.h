#pragma once

#include <cxx-qt/casting.h>
#include <cxx-qt/signalhandler.h>
#include <cxx-qt/type.h>

class Backend;

namespace rust::cxxqtgen1 {
using BackendCxxQtSignalHandlercurrent_textChanged =
    ::rust::cxxqt1::SignalHandler<
        struct BackendCxxQtSignalParamscurrent_textChanged *>;
} // namespace rust::cxxqtgen1

namespace rust::cxxqtgen1 {
using BackendCxxQtSignalHandleritemsChanged = ::rust::cxxqt1::SignalHandler<
    struct BackendCxxQtSignalParamsitemsChanged *>;
} // namespace rust::cxxqtgen1

namespace rust::cxxqtgen1 {
using BackendCxxQtSignalHandlericon_pathsChanged =
    ::rust::cxxqt1::SignalHandler<
        struct BackendCxxQtSignalParamsicon_pathsChanged *>;
} // namespace rust::cxxqtgen1

namespace rust::cxxqtgen1 {
using BackendCxxQtSignalHandlerpreview_colorsChanged =
    ::rust::cxxqt1::SignalHandler<
        struct BackendCxxQtSignalParamspreview_colorsChanged *>;
} // namespace rust::cxxqtgen1

namespace rust::cxxqtgen1 {
using BackendCxxQtSignalHandlercurrent_indexChanged =
    ::rust::cxxqt1::SignalHandler<
        struct BackendCxxQtSignalParamscurrent_indexChanged *>;
} // namespace rust::cxxqtgen1

namespace rust::cxxqtgen1 {
using BackendCxxQtSignalHandlershow_command_hintChanged =
    ::rust::cxxqt1::SignalHandler<
        struct BackendCxxQtSignalParamsshow_command_hintChanged *>;
} // namespace rust::cxxqtgen1

namespace rust::cxxqtgen1 {
using BackendCxxQtSignalHandlercommand_previewChanged =
    ::rust::cxxqt1::SignalHandler<
        struct BackendCxxQtSignalParamscommand_previewChanged *>;
} // namespace rust::cxxqtgen1

namespace rust::cxxqtgen1 {
using BackendCxxQtSignalHandleris_themes_modeChanged =
    ::rust::cxxqt1::SignalHandler<
        struct BackendCxxQtSignalParamsis_themes_modeChanged *>;
} // namespace rust::cxxqtgen1

namespace rust::cxxqtgen1 {
using BackendCxxQtSignalHandlertheme_window_bgChanged =
    ::rust::cxxqt1::SignalHandler<
        struct BackendCxxQtSignalParamstheme_window_bgChanged *>;
} // namespace rust::cxxqtgen1

namespace rust::cxxqtgen1 {
using BackendCxxQtSignalHandlertheme_borderChanged =
    ::rust::cxxqt1::SignalHandler<
        struct BackendCxxQtSignalParamstheme_borderChanged *>;
} // namespace rust::cxxqtgen1

namespace rust::cxxqtgen1 {
using BackendCxxQtSignalHandlertheme_input_bgChanged =
    ::rust::cxxqt1::SignalHandler<
        struct BackendCxxQtSignalParamstheme_input_bgChanged *>;
} // namespace rust::cxxqtgen1

namespace rust::cxxqtgen1 {
using BackendCxxQtSignalHandlertheme_textChanged =
    ::rust::cxxqt1::SignalHandler<
        struct BackendCxxQtSignalParamstheme_textChanged *>;
} // namespace rust::cxxqtgen1

namespace rust::cxxqtgen1 {
using BackendCxxQtSignalHandlertheme_text_dimChanged =
    ::rust::cxxqt1::SignalHandler<
        struct BackendCxxQtSignalParamstheme_text_dimChanged *>;
} // namespace rust::cxxqtgen1

namespace rust::cxxqtgen1 {
using BackendCxxQtSignalHandlertheme_highlightChanged =
    ::rust::cxxqt1::SignalHandler<
        struct BackendCxxQtSignalParamstheme_highlightChanged *>;
} // namespace rust::cxxqtgen1

namespace rust::cxxqtgen1 {
using BackendCxxQtSignalHandlertheme_highlight_textChanged =
    ::rust::cxxqt1::SignalHandler<
        struct BackendCxxQtSignalParamstheme_highlight_textChanged *>;
} // namespace rust::cxxqtgen1

#include "smoothysearch/src/backend.cxx.h"

namespace rust::cxxqtgen1 {
::QMetaObject::Connection Backend_current_textChangedConnect(
    Backend &self,
    ::rust::cxxqtgen1::BackendCxxQtSignalHandlercurrent_textChanged closure,
    ::Qt::ConnectionType type);
} // namespace rust::cxxqtgen1

namespace rust::cxxqtgen1 {
::QMetaObject::Connection Backend_itemsChangedConnect(
    Backend &self,
    ::rust::cxxqtgen1::BackendCxxQtSignalHandleritemsChanged closure,
    ::Qt::ConnectionType type);
} // namespace rust::cxxqtgen1

namespace rust::cxxqtgen1 {
::QMetaObject::Connection Backend_icon_pathsChangedConnect(
    Backend &self,
    ::rust::cxxqtgen1::BackendCxxQtSignalHandlericon_pathsChanged closure,
    ::Qt::ConnectionType type);
} // namespace rust::cxxqtgen1

namespace rust::cxxqtgen1 {
::QMetaObject::Connection Backend_preview_colorsChangedConnect(
    Backend &self,
    ::rust::cxxqtgen1::BackendCxxQtSignalHandlerpreview_colorsChanged closure,
    ::Qt::ConnectionType type);
} // namespace rust::cxxqtgen1

namespace rust::cxxqtgen1 {
::QMetaObject::Connection Backend_current_indexChangedConnect(
    Backend &self,
    ::rust::cxxqtgen1::BackendCxxQtSignalHandlercurrent_indexChanged closure,
    ::Qt::ConnectionType type);
} // namespace rust::cxxqtgen1

namespace rust::cxxqtgen1 {
::QMetaObject::Connection Backend_show_command_hintChangedConnect(
    Backend &self,
    ::rust::cxxqtgen1::BackendCxxQtSignalHandlershow_command_hintChanged
        closure,
    ::Qt::ConnectionType type);
} // namespace rust::cxxqtgen1

namespace rust::cxxqtgen1 {
::QMetaObject::Connection Backend_command_previewChangedConnect(
    Backend &self,
    ::rust::cxxqtgen1::BackendCxxQtSignalHandlercommand_previewChanged closure,
    ::Qt::ConnectionType type);
} // namespace rust::cxxqtgen1

namespace rust::cxxqtgen1 {
::QMetaObject::Connection Backend_is_themes_modeChangedConnect(
    Backend &self,
    ::rust::cxxqtgen1::BackendCxxQtSignalHandleris_themes_modeChanged closure,
    ::Qt::ConnectionType type);
} // namespace rust::cxxqtgen1

namespace rust::cxxqtgen1 {
::QMetaObject::Connection Backend_theme_window_bgChangedConnect(
    Backend &self,
    ::rust::cxxqtgen1::BackendCxxQtSignalHandlertheme_window_bgChanged closure,
    ::Qt::ConnectionType type);
} // namespace rust::cxxqtgen1

namespace rust::cxxqtgen1 {
::QMetaObject::Connection Backend_theme_borderChangedConnect(
    Backend &self,
    ::rust::cxxqtgen1::BackendCxxQtSignalHandlertheme_borderChanged closure,
    ::Qt::ConnectionType type);
} // namespace rust::cxxqtgen1

namespace rust::cxxqtgen1 {
::QMetaObject::Connection Backend_theme_input_bgChangedConnect(
    Backend &self,
    ::rust::cxxqtgen1::BackendCxxQtSignalHandlertheme_input_bgChanged closure,
    ::Qt::ConnectionType type);
} // namespace rust::cxxqtgen1

namespace rust::cxxqtgen1 {
::QMetaObject::Connection Backend_theme_textChangedConnect(
    Backend &self,
    ::rust::cxxqtgen1::BackendCxxQtSignalHandlertheme_textChanged closure,
    ::Qt::ConnectionType type);
} // namespace rust::cxxqtgen1

namespace rust::cxxqtgen1 {
::QMetaObject::Connection Backend_theme_text_dimChangedConnect(
    Backend &self,
    ::rust::cxxqtgen1::BackendCxxQtSignalHandlertheme_text_dimChanged closure,
    ::Qt::ConnectionType type);
} // namespace rust::cxxqtgen1

namespace rust::cxxqtgen1 {
::QMetaObject::Connection Backend_theme_highlightChangedConnect(
    Backend &self,
    ::rust::cxxqtgen1::BackendCxxQtSignalHandlertheme_highlightChanged closure,
    ::Qt::ConnectionType type);
} // namespace rust::cxxqtgen1

namespace rust::cxxqtgen1 {
::QMetaObject::Connection Backend_theme_highlight_textChangedConnect(
    Backend &self,
    ::rust::cxxqtgen1::BackendCxxQtSignalHandlertheme_highlight_textChanged
        closure,
    ::Qt::ConnectionType type);
} // namespace rust::cxxqtgen1

class Backend : public QObject, private ::rust::cxxqt1::CxxQtType<BackendRust> {
  Q_OBJECT
public:
  QML_NAMED_ELEMENT(Backend)
  Q_PROPERTY(QString current_text READ getCurrent_text WRITE setCurrent_text
                 NOTIFY current_textChanged)
  Q_PROPERTY(QStringList items READ getItems WRITE setItems NOTIFY itemsChanged)
  Q_PROPERTY(QStringList icon_paths READ getIcon_paths WRITE setIcon_paths
                 NOTIFY icon_pathsChanged)
  Q_PROPERTY(QStringList preview_colors READ getPreview_colors WRITE
                 setPreview_colors NOTIFY preview_colorsChanged)
  Q_PROPERTY(::std::int32_t current_index READ getCurrent_index WRITE
                 setCurrent_index NOTIFY current_indexChanged)
  Q_PROPERTY(bool show_command_hint READ getShow_command_hint WRITE
                 setShow_command_hint NOTIFY show_command_hintChanged)
  Q_PROPERTY(QString command_preview READ getCommand_preview WRITE
                 setCommand_preview NOTIFY command_previewChanged)
  Q_PROPERTY(bool is_themes_mode READ getIs_themes_mode WRITE setIs_themes_mode
                 NOTIFY is_themes_modeChanged)
  Q_PROPERTY(QString theme_window_bg READ getTheme_window_bg WRITE
                 setTheme_window_bg NOTIFY theme_window_bgChanged)
  Q_PROPERTY(QString theme_border READ getTheme_border WRITE setTheme_border
                 NOTIFY theme_borderChanged)
  Q_PROPERTY(QString theme_input_bg READ getTheme_input_bg WRITE
                 setTheme_input_bg NOTIFY theme_input_bgChanged)
  Q_PROPERTY(QString theme_text READ getTheme_text WRITE setTheme_text NOTIFY
                 theme_textChanged)
  Q_PROPERTY(QString theme_text_dim READ getTheme_text_dim WRITE
                 setTheme_text_dim NOTIFY theme_text_dimChanged)
  Q_PROPERTY(QString theme_highlight READ getTheme_highlight WRITE
                 setTheme_highlight NOTIFY theme_highlightChanged)
  Q_PROPERTY(QString theme_highlight_text READ getTheme_highlight_text WRITE
                 setTheme_highlight_text NOTIFY theme_highlight_textChanged)

  virtual ~Backend() = default;

public:
  QString const &getCurrent_text() const noexcept;
  Q_SLOT void setCurrent_text(QString value) noexcept;
  QStringList const &getItems() const noexcept;
  Q_SLOT void setItems(QStringList value) noexcept;
  QStringList const &getIcon_paths() const noexcept;
  Q_SLOT void setIcon_paths(QStringList value) noexcept;
  QStringList const &getPreview_colors() const noexcept;
  Q_SLOT void setPreview_colors(QStringList value) noexcept;
  ::std::int32_t const &getCurrent_index() const noexcept;
  Q_SLOT void setCurrent_index(::std::int32_t value) noexcept;
  bool const &getShow_command_hint() const noexcept;
  Q_SLOT void setShow_command_hint(bool value) noexcept;
  QString const &getCommand_preview() const noexcept;
  Q_SLOT void setCommand_preview(QString value) noexcept;
  bool const &getIs_themes_mode() const noexcept;
  Q_SLOT void setIs_themes_mode(bool value) noexcept;
  QString const &getTheme_window_bg() const noexcept;
  Q_SLOT void setTheme_window_bg(QString value) noexcept;
  QString const &getTheme_border() const noexcept;
  Q_SLOT void setTheme_border(QString value) noexcept;
  QString const &getTheme_input_bg() const noexcept;
  Q_SLOT void setTheme_input_bg(QString value) noexcept;
  QString const &getTheme_text() const noexcept;
  Q_SLOT void setTheme_text(QString value) noexcept;
  QString const &getTheme_text_dim() const noexcept;
  Q_SLOT void setTheme_text_dim(QString value) noexcept;
  QString const &getTheme_highlight() const noexcept;
  Q_SLOT void setTheme_highlight(QString value) noexcept;
  QString const &getTheme_highlight_text() const noexcept;
  Q_SLOT void setTheme_highlight_text(QString value) noexcept;
  Q_SIGNAL void current_textChanged();
  Q_SIGNAL void itemsChanged();
  Q_SIGNAL void icon_pathsChanged();
  Q_SIGNAL void preview_colorsChanged();
  Q_SIGNAL void current_indexChanged();
  Q_SIGNAL void show_command_hintChanged();
  Q_SIGNAL void command_previewChanged();
  Q_SIGNAL void is_themes_modeChanged();
  Q_SIGNAL void theme_window_bgChanged();
  Q_SIGNAL void theme_borderChanged();
  Q_SIGNAL void theme_input_bgChanged();
  Q_SIGNAL void theme_textChanged();
  Q_SIGNAL void theme_text_dimChanged();
  Q_SIGNAL void theme_highlightChanged();
  Q_SIGNAL void theme_highlight_textChanged();
  Q_INVOKABLE void set_query(QString value) noexcept;
  Q_INVOKABLE void move_down() noexcept;
  Q_INVOKABLE void move_up() noexcept;
  Q_INVOKABLE void select_index(::std::int32_t index) noexcept;
  Q_INVOKABLE void launch_current() noexcept;
  explicit Backend();

private:
  explicit Backend(::cxx_qt_Backend::CxxQtConstructorArguments0 &&args);

private:
  template <typename Inner, typename Outer>
  friend Inner & ::rust::cxxqt1::unsafeRustMut(Outer &outer);

  template <typename Inner, typename Outer>
  friend const Inner & ::rust::cxxqt1::unsafeRust(const Outer &outer);
};

static_assert(::std::is_base_of<QObject, Backend>::value,
              "Backend must inherit from QObject");

Q_DECLARE_METATYPE(Backend *)
