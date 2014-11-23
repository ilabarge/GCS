#ifndef VEHICLE_H
#define VEHICLE_H

//Qt headers
#include <vector>

#include "MapSymbol.h"
#include "Waypoint.h"

#include <QDebug>

class Vehicle : public MapSymbol
{

public:
    Vehicle();      // Empty Constructor
    ~Vehicle();     // Destructor

    // Constructor with data input
    explicit Vehicle(int vehicleID,    int vehicleType,   int altitude,
                     int mode,         int state,         int batteryStatus,
                     double latitude,  double longitude,  double heading,
                     double xAccel,    double yAccel,     double rollRate,
                     double pitchRate, double yawRate,    double velocity,
                     double roll,      double pitch,      double yaw);

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
    void setZAcceleration(double xAccel);
    void setRollRate(double rollRate);
    void setPitchRate(double pitchRate);
    void setYawRate(double yawRate);
    void setVelocity(double velocity);
    void setRoll(double roll);
    void setPitch(double pitch);
    void setYaw(double yaw);
    void setXVelocity(double xVel);
    void setYVelocity(double yVel);
    void setZVelocity(double zVel);
    /* END SETTERS */

    /* BEGIN GETTERS */
    int getVehicleID();
    int getVehicleType();
    int getAltitude();
    int getMode();
    int getState();
    int getBatteryStatus();
    double getLatitude();
    double getLongitude();
    double getHeading();
    double getXAcceleration();
    double getYAcceleration();
    double getZAcceleration();
    double getRollRate();
    double getPitchRate();
    double getYawRate();
    double getVelocity();
    double getRoll();
    double getPitch();
    double getYaw();
    double getXVelocity();
    double getYVelocity();
    double getZVelocity();
    bool getNeedsUpdate();
    /* END GETTERS */

    bool appendWaypoint(Waypoint& wp);
    bool removeWaypoint(int index);
    bool insertWaypoint(int index, Waypoint& wp);
    Waypoint* getWaypoint(int index);
    int numWaypoints();

    std::vector<Waypoint> waypoints;
    // HOW TO INSERT INTO VECTOR: waypoints.insert(waypoints.begin() + "position", "Waypointobject")

private:
    /* START DATA VARIABLES */
    int vehicleID;
    int vehicleType;
    int altitude;
    int mode;
    int state;
    int batteryStatus;
    double latitude;
    double longitude;
    double heading;
    double xAccel;
    double yAccel;
    double zAccel;
    double rollRate;
    double pitchRate;
    double yawRate;
    double velocity;
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

#endif // VEHICLE_H
