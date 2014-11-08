#ifndef _PROTONET_H
#define _PROTONET_H

/* User Includes */
#include <stdio.h>
#include <stdint.h>

/* System Includes */
#include <datalink.h>
#include <protocol.h>
#include <queue.h>
#include <thread.h>


namespace protonet
{
	/* 
	Forward declaration so callbacks can reference protonet::node*,
	and then be used in the class itself 
	*/

	class node;

	/* 
	Typedef of Function pointers that define the signature of a message callbacks. The user will declare
	and define a function that specifies the behaviors executed when the specified message
	is received. The callbacks are called by the event handler in protonet_handler.
	*/
	typedef void* (*enter_callback)(int8_t, proto_header_t, enter_t, protonet::node* node_ptr);
	typedef void* (*ping_callback)(int8_t, proto_header_t, ping_t, protonet::node* node_ptr);
	typedef void* (*pong_callback)(int8_t, proto_header_t, pong_t, protonet::node* node_ptr);
	typedef void* (*raw_callback)(int8_t, proto_header_t, raw_t, protonet::node* node_ptr);
	typedef void* (*connection_request_callback)(int8_t, proto_header_t, connection_request_t, protonet::node* node_ptr);
	typedef void* (*connection_reply_callback)(int8_t, proto_header_t, connection_reply_t, protonet::node* node_ptr);
	typedef void* (*exit_callback)(int8_t, proto_header_t, exit_t, protonet::node* node_ptr);
	typedef void* (*vehicle_identification_callback)(int8_t, proto_header_t, vehicle_identification_t, protonet::node* node_ptr);
	typedef void* (*vehicle_authorization_request_callback)(int8_t, proto_header_t, vehicle_authorization_request_t, protonet::node* node_ptr);
	typedef void* (*vehicle_authorization_reply_callback)(int8_t, proto_header_t, vehicle_authorization_reply_t, protonet::node* node_ptr);
	typedef void* (*vehicle_mode_command_callback)(int8_t, proto_header_t, vehicle_mode_command_t, protonet::node* node_ptr);
	typedef void* (*vehicle_joystick_command_callback)(int8_t, proto_header_t, vehicle_joystick_command_t, protonet::node* node_ptr);
	typedef void* (*vehicle_termination_command_callback)(int8_t, proto_header_t, vehicle_termination_command_t, protonet::node* node_ptr);
	typedef void* (*vehicle_telemetry_command_callback)(int8_t, proto_header_t, vehicle_telemetry_command_t, protonet::node* node_ptr);
	typedef void* (*vehicle_system_status_callback)(int8_t, proto_header_t, vehicle_system_status_t, protonet::node* node_ptr);
	typedef void* (*vehicle_inertial_state_callback)(int8_t, proto_header_t, vehicle_inertial_state_t, protonet::node* node_ptr);
	typedef void* (*vehicle_global_position_callback)(int8_t, proto_header_t, vehicle_global_position_t, protonet::node* node_ptr);
	typedef void* (*vehicle_body_sensed_state_callback)(int8_t, proto_header_t, vehicle_body_sensed_state_t, protonet::node* node_ptr);
	typedef void* (*vehicle_attitude_callback)(int8_t, proto_header_t, vehicle_attitude_t, protonet::node* node_ptr);
	typedef void* (*air_vehicle_ground_relative_state_callback)(int8_t, proto_header_t, air_vehicle_ground_relative_state_t, protonet::node* node_ptr);
	typedef void* (*payload_bay_command_callback)(int8_t, proto_header_t, payload_bay_command_t, protonet::node* node_ptr);
	typedef void* (*payload_data_recorder_command_callback)(int8_t, proto_header_t, payload_data_recorder_command_t, protonet::node* node_ptr);
	typedef void* (*communication_payload_command_callback)(int8_t, proto_header_t, communication_payload_command_t, protonet::node* node_ptr);
	typedef void* (*communication_payload_configuration_command_callback)(int8_t, proto_header_t, communication_payload_configuration_command_t, protonet::node* node_ptr);
	typedef void* (*payload_bay_status_callback)(int8_t, proto_header_t, payload_bay_status_t, protonet::node* node_ptr);
	typedef void* (*payload_data_recorder_status_callback)(int8_t, proto_header_t, payload_data_recorder_status_t, protonet::node* node_ptr);
	typedef void* (*payload_operating_status_callback)(int8_t, proto_header_t, payload_operating_status_t, protonet::node* node_ptr);
	typedef void* (*payload_operation_command_callback)(int8_t, proto_header_t, payload_operation_command_t, protonet::node* node_ptr);
	typedef void* (*communication_payload_status_callback)(int8_t, proto_header_t, communication_payload_status_t, protonet::node* node_ptr);
	typedef void* (*UGV_joystick_callback)(int8_t, proto_header_t, UGV_joystick_t, protonet::node* node_ptr);
	

