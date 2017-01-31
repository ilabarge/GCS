#include "Waypoint.h"

Waypoint::Waypoint(int id, int type, double lon, double lat, double alt) {
    this->wayPointID = id;
    this->wayPointType = type;
    this->longitude = lon;
    this->latitude = lat;
    this->altitude = alt;
}

int Waypoint::getID() {
    return this->wayPointID;
}
int Waypoint::getType() {
    return this->wayPointType;
}
double Waypoint::getLongitude() {
    return this->longitude;
}
double Waypoint::getLatitude() {
    return this->latitude;
}
double Waypoint::getAltitude() {
    return this->altitude;
}

void Waypoint::setLongitude(double longi) {
    longitude = longi;
}
void Waypoint::setLatitude(double lat) {
    latitude = lat;
}
void Waypoint::setAltitude(double alt) {
    altitude = alt;
}

void Waypoint::update(){
    emit updateWaypoint();
}
