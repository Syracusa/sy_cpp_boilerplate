
#include <stdexcept>
#include <iostream>
#include <cerrno>
#include "net.h"

#define NET_VERBOSE 1


/* === NetServer Impl === */

NetServer::NetServer(int port)
{
    this->port = port;

    if (NET_VERBOSE)
        std::cout << "NetServer port " << port << " initiated\n";
}

/* === NetClient Impl === */

NetClient::NetClient(const char* server_ip, int server_port)
{
    this->serverPort = server_port;
    memcpy(this->serverIpStr, server_ip, strlen(server_ip) + 1);

    this->serverAddr.sin_family = AF_INET;

    int tres = inet_pton(AF_INET,
                         this->serverIpStr,
                         &this->serverAddr.sin_addr);

    if (tres <= 0)
    {
        std::cerr << "Invalid IP " << this->serverIpStr << std::endl;
        std::cerr << "inet_pton() res : " << tres << std::endl;
        throw std::runtime_error("Invalid IPv4 Server IP");
    }
    this->serverAddr.sin_port = htons(server_port);

    if (NET_VERBOSE)
        std::cout << "NetClient Server IP: " << server_ip
        << " Server Port: " << server_port << " initiated\n";
}

/* === UdpServer Impl === */

UdpServer::UdpServer(int port)
    : NetServer(port)
{
    this->hasClient = 0;

    this->fd = socket(AF_INET, SOCK_DGRAM, 0);
    if (this->fd == -1)
    {
        throw std::runtime_error("Fail to create socket descriptor");
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(port);

    int bres = bind(this->fd, (sockaddr*)&server_addr, sizeof(server_addr));
    if (bres != 0)
    {
        std::cerr << "Bind for port " << port << "failed";
        throw std::runtime_error("Unavailable Port");
    }

    if (NET_VERBOSE)
        std::cout << "UdpServer port " << port << " initiated\n";
}

/* Send to recent client */
ssize_t UdpServer::sendtoRecentClient(const void* data, size_t len)
{
    if (this->hasClient)
    {
        return sendto(this->fd, data, len, 0,
                      (sockaddr*)&this->recentClient,
                      sizeof(this->recentClient));
    }
    else
    {
        std::cerr << "No client exist!\n";
        return 0;
    }
}

ssize_t UdpServer::recvfromClient(void* buf,
                                  size_t buflen,
                                  struct sockaddr_in* addr)
{
    socklen_t recv_addr_len = sizeof(struct sockaddr_in);
    ssize_t rlen = recvfrom(this->fd, buf, buflen, 0,
                            (struct sockaddr*)addr,
                            &recv_addr_len);

    if (rlen > 0)
    {
        this->hasClient = 1;
        this->recentClient = *addr;
        if (NET_VERBOSE)
        {
            std::cout << "Server recved " << rlen << "bytes from "
                << inet_ntoa(addr->sin_addr) << ":"
                << ntohs(addr->sin_port) << std::endl;
        }
    }
    else 
    {
        std::cerr << "Recvfrom fail " << rlen << std::endl;
        std::cerr << strerror(errno) << std::endl;
    }

    return rlen;
}

/* === UdpClient Impl === */

UdpClient::UdpClient(const char* server_ip, int server_port)
    : NetClient(server_ip, server_port)
{
    this->fd = socket(AF_INET, SOCK_DGRAM, 0);
    if (this->fd == -1)
    {
        throw std::runtime_error("Fail to create socket descriptor");
    }
}

ssize_t UdpClient::sendtoServer(const void* data, size_t len)
{
    return sendto(this->fd, data, len, 0,
                  (struct sockaddr*)&this->serverAddr,
                  sizeof(this->serverAddr));
}

ssize_t UdpClient::recvfromServer(void* buf, size_t buflen)
{
    sockaddr_in recv_addr;
    socklen_t recv_addr_len;

    return recvfrom(this->fd, buf, buflen, 0,
                    (struct sockaddr*)&recv_addr,
                    &recv_addr_len);
}

/* === TcpServer Impl === */

TcpServer::TcpServer(int port)
    : NetServer(port)
{

}

ssize_t TcpServer::sendtoAllClient(void* data, size_t len)
{
    return 0;
}

ssize_t TcpServer::recvfromClient(void* buf,
                                  size_t buflen,
                                  struct sockaddr_in* addr)
{
    return 0;
}

/* === TcpClient Impl === */
TcpClient::TcpClient(const char* server_ip, int server_port)
    : NetClient(server_ip, server_port)
{
}
ssize_t TcpClient::sendtoServer(const void* data, size_t len)
{
    /* TBD */
    return 0;
}

ssize_t TcpClient::recvfromServer(void* buf, size_t buflen)
{
    /* TBD*/
    return 0;
}
