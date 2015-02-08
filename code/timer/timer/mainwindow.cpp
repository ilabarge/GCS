#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qtimer.h"
#include <QDateTime>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
        time.start();
    showTime();
    connect(ui->startButton,SIGNAL(clicked()),this,SLOT(handleButton()));
    connect(ui->stopButton_2,SIGNAL(clicked()),this,SLOT(stopButton()));
}

void MainWindow::showTime()
{
    int secs = time.elapsed()/1000;
    int mins = (secs/60) % 60;
    int hours = (mins/60) % 60;
    secs = secs % 60;

    QString timeText = QString("%1").arg(secs);
    //Replace digital clock with whatever label used
    ui->DigitalClock->setText(QString("%1: %2: %3").arg(hours, 2, 10, QLatin1Char('0'))
                                 .arg(mins, 2, 10, QLatin1Char('0'))
                                 .arg(secs, 2, 10, QLatin1Char('0')))   ;
}

void MainWindow::handleButton()
{
    time.restart();
    connect(&timer, SIGNAL(timeout()), this, SLOT(showTime()));
    timer.start(500);
}

void MainWindow::reset()
{
    int secs,hours,mins = 0;
    ui->DigitalClock->setText(QString("%1: %2: %3").arg(hours, 2, 10, QLatin1Char('0'))
                                 .arg(mins, 2, 10, QLatin1Char('0'))
                                 .arg(secs, 2, 10, QLatin1Char('0')))   ;
}

void MainWindow::stopButton()
{
    timer.stop();
}

MainWindow::~MainWindow()
{
    delete ui;
}

