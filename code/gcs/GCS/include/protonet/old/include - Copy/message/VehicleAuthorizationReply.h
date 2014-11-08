#ifndef _VEHICLE_AUTHORIZATOIN_REPLY_H
#define _VEHICLE_AUTHORIZATOIN_REPLY_H

#include <marshal.h>
#include <message.h>

typedef struct vehicle_authorization_reply_s
{
	float64_t timestamp;
    uint32_t vehicle_ID;
    uint8_t vehicle_type; //enum
    uint8_t authorization_services; //enum
    uint8_t granted_services; //enum
}vehicle_authorization_reply_t;

msg_offset pack_vehicle_authorization_reply(
        vehicle_authorization_reply_t* vehicle_authorization_reply,
		msg_offset offset);

msg_offset unpack_vehicle_authorization_reply(
		msg_offset offset,
        vehicle_authorization_reply_t* out_ptr);

void encode_vehicle_authorization_reply(
        uint8_t src_id,
        uint8_t dest_id,
        uint8_t msg_ttl,
        uint8_t seq_number,
        vehicle_authorization_reply_t* tx_msg,
        proto_msg_t* msg
        );


#endif
