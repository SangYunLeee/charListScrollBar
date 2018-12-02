import QtQuick 2.11
import QtGraphicalEffects 1.0

Item {
    id: rootId
    width: height
    height: 60
    signal clicked
    property alias color: backgroundId.color
    property alias mouseArea: mouseAreaId

    //background
    Rectangle {
        z: -1
        id: backgroundId
        anchors.fill: rootId
        color: "red"
    }
    MouseArea {
        id: mouseAreaId
        anchors.fill: parent
    }
}
