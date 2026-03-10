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

class Backend : public QObject, private ::rust::cxxqt1::CxxQtType<BackendRust> {
  Q_OBJECT
public:
  QML_NAMED_ELEMENT(Backend)
  Q_PROPERTY(QString current_text READ getCurrent_text WRITE setCurrent_text
                 NOTIFY current_textChanged)
  Q_PROPERTY(QStringList items READ getItems WRITE setItems NOTIFY itemsChanged)
  Q_PROPERTY(QStringList icon_paths READ getIcon_paths WRITE setIcon_paths
                 NOTIFY icon_pathsChanged)
  Q_PROPERTY(::std::int32_t current_index READ getCurrent_index WRITE
                 setCurrent_index NOTIFY current_indexChanged)
  Q_PROPERTY(bool show_command_hint READ getShow_command_hint WRITE
                 setShow_command_hint NOTIFY show_command_hintChanged)
  Q_PROPERTY(QString command_preview READ getCommand_preview WRITE
                 setCommand_preview NOTIFY command_previewChanged)

  virtual ~Backend() = default;

public:
  QString const &getCurrent_text() const noexcept;
  Q_SLOT void setCurrent_text(QString value) noexcept;
  QStringList const &getItems() const noexcept;
  Q_SLOT void setItems(QStringList value) noexcept;
  QStringList const &getIcon_paths() const noexcept;
  Q_SLOT void setIcon_paths(QStringList value) noexcept;
  ::std::int32_t const &getCurrent_index() const noexcept;
  Q_SLOT void setCurrent_index(::std::int32_t value) noexcept;
  bool const &getShow_command_hint() const noexcept;
  Q_SLOT void setShow_command_hint(bool value) noexcept;
  QString const &getCommand_preview() const noexcept;
  Q_SLOT void setCommand_preview(QString value) noexcept;
  Q_SIGNAL void current_textChanged();
  Q_SIGNAL void itemsChanged();
  Q_SIGNAL void icon_pathsChanged();
  Q_SIGNAL void current_indexChanged();
  Q_SIGNAL void show_command_hintChanged();
  Q_SIGNAL void command_previewChanged();
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
