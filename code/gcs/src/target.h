//GCS includes
#include "MapSymbol22.h"

#ifndef TARGET_H
#define TARGET_H


class Target : public MapSymbol22
{
public:
    Target();
    explicit Target(double lat, double longi, double alt, int payid, int targid, int targtype, int vechid);

    double getLatitude();
    double getLongitude();
    double getAltitude();
    int getPayloadID();
    int getTargetID();
    int getTargetType();
    int getVehicleID();

    void setLatitude(double);
    void setLongitude(double);
    void setAltitude(double);
    void setPayloadID(int);
    void setTargetID(int);
    void setTargetType(int);
    void setVehicleID(int);

private:
    double altitude;
    double latitude;
    double longitude;
    int payload_id;
    int target_id;
    int target_type;
    int vehicle_id;
};

#endif // TARGET_H
