import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import SmoothySearch

ApplicationWindow {
    id: win

    property int collapsedWidth: backend.window_width
    property int expandedWidth: backend.window_editor_width
    property int baseHeight: backend.window_height
    readonly property int paneGap: 18
    readonly property int leftPaneWidth: 444
    readonly property int editorTargetWidth: expandedWidth - collapsedWidth - paneGap

    property int editorWidth: backend.is_themes_mode && backend.editor_open ? editorTargetWidth : 0

    readonly property int windowRadius: backend.ui_window_radius
    readonly property int panelRadius: backend.ui_search_bar_radius
    readonly property int selectorRadius: backend.ui_selector_radius
    readonly property int buttonRadius: Math.max(8, Math.round(panelRadius * 0.5))
    readonly property int editorInnerRadius: Math.max(10, panelRadius)

    width: collapsedWidth + editorWidth + (editorWidth > 0 ? paneGap : 0)
    height: baseHeight
    visible: !backend.resident_mode
    color: "transparent"
    flags: Qt.FramelessWindowHint | Qt.WindowStaysOnTopHint | Qt.Tool

    minimumHeight: baseHeight
    maximumHeight: baseHeight

    Behavior on editorWidth {
        NumberAnimation {
            duration: 260
            easing.type: Easing.OutCubic
        }
    }

    Backend {
        id: backend
    }

    function focusSearchField() {
        field.forceActiveFocus()
        field.cursorPosition = field.text.length
    }

    function focusEditor() {
        editorArea.forceActiveFocus()
        editorArea.cursorPosition = editorArea.length
    }

    function hideLauncher() {
        field.text = ""
        backend.set_query("")
        hide()
    }

    function showLauncher() {
        show()
        raise()
        requestActivate()
        Qt.callLater(function() { win.focusSearchField() })
    }

    function handleCloseRequest() {
        if (backend.resident_mode)
            hideLauncher()
        else
            Qt.quit()
    }

    onActiveChanged: {
        if (visible && !active) {
            Qt.callLater(function() {
                if (win.visible && !win.active)
                    handleCloseRequest()
            })
        }
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
                win.hideLauncher()
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
            id: content
            anchors.fill: parent
            anchors.margins: 18

            Item {
                id: leftPane
                x: 0
                y: 0
                width: leftPaneWidth
                height: parent.height

                Column {
                    anchors.fill: parent
                    spacing: 14

                    Rectangle {
                        id: searchBar
                        width: parent.width
                        height: 52
                        radius: win.panelRadius
                        color: backend.theme_input_bg
                        border.color: backend.theme_border
                        border.width: 1

                        Behavior on color {
                            ColorAnimation { duration: 200; easing.type: Easing.OutCubic }
                        }

                        Behavior on border.color {
                            ColorAnimation { duration: 200; easing.type: Easing.OutCubic }
                        }

                        Item {
                            anchors.fill: parent
                            anchors.leftMargin: 10
                            anchors.rightMargin: 10

                            TextField {
                                id: field
                                anchors.left: parent.left
                                anchors.leftMargin: 0
                                anchors.right: editorButton.visible ? editorButton.left : parent.right
                                anchors.rightMargin: editorButton.visible ? 10 : 0
                                anchors.verticalCenter: parent.verticalCenter
                                height: parent.height
                                color: backend.theme_text
                                placeholderText: backend.is_themes_mode ? "Theme search..." : "Search..."
                                placeholderTextColor: backend.theme_text_dim
                                font.pixelSize: 18
                                background: null
                                focus: true
                                selectByMouse: true
                                onTextChanged: backend.set_query(text)
                                cursorVisible: true

                                Keys.onDownPressed: backend.move_down()
                                Keys.onUpPressed: backend.move_up()
                                Keys.onReturnPressed: backend.launch_current()
                                Keys.onEnterPressed: backend.launch_current()
                                Keys.onEscapePressed: win.handleCloseRequest()

                                Behavior on color {
                                    ColorAnimation { duration: 200; easing.type: Easing.OutCubic }
                                }

                                Behavior on placeholderTextColor {
                                    ColorAnimation { duration: 200; easing.type: Easing.OutCubic }
                                }
                            }

                            Rectangle {
                                id: editorButton
                                anchors.right: parent.right
                                anchors.verticalCenter: parent.verticalCenter
                                width: 30
                                height: 30
                                radius: win.buttonRadius
                                visible: backend.is_themes_mode
                                color: editorButtonArea.containsMouse
                                ? Qt.lighter(backend.theme_input_bg, 1.12)
                                : backend.theme_window_bg
                                border.color: backend.editor_open ? backend.theme_highlight : backend.theme_border
                                border.width: backend.editor_open ? 2 : 1

                                Behavior on color {
                                    ColorAnimation { duration: 140; easing.type: Easing.OutCubic }
                                }

                                Behavior on border.color {
                                    ColorAnimation { duration: 200; easing.type: Easing.OutCubic }
                                }

                                Text {
                                    anchors.centerIn: parent
                                    text: backend.editor_open ? "×" : "✎"
                                    color: backend.editor_open ? backend.theme_highlight : backend.theme_text_dim
                                    font.pixelSize: 17
                                    font.bold: true

                                    Behavior on color {
                                        ColorAnimation { duration: 200; easing.type: Easing.OutCubic }
                                    }
                                }

                                MouseArea {
                                    id: editorButtonArea
                                    anchors.fill: parent
                                    hoverEnabled: true
                                    cursorShape: Qt.PointingHandCursor
                                    onClicked: {
                                        backend.toggle_editor()
                                        if (backend.editor_open) {
                                            editorArea.text = backend.themes_file_text
                                            Qt.callLater(function() { win.focusEditor() })
                                        } else {
                                            Qt.callLater(function() { win.focusSearchField() })
                                        }
                                    }
                                }
                            }
                        }
                    }

                    Item {
                        width: parent.width
                        height: parent.height - searchBar.height - 14

                        ListView {
                            id: list
                            anchors.fill: parent
                            model: backend.items
                            spacing: 8
                            clip: true
                            currentIndex: backend.current_index
                            interactive: false
                            visible: count > 0

                            readonly property int rowHeight: 28
                            readonly property int rowStep: rowHeight + spacing
                            property real targetContentY: 0

                            function indexFromViewY(yPos) {
                                const contentPos = yPos + contentY
                                const idx = Math.floor(contentPos / rowStep)
                                if (idx < 0 || idx >= count)
                                    return -1
                                    return idx
                            }

                            MouseArea {
                                anchors.fill: parent
                                acceptedButtons: Qt.LeftButton
                                z: 20

                                property real wheelAccumulator: 0

                                onClicked: function(mouse) {
                                    const idx = list.indexFromViewY(mouse.y)

                                    if (idx < 0) {
                                        return
                                    }

                                    if (backend.current_index === idx) {
                                        backend.launch_current()
                                    } else {
                                        backend.select_index(idx)
                                        win.focusSearchField()
                                    }
                                }

                                onWheel: function(wheel) {
                                    wheelAccumulator += wheel.angleDelta.y

                                    while (wheelAccumulator <= -120) {
                                        backend.move_down()
                                        wheelAccumulator += 120
                                    }

                                    while (wheelAccumulator >= 120) {
                                        backend.move_up()
                                        wheelAccumulator -= 120
                                    }

                                    wheel.accepted = true
                                }
                            }

                            Behavior on targetContentY {
                                NumberAnimation {
                                    duration: 220
                                    easing.type: Easing.OutCubic
                                }
                            }

                            onTargetContentYChanged: contentY = targetContentY

                            Rectangle {
                                id: highlight
                                z: -1
                                visible: list.currentIndex >= 0
                                x: 0
                                width: list.width
                                height: list.rowHeight
                                radius: win.selectorRadius
                                color: backend.theme_highlight

                                y: {
                                    if (!list.currentItem)
                                        return 0

                                        const rawY = list.currentItem.y - list.contentY
                                        const maxY = Math.max(0, list.height - height)

                                        if (rawY < 0)
                                            return 0
                                            if (rawY > maxY)
                                                return maxY
                                                return rawY
                                }

                                Behavior on color {
                                    ColorAnimation {
                                        duration: 200
                                        easing.type: Easing.OutCubic
                                    }
                                }

                                Behavior on y {
                                    SpringAnimation {
                                        spring: 5
                                        damping: 0.34
                                    }
                                }
                            }

                            delegate: Item {
                                id: rowItem

                                width: list.width
                                height: list.rowHeight

                                property real itemTopInView: y - list.contentY
                                property real itemBottomInView: itemTopInView + height
                                property real itemCenterInView: (itemTopInView + itemBottomInView) / 2

                                property real highlightTop: highlight.y
                                property real highlightBottom: highlight.y + highlight.height

                                property bool visuallySelected: itemCenterInView >= highlightTop
                                && itemCenterInView <= highlightBottom

                                Row {
                                    anchors.verticalCenter: parent.verticalCenter
                                    anchors.left: parent.left
                                    anchors.leftMargin: 14
                                    spacing: 12

                                    Item {
                                        width: 20
                                        height: 20
                                        anchors.verticalCenter: parent.verticalCenter

                                        readonly property string iconPath: (
                                            index >= 0 && index < backend.icon_paths.length
                                            ? backend.icon_paths[index]
                                            : ""
                                        )

                                        readonly property string previewColor: (
                                            index >= 0 && index < backend.preview_colors.length
                                            ? backend.preview_colors[index]
                                            : ""
                                        )

                                        Image {
                                            anchors.fill: parent
                                            visible: !backend.is_themes_mode && parent.iconPath !== ""
                                            source: parent.iconPath !== "" ? "file://" + parent.iconPath : ""
                                            fillMode: Image.PreserveAspectFit
                                            smooth: true
                                            mipmap: true
                                            asynchronous: true
                                            cache: true
                                            sourceSize.width: 20
                                            sourceSize.height: 20
                                        }

                                        Rectangle {
                                            width: 12
                                            height: 12
                                            radius: 6
                                            anchors.centerIn: parent
                                            visible: backend.is_themes_mode && parent.previewColor !== ""
                                            color: parent.previewColor
                                            border.width: 1
                                            border.color: Qt.rgba(0, 0, 0, 0.18)
                                        }
                                    }

                                    Text {
                                        text: modelData
                                        font.pixelSize: 17
                                        color: rowItem.visuallySelected
                                        ? backend.theme_highlight_text
                                        : backend.theme_text
                                    }
                                }

                                Rectangle {
                                    width: 8
                                    height: 8
                                    radius: 4
                                    anchors.right: parent.right
                                    anchors.rightMargin: 18
                                    anchors.verticalCenter: parent.verticalCenter

                                    visible: backend.is_themes_mode
                                    && backend.applied_theme_id !== ""
                                    && backend.is_applied_theme_index(index)

                                    color: rowItem.visuallySelected
                                    ? backend.theme_highlight_text
                                    : backend.theme_text_dim
                                }
                            }

                            onCurrentIndexChanged: {
                                if (currentIndex < 0 || !currentItem)
                                    return

                                    const itemTop = currentItem.y
                                    const itemBottom = itemTop + rowHeight

                                    const viewTop = contentY
                                    const viewBottom = contentY + height

                                    let nextY = contentY

                                    if (itemTop < viewTop) {
                                        nextY = itemTop
                                    } else if (itemBottom > viewBottom) {
                                        nextY = itemBottom - height
                                    }

                                    const maxY = Math.max(0, contentHeight - height)
                                    targetContentY = Math.max(0, Math.min(nextY, maxY))
                            }
                        }

                        Column {
                            anchors.centerIn: parent
                            spacing: 8
                            visible: backend.show_command_hint
                            opacity: backend.show_command_hint ? 1.0 : 0.0

                            Behavior on opacity {
                                NumberAnimation {
                                    duration: 180
                                    easing.type: Easing.OutCubic
                                }
                            }

                            Text {
                                anchors.horizontalCenter: parent.horizontalCenter
                                text: "<b>Enter</b> to execute fast command:"
                                textFormat: Text.RichText
                                color: backend.theme_text_dim
                                font.pixelSize: 18

                                Behavior on color {
                                    ColorAnimation { duration: 200; easing.type: Easing.OutCubic }
                                }
                            }

                            Text {
                                anchors.horizontalCenter: parent.horizontalCenter
                                text: backend.command_preview
                                color: backend.theme_text_dim
                                font.pixelSize: 17
                                font.bold: true

                                Behavior on color {
                                    ColorAnimation { duration: 200; easing.type: Easing.OutCubic }
                                }
                            }
                        }
                    }
                }
            }

            Rectangle {
                id: editorPane
                x: leftPane.width + (editorWidth > 0 ? paneGap : 0)
                y: 0
                width: editorWidth
                height: parent.height
                radius: win.windowRadius
                clip: true
                visible: width > 1
                color: backend.theme_input_bg
                border.color: backend.theme_border
                border.width: 1
                opacity: Math.min(1, width / 80)

                Behavior on color {
                    ColorAnimation { duration: 200; easing.type: Easing.OutCubic }
                }

                Behavior on border.color {
                    ColorAnimation { duration: 200; easing.type: Easing.OutCubic }
                }

                Behavior on opacity {
                    NumberAnimation { duration: 180; easing.type: Easing.OutCubic }
                }

                Column {
                    anchors.fill: parent
                    anchors.margins: 14
                    spacing: 10

                    RowLayout {
                        width: parent.width
                        height: 28
                        spacing: 8

                        Item {
                            Layout.fillWidth: true
                        }

                        Rectangle {
                            id: reloadButton
                            radius: win.buttonRadius
                            Layout.preferredWidth: 72
                            Layout.preferredHeight: 28
                            Layout.alignment: Qt.AlignVCenter
                            color: backend.theme_window_bg
                            border.color: backend.theme_border
                            border.width: 1

                            Text {
                                anchors.centerIn: parent
                                text: "Reload"
                                color: backend.theme_text
                                font.pixelSize: 13
                            }

                            MouseArea {
                                anchors.fill: parent
                                cursorShape: Qt.PointingHandCursor
                                onClicked: {
                                    backend.load_themes_file()
                                    editorArea.text = backend.themes_file_text
                                    Qt.callLater(function() { win.focusEditor() })
                                }
                            }
                        }

                        Rectangle {
                            id: saveButton
                            radius: win.buttonRadius
                            Layout.preferredWidth: 58
                            Layout.preferredHeight: 28
                            Layout.alignment: Qt.AlignVCenter
                            color: backend.theme_highlight
                            border.color: backend.theme_highlight
                            border.width: 1

                            Text {
                                anchors.centerIn: parent
                                text: "Save"
                                color: backend.theme_highlight_text
                                font.pixelSize: 13
                                font.bold: true
                            }

                            MouseArea {
                                anchors.fill: parent
                                cursorShape: Qt.PointingHandCursor
                                onClicked: backend.save_themes_file()
                            }
                        }
                    }

                    Rectangle {
                        width: parent.width
                        height: parent.height - 38
                        radius: win.editorInnerRadius
                        color: backend.theme_window_bg
                        border.color: backend.theme_border
                        border.width: 1
                        clip: true

                        ScrollView {
                            anchors.fill: parent
                            anchors.margins: 10
                            clip: true
                            ScrollBar.horizontal.policy: ScrollBar.AsNeeded
                            ScrollBar.vertical.policy: ScrollBar.AsNeeded

                            TextArea {
                                id: editorArea
                                text: ""
                                color: backend.theme_text
                                selectionColor: backend.theme_highlight
                                selectedTextColor: backend.theme_highlight_text
                                placeholderText: "[[theme]]\nid = \"my_theme_dark\"\nname = \"My Theme Dark\""
                                placeholderTextColor: backend.theme_text_dim
                                wrapMode: TextArea.NoWrap
                                font.family: "monospace"
                                font.pixelSize: 14
                                selectByMouse: true
                                persistentSelection: true
                                background: null
                                leftPadding: 0
                                rightPadding: 0
                                topPadding: 0
                                bottomPadding: 0

                                implicitWidth: Math.max(editorPane.width - 60, contentWidth + 20)
                                implicitHeight: Math.max(editorPane.height - 90, contentHeight + 20)

                                Keys.onEscapePressed: win.handleCloseRequest()

                                Keys.onPressed: function(event) {
                                    if ((event.modifiers & Qt.ControlModifier) && event.key === Qt.Key_S) {
                                        backend.save_themes_file()
                                        event.accepted = true
                                    }
                                }

                                onTextChanged: {
                                    if (backend.themes_file_text !== text)
                                        backend.themes_file_text = text
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    Component.onCompleted: {
        x = Math.round((Screen.width - collapsedWidth) / 2)
        y = Math.round((Screen.height - height) / 5)
        requestActivate()
        focusSearchField()
    }
}
