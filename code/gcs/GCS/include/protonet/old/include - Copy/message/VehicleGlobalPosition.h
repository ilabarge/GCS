#ifndef _VEHICLE_GLOBAL_POSITION_H
#define _VEHICLE_GLOBAL_POSITION_H

#include <marshal.h>
#include <message.h>
typedef struct vehicle_global_position_s
{
	float64_t timestamp;
    uint32_t vehicle_ID;
    int32_t latitude; //Lat*1E7
    int32_t longitude; //Lon*1E7
    int32_t altitude; //mm
    int16_t x_speed; //m/s*100
    int16_t y_speed; //m/s*100
    int16_t z_speed; //m/s*100

}vehicle_global_position_t;

msg_offset pack_vehicle_global_position(
        vehicle_global_position_t* vehicle_global_position,
        msg_offset offset);

msg_offset unpack_vehicle_global_position(
		msg_offset offset,
        vehicle_global_position_t* out_ptr);

void encode_vehicle_global_position(
        uint8_t src_id,
        uint8_t dest_id,
        uint8_t msg_ttl,
        uint8_t seq_number,
        vehicle_global_position_t* tx_msg,
        proto_msg_t* msg
        );


#endif 
