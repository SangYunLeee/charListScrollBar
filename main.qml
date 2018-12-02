import QtQuick 2.11
import QtQuick.Window 2.11
import QtQuick.Layouts 1.11
import QtQuick.Controls 1.4
import QtMultimedia 5.8
import Qt.labs.platform 1.0

Window {
    id: rootId
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    property string path: ""
    MyColumn {
        id: column1Id
        height: rootId.height
        width: rootId.width

        MyRow {
            width: column1Id.width * 4 / 5
            height: column1Id.height * 4 / 5
            MyListView {
                id: listViewId
                width: column1Id.width * 3 / 5
                height: column1Id.height * 4 / 5
                scrBarList: listscb
            }
            ListForChar {
                id: listForCharId
                width: column1Id.width * 1 / 5
                height: column1Id.height * 4 / 5
                Component.onCompleted: sendIndexOfChar.connect(
                                           listViewId.listviewId.setContextYByIndex)
            }

            ScrollBarListView {
                id: listscb
                width: 8
                targetForScrBar: listViewId.listviewId
            }
        }
        MyRow {
            width: 100
            height: 100
            MyButton {
                width: 50
                height: 50
                color: "black"
                mouseArea.onClicked: fileDialogId.open()
            }
            MyButton {
                width: 50
                height: 50
                color: "red"
                mouseArea.onClicked: ListZone.test()
            }
        }
    }

    FolderDialog {
        id: fileDialogId

        onAccepted: {
            ListZone.getListStringFromQml(folder)
        }
    }
}
