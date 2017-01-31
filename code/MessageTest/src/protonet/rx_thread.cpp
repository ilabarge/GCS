#include "rx_thread.h"
QMutex mutex;
comnet::node *np;
rx_thread *rx;

// ------- CONSTRUCTOR -------
rx_thread::rx_thread(uint8_t node_id, uint16_t self_port, uint16_t dest_port){
    // you could copy data from constructor arguments to internal variables here.
    this->node_id = node_id;
    this->self_port = self_port;
    this->dest_port = dest_port;
    qDebug() << "rx_thread constructor serial port is: " << this->serial_port;
    //give a pointer to the thread
    rx = this;
}

void rx_thread::update_vech_queue() { emit update_queue();}

void rx_thread::print_port() {  qDebug() << serial_port; }

void rx_thread::update(int vechID) { emit updateVech(vechID);}

float64_t rx_thread::getTime()
{
    QDateTime local(QDateTime::currentDateTime());
    QDateTime UTC(local.toUTC());
    return UTC.toMSecsSinceEpoch();
}
// ------- DECONSTRUCTOR -------
rx_thread::~rx_thread() {
    qDebug() << "Rx Deconstrutor";
    //destroy any pointers!
    //delete node;
}

void rx_thread::telemetryRequest()
{
    emit telemetryReq();
}

void rx_thread::authorizationRequest()
{
    emit authorizeReq();
}

//------------ User Commands -------------
void rx_thread::send_ping()
{
    qDebug() << "send ping";
    //Use vehicle type as id
    float64_t x = getTime();
    node->send_ping(1,x);
}

//Vech authorization request
void rx_thread::send_vehicle_auth_request(int vehicle)
{
   //Authorization request link key will be 100 for now
    float64_t x = getTime();
    mutex.lock();
    node->send_vehicle_authorization_request(vehicle,x,vehicle,100,1,0);
    mutex.unlock();
    emit messageConfirm(QString("Sent vehicle authorization request to ID" + vehicle));
}

//Need to send before vehicle will stream info
void rx_thread::send_telemetry_command(int vehicle)
{
    //NOTE: might need to fix telemetry rate.
    // 0 all streams
    // 1 attitude stream
    // 2 position stream
    // 3 heartbeat stream

    //node->send_vehicle_telemetry_command(dest_id,vehicle_id,telemetry_select,telemetry_rate);
    mutex.lock();
    node->send_vehicle_telemetry_command(vehicle,vehicle,0,1);
    mutex.unlock();
    emit messageConfirm(QString("Sent Telemetry Command to ID" + vehicle));
}

//Send targeting informaiton to vehicle
void rx_thread::send_targeting(int vehicle, float lat,float longi,float alt)
{
    //Target id = 1, Payload ID = 1
    float64_t x = getTime();
    //node->send_target_designation_command(dest_id,timestamp,vech_ID,payload_id, target_id,target_type,latitude,longitude,altitude);
    //target type?
    node->send_target_designation_command(vehicle, x,
                                          vehicle, 1, 1, 0,
                                          lat,
                                          longi,
                                          alt);
    //node->send_payload_bay_command(dest_id,timestamp,payload_id,bay_mode);
}

//emit target recieved out to main window
void rx_thread::target(float lat,float longi) { emit sendTarget(lat,longi);}

void rx_thread::send_global_position(int ID, double lat, double lon, double alt, double head, double xSpeed, double ySpeed, double zSpeed)
{
    float64_t x = getTime();
    node->send_vehicle_global_position(1,x,ID,lat,lon,alt,head,xSpeed,ySpeed,zSpeed);
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
    node->add_serial(&link_id, 9600, serialp);

    //Establish serial
    node->establish_serial(link_id,1);
    mutex.unlock();
    qDebug() << "node serial set is: " << serialp;
}

/** Test to see if need to wait after sending message
 * @brief hold
 */
void rx_thread::hold()
{
    for(int i = 0; i < 50; i++);
}

// -------- CHECKING VEHICLE --------
/*int checkVehicles(uint32_t vehicle_ID)
{
    for(int i = 1; i < vp->length(); i++){
        if(vp->at(i)->getVehicleID()== vehicle_ID){
            return i;
        }
    }
    return -1;
}*/

