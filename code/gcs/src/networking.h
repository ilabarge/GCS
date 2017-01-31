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
    networking(vehicle_list* v, TargetList* targ);
    ~networking();
    void invokeThread(vehicle_list *v, TargetList* tgt, uint8_t node_id, uint16_t self_port, uint16_t dest_port);

public slots:
    void update_vehicle_queue();
    void update_target_disp(Target*);

    //Update Vehicle with ID
    void updateVech(int);

    //Update Target with ID
    void updateTarg(int);
    void updateTargDisplay(int);

    //Basic Comnet
    void send_ping(int);

    //Comnet Setup
    void network_serial_set(QString);

    //General commands
    void send_vehicle_auth_request(int);
    void send_telemetry_command(int);
    void send_targeting(float,float,float);
    void send_waypoint(Waypoint22*,int);

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

    //Messages for Console Log
    void messageSlot(QString);
    void messageAlertSlot(QString);
    void messageConfirmSlot(QString);

signals:
    void ping(int);
    void update_queue();
    void network_set_serial(QString);
    void newTarget(Target*);

    //Update Vehicle at position
    void updateVechicle(int);
    //Update Target
    void updateTarget(int);
    void updateTargetDisplay(int);

    //Emit values for specific commands
    void waypoint(Waypoint22*, int);
    void vehicle_auth_request(int);
    void telemetry_command(int);
    void targeting(float,float,float);

    //targeting
    void manTargeting(double,double,double);

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

    //Messages for console log
    void message(QString);
    void messageAlert(QString);
    void messageConfirm(QString);

private:
    rx_thread* rx;
    QThread* network_thread;
};

#endif // NETWORKING_H
