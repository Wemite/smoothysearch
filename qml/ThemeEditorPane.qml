import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Rectangle {
    id: root

    required property var backend
    required property int windowRadius
    required property int buttonRadius
    required property int editorInnerRadius

    signal closeRequested()

    radius: windowRadius
    clip: true
    color: backend.theme_input_bg
    border.color: backend.theme_border
    border.width: 1

    function focusEditor() {
        editorArea.forceActiveFocus()
        editorArea.cursorPosition = editorArea.length
    }

    function syncEditorFromBackend() {
        if (editorArea.text === backend.themes_file_text)
            return

        const hadFocus = editorArea.activeFocus
        const cursorPosition = editorArea.cursorPosition
        editorArea.text = backend.themes_file_text
        editorArea.cursorPosition = Math.min(cursorPosition, editorArea.length)

        if (hadFocus)
            editorArea.forceActiveFocus()
    }

    Behavior on color {
        ColorAnimation { duration: 200; easing.type: Easing.OutCubic }
    }

    Behavior on border.color {
        ColorAnimation { duration: 200; easing.type: Easing.OutCubic }
    }

    onVisibleChanged: {
        if (visible)
            syncEditorFromBackend()
    }

    Connections {
        target: root.backend

        function onThemes_file_textChanged() {
            root.syncEditorFromBackend()
        }
    }

    ColumnLayout {
        anchors.fill: parent
        anchors.margins: 14
        spacing: 10

        RowLayout {
            Layout.fillWidth: true
            Layout.preferredHeight: 28
            spacing: 8
            clip: true

            Rectangle {
                radius: root.buttonRadius
                Layout.preferredWidth: 36
                Layout.preferredHeight: 28
                Layout.alignment: Qt.AlignVCenter
                color: !root.backend.editor_is_config ? root.backend.theme_highlight : root.backend.theme_window_bg
                border.color: !root.backend.editor_is_config ? root.backend.theme_highlight : root.backend.theme_border
                border.width: 1

                Behavior on color {
                    ColorAnimation { duration: 180; easing.type: Easing.OutCubic }
                }

                Behavior on border.color {
                    ColorAnimation { duration: 180; easing.type: Easing.OutCubic }
                }

                Text {
                    anchors.centerIn: parent
                    text: "\uD83C\uDFA8"
                    color: !root.backend.editor_is_config ? root.backend.theme_highlight_text : root.backend.theme_text
                    font.pixelSize: 15

                    Behavior on color {
                        ColorAnimation { duration: 180; easing.type: Easing.OutCubic }
                    }
                }

                MouseArea {
                    anchors.fill: parent
                    cursorShape: Qt.PointingHandCursor
                    onClicked: {
                        root.backend.set_editor_file(false)
                        root.syncEditorFromBackend()
                        Qt.callLater(function() { root.focusEditor() })
                    }
                }
            }

            Rectangle {
                radius: root.buttonRadius
                Layout.preferredWidth: 36
                Layout.preferredHeight: 28
                Layout.alignment: Qt.AlignVCenter
                color: root.backend.editor_is_config ? root.backend.theme_highlight : root.backend.theme_window_bg
                border.color: root.backend.editor_is_config ? root.backend.theme_highlight : root.backend.theme_border
                border.width: 1

                Behavior on color {
                    ColorAnimation { duration: 180; easing.type: Easing.OutCubic }
                }

                Behavior on border.color {
                    ColorAnimation { duration: 180; easing.type: Easing.OutCubic }
                }

                Text {
                    anchors.centerIn: parent
                    text: "\uD83D\uDD27"
                    color: root.backend.editor_is_config ? root.backend.theme_highlight_text : root.backend.theme_text
                    font.pixelSize: 15

                    Behavior on color {
                        ColorAnimation { duration: 180; easing.type: Easing.OutCubic }
                    }
                }

                MouseArea {
                    anchors.fill: parent
                    cursorShape: Qt.PointingHandCursor
                    onClicked: {
                        root.backend.set_editor_file(true)
                        root.syncEditorFromBackend()
                        Qt.callLater(function() { root.focusEditor() })
                    }
                }
            }

            Item {
                Layout.fillWidth: true
            }

            Text {
                Layout.alignment: Qt.AlignVCenter
                Layout.maximumWidth: Math.max(0, root.width - 140)
                text: "Ctrl+S"
                color: root.backend.theme_text_dim
                font.pixelSize: 12
                elide: Text.ElideRight
                horizontalAlignment: Text.AlignRight
                visible: root.width >= 170
            }
        }

        Rectangle {
            Layout.fillWidth: true
            Layout.fillHeight: true
            radius: root.editorInnerRadius
            color: root.backend.theme_window_bg
            border.color: root.backend.theme_border
            border.width: 1
            clip: true

            ScrollView {
                id: editorScroll
                anchors.fill: parent
                anchors.margins: 10
                clip: true
                ScrollBar.horizontal.policy: ScrollBar.AlwaysOff
                ScrollBar.vertical.policy: ScrollBar.AsNeeded

                TextArea {
                    id: editorArea
                    text: ""
                    color: root.backend.theme_text
                    selectionColor: root.backend.theme_highlight
                    selectedTextColor: root.backend.theme_highlight_text
                    placeholderText: "[[theme]]\nid = \"my_theme_dark\"\nname = \"My Theme Dark\""
                    placeholderTextColor: root.backend.theme_text_dim
                    wrapMode: TextArea.WrapAtWordBoundaryOrAnywhere
                    font.family: "monospace"
                    font.pixelSize: 14
                    selectByMouse: true
                    persistentSelection: true
                    background: null
                    leftPadding: 0
                    rightPadding: 0
                    topPadding: 0
                    bottomPadding: 0

                    width: editorScroll.availableWidth
                    height: Math.max(editorScroll.availableHeight, contentHeight + 20)

                    Keys.onEscapePressed: root.closeRequested()

                    Keys.onPressed: function(event) {
                        if (((event.modifiers & Qt.ControlModifier) || (event.modifiers & Qt.MetaModifier))
                                && event.key === Qt.Key_S) {
                            root.backend.save_themes_file()
                            event.accepted = true
                        }
                    }

                    onTextChanged: {
                        if (root.backend.themes_file_text !== text)
                            root.backend.themes_file_text = text
                    }
                }
            }
        }
    }
}
