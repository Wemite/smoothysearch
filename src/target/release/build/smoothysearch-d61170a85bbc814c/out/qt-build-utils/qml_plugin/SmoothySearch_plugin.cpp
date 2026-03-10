
#include <QtQml/qqmlextensionplugin.h>

// TODO: Add missing handling for GHS (Green Hills Software compiler) that is in
// https://code.qt.io/cgit/qt/qtbase.git/plain/src/corelib/global/qtsymbolmacros.h
extern void qml_register_types_SmoothySearch();
extern int qInitResources_qml_module_resources_SmoothySearch_qrc();
extern int qInitResources_qmlcache_SmoothySearch();

class SmoothySearch_plugin : public QQmlEngineExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QQmlEngineExtensionInterface")

public:
    SmoothySearch_plugin(QObject *parent = nullptr) : QQmlEngineExtensionPlugin(parent)
    {
        volatile auto qml_register_types_SmoothySearch_usage = &qml_register_types_SmoothySearch;
Q_UNUSED(qml_register_types_SmoothySearch_usage);
volatile auto qInitResources_qml_module_resources_SmoothySearch_qrc_usage = &qInitResources_qml_module_resources_SmoothySearch_qrc;
Q_UNUSED(qInitResources_qml_module_resources_SmoothySearch_qrc_usage);
volatile auto qInitResources_qmlcache_SmoothySearch_usage = &qInitResources_qmlcache_SmoothySearch;
Q_UNUSED(qInitResources_qmlcache_SmoothySearch_usage);
    }
};

extern "C" {
    // "drive-by initialization" causes the plugin class to be included in static linking scenarios
    // Any function that is called from within this file causes the entire object file to be linked in.
    // Therefore we provide an empty function that can be called at any point to ensure this file is linked in.
    bool init_cxx_qt_qml_module_SmoothySearch_plugin() {
        return true;
    }
}

// The moc-generated cpp file doesn't compile on its own; it needs to be #included here.
#include "moc_SmoothySearch_plugin.cpp.cpp"
