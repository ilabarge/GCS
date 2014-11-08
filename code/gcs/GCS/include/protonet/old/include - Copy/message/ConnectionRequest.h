#ifndef _CONNECTION_REQUEST_H
#define _CONNECTION_REQUEST_H

#include <marshal.h>
#include <message.h>

typedef struct connection_request_s
{
	float64_t timestamp;
    uint8_t tracenode_1;
    uint8_t tracenode_N;
}connection_request_t;

msg_offset pack_connection_request(
        connection_request_t* connection_request,
		msg_offset offset);

msg_offset unpack_connection_request(
		msg_offset offset,
        connection_request_t* out_ptr);

void encode_connection_request(
        uint8_t src_id,
        uint8_t dest_id,
        uint8_t msg_ttl,
        uint8_t seq_number,
        connection_request_t* tx_msg,
        proto_msg_t* msg
        );

#endif
