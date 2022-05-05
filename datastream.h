#ifndef DATASTREAM_H
#define DATASTREAM_H

#include <QObject>
#include <QThread>
#include <QUdpSocket>

class dataStream : public QObject
{
    Q_OBJECT
    QUdpSocket *socket;
    uint port;

public:
    explicit dataStream(QObject *parent = nullptr);

    Q_INVOKABLE void setupSocket(uint port);
    void readDatagram();

signals:
    Q_SIGNAL void dataUpdate(QList<float> dataarray);

};

#endif // DATASTREAM_H
