#include <QCoreApplication>
#include <QDir>
#include <QFileInfo>
#include <QDebug> // Для вывода в консоль
#include <QDirIterator>

#include "crecord.h"

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    // Путь к каталогу, который нужно прочитать.
    QString directoryPath = "/home/andy/Рабочий стол/From Smartfone"; // Путь для linux mint
    //QString directoryPath = "C:/Work/Pictures"; // Путь для Windows10
   // QString directoryPath = QCoreApplication::applicationDirPath(); // текущая папка с исполняемым файлом

    // Объект QDir для работы с каталогом.
    QDir directory(directoryPath);

    // Проверка существования  каталога
    if (!directory.exists())
    {
        qDebug() << "Каталог не существует: " << directoryPath;
        return 1;
    }

    // Фильтры для выбора нужных файлов и каталогов.
    QDir::Filters filters = QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot;
    directory.setFilter(filters);

    // Порядок сортировки.
    directory.setSorting(QDir::Name);

    // Список файлов и каталогов.
    QFileInfoList fileList = directory.entryInfoList();

    // Перебор списка и выведение информации о каждом файле и каталоге.
    qDebug() << "Содержимое каталога: " << directoryPath;

    std::unique_ptr<cRecord> RecordPtr(new cRecord());
    cRecord * Record = RecordPtr.get();
    for (const QFileInfo &fileInfo : fileList)
    {
        QString name = fileInfo.fileName();
        qDebug() << "Name: " << name << " Size=" << sizeof (name);

        QString path = fileInfo.filePath();
        qDebug() << "Path: " << path << " Size=" << sizeof (path);

        size_t size = fileInfo.size();
        qDebug() << "Size: " << size << " Size=" << sizeof (size);

        bool isDir = fileInfo.isDir();
        qDebug() << "IsDir: " << isDir << " Size=" << sizeof (isDir);

        qDebug() << "=====================";

        Record->qsName  = name;
        Record->qsPath = path;
        Record->iSize  = size;
        Record->IsDir = isDir;

        qDebug() << "Name: " << Record->qsName << " Size=" << sizeof (Record->qsName);
        qDebug() << "Path: " << Record->qsPath << " Size=" << sizeof (Record->qsPath);
        qDebug() << "Size: " << Record->iSize << " Size=" << sizeof (Record->iSize);
        qDebug() << "Is Directory: " << Record->IsDir << " Size=" << sizeof (Record->IsDir);
        qDebug() << ">>Record size=" << sizeof (Record);
        qDebug() << "--------------------";
    }

    RecordPtr.reset();

    return a.exec();
}
