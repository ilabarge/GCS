#ifndef _VEHICLE_WAYPOINT_COMMAND_H
#define _VEHICLE_WAYPOINT_COMMAND_H

#include <marshal.h>
#include <message.h>

typedef struct vehicle_waypoint_command_s
{
	/*
	vehicle ID
	Latitude
	Longitude
	altitude
	type
	waypoint id
	*/
    uint8_t vehicle_ID;
	int32_t latitude;
	int32_t longitude;
	int32_t altitude;
	uint8_t type;
	uint8_t waypoint_ID;
}vehicle_waypoint_command_t;

msg_offset pack_vehicle_waypoint_command(
        vehicle_waypoint_command_t* vehicle_waypoint_command,
		msg_offset offset);

msg_offset unpack_vehicle_waypoint_command(
		msg_offset offset,
        vehicle_waypoint_command_t* out_ptr);

void encode_vehicle_waypoint_command(
        uint8_t src_id,
        uint8_t dest_id,
        uint8_t msg_ttl,
        uint8_t seq_number,
        vehicle_waypoint_command_t* tx_msg,
        proto_msg_t* msg
        );
#endif