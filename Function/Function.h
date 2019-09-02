#ifndef Function_H
#define Function_H
#include "socket.h"

int PowerOn();
int Login(const char* msg);
int Send(const char* msg);
int Create(const char* msg);
int Apply(const char* msg);
int Reply(const char* msg);

#endif