#include "networking.h"
/**
 * @brief networking::invokeThread Creates thread for protonet messages
 * @param q NODE QUEUE (will need to remove after transfer to new signal is complete)
 * @param v vehicle list
 * @param tgt Holds targets
 * @param node_id  GCS NODE ID (1)
 * @param self_port UDP port to recieve protonet messages
 * @param dest_port UDP port to send protonet messages
 */
void networking::invokeThread(uint8_t node_id, uint16_t self_port, uint16_t dest_port)
{
    //create new thread
    network_thread = new QThread;
    //Create class to put in thread
    rx = new rx_thread(node_id,self_port, dest_port);
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
    connect(this,SIGNAL(ping()),rx,SLOT(send_ping()));

    //Update vehicle update queue (OLD NEED TO REMOVE DEPENDENCY)
    connect(rx,SIGNAL(update_queue()),this,SLOT(update_vehicle_queue()));

    //New Vehicle Information recieved
    connect(rx,SIGNAL(updateVech(int)),this,SLOT(updateVech(int)));

    //Update displayed vehicle target
    connect(rx,SIGNAL(sendTarget(float,float)),this,SLOT(newTarget(float,float)));

    //Displays UAV status
    connect(rx,SIGNAL(vechStatus(int,int)),this,SLOT(vStatus(int,int)));

    //UGV joystick
    connect(this,SIGNAL(UGV_joystick_start()), rx,SLOT(start_UGV_Joystick()));
    connect(this,SIGNAL(UGV_joystick_stop()),rx,SLOT(stop_UGV_Joystick()));

    //Updating netowrk set up
    connect(this,SIGNAL(network_set_serial(QString)),rx,SLOT(setNetworkSerial(QString)));

    //Console log messages
    connect(rx,SIGNAL(message(QString)),this,SLOT(messageSlot(QString)));
    connect(rx,SIGNAL(messageAlert(QString)),this,SLOT(messageAlertSlot(QString)));
    connect(rx,SIGNAL(messageConfirm(QString)),this,SLOT(messageConfirmSlot(QString)));


    connect(rx,SIGNAL(authorizeReq()),this,SLOT(vechAuthReq()));
    connect(rx,SIGNAL(telemetryReq()),this,SLOT(vechTeleReq()));

    network_thread->start();




    gpsGenny = new GPSGen(46);
    gpsGen_thread = new QThread();
    gpsGenny->moveToThread(gpsGen_thread);

    connect(gpsGen_thread, SIGNAL(started()), gpsGenny,SLOT(generateGPS()));
    //when process is finished, quit gpsGen_thread
    connect(gpsGenny, SIGNAL(finished()), gpsGen_thread, SLOT(quit()));
    //when process is finished, set object to delete later
    connect(gpsGenny, SIGNAL(finished()), gpsGenny, SLOT(deleteLater()));
    //when gpsGen_thread is finished set to delete later
    connect(gpsGen_thread, SIGNAL(finished()), gpsGen_thread, SLOT(deleteLater()));

    //GPS pos for testing
    connect(gpsGenny,SIGNAL(gpsMSG(int,double,double,double,double,double,double,double)),
            rx,SLOT(send_global_position(int,double,double,double,double,double,double,double)));


}
/**
 * @brief networking::networking invokes the thread to handle protonet messages
 */
networking::networking()
{
    //qDebug() << "Invoking thread with: " << port;
    invokeThread(46, 7990, 7991);
}

//Network send message signal/slots
void networking::send_ping(){ emit ping(); }

//Update Vehicle (OLD NEED TO REMOVE DEPENDENCY)
void networking::update_vehicle_queue() { emit update_queue(); }

//Update Vehicle with given ID
void networking::updateVech(int ID) {emit updateVechicle(ID); }

//Send vehicle authorization request to vehicle i
void networking::send_vehicle_auth_request(int i){ emit vehicle_auth_request(i);}

//Send telemetry command
void networking::send_telemetry_command(int i){ emit telemetry_command(i);}

//Send manual targeting
void networking::send_targeting(float lat, float longi, float alt){emit targeting(lat,longi,alt);}

//targeting
void networking::target(float lat, float longi, float alt) {emit manTargeting(lat,longi,alt);}

void networking::newTarget(float lat,float longi) { emit vTarget(lat,longi);}

//Network update setup settings
void networking::network_serial_set(QString serial) {
    messageAlert(QString("Changing Serial Port to " + serial));
    emit network_set_serial(serial);
}

//Vehicle state
void networking::vStatus(int vech, int state) { emit vehicleStatus(vech, state);}

//Message console log
void networking::messageSlot(QString messageString) { emit message(messageString); }

void networking::messageAlertSlot(QString messageString) { emit messageAlert(messageString); }

void networking::messageConfirmSlot(QString messageString) { emit messageConfirm(messageString); }

void networking::sendGPS()
{
    gpsGen_thread->start();
}

void networking::vechAuthReq()
{
    emit vechAuthRequest();
}

void networking::vechTeleReq()
{
    emit vechTeleRequest();
}

networking::~networking()
{
   //std::cout << "In networking deconstructor" << std::endl;
   network_thread ->exit();
}


