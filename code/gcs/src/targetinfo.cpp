#include "targetinfo.h"
#include "qdebug.h"

TargetInfo::TargetInfo(QWidget *parent) :
    QMainWindow(parent){

    QWidget *window = new QWidget;

    info = new QGridLayout();
    info->setVerticalSpacing(0);
    info->setContentsMargins(0,0,0,0);

    vehicleID = new QLabel("Vehicle ID", this);
    payloadID = new QLabel("Payload ID", this);
    targetID = new QLabel("Target ID", this);
    targetType = new QLabel("Target Type", this);
    latitude = new QLabel("Target Latitude", this);
    longitude = new QLabel("Target Longitude", this);
    altitude = new QLabel("Target Altitude",this);

    vechUp = new QLabel("Not set");
    payUp = new QLabel("Not set");
    targUp = new QLabel("Not set");
    typeUp = new QLabel("Not set");
    latUp = new QLabel("Not set");
    lonUp = new QLabel("Not set");
    altUp = new QLabel("Not set");

    info->addWidget(vehicleID, 0, 0);
    info->addWidget(payloadID, 1, 0);
    info->addWidget(targetID, 2, 0);
    info->addWidget(targetType, 3, 0);
    info->addWidget(latitude, 4, 0);
    info->addWidget(longitude, 5, 0);
    info->addWidget(altitude, 6, 0);

    info->addWidget(vechUp, 0, 1);
    info->addWidget(payUp, 1, 1);
    info->addWidget(targUp, 2, 1);
    info->addWidget(typeUp, 3, 1);
    info->addWidget(latUp, 4, 1);
    info->addWidget(lonUp, 5, 1);
    info->addWidget(altUp, 6, 1);

    window->setLayout(info);
    setCentralWidget(window);
}

// Display updated information about the target
void TargetInfo::tStatus(int tID) {
    Target *t = tl->getTarget(tID);
    // Updated vehicle must match currently selected vehicle
    if (currentTarget == tID) {
        vechUp->setText(QString::number(tID));
        payUp->setText(QString::number(t->getPayloadID()));
        targUp->setText(QString::number(t->getTargetID()));
        typeUp->setText(QString::number(t->getTargetType()));
        latUp->setText(QString::number(t->getLatitude()));
        lonUp->setText(QString::number(t->getLongitude()));
        altUp->setText(QString::number(t->getAltitude()));
    }
}

void TargetInfo::displayTargetInfo(int tID) {
    if(tl->inList(tID)){
        currentTarget = tID;
        Target *t = tl->getTarget(tID);
        vechUp->setText(QString::number(t->getVehicleID()));
        payUp->setText(QString::number(t->getPayloadID()));
        targUp->setText(QString::number(t->getTargetID()));
        typeUp->setText(QString::number(t->getTargetType()));
        latUp->setText(QString::number(t->getLatitude()));
        lonUp->setText(QString::number(t->getLongitude()));
        altUp->setText(QString::number(t->getAltitude()));
    }
    else
        vechUp->setText(QString::number(tID));
}

void TargetInfo::getList(TargetList *t) {
    tl = t;
}

TargetInfo::~TargetInfo(){

}

