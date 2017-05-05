#include "vehicleinfo.h"

VehicleInfo::VehicleInfo(QWidget *parent) :
    QMainWindow(parent){

    QWidget *window = new QWidget;

    infoType = new QGridLayout();
    infoType->setVerticalSpacing(0);
    infoType->setContentsMargins(0,0,0,0);

    vehicleID = new QLabel("Vehicle ID",this);
    vehicleType = new QLabel("Vehicle Type",this);
    altitude = new QLabel("Altitude",this);
    mode = new QLabel("Mode",this);
    state = new QLabel("State",this);
    latitude = new QLabel("Latitude",this);   
    longitude = new QLabel("Longitude",this);
    heading = new QLabel("Heading",this);
    velocity = new QLabel("Velocity",this);
    depth = new QLabel("Depth",this);

    idUp = new QLabel("Not set");
    typeUp = new QLabel("Not set");
    altUp = new QLabel("Not set");
    modeUp = new QLabel("Not set");
    stateUp = new QLabel("Not set");
    latUp = new QLabel("Not set");
    longUp = new QLabel("Not set");
    headingUp = new QLabel("Not set");
    velocityUp = new QLabel("Not set");
    depthUp = new QLabel("Not set");

    //    vehicleID->setStyleSheet("QLabel { background-color : red; }");
    //    vehicleType->setStyleSheet("QLabel { background-color : blue; }");
    //    idUp->setStyleSheet("QLabel { background-color : blue; }");
    //    typeUp->setStyleSheet("QLabel { background-color : red; }");


    //QSpacerItem *verticalSpacer = new QSpacerItem(100,20,QSizePolicy::Minimum);
    //infoType->addItem(verticalSpacer,0,0,Qt::AlignTop);

    infoType->addWidget(vehicleID, 0, 0);
    infoType->addWidget(vehicleType, 1, 0);
    infoType->addWidget(altitude, 2, 0);
    infoType->addWidget(mode, 3, 0);
    infoType->addWidget(state, 4, 0);
    infoType->addWidget(latitude, 5, 0);
    infoType->addWidget(longitude, 6, 0);
    infoType->addWidget(heading, 7, 0);
    infoType->addWidget(velocity, 8, 0);
    infoType->addWidget(idUp, 0, 1);
    infoType->addWidget(typeUp, 1, 1);
    infoType->addWidget(altUp, 2, 1);
    infoType->addWidget(modeUp, 3, 1);
    infoType->addWidget(stateUp, 4, 1);
    infoType->addWidget(latUp, 5, 1);
    infoType->addWidget(longUp, 6, 1);
    infoType->addWidget(headingUp, 7, 1);
    infoType->addWidget(velocityUp, 8, 1);
    infoType->addWidget(depth,9,0);
    infoType->addWidget(depthUp,9,1);

    window->setLayout(infoType);
    setCentralWidget(window);
}

// Display updated information about a vehicle
void VehicleInfo::status(int vID) {
    Vehicle22 *vp = vl->get(vID);
    // Updated vehicle must match currently selected vehicle
    if (currentVehicle == vID) {
        idUp->setText(QString::number(vID));
        typeUp->setText(QString::number(vp->getVehicleType()));
        altUp->setText( QString("%1").QString::number(vp->getAltitude()));
        modeUp->setText(QString::number(vp->getMode()));
        stateUp->setText(QString::number(vp->getState()));
        latUp->setText(QString("%1").QString::number(vp->getLatitude()));
        longUp->setText(QString("%1").QString::number(vp->getLongitude()));
        headingUp->setText(QString("%1").QString::number(vp->getHeading()));
        velocityUp->setText(QString("%1").QString::number(vp->getVelocity()));
        depthUp->setText(QString::number(vp->getDepth()));
    }
}

void VehicleInfo::displayVech(int vID) {
    currentVehicle = vID;
    Vehicle22 *vp = vl->get(vID);
    idUp->setText(QString::number(vID));
    typeUp->setText(QString::number(vp->getVehicleType()));
    altUp->setText(QString("%1").QString::number(vp->getAltitude()));
    modeUp->setText(QString::number(vp->getMode()));
    stateUp->setText(QString::number(vp->getState()));
    latUp->setText(QString("%1").QString::number(vp->getLatitude()));
    longUp->setText(QString("%1").QString::number(vp->getLongitude()));
    headingUp->setText(QString("%1").QString::number(vp->getHeading()));
    velocityUp->setText(QString("%1").QString::number(vp->getVelocity()));
    depthUp->setText(QString::number(vp->getDepth()));

}

void VehicleInfo::getList(vehicle_list *p) {
    vl = p;
}

VehicleInfo::~VehicleInfo(){

}
