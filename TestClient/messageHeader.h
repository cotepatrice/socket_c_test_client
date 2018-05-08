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

void getHeaderBuffer(MessageHeader *self, uint8_t *&buf);

MessageHeader getHeaderFromBuffer(char *buf);

#endif
