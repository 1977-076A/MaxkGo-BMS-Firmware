/*
	Copyright 2016 Benjamin Vedder	benjamin@vedder.se

	This file is part of the VESC firmware.

	The VESC firmware is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    The VESC firmware is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef MODCAN_H_
#define MODCAN_H_

#include "generalDefines.h"
#include "mainDataTypes.h"
#include "stm32f3xx_hal.h"
#include "stdbool.h"
#include "modDelay.h"
#include "modCommands.h"
#include "libCRC.h"
#include "libPacket.h"
#include "libBuffer.h"
#include <string.h>
#include <math.h>

// Settings
#define CAN_STATUS_MSG_INT_MS		1
#define RX_CAN_FRAMES_SIZE	100       // max 255
#define RX_CAN_BUFFER_SIZE	PACKET_MAX_PL_LEN

void          modCANInit(void);
void          modCANTask(void);
uint8_t       modCANGetDestinationID(CanRxMsgTypeDef canMsg);
CAN_PACKET_ID modCANGetPacketID(CanRxMsgTypeDef canMsg);

static void send_packet_wrapper(unsigned char *data, unsigned int len);
void cancom_process_task(void);
void comm_can_transmit_eid(uint32_t id, uint8_t *data, uint8_t len);
void comm_can_send_buffer(uint8_t controller_id, uint8_t *data, unsigned int len, bool send);
void comm_can_set_duty(uint8_t controller_id, float duty);
void comm_can_set_current(uint8_t controller_id, float current);
void comm_can_set_current_brake(uint8_t controller_id, float current);
void comm_can_set_rpm(uint8_t controller_id, float rpm);
void comm_can_set_pos(uint8_t controller_id, float pos);
void comm_can_set_current_rel(uint8_t controller_id, float current_rel);
void comm_can_set_current_brake_rel(uint8_t controller_id, float current_rel);
can_status_msg *comm_can_get_status_msg_index(int index);
can_status_msg *comm_can_get_status_msg_id(int id);

#endif /* MODCAN_H_ */
