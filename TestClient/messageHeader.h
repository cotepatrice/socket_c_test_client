#ifndef MESSAGE_HEADER_H
#define MESSAGE_HEADER_H

#include <stdint.h> 
#include <stdlib.h>

struct MessageHeader {
	uint8_t Status;
	uint8_t Command;
	uint8_t Hardware;
	uint16_t PayloadLength;
	uint8_t PacketID;
	uint8_t TotalPacketsCount;
	uint16_t InternalID;
	void (*getBuffer)(MessageHeader *, uint8_t *&buf);
};

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

#endif
