#include "ui_mainwindow.h"
#include "include/mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //BEGIN intialization=======================================================
//    dbdaemon = new datadaemon(this);
    //END initialization========================================================

    //BEGIN TEST CODE===========================================================
//    Vehicle x(0, 2, 20, 1, 3, 3, 3, 3, 3.3, 3.3, 3.3, 3.3, 3.3, 3.3, 3.3, 3.3,
//              3.3, 3.3, 3.3, 3.3);
//    x.setHeading(20.3);
//    vehicles.append(x);
    //END TEST CODE=============================================================

    //BEGIN NETWORKING CODE=====================================================
//    socket = new QUdpSocket(this);
//    socket->bind(QHostAddress("127.0.0.1"), 9001);

//    connect(socket, SIGNAL(readyRead()), this, SLOT(readDatagram()));
    //END NETWORKING CODE=======================================================
}

//void MainWindow::readDatagram(){
//    qDebug() << "Got data." << endl;
//    while(socket->hasPendingDatagrams()){
//        QByteArray datagram;
//        datagram.resize(socket->pendingDatagramSize());
//        QHostAddress sender;
//        quint16 senderPort;

//        socket->readDatagram(datagram.data(), datagram.size(), &sender, &senderPort);

//        processDatagram(datagram);
//    }
//}

//void MainWindow::processDatagram(QByteArray datagram){
//    qDebug() << "Got " << datagram << endl;

//    //for(int i = 0; i < datagram.size(); i++){
//        if(datagram.contains("TOGGLE")){
//            qDebug() << "Changing label." << endl;
//            //Change the collision avoidance status label text appropriately
//            ui->colAvoidActiveLabel->setText(ui->colAvoidActiveLabel->text() == "INACTIVE" ? "ACTIVE" : "INACTIVE");
//            //Change the collision avoidance slider based on change.
//            ui->colAvoidActiveSlider->setValue(ui->colAvoidActiveLabel->text() == "INACTIVE" ? 0 : 1);
//        }
//    //}
//}

MainWindow::~MainWindow()
{
    delete ui;
}
