#include "mainwindow.h"
#include "QPushButton"
#include "networking.h"
#include "QGridLayout"
#include "QLineEdit"
#include <QtSerialPort/QtSerialPort>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
  //,ui(new Ui::MainWindow)
{

    QGridLayout *lay = new QGridLayout();
    //Buttons
    QPushButton *ping = new QPushButton();
    QPushButton *GPS = new QPushButton();

    ping->setText("Send ping");
    GPS->setText("Send GPS");
    QPushButton *setSerial = new QPushButton();
    setSerial->setText("Serial set");
    networking *network = new networking();

    //Positioning Buttons
    lay->addWidget(ping,1,1);
    lay->addWidget(GPS,2,1);

//    lay->addWidget(setSerial,2,1);
    QWidget* display = new QWidget();
    display->setLayout(lay);
    setCentralWidget(display);
    showMaximized();

    connect(ping,SIGNAL(clicked()),network,SLOT(send_Ping()));
    connect(GPS,SIGNAL(clicked()),network,SLOT(send_GPS()));

    //network->network_serial_set("COM5");
    //ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    //delete ui;

}
