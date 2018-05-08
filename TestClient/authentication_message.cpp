#include "authentication_message.h"

void getAuthenticationBuffer(AuthenticationMessage *self, uint8_t *&buf) {

	buf = (uint8_t*)calloc(9, sizeof(uint8_t));

	// KeeogoId 1
	buf[0] = (uint8_t)(self->KeeogoId & 0xff);

	// KeeogoId 2
	buf[1] = (uint8_t)(self->KeeogoId >> 8);

	// SensorsCount
	buf[2] = (uint8_t)(self->SensorsCount);

	// Sensor1Id 1
	buf[3] = (uint8_t)(self->Sensor1Id & 0xff);

	// Sensor1Id 2
	buf[4] = (uint8_t)(self->Sensor1Id >> 8);

	// Sensor1SN 1
	buf[5] = (uint8_t)(self->Sensor1SN & 0xff);

	// Sensor1SN 2
	buf[6] = (uint8_t)(self->Sensor1SN >> 8);

	// Sensor2Id 1
	buf[7] = (uint8_t)(self->Sensor2Id & 0xff);

	// Sensor2Id 2
	buf[8] = (uint8_t)(self->Sensor2Id >> 8);

	// Sensor2SN 1
	buf[9] = (uint8_t)(self->Sensor2SN & 0xff);

	// Sensor2SN 2
	buf[10] = (uint8_t)(self->Sensor2SN >> 8);

	// Sensor3Id 1
	buf[11] = (uint8_t)(self->Sensor3Id & 0xff);

	// Sensor3Id 2
	buf[12] = (uint8_t)(self->Sensor3Id >> 8);

	// Sensor3SN 1
	buf[13] = (uint8_t)(self->Sensor3SN & 0xff);

	// Sensor3SN 2
	buf[14] = (uint8_t)(self->Sensor3SN >> 8);

	// Sensor4Id 1
	buf[15] = (uint8_t)(self->Sensor4Id & 0xff);

	// Sensor4Id 2
	buf[16] = (uint8_t)(self->Sensor4Id >> 8);

	// Sensor4SN 1
	buf[17] = (uint8_t)(self->Sensor4SN & 0xff);

	// Sensor4SN 2
	buf[18] = (uint8_t)(self->Sensor4SN >> 8);

	// Sensor5Id 1
	buf[19] = (uint8_t)(self->Sensor5Id & 0xff);

	// Sensor5Id 2
	buf[20] = (uint8_t)(self->Sensor5Id >> 8);

	// Sensor5SN 1
	buf[21] = (uint8_t)(self->Sensor5SN & 0xff);

	// Sensor5SN 2
	buf[22] = (uint8_t)(self->Sensor5SN >> 8);

	// Sensor6Id 1
	buf[23] = (uint8_t)(self->Sensor6Id & 0xff);

	// Sensor6Id 2
	buf[24] = (uint8_t)(self->Sensor6Id >> 8);

	// Sensor6SN 1
	buf[25] = (uint8_t)(self->Sensor6SN & 0xff);

	// Sensor6SN 2
	buf[26] = (uint8_t)(self->Sensor6SN >> 8);

}