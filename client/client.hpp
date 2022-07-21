#pragma once
#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#define PORT 8080

class Client {
public:
  Client();
  //~Client(); 
  void Connect(); 
  void Close(); 

private:
  int sock = 0, valread, client_fd;
  struct sockaddr_in serv_addr;
  char *hello = "Hello from client";
  char buffer[1024] = {0};
};

