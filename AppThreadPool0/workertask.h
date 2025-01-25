#ifndef WORKERTASK_H
#define WORKERTASK_H

#include <QRunnable>
#include <QThread>
#include <QDebug>
#include <iostream>


class WorkerTask : public QRunnable
{
public:
    explicit WorkerTask(int id);

    void run();
private:
    int taskId; // Уникальный идентификатор задачи
 };

#endif // WORKERTASK_H

/*
#ifndef WORKERTASK_H
#define WORKERTASK_H

#include <QRunnable>
#include <QDebug>

class WorkerTask : public QRunnable {
public:
    explicit WorkerTask(int id) : taskId(id) {}

    void run() override {
        qDebug() << "Задача" << taskId << "выполняется в потоке" << QThread::currentThread();
        QThread::sleep(2); // Симуляция длительной работы
        qDebug() << "Задача" << taskId << "завершена.";
    }

private:
    int taskId; // Уникальный идентификатор задачи
};

#endif // WORKERTASK_H

*/
