#include "Waypoint.h"

Waypoint::Waypoint(int id, int type, double lon, double lat, int alt) {
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
int Waypoint::getLongitude() {
    return this->longitude;
}
int Waypoint::getLatitude() {
    return this->latitude;
}
int Waypoint::getAltitude() {
    return this->altitude;
}
