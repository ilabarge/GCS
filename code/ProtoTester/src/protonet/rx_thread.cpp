#include "rx_thread.h"
#include <QTcpSocket>

QMutex mutex;
protonet::node *np;

// ------- CONSTRUCTOR -------
rx_thread::rx_thread(uint8_t node_id, uint16_t self_port, uint16_t dest_port,QString serial){
    // you could copy data from constructor arguments to internal variables here.
    this->node_id = node_id;
    this->self_port = self_port;
    this->dest_port = dest_port;
    qDebug() << "rx_thread constructor serial port is: " << this->serial_port;
}

void rx_thread::print_port() {  qDebug() << serial_port; }

// ------- DECONSTRUCTOR -------
rx_thread::~rx_thread() {
    qDebug() << "Rx Deconstrutor";
    //destroy any pointers!
    //delete node;
}

//------------ User Commands -------------
void rx_thread::send_ping()
{
    qDebug() << "send ping";
    //Use vehicle type as id
    QDateTime local(QDateTime::currentDateTime());
    QDateTime UTC(local.toUTC());
    float64_t x = UTC.toMSecsSinceEpoch();
    //qDebug() << "Sending ping";
    node->send_ping(1,x);
}
//Adjusting network settings
//Adjust serial port
void rx_thread::setNetworkSerial(QString serial)
{
    //Translating the QString to a char*
//    /QString con = "COM4";
    QByteArray portN = serial.toLocal8Bit();
    char *serialp = portN.data();

    //Set link_id to 0
    int8_t link_id(0);

    //Add serial at link id, baud rate, serial port
    node->add_serial(&link_id, 9600, serialp);

    //Establish serial
    node->establish_serial(link_id,1);

    qDebug() << "node serial set is: " << serialp;
    //qDebug() << con;
}

//TEST SEND GPS POSITION
void rx_thread::GPS()
{

//    socket = new QTcpSocket( this ); // <-- needs to be a member variable: QTcpSocket * _pSocket;
//    //connect( socket, SIGNAL(readyRead()), SLOT(readTcpData()) );
//     QByteArray data;
//     data.push_front("test");
//    socket->connectToHost("kfriede.com", 6969);
//    if( socket->waitForConnected() ) {
//        socket->write( data );
//    }
    //node->send_vehicle_inertial_state(node id,time,id,lat,long,alt,roll,pitch,heading);
    node->send_vehicle_inertial_state(1,0,69,0,0,0,34,32,12,21,12,12,21,21,12,21,21,12);
    node->send_vehicle_global_position(1,0,69,32*1E7,18*1E7,0,1,3*1E7,4*1E7,3*1E7);
    qDebug() << "sent info";
}

// -------- CHECKING VEHICLE --------
int checkVehicles(uint32_t vehicle_ID)
{

    return -1;
//    if(vehicle_ID > 10 || vehicle_ID < 1)
//    {
//       return 0;
//    }
//    else
//    {
//        return vehicle_ID;
//    }
}

// --------- PROTONET CALLBACKS ---------
//Clean up code!!
void* enter_callback(int8_t id, proto_header_t header, enter_t enter, protonet::node* node)
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
    np->send_vehicle_authorization_request(header.node_src_id,x,header.node_src_id,200,1,0);
    return 0;
}

void* ping_callback(int8_t id, proto_header_t header, ping_t ping, protonet::node* node)
{
   printf("got ping");
   //qDebug() << "Ping timestamp:" << ping.timestamp << endl;
   //qDebug() << "Sending pong response." << endl;
   //send a pong as a reply
   node->send_pong(header.node_src_id,0);
   return 0;
}

void* pong_callback(int8_t, proto_header_t header, pong_t pong, protonet::node* node_ptr)
{
   printf("got pong");
   node_ptr->send_ping(header.node_src_id,0);
   return 0;
}

void* vehicle_authorization_request_callback(int8_t id, proto_header_t header, vehicle_authorization_request_t vehicle, protonet::node* node_ptr)
{
   printf("Got Vehicle Authorization Request");
   //node_ptr->send_vehicle_authorization_reply(header.node_src_id,99,vehicle.vehicle_ID,99 ,vehicle.request_services,99);
   return 0;
}

