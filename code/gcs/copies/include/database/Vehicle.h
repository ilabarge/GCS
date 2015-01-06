#ifndef VEHICLE_H
#define VEHICLE_H

class Vehicle
{
public:
    Vehicle();
    explicit Vehicle(int vehicleID,     int vehicleType,    int altitude,
                     int wayPointID,    int wayPointType,   int mode,
                     int state,         int batteryStatus,  double latitude,
                     double longitude,  double heading,     double xAccel,
                     double yAccel,     double rollRate,    double pitchRate,
                     double yawRate,    double velocity,    double roll,
                     double pitch,      double yaw);

    bool getNeedsUpdate();

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

private:
    /* Start trip data variables */
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

    bool needsUpdate;

};

#endif // VEHICLE_H
