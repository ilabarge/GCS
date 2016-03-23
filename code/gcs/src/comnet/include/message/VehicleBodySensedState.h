/**@file This file was autogenerated. All changes will be undone. */

/** Message: Vehicle_Body_Sensed_State, ID: 2003*/

#ifndef _VEHICLE_BODY_SENSED_STATE_H_
#define _VEHICLE_BODY_SENSED_STATE_H_

#include <comnet_marshal.h>
#include <comnet_message.h>

#include"random_numbers.h"
#include "aes.h"
using CryptoPP::AES;
#include "ccm.h"
using CryptoPP::CFB_Mode;
typedef struct {
   float64_t timestamp;
   uint16_t vehicle_ID;
   int16_t x_accel;
   int16_t y_accel;
   int16_t z_accel;
   int16_t roll_rate;
   int16_t pitch_rate;
   int16_t yaw_rate;
} vehicle_body_sensed_state_t;

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
   com_msg_t* msg,
   uint8_t keyArr[]);//key for encryption CryptoPP

#endif