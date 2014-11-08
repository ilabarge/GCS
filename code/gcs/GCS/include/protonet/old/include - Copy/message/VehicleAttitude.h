#ifndef _VEHICICLE_ATTITUDE_H
#define _VEHICICLE_ATTITUDE_H

#include <marshal.h>
#include <message.h>

typedef struct vehicle_attitude_s
{
	float64_t timestamp;
    uint32_t vehicle_ID;
    float32_t roll; //rad
    float32_t pitch; //rad
    float32_t yaw; //rad
}vehicle_attitude_t;

msg_offset pack_vehicle_attitude(
        vehicle_attitude_t* vehicle_attitude,
        msg_offset offset);

msg_offset unpack_vehicle_attitude(
		msg_offset offset,
        vehicle_attitude_t* out_ptr);

void encode_vehicle_attitude(
        uint8_t src_id,
        uint8_t dest_id,
        uint8_t msg_ttl,
        uint8_t seq_number,
        vehicle_attitude_t* tx_msg,
        proto_msg_t* msg
        );

#endif
