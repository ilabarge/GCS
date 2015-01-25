#ifndef _CONNECTION_REPLY_MESSAGE_H
#define _CONNECTION_REPLY_MESSAGE_H

#include <marshal.h>
#include <message.h>
typedef struct connection_reply_s
{
	float64_t timestamp;
    uint8_t connection_ID;
    uint8_t tracenode_1;
    uint8_t tracenode_N;
    uint8_t tracenode_NPrev;
}connection_reply_t;

msg_offset pack_connection_reply(
        connection_reply_t* connection_reply,
		msg_offset offset);

msg_offset unpack_connection_reply(
		msg_offset offset,
        connection_reply_t* out_ptr);

void encode_connection_reply(
        uint8_t src_id,
        uint8_t dest_id,
        uint8_t msg_ttl,
        uint8_t seq_number,
        connection_reply_t* tx_msg,
        proto_msg_t* msg
        );

#endif
