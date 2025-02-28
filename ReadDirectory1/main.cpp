#include <QCoreApplication>
#include <QDir>
#include <QFileInfo>
#include <QDebug> // Для вывода в консоль
#include <QDirIterator>
#include <QVector>

#include "crecord.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Путь к каталогу, который нужно прочитать
    QString directoryPath = "/home/andy/Рабочий стол/From Smartfone"; // Путь для Linux
    //QString directoryPath = "C:/WORK/Pictures"; // Путь для Windows

   // QString directoryPath = QCoreApplication::applicationDirPath(); // текущая папка с исполняемым файлом

    //Объект QDir для работы с каталогом
    QDir directory(directoryPath);

    if (!directory.exists()) {
        qDebug() << "Directory not found: " << directoryPath;
        return 1;
    }

    // Фильтры для выбора нужных файлов и каталогов
    QDir::Filters filters = QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot;
    directory.setFilter(filters);

    //Порядок сортировки
    directory.setSorting(QDir::Name);

    //Список файлов и каталогов.
    QFileInfoList fileList = directory.entryInfoList();
    size_t FileListSize = fileList.count();
    qDebug() << "FileList size:" << FileListSize;


    // Чтение информации о каждом файле и каталоге
    qDebug() << "Target directory: " << directoryPath;

    //cRecord * Record = new cRecord();
    std::unique_ptr<cRecord> RecordPtr(new cRecord());
    cRecord * Record = RecordPtr.get();

    std::unique_ptr<cRecord> RecordPtr1(new cRecord());
    cRecord * Record1 = RecordPtr1.get();

    //std::unique_ptr<cRecord[]> RecordPtrX(new cRecord[5]);
    //cRecord * RecordX = RecordPtrX.get();

    std::unique_ptr<QVector<cRecord*> >  RecordListPtr(new QVector<cRecord*>);
    QVector<cRecord*> * qvRecordList = RecordListPtr.get();

    qvRecordList->clear();

    Record->qsName = "One";
    Record->qsPath = "Default";
    Record->iSize = 5;
    Record->IsDir = false;


    Record1->qsName = "Two";
    Record1->qsPath = "Default";
    Record1->iSize = 6;
    Record1->IsDir = false;


    //auto RecordsPtr {std::make_unique<cRecord*[]>(FileListSize)};
    std::unique_ptr<cRecord*[]> RecordsPtr(new cRecord*[FileListSize]);

    cRecord * Records[] = {
        Record,
        Record1
    };
//    cRecord * Records[] = RecordsPtr.get();

//    qvRecordList->push_back(Record);
//    qvRecordList->push_back(Record1);
    qvRecordList->push_back(Records[0]);
    qvRecordList->push_back(Records[1]);

/*
    for (const QFileInfo &fileInfo : fileList)
    {
        Record->qsName = fileInfo.fileName();
        Record->qsPath  = fileInfo.filePath();
        Record->iSize = fileInfo.size();
        Record->IsDir = fileInfo.isDir();

//        cRecord::RecordList->append(Record);
        qvRecordList->push_back(Record);

        delete Record;

//        qDebug() << "Имя: " << name;
//        qDebug() << "Путь: " << path;
//        qDebug() << "Размер: " << size << " байт";
//        qDebug() << "Это каталог: " << isDir;
//        qDebug() << "--------------------";
    }
*/
    //delete Record;

    qDebug() << "RecordList records number: " << cRecord::RecordList->length();

//    cRecord::showList();

    for(auto it = qvRecordList->cbegin(); it != qvRecordList->cend(); ++it)
    {
        if(sizeof(*it) > 0)
        {
            qDebug() << ">>>recordSize=" << sizeof(*it);
            auto element = *it;
            qDebug() << "Name: " << element->qsName;
            qDebug() << "Path: " << element->qsPath;
            qDebug() << "Sise: " << element->iSize;
            qDebug() << "IsDir: " << element->IsDir;
            qDebug() << "--------------------";
        }
        else
        {
            qDebug() << "Empty element:";// << record;
        }
    }//End of for(int i = 0; i < cRecord::RecordList->count(); i++)

    return a.exec();

}//End of int main(int argc, char *argv[])
