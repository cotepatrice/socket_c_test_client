#include <winsock2.h>
#include <stdint.h>

#ifndef AUTHENTICATION_MESSAGE
#define AUTHENTICATION_MESSAGE

enum AuthenticatedMessageStatus { Success = 1, Failed = 2, UnknownError = 3 };

void sendAuthenticationMessage(uint8_t *&authMessage);

#endif


