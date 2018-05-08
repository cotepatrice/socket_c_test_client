#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h> 
#include "MessageHeader.h"
#include "RtcMessage.h"
#include "shared.h"
#include "test_rtc.h"

void testRtcMessage(uint8_t *&rtcMessage) {

	MessageHeader messageHeader;
	messageHeader.Status = (uint8_t)(0);
	messageHeader.Command = (uint8_t)(114);
	messageHeader.Hardware = (uint8_t)(221);
	messageHeader.PayloadLength = (uint16_t)(6);
	messageHeader.PacketID = (uint8_t)(1);
	messageHeader.TotalPacketsCount = (uint8_t)(1);
	messageHeader.InternalID = (uint16_t)(3365);
	messageHeader.getBuffer = getHeaderBuffer;

	RtcMessage rtc;
	rtc.Year = (uint8_t)(18);
	rtc.Month = (uint8_t)(8);
	rtc.Day = (uint8_t)(21);
	rtc.Hour = (uint8_t)(17);
	rtc.Minute = (uint8_t)(36);
	rtc.Second = (uint8_t)(58);
	rtc.getBuffer = getRtcBuffer;

	uint8_t *headBuffer = NULL;
	uint8_t *rtcBuffer = NULL;

	messageHeader.getBuffer(&messageHeader, headBuffer);
	rtc.getBuffer(&rtc, rtcBuffer);

	rtcMessage = (uint8_t*)malloc(MESSAGE_HEADER_SIZE + MESSAGE_RTC_SIZE);
	if (rtcMessage) memset(rtcMessage, 0, MESSAGE_HEADER_SIZE + MESSAGE_RTC_SIZE);
	memcpy(rtcMessage, headBuffer, MESSAGE_HEADER_SIZE);
	memcpy(rtcMessage + MESSAGE_HEADER_SIZE, rtcBuffer, MESSAGE_RTC_SIZE);

}