#include "vehicleauthorizationgui.h"

VehicleAuthorizationGUI::VehicleAuthorizationGUI(QWidget *parent) :
    QWidget(parent)
{
    //Creates Layout
    mainLayout = new QGridLayout();
    //Sets Margin
    mainLayout->setMargin( 0 );
    //Creates button to send vehicle ID
    Authorization = new QPushButton();
    //Sets text for button
    Authorization->setText("Send Authorizaiton");
    //Create user input for ID
    vehicle = new QLineEdit();
    //Add button and user input to layout
    mainLayout->addWidget(Authorization,1,0);
    mainLayout->addWidget(vehicle,1,1);
    //Sets widget's layout to layout created
    setLayout( mainLayout );
    //If the button is pressed, activate the slot to send the vehicle ID as a signal
    connect(Authorization,SIGNAL(clicked()),this,SLOT(send_authorization()));

}
/**
 * @brief VehicleAuthorizationGUI::send_authorization Emits signal containing the vehicle ID to ask for authorization
 */
void VehicleAuthorizationGUI::send_authorization()
{
    emit authorize(vehicle->text().toInt());
}
