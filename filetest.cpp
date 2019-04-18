#include "filetest.h"

FileTest::FileTest(QObject *parent) : QObject(parent)
{


}

void FileTest::loadFile() {
    QHtml5File::load(".txt", [=](QByteArray contents, QString fileName){qDebug() << fileName; qDebug() << contents; emit toTextEdit(contents);});
}

void FileTest::saveFile(QString contents) {
    // pass the contents as a QByteArray
    QHtml5File::save(contents.toUtf8(), "QtWasmFile.txt");
}
