#include "networking.h"
/**
 * @brief networking::invokeThread Creates thread
 * @param node_id ID of node (GCS is 1)
 * @param self_port UDP port for recieveing
 * @param dest_port UDP port for sending
 */
void networking::invokeThread(uint8_t node_id, uint16_t self_port, uint16_t dest_port)
{
    //create new thread
    network_thread = new QThread;
    //Create class to put in thread
    QString serial = "a";
    rx = new rx_thread(node_id,7990, 7991,serial);
    //Put class in thread
    rx->moveToThread(network_thread);
    //Mapp error strings
    //connect(rx, SIGNAL(error(QString)), this, SLOT(errorString(QString)));
    //If thread started then start process in class
    connect(network_thread, SIGNAL(started()), rx, SLOT(process()));
    //when process is finished, quit network_thread
    connect(rx, SIGNAL(finished()), network_thread, SLOT(quit()));
    //when process is finished, set object to delete later
    connect(rx, SIGNAL(finished()), rx, SLOT(deleteLater()));
    //when network_thread is finished set to delete later
    connect(network_thread, SIGNAL(finished()), network_thread, SLOT(deleteLater()));

    //Send messages
    connect(this,SIGNAL(ping()),rx,SLOT(send_ping()));
    connect(this,SIGNAL(sendGPS()),rx,SLOT(GPS()));

    //Updating netowrk set up
    connect(this,SIGNAL(network_set_serial(QString)),rx,SLOT(setNetworkSerial(QString)));

    network_thread->start();
}

/**
 * @brief networking::networking creates the thread to handle comnet messages
 */
networking::networking()
{
    //qDebug() << "Invoking thread with: " << port;
    invokeThread(69, 7990, 7991);
}

//Network send message signal/slots
void networking::send_ping(){ emit ping(); }

//Send dummy global position for specific vehicle ID
void networking::send_GPS() { emit sendGPS(); }

//Change serial port
void networking::network_serial_set(QString serial) { emit network_set_serial(serial); }

networking::~networking()
{
   //std::cout << "In networking deconstructor" << std::endl;
   network_thread ->exit();
}


//Unused user commands
/*
 *
//TEST GUI FUNCTIONS
void networking::send_waypoint(int x){ emit waypoint(x); }

void networking::send_vehicle_auth_request(int i){ emit vehicle_auth_request(i);}

void networking::send_telemetry_command(int i){ emit telemetry_command(i);}

void networking::send_targeting(int i){emit targeting(i);}

//UAV drop
void networking::UDrop(int v) { emit drop(v); }

//UAV arm
void networking::arm(int x) { emit armUAV(x); }

//UAV disarm
void networking::disarm(int x) { emit disarmUAV(x); }

//targeting
void networking::target(float lat, float longi, float alt) {emit manTargeting(lat,longi,alt);}

void networking::newTarget(float lat,float longi) { emit vTarget(lat,longi);}

//Network update setup settings

//Vehicle state
void networking::vStatus(int vech, int state) { emit vehicleStatus(vech, state);}

*/

//Unused connects for user commands
/*
    connect(this,SIGNAL(waypoint(int)), rx,SLOT(send_vehicle_waypoint(int)));
    connect(this,SIGNAL(telemetry_command(int)),rx,SLOT(send_telemetry_command(int)));
    connect(this,SIGNAL(vehicle_auth_request(int)),rx,SLOT(send_vehicle_auth_request(int)));

    //Update vehicle update queue
   //vehicle
    connect(rx,SIGNAL(sendTarget(float,float)),this,SLOT(newTarget(float,float)));
    //UAV arm/disarm
    connect(this,SIGNAL(armUAV(int)),rx,SLOT(arm_uav(int)));
    connect(this,SIGNAL(disarmUAV(int)),rx,SLOT(disarm_uav(int)));

    //UAV Drop
    connect(this,SIGNAL(drop(int)),rx,SLOT(drop(int)));

    //UAV targeting
    connect(this,SIGNAL(manTargeting(float,float,float)),rx,SLOT(send_manTargeting(float,float,float)));

*/

