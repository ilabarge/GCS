#ifndef VEHICLELISTGUI_H
#define VEHICLELISTGUI_H

#include <QWidget>
#include <QScrollArea>
#include <QMainWindow>
#include "vehicleelementdisplay.h"
#include <QDebug>

class vehiclelistgui : public QMainWindow
{
    Q_OBJECT

public:
    vehiclelistgui(QWidget *parent = 0);
    ~vehiclelistgui();

private:
    QScrollArea* list;
    VehicleElementDisplay *element;
    QGridLayout *layout;
    QWidget *centralWidget;

};

#endif // VEHICLELISTGUI_H
