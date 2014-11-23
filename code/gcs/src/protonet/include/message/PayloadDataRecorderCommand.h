#ifndef _PAYLOAD_DATA_RECORDER_COMMAND_H
#define _PAYLOAD_DATA_RECORDER_COMMAND_H

#include <marshal.h>
#include <message.h>
typedef struct payload_data_recorder_command_s
{
	float64_t timestamp;
    uint32_t payload_ID;
    uint8_t payload_record_mode; //enum
}payload_data_recorder_command_t;

msg_offset pack_payload_data_recorder_command(
        payload_data_recorder_command_t* payload_data_recorder_command,
        msg_offset offset);

msg_offset unpack_payload_data_recorder_command(
		msg_offset offset,
        payload_data_recorder_command_t* out_ptr);

void encode_payload_data_recorder_command(
        uint8_t src_id,
        uint8_t dest_id,
        uint8_t msg_ttl,
        uint8_t seq_number,
        payload_data_recorder_command_t* tx_msg,
        proto_msg_t* msg
        );

#endif
