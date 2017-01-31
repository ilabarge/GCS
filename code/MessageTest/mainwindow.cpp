#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
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

    connect(ping,SIGNAL(clicked()),network,SLOT(send_ping()));
    connect(GPS,SIGNAL(clicked()),network,SLOT(sendGPS()));
    connect(this,SIGNAL(sendGPS()),network,SLOT(sendGPS()));
    //network->network_serial_set("COM5");
    connect(network,SIGNAL(vechAuthRequest()),this,SLOT(vechAuthRequest()));
    connect(network,SIGNAL(vechTeleRequest()),this,SLOT(vechTeleRequest()));
}

MainWindow::~MainWindow()
{

}

void MainWindow::waypoint(int id, int type, double lat, double longi, double alt){
    wayNumbLabel.setText(QString::number(id));
    typeLabel.setText(QString::number(type));
    latLabel.setText(QString::number(lat));
    longLabel.setText(QString::number(longi));
    altitudeLabel.setText(QString::number(alt));
}

void MainWindow::vechAuthRequest()
{
    auth = true;
}

void MainWindow::vechTeleRequest()
{
    if(auth){
        emit sendGPS();
    }
}

void MainWindow::initWidgets()
{
    wayNumbLabel.setText("Waypoint ID");
    typeLabel.setText("Type");
    latLabel.setText("Latitude");
    longLabel.setText("Longitude");
    altitudeLabel.setText("Altitude");
}

void MainWindow::initLayouts()
{

}

