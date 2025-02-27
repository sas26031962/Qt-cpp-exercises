#include <QCoreApplication>
#include <QDir>
#include <QFileInfo>
#include <QDebug> // Для вывода в консоль
#include <QDirIterator>

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


    // Чтение информации о каждом файле и каталоге
    qDebug() << "Target directory: " << directoryPath;

    for (const QFileInfo &fileInfo : fileList)
    {
        cRecord * Record = new cRecord();

        Record->qsName = fileInfo.fileName();
        Record->qsPath  = fileInfo.filePath();
        Record->iSize = fileInfo.size();
        Record->IsDir = fileInfo.isDir();

        cRecord::RecordList->append(Record);

        qDebug() << "Name: " << Record->qsName;
        qDebug() << "Path: " << Record->qsPath;
        qDebug() << "Size: " << Record->iSize << " bytes";
        qDebug() << "IsDir: " << Record->IsDir;
        qDebug() << "--------------------";

        delete Record;

    }

    qDebug() << "RecordList records number: " << cRecord::RecordList->length();
/*
//    cRecord::showList();
    for(int i = 0; i < cRecord::RecordList->count(); i++)
    {
        if(sizeof(cRecord::RecordList->at(i)) > 0)
        {
//            qDebug() << "Name: " << cRecord::RecordList->at(i)->qsName;
//            qDebug() << "Path: " << cRecord::RecordList->at(i)->qsPath;
//            qDebug() << "Sise: " << cRecord::RecordList->at(i)->iSize;
//            qDebug() << "IsDir: " << cRecord::RecordList->at(i)->IsDir;
            qDebug() << "--------------------";
        }
        else
        {
            qDebug() << "Empty element:" << i;
        }
    }//End of for(int i = 0; i < cRecord::RecordList->count(); i++)
*/
    return a.exec();

}//End of int main(int argc, char *argv[])
