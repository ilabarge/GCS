#include "mainwindow.h"
#include <QApplication>
#include <QDebug>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    //w.show();

    return a.exec();
}
//#include <QSerialPort>


//int main(int argc, char *argv[])
//{
//    QCoreApplication a(argc, argv);

//    // Example use QSerialPortInfo
//    // Example use QSerialPort
//        QSerialPort serial;
//        serial.open(QIODevice::WriteOnly);
//        serial.setPortName("COM5");
//        serial.setBaudRate(QSerialPort::Baud9600);
//        serial.setParity(QSerialPort::NoParity);
//        serial.setFlowControl(QSerialPort::NoFlowControl);
//        serial.open(QIODevice::ReadWrite);
//        long i = 0;
//        while(true)
//        {
//            if (i%555555555 == 0)
//            {
//                serial.write("ok");
//                qDebug() << "sending " << i;
//            }
//            i++;
//        }
//    return a.exec();
//}
