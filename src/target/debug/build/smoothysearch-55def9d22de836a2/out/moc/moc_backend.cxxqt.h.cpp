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
        "current_indexChanged",
        "show_command_hintChanged",
        "command_previewChanged",
        "setCurrent_text",
        "value",
        "setItems",
        "setIcon_paths",
        "setCurrent_index",
        "::std::int32_t",
        "setShow_command_hint",
        "setCommand_preview",
        "set_query",
        "move_down",
        "move_up",
        "select_index",
        "index",
        "launch_current",
        "current_text",
        "items",
        "icon_paths",
        "current_index",
        "show_command_hint",
        "command_preview"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'current_textChanged'
        QtMocHelpers::SignalData<void()>(2, 3, QMC::AccessPublic, QMetaType::Void),
        // Signal 'itemsChanged'
        QtMocHelpers::SignalData<void()>(4, 3, QMC::AccessPublic, QMetaType::Void),
        // Signal 'icon_pathsChanged'
        QtMocHelpers::SignalData<void()>(5, 3, QMC::AccessPublic, QMetaType::Void),
        // Signal 'current_indexChanged'
        QtMocHelpers::SignalData<void()>(6, 3, QMC::AccessPublic, QMetaType::Void),
        // Signal 'show_command_hintChanged'
        QtMocHelpers::SignalData<void()>(7, 3, QMC::AccessPublic, QMetaType::Void),
        // Signal 'command_previewChanged'
        QtMocHelpers::SignalData<void()>(8, 3, QMC::AccessPublic, QMetaType::Void),
        // Slot 'setCurrent_text'
        QtMocHelpers::SlotData<void(QString)>(9, 3, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 10 },
        }}),
        // Slot 'setItems'
        QtMocHelpers::SlotData<void(QStringList)>(11, 3, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QStringList, 10 },
        }}),
        // Slot 'setIcon_paths'
        QtMocHelpers::SlotData<void(QStringList)>(12, 3, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QStringList, 10 },
        }}),
        // Slot 'setCurrent_index'
        QtMocHelpers::SlotData<void(::std::int32_t)>(13, 3, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 14, 10 },
        }}),
        // Slot 'setShow_command_hint'
        QtMocHelpers::SlotData<void(bool)>(15, 3, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 10 },
        }}),
        // Slot 'setCommand_preview'
        QtMocHelpers::SlotData<void(QString)>(16, 3, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 10 },
        }}),
        // Method 'set_query'
        QtMocHelpers::MethodData<void(QString)>(17, 3, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 10 },
        }}),
        // Method 'move_down'
        QtMocHelpers::MethodData<void()>(18, 3, QMC::AccessPublic, QMetaType::Void),
        // Method 'move_up'
        QtMocHelpers::MethodData<void()>(19, 3, QMC::AccessPublic, QMetaType::Void),
        // Method 'select_index'
        QtMocHelpers::MethodData<void(::std::int32_t)>(20, 3, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 14, 21 },
        }}),
        // Method 'launch_current'
        QtMocHelpers::MethodData<void()>(22, 3, QMC::AccessPublic, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'current_text'
        QtMocHelpers::PropertyData<QString>(23, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 0),
        // property 'items'
        QtMocHelpers::PropertyData<QStringList>(24, QMetaType::QStringList, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 1),
        // property 'icon_paths'
        QtMocHelpers::PropertyData<QStringList>(25, QMetaType::QStringList, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 2),
        // property 'current_index'
        QtMocHelpers::PropertyData<::std::int32_t>(26, 0x80000000 | 14, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet, 3),
        // property 'show_command_hint'
        QtMocHelpers::PropertyData<bool>(27, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 4),
        // property 'command_preview'
        QtMocHelpers::PropertyData<QString>(28, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 5),
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
        case 3: _t->current_indexChanged(); break;
        case 4: _t->show_command_hintChanged(); break;
        case 5: _t->command_previewChanged(); break;
        case 6: _t->setCurrent_text((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 7: _t->setItems((*reinterpret_cast<std::add_pointer_t<QStringList>>(_a[1]))); break;
        case 8: _t->setIcon_paths((*reinterpret_cast<std::add_pointer_t<QStringList>>(_a[1]))); break;
        case 9: _t->setCurrent_index((*reinterpret_cast<std::add_pointer_t<::std::int32_t>>(_a[1]))); break;
        case 10: _t->setShow_command_hint((*reinterpret_cast<std::add_pointer_t<bool>>(_a[1]))); break;
        case 11: _t->setCommand_preview((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 12: _t->set_query((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 13: _t->move_down(); break;
        case 14: _t->move_up(); break;
        case 15: _t->select_index((*reinterpret_cast<std::add_pointer_t<::std::int32_t>>(_a[1]))); break;
        case 16: _t->launch_current(); break;
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
        if (QtMocHelpers::indexOfMethod<void (Backend::*)()>(_a, &Backend::current_indexChanged, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (Backend::*)()>(_a, &Backend::show_command_hintChanged, 4))
            return;
        if (QtMocHelpers::indexOfMethod<void (Backend::*)()>(_a, &Backend::command_previewChanged, 5))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<QString*>(_v) = _t->getCurrent_text(); break;
        case 1: *reinterpret_cast<QStringList*>(_v) = _t->getItems(); break;
        case 2: *reinterpret_cast<QStringList*>(_v) = _t->getIcon_paths(); break;
        case 3: *reinterpret_cast<::std::int32_t*>(_v) = _t->getCurrent_index(); break;
        case 4: *reinterpret_cast<bool*>(_v) = _t->getShow_command_hint(); break;
        case 5: *reinterpret_cast<QString*>(_v) = _t->getCommand_preview(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setCurrent_text(*reinterpret_cast<QString*>(_v)); break;
        case 1: _t->setItems(*reinterpret_cast<QStringList*>(_v)); break;
        case 2: _t->setIcon_paths(*reinterpret_cast<QStringList*>(_v)); break;
        case 3: _t->setCurrent_index(*reinterpret_cast<::std::int32_t*>(_v)); break;
        case 4: _t->setShow_command_hint(*reinterpret_cast<bool*>(_v)); break;
        case 5: _t->setCommand_preview(*reinterpret_cast<QString*>(_v)); break;
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
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 17;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
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
void Backend::current_indexChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void Backend::show_command_hintChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void Backend::command_previewChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}
QT_WARNING_POP
