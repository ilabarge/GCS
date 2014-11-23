#include "telemetrygui.h"

TelemetryGUI::TelemetryGUI(QWidget *parent) :
    QWidget(parent)
{
mainLayout = new QGridLayout();
mainLayout->setMargin( 0 );
Telemetry = new QPushButton();
Telemetry->setText("Start Telemetry");
telemetryInput = new QLineEdit();
mainLayout->addWidget(Telemetry,1,0);
mainLayout->addWidget(telemetryInput,1,1);
setLayout( mainLayout );
connect(Telemetry,SIGNAL(clicked()),this,SLOT(send_telemetry()));
}

/**
 * @brief TelemetryGUI::send_telemetry Emits signal that contains the value of the vehicle ID to start telemetry
 */
void TelemetryGUI::send_telemetry()
{
    emit telemetry(telemetryInput->text().toInt());
}

