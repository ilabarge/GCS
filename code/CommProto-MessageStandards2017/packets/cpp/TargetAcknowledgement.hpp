/**
TargetAcknowledgement

Copyright (C) 2016-2017 Northrup Grumman Collaboration Project.

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(At your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef NGCP_TARGET_ACKNOWLEDGEMENT_HPP
#define NGCP_TARGET_ACKNOWLEDGEMENT_HPP


#include <CommProto/commproto.h>


namespace ngcp {

  struct TargetAcknowledgement : INHERITS_ABSPACKET {
    /**
    Creates an instance
    */
    TargetAcknowledgement(uint8_t target_status = 0)
      : CHAIN_ABSPACKET(TargetAcknowledgement),
      target_status(target_status)
    {
    }


    /**
    Pack data into the stream for sending out.
    */
    void Pack(comnet::ObjectStream &obj) override {
      obj << target_status;
    }


    /**
    Unpack data back into this packet when receiving data.
    */
    void Unpack(comnet::ObjectStream &obj) override {
      obj >> target_status;
    }


    /**
    Tells CommProtocol how to recreate the TargetAcknowledgement packet
    when receiving data.
    */
    comnet::AbstractPacket *Create() override {
      return new TargetAcknowledgement();
    }

    /**
    Data.
    */
    uint8_t target_status;
  };
} // ngcp
#endif // NGCP_TARGET_ACKNOWLEDGEMENT_HPP