//Runs after we send a request to a vehicle
void* vehicle_authorization_reply_callback(int8_t id, proto_header_t header, vehicle_authorization_reply_t vehicle, protonet::node* node_ptr)
{
   printf("Got Vehicle Authorization Reply");
   int i = checkVehicles(header.node_src_id);
   if(i == -1){
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
void* vehicle_system_status_callback(int8_t, proto_header_t header, vehicle_system_status_t status, protonet::node* node_ptr)
{
    printf("=============\nsystem status\n");
    //Finds index of vehicle
    int i = checkVehicles(header.node_src_id);
    if(i == -1){
        return 0; //Bad ID
    }
    printf("state: %d  mode: %d\n",status.vehicle_state,status.vehicle_mode);
    printf("=============\n");
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
    int state = status.vehicle_state;
    int mode = status.vehicle_mode;
    //Sets vehicle update value to true
    //Debug
    /*
    qDebug() << "Timestamp: " << status.timestamp;
    qDebug() << "ID: " << status.vehicle_ID;
    qDebug() << "Mode: " << status.vehicle_mode;
    qDebug() << "State: "<<status.vehicle_state;
    */
    return 0;
}

void* vehicle_inertial_state_callback(int8_t id, proto_header_t header, vehicle_inertial_state_t inertial, protonet::node* node_ptr)
{
    //Finds index of vehicle
    int i = checkVehicles(header.node_src_id);
    if(i == -1){
        return 0; //Bad ID
        //vp->append(Vehicle(hea));
    }
    printf("==========\ninternal State\n");
    printf("longitude: %f\n",((float)inertial.longitude)/1E7);
    printf("longitude: %f\n", ((float)inertial.latitude)/1E7);
    printf("===============");
    mutex.lock();
    /*
    inertial.east_accel(); Unused?
    inertial.east_speed();
    inertial.north_accel();
    inertial.north_speed();
    */
    inertial.vertical_accel; //Missing?
    inertial.vertical_speed; //Missing?
    float32_t roll = inertial.roll;
    float32_t roll_rate = inertial.roll_rate;
    float32_t heading = inertial.heading;
    float32_t altitude = inertial.altitude;
    float32_t latitude = ((float)inertial.latitude)/1E7;
    float32_t longitude = ((float)inertial.longitude)/1E7;
    float32_t pitch = inertial.pitch;
    float32_t pitch_rate = inertial.pitch_rate;
    int node_id = header.node_src_id;
    return 0;
}

void* vehicle_global_position_callback(int8_t id, proto_header_t header, vehicle_global_position_t position, protonet::node* node_ptr)
{
    //Finds index of vehicle
    //qDebug() << "globalpos";
    int i = checkVehicles(header.node_src_id);
    if(i == -1){
        return 0; //Bad ID
    }
    //Debug prints
    printf("==============\nGlobal position\n");
    printf("longitude: %f\n",((float)position.longitude)/1E7);  //137
    printf("latitude: %f\n", ((float)position.latitude)/1E7);
    printf("altitude: %d\n",position.altitude);
    //heading 1E6
    //everything else strieght
    printf("===============\n");
    mutex.lock();
    //Setting variables
    float32_t altitude = position.altitude;
    float32_t latitude = ((float)position.latitude)/1E7;
    float32_t longitude = ((float)position.longitude)/1E7;
    int16_t x_speed = position.x_speed;
    int16_t y_speed = position.y_speed;
    int16_t z_speed = position.z_speed;
    float32_t heading = ((float)position.heading)/1E6;
    mutex.unlock();
    int node_src = header.node_src_id;
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

void* vehicle_attitude_callback(int8_t, proto_header_t header, vehicle_attitude_t attitude, protonet::node* node_ptr)
{
    //Finds index of vehicle
    int i = checkVehicles(header.node_src_id);
    if(i == -1){
        return 0; //Bad ID
    }
    //qDebug() << "attitude";
    //Setting variables
    float32_t pitch = attitude.pitch;
    float32_t roll = attitude.roll;
    float32_t yaw = attitude.yaw;
    int node_src = attitude.yaw;
    /*
    qDebug() << "Vehicle ID:" << attitude.vehicle_ID << "Timestamp:" << attitude.timestamp;
    qDebug() << "\nAttitudes";
    qDebug() << "Pitch:" << attitude.pitch;
    qDebug() << "Roll:" << attitude.roll;
    qDebug() << "Yaw:" << attitude.yaw;
    */
    return 0;
}

void* target_designation_command_callback(int8_t, proto_header_t, target_designation_command_t target, protonet::node* node_ptr)
{
    //Add target to the target list
    //targetList->addTarget(&Target(((float)target.latitude)/1E7,
      //                        ((float)target.longitude)/1E7,
        //                      target.altitude,
          //                    target.payload_ID,target.target_ID,target.target_type));
    //send target to UAV
    QDateTime local(QDateTime::currentDateTime());
    QDateTime UTC(local.toUTC());
    float64_t x = UTC.toMSecsSinceEpoch();
    qDebug() << "latitude" << ((float)target.latitude)/1E7;
    qDebug() << "longitude" << ((float)target.longitude)/1E7;
    np->send_target_designation_command(69,x,69,1,1,0,
                                          ((float)target.latitude)/1E7,
                                          ((float)target.longitude)/1E7,
                                          target.altitude);
    float32_t latitude = (float)target.latitude/1E7;
    float32_t longitude = (float)target.longitude/1E7;
    return 0;
}

void* vehicle_waypoint_command_callback(int8_t, proto_header_t h, vehicle_waypoint_command_t way, protonet::node* node_ptr)
{
    if(way.waypoint_type == 1)
    {
        float32_t latitude = (float)way.latitude/1E7;
        float32_t longitude = (float)way.longitude/1E7;
        float32_t altitude = (float)way.altitude/1E7;
    }
    qDebug() << "got waypoint";
   return 0;
}
// ----------- PROCESS -----------
// Start processing data.
//dynamic alloc
void rx_thread::process() {
   // allocate resources using new here

    //Create Protonet Node
   node = new protonet::node(node_id);

   //Have the methods outside of class (i.e. callbacks) be able to have access to node
   np = node;

   //Set link_id to 0
   int8_t link_id(0);

   //Add udp at link id, self port, self ip
   //NOTE: ip is self IP for testing purposes
   qDebug() << "Self port for tester: " << self_port;
   node->add_udp(&link_id,self_port,"127.0.0.1");
   qDebug() << "Dest port for tester: " << dest_port;
   //Add endpoint for udp using link id, dest_id, destinition port, destinition address
   //NOTE: ip is self IP for testing purposes
   node->establish_udp(link_id, 1 ,dest_port,"127.0.0.1");

   //Start Node
   //node->start(); <- no longer needed due to protonet update

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
   //ack vehicle got t
   //request list

   //UGV Sends when
   node->register_on_target_designation_command(*target_designation_command_callback);

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

//UNUSED CALLBACKS
/* REMOVE AS NEEDED SOME ARE MORE COMPLETE THAN OTHERS
 *

//Payload operation command
void send_payload_operation_command()
{
   node->send_payload_operation_command(dest_id,timestamp,payloadID,payloadCommand);
}
//Vehicle Mode
void send_vehicle_mode_command()
{
   node->send_vehicle_mode_command(dest_id,timestamp,vehicle_id,vehicle_mode);
}

void* connection_request_callback(int8_t, proto_header_t header, connection_request_t
connection, protonet::node* node_ptr)
{
   printf("got request for connection");
   qDebug() << "Trace node1" << connection.tracenode_1;
   qDebug() << "Trace nodeN" << connection.tracenode_N;
   //Missing inorder timestamp, connection, tracenode_Npre
   //Is sending out connection id, n previous.
   node_ptr->send_connection_reply
(header.node_src_id,999,999,connection.tracenode_1,connection.tracenode_N,999);
   return 0;
}

void* connection_reply_callback(int8_t, proto_header_t header, connection_reply_t
reply, protonet::node* node_ptr)
{
   printf("got connection reply");
   //qDebug()<< "Connection id:" << reply.connection_ID << "Timestamp:" <<
reply.timestamp;
   //qDebug() << reply.tracenode_1 << reply.tracenode_N << reply.tracenode_NPrev;
   return 0;
}

typedef void* (*exit_callback)(int8_t, proto_header_t, exit_t, protonet::node*
node_ptr);

typedef void* (*vehicle_identification_callback)(int8_t, proto_header_t,
vehicle_identification_t, protonet::node* node_ptr);


void* air_vehicle_ground_relative_state_callback(int8_t, proto_header_t header,
air_vehicle_ground_relative_state_t air_ground, protonet::node* node_ptr)
{
   qDebug() << "Vehicle ID:" << air_ground.vehicle_ID << "Timestamp:" <<
air_ground.timestamp;
   qDebug() << "Sideslip angle:" << air_ground.sideslip_angle;
   qDebug() << "Angle of attack:" << air_ground.angle_of_attack;
   qDebug() << "Baro altitude:" << air_ground.baro_altitude;
   qDebug() << "East Ground Speed:" << air_ground.east_ground_speed;
   qDebug() << "East Wind Speed:" << air_ground.east_wind_speed;
   qDebug() << "Indicated air Speed:" << air_ground.indicated_air_speed;
   qDebug() << "North Ground Speed:" << air_ground.north_ground_speed;
   qDebug() << "North Wind Speed:" << air_ground.north_wind_speed;
   qDebug() << "True air Speed:" << air_ground.true_air_speed;
   return 0;
}


void* vehicle_body_sensed_state_callback(int8_t id, proto_header_t header,
vehicle_body_sensed_state_t state, protonet::node* node_ptr)
{

   qDebug() << "Vehicle ID:" << state.vehicle_ID << " Timestamp:" << state.timestamp;
   qDebug() << "\nRates";
   qDebug() << "Pitch Rate:" << state.pitch_rate;
   qDebug() << "Roll Rate:" << state.roll_rate;
   qDebug() << "Yaw Rate:" << state.yaw_rate;
   qDebug() << "\nAccelerations";
   qDebug() << "X acceleration:" << state.x_accel;
   qDebug() << "Y acceleration:" << state.y_accel;
   qDebug() << "Z acceleration:" << state.z_accel;
   return 0;
}

/*UNUSED USER COMMANDS--------------------------------
//Vech authorization request
void rx_thread::send_vehicle_auth_request(int vehicle)
{
   //Authorization request link key will be 100 for now
    QDateTime local(QDateTime::currentDateTime());
    QDateTime UTC(local.toUTC());
    float64_t x = UTC.toMSecsSinceEpoch();
    node->send_vehicle_authorization_request(vehicle,x,vehicle,
                                             //vp->at(0)->getVehicleType(),x,
                                             //vp->at(0)->getVehicleType(),
                                             100,1,0);
}

//Vehicle waypoint
void rx_thread::send_vehicle_waypoint(int vehicle)
{
    QDateTime local(QDateTime::currentDateTime());
    QDateTime UTC(local.toUTC());
    float64_t x = UTC.toMSecsSinceEpoch();
   //send t to vehicle
    //For Testing purposes
//    node->send_vehicle_t_command(vehicle,x,vehicle, (int32_t)4*1E7,(int32_t)-8*1E7,(int32_t)4*1E7,0,0,2);
    node->send_vehicle_waypoint_command(vehicle,x,vehicle, (int32_t)(-3.29)*1E7,(int32_t)9*1E7,(int32_t)12.0*1E7,0,1,0);
    //node->send_vehicle_t_command(vehicle,x,vehicle, (int32_t)-4*1E7,(int32_t)5*1E7,(int32_t)1*1E7,0,2,2);
   //update vehicle localy to have t

//      node->send_vehicle_waypoint_command(vehicle,x,vehicle,
//                                         2,//latitude
//                                         4, //longitude
//                                         50 , //alt
//                                         0,
//                                         1,//type
//                                         1);//i
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
    node->send_vehicle_telemetry_command(vehicle,vehicle,
                                           //vp->at(0)->getVehicleType(),
                                           //vp->at(0)->getVehicleType(),
                                           0,1);
}

void rx_thread::send_targeting(int vehicle)
{
    //Target id = 1, Payload ID = 1
    QDateTime local(QDateTime::currentDateTime());
    QDateTime UTC(local.toUTC());
    float64_t x = UTC.toMSecsSinceEpoch();
    //node->send_target_designation_command(dest_id,timestamp,vech_ID,payload_id, target_id,target_type,latitude,longitude,altitude);
    //target type?
    node->send_target_designation_command(vehicle, x,
                                          vehicle, 1, 1, 0,
                                          3,// lat
                                          4,// long
                                          5);// altitude
    //node->send_payload_bay_command(dest_id,timestamp,payload_id,bay_mode);
}

void rx_thread::send_manTargeting(float latitude,float longitude, float altitude)
{
    //Target id = 1, Payload ID = 1
    QDateTime local(QDateTime::currentDateTime());
    QDateTime UTC(local.toUTC());
    float64_t x = UTC.toMSecsSinceEpoch();
    //node->send_target_designation_command(dest_id,timestamp,vech_ID,payload_id, target_id,target_type,latitude,longitude,altitude);
    //target type?
    //printf("lat: %f long: %f alt: %f",latitude,longitude,altitude);
    node->send_target_designation_command(69, x,
                                          69, 1, 1, 0,
                                          latitude*1E7,longitude*1E7,altitude);
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
    node->send_payload_bay_mode_command(vehicle,x,1,1);
}

//UAV disarm
void rx_thread::disarm_uav(int vehicle)
{
    QDateTime local(QDateTime::currentDateTime());
    QDateTime UTC(local.toUTC());
    float64_t x = UTC.toMSecsSinceEpoch();
    //vehicle id, timestamp, payload bay, mode (0 disarm 1 arm)
    node->send_payload_bay_mode_command(vehicle,x,1,0);
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
        node->send_payload_bay_command(vehicle,x,1,1);
        //send to UGV for ack to end of mission
        node->send_payload_bay_command(46,x,1,1);
    }
    else
        node->send_payload_bay_command(46,x,1,1);
}


*/
