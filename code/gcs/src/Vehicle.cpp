#include "Vehicle.h"

#include <QMutex>
#include <QMutexLocker>

QMutex mx1;

Vehicle::Vehicle()
{
    needsUpdate = false;
}

Vehicle::Vehicle(int vehicleID,     int vehicleType,    int altitude,
                 int mode,          int state,          int batteryStatus,
                 double latitude,   double longitude,   double heading,
                 double xAccel,     double yAccel,      double rollRate,
                 double pitchRate,  double yawRate,     double velocity,
                 double roll,       double pitch,       double yaw)
{
    this->vehicleID = vehicleID;
    this->vehicleType = vehicleType;
    this->altitude = altitude;
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
    //Reserves room in vector
    waypoints.reserve(30);
}

/* BEGIN SETTER METHODS */
void Vehicle::setVehicleID(int vehicleID) {
    QMutexLocker l(&mx1);
    this->vehicleID = vehicleID;
    needsUpdate = true;
}
void Vehicle::setVehicleType(int vehicleType) {
    QMutexLocker l(&mx1);
    this->vehicleType = vehicleType;
    needsUpdate = true;
}
void Vehicle::setAltitude(int altitude) {
    QMutexLocker l(&mx1);
    this->altitude = altitude;
    needsUpdate = true;
}
void Vehicle::setMode(int mode) {
    QMutexLocker l(&mx1);
    this->mode = mode;
    needsUpdate = true;
}
void Vehicle::setState(int state) {
    QMutexLocker l(&mx1);
    this->state = state;
    needsUpdate = true;
}
void Vehicle::setBatteryStatus(int batteryStatus) {
    QMutexLocker l(&mx1);
    this->batteryStatus = batteryStatus;
    needsUpdate = true;
}
void Vehicle::setLatitude(double latitude) {
    QMutexLocker l(&mx1);
    this->latitude = latitude;
    needsUpdate = true;
}
void Vehicle::setLongitude(double longitude) {
    QMutexLocker l(&mx1);
    this->longitude = longitude;
    needsUpdate = true;
}
void Vehicle::setHeading(double heading) {
    QMutexLocker l(&mx1);
    this->heading = heading;
    needsUpdate = true;
}
void Vehicle::setXAcceleration(double xAcceleration) {
    QMutexLocker l(&mx1);
    this->xAccel = xAcceleration;
    needsUpdate = true;
}
void Vehicle::setYAcceleration(double yAcceleration) {
    QMutexLocker l(&mx1);
    this->yAccel = yAcceleration;
    needsUpdate = true;
}
void Vehicle::setZAcceleration(double zAcceleration) {
    QMutexLocker l(&mx1);
    this->zAccel = zAcceleration;
    needsUpdate = true;
}
void Vehicle::setRollRate(double rollRate) {
    QMutexLocker l(&mx1);
    this->rollRate = rollRate;
    needsUpdate = true;
}
void Vehicle::setPitchRate(double pitchRate) {
    QMutexLocker l(&mx1);
    this->pitchRate = pitchRate;
    needsUpdate = true;
}
void Vehicle::setYawRate(double yawRate) {
    QMutexLocker l(&mx1);
    this->yawRate = yawRate;
    needsUpdate = true;
}
void Vehicle::setVelocity(double velocity) {
    QMutexLocker l(&mx1);
    this->velocity = velocity;
    needsUpdate = true;
}
void Vehicle::setRoll(double roll) {
    QMutexLocker l(&mx1);
    this->roll = roll;
    needsUpdate = true;
}
void Vehicle::setPitch(double pitch) {
    QMutexLocker l(&mx1);
    this->pitch = pitch;
    needsUpdate = true;
}
void Vehicle::setYaw(double yaw) {
    QMutexLocker l(&mx1);
    this->yaw = yaw;
    needsUpdate = true;
}
void Vehicle::setXVelocity(double xVel) {
    QMutexLocker l(&mx1);
    this->xVel = xVel;
    needsUpdate = true;
}
void Vehicle::setYVelocity(double yVel) {
    QMutexLocker l(&mx1);
    this->yVel = yVel;
    needsUpdate = true;
}
void Vehicle::setZVelocity(double zVel) {
    QMutexLocker l(&mx1);
    this->zVel = zVel;
    needsUpdate = true;
}

