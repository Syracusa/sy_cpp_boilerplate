#include "sock.h"

const int get_rawsocket(const int ipproto)
{
    const int rsock = socket(AF_INET, SOCK_RAW, ipproto);
    return rsock;
}

/* TODO : Multicast sock*/