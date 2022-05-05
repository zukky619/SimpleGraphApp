import QtQuick 2.15
import QtCharts 2.15

ChartView {
    id: chartView

    ValueAxis {
        id: axisY1
        min: -1
        max: 4
    }

    ValueAxis {
        id: axisX
        min: 0
        max: 32
    }

    LineSeries {
        id: lineSeries1
        name: "signal 1"
        axisX: axisX
        axisY: axisY1
        useOpenGL: false

        XYPoint {
            id: sec0Id
            x: 0
            y: 0
        }
        XYPoint {
            id: sec1Id
            x: 1
            y: 0
        }
    }

    Connections {
        target: dataStream

        function onDataUpdate(dataarray) {
            sec0Id.y = dataarray[0];
            sec1Id.y = dataarray[1];
            console.log("sec0Id.y = " + sec0Id.y + ", sec1Id.y = " + sec1Id.y)
        }
    }

    Component.onCompleted: {
        console.log("Chartview load completed.")
    }
}
