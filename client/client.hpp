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
  int port = 5566;
  int sock;
  string message = "hello from client";
  struct sockaddr_in addr;
  socklen_t addr_size;
  char buffer[1024];
};