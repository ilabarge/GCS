#include "Waypoint.h"

Waypoint::Waypoint(){}

Waypoint::Waypoint(int id, int type, double lon, double lat, int alt, int vehicleType) {
    this->wayPointID = id;
    this->wayPointType = type;
    this->longitude = lon;
    this->latitude = lat;
    this->altitude = alt;
    //Add in vehicle type to select color/shape
    QList<EsriRuntimeQt::Point> points;
    points.append(EsriRuntimeQt::Point(0,0));
    points.append(EsriRuntimeQt::Point(0,0));
    QList< QList<EsriRuntimeQt::Point> > pathList;
    pathList.append(points);
    line = EsriRuntimeQt::Polyline(pathList);
    lineSymb.setColor(color);
    lineSymb.setWidth(2);
    lineGraphic = EsriRuntimeQt::Graphic(line, lineSymb);
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
int Waypoint::getAltitude() {
    return this->altitude;
}

bool Waypoint::setNextWaypoint(double x, double y){
    line.removePoint(0, 1);
    line.insertPoint(0, -1, EsriRuntimeQt::Point(x, y));
    return true;
}

void Waypoint::clearNextWaypoint(){
    line.removePoint(0, 1);
}

int Waypoint::getLineGraphicID(){
    return lineGraphicID;
}

EsriRuntimeQt::Graphic Waypoint::getLineGraphic(){
    return lineGraphic;
}
