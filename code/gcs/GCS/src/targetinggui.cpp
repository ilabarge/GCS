#include "targetinggui.h"
#include <QLabel>
#include <QDebug>

targetingGUI::targetingGUI(QWidget *parent) :
    QWidget(parent)
{
    //Initialize and set up user input and buttons
    mainLayout = new QGridLayout();
    targets = new QPushButton();
    targets->setText("Send Target");
    latitude = new QLineEdit();
    longitude = new QLineEdit();
    altitude = new QLineEdit();

    //Creates and sets labels
    QLabel* lat = new QLabel();
    lat->setText("Latitude");
    QLabel* longi = new QLabel();
    longi->setText("Longitude");
    QLabel* alt = new QLabel();
    alt->setText("Altitude");

    //Labels mouse overs
    latitude->setToolTip("Latitude");
    longitude->setToolTip("Longitude");
    altitude->setToolTip("Altitude");

    //Add widgets to layout
    mainLayout->addWidget(targets,0,0);
    mainLayout->addWidget(lat,0,1);
    mainLayout->addWidget(latitude,0,2);
    mainLayout->addWidget(longi,0,3);
    mainLayout->addWidget(longitude,0,4);
    mainLayout->addWidget(alt,0,5);
    mainLayout->addWidget(altitude,0,6);

    //Set widget layout
    setLayout(mainLayout);

    //If button is pressed, we emit
    connect(targets,SIGNAL(clicked()),this,SLOT(targetsend()));
}

//Upon button press, we send the entered latitude, longitude and altitude as a signal
void targetingGUI::targetsend()
{
    emit target(latitude->text().toFloat(),longitude->text().toFloat(),altitude->text().toFloat());
}
