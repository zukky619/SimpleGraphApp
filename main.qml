import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Rectangle {
        id: mainId
        anchors.fill: parent

        Button {
            anchors.top : mainId.top
            anchors.horizontalCenter: mainId.horizontalCenter
            id: buttonId
            onClicked: {
                dataStream.setupSocket(19001);
            }
        }

        GraphView {
            id: graphViewId
            width: 600
            height: 400
            anchors.bottom: mainId.bottom
            anchors.horizontalCenter: mainId.horizontalCenter
            visible: true
        }

    }
}
