#include "server.hpp"

Server::Server() {
  server_sock = socket(AF_INET, SOCK_STREAM, 0);
  if (server_sock < 0) {
    perror("[-]Socket error");
    exit(1);
  }
  printf("[+]TCP server socket created.\n");
  memset(&server_addr, '\0', sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = port;
  server_addr.sin_addr.s_addr = inet_addr(ip);
}

void Server::Bind() {
  n = bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr));
  if (n < 0) {
    perror("[-]Bind error");
    exit(1);
  }
  printf("[+]Bind to the port number: %d\n", port);
}

void Server::Listen() {
  listen(server_sock, 5);
  printf("Listening...\n");
}

void Server::Connect() {
  while (1) {
    addr_size = sizeof(client_addr);
    client_sock =
        accept(server_sock, (struct sockaddr *)&client_addr, &addr_size);
    printf("[+]Client connected.\n");

    recv(client_sock, buffer, sizeof(buffer), 0);
    printf("Client: %s\n", buffer);

    strcpy(buffer, "Hello from SERVER");
    printf("Server: %s\n", buffer);
    send(client_sock, buffer, strlen(buffer), 0);
  
  
    sleep(5000);
    Close();
  }
}

void Server::Close() {
  close(client_sock);
  printf("[+]Client disconnected.\n\n");
}