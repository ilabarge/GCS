//GCS includes
#include "MapSymbol22.h"

#ifndef TARGET_H
#define TARGET_H


class Target : public MapSymbol22
{
public:
    Target();
    explicit Target(double lat, double longi, double alt, int payid, int targid, int targtype);

    double getLatitude();
    double getLongitude();
    double getAltitude();
    int getPayloadID();
    int getTargetID();
    int getTargetType();

    void setLatitude(double);
    void setLongitude(double);
    void setAltitude(double);
    void setPayloadID(int);
    void setTargetID(int);
    void setTargetType(int);

private:
    double altitude;
    double latitude;
    double longitude;
    int payload_id;
    int target_id;
    int target_type;
};

#endif // TARGET_H
