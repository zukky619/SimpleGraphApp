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
        qDebug() << QString::fromUtf8(data.data());

        QJsonDocument jsonDoc = QJsonDocument::fromJson(QString::fromUtf8(data.data()).toUtf8());
        QJsonObject jsonObj = jsonDoc.object();

        quint32 value1 = jsonObj.value("value1").toInt();
        QJsonArray value2_array = jsonObj.value("value2").toArray();

        QList<float> emit_array;

        foreach(QJsonValue value, value2_array) {
            emit_array.push_back(static_cast<float>(value.toDouble()));
        }
        emit dataUpdate(emit_array);
    }
}
