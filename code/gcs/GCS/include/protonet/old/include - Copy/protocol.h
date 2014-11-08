#ifndef _PROTOCOL_H
#define _PROTOCOL_H
#include <message.h>
#include <message/Enter.h>
#include <message/Exit.h>
#include <message/Ping.h>
#include <message/Pong.h>
#include <message/Raw.h>
#include <message/UGVJoystick.h>
#include <message/AirVehicleGroundRelativeState.h>
#include <message/CommunicationPayloadCommand.h>
#include <message/CommunicationPayloadConfigurationCommand.h>
#include <message/CommunicationPayloadStatus.h>
#include <message/ConnectionReply.h>
#include <message/ConnectionRequest.h>
#include <message/PayloadBayCommand.h>
#include <message/PayloadBayStatus.h>
#include <message/PayloadDataRecorderCommand.h>
#include <message/PayloadDataRecorderStatus.h>
#include <message/PayloadOperationCommand.h>
#include <message/PayloadOperatingStatus.h>
#include <message/VehicleAttitude.h>
#include <message/VehicleAuthorizationRequest.h>
#include <message/VehicleAuthorizationReply.h>
#include <message/VehicleBodySensedState.h>
#include <message/VehicleGlobalPosition.h>
#include <message/VehicleIdentification.h>
#include <message/VehicleInertiaLState.h>
#include <message/VehicleJoystickCommand.h>
#include <message/VehicleModeCommand.h>
#include <message/VehicleSystemStatus.h>
#include <message/VehicleTelemetryCommand.h>
#include <message/VehicleTerminationCommand.h>


/* 
Contains a buffer of every message type, used for internal storage 
and message lookup after parsing
*/
typedef union proto_msg_buf_s
{
	enter_t enter;
	ping_t ping;
	pong_t pong;
	exit_t exit;
	raw_t raw;
	connection_request_t connection_request; 
	connection_reply_t connection_reply;
	vehicle_identification_t vehicle_identification;
	vehicle_authorization_request_t vehicle_authorization_request;
	vehicle_authorization_reply_t vehicle_authorization_reply;
	vehicle_mode_command_t vehicle_mode_command;
	vehicle_joystick_command_t vehicle_joystick_command;
	vehicle_termination_command_t vehicle_termination_command;
	vehicle_telemetry_command_t vehicle_telemetry_command;
	vehicle_system_status_t vehicle_system_status;
	vehicle_inertial_state_t vehicle_inertial_state;
	vehicle_global_position_t vehicle_global_position;
	vehicle_body_sensed_state_t vehicle_body_sensed_state;
	vehicle_attitude_t vehicle_attitude;
	air_vehicle_ground_relative_state_t air_vehicle_ground_relative_state;
	payload_bay_command_t payload_bay_command;
	payload_data_recorder_command_t payload_data_recorder_command;
	communication_payload_command_t communication_payload_command;
	communication_payload_configuration_command_t communication_payload_configuration_command;
	payload_bay_status_t payload_bay_status;
	payload_data_recorder_status_t payload_data_recorder_status; 
	payload_operating_status_t payload_operating_status;
	payload_operation_command_t payload_operation_command;
	communication_payload_status_t communication_payload_status;
	UGV_joystick_t UGV_joystick;
	
}proto_msg_buf_t;


/* Massive switch case statement that returns the message type */
void unpack_proto_msg_t(
		proto_msg_t* msg,
		proto_msg_buf_t* buf);


/* returns a character array with the message type */
char* proto_typestr(proto_msg_type_t msg_type);

#endif