#include "vehicleauthorizationgui.h"

VehicleAuthorizationGUI::VehicleAuthorizationGUI(QWidget *parent) :
    QWidget(parent)
{
    mainLayout = new QGridLayout();
    mainLayout->setMargin( 0 );
    Authorization = new QPushButton();
    Authorization->setText("Send Authorizaiton");
    vehicle = new QLineEdit();
    mainLayout->addWidget(Authorization,1,0);
    mainLayout->addWidget(vehicle,1,1);
    setLayout( mainLayout );
    connect(Authorization,SIGNAL(clicked()),this,SLOT(send_authorization()));

}
/**
 * @brief VehicleAuthorizationGUI::send_authorization Emits signal containing the vehicle ID to ask for authorization
 */
void VehicleAuthorizationGUI::send_authorization()
{
    emit authorize(vehicle->text().toInt());
}
