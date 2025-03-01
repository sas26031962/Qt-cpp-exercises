#include "crecord.h"

cRecord::cRecord(QObject *parent) : QObject(parent)
{
    qDebug() << "#cRecrod created";
}

cRecord::~cRecord()
{
    qDebug() << "#cRecrod deleted";
}

//auto ptr = std::makeunique<QList<cRecord*> >;
//QList<cRecord*> * cRecord::RecordList = std::move(ptr);

QList<cRecord*> * cRecord::RecordList = new QList<cRecord*>();

void cRecord::showList()
{
    if(cRecord::RecordList->size() > 0)
    {
        for(int i = 0; i < cRecord::RecordList->count(); i++)
        {
            qDebug() << "Name: " << cRecord::RecordList->at(i)->qsName;
            qDebug() << "Path: " << cRecord::RecordList->at(i)->qsPath;
            qDebug() << "Sise: " << cRecord::RecordList->at(i)->iSize;
            qDebug() << "IsDir: " << cRecord::RecordList->at(i)->IsDir;
            qDebug() << "--------------------";
        }
    }
    else
    {
        qDebug() << "List is empty";
    }
}

void cRecord::show()
{
    qDebug() << "Name: " << qsName;
    qDebug() << "Path: " << qsPath;
    qDebug() << "Size: " << iSize;
    qDebug() << "Is Directory: " << IsDir;
    qDebug() << ">>Record size=" << sizeof (this);
    qDebug() << "--------------------";
}
