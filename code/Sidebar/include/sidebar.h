#ifndef SIDEBAR_H
#define SIDEBAR_H

#include <QMainWindow>
#include "../include/togglebutton.h"

class sideBar : public QWidget
{
    Q_OBJECT

public:
    explicit sideBar(QWidget *parent = 0);
    ~sideBar();

signals:
    void uavOn();
    void uavOff();
    void ugvOn();
    void ugvOff();
    void waypointOn();
    void waypointOff();
    void satelliteOn();
    void satelliteOff();
    void opspaceOn();
    void opspaceOff();
    void targetOn();
    void targetOff();

private slots:
    void uavToggle();
    void ugvToggle();
    void waypointToggle();
    void satelliteToggle();
    void opspaceToggle();
    void targetToggle();

private:
    toggleButton *uav;
    toggleButton *ugv;
    toggleButton *waypoint;
    toggleButton *satellite;
    toggleButton *opspace;
    toggleButton *target;

};

#endif // SIDEBAR_H
