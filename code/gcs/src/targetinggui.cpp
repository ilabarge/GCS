#include "targetinggui.h"
#include <QLabel>
#include <QDebug>

targetingGUI::targetingGUI(QWidget *parent) :
    QWidget(parent)
{
    //Create layout
    mainLayout = new QGridLayout();

    initGUIElements();
    setGUIElementText();
    addGUIElementToLayout();
    //Set widget layout
    setLayout(mainLayout);

    //If button is pressed, we activate the slot which sends the values stored in the user input
    connect(targets,SIGNAL(clicked()),this,SLOT(targetsend()));
}

/**
 * @brief targetingGUI::targetsend Upon button press, we send the entered latitude, longitude and altitude as a signal
 */
void targetingGUI::targetsend()
{
    emit target(latitude->text().toFloat(),longitude->text().toFloat(),altitude->text().toFloat());
}

void targetingGUI::initGUIElements()
{
    //Create button to send information
    targets = new QPushButton();
    //Create user inputs for latitude, longitude and altitude
    latitude = new QLineEdit();
    longitude = new QLineEdit();
    altitude = new QLineEdit();
    lat = new QLabel();
    longi = new QLabel();
    alt = new QLabel();
}

void targetingGUI::setGUIElementText()
{
    targets->setText("Send Target");
    //Labels mouse overs for user input
    latitude->setToolTip("Latitude");
    longitude->setToolTip("Longitude");
    altitude->setToolTip("Altitude");
    lat->setText("Latitude");
    longi->setText("Longitude");
    alt->setText("Altitude");
}

void targetingGUI::addGUIElementToLayout()
{
    mainLayout->addWidget(targets,0,0);
    mainLayout->addWidget(lat,0,1);
    mainLayout->addWidget(latitude,0,2);
    mainLayout->addWidget(longi,0,3);
    mainLayout->addWidget(longitude,0,4);
    mainLayout->addWidget(alt,0,5);
    mainLayout->addWidget(altitude,0,6);
}
