#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h> 
#include "MessageHeader.h"
#include "authentication_message.h"
#include "shared.h"

void sendAuthenticationMessage(uint8_t *&authMessage) {

	MessageHeader messageHeader;
	messageHeader.Status = (uint8_t)(1);
	messageHeader.Command = (uint8_t)(1);
	messageHeader.Hardware = (uint8_t)(221);
	messageHeader.PayloadLength = (uint16_t)(27);
	messageHeader.PacketID = (uint8_t)(1);
	messageHeader.TotalPacketsCount = (uint8_t)(1);
	messageHeader.InternalID = (uint16_t)(3185);
	messageHeader.getBuffer = getHeaderBuffer;

	AuthenticationMessage auth;
	auth.KeeogoId = (uint16_t)(9284);
	auth.SensorsCount = (uint8_t)(SENSORS_COUNT);
	auth.Sensor1Id = (uint16_t)(2111);
	auth.Sensor1SN = (uint16_t)(65534);
	auth.Sensor2Id = (uint16_t)(2112);
	auth.Sensor2SN = (uint16_t)(32565);
	auth.Sensor3Id = (uint16_t)(2113);
	auth.Sensor3SN = (uint16_t)(8754);
	auth.Sensor4Id = (uint16_t)(2114);
	auth.Sensor4SN = (uint16_t)(56253);
	auth.Sensor5Id = (uint16_t)(2115);
	auth.Sensor5SN = (uint16_t)(44888);
	auth.Sensor6Id = (uint16_t)(2116);
	auth.Sensor6SN = (uint16_t)(20541);

	auth.getBuffer = getAuthenticationBuffer;

	uint8_t *headBuffer = NULL;
	uint8_t *authBuffer = NULL;

	messageHeader.getBuffer(&messageHeader, headBuffer);
	auth.getBuffer(&auth, authBuffer);

	authMessage = (uint8_t*)malloc(MESSAGE_HEADER_SIZE + AUTHENTICATION_MESSAGE_SIZE);
	if (authMessage) memset(authMessage, 0, MESSAGE_HEADER_SIZE + AUTHENTICATION_MESSAGE_SIZE);
	memcpy(authMessage, headBuffer, MESSAGE_HEADER_SIZE);
	memcpy(authMessage + MESSAGE_HEADER_SIZE, authBuffer, AUTHENTICATION_MESSAGE_SIZE);

}