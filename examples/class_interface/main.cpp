#include <iostream>
#include "net.h"

void test_udp()
{
    UdpServer server(15000);
    UdpClient client("127.0.0.1", 15000);

    client.sendtoServer("Hello server!", 14);

    char recvbuf[100];
    sockaddr_in cli_addr;
    server.recvfromClient(recvbuf, 100, &cli_addr);
    std::cout << "Recvform Client : " << recvbuf << std::endl;
    server.sendtoRecentClient("Hello client!", 14);

    client.recvfromServer(recvbuf, 100);
    std::cout << "Recvfrom Server : " << recvbuf << std::endl;
}

void test_tcp()
{

}

int main()
{
    test_udp();
    test_tcp();

    return 0;
}