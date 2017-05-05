#include "rx_thread.h"
#include <QDebug>
#include <stdio.h>
#include <stdlib.h>

// CommProto Default Packets.
#include "VehicleGlobalPosition.hpp"
#include "VehicleWaypointCommand.hpp"
#include "VehicleInertialState.hpp"
#include "VehicleAuthorizationRequest.hpp"
#include "VehicleSystemStatus.hpp"
#include "VehicleAuthorizationReply.hpp"
#include "VehicleAttitude.hpp"
#include "TargetDesignationCommand.hpp"
#include "VehicleModeCommand.hpp"

//TargetList* targetList;
//vehicle_list* vp;
QMutex mutex;
comnet::Comms *np;

// ------- CONSTRUCTOR -------
rx_thread::rx_thread(uint8_t node_id, uint16_t self_port, uint16_t dest_port, QString serial){
    // you could copy data from constructor arguments to internal variables here.
    this->node_id = node_id;
    this->self_port = self_port;
    this->dest_port = dest_port;
    qDebug() << "rx_thread constructor serial port is: " << this->serial_port;
    //vp = v;
    //this->vList = v;
    //targetList = tgt;
    //connect(q,SIGNAL(update_queue()),this,SLOT(update_vech_queue()));
    //connect(q,SIGNAL(vechStat(int,int)),this,SLOT(vechStat(int,int)));
    //connect(targetList,SIGNAL(newTarget(Target*)),this,SLOT(target_added(Target*)));
    //connect(q,SIGNAL(target(float,float)),this,SLOT(target(float,float)));
    //Connect for callback for new vehicle list
    //connect(v,SIGNAL(update(int)),this,SLOT(update(int)));
}

void rx_thread::update_vech_queue() { emit update_queue();}

void rx_thread::print_port() {  qDebug() << serial_port; }

void rx_thread::update(int vechID) { emit updateVech(vechID);}
// ------- DECONSTRUCTOR -------
rx_thread::~rx_thread() {
    qDebug() << "Rx Deconstrutor";
    //destroy any pointers!
    //delete node;
}

//------------ User Commands -------------
void rx_thread::send_Ping()
{
    qDebug() << "send ping";
    //Use vehicle type as id
    QDateTime local(QDateTime::currentDateTime());
    QDateTime UTC(local.toUTC());
    double x = UTC.toMSecsSinceEpoch();
    //node->send_ping(1,x);
    //node->send_target_designation_command(1,1,x,69,16,17,0,3109.45,8452.821,28);
}

void rx_thread::send_GPS()
{
    QDateTime local(QDateTime::currentDateTime());
    QDateTime UTC(local.toUTC());
    double x = UTC.toMSecsSinceEpoch();
    double lat = 3109.45;
    double lon = -117.8215;

    // Send State of the vehicle. Default constructor called, which zeroes all values
    // (Should you wish to add data, you can modify the values inside).
    ngcp::VehicleAuthorizationRequest status;
    status.vehicle_type = 100 ;
    status.authorized_services = 200;
    status.granted_services = 300;
    status.vehicle_id = 5;


    // Send the packet.
    node->Send(status, 1);
    qDebug() << "sent GPS";
}

//Vech authorization request
void rx_thread::send_vehicle_auth_request(int vehicle)
{
   //Authorization request link key will be 100 for now
    QDateTime local(QDateTime::currentDateTime());
    QDateTime UTC(local.toUTC());
    double x = UTC.toMSecsSinceEpoch();
    mutex.lock();
    // TODO(): REPLACE WITH NODE->SEND -> From packets.
    //node->send_vehicle_authorization_request(vehicle,x,vehicle,100,1,0);
    qDebug() << "Sent auth request";
    mutex.unlock();
    emit messageConfirm(QString("Sent vehicle authorization request to ID " + QString::number(vehicle)));
}

//Need to send before vehicle will stream info
void rx_thread::send_telemetry_command(int vehicle)
{
    //NOTE: might need to fix telemetry rate.
    // 0 all streams
    // 1 attitude stream
    // 2 position stream
    // 3 heartbeat stream

    QDateTime local(QDateTime::currentDateTime());
    QDateTime UTC(local.toUTC());
    double x = UTC.toMSecsSinceEpoch();

    //node->send_vehicle_telemetry_command(dest_id,vehicle_id,telemetry_select,telemetry_rate);
    mutex.lock();
    //node->send_vehicle_telemetry_command(vehicle,x,vehicle,0,1);
    qDebug() << "Sent telemetry request";
    mutex.unlock();
    emit messageConfirm(QString("  Sent Telemetry Command to ID " + QString::number(vehicle)));
}

//Send targeting informaiton to vehicle
void rx_thread::send_targeting(int vehicle, float lat,float longi,float alt)
{
    //Target id = 1, Payload ID = 1
    QDateTime local(QDateTime::currentDateTime());
    QDateTime UTC(local.toUTC());
    double x = UTC.toMSecsSinceEpoch();
    //node->send_target_designation_command(dest_id,timestamp,vech_ID,payload_id, target_id,target_type,latitude,longitude,altitude);
    //target type?
    /*
    node->send_target_designation_command(vehicle, x,
                                          vehicle, 1, 1, 0,
                                          lat,
                                          longi,
                                          alt);
    */
    //node->send_payload_bay_command(dest_id,timestamp,payload_id,bay_mode);
}

