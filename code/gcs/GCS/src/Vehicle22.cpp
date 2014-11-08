#include "Vehicle22.h"

#include <QMutex>
#include <QMutexLocker>

#include <QDebug>

Vehicle22::Vehicle22(QObject *parent) :
    MapSymbol22(parent)
{
    needsUpdate = false;
}

Vehicle22::Vehicle22(int vehicleID,    int vehicleType,  double altitude,
                     int mode,         int state,        int batteryStatus,
                     double latitude,  double longitude, double heading,
                     double xAccel,    double yAccel,    double rollRate,
                     double pitchRate, double yawRate,   double velocity,
                     double roll,      double pitch,     double yaw){
    vID = vehicleID;
    vType = vehicleType;
    alt = altitude;
    this->mode = mode;
    this->state = state;
    this->batteryStatus = batteryStatus;
    lat = latitude;
    lon = longitude;
    this->heading = heading;
    this->xAccel = xAccel;
    this->yAccel = yAccel;
    this->zAccel = zAccel;
    this->rollRate = rollRate;
    this->pitchRate = pitchRate;
    this->yawRate = yawRate;
    vel = velocity;
    this->roll = roll;
    this->pitch = pitch;
    this->yaw = yaw;

    needsUpdate = true;

    color = Qt::black;
}

void Vehicle22::setVehicleID(int vehicleID){
    QMutexLocker l(&mx);
    vID = vehicleID;
    needsUpdate = true;
}
void Vehicle22::setVehicleType(int vehicleType){
    QMutexLocker l(&mx);
    vType = vehicleType;
    needsUpdate = true;
}
void Vehicle22::setAltitude(int altitude) {
    QMutexLocker l(&mx);
    alt = altitude;
    needsUpdate = true;
}
void Vehicle22::setMode(int mode) {
    QMutexLocker l(&mx);
    this->mode = mode;
    needsUpdate = true;
}
void Vehicle22::setState(int state) {
    QMutexLocker l(&mx);
    this->state = state;
    needsUpdate = true;
}
void Vehicle22::setBatteryStatus(int batteryStatus) {
    QMutexLocker l(&mx);
    this->batteryStatus = batteryStatus;
    needsUpdate = true;
}
void Vehicle22::setLatitude(double latitude) {
    QMutexLocker l(&mx);
    this->lat = latitude;
    needsUpdate = true;
}
void Vehicle22::setLongitude(double longitude) {
    QMutexLocker l(&mx);
    this->lon = longitude;
    needsUpdate = true;
}
void Vehicle22::setHeading(double heading) {
    QMutexLocker l(&mx);
    this->heading = heading;
    needsUpdate = true;
}
void Vehicle22::setXAcceleration(double xAcceleration) {
    QMutexLocker l(&mx);
    this->xAccel = xAcceleration;
    needsUpdate = true;
}
void Vehicle22::setYAcceleration(double yAcceleration) {
    QMutexLocker l(&mx);
    this->yAccel = yAcceleration;
    needsUpdate = true;
}
void Vehicle22::setZAcceleration(double zAcceleration) {
    QMutexLocker l(&mx);
    this->zAccel = zAcceleration;
    needsUpdate = true;
}
void Vehicle22::setRollRate(double rollRate) {
    QMutexLocker l(&mx);
    this->rollRate = rollRate;
    needsUpdate = true;
}
void Vehicle22::setPitchRate(double pitchRate) {
    QMutexLocker l(&mx);
    this->pitchRate = pitchRate;
    needsUpdate = true;
}
void Vehicle22::setYawRate(double yawRate) {
    QMutexLocker l(&mx);
    this->yawRate = yawRate;
    needsUpdate = true;
}
void Vehicle22::setVelocity(double velocity) {
    QMutexLocker l(&mx);
    this->vel = velocity;
    needsUpdate = true;
}
void Vehicle22::setRoll(double roll) {
    QMutexLocker l(&mx);
    this->roll = roll;
    needsUpdate = true;
}
void Vehicle22::setPitch(double pitch) {
    QMutexLocker l(&mx);
    this->pitch = pitch;
    needsUpdate = true;
}
void Vehicle22::setYaw(double yaw) {
    QMutexLocker l(&mx);
    this->yaw = yaw;
    needsUpdate = true;
}
void Vehicle22::setXVelocity(double xVel) {
    QMutexLocker l(&mx);
    this->xVel = xVel;
    needsUpdate = true;
}
void Vehicle22::setYVelocity(double yVel) {
    QMutexLocker l(&mx);
    this->yVel = yVel;
    needsUpdate = true;
}
void Vehicle22::setZVelocity(double zVel) {
    QMutexLocker l(&mx);
    this->zVel = zVel;
    needsUpdate = true;
}

