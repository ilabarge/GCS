/* This file was autogenerated. All changes will be undone. */

#ifndef _COMNET_H_
#define _COMNET_H_

#include <datalink.h>
#include <comnet_protocol.h>
#include <queue.h>
#include <thread.h>

namespace comnet
{
   class node;

   typedef void* (*enter_callback)(int8_t, proto_header_t, enter_t, comnet::node* node_ptr);
   typedef void* (*exit_callback)(int8_t, proto_header_t, exit_t, comnet::node* node_ptr);
   typedef void* (*ping_callback)(int8_t, proto_header_t, ping_t, comnet::node* node_ptr);
   typedef void* (*pong_callback)(int8_t, proto_header_t, pong_t, comnet::node* node_ptr);
   typedef void* (*vehicle_identification_callback)(int8_t, proto_header_t, vehicle_identification_t, comnet::node* node_ptr);
   typedef void* (*vehicle_authorization_request_callback)(int8_t, proto_header_t, vehicle_authorization_request_t, comnet::node* node_ptr);
   typedef void* (*vehicle_authorization_reply_callback)(int8_t, proto_header_t, vehicle_authorization_reply_t, comnet::node* node_ptr);
   typedef void* (*vehicle_mode_command_callback)(int8_t, proto_header_t, vehicle_mode_command_t, comnet::node* node_ptr);
   typedef void* (*vehicle_termination_command_callback)(int8_t, proto_header_t, vehicle_termination_command_t, comnet::node* node_ptr);
   typedef void* (*vehicle_telemetry_command_callback)(int8_t, proto_header_t, vehicle_telemetry_command_t, comnet::node* node_ptr);
   typedef void* (*vehicle_waypoint_command_callback)(int8_t, proto_header_t, vehicle_waypoint_command_t, comnet::node* node_ptr);
   typedef void* (*vehicle_system_status_callback)(int8_t, proto_header_t, vehicle_system_status_t, comnet::node* node_ptr);
   typedef void* (*vehicle_inertial_state_callback)(int8_t, proto_header_t, vehicle_inertial_state_t, comnet::node* node_ptr);
   typedef void* (*vehicle_global_position_callback)(int8_t, proto_header_t, vehicle_global_position_t, comnet::node* node_ptr);
   typedef void* (*vehicle_body_sensed_state_callback)(int8_t, proto_header_t, vehicle_body_sensed_state_t, comnet::node* node_ptr);
   typedef void* (*vehicle_attitude_callback)(int8_t, proto_header_t, vehicle_attitude_t, comnet::node* node_ptr);
   typedef void* (*vehicle_ground_relative_state_callback)(int8_t, proto_header_t, vehicle_ground_relative_state_t, comnet::node* node_ptr);
   typedef void* (*payload_bay_command_callback)(int8_t, proto_header_t, payload_bay_command_t, comnet::node* node_ptr);
   typedef void* (*payload_bay_mode_command_callback)(int8_t, proto_header_t, payload_bay_mode_command_t, comnet::node* node_ptr);
   typedef void* (*target_designation_command_callback)(int8_t, proto_header_t, target_designation_command_t, comnet::node* node_ptr);
   typedef void* (*UGV_joystick_callback)(int8_t, proto_header_t, UGV_joystick_t, comnet::node* node_ptr);
   typedef void* (*UGV_battery_status_callback)(int8_t, proto_header_t, UGV_battery_status_t, comnet::node* node_ptr);

   class node
   {
   public:
      node(uint8_t node_id);
      node(uint8_t node_id, int32_t mode);
      ~node();
      void start();

      void add_serial(int8_t* link_id, uint32_t baud_rate, char device_path[50]);
      void add_udp(int8_t* link_id, uint16_t port);
      void add_udp(int8_t* link_id, uint16_t port, char addr[16]);

      void establish_serial(int8_t link_id, uint8_t node_id);
      void establish_udp(int8_t link_id, uint8_t node_id, uint16_t port, char addr[16]);

      uint8_t get_num_datalinks();
      int32_t query_datalink_connected(int8_t link_id);
      datalink_type_t query_datalink_type(int8_t link_id);

      void send_enter(
         uint8_t dest_id,
         float64_t timestamp);

      void send_exit(
         uint8_t dest_id,
         float64_t timestamp);

      void send_ping(
         uint8_t dest_id,
         float64_t timestamp);

      void send_pong(
         uint8_t dest_id,
         float64_t timestamp);

