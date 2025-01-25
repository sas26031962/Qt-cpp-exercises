#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    globalCounter++;

    std::cout << "globalCounter=" << globalCounter << std::endl;

}

MainWindow::~MainWindow()
{
    delete ui;
}

