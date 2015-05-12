#ifndef VEHICLE22_H
#define VEHICLE22_H

// Standard Library Headers
#include <vector>

// Qt Headers

// ArcGIS Headers

// Our headers
#include "MapSymbol22.h"
#include "Waypoint22.h"

class Vehicle22 : public MapSymbol22
{
    Q_OBJECT
public:
    explicit Vehicle22(QObject *parent = 0);

    Vehicle22(int vehicleID,    int vehicleType,  double alt,
            int mode,         int state,        int batteryStatus,
            double latitude,  double longitude, double heading,
            double xAccel,    double yAccel,    double rollRate,
            double pitchRate, double yawrate,   double velocity,
            double roll,      double pitch,     double yaw);
    //Copy Constructor
    Vehicle22(const Vehicle22&);
    /* BEGIN SETTERS */
    void setVehicleID(int vehicleID);
    void setVehicleType(int vehicleType);
    void setAltitude(int altitude);
    void setMode(int mode);
    void setState(int state);
    void setBatteryStatus(int batteryStatus);
    void setLatitude(double latitude);
    void setLongitude(double longitude);
    void setHeading(double heading);
    void setXAcceleration(double xAccel);
    void setYAcceleration(double yAccel);
    void setZAcceleration(double zAccel);
    void setRollRate(double rollRate);
    void setPitchRate(double pitchRate);
    void setYawRate(double yawRate);
    void setVelocity(double velocity);
    void setRoll(double roll);
    void setPitch(double pitch);
    void setYaw(double yaw);
    void setXVelocity(double xVelocity);
    void setYVelocity(double yVelocity);
    void setZVelocity(double zVelocity);
    /* END SETTERS */

    /* START GETTERS */
    // Data
    int getVehicleID(){ return vID; }
    int getVehicleType(){ return vType; }
    int getMode(){ return mode; }
    int getState(){ return state; }
    int getBatteryStatus(){ return batteryStatus; }
    double getAltitude(){ return alt; }
    double getLatitude(){ return lat; }
    double getLongitude(){ return lon; }
    double getHeading(){ return heading; }
    double getXAcceleration(){ return xAccel; }
    double getYAcceleration(){ return yAccel; }
    double getZAcceleration(){ return zAccel; }
    double getRollRate(){ return rollRate; }
    double getPitchRate(){ return pitchRate; }
    double getYawRate(){ return yawRate; }
    double getVelocity(){ return vel; }
    double getRoll(){ return roll; }
    double getPitch(){ return pitch; }
    double getYaw(){ return yaw; }
    double getXVelocity(){ return xVel; }
    double getYVelocity(){ return yVel; }
    double getZVelocity(){ return zVel; }
    bool getNeedsUpdate(){ return needsUpdate; }

    // Waypoints
    Waypoint22* getWaypoint(int index);
    /* END GETTERS */

    bool appendWaypoint(Waypoint22* wp, QColor color);
    bool removeWaypoint(int index);
    bool insertWaypoint(int index, Waypoint22* wp, QColor color);
    int numWaypoints();

    std::vector<Waypoint22*> waypoints;

signals:
    void GCSUpdateGraphic(int gID, EsriRuntimeQt::Graphic *graphic);
    void addWaypointGraphic(Waypoint22*, QColor);
    void updateWaypointGraphics(Waypoint22* wp );
    void removeWaypointGraphic(int waypointID, int lineID);

private:
    QMutex mx;
    /* START DATA VARIABLES */
    int vID;
    int vType;
    double alt;
    int mode;
    int state;
    int batteryStatus;
    double lat;
    double lon;
    double heading;
    double xAccel;
    double yAccel;
    double zAccel;
    double rollRate;
    double pitchRate;
    double yawRate;
    double vel;
    double roll;
    double pitch;
    double yaw;
    double xVel;
    double yVel;
    double zVel;

    bool needsUpdate;
    /* END DATA VARIABLES */

    /* BEGIN FUNCTIONS */
    void updateWaypoints(int first, int second, int third);
    bool validIndex(int index);
    /* END FUNCTIONS */
};

#endif // VEHICLE22_H