/* BEGIN GETTER METHODS */
int Vehicle::getVehicleID() { return vehicleID; }
int Vehicle::getVehicleType() { return vehicleType; }
int Vehicle::getAltitude() { return altitude; }
int Vehicle::getMode() { return mode; }
int Vehicle::getState() { return state; }
int Vehicle::getBatteryStatus() { return batteryStatus; }
double Vehicle::getLatitude() { return latitude; }
double Vehicle::getLongitude() { return longitude; }
double Vehicle::getHeading() { return heading; }
double Vehicle::getXAcceleration() { return xAccel; }
double Vehicle::getYAcceleration() { return yAccel; }
double Vehicle::getZAcceleration() { return zAccel; }
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

bool Vehicle::appendWaypoint(Waypoint& wp){
    qDebug() << "Appended waypoint";
    QMutexLocker l(&mx1);
    waypoints.push_back(wp);
    updateWaypoints((int)waypoints.size() - 2, -1, (int)waypoints.size() - 1);
    qDebug() << "Done updating waypoint graphic";
    return true;
}

bool Vehicle::removeWaypoint(int index){
    if(!validIndex(index)){ return false; }

    qDebug() << "Good index";

    //Lock the data for ourselves
    QMutexLocker l(&mx1);

    //Remove the line and waypoint
//    emit GCSRemoveGraphic(waypoints.at(waypoints.begin() + index).getGraphicID());

    //We will have at least two after delete
    if(waypoints.size() > 2){
        updateWaypoints(index - 1, -1, index);
    }
    //We have one waypoint left after delete
    else if(waypoints.size() == 2){
        //Just tell the waypoint it's all alone... :(

        //If it's the second waypoint we just need to tell
        //the first waypoint it has no next waypoint.
        if(index == 1){
            waypoints.at(index-1).clearNextWaypoint();
        }

        //Otherwise, the second waypoint doesn't have a line
        //drawn to anything, so we can just leave it.
    }
    //We have no waypoints after delete
    else if(waypoints.size() == 1){
        //Don't really need to redraw anything because graphic
        //was already removed.
    }

    qDebug() << "Removed waypoint";
    waypoints.erase(waypoints.begin() + index);

    return true;
}

bool Vehicle::insertWaypoint(int index, Waypoint& wp){
    if(!validIndex(index)){ return false; }

    //Lock the data for ourselves
    QMutexLocker l(&mx1);

    //Insert the waypoint into the list
    waypoints.insert(waypoints.begin() + index, wp);

    //We're inserting it to the front
    if(index == 0){
        //We only need to update the first element and tell
        //it to point to the former first waypoint.
        updateWaypoints(index, -1, index + 1);
    }
    //We're adding it somewhere in between two waypoints
    else{
        updateWaypoints(index - 1, index, index + 1);
    }
    return true;
}

Waypoint* Vehicle::getWaypoint(int index){
    if(!validIndex(index)){ return NULL; }

    //Lock data
    QMutexLocker l(&mx1);
    return &waypoints.at(index);
}

int Vehicle::numWaypoints(){
    //Lock data
    QMutexLocker l(&mx1);
    return (int)waypoints.size();
}

void Vehicle::updateWaypoints(int first, int middle, int last){

    //Don't need mutex because it's a private function
    //and is only called after a mutex lock.

    //Check to see if drawing only the first waypoint
    if(middle == -1){
        //htfutyf
    }
    //We're inserting a waypoint, so need to draw two
    //waypoints
    else{
        //First, make the first waypoint point to the inserted
        //waypoint

        //Make the first connect to the middle
        waypoints.at(first).setNextWaypoint(
                    waypoints.at(middle).getLatitude(),
                    waypoints.at(middle).getLongitude());
        //Make the middle connect to the last
        waypoints.at(middle).setNextWaypoint(
                    waypoints.at(last).getLatitude(),
                    waypoints.at(last).getLongitude());
//        emit GCSUpdateGraphic(waypoints.at(first).getLineGraphicID(), waypoints.at(first).getLineGraphic());
//        emit updateGraphic(waypoints.at(middle).getLineGraphicID(), waypoints.at(middle).getLineGraphic());
    }
}

bool Vehicle::validIndex(int index){
    if(index < 0 || index > waypoints.size() - 1){
        return false;
    }
    return true;
}

Vehicle::~Vehicle(){}
