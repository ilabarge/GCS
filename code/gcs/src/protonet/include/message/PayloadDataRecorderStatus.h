#ifndef _PAYLOAD_DATA_RECORDER_STATUS_H
#define _PAYLOAD_DATA_RECORDER_STATUS_H

#include <marshal.h>
#include <message.h>
typedef struct payload_data_recorder_status_s
{
	float64_t timestamp;
    uint8_t data_recorder_mode; //enum
}payload_data_recorder_status_t;

msg_offset pack_payload_data_recorder_status(
        payload_data_recorder_status_t* payload_data_recorder_status,
        msg_offset offset);

msg_offset unpack_payload_data_recorder_status(
		msg_offset offset,
        payload_data_recorder_status_t* out_ptr);

void encode_payload_data_recorder_status(
        uint8_t src_id,
        uint8_t dest_id,
        uint8_t msg_ttl,
        uint8_t seq_number,
        payload_data_recorder_status_t* tx_msg,
        proto_msg_t* msg
        );

#endif
