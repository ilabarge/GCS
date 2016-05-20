/**@file This file was autogenerated. All changes will be undone. */

/** Message: UAV_Location, ID: 6000*/

#ifndef _UAV_LOCATION_H_
#define _UAV_LOCATION_H_

#include <comnet_marshal.h>
#include <comnet_message.h>

#include"random_numbers.h"
#include "aes.h"
using CryptoPP::AES;
#include "ccm.h"
using CryptoPP::CFB_Mode;
typedef struct {
   float64_t timestamp;
   float64_t longitude;
   float64_t latitude;
   float64_t altitude;
} UAV_location_t;

msg_offset pack_UAV_location(
   UAV_location_t* UAV_location,
   msg_offset offset);

msg_offset unpack_UAV_location(
   msg_offset offset,
   UAV_location_t* out_ptr);

void encode_UAV_location(
   uint8_t src_id,
   uint8_t dest_id,
   UAV_location_t* tx_msg,
   com_msg_t* msg,
   uint8_t keyArr[]);//key for encryption CryptoPP

#endif