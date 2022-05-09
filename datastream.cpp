#include <QNetworkDatagram>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include "datastream.h"

dataStream::dataStream(QObject *parent)
    : QObject{parent},
      socket(new QUdpSocket(this)),
      port(0)
{

}

void dataStream::setupSocket(uint port)
{
    qDebug() << "setupSocket Called" << port;
    socket->bind(QHostAddress::LocalHost, port);
    connect(socket, &QUdpSocket::readyRead, this, &dataStream::readDatagram);
}

void dataStream::readDatagram()
{
    while (socket->hasPendingDatagrams()) {
        QNetworkDatagram data = socket->receiveDatagram();
        //qDebug() << QString::fromUtf8(data.data());

        QJsonDocument jsonDoc = QJsonDocument::fromJson(QString::fromUtf8(data.data()).toUtf8());
        QJsonObject jsonObj = jsonDoc.object();

        {
            QJsonArray value1_array = jsonObj.value("value1").toArray();

            QList<QPointF> points;

            uint i = 0;
            double minValue = 0;
            double maxValue = 0;
            foreach(QJsonValue value, value1_array) {
                double s = static_cast<float>(value.toDouble());
                QPointF point(i++, s);
                points.push_back(point);
                if (s < minValue) {
                    minValue = s;
                } else if (s > maxValue) {
                    maxValue = s;
                }
            }
            m_series1->replace(points);

            emit series1Update(minValue, maxValue);
        }

        {
            QJsonArray value2_array = jsonObj.value("value2").toArray();

            QList<QPointF> points;

            uint i = 0;
            double minValue = 0;
            double maxValue = 0;
            foreach(QJsonValue value, value2_array) {
                double s = static_cast<float>(value.toDouble());
                QPointF point(i++, s);
                points.push_back(point);
                if (s < minValue) {
                    minValue = s;
                } else if (s > maxValue) {
                    maxValue = s;
                }
            }
            m_series2->replace(points);

            emit series2Update(minValue, maxValue);
        }

        {
            QJsonArray value3_array = jsonObj.value("value3").toArray();

            QList<QPointF> points;

            uint i = 0;
            double minValue = 0;
            double maxValue = 0;
            foreach(QJsonValue value, value3_array) {
                double s = static_cast<float>(value.toDouble());
                QPointF point(i++, s);
                points.push_back(point);
                if (s < minValue) {
                    minValue = s;
                } else if (s > maxValue) {
                    maxValue = s;
                }
            }
            m_series3->replace(points);

            emit series3Update(minValue, maxValue);
        }
    }
}

QtCharts::QLineSeries *dataStream::series1() const
{
    return m_series1;
}

void dataStream::setSeries1(QtCharts::QLineSeries *newSeries1)
{
    if (m_series1 == newSeries1)
        return;
    m_series1 = newSeries1;
    emit series1Changed();
}


QtCharts::QLineSeries *dataStream::series2() const
{
    return m_series2;
}

void dataStream::setSeries2(QtCharts::QLineSeries *newSeries2)
{
    if (m_series2 == newSeries2)
        return;
    m_series2 = newSeries2;
    emit series2Changed();
}

QtCharts::QLineSeries *dataStream::series3() const
{
    return m_series3;
}

void dataStream::setseries3(QtCharts::QLineSeries *newSeries3)
{
    if (m_series3 == newSeries3)
        return;
    m_series3 = newSeries3;
    emit series3Changed();
}

/*
QtCharts::QLineSeries *dataStream::series4() const
{
    return m_series4;
}

void dataStream::setseries4(QtCharts::QLineSeries *newSeries4)
{
    if (m_series4 == newSeries4)
        return;
    m_series4 = newSeries4;
    emit series4Changed();
}
*/
