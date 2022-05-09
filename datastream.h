#ifndef DATASTREAM_H
#define DATASTREAM_H

#include <QObject>
#include <QThread>
#include <QUdpSocket>
#include <QtCharts/QLineSeries>

QT_USE_NAMESPACE

class dataStream : public QObject
{
    Q_OBJECT
    QUdpSocket *socket;
    uint port;

    Q_PROPERTY(QtCharts::QLineSeries* series1 READ series1 WRITE setSeries1 NOTIFY series1Changed)
    Q_PROPERTY(QtCharts::QLineSeries* series2 READ series2 WRITE setSeries2 NOTIFY series2Changed)
    Q_PROPERTY(QtCharts::QLineSeries* series3 READ series3 WRITE setseries3 NOTIFY series3Changed)
//    Q_PROPERTY(QtCharts::QLineSeries* series4 READ series4 WRITE setseries4 NOTIFY series4Changed)

public:
    explicit dataStream(QObject *parent = nullptr);

    Q_INVOKABLE void setupSocket(uint port);
    void readDatagram();

    QtCharts::QLineSeries *series1() const;
    void setSeries1(QtCharts::QLineSeries *newSeries1);

    QtCharts::QLineSeries *series2() const;
    void setSeries2(QtCharts::QLineSeries *newSeries2);

    QtCharts::QLineSeries *series3() const;
    void setseries3(QtCharts::QLineSeries *newSeries3);

//    QtCharts::QLineSeries *series4() const;
//    void setseries4(QtCharts::QLineSeries *newSeries4);

signals:
    Q_SIGNAL void series1Update(float minValue, float maxValue);
    Q_SIGNAL void series2Update(double minValue, double maxValue);
    Q_SIGNAL void series3Update(double minValue, double maxValue);
//    Q_SIGNAL void series4Update(double minValue, double maxValue);
    void series1Changed();
    void series2Changed();
    void series3Changed();
//    void series4Changed();

private:
    QtCharts::QLineSeries *m_series1;
    QtCharts::QLineSeries *m_series2;
    QtCharts::QLineSeries *m_series3;
//    QtCharts::QLineSeries *m_series4;
};

#endif // DATASTREAM_H
