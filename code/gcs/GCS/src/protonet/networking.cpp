#include "networking.h"

void networking::invokeThread(NodeQueue* q, QVector<Vehicle22*>* v, TargetList* tgt,uint8_t node_id, uint16_t self_port, uint16_t dest_port)
{
    //create new thread
    network_thread = new QThread;
    //Create class to put in thread
    rx = new rx_thread(node_id,self_port, dest_port, v,q,tgt);
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
    connect(this,SIGNAL(ping(int)),rx,SLOT(send_ping(int)));

    //Send waypoint command
    connect(this,SIGNAL(waypoint(int vehicle, int pos, int type, float lat, float longi, float alt)), rx,SLOT(send_vehicle_waypoint(int, int, int, float, float, float)));

    //Vehicle Telemetry Command
    //Begin the telemetry stream from vehicle
    connect(this,SIGNAL(telemetry_command(int)),rx,SLOT(send_telemetry_command(int)));

    //Vehicle Auhorization request
    //To allow C&C over vehicle
    connect(this,SIGNAL(vehicle_auth_request(int)),rx,SLOT(send_vehicle_auth_request(int)));

    //Update vehicle update queue
    connect(rx,SIGNAL(update_queue()),this,SLOT(update_vehicle_queue()));

    //Update the location of the target found
    connect(rx,SIGNAL(newTarget(Target*)),this,SLOT(update_target_disp(Target*)));

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
    //Reset UGV state
    connect(this,SIGNAL(R()),rx,SLOT(Reset()));

    //UGV Motor State
    connect(this,SIGNAL(DisableM()),rx,SLOT(DisableMotor()));
    connect(this,SIGNAL(EnableM()),rx,SLOT(EnableMotor()));
    connect(this,SIGNAL(ToggleM()),rx,SLOT(ToggleMotor()));

    //UGV joystick
    connect(this,SIGNAL(UGV_joystick_start()), rx,SLOT(start_UGV_Joystick()));
    connect(this,SIGNAL(UGV_joystick_stop()),rx,SLOT(stop_UGV_Joystick()));

    //Updating netowrk set up
    connect(this,SIGNAL(network_set_serial(QString)),rx,SLOT(setNetworkSerial(QString)));

    network_thread->start();
}

networking::networking(QVector<Vehicle22*>* v, NodeQueue *q, TargetList* targ)
{
    //qDebug() << "Invoking thread with: " << port;
    invokeThread(q,v,targ,1, 7991, 7990);
}

//Network send message signal/slots
void networking::send_ping(int id){ emit ping(id); }

void networking::update_vehicle_queue() { emit update_queue(); }

//Sending waypoint
void networking::send_waypoint(int vehicle, int pos, int type, double lat, double longi, double alt){ emit waypoint( vehicle, pos, type, lat, longi,alt); }

void networking::send_vehicle_auth_request(int i){ emit vehicle_auth_request(i);}

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
void networking::update_target_disp(Target* target) { emit newTarget(target);}

//Network update setup settings
void networking::network_serial_set(QString serial) { emit network_set_serial(serial); }

//UGV joystick
void networking::start_UGV_Joystick() { emit UGV_joystick_start();}

void networking::stop_UGV_Joystick() { emit UGV_joystick_stop();}

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

networking::~networking()
{
   //std::cout << "In networking deconstructor" << std::endl;
   network_thread ->exit();
}


