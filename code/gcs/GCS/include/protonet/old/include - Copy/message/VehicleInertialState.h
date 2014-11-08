#ifndef _VEHICLE_INERTIAL_STATE_H
#define _VEHICLE_INERTIAL_STATE_H

#include <marshal.h>
#include <message.h>

typedef struct vehicle_inertial_state_s
{
	float64_t timestamp;
    uint32_t vehicle_ID;
    float64_t latitude; //rad
    float64_t longitude; //rad
    float32_t altitude; //m
    float32_t roll; //rad
    float32_t pitch; //rad
    float32_t heading; //rad
    float32_t north_speed; //m/s
    float32_t east_speed; //m/s
    float32_t vertical_speed; //m/s
    float32_t roll_rate; //rad/s
    float32_t pitch_rate; //rad/s
    float32_t yaw_rate; //rad/s
    float32_t north_accel; //rad/s
    float32_t east_accel; //m/s^2
    float32_t vertical_accel; //m/s^2
}vehicle_inertial_state_t;

msg_offset pack_vehicle_inertial_state(
        vehicle_inertial_state_t* vehicle_inertial_state,
        msg_offset offset);

msg_offset unpack_vehicle_inertial_state(
		msg_offset offset,
        vehicle_inertial_state_t* out_ptr);

void encode_vehicle_inertial_state(
        uint8_t src_id,
        uint8_t dest_id,
        uint8_t msg_ttl,
        uint8_t seq_number,
        vehicle_inertial_state_t* tx_msg,
        proto_msg_t* msg
        );

#endif
