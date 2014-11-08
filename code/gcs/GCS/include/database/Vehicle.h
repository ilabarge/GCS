#ifndef VEHICLE_H
#define VEHICLE_H

#include <vector>
#include "Waypoint.h"

class Vehicle
{
public:
    Vehicle();      // Empty Constructor
    explicit Vehicle(int vehicleID,     
                             int vehicleType,    
                             int altitude,
                             int wayPointID,    
                             int wayPointType,   
                             int mode,
                             int state,         
                             int batteryStatus,  
                             double latitude,
                             double longitude,  
                             double heading,     
                             double xAccel,
                             double yAccel,     
                             double rollRate,    
                             double pitchRate,
                             double yawRate,    
                             double velocity,    
                             double roll,
                             double pitch,      
                             double yaw);       // Constructor with data input

    /* BEGIN SETTERS */
    void setVehicleID(int vehicleID);
    void setVehicleType(int vehicleType);
    void setAltitude(int altitude);
    void setWayPointID(int wayPointID);
    void setWayPointType(int wayPointType);
    void setMode(int mode);
    void setState(int state);
    void setBatteryStatus(int batteryStatus);
    void setLatitude(double latitude);
    void setLongitude(double longitude);
    void setHeading(double heading);
    void setXAcceleration(double xAccel);
    void setYAcceleration(double yAccel);
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

    /* BEGIN GETTERS */
    int getVehicleID();
    int getVehicleType();
    int getAltitude();
    int getWayPointID();
    int getWayPointType();
    int getMode();
    int getState();
    int getBatteryStatus();
    double getLatitude();
    double getLongitude();
    double getHeading();
    double getXAcceleration();
    double getYAcceleration();
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

    bool needsUpdate;

private:
    /* START TRIP DATA VARIABLES */
    int vehicleID;
    int vehicleType;
    int altitude;
    int wayPointID;
    int wayPointType;
    int mode;
    int state;
    int batteryStatus;
    double latitude;
    double longitude;
    double heading;
    double xAccel;
    double yAccel;
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

    
//public: vector<Waypoint> waypoints;   // Removed for temporary compiling issue
// HOW TO INSERT INTO VECTOR: waypoints.insert(waypoints.begin() + "position", "Waypointobject")

};

#endif // VEHICLE_H
