#include "waypointgui.h"
#include <QDebug>

WaypointGUI::WaypointGUI(QWidget *parent, Vehicle22* vech) :
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
    //Create button to send
    WaypointB = new QPushButton();
    //Label button
    WaypointB->setText("Send Waypoint");
    //Create User input for vehicle ID
    vehicle = new QLineEdit();
    //Set text for mouse over
    vehicle->setToolTip("Vehicle");
    //Create User input for latitude
    latitude = new QLineEdit();
    //Set text for mouse over
    latitude->setToolTip("Latitude");
    //Create user input for longitude
    longitude = new QLineEdit();
    //Set text for mouse over
    longitude->setToolTip("Longitude");
    //Create user input for altitude
    altitude = new QLineEdit();
    //Set text for mouse over
    altitude->setToolTip("Altitude");
    //Create user input for heading
    heading = new QLineEdit();
    //Set text for mouse over
    heading->setToolTip("Heading");
    //Create user input for waypoint id
    id = new QLineEdit();
    //Set text for mouse over
    id->setToolTip("ID");
    //Create user input for waypoint type
    type = new QLineEdit();
    //Set text for mouse over
    type->setToolTip("Type");

    //Create labels to notify user of what input is for
    vIDLabel = new QLabel("VehicleID");
    wIDLabel = new QLabel("WaypointID");
    typeLabel = new QLabel("Type");
    latLabel = new QLabel("Lat");
    lonLabel = new QLabel("Lon");
    altLabel = new QLabel("Alt");
    headingLabel = new QLabel("Heading");

    //Add widgets to layout
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

    //Set Widget layout
    setLayout( mainLayout );
    //Connect button press to send information for waypoint
    connect(WaypointB,SIGNAL(clicked()),this,SLOT(send_waypoint()));
    v = vech;
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
                         altitude->text().toFloat(),
                         0);

    mutex.lock();
    //old way of appending waypoint
    //v->appendWaypoint(w, Qt::green );
    mutex.unlock();
    qDebug() << "Vehicle" << vehicle->text();
    qDebug() << "id" << id->text();
    emit waypoint(vehicle->text().toInt(),id->text().toInt(),type->text().toInt(),latitude->text().toFloat(),longitude->text().toFloat(),altitude->text().toFloat());
    //we will append the waypoint in mainwindow.cpp
    emit addWaypoint(id->text().toInt(),w);
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
