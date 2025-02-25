#include <QCoreApplication>
#include <QDir>
#include <QFileInfo>
#include <QDebug> // Для вывода в консоль
#include <QDirIterator>
#include <QList>

#include "crecord.h"

//
// Глобальные переменные
//

QString DetectedOs = "Default OS name";

//QString directoryPath = QCoreApplication::applicationDirPath();// текущая папка с исполняемым файлом
QString directoryPath = "C:/WORK/Pictures"; // Путь к целевому каталогу на VirtualBox Windows

//
// Главная функция программы
//
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

#ifdef Q__OS_WIN
    //qDebug() << "OS Windows detected";
    directoryPath = "C:/WORK/Pictures"; // Путь к целевому каталогу Windows
    DetectedOs = "OS Windows";
#endif

#ifdef Q__OS_LINUX
    //qDebug() << "OS Linux detected";
    directoryPath = "/home/andy/Рабочий стол"; // Путь к целевому каталогу Linux
    DetectedOs = "OS Linux";
#endif

    qDebug() << "Detected OS:" << DetectedOs;

    QDir directory(directoryPath);//объект QDir для работы с каталогом

    // Проверка на существование каталога
    if (!directory.exists())
    {
        qDebug() << "Directory not found: " << directoryPath;
        delete cRecord::RecordList;
        return 1;
    }
    else
    {
        qDebug() << "Working directory:" << directoryPath;
    }

    // Фильтры для выбора нужных файлов и каталогов.
    QDir::Filters filters = QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot;
    directory.setFilter(filters);

    // Порядок сортировки каталога
    directory.setSorting(QDir::Name);

    // Список файлов и каталогов.
    QFileInfoList fileList = directory.entryInfoList();

    // Анализ списока и вывод информации о каждом файле и каталоге.
    //qDebug() << "Directrory content: " << directoryPath;

    for (const QFileInfo &fileInfo : fileList)
    {
        QString name = fileInfo.fileName();
        QString path = fileInfo.filePath();
        qint64 size = fileInfo.size();
        bool isDir = fileInfo.isDir();

        qDebug() << "Name: " << name;
        qDebug() << "Path: " << path;
        qDebug() << "Sise: " << size << " bytes";
        qDebug() << "IsDir: " << isDir;
        qDebug() << "--------------------";
    }

    delete cRecord::RecordList;

    return a.exec();
}
