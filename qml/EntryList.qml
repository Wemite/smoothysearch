import QtQuick
import QtQuick.Controls

Item {
    id: root

    required property var backend
    required property int selectorRadius
    required property int wheelStepAngle
    required property int animationToken

    signal launchRequested()
    signal focusSearchRequested()

    property int revealToken: 0

    function triggerReveal() {
        revealToken = animationToken
        revealWindowTimer.restart()
    }

    Timer {
        id: revealWindowTimer
        interval: 720
        repeat: false
        onTriggered: root.revealToken = 0
    }

    Connections {
        target: root

        function onAnimationTokenChanged() {
            root.triggerReveal()
        }
    }

    ListView {
        id: list
        anchors.fill: parent
        model: root.backend.items
        spacing: 8
        clip: true
        currentIndex: root.backend.current_index
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

                if (idx < 0)
                    return

                if (root.backend.current_index === idx) {
                    root.launchRequested()
                } else {
                    root.backend.select_index(idx)
                    root.focusSearchRequested()
                }
            }

            onWheel: function(wheel) {
                wheelAccumulator += wheel.angleDelta.y

                while (wheelAccumulator <= -root.wheelStepAngle) {
                    const before = root.backend.current_index
                    root.backend.move_down()
                    if (root.backend.current_index !== before)
                        root.focusSearchRequested()
                    wheelAccumulator += root.wheelStepAngle
                }

                while (wheelAccumulator >= root.wheelStepAngle) {
                    const before = root.backend.current_index
                    root.backend.move_up()
                    if (root.backend.current_index !== before)
                        root.focusSearchRequested()
                    wheelAccumulator -= root.wheelStepAngle
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
            radius: root.selectorRadius
            color: root.backend.theme_highlight

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
            x: 0
            opacity: 1
            property int lastRevealToken: 0

            function playRevealAnimation() {
                if (root.revealToken === 0 || lastRevealToken === root.revealToken)
                    return

                lastRevealToken = root.revealToken
                x = -56
                opacity = 0
                revealAnimation.restart()
            }

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
                spacing: root.backend.is_themes_mode ? 12 : 0

                Item {
                    width: root.backend.is_themes_mode ? 12 : 0
                    height: 20
                    anchors.verticalCenter: parent.verticalCenter
                    visible: root.backend.is_themes_mode

                    readonly property string previewColor: (
                        index >= 0 && index < root.backend.preview_colors.length
                        ? root.backend.preview_colors[index]
                        : ""
                    )

                    Rectangle {
                        width: 12
                        height: 12
                        radius: 6
                        anchors.centerIn: parent
                        visible: parent.previewColor !== ""
                        color: parent.previewColor
                        border.width: 1
                        border.color: Qt.rgba(0, 0, 0, 0.18)
                    }
                }

                Item {
                    anchors.verticalCenter: parent.verticalCenter
                    width: searchLabel.visible
                        ? searchLabel.implicitWidth + searchQueryLabel.implicitWidth
                        : (themeCommandLabel.visible
                            ? themeCommandLabel.implicitWidth
                            : defaultLabel.implicitWidth)
                    height: Math.max(defaultLabel.implicitHeight, searchLabel.implicitHeight)

                    readonly property color rowColor: rowItem.visuallySelected
                        ? root.backend.theme_highlight_text
                        : root.backend.theme_text
                    readonly property bool searchEntry: root.backend.is_search_index(index)
                    readonly property bool themeCommandEntry: root.backend.is_theme_command_index(index)

                    Text {
                        id: defaultLabel
                        visible: !parent.searchEntry && !parent.themeCommandEntry
                        text: modelData
                        font.pixelSize: 17
                        color: parent.rowColor
                    }

                    Text {
                        id: themeCommandLabel
                        visible: parent.themeCommandEntry
                        text: "Switch theme"
                        font.pixelSize: 17
                        color: parent.rowColor
                    }

                    Text {
                        id: searchLabel
                        visible: parent.searchEntry
                        text: "Search"
                        font.pixelSize: 17
                        color: parent.rowColor
                        opacity: 0.56
                    }

                    Text {
                        id: searchQueryLabel
                        visible: parent.searchEntry
                        anchors.left: searchLabel.right
                        text: root.backend.current_text !== "" ? " " + root.backend.current_text : ""
                        font.pixelSize: 17
                        color: parent.rowColor
                    }
                }
            }

            Rectangle {
                width: 8
                height: 8
                radius: 4
                anchors.right: parent.right
                anchors.rightMargin: 18
                anchors.verticalCenter: parent.verticalCenter
                visible: root.backend.is_themes_mode
                    && root.backend.applied_theme_id !== ""
                    && root.backend.is_applied_theme_index(index)
                color: rowItem.visuallySelected
                    ? root.backend.theme_highlight_text
                    : root.backend.theme_text_dim
            }

            SequentialAnimation {
                id: revealAnimation
                running: false

                PauseAnimation {
                    duration: Math.min(index * 22, 180)
                }

                ParallelAnimation {
                    NumberAnimation {
                        target: rowItem
                        property: "x"
                        from: -56
                        to: 0
                        duration: 420
                        easing.type: Easing.OutBack
                        easing.overshoot: 1.18
                    }

                    NumberAnimation {
                        target: rowItem
                        property: "opacity"
                        from: 0
                        to: 1
                        duration: 220
                        easing.type: Easing.OutCubic
                    }
                }
            }

            Connections {
                target: root

                function onRevealTokenChanged() {
                    rowItem.playRevealAnimation()
                }
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
}
