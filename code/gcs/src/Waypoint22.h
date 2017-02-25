#ifndef WAYPOINT22_H
#define WAYPOINT22_H

//Qt Headers
#include <QList>
//#include <QColor> // From MapSymbol22

//ArcGIS Headers
#include <Polyline.h>
#include <SimpleLineSymbol.h>
//#include <Graphic.h> // From MapSymbol22

#include "MapSymbol22.h"

class Waypoint22 : public MapSymbol22
{
    Q_OBJECT

public:

    explicit Waypoint22(QObject *parent = 0);
    Waypoint22(int id,     int type,        double lat,
               double lon, double altitude, int vehicleType, EsriRuntimeQt::SpatialReference spatialReference);

    /* START GETTERS */
    double getAltitude(){ return alt; }
    int getID(){ return ID; }
    double getLongitude(){ return lon; }
    double getLatitude(){ return lat; }
    int getType(){ return type; }

    double getNextLatitude(){ return nextLat; }
    double getNextLongitude(){ return nextLon; }

    //ESRI 10.2.5 update change uid to uniqueId
    int getLineGraphicID(){ return lineGraphic->uniqueId(); }
    EsriRuntimeQt::Graphic* getLineGraphic(){ return lineGraphic; }
    EsriRuntimeQt::Polyline getLine(){ return line; }
    /* END GETTERS */

    /* START SETTERS */
    void setAltitude(double altitude){ alt = altitude; }
    void setLongitude(double longitude){ lon = longitude; }
    void setLatitude(double latitude){ lat = latitude; }
    void setType(int type){ this->type = type; }

    void clearNextWaypoint();
    void setLineGraphic(EsriRuntimeQt::Graphic graphic);
    bool setLinePoints(EsriRuntimeQt::Point p1, EsriRuntimeQt::Point p2);
    bool setLinePoints2(EsriRuntimeQt::Point p1, EsriRuntimeQt::Point p2);
    void setWaypointOrigin(double lat, double lon);
    bool setNextWaypoint(double lat, double lon);
    void updateLineGraphic();
    /* END SETTERS */

private:
    double alt;
    int ID;
    double lat;
    double lon;
    int type;

    double nextLat;
    double nextLon;

    QList<EsriRuntimeQt::Point> points;
    QList<QList<EsriRuntimeQt::Point>> pathList;

    // Graphics members
    int lineGraphicID;
    EsriRuntimeQt::Polyline line;
    EsriRuntimeQt::SimpleLineSymbol lineSymb;
    EsriRuntimeQt::Graphic *lineGraphic;
    EsriRuntimeQt::SpatialReference spatialReference;

signals:

public slots:

};

#endif // WAYPOINT22_H
