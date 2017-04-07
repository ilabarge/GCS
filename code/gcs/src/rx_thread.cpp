/*
 *
 * TODO(): Legacy Comnet code was commented out, Look for them and replace with CommProtocol v2
 *         Signatures and handles. (callbacks). An example is provided below in the process() function call
 *         of this thread object on how to register your callbacks.
 *
 */
#include "rx_thread.h"
#include "qdebug.h"

// CommProto Default Packets.
#include <Packets.hpp>


using namespace ngcp;
// These don't do anything, only make it easier to read.
#define CALLBACK_REGISTER_BLOCK
#define END_CALLBACK_REGISTER_BLOCK

// set 0 to disable XBEE, 1 to switch to xbee connections. This is for debugging!!
#define XBEE 0

TargetList* targetList;
vehicle_list* vp;
QMutex mutex;
comnet::Comms *np;


// ------- CONSTRUCTOR -------
rx_thread::rx_thread(uint8_t node_id, uint16_t self_port, uint16_t dest_port, vehicle_list* v, TargetList* tgt){

    // you could copy data from constructor arguments to internal variables here.
    this->node_id = node_id;
    this->self_port = self_port;
    this->dest_port = dest_port;
    qDebug() << "rx_thread constructor serial port is: " << this->serial_port;
    vp = v;
    this->vList = v;
    targetList = tgt;
    //connect(q,SIGNAL(update_queue()),this,SLOT(update_vech_queue()));
    //connect(q,SIGNAL(vechStat(int,int)),this,SLOT(vechStat(int,int)));
    connect(targetList,SIGNAL(newTarget(Target*)),this,SLOT(target_added(Target*)));
    //connect(q,SIGNAL(target(float,float)),this,SLOT(target(float,float)));
    //Connect for callback for new vehicle list
    connect(v,SIGNAL(update(int)),this,SLOT(update(int)));
    connect(tgt,SIGNAL(update(int)),this,SLOT(updateTarget(int)));
    connect(tgt,SIGNAL(updateDisplay(int)),this,SLOT(updateTargetDisplay(int)));
    connect(v,SIGNAL(update(int)),this,SLOT(sendMessage(int)));
}

void rx_thread::update_vech_queue() { emit update_queue();}

void rx_thread::print_port() {  qDebug() << serial_port; }

void rx_thread::update(int vechID) { emit updateVech(vechID);}

void rx_thread::updateTarget(int targID) { emit updateTarg(targID);}

void rx_thread::updateTargetDisplay(int targID) { emit updateTargDisplay(targID);}
// ------- DECONSTRUCTOR -------
rx_thread::~rx_thread() {
    qDebug() << "Rx Deconstrutor";
    //destroy any pointers!
    //delete node;
}

//------------ User Commands -------------
void rx_thread::send_ping(int id)
{
    //for testing
    //qDebug() << "send ping";
    //Use vehicle type as id
    QDateTime local(QDateTime::currentDateTime());
    QDateTime UTC(local.toUTC());
    float64_t x = UTC.toMSecsSinceEpoch();
    //node->send_ping(id,x);
    // TODO(): Will need to supply a ping command for yourselves.
}

//Vech authorization request
void rx_thread::send_vehicle_auth_request(int vehicle)
{
   //Authorization request link key will be 100 for now
    QDateTime local(QDateTime::currentDateTime());
    QDateTime UTC(local.toUTC());
    float64_t x = UTC.toMSecsSinceEpoch();
    mutex.lock();
    //node->send_vehicle_authorization_request(vehicle,x,vehicle,100,1,0);
    ngcp::VehicleAuthorizationRequest request;
    request.vehicle_id = vehicle;
    request.authorized_services = 0;
    request.granted_services = 0;
    request.vehicle_type = 0;
    // Assuming our vehicle number is also the dest_id.
    node->Send(request, vehicle);
    qDebug() << "Sent auth request";
    mutex.unlock();
    emit messageConfirm(QString("Sent vehicle authorization request to ID " + QString::number(vehicle)));
}

