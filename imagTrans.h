#ifndef TCPSOCKET_IMAGTRANS_H
#define TCPSOCKET_IMAGTRANS_H

#include<stdio.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<sys/ioctl.h>
#include<unistd.h>
#include<iostream>
#include<fstream>
#include<errno.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<iostream>
#include<fstream>
#include<cstdio>
#include<cinttypes>
#include<cstdlib>
#include<cstring>


int receive_image(int socket);
int send_image(int socket, const char* filename);


#endif //TCPSOCKET_IMAGTRANS_H