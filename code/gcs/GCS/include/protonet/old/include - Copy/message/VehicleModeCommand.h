#ifndef _VEHICLE_MODE_COMMAND_H
#define _VEHICLE_MODE_COMMAND_H

#include <marshal.h>
#include <message.h>

typedef struct vehicle_mode_command_s
{
	float64_t timestamp;
    uint8_t vehicle_ID;
    uint8_t vehicle_mode; //enum
}vehicle_mode_command_t;

msg_offset pack_vehicle_mode_command(
        vehicle_mode_command_t* vehicle_mode_command,
        msg_offset offset);

msg_offset unpack_vehicle_mode_command(
		msg_offset offset,
        vehicle_mode_command_t* out_ptr);

void encode_vehicle_mode_command(
        uint8_t src_id,
        uint8_t dest_id,
        uint8_t msg_ttl,
        uint8_t seq_number,
        vehicle_mode_command_t* tx_msg,
        proto_msg_t* msg
        );

#endif
