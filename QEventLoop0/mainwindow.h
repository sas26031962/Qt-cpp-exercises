#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include <QProgressBar>
#include <QVBoxLayout>
#include <QThread>
#include <QEventLoop>
#include <QTimer>
#include <chrono>
#include <iostream>

#include <workerthread.h>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

using namespace std;

class MainWindow : public QMainWindow {
  Q_OBJECT
public:
    MainWindow() {
        setWindowTitle("QEventLoop Example");

        auto* centralWidget = new QWidget(this);
        setCentralWidget(centralWidget);

        auto* layout = new QVBoxLayout(centralWidget);

        progressLabel = new QLabel("Progress: 0%");
        progressBar = new QProgressBar();
        progressBar->setValue(0);
        startButton = new QPushButton("Start Processing");
        layout->addWidget(progressLabel);
        layout->addWidget(progressBar);
        layout->addWidget(startButton);
        setLayout(layout);
        thread = new WorkerThread(this);

        connect(startButton, &QPushButton::clicked, this, &MainWindow::startProcessing);
        connect(thread, &WorkerThread::progress, this, &MainWindow::updateProgress);
        connect(thread, &WorkerThread::finished, this, &MainWindow::processFinished);
    }

 private slots:
  void startProcessing() {
    startButton->setEnabled(false);
    progressLabel->setText("Progress: 0%");
    progressBar->setValue(0);
     thread->start();
  }

  void updateProgress(int percentage) {
     progressLabel->setText("Progress: " + QString::number(percentage) + "%");
     progressBar->setValue(percentage);
  }

  void processFinished() {
     progressLabel->setText("Process completed");
      startButton->setEnabled(true);
      thread->quit();
      thread->wait();
  }

private:
  QLabel* progressLabel;
  QProgressBar* progressBar;
  QPushButton* startButton;
  WorkerThread* thread;
};

#endif // MAINWINDOW_H
