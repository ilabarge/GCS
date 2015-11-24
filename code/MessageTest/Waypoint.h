#ifndef WAYPOINT_H
#define WAYPOINT_H

//Qt Headers
#include <QList>
//#include <QColor> //Already in MapSymbol
#include <QObject>
class Waypoint : public QObject
{
    Q_OBJECT
public:
    explicit Waypoint(int id, int type, double lon, double lat, double alt);
	
	/* Getter Methods */
	int getID();
	int getType();
    double getLongitude();
    double getLatitude();
    double getAltitude();
    void setLongitude(double);
    void setLatitude(double);
    void setAltitude(double);
    void update();

signals:
    void updateWaypoint();

private:
	int wayPointID;
	int wayPointType;
	double longitude;
	double latitude;
    double altitude;
};

#endif // WAYPOINT_H
