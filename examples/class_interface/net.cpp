#include <arpa/inet.h>
#include <sys/socket.h>


#include <iostream>
#include "net.h"

void UdpClient::sendtoServer(void* data, int len){
    this->fd = socket(AF_INET, SOCK_DGRAM, 0);
    /* TBD */
}

int UdpClient::recvfromServer(void* data){

    return 0;
}