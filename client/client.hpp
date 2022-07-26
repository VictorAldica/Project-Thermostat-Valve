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
class Client {
public:
  Client();
  void Connect();
  void Send();
  void Receive();
  void Close();

private:
  string ip = "127.0.0.1";
  int port = 8080;
  int client_sock;
  string message = "Hello from client\n";
  struct sockaddr_in client_addr;
  socklen_t addr_size;
  char buffer[4096];
};