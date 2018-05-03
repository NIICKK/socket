#include "imagTrans.h"

using namespace std;

int main(int argc , char **argv){
  
  int socket_desc;
  struct sockaddr_in server;
  char *parray;
  string filename = "";
  string ip = "";
  filename = argv[1];
  ip = argv[2];

  //Create socket
  socket_desc = socket(AF_INET , SOCK_STREAM , 0);

  if (socket_desc == -1) {
  printf("Could not create socket");
  }

  memset(&server,0,sizeof(server));
  server.sin_addr.s_addr = inet_addr(ip.c_str());
  server.sin_family = AF_INET;
  server.sin_port = htons( 8889 );

  //Connect to remote server
  if (connect(socket_desc , (struct sockaddr *)&server , sizeof(server)) < 0) {
    cout<<strerror(errno);
    close(socket_desc);
    puts("Connect Error");
    return 1;
  }

  puts("Connected\n");

  send_image(socket_desc, filename.c_str());

  receive_image(socket_desc);

  close(socket_desc);

  return 0;
}