#include "uavpayload.h"

UAVPayload::UAVPayload(QWidget *parent) :
    QWidget(parent)
{
    //Create Layout
    mainLayout = new QGridLayout();
    //Create button to arm uav
    arming = new QPushButton();
    //Create button to disarm uav
    disarming = new QPushButton();
    //Label buttons respectively
    arming->setText("Arm UAV");
    disarming->setText("Disarm UAV");
    //Add the buttons so that they are horizontally next to each other
    mainLayout->addWidget(arming,0,0);
    mainLayout->addWidget(disarming,0,1);
    //Set widget layout as created layout
    setLayout(mainLayout);
    //Connect butons to send arming/disarming to statically set uav ID
    connect(arming,SIGNAL(clicked()),this,SLOT(armvech()));
    connect(disarming,SIGNAL(clicked()),this,SLOT(disarmvech()));
}
/**
 * @brief UAVPayload::armvech arms staticlaly set UAV to drop payload
 */
void UAVPayload::armvech() { emit arm(69); }

/**
 * @brief UAVPayload::disarmvech disarms staticaly set UAV to not drop payload
 */
void UAVPayload::disarmvech() {emit disarm(69); }
