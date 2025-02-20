#include <QCoreApplication>
#include <QSettings>
#include <QDebug>

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    // 1. Укажите имя организации и имя приложения.
    QCoreApplication::setOrganizationName("MyOrganization");
    QCoreApplication::setApplicationName("MyApp");

    // 2. Создайте объект QSettings для работы с INI-файлом.
    //    Первый аргумент - формат хранения (QSettings::IniFormat).
    //    Второй аргумент - область хранения (QSettings::UserScope или QSettings::SystemScope).
    //    Третий аргумент - имя организации.
    //    Четвертый аргумент - имя приложения.
    QSettings settings(QSettings::IniFormat, QSettings::UserScope,
                         QCoreApplication::organizationName(), QCoreApplication::applicationName());

    // 3. Запись значений в INI-файл.
    settings.beginGroup("MainWindow"); //Начинаем секцию MainWindow
    settings.setValue("width", 800);
    settings.setValue("height", 600);
    settings.setValue("xPosition", 100);
    settings.setValue("yPosition", 50);
    settings.endGroup(); //Заканчиваем секцию MainWindow

    settings.beginGroup("General"); //Начинаем секцию General
    settings.setValue("language", "en");
    settings.setValue("showSplashScreen", true);
    settings.endGroup(); //Заканчиваем секцию General

    // 4. Чтение значений из INI-файла.
    settings.beginGroup("MainWindow");
    int width = settings.value("width", 640).toInt(); // Второй аргумент - значение по умолчанию.
    int height = settings.value("height", 480).toInt();
    int xPosition = settings.value("xPosition", 0).toInt();
    int yPosition = settings.value("yPosition", 0).toInt();
    settings.endGroup();

    settings.beginGroup("General");
    QString language = settings.value("language", "ru").toString();
    bool showSplashScreen = settings.value("showSplashScreen", false).toBool();
    settings.endGroup();

    // 5. Вывод прочитанных значений.
    qDebug() << "Width: " << width;
    qDebug() << "Height: " << height;
    qDebug() << "X Position: " << xPosition;
    qDebug() << "Y Position: " << yPosition;
    qDebug() << "Language: " << language;
    qDebug() << "Show splash screen: " << showSplashScreen;

   settings.sync();//Явная запись файла на диск
   qDebug() << "Store file on the disk";// << x;

    return a.exec();
}
