#include <iostream>

#include <QCoreApplication>
#include <QVector>
#include <QMutex>

#include "DataDaemon.h"
#include "networking.h"
#include "Vehicle.h"

void displayInfo(Vehicle* v);

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
//    DataDaemon dd;
    QVector<Vehicle*>* vList = new QVector<Vehicle*>();
    Vehicle* vehicle = new Vehicle();
    vehicle->setVehicleID(-1);
    vList->append(vehicle);
    networking net(vList);
    /*
    std::cout << "Vehicle | Collision Avoidance State | Connected" << std::endl
              << "--------+---------------------------+----------" << std::endl
              << "list 1   | ACTIVE                    | YES" << std::endl
              << "list 2   |                           | NO " << std::endl;
    */


    while(1)
    {
        /*The first vehicle in list acts as a boolean placeholder
         * to check to see if there is any new information*/
        if(vehicle->getNeedsUpdate()){
            std::system("cls");
            //qDebug() << vList->size();
            for(int i = 1; i < vList->size(); i++){
                //qDebug() << "in for loop";
                displayInfo(vList->at(i));
            }
        }
    }

    //Cleanup vehicles
    for(int i = 0; i < vList->size(); i++){
        delete vList->at(i);
    }
    //Cleanup vehicle list
    delete vList;

    return a.exec();
}

void displayInfo(Vehicle* v){
    std::cout << "ID: " << v->getVehicleID() << std::endl;
    std::cout << "Altitude: " << v->getAltitude() << std::endl;
    std::cout << "Latitude: " << v->getLatitude() << std::endl;
    std::cout << "Longitude: " << v->getLongitude() << std::endl;
    std::cout << "Collision Avoidance Status: " << v->getState() << std::endl;
    std::cout << "Pitch: "<< v->getPitch() << std::endl;
    std::cout << "Roll: " << v->getRoll() << std::endl;
    std::cout << "Yaw: " << v->getYaw() << std::endl;
}