// --------- COMNET CALLBACKS ---------
//Clean up code!!
void* enter_callback(int8_t id, proto_header_t header, enter_t enter, comnet::node* node)
{
    //printf("got enter");
    //upon enter message add vehicle to vector if it doesn't exist already
    //Send reply
    QDateTime local(QDateTime::currentDateTime());
    QDateTime UTC(local.toUTC());
    float64_t x = UTC.toMSecsSinceEpoch();
    //IMPORTANT:send vehicle authorization request on user input
    //emmit Authorization_Request();
    //Request is as follows, vech id, timestamp, our id, link key (100 for now),
    //request services (1 for we want services 0 for we do not want),
    //handover node (default is 0 only change if we want to give control to someone else node#)
    //np->send_vehicle_authorization_request(header.node_src_id,x,header.node_src_id,200,1,0);
    return 0;
}

void* ping_callback(int8_t id, proto_header_t header, ping_t ping, comnet::node* node)
{
   printf("got ping");
   qDebug() << "got ping";
   //send a pong as a reply
   node->send_pong(header.node_src_id,0);
   return 0;
}

void* pong_callback(int8_t, proto_header_t header, pong_t pong, comnet::node* node_ptr)
{
   printf("got pong");
   return 0;
}

void* vehicle_authorization_request_callback(int8_t id, proto_header_t header, vehicle_authorization_request_t vehicle, comnet::node* node_ptr)
{
   qDebug("Got Vehicle Authorization Request");
   rx->authorizationRequest();
   //node_ptr->send_vehicle_authorization_reply(header.node_src_id,99,vehicle.vehicle_ID,99 ,vehicle.request_services,99);
   return 0;
}


void* vehicle_telemetry_command_callback(int8_t, proto_header_t, vehicle_telemetry_command_t, comnet::node* node_ptr)
{
    qDebug("Got vehicle telemetry request");
    rx->telemetryRequest();
    return 0;
}

//Runs after we send a request to a vehicle
void* vehicle_authorization_reply_callback(int8_t id, proto_header_t header, vehicle_authorization_reply_t vehicle, comnet::node* node_ptr)
{
   printf("Got Vehicle Authorization Reply");
   int ID = header.node_src_id;
   //Is the vehicle id in list?
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
    qDebug() << "recieved vechicle authorization request";
    qDebug() << vehicle.granted_services;      //granted service
   return 0;
}

//Gives system status
void* vehicle_system_status_callback(int8_t, proto_header_t header, vehicle_system_status_t status, comnet::node* node_ptr)
{
    printf("=============\nsystem status\n");
    int ID = header.node_src_id;
    //Is the vehicle id in list?
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
    mutex.unlock();
    //Debug
    return 0;
}

void* vehicle_inertial_state_callback(int8_t id, proto_header_t header, vehicle_inertial_state_t inertial, comnet::node* node_ptr)
{
    int ID = header.node_src_id;
    //Is the vehicle id in list?
    printf("==========\ninternal State\n");
    printf("longitude: %f\n",((float)inertial.longitude)/1E7);
    printf("longitude: %f\n", ((float)inertial.latitude)/1E7);
    printf("===============");
    mutex.lock();
    /*
     * Unused
    inertial.east_accel();
    inertial.east_speed();
    inertial.north_accel();
    inertial.north_speed();
    */
//    inertial.vertical_accel; //Missing?
//    inertial.vertical_speed; //Missing?
//    vp->set(ID)->setRoll(inertial.roll);
//    vp->set(ID)->setRollRate(inertial.roll_rate);
//    vp->set(ID)->setHeading(inertial.heading);
//    vp->set(ID)->setAltitude(inertial.altitude/1E6);
//    vp->set(ID)->setLatitude(((float)inertial.latitude)/1E7);
//    vp->set(ID)->setLongitude(((float)inertial.longitude)/1E7);
//    vp->set(ID)->setPitch(inertial.pitch);
//    vp->set(ID)->setPitchRate(inertial.pitch_rate);
    mutex.unlock();
//    vp->update(header.node_src_id);
//    nq->enqueue(header.node_src_id);
    return 0;
}

