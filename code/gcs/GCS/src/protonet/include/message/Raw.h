#ifndef _RAW_H
#define _RAW_H

#include <marshal.h>
#include <message.h>
typedef struct raw_s
{
	uint16_t length;
	uint8_t data[512];
}raw_t;

msg_offset pack_raw(
		raw_t* Raw,
		msg_offset offset);

msg_offset unpack_raw(
		msg_offset offset,
		raw_t* out_ptr);

void encode_raw(
		uint8_t src_id, 
		uint8_t dest_id, 
		uint8_t msg_ttl, 
		uint8_t seq_number,
		raw_t* tx_msg, 
		proto_msg_t* msg);

#endif
