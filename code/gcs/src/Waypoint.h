#ifndef WAYPOINT_H
#define WAYPOINT_H

//ArcGIS Headers
#include <Polyline.h>
#include <CoordinateConversion.h>
//#include <Graphic.h> //Already in MapSymbol

//Qt Headers
#include <QList>
//#include <QColor> //Already in MapSymbol

//Our Headers
#include "MapSymbol.h"

class Waypoint : public MapSymbol
{
public:
    Waypoint();
    explicit Waypoint(int id, int type, double lon, double lat, int alt, int vehicleType);
	
	/* Getter Methods */
	int getID();
	int getType();
    double getLongitude();
    double getLatitude();
    int getAltitude();

    void setLineGraphicID(int id);
    bool setNextWaypoint(double x, double y);
    void clearNextWaypoint();

    int getLineGraphicID();
    EsriRuntimeQt::Graphic getLineGraphic();
	
private:
	int wayPointID;
	int wayPointType;
	double longitude;
	double latitude;
	int altitude;

    int lineGraphicID;
    EsriRuntimeQt::Polyline line;
    EsriRuntimeQt::SimpleLineSymbol lineSymb;
    EsriRuntimeQt::Graphic lineGraphic;
};

#endif // WAYPOINT_H
