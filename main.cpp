#include <QApplication>
//#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "filetest.h"
#include <QDebug>
#include "qhtml5file/qhtml5file.h"
#include <QQmlContext>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QApplication app (argc, argv);

    QQmlApplicationEngine engine;

    FileTest fileTest;
    /*
     Make fileTest visible to QML.
     QML needs to catch fileTests toTextEdit signal.
     This needs to be done before engine.load()
     */
    engine.rootContext()->setContextProperty("fileTest", &fileTest);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    // Get the QML for creating signal-slot connections
    QObject *mainQml= engine.rootObjects().first();

    QObject::connect(mainQml, SIGNAL(loadFile()), &fileTest, SLOT(loadFile()));
    QObject::connect(mainQml, SIGNAL(saveFile(QString)), &fileTest, SLOT(saveFile(QString)));

    return app.exec();
}
