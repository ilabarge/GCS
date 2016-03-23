/**@file This file was autogenerated. All changes will be undone. */

/** Message: UGV_Joystick, ID: 6000*/

#ifndef _UGV_JOYSTICK_H_
#define _UGV_JOYSTICK_H_

#include <comnet_marshal.h>
#include <comnet_message.h>

#include"random_numbers.h"
#include "aes.h"
using CryptoPP::AES;
#include "ccm.h"
using CryptoPP::CFB_Mode;
typedef struct {
   float64_t timestamp;
   uint8_t vehicle_id;
   float32_t steering;
   float32_t throttle;
} UGV_joystick_t;

msg_offset pack_UGV_joystick(
   UGV_joystick_t* UGV_joystick,
   msg_offset offset);

msg_offset unpack_UGV_joystick(
   msg_offset offset,
   UGV_joystick_t* out_ptr);

void encode_UGV_joystick(
   uint8_t src_id,
   uint8_t dest_id,
   uint8_t msg_ttl,
   uint8_t seq_number,
   UGV_joystick_t* tx_msg,
   com_msg_t* msg,
   uint8_t keyArr[]);//key for encryption CryptoPP

#endif