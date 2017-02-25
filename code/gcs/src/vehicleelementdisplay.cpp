#include "vehicleelementdisplay.h"

VehicleElementDisplay::VehicleElementDisplay(QWidget *parent) :
    QWidget(parent)
{
    //imgTemp = new QWidget(this);
    //imgTemp->setGeometry(0,0,300,100);
    //QPalette Pal(palette());

    // set black background
    //Pal.setColor(QPalette::Background, Qt::black);
    //imgTemp->setAutoFillBackground(true);
    //imgTemp->setPalette(Pal);

    VehicleType = new QLabel();
    VehicleNo = new QLabel();
    VehicleStatus = new QLabel();

    vehicleLayout = new QGridLayout();
    vehicleLayout->setMargin(0);
    vehicleLayout->addWidget(VehicleType,0,0);
    vehicleLayout->addWidget(VehicleNo,0,1);

    infoLayout = new QGridLayout();
    infoLayout->setMargin(0);
    infoLayout->addLayout(vehicleLayout,0,0);
    infoLayout->addWidget(VehicleStatus,0,1);



    VehicleType->setText("VEHICLE_TYPE");
    VehicleNo->setText("VEHICLE_ID");
    VehicleStatus->setText("Unknown State");

    mainLayout = new QGridLayout();
    mainLayout->setMargin(10);
    //mainLayout->addWidget(imgTemp,0,0);
    mainLayout->addLayout(infoLayout,0,0);
    vehicleSelect = new QPushButton();
    vehicleSelect->setLayout(mainLayout);
    vehicleSelect->setMaximumHeight(50);
    vehicleSelect->setMinimumWidth(200);

    QGridLayout *element = new QGridLayout();
    element->addWidget(vehicleSelect);
    element->setMargin(0);
    connect(vehicleSelect,SIGNAL(clicked()), this,SLOT(vehicleClick()));
    setLayout(element);
}

void VehicleElementDisplay::setID(int vechID){
    id = vechID;
    VehicleNo->setText(QString::number(id));
}

int VehicleElementDisplay::getID(){
    return vechicle->getVehicleID();
}

void VehicleElementDisplay::setText(){
    if(vechicle->getVehicleType() == 0){
        if(vechicle->getVehicleID() == 101)
            VehicleType->setText("Telemaster");
        else if(vechicle->getVehicleID() == 69)
            VehicleType->setText("Sigkadet");
        else if(vechicle->getVehicleID() == 102)
            VehicleType->setText("QUAD 1");
        else
            VehicleType->setText("QUAD 2");
    }else if(vechicle->getVehicleType() == 1){
        VehicleType->setText("UGV");
    }else if(vechicle->getVehicleType() == 2){
        VehicleType->setText("UUV");
    }
    else {
        VehicleType->setText("ROV");
    }
    VehicleNo->setText(QString::number(vechicle->getVehicleID()));
}

void VehicleElementDisplay::updateDisplay(int vechID){
   if(vechID == id){
       //Update display with information
       update();
   }
}

/**
 * @brief VehicleElementDisplay::setVehicle
 * Sets the vehicle to display
 * @param vech
 * Vehicle pointer that points to the data to display.
 */
void VehicleElementDisplay::setVehicle(Vehicle22* vech){
    id = vech->getVehicleID();
    vechicle = vech;
    VehicleNo->setText(QString::number(id));
    //Call update to update the status of the vehicle
    update();
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

void VehicleElementDisplay::vehicleClick(){
    emit vechID(id);
}

VehicleElementDisplay::~VehicleElementDisplay(){
}