	/* In Mario's voice: "Here we goooooo" */
	class node
	{
	public: 
		/* Pass in the desired node_id of the system */
		node(uint8_t node_id);
		/* Pass in the desired node_id and mode, note that mode is not implemented */
		node(uint8_t node_id, int32_t mode);
		~node();
		
		/* 
		Start the automatic node entry function, periodically discovers nodes on all
		connected datalinks, akin to DHCP
		*/
		void start();

		/* Message send functions */
		void send_enter();
		void send_exit();
		void send_ping(uint8_t dest_id); 
		void send_pong(uint8_t dest_id);
		void send_raw(uint8_t dest_id, uint8_t* raw, uint16_t length);

		void send_air_vehicle_ground_relative_state(
			uint8_t dest_id,
			float64_t timestamp,
			uint32_t vehicle_ID,
		    float32_t angle_of_attack,
		    float32_t sideslip_angle,
		    float32_t true_air_speed,
		    float32_t indicated_air_speed, 
		    float32_t north_wind_speed,
		    float32_t east_wind_speed, 
		    float32_t north_ground_speed, 
		    float32_t east_ground_speed,
		    float32_t baro_pressure, 
		    float32_t baro_altitude);

		void send_communication_payload_command(
			uint8_t dest_id,
			float64_t timestamp, 
			uint32_t communication_payload_ID, 
			uint8_t communication_payload_command);

		void send_communication_payload_configuration_command(
			uint8_t dest_id,
			float64_t timestamp,
			uint32_t communication_payload_ID,
			uint8_t communication_payload_mode);

		void send_communication_payload_status(
			uint8_t dest_id,
			float64_t timestamp,
			uint32_t communication_ID,
			uint8_t communication_mode, 
			uint8_t communication_status);

		void send_connection_reply(
			uint8_t dest_id,
			float64_t timestamp,
			uint8_t connection_ID,
			uint8_t tracenode_1,
			uint8_t tracenode_N,
			uint8_t tracenode_NPrev);

		void send_connection_request(
			uint8_t dest_id,
			float64_t timestamp,
			uint8_t tracenode_1,
			uint8_t tracenode_N);

		void send_payload_bay_command(
			uint8_t dest_id,
			float64_t timestamp,
			uint32_t payload_bay_ID,
			uint8_t payload_bay_mode);

		void send_payload_bay_status(
			uint8_t dest_id,
			float64_t timestamp,
			uint32_t payload_bay_ID,
		    uint8_t payload_bay_mode,
		    uint8_t payload_bay_status);

		void send_payload_data_recorder_command(
			uint8_t dest_id,
			float64_t timestamp,
		    uint32_t payload_ID,
		    uint8_t payload_record_mode);

		void send_payload_data_recorder_status(
			uint8_t dest_id,
			float64_t timestamp,
			uint8_t data_recorder_mode);

		void send_payload_operating_status(
			uint8_t dest_id,
			float64_t timestamp,
			uint32_t payload_ID,
			uint8_t payload_mode, //enum
			uint8_t payload_status);

		void send_payload_operation_command(
			uint8_t dest_id,
			float64_t timestamp,
			uint32_t payload_ID,
		    uint8_t payload_command);

		void send_vehicle_attitude(
			uint8_t dest_id,
			float64_t timestamp,
			uint32_t vehicle_ID,
		    float32_t roll, //rad
		    float32_t pitch, //rad
		    float32_t yaw);

		void send_vehicle_authorization_reply(
			uint8_t dest_id,
			float64_t timestamp,
			uint32_t vehicle_ID,
			uint8_t vehicle_type, //enum
			uint8_t authorization_services, //enum
			uint8_t granted_services);
		
		void send_vehicle_authorization_request(
			uint8_t dest_id,
			float64_t timestamp,
			uint8_t vehicle_ID,
			uint32_t link_key, //key
			uint8_t request_services, //enum
			uint8_t handover_node);

		void send_vehicle_body_sensed_state(
			uint8_t dest_id,
			float64_t timestamp,
			uint32_t vehicle_ID,
			int16_t x_accel, //g/1000
			int16_t y_accel, //g/1000
			int16_t z_accel, //g/1000
			int16_t roll_rate, //millirad/s
			int16_t pitch_rate, //millirad/s
			int16_t yaw_rate);