//Vehicle waypoint
void rx_thread::send_vehicle_waypoint(Waypoint22 *waypoint, int id)
{
    QDateTime local(QDateTime::currentDateTime());
    QDateTime UTC(local.toUTC());
    float64_t x = UTC.toMSecsSinceEpoch();
     int vehicle = id;
   qDebug() << "vehicle ID " << id;
   qDebug() << "waypoint type" << waypoint->getType();
   if(vList->get(id) != 0){

       qDebug() << "at vehicle: " <<  vList->get(id)->getVehicleID();
       if(vList->get(id)->getVehicleID() == vehicle)
       {
           int size = vList->get(id)->waypoints.size();
           int type = waypoint->getType();
           qDebug() << "dest size: " << size;
           qDebug() << "Waypoint id: " << waypoint->getID();
           if((type == 0) && ((waypoint->getID() - 1) == (size)))
           {
               mutex.lock();
               vList->get(id)->appendWaypoint(waypoint, vList->get(id)->getColor() );

               VehicleWaypointCommand command;
               command.longitude = waypoint->getLongitude(); // no need to cast to int (retains precision)
               command.latitude = waypoint->getLatitude();
               command.altitude = waypoint->getAltitude();

//                qDebug() << "Longitude = " << waypoint->getLongitude();
//                qDebug() << "Latitude = " << waypoint->getLatitude();
//                qDebug() << "Altitude = " << waypoint->getAltitude();

//               command.vehicle_id = vehicle;
               // vehicle_id is not the same as dest_id
               // setting as 3 for now
               command.vehicle_id = 3;
               node->Send(command, 3);

               mutex.unlock();
               emit message(QString("Added waypoint"));
               emit messageConfirm(QString("  Sent Waypoint to ID " + QString::number(vehicle)));
           }
           else if((type == 0) && ((waypoint->getID()) > (size)))
           {
               emit messageAlert(QString("added t past end of list!!"));

           }
          //this condition must be true for editing and removing t to
          //work
          if((waypoint->getID()) <= size)
          {
              //qDebug() << "type" << type;
              if(type == 1)
              {
                  //qDebug() << "edited t";
                 if(waypoint->getID() == size)
                 {
                     mutex.lock();
                     vList->get(id)->removeWaypoint(waypoint->getID() -1);
                     vList->get(id)->appendWaypoint(waypoint, Qt::green );
                     mutex.unlock();
                     emit message(QString("Edited waypoint at first position"));

                 }
                 else
                 {
                     mutex.lock();
                     vList->get(id)->removeWaypoint(waypoint->getID() -1);
                     vList->get(id)->insertWaypoint(waypoint->getID() - 1, waypoint, Qt::green );
                     mutex.unlock();
                     emit message(QString("Edited waypoint"));

                 }

              }

              else if(type == 2)
              {
                  //qDebug() << "removed t";
                  mutex.lock();
                  vList->get(id)->removeWaypoint(waypoint->getID() - 1);
                  mutex.unlock();
                  emit message(QString("Removed Waypoint"));

              }

              if((type == 1) || (type == 2))
              {
                  mutex.lock();
                  VehicleWaypointCommand command;
                  command.longitude = waypoint->getLongitude(); // no need to cast to int (this retains precision)
                  command.latitude = waypoint->getLatitude();
                  command.altitude = waypoint->getAltitude();
//                  command.vehicle_id = vehicle;
                  // vehicle_id is not the same as dest_id
                  // setting as 3 for now
                  command.vehicle_id = 3;
                  node->Send(command, 3);


                  mutex.unlock();
                  emit messageConfirm(QString("  Sent Waypoint to ID " + QString::number(vehicle)));

              }
          }
        //qDebug() << "Dest size after Waypoint command" << vList->at(i)->waypoints.size();
       }
   }
   qDebug() << "Vehicle not found";
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
    float64_t x = UTC.toMSecsSinceEpoch();

    //node->send_vehicle_telemetry_command(dest_id,vehicle_id,telemetry_select,telemetry_rate);
    mutex.lock();
    //node->send_vehicle_telemetry_command(vehicle, x, vehicle, 0, 1);
    qDebug() << "Sent telemetry request";
    mutex.unlock();
    emit messageConfirm(QString("  Sent Telemetry Command to ID " + QString::number(vehicle)));
}

