#ifndef NETWORKING_H
#define NETWORKING_H

//QT includes
#include <QObject>
#include <QDebug>
#include <QThread>
#include <QListIterator>
#include <thread>

//C lib include
#include <string>
#include <iostream>

//GCS includes
#include "rx_thread.h"
#include "serialscanner.h"
//Testing Include
#include "gpsgen.h"

class networking : public QObject
{
    Q_OBJECT
public:
    networking();
    ~networking();
    void invokeThread(uint8_t node_id, uint16_t self_port, uint16_t dest_port);

public slots:
    void update_vehicle_queue();
    //void update_target_disp(Target*);

    //Update Vehicle with ID
    void updateVech(int);

    //Basic Comnet
    void send_ping();

    //Comnet Setup
    void network_serial_set(QString);

    //General commands
    void send_vehicle_auth_request(int);
    void send_telemetry_command(int);
    void send_targeting(float,float,float);
    //void send_waypoint(Waypoint22*,int);

    //Passes target found from vehicle
    void newTarget(float,float);
    //targeting manual
    void target(float,float,float);

    //vehcile status (UAV)
    void vStatus(int, int);

    //Messages for Console Log
    void messageSlot(QString);
    void messageAlertSlot(QString);
    void messageConfirmSlot(QString);

    //ProtoReciever
    void sendGPS();
    void vechAuthReq();
    void vechTeleReq();

signals:
    void ping();
    void update_queue();
    void network_set_serial(QString);
//    void newTarget(Target*);

    //Update Vehicle at position
    void updateVechicle(int);

    //Emit values for specific commands
//    void waypoint(Waypoint22*, int);
    void vehicle_auth_request(int);
    void telemetry_command(int);
    void targeting(float,float,float);

    //targeting
    void manTargeting(float,float,float);

    //from vech
    void vTarget(float,float);

    //Vehicle states (UAV)
    void vehicleStatus(int,int);

    //Messages for console log
    void message(QString);
    void messageAlert(QString);
    void messageConfirm(QString);

    //ProtoReceiver
    void gpsMSG(int,double,double,double,double,double,double,double);
    void vechAuthRequest();
    void vechTeleRequest();

private:
    rx_thread* rx;
    QThread* network_thread;

    GPSGen *gpsGenny;
    QThread *gpsGen_thread;
};

#endif // NETWORKING_H
