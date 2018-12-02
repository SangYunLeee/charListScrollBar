import QtQuick 2.11

Item {
    id: rootId
    default property alias content: columnId.children
    property alias color: backgroundId.color
    property alias padding: columnId.padding
    property alias spacing: columnId.spacing
    Column {
        id: columnId
        height: rootId.height
        width: rootId.width
    }
    //background
    Rectangle {
        z: -1
        id: backgroundId
        anchors.fill: rootId
        color: "Khaki"
    }
}
