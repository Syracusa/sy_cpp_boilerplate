#ifndef sock_h
#define sock_h

#include <iostream>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>

const int get_rawsocket(const int ipproto);

#endif
