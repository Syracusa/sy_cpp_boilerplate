#include <arpa/inet.h>
#include <sys/socket.h>
#include <stdexcept>
#include <iostream>
#include "net.h"

UdpClient::UdpClient(const char *server_ip, int server_port)
    : NetClient(server_ip, server_port)
{
    this->fd = socket(AF_INET, SOCK_DGRAM, 0);
    if (this->fd == -1){
        throw std::runtime_error("Fail to create socket descriptor");
    }
    
}

void UdpClient::sendtoServer(void *data, int len)
{

    this->fd = socket(AF_INET, SOCK_DGRAM, 0);
    /* TBD */

    // sendto()
}

int UdpClient::recvfromServer(void *data)
{

    return 0;
}