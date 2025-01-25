#ifndef WORKERTHREAD_H
#define WORKERTHREAD_H

#include <QObject>
#include <QThread>
#include <chrono>
#include <iostream>
#include <thread>

class WorkerThread : public QThread {
  Q_OBJECT
public:
   explicit WorkerThread(QObject *parent = nullptr) : QThread(parent) {}
  signals:
    void progress(int percentage);
    void finished();
  protected:
    void run() override {
        for (int i = 0; i <= 100; ++i) {
          std::this_thread::sleep_for(std::chrono::milliseconds(50));
          emit progress(i);
        }
         emit finished();
      }
};

#endif // WORKERTHREAD_H

/*



 */
