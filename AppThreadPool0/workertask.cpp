#include "workertask.h"

WorkerTask::WorkerTask(int id) : taskId(id)
{
    //...
}

void WorkerTask::run()
{
    std::cout << "Задача " << taskId << "  выполняется в потоке " << QThread::currentThread() << std::endl;
    QThread::sleep(2); // Симуляция длительной работы
    std::cout << "Задача " << taskId << " завершена.\n" << std::endl;
}
