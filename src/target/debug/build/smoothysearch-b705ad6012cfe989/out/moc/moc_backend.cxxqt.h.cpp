/****************************************************************************
** Meta object code from reading C++ file 'backend.cxxqt.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.10.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../cxxqtbuild/include/smoothysearch/src/backend.cxxqt.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'backend.cxxqt.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 69
#error "This file was generated using the moc from 6.10.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {
struct qt_meta_tag_ZN7BackendE_t {};
} // unnamed namespace

template <> constexpr inline auto Backend::qt_create_metaobjectdata<qt_meta_tag_ZN7BackendE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "Backend",
        "QML.Element",
        "current_textChanged",
        "",
        "itemsChanged",
        "icon_pathsChanged",
        "preview_colorsChanged",
        "current_indexChanged",
        "show_command_hintChanged",
        "command_previewChanged",
        "is_themes_modeChanged",
        "theme_window_bgChanged",
        "theme_borderChanged",
        "theme_input_bgChanged",
        "theme_textChanged",
        "theme_text_dimChanged",
        "theme_highlightChanged",
        "theme_highlight_textChanged",
        "setCurrent_text",
        "value",
        "setItems",
        "setIcon_paths",
        "setPreview_colors",
        "setCurrent_index",
        "::std::int32_t",
        "setShow_command_hint",
        "setCommand_preview",
        "setIs_themes_mode",
        "setTheme_window_bg",
        "setTheme_border",
        "setTheme_input_bg",
        "setTheme_text",
        "setTheme_text_dim",
        "setTheme_highlight",
        "setTheme_highlight_text",
        "set_query",
        "move_down",
        "move_up",
        "select_index",
        "index",
        "launch_current",
        "current_text",
        "items",
        "icon_paths",
        "preview_colors",
        "current_index",
        "show_command_hint",
        "command_preview",
        "is_themes_mode",
        "theme_window_bg",
        "theme_border",
        "theme_input_bg",
        "theme_text",
        "theme_text_dim",
        "theme_highlight",
        "theme_highlight_text"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'current_textChanged'
        QtMocHelpers::SignalData<void()>(2, 3, QMC::AccessPublic, QMetaType::Void),
        // Signal 'itemsChanged'
        QtMocHelpers::SignalData<void()>(4, 3, QMC::AccessPublic, QMetaType::Void),
        // Signal 'icon_pathsChanged'
        QtMocHelpers::SignalData<void()>(5, 3, QMC::AccessPublic, QMetaType::Void),
        // Signal 'preview_colorsChanged'
        QtMocHelpers::SignalData<void()>(6, 3, QMC::AccessPublic, QMetaType::Void),
        // Signal 'current_indexChanged'
        QtMocHelpers::SignalData<void()>(7, 3, QMC::AccessPublic, QMetaType::Void),
        // Signal 'show_command_hintChanged'
        QtMocHelpers::SignalData<void()>(8, 3, QMC::AccessPublic, QMetaType::Void),
        // Signal 'command_previewChanged'
        QtMocHelpers::SignalData<void()>(9, 3, QMC::AccessPublic, QMetaType::Void),
        // Signal 'is_themes_modeChanged'
        QtMocHelpers::SignalData<void()>(10, 3, QMC::AccessPublic, QMetaType::Void),
        // Signal 'theme_window_bgChanged'
        QtMocHelpers::SignalData<void()>(11, 3, QMC::AccessPublic, QMetaType::Void),
        // Signal 'theme_borderChanged'
        QtMocHelpers::SignalData<void()>(12, 3, QMC::AccessPublic, QMetaType::Void),
        // Signal 'theme_input_bgChanged'
        QtMocHelpers::SignalData<void()>(13, 3, QMC::AccessPublic, QMetaType::Void),
        // Signal 'theme_textChanged'
        QtMocHelpers::SignalData<void()>(14, 3, QMC::AccessPublic, QMetaType::Void),
        // Signal 'theme_text_dimChanged'
        QtMocHelpers::SignalData<void()>(15, 3, QMC::AccessPublic, QMetaType::Void),
        // Signal 'theme_highlightChanged'
        QtMocHelpers::SignalData<void()>(16, 3, QMC::AccessPublic, QMetaType::Void),
        // Signal 'theme_highlight_textChanged'
        QtMocHelpers::SignalData<void()>(17, 3, QMC::AccessPublic, QMetaType::Void),
        // Slot 'setCurrent_text'
        QtMocHelpers::SlotData<void(QString)>(18, 3, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 19 },
        }}),
        // Slot 'setItems'
        QtMocHelpers::SlotData<void(QStringList)>(20, 3, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QStringList, 19 },
        }}),
        // Slot 'setIcon_paths'
        QtMocHelpers::SlotData<void(QStringList)>(21, 3, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QStringList, 19 },
        }}),
        // Slot 'setPreview_colors'
        QtMocHelpers::SlotData<void(QStringList)>(22, 3, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QStringList, 19 },
        }}),
        // Slot 'setCurrent_index'
        QtMocHelpers::SlotData<void(::std::int32_t)>(23, 3, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 24, 19 },
        }}),
        // Slot 'setShow_command_hint'
        QtMocHelpers::SlotData<void(bool)>(25, 3, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 19 },
        }}),
        // Slot 'setCommand_preview'
        QtMocHelpers::SlotData<void(QString)>(26, 3, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 19 },
        }}),
        // Slot 'setIs_themes_mode'
        QtMocHelpers::SlotData<void(bool)>(27, 3, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 19 },
        }}),
        // Slot 'setTheme_window_bg'
        QtMocHelpers::SlotData<void(QString)>(28, 3, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 19 },
        }}),
        // Slot 'setTheme_border'
        QtMocHelpers::SlotData<void(QString)>(29, 3, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 19 },
        }}),
        // Slot 'setTheme_input_bg'
        QtMocHelpers::SlotData<void(QString)>(30, 3, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 19 },
        }}),
        // Slot 'setTheme_text'
        QtMocHelpers::SlotData<void(QString)>(31, 3, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 19 },
        }}),
        // Slot 'setTheme_text_dim'
        QtMocHelpers::SlotData<void(QString)>(32, 3, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 19 },
        }}),
        // Slot 'setTheme_highlight'
        QtMocHelpers::SlotData<void(QString)>(33, 3, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 19 },
        }}),
        // Slot 'setTheme_highlight_text'
        QtMocHelpers::SlotData<void(QString)>(34, 3, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 19 },
        }}),
        // Method 'set_query'
        QtMocHelpers::MethodData<void(QString)>(35, 3, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 19 },
        }}),
        // Method 'move_down'
        QtMocHelpers::MethodData<void()>(36, 3, QMC::AccessPublic, QMetaType::Void),
        // Method 'move_up'
        QtMocHelpers::MethodData<void()>(37, 3, QMC::AccessPublic, QMetaType::Void),
        // Method 'select_index'
        QtMocHelpers::MethodData<void(::std::int32_t)>(38, 3, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 24, 39 },
        }}),
        // Method 'launch_current'
        QtMocHelpers::MethodData<void()>(40, 3, QMC::AccessPublic, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'current_text'
        QtMocHelpers::PropertyData<QString>(41, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 0),
        // property 'items'
        QtMocHelpers::PropertyData<QStringList>(42, QMetaType::QStringList, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 1),
        // property 'icon_paths'
        QtMocHelpers::PropertyData<QStringList>(43, QMetaType::QStringList, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 2),
        // property 'preview_colors'
        QtMocHelpers::PropertyData<QStringList>(44, QMetaType::QStringList, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 3),
        // property 'current_index'
        QtMocHelpers::PropertyData<::std::int32_t>(45, 0x80000000 | 24, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet, 4),
        // property 'show_command_hint'
        QtMocHelpers::PropertyData<bool>(46, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 5),
        // property 'command_preview'
        QtMocHelpers::PropertyData<QString>(47, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 6),
        // property 'is_themes_mode'
        QtMocHelpers::PropertyData<bool>(48, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 7),
        // property 'theme_window_bg'
        QtMocHelpers::PropertyData<QString>(49, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 8),
        // property 'theme_border'
        QtMocHelpers::PropertyData<QString>(50, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 9),
        // property 'theme_input_bg'
        QtMocHelpers::PropertyData<QString>(51, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 10),
        // property 'theme_text'
        QtMocHelpers::PropertyData<QString>(52, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 11),
        // property 'theme_text_dim'
        QtMocHelpers::PropertyData<QString>(53, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 12),
        // property 'theme_highlight'
        QtMocHelpers::PropertyData<QString>(54, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 13),
        // property 'theme_highlight_text'
        QtMocHelpers::PropertyData<QString>(55, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 14),
    };
    QtMocHelpers::UintData qt_enums {
    };
    QtMocHelpers::UintData qt_constructors {};
    QtMocHelpers::ClassInfos qt_classinfo({
            {    1,    0 },
    });
    return QtMocHelpers::metaObjectData<Backend, void>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors, qt_classinfo);
}
Q_CONSTINIT const QMetaObject Backend::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN7BackendE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN7BackendE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN7BackendE_t>.metaTypes,
    nullptr
} };

void Backend::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<Backend *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->current_textChanged(); break;
        case 1: _t->itemsChanged(); break;
        case 2: _t->icon_pathsChanged(); break;
        case 3: _t->preview_colorsChanged(); break;
        case 4: _t->current_indexChanged(); break;
        case 5: _t->show_command_hintChanged(); break;
        case 6: _t->command_previewChanged(); break;
        case 7: _t->is_themes_modeChanged(); break;
        case 8: _t->theme_window_bgChanged(); break;
        case 9: _t->theme_borderChanged(); break;
        case 10: _t->theme_input_bgChanged(); break;
        case 11: _t->theme_textChanged(); break;
        case 12: _t->theme_text_dimChanged(); break;
        case 13: _t->theme_highlightChanged(); break;
        case 14: _t->theme_highlight_textChanged(); break;
        case 15: _t->setCurrent_text((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 16: _t->setItems((*reinterpret_cast<std::add_pointer_t<QStringList>>(_a[1]))); break;
        case 17: _t->setIcon_paths((*reinterpret_cast<std::add_pointer_t<QStringList>>(_a[1]))); break;
        case 18: _t->setPreview_colors((*reinterpret_cast<std::add_pointer_t<QStringList>>(_a[1]))); break;
        case 19: _t->setCurrent_index((*reinterpret_cast<std::add_pointer_t<::std::int32_t>>(_a[1]))); break;
        case 20: _t->setShow_command_hint((*reinterpret_cast<std::add_pointer_t<bool>>(_a[1]))); break;
        case 21: _t->setCommand_preview((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 22: _t->setIs_themes_mode((*reinterpret_cast<std::add_pointer_t<bool>>(_a[1]))); break;
        case 23: _t->setTheme_window_bg((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 24: _t->setTheme_border((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 25: _t->setTheme_input_bg((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 26: _t->setTheme_text((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 27: _t->setTheme_text_dim((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 28: _t->setTheme_highlight((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 29: _t->setTheme_highlight_text((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 30: _t->set_query((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 31: _t->move_down(); break;
        case 32: _t->move_up(); break;
        case 33: _t->select_index((*reinterpret_cast<std::add_pointer_t<::std::int32_t>>(_a[1]))); break;
        case 34: _t->launch_current(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (Backend::*)()>(_a, &Backend::current_textChanged, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (Backend::*)()>(_a, &Backend::itemsChanged, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (Backend::*)()>(_a, &Backend::icon_pathsChanged, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (Backend::*)()>(_a, &Backend::preview_colorsChanged, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (Backend::*)()>(_a, &Backend::current_indexChanged, 4))
            return;
        if (QtMocHelpers::indexOfMethod<void (Backend::*)()>(_a, &Backend::show_command_hintChanged, 5))
            return;
        if (QtMocHelpers::indexOfMethod<void (Backend::*)()>(_a, &Backend::command_previewChanged, 6))
            return;
        if (QtMocHelpers::indexOfMethod<void (Backend::*)()>(_a, &Backend::is_themes_modeChanged, 7))
            return;
        if (QtMocHelpers::indexOfMethod<void (Backend::*)()>(_a, &Backend::theme_window_bgChanged, 8))
            return;
        if (QtMocHelpers::indexOfMethod<void (Backend::*)()>(_a, &Backend::theme_borderChanged, 9))
            return;
        if (QtMocHelpers::indexOfMethod<void (Backend::*)()>(_a, &Backend::theme_input_bgChanged, 10))
            return;
        if (QtMocHelpers::indexOfMethod<void (Backend::*)()>(_a, &Backend::theme_textChanged, 11))
            return;
        if (QtMocHelpers::indexOfMethod<void (Backend::*)()>(_a, &Backend::theme_text_dimChanged, 12))
            return;
        if (QtMocHelpers::indexOfMethod<void (Backend::*)()>(_a, &Backend::theme_highlightChanged, 13))
            return;
        if (QtMocHelpers::indexOfMethod<void (Backend::*)()>(_a, &Backend::theme_highlight_textChanged, 14))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<QString*>(_v) = _t->getCurrent_text(); break;
        case 1: *reinterpret_cast<QStringList*>(_v) = _t->getItems(); break;
        case 2: *reinterpret_cast<QStringList*>(_v) = _t->getIcon_paths(); break;
        case 3: *reinterpret_cast<QStringList*>(_v) = _t->getPreview_colors(); break;
        case 4: *reinterpret_cast<::std::int32_t*>(_v) = _t->getCurrent_index(); break;
        case 5: *reinterpret_cast<bool*>(_v) = _t->getShow_command_hint(); break;
        case 6: *reinterpret_cast<QString*>(_v) = _t->getCommand_preview(); break;
        case 7: *reinterpret_cast<bool*>(_v) = _t->getIs_themes_mode(); break;
        case 8: *reinterpret_cast<QString*>(_v) = _t->getTheme_window_bg(); break;
        case 9: *reinterpret_cast<QString*>(_v) = _t->getTheme_border(); break;
        case 10: *reinterpret_cast<QString*>(_v) = _t->getTheme_input_bg(); break;
        case 11: *reinterpret_cast<QString*>(_v) = _t->getTheme_text(); break;
        case 12: *reinterpret_cast<QString*>(_v) = _t->getTheme_text_dim(); break;
        case 13: *reinterpret_cast<QString*>(_v) = _t->getTheme_highlight(); break;
        case 14: *reinterpret_cast<QString*>(_v) = _t->getTheme_highlight_text(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setCurrent_text(*reinterpret_cast<QString*>(_v)); break;
        case 1: _t->setItems(*reinterpret_cast<QStringList*>(_v)); break;
        case 2: _t->setIcon_paths(*reinterpret_cast<QStringList*>(_v)); break;
        case 3: _t->setPreview_colors(*reinterpret_cast<QStringList*>(_v)); break;
        case 4: _t->setCurrent_index(*reinterpret_cast<::std::int32_t*>(_v)); break;
        case 5: _t->setShow_command_hint(*reinterpret_cast<bool*>(_v)); break;
        case 6: _t->setCommand_preview(*reinterpret_cast<QString*>(_v)); break;
        case 7: _t->setIs_themes_mode(*reinterpret_cast<bool*>(_v)); break;
        case 8: _t->setTheme_window_bg(*reinterpret_cast<QString*>(_v)); break;
        case 9: _t->setTheme_border(*reinterpret_cast<QString*>(_v)); break;
        case 10: _t->setTheme_input_bg(*reinterpret_cast<QString*>(_v)); break;
        case 11: _t->setTheme_text(*reinterpret_cast<QString*>(_v)); break;
        case 12: _t->setTheme_text_dim(*reinterpret_cast<QString*>(_v)); break;
        case 13: _t->setTheme_highlight(*reinterpret_cast<QString*>(_v)); break;
        case 14: _t->setTheme_highlight_text(*reinterpret_cast<QString*>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *Backend::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Backend::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN7BackendE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Backend::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 35)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 35;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 35)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 35;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void Backend::current_textChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Backend::itemsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Backend::icon_pathsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void Backend::preview_colorsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void Backend::current_indexChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void Backend::show_command_hintChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void Backend::command_previewChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void Backend::is_themes_modeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void Backend::theme_window_bgChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}

// SIGNAL 9
void Backend::theme_borderChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 9, nullptr);
}

// SIGNAL 10
void Backend::theme_input_bgChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 10, nullptr);
}

// SIGNAL 11
void Backend::theme_textChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 11, nullptr);
}

// SIGNAL 12
void Backend::theme_text_dimChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 12, nullptr);
}

// SIGNAL 13
void Backend::theme_highlightChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 13, nullptr);
}

// SIGNAL 14
void Backend::theme_highlight_textChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 14, nullptr);
}
QT_WARNING_POP
