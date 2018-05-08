#include "messageHeader.h"

void getHeaderBuffer(MessageHeader *self, uint8_t *&buf) {

	buf = (uint8_t*)calloc(9, sizeof(uint8_t));
	//if (buf) memset(buf, 0, 9);
	// Status
	buf[0] = (uint8_t)(self->Status);

	// Command
	buf[1] = (uint8_t)(self->Command);

	// hardwareId
	buf[2] = (uint8_t)(self->Hardware);

	// payloadLength 1
	buf[3] = (uint8_t)(self->PayloadLength & 0xff);

	// payloadLength 2
	buf[4] = (uint8_t)(self->PayloadLength >> 8);

	// packetId
	buf[5] = (uint8_t)(self->PacketID);

	// packetTotal
	buf[6] = (uint8_t)(self->TotalPacketsCount);

	// messageId 1
	buf[7] = (uint8_t)(self->InternalID & 0xff);

	// messageId 2
	buf[8] = (uint8_t)(self->InternalID >> 8);
}

MessageHeader getHeaderFromBuffer(char *buf) {

	MessageHeader result;
	result.Status = (uint8_t)buf[0];
	result.Command = (uint8_t)buf[1];
	result.Hardware = (uint8_t)buf[2];
	result.PayloadLength = (uint16_t)(buf[4] << 8) | buf[3];
	result.PacketID = (uint8_t)buf[5];
	result.TotalPacketsCount = (uint8_t)buf[6];
	result.InternalID = (uint16_t)(buf[8] << 8) | buf[7];

	return result;
}