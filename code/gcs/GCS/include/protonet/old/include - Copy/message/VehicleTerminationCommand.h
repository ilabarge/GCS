#ifndef _VEHICLE_TERMINATION_COMMAND_H
#define _VEHICLE_TERMINATION_COMMAND_H

#include <marshal.h>
#include <message.h>
typedef struct vehicle_termination_command_s
{
	uint8_t vehicle_ID;
	uint8_t termination_mode;
}vehicle_termination_command_t;

msg_offset pack_vehicle_termination_command(
        vehicle_termination_command_t* vehicle_termination_command,
		msg_offset offset);


msg_offset unpack_vehicle_termination_command(
		msg_offset offset,
        vehicle_termination_command_t* out_ptr);


void encode_vehicle_termination_command(
        uint8_t src_id,
        uint8_t dest_id,
        uint8_t msg_ttl,
        uint8_t seq_number,
        vehicle_termination_command_t* tx_msg,
        proto_msg_t* msg
        );
#endif