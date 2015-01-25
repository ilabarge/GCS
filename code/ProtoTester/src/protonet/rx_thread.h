#ifndef RX_THREAD_H
#define RX_THREAD_H
//QT includes
#include <QDebug>
#include <QMutex>
#include <QDateTime>
#include <QObject>
#include <QDebug>
#include <QStringList>
#include <QThread>

//C lib includes
#include <cstring>
#include <chrono>
#include <iostream>
#include <string>

//GCS Includes
#include "protonet.h"


class rx_thread : public QObject
{
    Q_OBJECT
public:
    rx_thread(uint8_t, uint16_t, uint16_t, QString serial);
    rx_thread();
    void print_port();
    ~rx_thread();

private:
    //Protonet node setup
    uint8_t node_id;
    uint16_t self_port;
    uint16_t dest_port;
    char serial_port[25];
    protonet::node *node;
    QThread *joystick_thread;
    boolean send;
public slots:
    void process();
    void send_ping();

    //Send GPS Data
    void GPS();

    //Changing Networking Settings
    void setNetworkSerial(QString);

signals:
    void finished();
    void error(QString err);
};

//Unused User commands
/*
 *
 *     //Communicates vehicle updating
    void update_vech_queue();

    //Protonet send messages
    void send_vehicle_auth_request(int);
    void send_vehicle_waypoint(int);
    void send_telemetry_command(int);
    void send_targeting(int);
    void send_manTargeting(float,float,float);

    //Veh status
    void vechStat(int,int);

    //UAV drop
    void drop(int);

    //UAV arm/disarm payload
    void arm_uav(int);
    void disarm_uav(int);

*/
#endif // RX_THREAD_H
