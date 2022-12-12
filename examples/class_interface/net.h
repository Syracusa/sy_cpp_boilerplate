#ifndef NET_H
#define NET_H

#define NET_IPSTR_LEN 16

#include <stdlib.h>
#include <string.h>
#include <vector>
#include <arpa/inet.h>
#include <sys/socket.h>

class NetServer
{
private:
protected:
    int port;

public:
    /* Constructor */
    NetServer(int port);

    /* Virtual Function */
    virtual void sendtoClient(void *data, size_t len) = 0;
    virtual ssize_t recvfromClient(void *buf, size_t buflen) = 0;
};

class NetClient
{
private:
protected:
    int serverPort;
    char serverIpStr[NET_IPSTR_LEN];
    struct sockaddr_in serverAddr;

public:
    /* Constructor */
    NetClient(const char *server_ip, int server_port);

    virtual void sendtoServer(void *data, size_t len) = 0;
    virtual ssize_t recvfromServer(void *buf, size_t buflen) = 0;
};

class TcpServer : NetServer
{
public:
    /* Public member variables */
    int fd;

    /* Public member functions */
    void sendtoClient(void *data, size_t len) override;
    ssize_t recvfromClient(void *buf, size_t buflen) override;

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
    TcpClient(const char *server_ip, int server_port);

    /* Overrided Function */
    void sendtoServer(void *data, size_t len) override;
    ssize_t recvfromServer(void *buf, size_t buflen) override;
};

class UdpServer : NetServer
{
public:
    int fd;

    /* Constructor Function -> Inherited from NetServer */
    UdpServer(int port);

    /* Overrided Function */
    void sendtoClient(void *data, size_t len) override;
    ssize_t recvfromClient(void *buf, size_t buflen) override;
};

class UdpClient : NetClient
{
public:
    int fd;

    /* Constructor Function -> Inherited from NetClient */
    UdpClient(const char *server_ip, int server_port);

    /* Overrided Function */
    void sendtoServer(void *data, size_t len) override;
    ssize_t recvfromServer(void *buf, size_t buflen) override;
};

#endif