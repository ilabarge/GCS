#ifndef _VEHICLE_BODY_SENSED_STATE_H
#define _VEHICLE_BODY_SENSED_STATE_H

#include <marshal.h>
#include <message.h>

typedef struct vehicle_body_sensed_state_s
{
	float64_t timestamp;
    uint32_t vehicle_ID;
    int16_t x_accel; //g/1000
    int16_t y_accel; //g/1000
    int16_t z_accel; //g/1000
    int16_t roll_rate; //millirad/s
    int16_t pitch_rate; //millirad/s
    int16_t yaw_rate; //millirad/s
}vehicle_body_sensed_state_t;

msg_offset pack_vehicle_body_sensed_state(
        vehicle_body_sensed_state_t* vehicle_body_sensed_state,
        msg_offset offset);

msg_offset unpack_vehicle_body_sensed_state(
		msg_offset offset,
        vehicle_body_sensed_state_t* out_ptr);

void encode_vehicle_body_sensed_state(
        uint8_t src_id,
        uint8_t dest_id,
        uint8_t msg_ttl,
        uint8_t seq_number,
        vehicle_body_sensed_state_t* tx_msg,
        proto_msg_t* msg
        );


#endif
