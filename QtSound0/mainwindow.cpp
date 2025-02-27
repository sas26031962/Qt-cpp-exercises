#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect( ui->actionPlay0, SIGNAL( triggered() ), this, SLOT( execPlay0() ) );
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::execPlay0()
{
    qDebug() << "execPlay0" << endl;
    QSound::play(":/Sound/sound/MotorHydraulics_YG18_AND_YG17_ON.wav");
}
