#include "server.hpp"

Server::Server() {
  server_sock = socket(AF_INET, SOCK_STREAM, 0);
  if (server_sock < 0) {
    perror("[-]Socket error");
    exit(1);
  }
  cout << "[+]TCP server socket created.\n";
}

void Server::Bind() {
  memset(&server_addr, '\0', sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(port);
  inet_pton(AF_INET, "0.0.0.0", &server_addr.sin_addr);

  n = bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr));
  if (n < 0) {
    perror("[-]Bind error");
    exit(1);
  }
  cout << "[+]Bind to the port number:" << port << "\n";
}

void Server::Listen() {
  listen(server_sock, 5);
  cout << "Listening...\n";
}

void Server::Connect() {
  addr_size = sizeof(client_addr);
  client_sock =
      accept(server_sock, (struct sockaddr *)&client_addr, &addr_size);
  cout << "[+]Client connected.\n";
}
void Server::Receive() {
  int bytesReceived = recv(client_sock, buffer, sizeof(buffer), 0);
  if (bytesReceived <0 )

   perror("Error in recv(). Quitting\n");

  if (bytesReceived == 0)

    cout << "Client disconnected \n";

  cout << string(buffer, 0, bytesReceived) << "\n";
}
void Server::Send() { send(client_sock, buffer, strlen(buffer), 0); }

void Server::CloseFD() { close(server_sock); }

void Server::Close() {
  close(client_sock);
  cout << "[+]Client disconnected.\n\n";
}