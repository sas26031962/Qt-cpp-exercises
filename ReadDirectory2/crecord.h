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
    size_t iSize = 0;
    bool IsDir = false;

    //Конструктор
    explicit cRecord(QObject *parent = 0);
    ~cRecord();

    //Методы
    static void showList();
    void show();

signals:

public slots:

};

#endif // CRECORD_H
