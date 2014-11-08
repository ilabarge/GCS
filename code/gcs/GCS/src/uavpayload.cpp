#include "uavpayload.h"

UAVPayload::UAVPayload(QWidget *parent) :
    QWidget(parent)
{
    mainLayout = new QGridLayout();
    arming = new QPushButton();
    disarming = new QPushButton();
    arming->setText("Arm UAV");
    disarming->setText("Disarm UAV");
    mainLayout->addWidget(arming,0,0);
    mainLayout->addWidget(disarming,0,1);
    setLayout(mainLayout);
    connect(arming,SIGNAL(clicked()),this,SLOT(armvech()));
    connect(disarming,SIGNAL(clicked()),this,SLOT(disarmvech()));
}

void UAVPayload::armvech() { emit arm(69); }

void UAVPayload::disarmvech() {emit disarm(69); }
