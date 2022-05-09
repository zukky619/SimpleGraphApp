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

        Column {
            Button {
                text: "Start"

                id: buttonId
                onClicked: {
                    dataStream.setupSocket(19001);
                }
            }

            GraphView {
                id: graph1Id
                graphIndex: 1
            }
            GraphView {
                id: graph2Id
                graphIndex: 2
            }
            GraphView {
                id: graph3Id
                graphIndex: 3
            }

        }
    }
}
