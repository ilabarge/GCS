#ifndef _COMMUNICATION_PAYLOAD_COMMAND_H
#define _COMMUNICATION_PAYLOAD_COMMAND_H

#include <marshal.h>
#include <message.h>

typedef struct communication_payload_command_s
{
	float64_t timestamp;
    uint32_t communication_payload_ID;
    uint8_t communication_payload_command; //enum
}communication_payload_command_t;

msg_offset pack_communication_payload_command(
        communication_payload_command_t* communication_payload_command,
        msg_offset offset);

msg_offset unpack_communication_payload_command(
		msg_offset offset,
        communication_payload_command_t* out_ptr);

void encode_communication_payload_command(
        uint8_t src_id,
        uint8_t dest_id,
        uint8_t msg_ttl,
        uint8_t seq_number,
        communication_payload_command_t* tx_msg,
        proto_msg_t* msg
        );


#endif
