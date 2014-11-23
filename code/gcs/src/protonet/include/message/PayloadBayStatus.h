#ifndef _PAYLOAD_BAY_STATUS_H
#define _PAYLOAD_BAY_STATUS_H

#include <marshal.h>
#include <message.h>
typedef struct payload_bay_status_s
{
	float64_t timestamp;
    uint32_t payload_bay_ID;
    uint8_t payload_bay_mode; //enum
    uint8_t payload_bay_status; //enum
}payload_bay_status_t;

msg_offset pack_payload_bay_status(
        payload_bay_status_t* payload_bay_status,
        msg_offset offset);

msg_offset unpack_payload_bay_status(
		msg_offset offset,
        payload_bay_status_t* out_ptr);

void encode_payload_bay_status(
        uint8_t src_id,
        uint8_t dest_id,
        uint8_t msg_ttl,
        uint8_t seq_number,
        payload_bay_status_t* tx_msg,
        proto_msg_t* msg
        );

#endif
