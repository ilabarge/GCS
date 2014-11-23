#include "target.h"

Target::Target()
{
    altitude = NULL;
    latitude = NULL;
    longitude = NULL;
    payload_id = NULL;
    target_id = NULL;
    target_type = NULL;
}

Target::Target(double lat,double longi,double alt,int payid, int targid, int targtype)
{
    altitude = alt;
    latitude = lat;
    longitude = longi;
    payload_id = payid;
    target_id = targid;
    target_type = targtype;
}

double Target::getLatitude() {return latitude;}
double Target::getLongitude() {return longitude;}
double Target::getAltitude(){return altitude;}
int Target::getPayloadID() {return payload_id;}
int Target::getTargetID() {return target_id;}
int Target::getTargetType() {return target_type;}

void Target::setLatitude(double lat) { latitude = lat;}
void Target::setLongitude(double longi) { longitude = longi; }
void Target::setAltitude(double alt) { altitude = alt;}
void Target::setPayloadID(int payid) { payload_id = payid; }
void Target::setTargetID(int targid) { target_id = targid; }
void Target::setTargetType(int targtype) {target_type = targtype; }