//Send targeting informaiton to vehicle
void rx_thread::send_targeting(int vehicle, float lat,float longi,float alt)
{
    qDebug() << "received target";
    //Target id = 1, Payload ID = 1
    QDateTime local(QDateTime::currentDateTime());
    QDateTime UTC(local.toUTC());
    float64_t x = UTC.toMSecsSinceEpoch();
    //node->send_target_designation_command(dest_id,timestamp,vech_ID,payload_id, target_id,target_type,latitude,longitude,altitude);
    //target type?
    //node->send_target_designation_command(vehicle, vehicle, x,
    //                                      vehicle, 1, 1, 0,
    //                                      lat,
    //                                      longi,
    //                                      alt);
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
    float64_t x = UTC.toMSecsSinceEpoch();
    //node->send_target_designation_command(dest_id,timestamp,vech_ID,payload_id, target_id,target_type,latitude,longitude,altitude);
    //target type?
    //printf("lat: %f long: %f alt: %f",latitude,longitude,altitude);

    //node->send_target_designation_command(69, 69, x,
     //                                     69, 1, 1, 0,
     //                                     latitude*1E7,longitude*1E7,altitude);
//node->send_payload_bay_command(dest_id,timestamp,payload_id,bay_mode);
}

//UAV arm
void rx_thread::arm_uav(int vehicle)
{
    QDateTime local(QDateTime::currentDateTime());
    QDateTime UTC(local.toUTC());
    float64_t x = UTC.toMSecsSinceEpoch();
    //vehicle id, timestamp, payload bay, mode (0 disarm 1 arm)
    qDebug() << "arming";
    //node->send_payload_bay_mode_command(vehicle,x,1,1);
}

//UAV disarm
void rx_thread::disarm_uav(int vehicle)
{
    QDateTime local(QDateTime::currentDateTime());
    QDateTime UTC(local.toUTC());
    float64_t x = UTC.toMSecsSinceEpoch();
    //vehicle id, timestamp, payload bay, mode (0 disarm 1 arm)
    //node->send_payload_bay_mode_command(vehicle,x,1,0);
}

