#ifndef _COMMUNICATION_PAYLOAD_STATUS_H
#define _COMMUNICATION_PAYLOAD_STATUS_H

#include <marshal.h>
#include <message.h>

typedef struct communication_payload_status_s
{
	float64_t timestamp;
    uint32_t communication_ID;
    uint8_t communication_mode; //enum
    uint8_t communication_status; //enum
}communication_payload_status_t;

msg_offset pack_communication_payload_status(
        communication_payload_status_t* communication_payload_status,
        msg_offset offset);

msg_offset unpack_communication_payload_status(
		msg_offset offset,
        communication_payload_status_t* out_ptr);

void encode_communication_payload_status(
        uint8_t src_id,
        uint8_t dest_id,
        uint8_t msg_ttl,
        uint8_t seq_number,
        communication_payload_status_t* tx_msg,
        proto_msg_t* msg
        );

#endif
