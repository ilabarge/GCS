#ifndef MSG_H_
#define MSG_H_

/* System Includes */
#include <stdint.h>
#include <stdio.h>

/* User Includes */
#include <marshal.h>

/* Protonet Header Struct */
typedef struct proto_header_s
{
	uint8_t node_src_id; 
	uint8_t node_dest_id;
	uint8_t sequence_number;
	uint8_t message_ttl;
	uint16_t message_type;
	uint16_t message_length;
}proto_header_t;

/* Two's complement checksum at the end of a message */
typedef int8_t checksum_t;


/* Denotes whether a message is inbound or outbound*/
typedef enum proto_direction
{
	Proto_Out = 0,
	Proto_In = 1
}proto_direction_t;

/* 
General message storage for passing data between handler threads,
parsing routines, and encoding routines. Used frequently 
*/
typedef struct proto_msg_s
{
	proto_header_t header;
	proto_direction_t direction;
	uint8_t link_id;
	uint8_t data[540]; /* Raw data from parser/serialization */
	uint16_t tx_len;
	checksum_t checksum; 
}proto_msg_t;


/* Packs the start sequence (CPP0) at a specified offset */
msg_offset pack_sync(msg_offset offset);


/* 
Calculates and packs the checksum given the beginning and end
of a message that has been packed into a buffer
*/
msg_offset pack_checksum(
		const msg_offset start,
		const msg_offset end);

msg_offset pack_header(
		proto_header_t* header,
		msg_offset offset);

msg_offset unpack_header(
		msg_offset offset,
		proto_header_t* out_ptr);


/* Enumerates message type for ease of access */
typedef enum proto_msg_type 
{
	Proto_Enter = 0,
	Proto_Exit = 1,
	Proto_Ping = 2,
	Proto_Pong = 3,
    Proto_Raw = 5,
    Proto_Connection_Request = 6,
    Proto_Connection_Reply = 7,
    Proto_Vehicle_Identification = 8,
    Proto_Vehicle_Authorization_Request = 9,
    Proto_Vehicle_Authorization_Reply = 10,
    Proto_Vehicle_Mode_Command = 11,
    Proto_Vehicle_Joystick_Command = 12,
    Proto_Vehicle_Termination_Command = 13,
    Proto_Vehicle_Telemetry_Command = 14,
    Proto_Vehicle_System_Status = 15,
    Proto_Vehicle_Inertial_State = 16,
    Proto_Vehicle_Global_Position = 17,
    Proto_Vehicle_Body_Sensed_State = 18,
    Proto_Vehicle_Attitude = 19,
    Proto_Air_Vehicle_Ground_Relative_State = 20,
    Proto_Payload_Bay_Command = 21,
    Proto_Payload_Data_Recorder_Command = 22,
    Proto_Payload_Operation_Command = 23,
    Proto_Communication_Payload_Command = 24,
    Proto_Communication_Payload_Configuration_Command = 25,
    Proto_Payload_Bay_Status = 26,
    Proto_Payload_Data_Recorder_Status = 27,
    Proto_Payload_Operating_Status = 28,
    Proto_Communication_Payload_Status = 29,
	Proto_UGV_Joystick = 30
} proto_msg_type_t;




#endif /* MSG_H_ */