//UAV drop payload
void rx_thread::drop(int vehicle)
{
    qDebug() << "dropping";
    QDateTime local(QDateTime::currentDateTime());
    QDateTime UTC(local.toUTC());
    float64_t x = UTC.toMSecsSinceEpoch();
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

//Start Joystick commands
void rx_thread::start_UGV_Joystick()
{
    joystick->send = true;
    emit startUGVJoystick();
    emit messageConfirm(QString("Begin UGV joystick control"));
}

//Stop Joystick commands
void rx_thread::stop_UGV_Joystick()
{
    joystick->send = false;
    emit endUGVJoystick();
    emit messageConfirm(QString("End UGV joystick control"));
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
    int8_t link_id(1);
    mutex.lock();
    //Add serial at link id, baud rate, serial port
    //node->add_serial(&link_id, 9600, serialp);

    //Establish serial
    //node->establish_serial(link_id,1);
    mutex.unlock();
    qDebug() << "node serial set is: " << serialp;
}

//Got a new target from vech
void rx_thread::target_added(Target* tgt) { emit newTarget(tgt); }

//Change UGV states
//0x12 from manual to autonomous control
//0x10 from auto to manual control
//0x00 reset state
void rx_thread::ManualToAuto()
{
    QDateTime local(QDateTime::currentDateTime());
    QDateTime UTC(local.toUTC());
    float64_t x = UTC.toMSecsSinceEpoch();
    //node->send_vehicle_mode_command(46,x,46,0x12);
}

void rx_thread::AutoToManual()
{
    QDateTime local(QDateTime::currentDateTime());
    QDateTime UTC(local.toUTC());
    float64_t x = UTC.toMSecsSinceEpoch();
    //node->send_vehicle_mode_command(46,x,46,0x10);
}

void rx_thread::Reset()
{
    QDateTime local(QDateTime::currentDateTime());
    QDateTime UTC(local.toUTC());
    float64_t x = UTC.toMSecsSinceEpoch();
    //node->send_vehicle_mode_command(46,x,46,0x00);
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
    float64_t x = UTC.toMSecsSinceEpoch();
    //node->send_vehicle_mode_command(46,x,46,0xFF);
}

void rx_thread::ToggleMotor()
{
    QDateTime local(QDateTime::currentDateTime());
    QDateTime UTC(local.toUTC());
    float64_t x = UTC.toMSecsSinceEpoch();
    //node->send_vehicle_mode_command(46,x,46,0xF7);
}

void rx_thread::EnableMotor()
{
    QDateTime local(QDateTime::currentDateTime());
    QDateTime UTC(local.toUTC());
    float64_t x = UTC.toMSecsSinceEpoch();
    //node->send_vehicle_mode_command(46,x,46,0xF0);
}

/** Test to see if need to wait after sending message
 * @brief hold
 */
void rx_thread::hold()
{
    for(int i = 0; i < 50; i++);
}

void rx_thread::sendMessage(int ID){
    //qDebug() << "Sending UDP message";
//    QJsonObject obj;
//    obj.insert("vehicleID", ID);
//    obj.insert("alt", vp->get(ID)->getAltitude());
//    obj.insert("mode", vp->get(ID)->getMode());
//    obj.insert("state", vp->get(ID)->getState());
//    obj.insert("latitude", vp->get(ID)->getLongitude());
//    obj.insert("longitude", vp->get(ID)->getLongitude());
//    obj.insert("heading", vp->get(ID)->getLongitude());
//    QJsonDocument doc(obj);
//    QTcpSocket * _pSocket;
//    QByteArray data = doc.toJson(); // <-- fill with data
//    _pSocket = new QTcpSocket(); // <-- needs to be a member variable: QTcpSocket * _pSocket;
//    connect( _pSocket, SIGNAL(readyRead()), SLOT(readTcpData()) );

//    _pSocket->connectToHost("127.0.0.1", 9000);
//    if( _pSocket->waitForConnected() ) {
//        _pSocket->write( data );
//    }
}

// -------- CHECKING VEHICLE --------
int checkVehicles(uint32_t vehicle_ID)
{
    for(int i = 1; i < vp->length(); i++){
        if(vp->at(i)->getVehicleID()== vehicle_ID){
            return i;
        }
    }

    return -1;
}

// --------- COMNET CALLBACKS ---------

//Clean up code!!
void* enter_callback(int8_t id, com_header_t header, enter_t enter, comnet::node* node)
{
    printf("got enter");
    qDebug() << "got enter";
    //upon enter message add vehicle to vector if it doesn't exist already
    //Send reply
    if(checkVehicles(header.node_src_id) == -1){
        Vehicle22* v = new Vehicle22();
        v->setVehicleID(header.node_src_id);
        vp->append(v);
    }
//    QDateTime local(QDateTime::currentDateTime());
//    QDateTime UTC(local.toUTC());
//    float64_t x = UTC.toMSecsSinceEpoch();
    //IMPORTANT:send vehicle authorization request on user input
    //emmit Authorization_Request();
    //Request is as follows, vech id, timestamp, our id, link key (100 for now),
    //request services (1 for we want services 0 for we do not want),
    //handover node (default is 0 only change if we want to give control to someone else node#)
    //np->send_vehicle_authorization_request(header.node_src_id,x,header.node_src_id,200,1,0);
    return 0;
}

void* ping_callback(int8_t id, com_header_t header, ping_t ping, comnet::node* node)
{
   printf("got ping");
   qDebug() << "got ping";
   //qDebug() << "Ping timestamp:" << ping.timestamp << endl;
   //qDebug() << "Sending pong response." << endl;
   //send a pong as a reply
   //node->send_pong(header.node_src_id,0);
   return 0;
}

void* pong_callback(int8_t, com_header_t header, pong_t pong, comnet::node* node_ptr)
{
   printf("got pong");
   qDebug() << "got pong";
   //node_ptr->send_ping(header.node_src_id,0);
   return 0;
}

void* vehicle_authorization_request_callback(int8_t id, com_header_t header, vehicle_authorization_request_t vehicle, comnet::node* node_ptr)
{
   printf("Got Vehicle Authorization Request");
   //node_ptr->send_vehicle_authorization_reply(header.node_src_id,99,vehicle.vehicle_ID,99 ,vehicle.request_services,99);
   return 0;
}

//Runs after we send a request to a vehicle
void* vehicle_authorization_reply_callback(int8_t id, com_header_t header, vehicle_authorization_reply_t vehicle, comnet::node* node_ptr)
{
   printf("Got Vehicle Authorization Reply");
   int ID = header.node_src_id;
   //Is the vehicle id in list?
   if(!(vp->inList(ID))){
       qDebug() << "bad id " << ID;
       return 0; //Bad ID
   }
   //Begin setting reply information
   //Add behavior to results recieved?
   //qDebug() << vehicle.authorized_services;
   //qDebug() << vehicle.granted_services;
   mutex.lock();
   //Settting Varibles
   //NOTE: Add to vechicle object?
   //Behavior in case the GCS is not authorized?
   //v->at(i)->setAuthorizedServices(vehicle.authorization_services);
   //v->at(i)->setGrantedServices(vehicle.granted_services);
   //Sets vehicle update value to true
   mutex.unlock();
   //Debug
   /*   qDebug() << vehicle.authorization_services;  sbmitted right key
        qDebug() << vehicle.granted_services;      granted service*/
   return 0;
}

//Gives system status
void* vehicle_system_status_callback(int8_t, com_header_t header, vehicle_system_status_t status, comnet::node* node_ptr)
{
    printf("=============\nsystem status\n");
    int ID = header.node_src_id;
    //Is the vehicle id in list?
    if(!(vp->inList(ID))){
        qDebug() << "bad id " << ID;
        return 0; //Bad ID
    }
    printf("state: %d  mode: %d\n",status.vehicle_state,status.vehicle_mode);
    printf("=============\n");
    mutex.lock();
    //Check vehicle

    //mode
    //no mode/boot 0
    //manual mode 1
    //assisted mode 2
    //auto mode 3
    //collision avoid 4
    //seek & destroy 5

    //state
    //0 power up
    //1 ready
    //2 fault

    //Setting variables
    //(vp + vehicleIndex)->setVehicleID(status.vehicle_ID);
    vp->set(ID)->setState(status.vehicle_state);
    vp->set(ID)->setMode(status.vehicle_mode);
    //Sets vehicle update value to true
    mutex.unlock();
//    obj.insert("xAccel", v->getLongitude());
//    obj.insert("yAccel", v->getLongitude());
//    obj.insert("rollRate", v->getLongitude());
//    obj.insert("pitchRate", v->getLongitude());
//    obj.insert("yawrate", v->getLongitude());
//    obj.insert("velocity", v->getLongitude());
//    obj.insert("roll", );
//    obj.insert("pitch", );
//    obj.insert("yaw", );
    vp->update(header.node_src_id);
    //nq->enqueue(header.node_src_id);
    if(header.node_src_id == 69)
    {
        //nq->status(header.node_src_id,status.vehicle_mode);
    }
    //Debug
    /*
    qDebug() << "Timestamp: " << status.timestamp;
    qDebug() << "ID: " << status.vehicle_ID;
    qDebug() << "Mode: " << status.vehicle_mode;
    qDebug() << "State: "<<status.vehicle_state;
    */
    return 0;
}

//void* vehicle_inertial_state_callback(int8_t id, com_header_t header, vehicle_inertial_state_t inertial, comnet::node* node_ptr)
error_t VehicleInertialStateCallback(
const comnet::Header &header, VehicleInertialState &packet, comnet::Comms &node)
{
    //int ID = header.source_id;
    int ID = packet.vehicle_id;

    //Is the vehicle id in list?
    if(!(vp->inList(ID))){
        qDebug() << "bad id " << ID;
        return 0; //Bad ID
    }
    printf("==========\ninternal State\n");
    printf("longitude: %f\n",((float)packet.longitude)/1E7);
    printf("longitude: %f\n", ((float)packet.latitude)/1E7);
    printf("===============");
    mutex.lock();
    /*
     * Unused
    inertial.east_accel();
    inertial.east_speed();
    inertial.north_accel();
    inertial.north_speed();
    */
    packet.vertical_accel; //Missing?
    packet.vertical_speed; //Missing?
    vp->set(ID)->setRoll(packet.roll);
    //std::string s = std::to_string(inertial.roll_rate);
    vp->set(ID)->setRollRate(packet.roll_rate);
    vp->set(ID)->setHeading(packet.heading);
    vp->set(ID)->setAltitude(packet.altitude);
    vp->set(ID)->setLatitude(((float)packet.latitude));
    vp->set(ID)->setLongitude(((float)packet.longitude)/1E6);
    vp->set(ID)->setPitch(packet.pitch);
    vp->set(ID)->setPitchRate(packet.pitch_rate);
    mutex.unlock();
    vp->update(ID);
//    /nq->enqueue(header.node_src_id);
    //return 0;
    return comnet::CALLBACK_SUCCESS | comnet::CALLBACK_DESTROY_PACKET;
}

void* vehicle_global_position_callback(int8_t id, com_header_t header, vehicle_global_position_t position, comnet::node* node_ptr)
{
    qDebug() << "globalpos" << header.node_src_id;
    int ID = header.node_src_id;
    //Is the vehicle id in list?
    if(!(vp->inList(ID))){
        qDebug() << "bad id " << ID;
        return 0; //Bad ID
    }
    //Debug prints
    printf("==============\nGlobal position\n");
    printf("longitude: %f\n",((float)position.longitude)/1E7);  //137
    printf("latitude: %f\n", ((float)position.latitude)/1E7);
    printf("altitude: %d\n",position.altitude/1E6);
    //heading 1E6
    //everything else strieght
    printf("===============\n");

    mutex.lock();
    //Setting variables
    vp->set(ID)->setAltitude(position.altitude/1E6);
    vp->set(ID)->setLongitude(((float)position.longitude)/1E7);
    vp->set(ID)->setLatitude(((float)position.latitude)/1E7);
//    qDebug() << "position.latitude = " << (float)position.latitude;
//    qDebug() << "latitude/1E7 = " << (float)position.latitude/1E7;
    vp->set(ID)->setXVelocity(position.x_speed);
    vp->set(ID)->setYVelocity(position.y_speed);
    vp->set(ID)->setZVelocity(position.z_speed);
    //vp->set(ID)->setHeading(((float)position.heading)/1E6);
    mutex.unlock();
    vp->update(header.node_src_id);

//    int tID = 1;

//    mutex.lock();
//    if(!(targetList->inList(tID))){
//    //Add target to the target list
//        targetList->addTarget(new Target((float)position.latitude/1E7, (float)position.longitude/1E7, (float)position.altitude/1E6, 0, tID, 0, header.node_src_id));
//        //Target* t = new Target();
////        t->setTargetID(ID);
////        t->setLatitude(target.latitude/1E7);
////        t->setLongitude(target.longitude/1E7);
////        t->setAltitude(target.altitude/1E6);
////        t->setPayloadID(target.payload_ID);
////        t->setTargetID(target.target_ID);
////        t->setTargetType(target.target_type);
//        //targetList->addTarget(t);
//        targetList->updateDisplay(ID);
//    }
//    else
//    {
//        targetList->getTarget(ID)->setLatitude((float)position.latitude/1E7);
//        targetList->getTarget(ID)->setLongitude((float)position.longitude/1E7);
//        targetList->getTarget(ID)->setAltitude((float)position.altitude/1E6);
//        targetList->getTarget(ID)->setPayloadID(0);
//        targetList->getTarget(ID)->setTargetID(tID);
//        targetList->getTarget(ID)->setTargetType(0);
//        targetList->getTarget(ID)->setVehicleID(header.node_src_id);
//        targetList->update(ID);
//    }
//    mutex.unlock();
    /*
//    nq->enqueue(header.node_src_id);
    //Call database update in thread?
    //int checkLong = vp->at(i)->ts.at(0)->getLongitude() - vp->at(i)->getLatitude();
    //int checkLat = vp->at(i)->ts.at(0)->getLatitude() - vp->at(i)->getLatitude();

//    Debug
//    printf("Recieved global position\n");
//    std::cout << "Vehicle ID:" << position.vehicle_ID << " Timestamp:" << position.timestamp;;
//    std::cout << "\nPosition";
//    std::cout << "Altitude:" << position.altitude << "\nLatitude" << position.latitude;
//    std::cout << "Longitude:" << position.longitude;
//    std::cout << "\nSpeeds" << "\nX Speed:" << position.x_speed;
//    std::cout << "Y Speed:" << position.y_speed << "\nZ Speed:" << position.z_speed;
//    std::cout << "Vehicle Altitude:" << vp->at(i)->getAltitude() << "\nVehicle Latitude" << vp->at(i)->getLatitude();
//    std::cout << "Vehicle Longitude:" << vp->at(i)->getLongitude();

    return 0;
}

void* vehicle_attitude_callback(int8_t, com_header_t header, vehicle_attitude_t attitude, comnet::node*)
{
    //Finds index of vehicle
    int ID = header.node_src_id;
    //Is the vehicle id in list?
    if(!(vp->inList(ID))){
        qDebug() << "bad id " << ID;
        return 0; //Bad ID
    }
    //qDebug() << "attitude";
    mutex.lock();
    //Setting variables
    vp->set(ID)->setPitch(attitude.pitch);
    vp->set(ID)->setRoll(attitude.roll);
    vp->set(ID)->setYaw(attitude.yaw);
    mutex.unlock();
    vp->update(header.node_src_id);
//    nq->enqueue(header.node_src_id);
    /*
    qDebug() << "Vehicle ID:" << attitude.vehicle_ID << "Timestamp:" << attitude.timestamp;
    qDebug() << "\nAttitudes";
    qDebug() << "Pitch:" << attitude.pitch;
    qDebug() << "Roll:" << attitude.roll;
    qDebug() << "Yaw:" << attitude.yaw;
    */
    return 0;
}

void* target_designation_command_callback(int8_t, com_header_t header, target_designation_command_t target, comnet::node* node)
{
    qDebug() << "target received";
    //Add target to the target list
    /*
    targetList->addTarget(&Target(((float)target.latitude)/1E7,
                              ((float)target.longitude)/1E7,
                              target.altitude,
                              target.payload_ID,target.target_ID,target.target_type));
*/
    //int ID = header.node_src_id;

    int ID = target.target_ID;

    mutex.lock();
    if(!(targetList->inList(ID))){
    //Add target to the target list
        targetList->addTarget(new Target((float)target.latitude/1E7, (float)target.longitude/1E7, (float)target.altitude/1E6, target.payload_ID, target.target_ID, target.target_type, header.node_src_id));
        //Target* t = new Target();
//        t->setTargetID(ID);
//        t->setLatitude(target.latitude/1E7);
//        t->setLongitude(target.longitude/1E7);
//        t->setAltitude(target.altitude/1E6);
//        t->setPayloadID(target.payload_ID);
//        t->setTargetID(target.target_ID);
//        t->setTargetType(target.target_type);
        //targetList->addTarget(t);
        targetList->updateDisplay(ID);
    }
    else
    {
        targetList->getTarget(ID)->setLatitude((float)target.latitude/1E7);
        targetList->getTarget(ID)->setLongitude((float)target.longitude/1E7);
        targetList->getTarget(ID)->setAltitude((float)target.altitude/1E6);
        targetList->getTarget(ID)->setPayloadID(target.payload_ID);
        targetList->getTarget(ID)->setTargetID(target.target_ID);
        targetList->getTarget(ID)->setTargetType(target.target_type);
        targetList->getTarget(ID)->setVehicleID(header.node_src_id);
        targetList->update(ID);
    }
    mutex.unlock();
    /*
//Send recieved target command to uav
    QDateTime local(QDateTime::currentDateTime());
    QDateTime UTC(local.toUTC());
    float64_t x = UTC.toMSecsSinceEpoch();
    qDebug() << "latitude" << ((float)target.latitude)/1E7;
    qDebug() << "longitude" << ((float)target.longitude)/1E7;
    np->send_target_designation_command(69,69,x,69,1,1,0,
                                          ((float)target.latitude)/1E7,
                                          ((float)target.longitude)/1E7,
                                          target.altitude);
    //???
    //nq->targetRec(((float)target.latitude)/1E7,
                  //((float)target.longitude)/1E7);

    */
    return 0;
}

/*
void* target_status_callback(int8_t link_id, com_header_t header, target_status_t target_status, comnet::node* node_ptr)
{
    int ID = header.node_src_id;
    if(!(targetList->inList(ID))){
        //qDebug() << "adding target to list";
        //Add target to the target list
        Target* t = new Target();
        t->setTargetID(ID);
        t->setRadius((float)target_status.target_radius/1E7);
        t->setAngle((float)target_status.target_angle/1E7);
        t->setAltitude((float)target_status.target_altitude/1E7);
    targetList->addTarget(t);
    }
    mutex.lock();

    targetList->getTarget(ID)->setRadius(target_status.target_radius/1E7);
    targetList->getTarget(ID)->setAngle(target_status.target_angle/1E7);
    targetList->getTarget(ID)->setAltitude(target_status.target_altitude/1E7);

    mutex.unlock();

    return 0;
}

void* vehicle_waypoint_command_callback(int8_t, com_header_t h, vehicle_waypoint_command_t way, comnet::node* node_ptr)
{
    //if(way.waypoint_type == 1)
    targetList->addTarget(&Target(((float)way.latitude)/1E7,
                              ((float)way.longitude)/1E7,
                              ((float)way.altitude)/1E7,
                              0,0,0));
   return 0;
}*/



// Callback function that we will be using to link to Ping packet.
// Custom ping packet!
error_t VehicleAuthorizationRequestCallback(
const comnet::Header &header, VehicleAuthorizationRequest &packet, comnet::Comms &node)
{
  std::cout << "=::RECEIVED PACKET::=" << std::endl;
  std::cout << std::endl << "Source node: " <<
  (int32_t)header.source_id << std::endl;
  std::cout << "Message: " << std::endl;
  std::cout << packet.vehicle_id << std::endl;
  std::cout << packet.vehicle_type << std::endl;
  std::cout << packet.authorized_services << std::endl;
  std::cout << packet.granted_services << std::endl;
  return comnet::CALLBACK_SUCCESS | comnet::CALLBACK_DESTROY_PACKET;
}



// ----------- PROCESS -----------
// Start processing data.
//dynamic alloc
void rx_thread::process() {
   // allocate resources using new here
    //Create comnet Node
   node = new comnet::Comms(node_id);

   //Have the methods outside of class (i.e. callbacks) be able to have access to node
   np = node;
//   node->LoadKey("123456789ABCDEF");

   //Joystick Handling
   /*
   joystick = new JoystickInput(NULL,node);
   joystick_thread = new QThread;
   joystick -> moveToThread(joystick_thread);
   joystick_thread->start();*/

   //NOTE: ip is self IP for testing purposes
   qDebug() << "Self port for GCS: " << self_port;
   qDebug() << "Dest port for GCS: " << dest_port;

#if !XBEE
   char  ip[] = "127.0.0.1";
   char port_str[4];
   sprintf(port_str, "%d", self_port);
   node->InitConnection(UDP_LINK, port_str, ip);
   // testing a connection to yourself.
//   node->AddAddress(3, ip, self_port);
   node->AddAddress(3, ip, dest_port);
#else
   char  ip[] = "0013A20040917A31";
//   char  ipUGV[] = "0013A2004067E4A0";
   char  ipUGV[] = "0013A200409BD79C";
   // this value might change depending on your machine. Check which port your xbee is connected to and
   // make sure this value is the xbee port.
   char commport[] = "COM3";
   // Will initialize YOUR home address. This is your sender/receiver.
   qDebug() << "Initializing xbee home";
   if (!node->InitConnection(ZIGBEE_LINK, commport, ip, 57600)) {
     qDebug() << "Failed to initialize xbee home!";
   }
   // What is ugv node id again?
   // Add the address you wish to talk to.
   if (!node->AddAddress(3, ipUGV)) {
     qDebug() << "Failed to connect to ugv xbee!";
   }
#endif

   //Start Node
   //node->start(); <- no longer needed due to comnet update
    // Due to new library, things are more explicit, giving you more control.
   node->Run();

   /*Begin Callback Register functions*/
   // TODO(): Mimick the registration of these callbacks and redesign to use CommProtocol callback signatures.
   //  node->LinkCallback() is the call to register. allocated values are taken care of by the CommProto state machine.

   CALLBACK_REGISTER_BLOCK
   node->LinkCallback(new VehicleAuthorizationRequest(),  new comnet::Callback((comnet::callback_t )VehicleAuthorizationRequestCallback));
   node->LinkCallback(new VehicleInertialState(),         new comnet::Callback((comnet::callback_t )VehicleInertialStateCallback)); // <- replace nullptr with function callback that handles the corresponding Packet.
   node->LinkCallback(new VehicleModeCommand(),           new comnet::Callback(nullptr));
   node->LinkCallback(new VehicleWaypointCommand(),       new comnet::Callback(nullptr));
   node->LinkCallback(new VehicleAuthorizationReply(),    new comnet::Callback(nullptr));
   node->LinkCallback(new VehicleSystemStatus(),          new comnet::Callback(nullptr));
   END_CALLBACK_REGISTER_BLOCK

   //connect(this,SIGNAL(endUGVJoystick()),joystick,SLOT(stop()));
   //connect(this, SIGNAL(startUGVJoystick()), joystick, SLOT(process()));
   //when process is finished, set object to delete later
   //connect(this, SIGNAL(endUGVJoystick()), joystick, SLOT(deleteLater()));
   /*emit finished();
    * Ignoring as if emit it will close the thread prematurely, we will instead close
    * the thread upon the closing of the program. Network's deconstructor will close the thread
    */

}
//-----------------------------------------------------------------
/*Setting up callbacks
 * We need node->register_on_---(*---) and void *---(-----------)
 * to set up the call back the void function is to set up what do to
 * the register function is to accept an incomming message
 * We use void* and (*--) due to the fact that the typedefs were
 * void* (*---), meaning that we are going to have a pointer to a pointer
*/
