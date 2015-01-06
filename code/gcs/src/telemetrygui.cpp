#include "telemetrygui.h"

TelemetryGUI::TelemetryGUI(QWidget *parent) :
    QWidget(parent)
{
    //Create the main layout for the widget
    mainLayout = new QGridLayout();
    //set margins
    mainLayout->setMargin( 0 );
    //Create button for the sending of command
    Telemetry = new QPushButton();
    //Set text of button
    Telemetry->setText("Start Telemetry");
    //Create text input
    telemetryInput = new QLineEdit();
    //Add the two widgets to the layout
    mainLayout->addWidget(Telemetry,1,0);
    mainLayout->addWidget(telemetryInput,1,1);
    //sets the layout of the widget to mainLayout
    setLayout( mainLayout );

    //Signal/slot for button, to emit value at input
    connect(Telemetry,SIGNAL(clicked()),this,SLOT(send_telemetry()));
}

/**
 * @brief TelemetryGUI::send_telemetry Emits signal that contains the value of the vehicle ID to start telemetry
 */
void TelemetryGUI::send_telemetry()
{
    //Handle empty/null input?
    emit telemetry(telemetryInput->text().toInt());
}

