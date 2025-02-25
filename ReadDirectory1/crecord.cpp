#include "crecord.h"

cRecord::cRecord(QObject *parent) : QObject(parent)
{
    //...
}

//auto ptr = std::makeunique<QList<cRecord*> >;
//QList<cRecord*> * cRecord::RecordList = std::move(ptr);
QList<cRecord*> * cRecord::RecordList = new QList<cRecord*>();
