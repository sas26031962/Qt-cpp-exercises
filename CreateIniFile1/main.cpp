/*
#include <QCoreApplication>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    return a.exec();
}
*/

#include <QCoreApplication>
#include <QSettings>
#include <QDebug>
#include <QDir>

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    // 1. Получаем путь к папке проекта.
    QString applicationDirPath = QCoreApplication::applicationDirPath();

    // 2. Формируем путь к подпапке.
    QString configDirPath = QDir::cleanPath(applicationDirPath + "/config");

    // 3. Создаем подпапку, если она не существует.
    QDir configDir(configDirPath);
    if (!configDir.exists()) {
        if (!configDir.mkpath(".")) {
            qDebug() << "Не удалось создать папку конфигурации!";
            return 1;
        }
    }

    // 4. Формируем путь к INI-файлу.
    QString iniFilePath = QDir::cleanPath(configDirPath + "/config.ini");

    // 5. Создаем объект QSettings с указанием пути к файлу.
    QSettings settings(iniFilePath, QSettings::IniFormat);

    // 6. Записываем значения в INI-файл.
    settings.beginGroup("MainWindow");
    settings.setValue("width", 800);
    settings.setValue("height", 600);
    settings.endGroup();

    // 7. Явная запись изменений на диск (необязательно, но рекомендуется).
    settings.sync();

    qDebug() << "Настройки сохранены в: " << iniFilePath;

    return a.exec();
}