Waypoint22* Vehicle22::getWaypoint(int index){
    if(!validIndex(index)){ return NULL; }

    //Lock data
    QMutexLocker l(&mx);
    return waypoints.at(index);
}

bool Vehicle22::appendWaypoint(Waypoint22* wp, QColor color){
    QMutexLocker l(&mx);
    waypoints.push_back(wp);
    emit addWaypointGraphic( wp, color );
    updateWaypoints((int)waypoints.size() - 2, -1, (int)waypoints.size() - 1);
    return true;
}

bool Vehicle22::removeWaypoint(int index){
    if(!validIndex(index)){ return false; }

    //Lock the data for ourselves
    QMutexLocker l(&mx);

    //Remove the line and waypoint
    emit removeWaypointGraphic(waypoints.at(index)->getGraphicID(), waypoints.at(index)->getLineGraphicID());

    if(index == 0){
        //Ignore because we're just removing the first waypoint
        //graphic and its line graphic
    }
    //We will have at least two after delete
    else if(waypoints.size() > 2){
        if(index == (waypoints.size() - 1) ){
            waypoints.at(index-1)->clearNextWaypoint();
            emit updateWaypointGraphics(waypoints.at(index-1));
        }
        else{
            updateWaypoints(index - 1, -1, index +1);
        }
    }
    //We have one waypoint left after delete
    else if(waypoints.size() == 2){
        //Just tell the waypoint it's all alone... :(

        //If it's the second waypoint we just need to tell
        //the first waypoint it has no next waypoint.
        if(index == 1){
            waypoints.at(index-1)->clearNextWaypoint();
            emit updateWaypointGraphics(waypoints.at(index-1));
        }

        //Otherwise, the second waypoint doesn't have a line
        //drawn to anything, so we can just leave it.
    }
    //We have no waypoints after delete
    else if(waypoints.size() == 1){
        //Don't really need to redraw anything because graphic
        //was already removed.
    }

    delete waypoints.at(index);
    waypoints.at(index) = NULL;
    waypoints.erase(waypoints.begin() + index);

    return true;
}

bool Vehicle22::insertWaypoint(int index, Waypoint22* wp, QColor color){
    if(!validIndex(index)){ return false; }

    //Lock the data for ourselves
    QMutexLocker l(&mx);

    //Insert the waypoint into the list
    waypoints.insert(waypoints.begin() + index, wp);
    emit addWaypointGraphic(waypoints.at(index), color );

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

int Vehicle22::numWaypoints(){
    //Lock data
    QMutexLocker l(&mx);
    return (int)waypoints.size();
}

void Vehicle22::updateWaypoints(int first, int middle, int last){

    //Don't need mutex because it's a private function
    //and is only called after a mutex lock.

    //Check to see if drawing only the first waypoint
    if(middle == -1){
        //Check to see if we're drawing the first element
        if(first == -1){
            waypoints.at(last)->setNextWaypoint(
                        waypoints.at(last)->getLatitude(),
                        waypoints.at(last)->getLongitude());
            emit updateWaypointGraphics(waypoints.at(last));
        }
        //Not the first
        else{
            waypoints.at(first)->setNextWaypoint(
                        waypoints.at(last)->getLatitude(),
                        waypoints.at(last)->getLongitude());
            emit updateWaypointGraphics(waypoints.at(first));
        }
    }
    //We're inserting a waypoint, so need to draw two
    //waypoints
    else{
        //First, make the first waypoint point to the inserted
        //waypoint

        //Make the first connect to the middle
        waypoints.at(first)->setNextWaypoint(
                    waypoints.at(middle)->getLatitude(),
                    waypoints.at(middle)->getLongitude());
        //Make the middle connect to the last
        waypoints.at(middle)->setNextWaypoint(
                    waypoints.at(last)->getLatitude(),
                    waypoints.at(last)->getLongitude());
        emit updateWaypointGraphics(waypoints.at(first));
        emit updateWaypointGraphics(waypoints.at(middle));
    }
}

bool Vehicle22::validIndex(int index){
    if(index < 0 || index > waypoints.size() - 1){
        return false;
    }
    return true;
}
