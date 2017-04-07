#include "networking.h"
/**
 * @brief networking::invokeThread Creates thread for comnet messages
 * @param q NODE QUEUE (will need to remove after transfer to new signal is complete)
 * @param v vehicle list
 * @param tgt Holds targets
 * @param node_id  GCS NODE ID (1)
 * @param self_port UDP port to recieve comnet messages
 * @param dest_port UDP port to send comnet messages
 */
void networking::invokeThread(uint8_t node_id, uint16_t self_port, uint16_t dest_port)
{
    //create new thread
    network_thread = new QThread;
    //Create class to put in thread
    QString serial = "a";
    rx = new rx_thread(node_id, 1337, 1338, serial);
    //Put class in thread
    rx->moveToThread(network_thread);
    //Map error strings
    //connect(rx, SIGNAL(error(QString)), this, SLOT(errorString(QString)));

    //If thread started then start process in class
    connect(network_thread, SIGNAL(started()), rx, SLOT(process()));
    //when process is finished, quit network_thread
    connect(rx, SIGNAL(finished()), network_thread, SLOT(quit()));
    //when process is finished, set object to delete later
    connect(rx, SIGNAL(finished()), rx, SLOT(deleteLater()));
    //when network_thread is finished set to delete later
    connect(network_thread, SIGNAL(finished()), network_thread, SLOT(deleteLater()));

    //Basic network actions
    //connect(this,SIGNAL(ping(int)),rx,SLOT(send_ping(int)));

    //Send waypoint command
    //connect(this,SIGNAL(waypoint(Waypoint22*, int)), rx,SLOT(send_vehicle_waypoint(Waypoint22*, int)));
    //Vehicle Telemetry Command
    //Begin the telemetry stream from vehicle
    connect(this,SIGNAL(telemetry_command(int)),rx,SLOT(send_telemetry_command(int)));

    //Vehicle Auhorization request
    //To allow C&C over vehicle
    connect(this,SIGNAL(vehicle_auth_request(int)),rx,SLOT(send_vehicle_auth_request(int)));

    //Update vehicle update queue (OLD NEED TO REMOVE DEPENDENCY)
    connect(rx,SIGNAL(update_queue()),this,SLOT(update_vehicle_queue()));

    //New Vehicle Information recieved
    connect(rx,SIGNAL(updateVech(int)),this,SLOT(updateVech(int)));

    //Update the location of the target found
    //connect(rx,SIGNAL(newTarget(Target*)),this,SLOT(update_target_disp(Target*)));

    //Update displayed vehicle target
    connect(rx,SIGNAL(sendTarget(float,float)),this,SLOT(newTarget(float,float)));

    //UAV arm/disarm
    connect(this,SIGNAL(armUAV(int)),rx,SLOT(arm_uav(int)));
    connect(this,SIGNAL(disarmUAV(int)),rx,SLOT(disarm_uav(int)));

    //UAV Drop payload (manual)
    connect(this,SIGNAL(drop(int)),rx,SLOT(drop(int)));

    //UAV targeting (manual)
    connect(this,SIGNAL(manTargeting(double,double,double)),rx,SLOT(send_manTargeting(double,double,double)));

    //Displays UAV status
    connect(rx,SIGNAL(vechStatus(int,int)),this,SLOT(vStatus(int,int)));

    //UGV State change
    //Auto to manual control
    connect(this,SIGNAL(ATM()),rx,SLOT(AutoToManual()));
    //Mantual to auto
    connect(this,SIGNAL(MTA()),rx,SLOT(ManualToAuto()));

    //UGV Motor State
    connect(this,SIGNAL(DisableM()),rx,SLOT(DisableMotor()));
    connect(this,SIGNAL(EnableM()),rx,SLOT(EnableMotor()));
    connect(this,SIGNAL(ToggleM()),rx,SLOT(ToggleMotor()));

    //UGV joystick
    //connect(this,SIGNAL(UGV_joystick_start()), rx,SLOT(start_UGV_Joystick()));
    //connect(this,SIGNAL(UGV_joystick_stop()),rx,SLOT(stop_UGV_Joystick()));

    //Updating netowrk set up
    connect(this,SIGNAL(network_set_serial(QString)),rx,SLOT(setNetworkSerial(QString)));

    //Console log messages
    connect(rx,SIGNAL(message(QString)),this,SLOT(messageSlot(QString)));
    connect(rx,SIGNAL(messageAlert(QString)),this,SLOT(messageAlertSlot(QString)));
    connect(rx,SIGNAL(messageConfirm(QString)),this,SLOT(messageConfirmSlot(QString)));

    connect(this, SIGNAL(sendGPS()),rx,SLOT(send_GPS()));
    connect(this, SIGNAL(sendPing()),rx,SLOT(send_Ping()));
    network_thread->start();
}
/**
 * @brief networking::networking invokes the thread to handle comnet messages
 */
networking::networking()
{
    //qDebug() << "Invoking thread with: " << port;
    invokeThread(3, 1337, 1338);
}

void networking::send_GPS(){ emit sendGPS();}
void networking::send_Ping(){ emit sendPing();}

//Network send message signal/slots
void networking::send_ping(int id){ emit ping(id); }

//Update Vehicle (OLD NEED TO REMOVE DEPENDENCY)
void networking::update_vehicle_queue() { emit update_queue(); }

//Update Vehicle with given ID
void networking::updateVech(int ID) {emit updateVechicle(ID); }

//Sending waypoint
//void networking::send_waypoint(Waypoint22* w, int id){ qDebug() << "in networking";emit waypoint(w, id); }

//Send vehicle authorization request to vehicle i
void networking::send_vehicle_auth_request(int i){emit vehicle_auth_request(i);}

//Send telemetry command
void networking::send_telemetry_command(int i){ emit telemetry_command(i);}

//Send manual targeting
void networking::send_targeting(float lat, float longi, float alt){emit targeting(lat,longi,alt);}

//UAV drop
void networking::UDrop(int v) { emit drop(v); }

//UAV arm
void networking::arm(int x) { emit armUAV(x); }

//UAV disarm
void networking::disarm(int x) { emit disarmUAV(x); }

//targeting
void networking::target(float lat, float longi, float alt) {emit manTargeting(lat,longi,alt);}

void networking::newTarget(float lat,float longi) { emit vTarget(lat,longi);}

//To update displayed target location on map
//void networking::update_target_disp(Target* target) { emit newTarget(target);}

//Network update setup settings
void networking::network_serial_set(QString serial) {
    messageAlert(QString("Changing Serial Port to " + serial));
    emit network_set_serial(serial); }

//UGV joystick
//void networking::start_UGV_Joystick() { emit UGV_joystick_start();}

//void networking::stop_UGV_Joystick() { emit UGV_joystick_stop();}

//UGV state
void networking::ManualToAuto() {emit MTA();}

void networking::AutoToManual() {emit ATM();}

void networking::Reset(){ emit R(); }

//UGV Motor
void networking::DisableMotor() {emit DisableM();}

void networking::EnableMotor() { emit EnableM(); }

void networking::ToggleMotor() { emit ToggleM(); }

//Vehicle state
void networking::vStatus(int vech, int state) { emit vehicleStatus(vech, state);}

//Message console log
void networking::messageSlot(QString messageString) { emit message(messageString); }

void networking::messageAlertSlot(QString messageString) { emit messageAlert(messageString); }

void networking::messageConfirmSlot(QString messageString) {emit messageConfirm(messageString); }

networking::~networking()
{
   //std::cout << "In networking deconstructor" << std::endl;
   network_thread ->exit();
}


