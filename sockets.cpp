#include <iostream>
#include <string>
#include <cmath>
#include <Windows.h>
#include <sys/socket.h>

int main()
{
  int socket_desc;
  struct sockaddr_in server;
  
  //create socket client
  socket_desc = socket(AF_INET , SOCK_STREAM , 0);
  
  //server settings
  server.sin_addr.s_addr = inet_addr("127.0.0.1");
  server.sin_family = AF_INET;
  server.sin_port = htons(444);
  
  //connect to server socket
  connect(socket_desc , (struct sockaddr *)&server , sizeof(server);
  //create buffer variable for print data
  bzero(buffer, 256);
          
  while(true)
  {
    //read and save to buffer variable
    if(read(socket_desc, buffer, 255) >= 0)
    {
      //send the recieved message
      send(socket_desc, "Message Recieved!", strlen("Message Recieved!"), 0);
    }
  }
}
