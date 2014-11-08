#ifndef _TARGET_DESIGNATION_COMMAND_H
#define _TARGET_DESIGNATION_COMMAND_H

#include <marshal.h>
#include <message.h>
typedef struct target_designation_command_s
{
	float64_t timestamp;
    uint32_t vehicle_ID;
	uint8_t payload_ID;
	uint8_t target_ID;
	uint8_t target_type;
    int32_t latitude; //Lat*1E7
    int32_t longitude; //Lon*1E7
    int32_t altitude; 
	

}target_designation_command_t;

msg_offset pack_target_designation_command(
        target_designation_command_t* target_designation_command,
        msg_offset offset);

msg_offset unpack_target_designation_command(
		msg_offset offset,
        target_designation_command_t* out_ptr);

void encode_target_designation_command(
        uint8_t src_id,
        uint8_t dest_id,
        uint8_t msg_ttl,
        uint8_t seq_number,
        target_designation_command_t* tx_msg,
        proto_msg_t* msg
        );


#endif 
