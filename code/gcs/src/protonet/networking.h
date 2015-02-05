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
#include "vehicle_list.h"


class networking : public QObject
{
    Q_OBJECT
public:
    networking(vehicle_list* v, NodeQueue* q, TargetList* targ);
    ~networking();
    void invokeThread(NodeQueue* q, vehicle_list *v, TargetList* tgt, uint8_t node_id, uint16_t self_port, uint16_t dest_port);

public slots:
    void update_vehicle_queue();
    void update_target_disp(Target*);

    //Update Vehicle with ID
    void updateVech(int);

    //Basic Protonet
    void send_ping(int);

    //Protonet Setup
    void network_serial_set(QString);

    //General commands
    void send_vehicle_auth_request(int);
    void send_telemetry_command(int);
    void send_targeting(float,float,float);
    void send_waypoint(int, int, int, float, float, float);

    //Passes target found from vehicle
    void newTarget(float,float);
    //targeting manual
    void target(float,float,float);

    //UAV commands
    //Drop
    void UDrop(int);

    //Arm/disarm
    void arm(int);
    void disarm(int);

    //vehcile status (UAV)
    void vStatus(int, int);

    //UGV commands
    //Joystick
    void start_UGV_Joystick();
    void stop_UGV_Joystick();

    //States
    void ManualToAuto();
    void AutoToManual();
    void Reset();

    //Motor states
    void DisableMotor();
    void EnableMotor();
    void ToggleMotor();

signals:
    void ping(int);
    void update_queue();
    void network_set_serial(QString);
    void newTarget(Target*);

    //Update Vehicle at position
    void updateVechicle(int);

    //Emit values for specific commands
    void waypoint(int, int, int, float, float, float);
    void vehicle_auth_request(int);
    void telemetry_command(int);
    void targeting(float,float,float);

    //targeting
    void manTargeting(float,float,float);

    //from vech
    void vTarget(float,float);
    //UAV drop
    void drop(int);

    //UAV arm/disarm
    void armUAV(int);
    void disarmUAV(int);

    //Vehicle states (UAV)
    void vehicleStatus(int,int);

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

private:
    rx_thread* rx;
    rx_thread* rx2;
    QThread* network_thread;
    QThread* network_send_thread;
};

#endif // NETWORKING_H
