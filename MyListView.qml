import QtQuick 2.11

Item {
    id: rootId

    property var scrBarList
    property alias listviewId: listViewId
    property var delegateHeight: listViewId.height / 10
    ListView {
        clip: true
        id: listViewId
        delegate: delegateId
        width: rootId.width
        height: rootId.height
        model: ListZone.convertedList

        signal changeListBar(int contentY)

        //slot for ScrollBar
        function moveUpDown(cotentforY) {
            if (cotentforY < 0)
                contentY = -cotentforY
            else
                contentY = 0
        }
        //slot for CharList
        function setContextYByIndex(index) {
            if (contentHeight - height < index * delegateHeight) {
                contentY = contentHeight - height
            } else {
                contentY = height / 10 * index
                print("contentY: ", contentY)
                print(height / 10 * index)
            }
        }

        onModelChanged: {
            scrBarList.setup()
        }
        onContentYChanged: {
            if (!scrBarList.dragger.drag.active /* && !listViewId.atYEnd*/)
                changeListBar(contentY)
        }
        Component.onCompleted: {
            changeListBar.connect(scrBarList.changeBarY)
        }
    }
    Component {
        id: delegateId

        Item {
            height: delegateHeight
            width: listViewId.width
            Rectangle {
                anchors.fill: parent
                color: "blue"
                opacity: 0.05
            }
            MouseArea {
                anchors.fill: parent
                //                onClicked: {
                //                    listViewId.contentY = 400
                //                }
            }
            Text {
                anchors.centerIn: parent
                text: modelData.zone
            }
        }
    }
    Rectangle {
        anchors.fill: parent
        color: "black"
        opacity: 0.2
        z: -1
    }
}
