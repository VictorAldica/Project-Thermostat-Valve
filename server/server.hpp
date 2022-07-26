#pragma once
#include <arpa/inet.h>
#include <iostream>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <sys/socket.h>
#include <unistd.h>
#define NI_MAXHOST 1025
#define NI_MAXSERV 32
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
  int port = 8080;
  int server_sock, client_sock;
  struct sockaddr_in server_addr, client_addr;
  socklen_t addr_size;
  char buffer[4096];
  int n;
};