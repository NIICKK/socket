#include<stdio.h>
#include "imagTrans.h"

using namespace std;

int main(int argc , char *argv[]){

  int socket_desc , new_socket , c, read_size,buffer = 0;
  struct sockaddr_in server , client;
  char *readin;
  bool READY = false; //determine if the image processing has finish
  const char filename[] = "iceland.jpeg";

  //Create socket
  socket_desc = socket(AF_INET , SOCK_STREAM , 0);
  if (socket_desc == -1){
    printf("Could not create socket");
  }

  //Prepare the sockaddr_in structure
  server.sin_family = AF_INET;
  server.sin_addr.s_addr = INADDR_ANY;
  server.sin_port = htons( 8889 );

  //Bind
  if( bind(socket_desc,(struct sockaddr *)&server , sizeof(server)) < 0){
    puts("bind failed");
    return 1;
  }
  puts("bind done");

  //Listen
  listen(socket_desc , 3);

  //Accept and incoming connection
  puts("Waiting for incoming connections...");
  c = sizeof(struct sockaddr_in);

  if((new_socket = accept(socket_desc, (struct sockaddr *)&client,(socklen_t*)&c))){
    puts("Connection accepted");
  }
  fflush(stdout);

  if (new_socket<0){
    perror("Accept Failed");
    return 1;
  }

  receive_image(new_socket);
  //while(!READY){}//wait for imag processing to complete

  
  send_image(new_socket,filename);

  close(socket_desc);
  fflush(stdout);
  return 0;
}