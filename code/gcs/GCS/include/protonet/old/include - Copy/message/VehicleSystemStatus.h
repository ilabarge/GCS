#ifndef _VEHICLE_SYSTEM_STATUS_H
#define _VEHICLE_SYSTEM_STATUS_H

#include <marshal.h>
#include <message.h>
typedef struct vehicle_system_status_s
{
	float64_t timestamp;
    uint32_t vehicle_ID;
    uint8_t vehicle_mode; //enum
    uint8_t vehicle_state; //enum
}vehicle_system_status_t;

msg_offset pack_vehicle_system_status(
        vehicle_system_status_t* vehicle_system_status,
        msg_offset offset);

msg_offset unpack_vehicle_system_status(
		msg_offset offset,
        vehicle_system_status_t* out_ptr);

void encode_vehicle_system_status(
        uint8_t src_id,
        uint8_t dest_id,
        uint8_t msg_ttl,
        uint8_t seq_number,
        vehicle_system_status_t* tx_msg,
        proto_msg_t* msg
        );

#endif
