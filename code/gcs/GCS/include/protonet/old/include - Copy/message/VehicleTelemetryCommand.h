#ifndef _VEHICLE_TELEMENTRY_COMMAND_H
#define _VEHICLE_TELEMENTRY_COMMAND_H

#include <marshal.h>
#include <message.h>
typedef struct vehicle_telemetry_command_s
{
    uint8_t vehicle_ID;
    uint8_t telemetry_select; //enum
    uint8_t telemetry_rate; //ms
}vehicle_telemetry_command_t;

msg_offset pack_vehicle_telemetry_command(
        vehicle_telemetry_command_t* vehicle_telemetry_command,
        msg_offset offset);

msg_offset unpack_vehicle_telemetry_command(
		msg_offset offset,
        vehicle_telemetry_command_t* out_ptr);

void encode_vehicle_telemetry_command(
        uint8_t src_id,
        uint8_t dest_id,
        uint8_t msg_ttl,
        uint8_t seq_number,
        vehicle_telemetry_command_t* tx_msg,
        proto_msg_t* msg
        );

#endif
