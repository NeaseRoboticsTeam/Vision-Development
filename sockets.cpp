#include <iostream>
#include <string>
#include <cmath>
#include <Windows.h>
#include <sys/socket.h>

int main()
{
  int socket_desc;
  struct sockaddr_in server;
  
  char * buffer;
  
  socket_desc = socket(AF_INET , SOCK_STREAM , 0);
  
  server.sin_addr.s_addr = inet_addr("127.0.0.1");
  server.sin_family = AF_INET;
  server.sin_port = htons(444);
  
  connect(socket_desc , (struct sockaddr *)&server , sizeof(server);
  
  while(true)
  {
    if(read(socket_desc, buffer, 2000, 0) != 0)
    {
      send(socket_desc, "Message Received!", strlen("Message Recieved!"), 0);
    }
  }
}
