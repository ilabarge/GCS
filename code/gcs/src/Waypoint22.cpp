#include "Waypoint22.h"

#include <QMutex>
#include <QMutexLocker>

QMutex mx;

Waypoint22::Waypoint22(QObject *parent) :
    MapSymbol22(parent)
{
}

Waypoint22::Waypoint22(int id,          int type,        double latitude,
                       double longitude, double altitude, int vehicleType, EsriRuntimeQt::SpatialReference spatialReference){
    QMutexLocker l(&mx);
    this->ID = id;
    this->type = type;
    this->lon = longitude;
    this->lat = latitude;
    this->alt = altitude;
    nextLat = latitude;
    nextLon = longitude;
    this->spatialReference = spatialReference;


    // TODO: Add in vehicle type to select color/shape
//    QList<EsriRuntimeQt::Point> points;
    points.append( EsriRuntimeQt::Point(0,  0, spatialReference) ); //Starting
    points.append( EsriRuntimeQt::Point(0, 0, spatialReference) ); //Ending
////    QList< QList<EsriRuntimeQt::Point> > pathList;
    pathList.append(points);
    color = Qt::red;
    line = EsriRuntimeQt::Polyline(pathList);

    lineSymb.setColor(color);
    lineSymb.setWidth(2);
    lineGraphic = new EsriRuntimeQt::Graphic(line, lineSymb);
}

bool Waypoint22::setLinePoints(EsriRuntimeQt::Point p1, EsriRuntimeQt::Point p2){
    QMutexLocker l(&mx);

    //Clear the path
    line.removePath(0);

//  QList<EsriRuntimeQt::Point> pointList;

//    pointList.append(p1);
//    pointList.append(p2);

////    points.append(p1);
////    points.append(p2);

    line.startPath(p1);
    line.lineTo(p2);


//               index, list, offset, numPoints, inOrder
//    line.insertPath(0, pointList, 0, 2,  true);

    updateLineGraphic();
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
    //QMutexLocker l(&mx);
    lineGraphic = new EsriRuntimeQt::Graphic(line, lineSymb);
}
