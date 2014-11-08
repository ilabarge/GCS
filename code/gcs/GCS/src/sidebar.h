#ifndef SIDEBAR_H
#define SIDEBAR_H

#include "togglebutton.h"

class sideBar : public QWidget
{
    Q_OBJECT

public:
    explicit sideBar(QWidget *parent = 0);
    ~sideBar();

signals:
    void uavOn(bool isOn);
    void ugvOn(bool isOn);
    void waypointOn(bool isOn);
    void satelliteOn(bool isOn);
    void opspaceOn(bool isOn);
    void targetOn(bool isOn);

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