      void send_vehicle_identification(
         uint8_t dest_id,
         float64_t timestamp,
         uint16_t vehicle_ID,
         uint8_t vehicle_type,
         uint16_t owner_ID);

      void send_vehicle_authorization_request(
         uint8_t dest_id,
         float64_t timestamp,
         uint16_t vehicle_ID,
         uint8_t link_key,
         uint8_t requested_services,
         uint8_t handover_node);

      void send_vehicle_authorization_reply(
         uint8_t dest_id,
         float64_t timestamp,
         uint16_t vehicle_ID,
         uint8_t vehicle_type,
         uint8_t authorized_services,
         uint8_t granted_services);

      void send_vehicle_mode_command(
         uint8_t dest_id,
         float64_t timestamp,
         uint16_t vehicle_ID,
         uint8_t vehicle_mode);

      void send_vehicle_termination_command(
         uint8_t dest_id,
         float64_t timestamp,
         uint16_t vehicle_ID,
         uint8_t termination_mode);

      void send_vehicle_telemetry_command(
         uint8_t dest_id,
         float64_t timestamp,
         uint8_t telemetry_select,
         uint8_t telemetry_rate);

      void send_vehicle_waypoint_command(
         uint8_t dest_id,
         float64_t timestamp,
         uint16_t vehicle_ID,
         int32_t latitude,
         int32_t longitude,
         int32_t altitude,
         int32_t heading,
         uint8_t waypoint_ID,
         uint8_t waypoint_type);

      void send_vehicle_system_status(
         uint8_t dest_id,
         float64_t timestamp,
         uint16_t vehicle_ID,
         uint8_t vehicle_mode,
         uint8_t vehicle_state);

      void send_vehicle_inertial_state(
         uint8_t dest_id,
         float64_t timestamp,
         uint16_t vehicle_ID,
         float64_t latitude,
         float64_t longitude,
         float32_t altitude,
         float32_t roll,
         float32_t pitch,
         float32_t heading,
         float32_t north_speed,
         float32_t east_speed,
         float32_t vertical_speed,
         float32_t roll_rate,
         float32_t pitch_rate,
         float32_t yaw_rate,
         float32_t north_accel,
         float32_t east_accel,
         float32_t vertical_accel);

      void send_vehicle_global_position(
         uint8_t dest_id,
         float64_t timestamp,
         uint16_t vehicle_ID,
         int32_t latitude,
         int32_t longitude,
         int32_t altitude,
         int32_t heading,
         int16_t x_speed,
         int16_t y_speed,
         int16_t z_speed);

      void send_vehicle_body_sensed_state(
         uint8_t dest_id,
         float64_t timestamp,
         uint16_t vehicle_ID,
         int16_t x_accel,
         int16_t y_accel,
         int16_t z_accel,
         int16_t roll_rate,
         int16_t pitch_rate,
         int16_t yaw_rate);

      void send_vehicle_attitude(
         uint8_t dest_id,
         float64_t timestamp,
         uint16_t vehicle_ID,
         float32_t roll,
         float32_t pitch,
         float32_t yaw);

      void send_vehicle_ground_relative_state(
         uint8_t dest_id,
         float64_t timestamp,
         uint16_t vehicle_ID,
         float32_t angle_of_attack,
         float32_t angle_of_sideslip,
         float32_t true_airspeed,
         float32_t indicated_airspeed,
         float32_t north_wind_speed,
         float32_t east_wind_speed,
         float32_t north_ground_speed,
         float32_t east_ground_speed,
         float32_t barometric_pressure,
         float32_t barometric_altitude);

      void send_payload_bay_command(
         uint8_t dest_id,
         float64_t timestamp,
         uint32_t payload_ID,
         uint8_t payload_command);

      void send_payload_bay_mode_command(
         uint8_t dest_id,
         float64_t timestamp,
         uint32_t payload_ID,
         uint8_t payload_mode);

      void send_target_designation_command(
         uint8_t dest_id,
         float64_t timestamp,
         uint16_t vehicle_ID,
         uint8_t payload_ID,
         uint8_t target_ID,
         uint8_t target_type,
         int32_t latitude,
         int32_t longitude,
         int32_t altitude);

      void send_UGV_joystick(
         uint8_t dest_id,
         float64_t timestamp,
         uint8_t vehicle_id,
         float32_t steering,
         float32_t throttle);

      void send_UGV_battery_status(
         uint8_t dest_id,
         float64_t timestamp,
         float32_t voltage_3_3V,
         float32_t voltage_5V,
         float32_t voltage_12V,
         float32_t current_3_3V,
         float32_t current_5V,
         float32_t current_12V,
         float32_t current_fore_motor,
         float32_t current_aft_motor);

