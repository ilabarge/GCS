#include "Vehicle.h"

Vehicle::Vehicle()
{
    needsUpdate = false;
}

Vehicle::Vehicle(int vehicleID,     int vehicleType,    int altitude,
                 int wayPointID,    int wayPointType,   int mode,
                 int state,         int batteryStatus,  double latitude,
                 double longitude,  double heading,     double xAccel,
                 double yAccel,     double rollRate,    double pitchRate,
                 double yawRate,    double velocity,    double roll,
                 double pitch,      double yaw)
{
    this->vehicleID = vehicleID;
    this->vehicleType = vehicleType;
    this->altitude = altitude;
    this->wayPointID = wayPointID;
    this->wayPointType = wayPointType;
    this->mode = mode;
    this->state = state;
    this->batteryStatus = batteryStatus;
    this->latitude = latitude;
    this->longitude = longitude;
    this->heading = heading;
    this->xAccel = xAccel;
    this->yAccel = yAccel;
    this->rollRate = rollRate;
    this->pitchRate = pitchRate;
    this->yawRate = yawRate;
    this->velocity = velocity;
    this->roll = roll;
    this->pitch = pitch;
    this->yaw = yaw;

    needsUpdate = true;
}

/* BEGIN SETTER METHODS */
void Vehicle::setVehicleID(int vehicleID) {
    this->vehicleID = vehicleID;
    needsUpdate = true;
}
void Vehicle::setVehicleType(int vehicleType) {
    this->vehicleType = vehicleType;
    needsUpdate = true;
}
void Vehicle::setAltitude(int altitude) {
    this->altitude = altitude;
    needsUpdate = true;
}
void Vehicle::setWayPointID(int wayPointID) {
    this->wayPointID = wayPointID;
    needsUpdate = true;
}
void Vehicle::setWayPointType(int wayPointType) {
    this->wayPointType = wayPointType;
    needsUpdate = true;
}
void Vehicle::setMode(int mode) {
    this->mode = mode;
    needsUpdate = true;
}
void Vehicle::setState(int state) {
    this->state = state;
    needsUpdate = true;
}
void Vehicle::setBatteryStatus(int batteryStatus) {
    this->batteryStatus = batteryStatus;
    needsUpdate = true;
}
void Vehicle::setLatitude(double latitude) {
    this->latitude = latitude;
    needsUpdate = true;
}
void Vehicle::setLongitude(double longitude) {
    this->longitude = longitude;
    needsUpdate = true;
}
void Vehicle::setHeading(double heading) {
    this->heading = heading;
    needsUpdate = true;
}
void Vehicle::setXAcceleration(double xAcceleration) {
    this->xAccel = xAcceleration;
    needsUpdate = true;
}
void Vehicle::setYAcceleration(double yAcceleration) {
    this->yAccel = yAcceleration;
    needsUpdate = true;
}
void Vehicle::setRollRate(double rollRate) {
    this->rollRate = rollRate;
    needsUpdate = true;
}
void Vehicle::setPitchRate(double pitchRate) {
    this->pitchRate = pitchRate;
    needsUpdate = true;
}
void Vehicle::setYawRate(double yawRate) {
    this->yawRate = yawRate;
    needsUpdate = true;
}
void Vehicle::setVelocity(double velocity) {
    this->velocity = velocity;
    needsUpdate = true;
}
void Vehicle::setRoll(double roll) {
    this->roll = roll;
    needsUpdate = true;
}
void Vehicle::setPitch(double pitch) {
    this->pitch = pitch;
    needsUpdate = true;
}
void Vehicle::setYaw(double yaw) {
    this->yaw = yaw;
    needsUpdate = true;
}
void Vehicle::setXVelocity(double xVel){
    this->xVel = xVel;
    needsUpdate = true;
}
void Vehicle::setYVelocity(double yVel){
    this->yVel = yVel;
    needsUpdate = true;
}
void Vehicle::setZVelocity(double zVel){
    this->zVel = zVel;
    needsUpdate = true;
}

/* BEGIN GETTER METHODS */
int Vehicle::getVehicleID() { return vehicleID; }
int Vehicle::getVehicleType() { return vehicleType; }
int Vehicle::getAltitude() { return altitude; }
int Vehicle::getWayPointID() { return wayPointID; }
int Vehicle::getWayPointType() { return wayPointType; }
int Vehicle::getMode() { return mode; }
int Vehicle::getState() { return state; }
int Vehicle::getBatteryStatus() { return batteryStatus; }
double Vehicle::getLatitude() { return latitude; }
double Vehicle::getLongitude() { return longitude; }
double Vehicle::getHeading() { return heading; }
double Vehicle::getXAcceleration() { return xAccel; }
double Vehicle::getYAcceleration() { return yAccel; }
double Vehicle::getRollRate() { return rollRate; }
double Vehicle::getPitchRate() { return pitchRate; }
double Vehicle::getYawRate() { return yawRate; }
double Vehicle::getVelocity() { return velocity; }
double Vehicle::getRoll() { return roll; }
double Vehicle::getPitch() { return pitch; }
double Vehicle::getYaw() { return yaw; }
double Vehicle::getXVelocity() { return xVel; }
double Vehicle::getYVelocity() { return yVel; }
double Vehicle::getZVelocity() { return zVel; }

bool Vehicle::getNeedsUpdate() { return needsUpdate; }
