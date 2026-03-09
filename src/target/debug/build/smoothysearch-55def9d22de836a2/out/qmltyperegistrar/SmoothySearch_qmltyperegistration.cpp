/****************************************************************************
** Generated QML type registration code
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <QtQml/qqml.h>
#include <QtQml/qqmlmoduleregistration.h>

#if __has_include(<backend.cxxqt.h>)
#  include <backend.cxxqt.h>
#endif


#if !defined(QT_STATIC)
#define Q_QMLTYPE_EXPORT Q_DECL_EXPORT
#else
#define Q_QMLTYPE_EXPORT
#endif
Q_QMLTYPE_EXPORT void qml_register_types_SmoothySearch()
{
    QT_WARNING_PUSH QT_WARNING_DISABLE_DEPRECATED
    qmlRegisterTypesAndRevisions<Backend>("SmoothySearch", 1);
    QT_WARNING_POP
    qmlRegisterModule("SmoothySearch", 1, 0);
}

static const QQmlModuleRegistration smoothySearchRegistration("SmoothySearch", qml_register_types_SmoothySearch);
