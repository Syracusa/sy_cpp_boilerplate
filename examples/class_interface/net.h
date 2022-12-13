#ifndef NET_H
#define NET_H

#define NET_IPSTR_LEN 16

#include <unistd.h>
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
    virtual ssize_t recvfromClient(void* buf,
                                   size_t buflen,
                                   struct sockaddr_in *addr) = 0;
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
    NetClient(const char* server_ip, int server_port);

    virtual ssize_t sendtoServer(const void* data, size_t len) = 0;
    virtual ssize_t recvfromServer(void* buf, size_t buflen) = 0;
};

class TcpServer: NetServer
{
    private:
    int fd;

    public:
    /* Public member functions */
    ssize_t sendtoAllClient(void* data, size_t len);
    ssize_t recvfromClient(void* buf,
                           size_t buflen,
                           struct sockaddr_in *addr) override;

    /* Constructor & Destructor */
    TcpServer(int port);
};

class TcpClient: NetClient
{
    private:
    std::vector<int> clientfds = {};
    int fd;

    public:
    /* Public memeber Function */
    ssize_t sendtoServer(const void* data, size_t len) override;
    ssize_t recvfromServer(void* buf, size_t buflen) override;

    /* Constructor & Destructor */
    TcpClient(const char* server_ip, int server_port);
};

class UdpServer: NetServer
{
    private:
    int fd;
    int hasClient;
    struct sockaddr_in recentClient;

    public:
    /* Public Functions */
    ssize_t sendtoRecentClient(const void* data, size_t len);
    ssize_t recvfromClient(void* buf,
                           size_t buflen,
                           struct sockaddr_in *addr) override;

    /* Constructor & Destructor */
    UdpServer(int port);
    ~UdpServer() { if (this->fd) close(this->fd); };

};

class UdpClient: NetClient
{
    private:
    int fd;

    public:
    /* Overrided Function */
    ssize_t sendtoServer(const void* data, size_t len) override;
    ssize_t recvfromServer(void* buf, size_t buflen) override;

    /* Constructor & Destructor */
    UdpClient(const char* server_ip, int server_port);
    ~UdpClient() { if (this->fd) close(this->fd); };
};

#endif