#ifndef _VEHICLE_JOYSTICK_COMMAND_H
#define _VEHICLE_JOYSTICK_COMMAND_H

#include <marshal.h>
#include <message.h>

typedef struct vehicle_joystick_command_s
{
    uint8_t vehicle_ID;
    float32_t input_N;
}vehicle_joystick_command_t;

msg_offset pack_vehicle_joystick_command(
        vehicle_joystick_command_t* vehicle_joystick_command,
		msg_offset offset);

msg_offset unpack_vehicle_joystick(
		msg_offset offset,
        vehicle_joystick_command_t* out_ptr);

void encode_vehicle_joystick_command(
        uint8_t src_id,
        uint8_t dest_id,
        uint8_t msg_ttl,
        uint8_t seq_number,
        vehicle_joystick_command_t* tx_msg,
        proto_msg_t* msg
        );

#endif
