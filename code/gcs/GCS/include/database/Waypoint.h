#ifndef WAYPOINT_H
#define WAYPOINT_H

class Waypoint 
{
public:
	Waypoint(int id, int type, double lon, double lat, int alt);
	
	/* Getter Methods */
	int getPriority();
	int getID();
	int getType();
	int getLongitude();
	int getLatitude();
	int getAltitude();
	
private:
	int wayPointID;
	int wayPointType;
	double longitude;
	double latitude;
	int altitude;
};

#endif // WAYPOINT_H