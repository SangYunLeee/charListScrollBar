import QtQuick 2.11

Item {
    id: rootId
    default property alias content: rowId.children
    property alias color: backgroundId.color
    property alias padding: rowId.padding
    property alias spacing: rowId.spacing

    Row {
        id: rowId
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