void* vehicle_global_position_callback(int8_t id, proto_header_t header, vehicle_global_position_t position, comnet::node* node_ptr)
{
    qDebug() << "globalpos" << header.node_src_id;
    int ID = header.node_src_id;
    //Is the vehicle id in list?
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
//    vp->set(ID)->setAltitude(position.altitude/1E6);
//    vp->set(ID)->setLongitude(((float)position.longitude)/1E7);
//    vp->set(ID)->setLatitude(((float)position.latitude)/1E7);
//    vp->set(ID)->setXVelocity(position.x_speed);
//    vp->set(ID)->setYVelocity(position.y_speed);
//    vp->set(ID)->setZVelocity(position.z_speed);
//    vp->set(ID)->setHeading(((float)position.heading)/1E6);
    mutex.unlock();
//    vp->update(header.node_src_id);
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

void* vehicle_attitude_callback(int8_t, proto_header_t header, vehicle_attitude_t attitude, comnet::node* node_ptr)
{
    //Finds index of vehicle
    int ID = header.node_src_id;
    //qDebug() << "attitude";
    mutex.lock();
    //Setting variables
//    vp->set(ID)->setPitch(attitude.pitch);
//    vp->set(ID)->setRoll(attitude.roll);
//    vp->set(ID)->setYaw(attitude.yaw);
    mutex.unlock();
//    vp->update(header.node_src_id);
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

void* target_designation_command_callback(int8_t, proto_header_t, target_designation_command_t target, comnet::node* node_ptr)
{
    //Add target to the target list
    //targetList->addTarget(&Target(((float)target.latitude)/1E7,
      //                        ((float)target.longitude)/1E7,
        //                      target.altitude,
          //                    target.payload_ID,target.target_ID,target.target_type));

    //Send recieved target command to uav


    QDateTime local(QDateTime::currentDateTime());
    QDateTime UTC(local.toUTC());
    float64_t x = UTC.toMSecsSinceEpoch();
    qDebug() << "latitude" << ((float)target.latitude)/1E7;
    qDebug() << "longitude" << ((float)target.longitude)/1E7;
   /*np->send_target_designation_command(69,x,69,1,1,0,
                                          ((float)target.latitude)/1E7,
                                          ((float)target.longitude)/1E7,
                                          target.altitude);
    //???
   // nq->targetRec(((float)target.latitude)/1E7,
                  ((float)target.longitude)/1E7);*/
    return 0;
}

void* vehicle_waypoint_command_callback(int8_t, proto_header_t h, vehicle_waypoint_command_t way, comnet::node* node_ptr)
{
    if(way.waypoint_type == 1)
    /*targetList->addTarget(&Target(((float)way.latitude)/1E7,
                              ((float)way.longitude)/1E7,
                              ((float)way.altitude)/1E7,
                              0,0,0));*/
   return 0;
}


// ----------- PROCESS -----------
// Start processing data.
//dynamic alloc
void rx_thread::process() {
   // allocate resources using new here

    //Create Comnet Node
   node = new comnet::node(node_id);

   //Have the methods outside of class (i.e. callbacks) be able to have access to node
   np = node;

   //Set link_id to 0
   int8_t link_id(0);

   //Add udp at link id, self port, self ip
   //NOTE: ip is self IP for testing purposes
   //Changed due to original being a const char
   std::string *str = new std::string("127.0.0.1");
   //We grab the memory location of the first char in the string as it is a char array
   char *arr = &(*str)[0];
   node->add_udp(&link_id,self_port,arr);
   qDebug() << "Self port for Tester: " << self_port;
   //Add endpoint for udp using link id, dest_id, destinition port, destinition address
   //NOTE: ip is self IP for testing purposes
   node->establish_udp(link_id,1,dest_port,arr);
   qDebug() << "Dest port for Tester: " << dest_port;

   //Start Node
   //node->start(); <- no longer needed due to comnet update

   /*Begin Callback Register functions*/
   node->register_on_ping(*ping_callback);
   node->register_on_enter(*enter_callback);
   node->register_on_pong(*pong_callback);
   node->register_on_vehicle_global_position(*vehicle_global_position_callback);
   node->register_on_vehicle_system_status(*vehicle_system_status_callback);
   node->register_on_vehicle_attitude(*vehicle_attitude_callback);
   node->register_on_vehicle_authorization_request(*vehicle_authorization_request_callback);
   node->register_on_vehicle_authorization_reply(*vehicle_authorization_reply_callback);
   node->register_on_vehicle_waypoint_command(*vehicle_waypoint_command_callback);
   node->register_on_vehicle_telemetry_command(*vehicle_telemetry_command_callback);
   //ack vehicle got t
   //request list

   //UGV Sends when
   node->register_on_target_designation_command(*target_designation_command_callback);
}
//-----------------------------------------------------------------
/*Setting up callbacks
 * We need node->register_on_---(*---) and void *---(-----------)
 * to set up the call back the void function is to set up what do to
 * the register function is to accept an incomming message
 * We use void* and (*--) due to the fact that the typedefs were
 * void* (*---), meaning that we are going to have a pointer to a pointer
*/