//emit target recieved out to main window
void rx_thread::target(float lat,float longi) { emit sendTarget(lat,longi);}

//Send manual targeting to UAV (static ID)
void rx_thread::send_manTargeting(double latitude, double longitude, double altitude)
{
    qDebug() << "sent manual targeting";
    //Target id = 1, Payload ID = 1
    QDateTime local(QDateTime::currentDateTime());
    QDateTime UTC(local.toUTC());
    double x = UTC.toMSecsSinceEpoch();
    //node->send_target_designation_command(dest_id,timestamp,vech_ID,payload_id, target_id,target_type,latitude,longitude,altitude);
    //target type?
    //printf("lat: %f long: %f alt: %f",latitude,longitude,altitude);

    /*node->send_target_designation_command(69, x,
                                          69, 1, 1, 0,
                                          latitude*1E7,longitude*1E7,altitude);
    */
    //node->send_payload_bay_command(dest_id,timestamp,payload_id,bay_mode);
}

//UAV arm
void rx_thread::arm_uav(int vehicle)
{
    QDateTime local(QDateTime::currentDateTime());
    QDateTime UTC(local.toUTC());
    double x = UTC.toMSecsSinceEpoch();
    //vehicle id, timestamp, payload bay, mode (0 disarm 1 arm)
    qDebug() << "arming";
    //node->send_payload_bay_mode_command(vehicle,x,1,1);
    ngcp::VehicleModeCommand command;
    command.vehicle_id = vehicle;
    command.vehicle_mode = 1;
    node->Send(command, 1);
}

//UAV disarm
void rx_thread::disarm_uav(int vehicle)
{
    QDateTime local(QDateTime::currentDateTime());
    QDateTime UTC(local.toUTC());
    double x = UTC.toMSecsSinceEpoch();
    //vehicle id, timestamp, payload bay, mode (0 disarm 1 arm)

    ngcp::VehicleModeCommand command;
    command.vehicle_id = vehicle;
    command.vehicle_mode = 0;
    node->Send(command, 1);
}

//UAV drop payload
void rx_thread::drop(int vehicle)
{
    qDebug() << "dropping";
    QDateTime local(QDateTime::currentDateTime());
    QDateTime UTC(local.toUTC());
    double x = UTC.toMSecsSinceEpoch();
    if(vehicle == 69)
    {
        //vehicle id, timestamp, payload bay, mode (0 reset 1 drop)
        //node->send_payload_bay_command(vehicle,x,1,1);
        //send to UGV for ack to end of mission
        //node->send_payload_bay_command(46,x,1,1);
    }
    else {
        //node->send_payload_bay_command(46,x,1,1);
    }
}
//Emit vehicle status to be displayed in GUI
void rx_thread::vechStat(int vech, int status){  emit vechStatus(vech, status); }

//Adjusting network settings
//Adjust serial port
void rx_thread::setNetworkSerial(QString serial)
{
    //Translating the QString to a char*
    QByteArray portN = serial.toLocal8Bit();
    char *serialp = portN.data();

    //Set link_id to 0
    int8_t link_id(0);
    mutex.lock();
    //Add serial at link id, baud rate, serial port
    //node->add_serial(&link_id, 9600, serialp);

    //Establish serial
    //node->establish_serial(link_id,1);
    // CommProto nodes can only use one protocol at a time for now.
    mutex.unlock();
    qDebug() << "node serial set is: " << serialp;
}

//Got a new target from vech
//void rx_thread::target_added(Target* tgt) { emit newTarget(tgt); }

//Change UGV states
//0x12 from manual to autonomous control
//0x10 from auto to manual control
//0x00 reset state
void rx_thread::ManualToAuto()
{
    QDateTime local(QDateTime::currentDateTime());
    QDateTime UTC(local.toUTC());
    double x = UTC.toMSecsSinceEpoch();

}

void rx_thread::AutoToManual()
{
    QDateTime local(QDateTime::currentDateTime());
    QDateTime UTC(local.toUTC());
    double x = UTC.toMSecsSinceEpoch();

}

//Function motor commands
//enabler kill motor
//f0 enable
//ff disable
//f7 toggle
void rx_thread::DisableMotor()
{
    QDateTime local(QDateTime::currentDateTime());
    QDateTime UTC(local.toUTC());
    double x = UTC.toMSecsSinceEpoch();

    ngcp::VehicleModeCommand command;
    command.vehicle_id = 46;
    command.vehicle_mode = 0xff;
    node->Send(command, 1);
}

void rx_thread::ToggleMotor()
{
    QDateTime local(QDateTime::currentDateTime());
    QDateTime UTC(local.toUTC());
    double x = UTC.toMSecsSinceEpoch();

    ngcp::VehicleModeCommand command;
    command.vehicle_id = 46;
    command.vehicle_mode = 0xf7;
    node->Send(command, 1);
}

