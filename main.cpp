#include <QApplication>
#include <QtQml/QQmlContext>
#include <QQmlApplicationEngine>
#include "datastream.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);

    dataStream dataStream;
    engine.rootContext()->setContextProperty("dataStream", &dataStream);

    engine.load(url);

    return app.exec();
}
