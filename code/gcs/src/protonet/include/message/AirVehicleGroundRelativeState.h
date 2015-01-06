#ifndef _AIR_VEHICLE_GROUND_RELATIVE_STATE_H
#define _AIR_VEHICLE_GROUND_RELATIVE_STATE_H

#include <marshal.h>
#include <message.h>

typedef struct air_vehicle_ground_relative_state_s
{
	float64_t timestamp;
    uint32_t vehicle_ID;
    float32_t angle_of_attack; //rad
    float32_t sideslip_angle; //rad
    float32_t true_air_speed; //rad
    float32_t indicated_air_speed; //m/s
    float32_t north_wind_speed; //m/s
    float32_t east_wind_speed; //m/s
    float32_t north_ground_speed; //m/s
    float32_t east_ground_speed; //m/s
    float32_t baro_pressure; //pascal
    float32_t baro_altitude; //m
}air_vehicle_ground_relative_state_t;

msg_offset pack_air_vehicle_ground_relative_state(
	air_vehicle_ground_relative_state_t* air_vehicle_ground_relative_state,
        msg_offset offset);

msg_offset unpack_air_vehicle_ground_relative_state(
		msg_offset offset,
        air_vehicle_ground_relative_state_t* out_ptr);

void encode_air_vehicle_ground_relative_state(
        uint8_t src_id,
        uint8_t dest_id,
        uint8_t msg_ttl,
        uint8_t seq_number,
        air_vehicle_ground_relative_state_t* tx_msg,
        proto_msg_t* msg
        );

#endif
