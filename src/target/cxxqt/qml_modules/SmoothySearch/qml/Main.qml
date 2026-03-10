import QtQuick
import QtQuick.Controls.Basic
import QtQuick.Layouts
import SmoothySearch

ApplicationWindow {
    id: win
    width: 480
    height: 360
    visible: true
    flags: Qt.FramelessWindowHint | Qt.WindowStaysOnTopHint
    color: "transparent"
    title: "SmoothySearch"

    Backend {
        id: backend
    }

    onActiveChanged: {
        if (!active)
            Qt.quit()
    }

    Rectangle {
        anchors.fill: parent
        radius: 36
        color: backend.theme_window_bg
        border.color: backend.theme_border
        border.width: 2

        ColumnLayout {
            anchors.fill: parent
            anchors.margins: 18
            spacing: 14

            Rectangle {
                Layout.fillWidth: true
                height: 52
                radius: 48
                color: backend.theme_input_bg
                border.color: backend.theme_border
                border.width: 1

                RowLayout {
                    anchors.fill: parent
                    anchors.leftMargin: 14
                    anchors.rightMargin: 14
                    spacing: 0

                    Item {
                        width: 20
                        height: parent.height

                        Text {
                            anchors.centerIn: parent
                            text: "⌕"
                            color: backend.theme_highlight
                            font.pixelSize: 32
                        }
                    }

                    TextField {
                        id: field
                        Layout.fillWidth: true
                        color: backend.theme_text
                        placeholderText: backend.is_themes_mode ? "Theme search..." : "Search..."
                        placeholderTextColor: backend.theme_text_dim
                        font.pixelSize: 18
                        background: null
                        focus: true
                        selectByMouse: true

                        onTextChanged: backend.set_query(text)

                        Keys.onDownPressed: backend.move_down()
                        Keys.onUpPressed: backend.move_up()

                        Keys.onReturnPressed: {
                            backend.launch_current()
                        }

                        Keys.onEnterPressed: {
                            backend.launch_current()
                        }

                        Keys.onEscapePressed: Qt.quit()
                    }
                }
            }

            Item {
                Layout.fillWidth: true
                Layout.fillHeight: true

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

                    function indexFromViewY(yPos) {
                        const contentPos = yPos + contentY
                        const idx = Math.floor(contentPos / rowStep)
                        if (idx < 0 || idx >= count)
                            return -1
                            return idx
                    }

                    MouseArea {
                        id: listMouse
                        anchors.fill: parent
                        acceptedButtons: Qt.LeftButton
                        hoverEnabled: false
                        z: 20

                        property real wheelAccumulator: 0

                        onClicked: function(mouse) {
                            const idx = list.indexFromViewY(mouse.y)
                            if (idx < 0)
                                return

                                if (backend.current_index === idx) {
                                    backend.launch_current()
                                } else {
                                    backend.select_index(idx)
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

                    Behavior on contentY {
                        NumberAnimation {
                            duration: 220
                            easing.type: Easing.OutCubic
                        }
                    }

                    Rectangle {
                        id: highlight
                        z: -1
                        visible: list.currentIndex >= 0
                        x: 0
                        width: list.width
                        height: list.rowHeight
                        radius: height / 2
                        color: backend.theme_highlight

                        y: {
                            if (list.currentIndex < 0)
                                return 0

                                const rawY = list.currentIndex * list.rowStep - list.contentY
                                const maxY = list.height - height

                                if (rawY < 0)
                                    return 0
                                    if (rawY > maxY)
                                        return maxY
                                        return rawY
                        }

                        Behavior on y {
                            SpringAnimation {
                                spring: 5
                                damping: 0.34
                            }
                        }
                    }

                    delegate: Item {
                        width: list.width
                        height: list.rowHeight
                        z: 1

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

                                color: {
                                    const itemTop = parent.parent.y - list.contentY
                                    const itemBottom = itemTop + parent.parent.height
                                    const itemCenter = (itemTop + itemBottom) / 2

                                    const hlTop = highlight.y
                                    const hlBottom = highlight.y + highlight.height

                                    return (itemCenter >= hlTop && itemCenter <= hlBottom)
                                    ? backend.theme_highlight_text
                                    : backend.theme_text
                                }
                            }
                        }
                    }

                    onCurrentIndexChanged: {
                        if (currentIndex < 0)
                            return

                            const itemTop = currentIndex * rowStep
                            const itemBottom = itemTop + rowHeight

                            const viewTop = contentY
                            const viewBottom = contentY + height

                            if (itemTop < viewTop) {
                                contentY = itemTop
                            } else if (itemBottom > viewBottom) {
                                contentY = itemBottom - height
                            }
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
                    }

                    Text {
                        anchors.horizontalCenter: parent.horizontalCenter
                        text: backend.command_preview
                        color: backend.theme_text_dim
                        font.pixelSize: 17
                        font.bold: true
                    }
                }
            }
        }
    }

    Component.onCompleted: {
        x = Math.round((Screen.width - width) / 2)
        y = Math.round((Screen.height - height) / 5)
        requestActivate()
        field.forceActiveFocus()
    }
}
