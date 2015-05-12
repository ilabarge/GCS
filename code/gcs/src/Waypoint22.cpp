#include "Waypoint22.h"

#include <QMutex>
#include <QMutexLocker>

QMutex mx;

Waypoint22::Waypoint22(QObject *parent) :
    MapSymbol22(parent)
{
}

Waypoint22::Waypoint22(int id,          int type,        double latitude,
                       double longitude, double altitude, int vehicleType){
    QMutexLocker l(&mx);
    this->ID = id;
    this->type = type;
    this->lon = longitude;
    this->lat = latitude;
    this->alt = altitude;
    nextLat = latitude;
    nextLon = longitude;

    // TODO: Add in vehicle type to select color/shape
    QList<EsriRuntimeQt::Point> points;
    points.append( EsriRuntimeQt::Point(0, 0) ); //Starting
    points.append( EsriRuntimeQt::Point(0, 0) ); //Ending
    QList< QList<EsriRuntimeQt::Point> > pathList;
    pathList.append(points);
    color = Qt::red;
    line = EsriRuntimeQt::Polyline(pathList);
    lineSymb.setColor(color);
    lineSymb.setWidth(2);
    lineGraphic = &EsriRuntimeQt::Graphic(line, lineSymb, -1);
}

bool Waypoint22::setLinePoints(EsriRuntimeQt::Point p1, EsriRuntimeQt::Point p2){
    QMutexLocker l(&mx);

    //Clear the path
    line.removePath(0);

    QList<EsriRuntimeQt::Point> pointList;
    pointList.append(p1);
    pointList.append(p2);

    //           index, list, offset, numPoints, inOrder
    line.insertPath(0, pointList, 0, 2,  true);

    return true;
}

void Waypoint22::setWaypointOrigin(double lat, double lon){
    QMutexLocker l(&mx);
    this->lat = lat;
    this->lon = lon;
}

bool Waypoint22::setNextWaypoint(double lat, double lon){
    QMutexLocker l(&mx);

    nextLat = lat;
    nextLon = lon;
    return true;
}

void Waypoint22::clearNextWaypoint(){
    QMutexLocker l(&mx);
    nextLat = lat;
    nextLon = lon;
}

void Waypoint22::setLineGraphic(EsriRuntimeQt::Graphic graphic){
    QMutexLocker l(&mx);
    lineGraphic = &graphic;
}

void Waypoint22::updateLineGraphic(){
    QMutexLocker l(&mx);
    lineGraphic = &EsriRuntimeQt::Graphic(line, lineSymb);
}
