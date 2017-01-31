#ifndef VEHICLEELEMENTDISPLAY_H
#define VEHICLEELEMENTDISPLAY_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QGridLayout>
#include "Vehicle22.h"

class VehicleElementDisplay : public QWidget
{
    Q_OBJECT
public:
    explicit VehicleElementDisplay(QWidget *parent = 0);
    void setID(int);
    int getID();
    void setVehicle(Vehicle22*);
    void update();
    void setText();
    ~VehicleElementDisplay();

signals:
    void vechID(int);

public slots:
    void updateDisplay(int vechID);

private slots:
    void vehicleClick();

private:
    int id;
    QPushButton *vehicleSelect;
    QGridLayout *infoLayout;
    QGridLayout *vehicleLayout;
    QGridLayout *mainLayout;
    QLabel *VehicleType;
    QLabel *VehicleNo;
    QLabel *VehicleStatus;
    QWidget *imgTemp;
    Vehicle22 *vechicle;
};

#endif // VEHICLEELEMENTDISPLAY_H
