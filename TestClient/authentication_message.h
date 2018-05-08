#ifndef IDENTIFICATION_MESSAGE_H
#define IDENTIFICATION_MESSAGE_H

#include <stdint.h> 
#include <stdlib.h>

struct AuthenticationMessage {
	uint16_t KeeogoId;
	uint8_t SensorsCount;
	uint16_t Sensor1Id;
	uint16_t Sensor1SN;
	uint16_t Sensor2Id;
	uint16_t Sensor2SN;
	uint16_t Sensor3Id;
	uint16_t Sensor3SN;
	uint16_t Sensor4Id;
	uint16_t Sensor4SN;
	uint16_t Sensor5Id;
	uint16_t Sensor5SN;
	uint16_t Sensor6Id;
	uint16_t Sensor6SN;

	void(*getBuffer)(AuthenticationMessage *, uint8_t *&buf);
};

void getAuthenticationBuffer(AuthenticationMessage *self, uint8_t *&buf);

#endif