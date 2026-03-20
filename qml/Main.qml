import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import SmoothySearch

ApplicationWindow {
    id: win

    property int collapsedWidth: backend.window_width
    property int baseHeight: backend.window_height
    readonly property int contentMargin: 18
    readonly property int paneGap: 18
    readonly property int editorPanelWidth: 480
    readonly property int leftPaneWidth: Math.max(320, collapsedWidth - contentMargin * 2)
    readonly property int themesWindowWidth: collapsedWidth + paneGap + editorPanelWidth

    readonly property int windowRadius: backend.ui_window_radius
    readonly property int panelRadius: backend.ui_search_bar_radius
    readonly property int selectorRadius: backend.ui_selector_radius
    readonly property int buttonRadius: Math.max(8, Math.round(panelRadius * 0.5))
    readonly property int editorInnerRadius: Math.max(10, panelRadius)
    readonly property int wheelStepAngle: 120

    property bool launcherVisibleState: !backend.resident_mode
    property bool suppressInactiveClose: false
    property bool closeShouldQuit: false
    property bool closeShouldClearQuery: true
    property int listAnimationToken: 0

    width: backend.is_themes_mode ? themesWindowWidth : collapsedWidth
    height: baseHeight
    visible: launcherVisibleState
    color: "transparent"
    flags: Qt.FramelessWindowHint | Qt.WindowStaysOnTopHint | Qt.Tool

    minimumHeight: baseHeight
    maximumHeight: baseHeight
    minimumWidth: backend.is_themes_mode ? themesWindowWidth : collapsedWidth
    maximumWidth: backend.is_themes_mode ? themesWindowWidth : collapsedWidth

    Backend {
        id: backend
    }

    Component.onCompleted: {
        x = Math.round((Screen.width - collapsedWidth) / 2)
        y = Math.round((Screen.height - height) / 5)

        if (launcherVisibleState)
            Qt.callLater(function() { win.listAnimationToken += 1 })

        if (!backend.resident_mode) {
            suppressInactiveClose = true
            inactiveCloseGuard.restart()
            requestActivate()
            Qt.callLater(function() {
                win.scheduleBlurSync()
                win.focusSearchField()
            })
        }
    }

    Timer {
        id: inactiveCloseGuard
        interval: 220
        repeat: false
        onTriggered: win.suppressInactiveClose = false
    }

    Timer {
        id: blurSyncTimer
        interval: 0
        repeat: false
        onTriggered: {
            if (win.launcherVisibleState)
                backend.sync_window_blur(win.windowRadius)
        }
    }

    function focusSearchField() {
        searchBar.focusField()
    }

    function scheduleBlurSync() {
        blurSyncTimer.restart()
    }

    function clearSearch() {
        searchBar.text = ""
        backend.set_query("")
    }

    function closeLauncher(quitAfterClose, clearQueryAfterClose) {
        closeShouldQuit = quitAfterClose === true
        closeShouldClearQuery = clearQueryAfterClose !== false
        suppressInactiveClose = true
        inactiveCloseGuard.stop()

        if (!launcherVisibleState) {
            if (closeShouldQuit)
                Qt.quit()
            return
        }

        launcherVisibleState = false

        if (closeShouldClearQuery)
            clearSearch()

        const shouldQuit = closeShouldQuit
        closeShouldQuit = false
        closeShouldClearQuery = true

        if (shouldQuit)
            Qt.quit()
    }

    function showLauncher() {
        if (launcherVisibleState) {
            raise()
            requestActivate()
            suppressInactiveClose = true
            inactiveCloseGuard.restart()
            Qt.callLater(function() { win.focusSearchField() })
            return
        }

        closeShouldQuit = false
        closeShouldClearQuery = true
        launcherVisibleState = true
        listAnimationToken += 1
        show()
        raise()
        requestActivate()
        suppressInactiveClose = true
        inactiveCloseGuard.restart()
        Qt.callLater(function() {
            win.scheduleBlurSync()
            win.focusSearchField()
        })
    }

    function handleCloseRequest() {
        if (backend.is_themes_mode) {
            backend.save_selected_theme()
            clearSearch()
            backend.return_to_apps_mode()
            Qt.callLater(function() { win.focusSearchField() })
            return
        }

        if (backend.resident_mode)
            closeLauncher(false, true)
        else
            closeLauncher(true, true)
    }

    function handleInactiveCloseRequest() {
        if (backend.is_themes_mode) {
            backend.save_selected_theme()
            clearSearch()
            backend.return_to_apps_mode()
        }

        if (backend.resident_mode)
            closeLauncher(false, true)
        else
            closeLauncher(true, true)
    }

    function launchAndHide() {
        if (backend.is_theme_command_index(backend.current_index)) {
            clearSearch()
            backend.enter_themes_mode()
            editorPane.syncEditorFromBackend()
            Qt.callLater(function() { win.focusSearchField() })
            return
        }

        if (backend.is_themes_mode) {
            backend.launch_current()
            return
        }

        const searchLaunch = backend.is_search_index(backend.current_index)
        backend.launch_current()

        const closeAfterLaunch = function() {
            if (backend.resident_mode)
                closeLauncher(false, true)
            else
                closeLauncher(true, true)
        }

        if (searchLaunch)
            Qt.callLater(closeAfterLaunch)
        else
            closeAfterLaunch()
    }

    onActiveChanged: {
        if (visible && !active && !suppressInactiveClose) {
            Qt.callLater(function() {
                if (win.visible && !win.active && !win.suppressInactiveClose)
                    handleInactiveCloseRequest()
            })
        }
    }

    onWidthChanged: scheduleBlurSync()
    onHeightChanged: scheduleBlurSync()
    onWindowRadiusChanged: scheduleBlurSync()
    onVisibleChanged: {
        if (visible)
            scheduleBlurSync()
    }

    Timer {
        interval: 100
        running: true
        repeat: true
        onTriggered: {
            const command = backend.poll_resident_command()
            if (command === 1)
                win.showLauncher()
            else if (command === 2)
                win.closeLauncher(false, true)
        }
    }

    Rectangle {
        id: shell
        anchors.fill: parent
        radius: win.windowRadius
        color: backend.theme_window_bg
        border.color: backend.theme_border
        border.width: 2
        clip: true

        Behavior on color {
            ColorAnimation { duration: 200; easing.type: Easing.OutCubic }
        }

        Behavior on border.color {
            ColorAnimation { duration: 200; easing.type: Easing.OutCubic }
        }

        Item {
            anchors.fill: parent
            anchors.margins: win.contentMargin

            Item {
                id: leftPane
                x: 0
                y: 0
                width: win.leftPaneWidth
                height: parent.height

                Column {
                    anchors.fill: parent
                    spacing: 14

                    SearchBar {
                        id: searchBar
                        width: parent.width
                        height: 52
                        backend: backend
                        panelRadius: win.panelRadius
                        onLaunchRequested: win.launchAndHide()
                        onCloseRequested: win.handleCloseRequest()
                    }

                    Item {
                        width: parent.width
                        height: parent.height - searchBar.height - 14

                        EntryList {
                            anchors.fill: parent
                            backend: backend
                            selectorRadius: win.selectorRadius
                            wheelStepAngle: win.wheelStepAngle
                            animationToken: win.listAnimationToken
                            onLaunchRequested: win.launchAndHide()
                            onFocusSearchRequested: win.focusSearchField()
                        }
                    }
                }
            }

            ThemeEditorPane {
                id: editorPane
                x: leftPane.width + win.paneGap
                y: 0
                width: win.editorPanelWidth
                height: parent.height
                visible: backend.is_themes_mode
                enabled: visible
                backend: backend
                windowRadius: win.windowRadius
                buttonRadius: win.buttonRadius
                editorInnerRadius: win.editorInnerRadius
                onCloseRequested: win.handleCloseRequest()
            }
        }
    }

}