void rx_thread::EnableMotor()
{
    QDateTime local(QDateTime::currentDateTime());
    QDateTime UTC(local.toUTC());
    double x = UTC.toMSecsSinceEpoch();

    ngcp::VehicleModeCommand command;
    command.vehicle_id = 46;
    command.vehicle_mode = 0xf0;    
    node->Send(command, 1);
}

/** Test to see if need to wait after sending message
 * @brief hold
 */
void rx_thread::hold()
{
    for(int i = 0; i < 50; i++);
}

// --------- COMNET CALLBACKS ---------
/*
void* ping(int8_t link_id, com_header_t header,ping_t ping, comnet::node* node)
{
   printf("got ping");
   qDebug() << "got ping" << endl;
   //qDebug() << "Ping timestamp:" << ping.timestamp << endl;
   //qDebug() << "Sending pong response." << endl;
   //send a pong as a reply
   node->send_pong(header.node_src_id,0);
   return 0;
}

void* pong(int8_t link_id, com_header_t header,pong_t pong, comnet::node* node)
{
   printf("got pong");
   node_ptr->send_ping(header.node_src_id,0);
   return 0;
}
*/
/*
void* target_designation_command_callback(int8_t, com_header_t, target_designation_command_t target, comnet::node* node_ptr)
{
    //Add target to the target list
    //targetList->addTarget(&Target(((float)target.latitude)/1E7,
      //                        ((float)target.longitude)/1E7,
        //                      target.altitude,
          //                    target.payload_ID,target.target_ID,target.target_type));

    //Send recieved target command to uav
    QDateTime local(QDateTime::currentDateTime());
    QDateTime UTC(local.toUTC());
    double x = UTC.toMSecsSinceEpoch();
    qDebug() << "latitude" << ((float)target.latitude)/1E7;
    qDebug() << "longitude" << ((float)target.longitude)/1E7;
    np->send_target_designation_command(69,x,69,1,1,0,
                                          ((float)target.latitude)/1E7,
                                          ((float)target.longitude)/1E7,
                                          target.altitude);
    //???
    //nq->targetRec(((float)target.latitude)/1E7,
                  //((float)target.longitude)/1E7);
    return 0;
}

void* vehicle_waypoint_command(int8_t link_id, com_header_t header,vehicle_waypoint_command_t vehicle_waypoint_command, comnet::node* node)
{
    if(way.waypoint_type == 1)
     {
        float32_t latitude = (float)way.latitude/1E7;
        float32_t longitude = (float)way.longitude/1E7;
        float32_t altitude = (float)way.altitude/1E7;
   }
    printf("!waypoint!");
        return 0;
}
*/
// ----------- PROCESS -----------
// Start processing data.
//dynamic alloc
void rx_thread::process() {

    //Create comnet Node
   node = new comnet::Comms(node_id);

   //Have the methods outside of class (i.e. callbacks) be able to have access to node
   np = node;

   //Set link_id to 1
   int8_t link_id(1);

   //Add udp at link id, self port, self ip
   //NOTE: ip is self IP for testing purposes
   qDebug() << "Self port for GCS: " << self_port;
   char  ip[] = "127.0.0.1";
   char port_str[4];
   sprintf(port_str, "%d", self_port);
   node->InitConnection(transport_protocol_t::UDP_LINK, port_str, ip);
   qDebug() << "Dest port for GCS: " << dest_port;
   //Add endpoint for udp using link id, dest_id, destinition port, destinition address
   //NOTE: ip is self IP for testing purposes
   //Dest id is for the node id that we want to send to
   //To have ComnetTester test itself, set to self_port
      node->AddAddress(link_id, ip, dest_port);

   // This will initialize packets at runtime, which won't be a hassle to have things set up before hand.
   // Removes all of the rigid structures of comnet v1.
   // Looks complicated, but you don't have to LinkCallback lambda expressions! You can do it the old fashioned
   // way...
//   node->LinkCallback(new ngcp::VehicleModeCommand(), new comnet::Callback(
//                      [] (const comnet::Header &header, comnet::ABSPacket &packet, comnet::CommNode &node) -> error_t {
//     ngcp::VehicleModeCommand &command = comnet::ABSPacket::GetValue<ngcp::VehicleModeCommand>(packet);
//     qDebug() << "Received Vehicle Mode command";
//     return comnet::CALLBACK_SUCCESS | comnet::CALLBACK_DESTROY_PACKET;
//   }));
//   node->LinkCallback(new ngcp::VehicleInertialState(), new comnet::Callback(
//                      [] (const comnet::Header &header, comnet::ABSPacket &packet, comnet::CommNode &node) -> error_t {
//     ngcp::VehicleInertialState &state = comnet::ABSPacket::GetValue<ngcp::VehicleInertialState>(packet);
//     qDebug() << "Received GPS coords!";
//     return comnet::CALLBACK_SUCCESS | comnet::CALLBACK_DESTROY_PACKET;
//   }));

   node->Run();

}
