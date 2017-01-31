#include "vehiclelistgui.h"

vehiclelistgui::vehiclelistgui(QWidget *parent)
    : QMainWindow(parent)
{
    element = new VehicleElementDisplay();
    layout = new QGridLayout();

    qDebug() << element->getID();
    layout->setMargin(0);
    layout->addWidget(element,0,0);

    centralWidget = new QWidget();
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);
    showMaximized();
}


vehiclelistgui::~vehiclelistgui()
{

}
