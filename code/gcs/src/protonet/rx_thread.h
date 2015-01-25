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
#include "Vehicle22.h"
#include "nodequeue.h"
#include "joystickinput.h"
#include "targetlist.h"
#include "vehicle_list.h"

class rx_thread : public QObject
{
    Q_OBJECT
public:
    rx_thread(uint8_t, uint16_t, uint16_t, vehicle_list*, NodeQueue*, TargetList*);
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
    JoystickInput *joystick;
    vehicle_list* vList;
    boolean send;

public slots:
    void process();
    void send_ping(int id);

    //Communicates vehicle updating
    void update_vech_queue();

    //Protonet send messages
    void send_vehicle_auth_request(int);
    void send_vehicle_waypoint(int, int, int, float, float, float);
    void send_telemetry_command(int);
    void send_targeting(int, float, float, float);
    void send_manTargeting(double,double,double);
    void target_added(Target*);

    //target recieved
    void target(float,float);

    //Veh status
    void vechStat(int,int);

    //UAV drop
    void drop(int);

    //UAV arm/disarm payload
    void arm_uav(int);
    void disarm_uav(int);

    //UGV Joystick
    void start_UGV_Joystick();
    void stop_UGV_Joystick();

    //UGV state change
    void ManualToAuto();
    void AutoToManual();
    void Reset();

    //UGV MOTOR state
    void DisableMotor();
    void ToggleMotor();
    void EnableMotor();

    //Changing Networking Settings
    void setNetworkSerial(QString);
    void update(int);

signals:
    void finished();
    void error(QString err);
    void update_queue();
    void endUGVJoystick();
    void startUGVJoystick();

    void newTarget(Target*);
    void vechStatus(int,int);
    void sendTarget(float,float);

    //Has value of position of vech
    void updateVech(int);
};

#endif // RX_THREAD_H