		void send_vehicle_global_position(
			uint8_t dest_id, 
			float64_t timestamp,
			uint32_t vehicle_id,
			int32_t latitude,    
			int32_t longitude,
			int32_t altitude,
			int16_t x_speed, 
			int16_t y_speed, 
			int16_t z_speed);

		void send_vehicle_identification(
			uint8_t dest_id,
			float64_t timestamp,
			uint8_t vehicle_ID,
			uint8_t vehicle_type,
			uint8_t owner_ID);

		void send_vehicle_inertial_state(
			uint8_t dest_id,
			float64_t timestamp,
			uint32_t vehicle_ID,
			float64_t latitude, //rad
			float64_t longitude, //rad
			float32_t altitude, //m
			float32_t roll, //rad
			float32_t pitch, //rad
			float32_t heading, //rad
			float32_t north_speed, //m/s
			float32_t east_speed, //m/s
			float32_t vertical_speed, //m/s
			float32_t roll_rate, //rad/s
			float32_t pitch_rate, //rad/s
			float32_t yaw_rate, //rad/s
			float32_t north_accel, //rad/s
			float32_t east_accel, //m/s^2
			float32_t vertical_accel);

		void send_vehicle_joystick_command(
			uint8_t dest_id,
			uint8_t vehicle_ID,
			float32_t input_N);

		void send_vehicle_mode_command(
			uint8_t dest_id,
			float64_t timestamp,
			uint8_t vehicle_ID,
			uint8_t vehicle_mode);

		void send_vehicle_system_status(
			uint8_t dest_id,
			float64_t timestamp,
			uint32_t vehicle_ID,
			uint8_t vehicle_mode, //enum
			uint8_t vehicle_state);

		void send_vehicle_telemetry_command(
			uint8_t dest_id,
			uint8_t vehicle_ID,
			uint8_t telemetry_select, //enum
			uint8_t telemetry_rate);

		void send_vehicle_termination_command(
			uint8_t dest_id,
			uint8_t vehicle_ID,
			uint8_t termination_mode);

		void send_ugv_joystick(
			uint8_t dest_id, 
			uint8_t vehicle_id, 
			float32_t steering, 
			float32_t throttle);

		

		/* Datalink add functions */
		void add_serial(int8_t* link_id, uint32_t baud_rate, char device_path[50]);
		void add_udp(int8_t* link_id, uint16_t port);
		void add_udp(int8_t* link_id, uint16_t port, char addr[16]);

		/* Datalink establish functions */
		void establish_serial(int8_t link_id, uint8_t node_id);
		void establish_udp(int8_t link_id, uint8_t node_id, uint16_t port, char addr[16]);

		uint8_t get_num_datalinks();
		int32_t query_datalink_connected(int8_t link_id);
		datalink_type_t query_datalink_type(int8_t link_id);

		/* 
		Users register callbacks using the register functions 
		Signatures must match.
		*/
		void register_on_enter(enter_callback callback){on_enter = callback;}
		void register_on_exit(exit_callback callback){on_exit = callback;}
		void register_on_ping(ping_callback callback){on_ping = callback;}
		void register_on_pong(pong_callback callback){on_pong = callback;}
		void register_on_raw(raw_callback callback){on_raw = callback;}
		void register_on_connection_request(connection_request_callback callback){on_connection_request = callback;}
	    void register_on_connection_reply(connection_reply_callback callback){on_connection_reply = callback;}
		void register_on_vehicle_identification(vehicle_identification_callback callback){on_vehicle_identification = callback;}
		void register_on_vehicle_authorization_request(vehicle_authorization_request_callback callback){on_vehicle_authorization_request = callback;}
		void register_on_vehicle_authorization_reply(vehicle_authorization_reply_callback callback){on_vehicle_authorization_reply = callback;}
		void register_on_vehicle_mode_command(vehicle_mode_command_callback callback){on_vehicle_mode_command = callback;}
		void register_on_vehicle_joystick_command(vehicle_joystick_command_callback callback){on_vehicle_joystick_command = callback;}
		void register_on_vehicle_termination_command(vehicle_termination_command_callback callback){on_vehicle_termination_command = callback;}
		void register_on_vehicle_telemetry_command(vehicle_telemetry_command_callback callback){on_vehicle_telemetry_command = callback;}
		void register_on_vehicle_system_status(vehicle_system_status_callback callback){on_vehicle_system_status = callback;}
		void register_on_vehicle_inertial_state(vehicle_inertial_state_callback callback){on_vehicle_inertial_state = callback;}
		void register_on_vehicle_global_position(vehicle_global_position_callback callback){on_vehicle_global_position = callback;}
		void register_on_vehicle_body_sensed_state(vehicle_body_sensed_state_callback callback){on_vehicle_body_sensed_state = callback;}
		void register_on_vehicle_attitude(vehicle_attitude_callback callback){on_vehicle_attitude = callback;}
		void register_on_air_vehicle_ground_relative_state(air_vehicle_ground_relative_state_callback callback){on_air_vehicle_ground_relative_state = callback;}
		void register_on_payload_bay_command(payload_bay_command_callback callback){on_payload_bay_command = callback;}
		void register_on_payload_data_recorder_command(payload_data_recorder_command_callback callback){on_payload_data_recorder_command = callback;}
		void register_on_communication_payload_command(communication_payload_command_callback callback){on_communication_payload_command = callback;}
		void register_on_communication_payload_configuration_command(communication_payload_configuration_command_callback callback){on_communication_payload_configuration_command = callback;}
		void register_on_payload_bay_status(payload_bay_status_callback callback){on_payload_bay_status = callback;}
		void register_on_payload_data_recorder_status(payload_data_recorder_status_callback callback){on_payload_data_recorder_status = callback;}
		void register_on_payload_operating_status(payload_operating_status_callback callback){on_payload_operating_status = callback;}
		void register_on_payload_operation_command(payload_operation_command_callback callback){on_payload_operation_command = callback;}
		void register_on_communication_payload_status(communication_payload_status_callback callback){on_communication_payload_status = callback;}
		void register_on_UGV_joystick(UGV_joystick_callback callback){on_UGV_joystick = callback;}
		

