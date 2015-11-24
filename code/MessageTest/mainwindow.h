#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QPushButton"
#include "networking.h"
#include "QGridLayout"
#include "QLineEdit"
#include "QLabel"
#include <QtSerialPort/QtSerialPort>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

signals:
    void sendGPS();

public slots:
    void waypoint(int,int,double,double,double);
    void vechAuthRequest();
    void vechTeleRequest();

private:
    //Sending info to GCS
    QPushButton autoSendGPS;

    //Display Recieved Info
    //Waypoint
    QGridLayout waypointRec;
    QLabel wayNumbLabel;
    QLabel wayNumbData;
    QLabel typeLabel;
    QLabel typeData;
    QLabel latLabel;
    QLabel latData;
    QLabel longLabel;
    QLabel longData;
    QLabel altitudeLabel;
    QLabel altitudeData;
    //Vehicle Auth
    QLabel authLabel;
    QLabel authStatus;
    //Vehicle Telemetry
    QLabel teleLabel;
    QLabel teleStatus;

    void initWidgets();
    void initLayouts();
    bool auth;
};

#endif // MAINWINDOW_H
