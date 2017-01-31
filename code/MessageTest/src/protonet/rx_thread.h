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
#include "comnet.h"
#include "joystickinput.h"

class rx_thread : public QObject
{
    Q_OBJECT
public:
    rx_thread(uint8_t, uint16_t, uint16_t);
    rx_thread();
    void print_port();
    ~rx_thread();
    void telemetryRequest();
    void authorizationRequest();

private:
    //Comnet node setup
    uint8_t node_id;
    uint16_t self_port;
    uint16_t dest_port;
    char serial_port[25];
    comnet::node *node;
    //Thread and object for joystick control
//    QThread *joystick_thread;
//    JoystickInput *joystick;
    boolean send;

    void hold();
public slots:
    void process();
    void send_ping();

    //Communicates vehicle updating
    void update_vech_queue();

    //Comnet send messages
    void send_vehicle_auth_request(int);
    void send_telemetry_command(int);
    void send_targeting(int, float, float, float);

    //target recieved
    void target(float,float);

    //Veh status
    void vechStat(int,int);

    //Changing Networking Settings
    void setNetworkSerial(QString);
    void update(int);

    //ProtoReciever
    void send_global_position(int,double,double,double,double,double,double,double);

signals:
    void finished();
    void error(QString err);
    void update_queue();
    void endUGVJoystick();
    void startUGVJoystick();

    void vechStatus(int,int);
    void sendTarget(float,float);

    //Has value of ID of vech
    void updateVech(int);

    void message(QString);
    void messageAlert(QString);
    void messageConfirm(QString);

    //GCS request
    void telemetryReq();
    void authorizeReq();

private:
    float64_t getTime();
};

#endif // RX_THREAD_H
