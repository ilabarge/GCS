#include "waypointgui.h"
#include <QDebug>

WaypointGUI::WaypointGUI(QWidget *parent) :
    QWidget(parent)
{
    /* Type defn
        0 insert
        1 edit
        2 erase
    */
    //Create layout
    mainLayout = new QGridLayout();
    //Set margins
    mainLayout->setMargin( 0 );
    initGUIElements();
    setGUIElementText();
    addGUIElementToLayout();
    //Set Widget layout
    setLayout( mainLayout );
    //Connect button press to send information for waypoint
    connect(WaypointB,SIGNAL(clicked()),this,SLOT(send_waypoint()));
}
/**
 * @brief WaypointGUI::send_waypoint sends waypoint baised off of user input from text fields
 */
void WaypointGUI::send_waypoint()
{
    Waypoint22* w = new Waypoint22(id->text().toInt(),
                         type->text().toInt(),
                         latitude->text().toDouble(),
                         longitude->text().toDouble(),
                         altitude->text().toInt(),
                         0);

    mutex.lock();
    mutex.unlock();
    emit waypoint(w, vehicle->text().toInt());
}

/**
 * @brief WaypointGUI::coordDesignated Adds waypoint to display
 * @param lat Latitude of waypoint
 * @param lon Longitude of waypoint
 */
void WaypointGUI::coordDesignated(double lat, double lon){
    latitude->setText(QString("%1").arg(lat, 0, 'f'));
    longitude->setText(QString("%1").arg(lon, 0, 'f'));
}

/**
 * @brief WaypointGUI::initGUIElements Init GUI elements
 */
void WaypointGUI::initGUIElements()
{
    //Create button to send
    WaypointB = new QPushButton();
    //Create User input for vehicle ID
    vehicle = new QLineEdit();
    //Create User input for latitude
    latitude = new QLineEdit();
    //Create user input for longitude
    longitude = new QLineEdit();
    //Create user input for altitude
    altitude = new QLineEdit();
    //Create user input for heading
    heading = new QLineEdit();
    //Create user input for waypoint id
    id = new QLineEdit();
    //Create user input for waypoint type
    type = new QLineEdit();
    //Create labels to notify user of what input is for
    vIDLabel = new QLabel("VehicleID");
    wIDLabel = new QLabel("WaypointID");
    typeLabel = new QLabel("Type");
    latLabel = new QLabel("Lat");
    lonLabel = new QLabel("Lon");
    altLabel = new QLabel("Alt");
    headingLabel = new QLabel("Heading");
}

/**
 * @brief WaypointGUI::setGUIElementText Set text for elements
 */
void WaypointGUI::setGUIElementText()
{
    WaypointB->setText("Send Waypoint");
    //Set text for mouse over
    vehicle->setToolTip("Vehicle");
    latitude->setToolTip("Latitude");
    longitude->setToolTip("Longitude");
    altitude->setToolTip("Altitude");
    heading->setToolTip("Heading");
    id->setToolTip("ID");
    type->setToolTip("Type");
}

/**
 * @brief WaypointGUI::addGUIElementToLayout add widigets in wayout
 */
void WaypointGUI::addGUIElementToLayout()
{
    mainLayout->addWidget(WaypointB,1,0);
    mainLayout->addWidget(vIDLabel, 1, 1);
    mainLayout->addWidget(vehicle,1,2);
    mainLayout->addWidget(wIDLabel,1,3);
    mainLayout->addWidget(id,1,4);
    mainLayout->addWidget(typeLabel,1,5);
    mainLayout->addWidget(type,1,6);
    mainLayout->addWidget(latLabel,1,7);
    mainLayout->addWidget(latitude,1,8);
    mainLayout->addWidget(lonLabel,1,9);
    mainLayout->addWidget(longitude,1,10);
    mainLayout->addWidget(altLabel,1,11);
    mainLayout->addWidget(altitude,1,12);
    mainLayout->addWidget(headingLabel,1,13);
    mainLayout->addWidget(heading,1,14);
}
