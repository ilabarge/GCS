#ifndef _PAYLOAD_OPERATION_COMMAND_H
#define _PAYLOAD_OPERATION_COMMAND_H

#include <marshal.h>
#include <message.h>
typedef struct payload_operation_command_s
{
	float64_t timestamp;
    uint32_t payload_ID;
    uint8_t payload_command; //enum
}payload_operation_command_t;

msg_offset pack_payload_operation_command(
        payload_operation_command_t* payload_operation_command,
        msg_offset offset);

msg_offset unpack_payload_operation_command(
		msg_offset offset,
        payload_operation_command_t* out_ptr);


void encode_payload_operation_command(
        uint8_t src_id,
        uint8_t dest_id,
        uint8_t msg_ttl,
        uint8_t seq_number,
        payload_operation_command_t* tx_msg,
        proto_msg_t* msg
        );



#endif
