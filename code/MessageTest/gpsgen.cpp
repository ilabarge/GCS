#include "gpsgen.h"

GPSGen::GPSGen(int ID, QObject *parent) : QObject(parent)
{
    this->vechID = ID;
}

void GPSGen::generateGPS(){
    //Generate between
    //Lat   34059777 :   34057462
    //Lon -117822743 : -117818103
    //Using int could use long
    //Using whole number representation of points
    //Lat 34059777 = 34.059777
    //Lon -117822743 = -117.822743
    while(true){
        //We are adding a 0 due to the way GCS registers the stored lat/long
        int lat = rand() % 23150 +  340597770;
        int lon = rand() % 46400 + 1178227430;
        double heading = (rand() % 361) * 1000000;
        //if windows
        Sleep(uint(1000));
        qDebug() << "lat " << lat << " long " << lon;
        emit gpsMSG(vechID,lat,-lon,0,heading,0,0,0);
    }
}

