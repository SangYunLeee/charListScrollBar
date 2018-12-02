import QtQuick 2.11

Item {
    id: rootId
    signal sendIndexOfChar(int contentY)

    property real delegateHeight: listViewId.height / listViewId.count
    ListView {
        clip: true
        id: listViewId
        delegate: delegateId
        width: rootId.width
        height: rootId.height
        model: ListZone.convertedCharList
        Component.onCompleted: print(height, width)
        interactive: false
    }
    Component {
        id: delegateId

        Item {
            height: listViewId.height / listViewId.count
            width: listViewId.width
            Rectangle {
                anchors.fill: parent
                color: "red"
                opacity: 0.1
                z: -1
            }
            MouseArea {
                anchors.fill: parent
                onClicked: {
                    print(modelData.index)
                    sendIndexOfChar(modelData.index)
                }
            }
            Text {
                anchors.centerIn: parent
                text: modelData.zone
            }
        }
    }
    Rectangle {
        anchors.fill: parent
        color: "red"
        opacity: 0.1
        z: -1
    }
}
