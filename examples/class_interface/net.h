#ifndef NET_H
#define NET_H

#define NET_IPSTR_LEN 16

#include <stdlib.h>
#include <string.h>
#include <vector>

class NetServer
{
private:
protected:
    int port;

public:
    /* Constructor */
    NetServer(int port)
    {
        this->port = port;
    };

    /* Virtual Function */
    virtual void sendtoClient(void *data, int len) = 0;
    virtual int recvfromClient(void *data) = 0;
};

class NetClient
{
private:
protected:
    int serverPort;
    char serverIpStr[NET_IPSTR_LEN];

public:
    /* Constructor */
    NetClient(const char *server_ip, int server_port)
    {
        this->serverPort = server_port;
        memcpy(this->serverIpStr, server_ip, NET_IPSTR_LEN);
    };

    virtual void sendtoServer(void *data, int len) = 0;
    virtual int recvfromServer(void *data) = 0;
};

class TcpServer : NetServer
{
public:
    /* Public member variables */
    int fd;

    /* Public member functions */
    void sendtoClient(void *data, int len) override;
    int recvfromClient(void *data) override;

    /* Constructor Function -> Inherited from NetServer */
    TcpServer(int port) : NetServer(port) {};
};

class TcpClient : NetClient
{
private:
    std::vector<int> clientfds = {};

public:
    /* Public member variables */
    int fd;

    /* Constructor Function */
    TcpClient(const char *server_ip, int server_port)
        : NetClient(server_ip, server_port) {}

    /* Overrided Function */
    void sendtoServer(void *data, int len) override;
    int recvfromServer(void *data) override;
};

class UdpServer : NetServer
{
public:
    int fd;

    /* Constructor Function -> Inherited from NetServer */
    UdpServer(int port) : NetServer(port) {};

    /* Overrided Function */
    void sendtoClient(void *data, int len) override;
    int recvfromClient(void *data) override;
};

class UdpClient : NetClient
{
public:
    int fd;

    /* Constructor Function -> Inherited from NetClient */
    UdpClient(const char *server_ip, int server_port)
        : NetClient(server_ip, server_port) {}

    /* Overrided Function */
    void sendtoServer(void *data, int len) override;
    int recvfromServer(void *data) override;
};

#endif