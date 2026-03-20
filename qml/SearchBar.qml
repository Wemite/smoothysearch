import QtQuick
import QtQuick.Controls

Rectangle {
    id: root

    required property var backend
    required property int panelRadius

    signal launchRequested()
    signal closeRequested()
    property alias text: field.text

    radius: panelRadius
    color: backend.theme_input_bg
    border.color: backend.theme_border
    border.width: 1

    function focusField() {
        field.forceActiveFocus()
        field.cursorPosition = field.text.length
    }

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
            anchors.right: parent.right
            anchors.verticalCenter: parent.verticalCenter
            height: parent.height
            color: root.backend.theme_text
            placeholderText: root.backend.is_themes_mode ? "Theme search..." : "Search..."
            placeholderTextColor: root.backend.theme_text_dim
            font.pixelSize: 18
            background: null
            focus: true
            selectByMouse: true
            cursorVisible: true

            onTextChanged: {
                root.backend.set_query(text)
            }

            Keys.onDownPressed: function(event) {
                root.backend.move_down()
                event.accepted = true
            }
            Keys.onUpPressed: function(event) {
                root.backend.move_up()
                event.accepted = true
            }
            Keys.onReturnPressed: function(event) {
                root.launchRequested()
                event.accepted = true
            }
            Keys.onEnterPressed: function(event) {
                root.launchRequested()
                event.accepted = true
            }
            Keys.onEscapePressed: function(event) {
                root.closeRequested()
                event.accepted = true
            }

            Behavior on color {
                ColorAnimation { duration: 200; easing.type: Easing.OutCubic }
            }

            Behavior on placeholderTextColor {
                ColorAnimation { duration: 200; easing.type: Easing.OutCubic }
            }
        }
    }
}
