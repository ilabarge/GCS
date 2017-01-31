#ifndef VEHICLELISTDISPLAY_H
#define VEHICLELISTDISPLAY_H

#include <QWidget>
#include "vehicleelementdisplay.h"
#include "vehicle_list.h"

class VehicleListDisplay : public QWidget
{
    Q_OBJECT
public:
    explicit VehicleListDisplay(QWidget *parent = 0);
    void setList(vehicle_list*);

signals:

public slots:
    void updateDisplay(int);

private:
    QVector<VehicleElementDisplay*> *vehicleList;
    vehicle_list *vList;
};

#endif // VEHICLELISTDISPLAY_H
