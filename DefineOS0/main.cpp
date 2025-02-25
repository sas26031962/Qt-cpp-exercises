#include <QCoreApplication>
#include <QString>
#include <QSysInfo>
#include <QFile>
#include <QTextStream>
#include <QtDebug>

QString getOSInfo()
{
    QString osInfo;

    // Определение базовой ОС с помощью макросов Qt
#ifdef Q_OS_WIN
    osInfo = "Windows";
    // Дополнительная информация о версии Windows
    osInfo += " " + QSysInfo::productVersion();
#elif defined(Q_OS_MACOS)
    osInfo = "macOS";
    osInfo += " " + QSysInfo::productVersion();
#elif defined(Q_OS_LINUX)
    // Попытка определить дистрибутив Linux
    osInfo = "Linux";

    // Чтение информации из /etc/os-release
    QFile file("/etc/os-release");
    if (file.open(QIODevice::ReadOnly)) {
        QTextStream in(&file);
        while (!in.atEnd()) {
            QString line = in.readLine();
            if (line.startsWith("PRETTY_NAME=")) {
                QString prettyName = line.section('=', 1).trimmed();
                prettyName.remove('"');
                osInfo += " (" + prettyName + ")";
                break;
            }
        }
        file.close();
    }
#elif defined(Q_OS_ANDROID)
    osInfo = "Android";
    osInfo += " " + QSysInfo::productVersion();
#elif defined(Q_OS_IOS)
    osInfo = "iOS";
    osInfo += " " + QSysInfo::productVersion();
#else
    osInfo = "Unknown OS";
#endif

    // Дополнительная информация
    osInfo += "\nKernel: " + QSysInfo::kernelType() +
              " " + QSysInfo::kernelVersion();

    return osInfo;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qDebug() << "OsInfo" << getOSInfo();

    return a.exec();
}
