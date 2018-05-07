#ifndef RTC_MESSAGE_H
#define RTC_MESSAGE_H

#include <stdint.h> 

struct RtcMessage {
	uint8_t Year;
	uint8_t Month;
	uint8_t Day;
	uint8_t Hour;
	uint8_t Minute;
	uint8_t Second;
	void (*getBuffer)(RtcMessage *, uint8_t *&buf);
};

void getRtcBuffer(RtcMessage *self, uint8_t *&buf) {

	buf = (uint8_t*)malloc(6);
	if (buf) memset(buf, 0, 6);

	// Year
	buf[0] = (uint8_t)(self->Year);

	// Month
	buf[1] = (uint8_t)(self->Month);

	// Day
	buf[2] = (uint8_t)(self->Day);

	// Hour
	buf[3] = (uint8_t)(self->Hour);

	// Minute
	buf[4] = (uint8_t)(self->Minute);

	// Second
	buf[5] = (uint8_t)(self->Second);
}

#endif