#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtNetwork/QUdpSocket>
#include <QtNetwork/QHostAddress>
#include <QByteArray>
#include <QVector>

//#include "include/database/datadaemon.h"
//#include "include/database/Vehicle.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
//    QUdpSocket *socket;
//    datadaemon *dbdaemon;

//    QVector<Vehicle> vehicles;

//    void processDatagram(QByteArray datagram);

public slots:
    /**
     * @brief readDatagram
     *  Read a datagram.
     */
//    void readDatagram();
private slots:
};

#endif // MAINWINDOW_H
