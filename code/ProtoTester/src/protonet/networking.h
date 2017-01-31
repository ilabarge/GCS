#ifndef NETWORKING_H
#define NETWORKING_H
#include <QObject>
#include <QDebug>
#include <QThread>
#include <iostream>
#include "rx_thread.h"

class networking : public QObject
{
    Q_OBJECT
public:
    networking();
    ~networking();
    void invokeThread(uint8_t node_id, uint16_t self_port, uint16_t dest_port, uint16_t serial_port);
    void invokeThread(uint8_t node_id, uint16_t self_port, uint16_t dest_port);
    QString serialSelection();


public slots:
    void send_ping();
    void network_serial_set(QString);
    void send_GPS();


signals:
    void ping();
    void network_set_serial(QString);

    void sendGPS();
    //TEST GUI
    void waypoint(int);
    void vehicle_auth_request(int);
    void telemetry_command(int);
    void targeting(int);

    //targeting
    void manTargeting(float,float,float);

    //from vech
    void vTarget(float,float);
    //UAV drop
    void drop(int);

    //UAV arm/disarm
    void armUAV(int);
    void disarmUAV(int);


    //Vehicle states
    void vehicleStatus(int,int);


private:
    rx_thread* rx;
    QThread* network_thread;

};

//Unused user commands
/*
 *
    //Test GUI
    void send_waypoint(int);
    void send_vehicle_auth_request(int);
    void send_telemetry_command(int);
    void send_targeting(int);
    void newTarget(float,float);

    //UAV drop
    void UDrop(int);

    //UAV arm/disarm
    void arm(int);
    void disarm(int);

    //vehcile status
    void vStatus(int, int);

    //targeting
    void target(float,float,float);
*/
#endif // NETWORKING_H