	private:

		/* NULLs the callback function pointer storage for error handling in case of undefined callbacks */
		void null_callback_storage();

		/* Provides storage for registered callback functions, internally called by the protonet handler */
		enter_callback on_enter;
		exit_callback on_exit;
		ping_callback on_ping;
		pong_callback on_pong;
		raw_callback on_raw;
		connection_request_callback on_connection_request; 
		connection_reply_callback on_connection_reply;
		vehicle_identification_callback on_vehicle_identification;
		vehicle_authorization_request_callback on_vehicle_authorization_request;
		vehicle_authorization_reply_callback on_vehicle_authorization_reply;
		vehicle_mode_command_callback on_vehicle_mode_command;
		vehicle_joystick_command_callback on_vehicle_joystick_command;
		vehicle_termination_command_callback on_vehicle_termination_command;
		vehicle_telemetry_command_callback on_vehicle_telemetry_command;
		vehicle_system_status_callback on_vehicle_system_status;
		vehicle_inertial_state_callback on_vehicle_inertial_state;
		vehicle_global_position_callback on_vehicle_global_position;
		vehicle_body_sensed_state_callback on_vehicle_body_sensed_state;
		vehicle_attitude_callback on_vehicle_attitude;
		air_vehicle_ground_relative_state_callback on_air_vehicle_ground_relative_state;
		payload_bay_command_callback on_payload_bay_command;
		payload_data_recorder_command_callback on_payload_data_recorder_command;
		communication_payload_command_callback on_communication_payload_command;
		communication_payload_configuration_command_callback on_communication_payload_configuration_command;
		payload_bay_status_callback on_payload_bay_status;
		payload_data_recorder_status_callback on_payload_data_recorder_status; 
		payload_operating_status_callback on_payload_operating_status;
		payload_operation_command_callback on_payload_operation_command;
		communication_payload_status_callback on_communication_payload_status;
		UGV_joystick_callback on_UGV_joystick;
		

		uint8_t node_id;
	
		/* Datalink storage, dynamically allocated for now */
		datalink* datalinks[255];
		int8_t num_datalinks;

		/* Thread safe message queue used to pass messages between client, protonet_handler, and datalinks */
		proto_msg_queue queue;


		/* 
		Main entry point for protonet behavior.
		On receive, messages are removed from the queue, data unpacked, and handled based on message type
		On transmit, messages are sent over desired datalinks
		*/
		void* protonet_handler();
		/*
		Performs callbacks based on message type.
		*/
		void handle_proto_msg_t(proto_msg_t* rx_msg, proto_msg_buf_t* rx_buf);
		/*
		Helper function to convert between C++ and C function signatures
		due to casting as a class member being incompatible with C style
		thread creation APIs. Static linkage helps with that.
		*/
		static void *handler_helper(void* context);
		/* Thread handle */
		thread_t handler_thread;


		/*
		Takes care of automatic node discovery by repeatedly sending entry messages
		*/
		void* upkeep_handler();
		/* Similar to handler_helper, except for upkeep thread*/
		static void *upkeep_helper(void* context);
		thread_t upkeep_thread;


		thread_t IRC_thread;
		thread_t datalink_threads[255];
	};
}

#endif
