import QtQuick 2.15
import QtCharts 2.15

ChartView {
    id: chartView
    width: 600
    height: 400
    title: "SNR pattern"

    property int graphIndex

    ValueAxis {
        id: axisY1
        min: 0
        max: 1
        labelFormat: "%ddB"
    }

    ValueAxis {
        id: axisX
        min: 0
        max: 32
        labelFormat: "Sec%02d"
    }

    LineSeries {
        id: lineSeriesId
        name: "signal 1"
        axisX: axisX
        axisY: axisY1
        useOpenGL: true
    }

    Connections {
        target: dataStream

        function onSeries1Update(minValue, maxValue) {
            if (graphIndex === 1) {
                axisY1.max = Math.ceil(maxValue/10) * 10;
            }
        }
        function onSeries2Update(minValue, maxValue) {
            if (graphIndex === 2) {
                axisY1.max = Math.ceil(maxValue/10) * 10;
            }
        }
        function onSeries3Update(minValue, maxValue) {
            if (graphIndex === 3) {
                axisY1.max = Math.ceil(maxValue/10) * 10;
            }
        }
//        function seriesUpdate(minValue, maxValue) {
//            if (graphIndex === 4) {
//                axisY1.max = Math.ceil(maxValue/10) * 10;
//            }
//        }
    }

    Component.onCompleted: {
        console.log("Chartview load completed.")
        if (graphIndex === 1) {
            dataStream.series1 = lineSeriesId
        } else if (graphIndex === 2) {
            dataStream.series2 = lineSeriesId
        } else if (graphIndex === 3) {
            dataStream.series3 = lineSeriesId
        }
    }
}
