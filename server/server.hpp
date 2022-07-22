#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

class Server {

public:
  Server();
  void Bind();
  void Listen();
  void Connect();
  void Close();

private:
  char *ip = "127.0.0.1";
  int port = 5566;
  int server_sock, client_sock;
  struct sockaddr_in server_addr, client_addr;
  socklen_t addr_size;
  char buffer[1024];
  int n;
};