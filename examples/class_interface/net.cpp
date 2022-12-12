
#include <stdexcept>
#include <iostream>
#include "net.h"

/* === NetServer Impl === */
NetServer::NetServer(int port)
{
    this->port = port;
}

/* === NetClient Impl === */
NetClient::NetClient(const char *server_ip, int server_port)
{
    this->serverPort = server_port;
    memcpy(this->serverIpStr, server_ip, NET_IPSTR_LEN);

    this->serverAddr.sin_family = AF_INET;
    if (inet_pton(AF_INET,
                  this->serverIpStr,
                  &this->serverAddr.sin_addr) <= 0)
    {
        throw std::runtime_error("Invalid IPv4 Server IP");
    }
    this->serverAddr.sin_port = htons(server_port);
};

/* === UdpServer Impl === */

UdpServer::UdpServer(int port)
    : NetServer(port)
{
}

void UdpServer::sendtoClient(void *data, size_t len)
{
}

ssize_t recvfromClient(void *buf, size_t buflen)
{
    return 0;
}

/* === UdpClient Impl === */

UdpClient::UdpClient(const char *server_ip, int server_port)
    : NetClient(server_ip, server_port)
{
    this->fd = socket(AF_INET, SOCK_DGRAM, 0);
    if (this->fd == -1)
    {
        throw std::runtime_error("Fail to create socket descriptor");
    }
}

void UdpClient::sendtoServer(void *data, size_t len)
{
    sendto(this->fd, data, len, 0,
           (struct sockaddr *)&this->serverAddr,
           sizeof(this->serverAddr));
}

ssize_t UdpClient::recvfromServer(void *buf, size_t buflen)
{
    sockaddr_in recv_addr;
    socklen_t recv_addr_len;

    return recvfrom(this->fd, buf, buflen, 0,
                    (struct sockaddr *)&recv_addr,
                    &recv_addr_len);
}

/* === TcpServer Impl === */

TcpServer::TcpServer(int port)
    : NetServer(port)
{
}

void TcpServer::sendtoClient(void *data, size_t len)
{
}

ssize_t TcpServer::recvfromClient(void *buf, size_t buflen)
{
    return 0;
}

/* === TcpClient Impl === */
TcpClient::TcpClient(const char *server_ip, int server_port)
    : NetClient(server_ip, server_port)
{
}
void TcpClient::sendtoServer(void *data, size_t len)
{
    /* TBD */
}

ssize_t TcpClient::recvfromServer(void *buf, size_t buflen)
{
    /* TBD*/
    return 0;
}
