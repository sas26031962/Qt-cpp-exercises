#include <QCoreApplication>
#include <QDebug>
#include <QThreadPool>
#include <iostream>

#include "workertask.h"

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QThreadPool* pool = QThreadPool::globalInstance();
    int iMaxPoolTaskCount = 10;
    pool->setMaxThreadCount(iMaxPoolTaskCount);

    std::cout << "Количество потоков в пуле:" << pool->maxThreadCount() << std::endl;

    // Добавляем задачи в пул
    for (int i = 1; i <= iMaxPoolTaskCount; ++i)
    {
        WorkerTask* task = new WorkerTask(i);

        // Указываем, что объект будет автоматически удалён после завершения
        task->setAutoDelete(true);

        pool->start(task);
    }

    std::cout << "Все задачи отправлены в пул." << std::endl;

    // Дожидаемся завершения всех задач
    pool->waitForDone();

    std::cout << "Все задачи завершены." << std::endl;

    return 0;


    return a.exec();
}

