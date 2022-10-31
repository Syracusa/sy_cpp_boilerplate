
#include <iostream>
#include "sock.h"
#include <unistd.h>

void hexdump(void *data, int len, FILE* stream)
{
   const int BYTE_INLINE = 16;
   char ascii_buf[BYTE_INLINE + 1];
   unsigned char *ptr = (unsigned char *)data;

   ascii_buf[BYTE_INLINE] = '\0';

   int linecount = 0;
   int lineoffset;
   for (int i = 0; i < len; i++)
   {
      lineoffset = i % BYTE_INLINE;

      /* Print offset if newline */
      if (lineoffset == 0)
         fprintf(stream, " %04x ", i);
      
      /* Add space at every 4 bytes.. */
      if (lineoffset % 4 == 0)
         fprintf(stream, " ");

      fprintf(stream, " %02x", ptr[i]);
      if ((ptr[i] < 0x20) || (ptr[i] > 0x7e))
         ascii_buf[lineoffset] = ' ';
      else
         ascii_buf[lineoffset] = ptr[i];

      /* Print ASCII if end of line */
      if (lineoffset == BYTE_INLINE - 1){
         fprintf(stream, "  %s\n", ascii_buf);
         linecount++;

         /* Print additional newline at every 5 lines */
         if (linecount != 0 && linecount % 5 == 0)
            fprintf(stream, "\n");
      }
   }

   ascii_buf[lineoffset + 1] = '\0';
   fprintf(stream, " %s\n", ascii_buf);
}

int main(){
    std::cout << "Rawsocket testapp" << std::endl;
    const int rsock = get_rawsocket(IPPROTO_ICMP);

    while (1) {
        uint8_t buf[10000];
        const ssize_t recvlen = recvfrom(rsock, buf, 10000, 0, NULL, NULL);

        if (recvlen == -1){
            std::cout << "Recv fail" << std::endl; 
            sleep(1);
        } else {
            std::cout << "Recvraw len : " << recvlen << std::endl;
            hexdump(buf, recvlen, stdout);
        }
    }
    return 0;
}