#include <iostream>
#include "sock.h"
#include <unistd.h>

int main(){
    std::cout << "Hello world!" << std::endl;
    const int rsock = get_rawsocket(IPPROTO_ICMP);

    while (1) {
        uint8_t buf[10000];
        const ssize_t recvlen = recvfrom(rsock, buf, 10000, 0, NULL, NULL);

        if (recvlen == -1){
            std::cout << "Recv fail" << std::endl; 
            sleep(1);
        } else {
            std::cout << "Recvraw len : " << recvlen << std::endl;
        }
    }
    return 0;
}