#ifndef _ENTER_H
#define _ENTER_H

#include <marshal.h>
#include <message.h>
typedef struct enter_s
{
	float64_t timestamp;
}enter_t;

msg_offset pack_enter(
		enter_t* enter,
		msg_offset offset);

msg_offset unpack_enter(
		msg_offset offset,
		enter_t* out_ptr);

void encode_enter(
		uint8_t src_id, 
		uint8_t dest_id, 
		uint8_t msg_ttl, 
		uint8_t seq_number,
		enter_t* tx_msg, 
		proto_msg_t* msg);

#endif