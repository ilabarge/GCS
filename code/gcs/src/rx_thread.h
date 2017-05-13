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

//Connect to websharper
#include <QJsonObject>
#include <QJsonDocument>
#include <QTcpSocket>

//C lib includes
#include <cstring>
#include <chrono>
#include <iostream>
#include <string>

//GCS Includes
// New CommProto library.
// Qt is a troll...
#undef interface
#include <CommProto/commproto.h>
#include "Vehicle22.h"
#include "nodequeue.h"
#include "joystickinput.h"
#include "targetlist.h"
#include "vehicle_list.h"

class rx_thread : public QObject
{
    Q_OBJECT
public:
    rx_thread(uint8_t, uint16_t, uint16_t, vehicle_list*, TargetList*);
    rx_thread();
    void print_port();
    ~rx_thread();

private:
    //Comnet node setup
    uint8_t node_id;
    uint16_t self_port;
    uint16_t dest_port;
    char serial_port[25];
    comnet::Comms *node;
    QThread *joystick_thread;
    //JoystickInput *joystick;
    vehicle_list* vList;
    bool send;
    void hold();
public slots:
    void process();

    /* @TODO not being used in CommPorotocol
    void send_ping(int id);
    */

    //Communicates vehicle updating
    void update_vech_queue();

    //Comnet send messages
    /* @TODO swithc to CommProtocol
    void send_vehicle_auth_request(int);
    */
    void send_vehicle_waypoint(Waypoint22*,int);
    void send_telemetry_command(int);
    void send_targeting(int, float, float);
    void send_manTargeting(double,double);
    void target_added(Target *);

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
    /* @TODO swithc to CommProtocol
    void start_UGV_Joystick();
    void stop_UGV_Joystick();
    */

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

    void updateTarget(int);
    void updateTargetDisplay(int);

    //Send message with int vehicle id to airweb
    void sendMessage(int);

    //send messages to console
<<<<<<< HEAD
    void sendMessageToConsole(QString s);
=======
    void sendMessageToConsole(QString);
>>>>>>> 9ac2ec5159a1eabb6abc734f65e13976e0ef54ed

signals:
    void finished();
    void error(QString err);
    void update_queue();
    void endUGVJoystick();
    void startUGVJoystick();

    void newTarget(Target*);
    void vechStatus(int,int);
    void sendTarget(float,float);

    //Has value of ID of vech
    void updateVech(int);

    void updateTarg(int);
    void updateTargDisplay(int);

    void message(QString);
    void messageAlert(QString);
    void messageConfirm(QString);


};

// Why would Qt Do this??
#define interface __STRUCT__
#endif // RX_THREAD_H
