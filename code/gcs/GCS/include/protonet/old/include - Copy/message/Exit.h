#ifndef _EXIT_H
#define _EXIT_H

#include <marshal.h>
#include <message.h>
typedef struct exit_s
{
	float64_t timestamp;
}exit_t;

msg_offset pack_exit(
		exit_t* exit,
		msg_offset offset);

msg_offset unpack_exit(
		msg_offset offset,
		exit_t* out_ptr);

void encode_exit(
		uint8_t src_id, 
		uint8_t dest_id, 
		uint8_t msg_ttl, 
		uint8_t seq_number,
		exit_t* tx_msg, 
		proto_msg_t* msg);

#endif