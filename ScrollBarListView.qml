import QtQuick 2.11

Item {
    property real valuee: 0
    id: scrollBar
    width: scroller.width
    property var targetForScrBar
    property alias dragger: draggingId

    signal changeContentY(var valY)

    Rectangle {
        id: scroller
        color: "blue"
        width: 20
        height: scrollBar.height
        opacity: 0.1

        MouseArea {
            anchors.fill: parent
            onClicked: {
                console.log("clicked scroller")
            }
        }
    }

    Rectangle {
        id: scrollStick
        width: scroller.width
        height: 30

        color: "Violet"
        opacity: 0.8
        radius: 3
        onYChanged: {
            if (draggingId.drag.active)
                changeContentY(-scrollStick.y * valuee)
        }

        MouseArea {
            id: draggingId
            anchors.fill: parent
            drag.target: scrollStick
            drag.axis: Drag.YAxis
            drag.minimumY: scroller.y
            drag.maximumY: scroller.height - height
        }
    }

    function changeBarY(contentY) {
        scrollStick.y = (scroller.height - scrollStick.height)
                / (targetForScrBar.contentHeight - targetForScrBar.height) * contentY
    }

    function setup() {
        height = targetForScrBar.height
        if (height > targetForScrBar.contentHeight) {
            scrollStick.height = height
        } else {
            scrollStick.height = height / targetForScrBar.contentHeight * height
            valuee = (targetForScrBar.contentHeight - height) / (height - scrollStick.height)
        }
    }
    Component.onCompleted: {
        //making scrollBlock prefered size
        setup()
        changeContentY.connect(targetForScrBar.moveUpDown)
    }
}
