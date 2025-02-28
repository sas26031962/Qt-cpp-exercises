#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect( ui->actionPlay0, SIGNAL( triggered() ), this, SLOT( execPlay0() ) );
    connect( ui->actionPlay1, SIGNAL( triggered() ), this, SLOT( execPlay1() ) );
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

void MainWindow::execPlay1()
{
    qDebug() << "execPlay1" << endl;
    QSound::play(":/Sound/sound/MotorHydro_ARS.wav");
}
