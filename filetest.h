#ifndef FILETEST_H
#define FILETEST_H

#include <QObject>
#include <QtDebug>
#include <qhtml5file/qhtml5file.h>

class FileTest : public QObject
{
    Q_OBJECT
public:
    explicit FileTest(QObject *parent = nullptr);

signals:
    void toTextEdit(QByteArray contents);

public slots:
    void loadFile();
    void saveFile(QString contents);
};

#endif // FILETEST_H