      void register_on_enter(enter_callback callback){on_enter = callback;}
      void register_on_exit(exit_callback callback){on_exit = callback;}
      void register_on_ping(ping_callback callback){on_ping = callback;}
      void register_on_pong(pong_callback callback){on_pong = callback;}
      void register_on_vehicle_identification(vehicle_identification_callback callback){on_vehicle_identification = callback;}
      void register_on_vehicle_authorization_request(vehicle_authorization_request_callback callback){on_vehicle_authorization_request = callback;}
      void register_on_vehicle_authorization_reply(vehicle_authorization_reply_callback callback){on_vehicle_authorization_reply = callback;}
      void register_on_vehicle_mode_command(vehicle_mode_command_callback callback){on_vehicle_mode_command = callback;}
      void register_on_vehicle_termination_command(vehicle_termination_command_callback callback){on_vehicle_termination_command = callback;}
      void register_on_vehicle_telemetry_command(vehicle_telemetry_command_callback callback){on_vehicle_telemetry_command = callback;}
      void register_on_vehicle_waypoint_command(vehicle_waypoint_command_callback callback){on_vehicle_waypoint_command = callback;}
      void register_on_vehicle_system_status(vehicle_system_status_callback callback){on_vehicle_system_status = callback;}
      void register_on_vehicle_inertial_state(vehicle_inertial_state_callback callback){on_vehicle_inertial_state = callback;}
      void register_on_vehicle_global_position(vehicle_global_position_callback callback){on_vehicle_global_position = callback;}
      void register_on_vehicle_body_sensed_state(vehicle_body_sensed_state_callback callback){on_vehicle_body_sensed_state = callback;}
      void register_on_vehicle_attitude(vehicle_attitude_callback callback){on_vehicle_attitude = callback;}
      void register_on_vehicle_ground_relative_state(vehicle_ground_relative_state_callback callback){on_vehicle_ground_relative_state = callback;}
      void register_on_payload_bay_command(payload_bay_command_callback callback){on_payload_bay_command = callback;}
      void register_on_payload_bay_mode_command(payload_bay_mode_command_callback callback){on_payload_bay_mode_command = callback;}
      void register_on_target_designation_command(target_designation_command_callback callback){on_target_designation_command = callback;}
      void register_on_UGV_joystick(UGV_joystick_callback callback){on_UGV_joystick = callback;}
      void register_on_UGV_battery_status(UGV_battery_status_callback callback){on_UGV_battery_status = callback;}

   private:
      uint8_t node_id;

      int8_t num_datalinks;
      datalink* datalinks[255];
      thread_t datalink_threads[255];

      proto_msg_queue queue;
      void handle_proto_msg_t(proto_msg_t* rx_msg, proto_msg_buf_t* rx_buf);

      thread_t handler_thread;
      void* comnet_handler();
      static void* handler_helper(void* context);

      thread_t upkeep_thread;
      void* upkeep_handler();
      static void* upkeep_helper(void* context);

      void null_callback_storage();

      enter_callback on_enter;
      exit_callback on_exit;
      ping_callback on_ping;
      pong_callback on_pong;
      vehicle_identification_callback on_vehicle_identification;
      vehicle_authorization_request_callback on_vehicle_authorization_request;
      vehicle_authorization_reply_callback on_vehicle_authorization_reply;
      vehicle_mode_command_callback on_vehicle_mode_command;
      vehicle_termination_command_callback on_vehicle_termination_command;
      vehicle_telemetry_command_callback on_vehicle_telemetry_command;
      vehicle_waypoint_command_callback on_vehicle_waypoint_command;
      vehicle_system_status_callback on_vehicle_system_status;
      vehicle_inertial_state_callback on_vehicle_inertial_state;
      vehicle_global_position_callback on_vehicle_global_position;
      vehicle_body_sensed_state_callback on_vehicle_body_sensed_state;
      vehicle_attitude_callback on_vehicle_attitude;
      vehicle_ground_relative_state_callback on_vehicle_ground_relative_state;
      payload_bay_command_callback on_payload_bay_command;
      payload_bay_mode_command_callback on_payload_bay_mode_command;
      target_designation_command_callback on_target_designation_command;
      UGV_joystick_callback on_UGV_joystick;
      UGV_battery_status_callback on_UGV_battery_status;
   };
}
#endif
