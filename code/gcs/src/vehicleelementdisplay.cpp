#include "vehicleelementdisplay.h"

VehicleElementDisplay::VehicleElementDisplay(QWidget *parent) :
    QWidget(parent)
{
    imgTemp = new QWidget(this);
    imgTemp->setGeometry(0,0,300,100);
    QPalette Pal(palette());

    // set black background
    Pal.setColor(QPalette::Background, Qt::black);
    imgTemp->setAutoFillBackground(true);
    imgTemp->setPalette(Pal);

    VehicleType = new QLabel();
    VehicleNo = new QLabel();
    VehicleStatus = new QLabel();

    vehicleLayout = new QGridLayout();
    vehicleLayout->addWidget(VehicleType,0,0);
    vehicleLayout->addWidget(VehicleNo,0,1);

    infoLayout = new QGridLayout();
    infoLayout->addLayout(vehicleLayout,0,0);
    infoLayout->addWidget(VehicleStatus,1,0);

    mainLayout = new QGridLayout();
    mainLayout->setMargin(0);
    mainLayout->addWidget(imgTemp,0,0);
    mainLayout->addLayout(infoLayout,0,1);

    VehicleType->setText("UAV");
    VehicleNo->setText("69");
    VehicleStatus->setText("Collision Avoidence");

    setLayout(mainLayout);

}

void VehicleElementDisplay::setID(int vechID){
    id = vechID;
}

int VehicleElementDisplay::getID(){
    return vechicle->getVehicleID();
}

void VehicleElementDisplay::updateDisplay(int vechID){
   if(vechID == id){
       //Update display with information
   }
}

void VehicleElementDisplay::setVehicle(Vehicle22* vech){
    vechicle = vech;
}

void VehicleElementDisplay::update(){
    switch(vechicle->getMode())
    {
        case 0:
            VehicleStatus->setText("Startup");
            break;

        case 1:
            VehicleStatus->setText("Manual Mode");
            break;
        case 2:
            VehicleStatus->setText("Assisted Mode");
            break;

        case 3:
            VehicleStatus->setText("Autonomous Mode");
            break;

        case 4:
            VehicleStatus->setText("Collision Avoidence Mode");
            break;

        case 5:
             VehicleStatus->setText("Seek & Destroy");
             break;

        default:
            VehicleStatus->setText("Unknown Status Recieved");

    }
}

VehicleElementDisplay::~VehicleElementDisplay(){
}
