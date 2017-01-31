#ifndef VEHICLEINFO_H
#define VEHICLEINFO_H

#include <QMainWindow>
#include <QLabel>
#include <QGridLayout>
#include "vehicle_list.h"
#include "Vehicle22.h"
#include <QMutex>
#include <ctime>
#include <cmath>

class VehicleInfo : public QMainWindow
{
    Q_OBJECT

public:
    explicit VehicleInfo(QWidget *parent = 0);
    void getList(vehicle_list *);
    ~VehicleInfo();
    vehicle_list *vl;
    int currentVehicle;

signals:
    void info(int);

public slots:
    void status(int);
    void displayVech(int);

private:
    QGridLayout *infoType;
    QLabel *vehicleID;
    QLabel *vehicleType;
    QLabel *altitude;
    QLabel *mode;
    QLabel *state;
    QLabel *latitude;
    QLabel *longitude;
    QLabel *heading;
    QLabel *velocity;


    QLabel *idUp;
    QLabel *typeUp;
    QLabel *altUp;
    QLabel *modeUp;
    QLabel *stateUp;
    QLabel *latUp;
    QLabel *longUp;
    QLabel *headingUp;
    QLabel *velocityUp;
};

#endif // VEHICLEINFO_H
