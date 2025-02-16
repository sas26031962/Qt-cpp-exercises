#include <QCoreApplication>
#include <QDir>
#include <QFileInfo>
#include <QDebug> // Для вывода в консоль
#include <QDirIterator>

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    // 1. Укажите путь к каталогу, который нужно прочитать.
    QString directoryPath = "/home/andy"; // Замените на реальный путь
   // QString directoryPath = QCoreApplication::applicationDirPath(); // текущая папка с исполняемым файлом

    // 2. Создайте объект QDir для работы с каталогом.
    QDir directory(directoryPath);

    // 3. Проверьте, существует ли каталог.
    if (!directory.exists()) {
        qDebug() << "Каталог не существует: " << directoryPath;
        return 1;
    }

    // 4. Установите фильтры для выбора нужных файлов и каталогов.
    QDir::Filters filters = QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot;
    directory.setFilter(filters);

    // 5. Установите порядок сортировки.
    directory.setSorting(QDir::Name);

    // 6. Получите список файлов и каталогов.
    QFileInfoList fileList = directory.entryInfoList();

    // 7. Переберите список и выведите информацию о каждом файле и каталоге.
    qDebug() << "Содержимое каталога: " << directoryPath;

    for (const QFileInfo &fileInfo : fileList) {
        QString name = fileInfo.fileName();
        QString path = fileInfo.filePath();
        qint64 size = fileInfo.size();
        bool isDir = fileInfo.isDir();

        qDebug() << "Имя: " << name;
        qDebug() << "Путь: " << path;
        qDebug() << "Размер: " << size << " байт";
        qDebug() << "Это каталог: " << isDir;
        qDebug() << "--------------------";
    }

    //Альтернативный способ итерации по файлам и каталогам
   /* QDirIterator it(directoryPath, filters, QDirIterator::Subdirectories);
     while (it.hasNext()) {
        QString filePath = it.next();
         qDebug() << "File path: " << filePath;
    }*/


    return a.exec();
}
