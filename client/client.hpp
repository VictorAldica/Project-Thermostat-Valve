#include <iostream>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

class Client {
public:
  Client();
  void Connect();
  void Send();
  void Receive();
  void Close();

private:
  char *ip = "127.0.0.1";
  int port = 5566;
  int sock;
  struct sockaddr_in addr;
  socklen_t addr_size;
  char buffer[1024];
};