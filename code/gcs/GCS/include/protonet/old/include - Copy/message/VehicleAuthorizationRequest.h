#ifndef _VEHICLE_AUTHORIZATION_REQUEST_H
#define _VEHICLE_AUTHORIZATION_REQUEST_H

#include <marshal.h>
#include <message.h>

typedef struct vehicle_authorization_request_s
{
	float64_t timestamp;
    uint8_t vehicle_ID;
    uint32_t link_key; //key
    uint8_t request_services; //enum
    uint8_t handover_node; //enum
}vehicle_authorization_request_t;

msg_offset pack_vehicle_authorization_request(
        vehicle_authorization_request_t* vehicle_authorization_request,
		msg_offset offset);

msg_offset unpack_vehicle_authorization_request(
		msg_offset offset,
        vehicle_authorization_request_t* out_ptr);

void encode_vehicle_authorization_request(
        uint8_t src_id,
        uint8_t dest_id,
        uint8_t msg_ttl,
        uint8_t seq_number,
        vehicle_authorization_request_t* tx_msg,
        proto_msg_t* msg
        );

#endif
