#include <QCoreApplication>
#include <QDir>
#include <QFileInfo>
#include <QDebug> // Для вывода в консоль
#include <QDirIterator>

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    QString directoryPath = "/home/andy"; // Путь к целевому каталогу
   // QString directoryPath = QCoreApplication::applicationDirPath(); // текущая папка с исполняемым файлом

    QDir directory(directoryPath);//объект QDir для работы с каталогом

    // Проверка на существование каталога
    if (!directory.exists()) {
        qDebug() << "Directory not found: " << directoryPath;
        return 1;
    }

    // Фильтры для выбора нужных файлов и каталогов.
    QDir::Filters filters = QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot;
    directory.setFilter(filters);

    // Порядок сортировки каталога
    directory.setSorting(QDir::Name);

    // Список файлов и каталогов.
    QFileInfoList fileList = directory.entryInfoList();

    // Анализ списока и вывод информации о каждом файле и каталоге.
    qDebug() << "Directrory content: " << directoryPath;

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

    return a.exec();
}
