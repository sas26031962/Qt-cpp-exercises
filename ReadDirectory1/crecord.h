#ifndef CRECORD_H
#define CRECORD_H

#include <QObject>
#include <memory>
#include <QDebug>

class cRecord : public QObject
{
    Q_OBJECT
public:
    //Атрибуты
    static QList<cRecord*> * RecordList;
    QString qsName = "NoName";
    QString qsPath = "";
    qint64 iSize = 0;
    bool IsDir = false;

    //Конструктор
    explicit cRecord(QObject *parent = 0);

    //Методы
    static void showList();

signals:

public slots:

};

#endif // CRECORD_H
