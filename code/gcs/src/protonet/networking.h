#ifndef NETWORKING_H
#define NETWORKING_H

//QT includes
#include <QObject>
#include <QDebug>
#include <QThread>
#include <QListIterator>

//C lib include
#include <string>
#include <iostream>

//GCS includes
#include "rx_thread.h"
#include "Vehicle22.h"
#include "serialscanner.h"
#include "nodequeue.h"
#include "targetlist.h"

class networking : public QObject
{
    Q_OBJECT
public:
    networking(QVector<Vehicle22*>* v, NodeQueue* q, TargetList* targ);
    ~networking();
    void invokeThread(NodeQueue* q,QVector<Vehicle22*>* v, TargetList* tgt, uint8_t node_id, uint16_t self_port, uint16_t dest_port);

public slots:
    void send_ping();
    void update_vehicle_queue();
    void network_serial_set(QString);
    void update_target_disp(Target*);

    //Test GUI
    void send_waypoint(int);
    void send_vehicle_auth_request(int);
    void send_telemetry_command(int);
    void send_targeting(int);
    void start_UGV_Joystick();
    void stop_UGV_Joystick();

    void newTarget(float,float);

    //UAV drop
    void UDrop(int);

    //UAV arm/disarm
    void arm(int);
    void disarm(int);

    //UGV states
    void ManualToAuto();
    void AutoToManual();
    void Reset();

    //UGV Motor states
    void DisableMotor();
    void EnableMotor();
    void ToggleMotor();

    //vehcile status
    void vStatus(int, int);

    //targeting
    void target(float,float,float);

signals:
    void ping();
    void update_queue();
    void network_set_serial(QString);

    void newTarget(Target*);

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

    //UGV Joystick
    void UGV_joystick_stop();
    void UGV_joystick_start();

    //UGV states
    void ATM(); //auto to manual
    void MTA(); //manaul to auto
    void R(); //reset
    void DisableM(); //disable motor
    void ToggleM(); //toggle motor
    void EnableM(); //enable motor

    //Vehicle states
    void vehicleStatus(int,int);

private:
    rx_thread* rx;
    rx_thread* rx2;
    QThread* network_thread;
    QThread* network_send_thread;
};

#endif // NETWORKING_H
