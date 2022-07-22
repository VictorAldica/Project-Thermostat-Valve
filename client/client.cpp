#include "client.hpp"

Client::Client() {
  sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock < 0) {
    perror("[-]Socket error");
    exit(1);
  }
  printf("[+]TCP server socket created.\n");

  memset(&addr, '\0', sizeof(addr));
  addr.sin_family = AF_INET;
  addr.sin_port = port;
  addr.sin_addr.s_addr = inet_addr(ip);
}

void Client::Connect() {
  connect(sock, (struct sockaddr *)&addr, sizeof(addr));
  printf("Connected to the server.\n");
}

void Client::Receive() {

  recv(sock, buffer, sizeof(buffer), 0);
  printf("Server: %s\n", buffer);
}

void Client::Send() {

  strcpy(buffer, "Hello from CLIENT");
  printf("Client: %s\n", buffer);
  send(sock, buffer, strlen(buffer), 0);
}

void Client::Close() {
  close(sock);
  printf("Disconnected from the server.\n");
}