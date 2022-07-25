#pragma once
#include <arpa/inet.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <unistd.h>
using std::cout;
using std::string;
class Server {

public:
  Server();
  void Bind();
  void Listen();
  void Connect();
  void Send();
  void Receive();
  void CloseFD();
  void Close();

private:
  int port = 5566;
  int server_sock, client_sock;
  struct sockaddr_in server_addr, client_addr;
  socklen_t addr_size;
  char buffer[4096];
  int n;
};