#include "server.hpp"

Server::Server() {
  server_sock = socket(AF_INET, SOCK_STREAM, 0);
  if (server_sock < 0) {
    perror("[-]Socket error");
    exit(1);
  }
  cout << "[+]TCP server socket created.\n";

  memset(&server_addr, '\0', sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(port);
  inet_pton(AF_INET, "0.0.0.0", &server_addr.sin_addr);
}

void Server::Bind() {

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

  char host[NI_MAXHOST];    // Client's remote name
  char service[NI_MAXSERV]; // Service (i.e. port) the client is connect on

  memset(host, 0, NI_MAXHOST);
  memset(service, 0, NI_MAXSERV);

  if (getnameinfo((sockaddr *)&client_addr, sizeof(client_addr), host,
                  NI_MAXHOST, service, NI_MAXSERV, 0) == 0) {
    cout << host << " connected on port " << service << "\n";
  } else {
    inet_ntop(AF_INET, &client_addr.sin_addr, host, NI_MAXHOST);
    cout << host << " connected on port " << ntohs(client_addr.sin_port)
         << "\n";
  }
}
void Server::Receive() {

  memset(buffer, 0, 4096);
  int bytes_received = recv(client_sock, buffer, sizeof(buffer), 0);
  if (bytes_received < 0)

    perror("Error in recv(). Quitting\n");

  if (bytes_received == 0)

    cout << "Client disconnected \n";

  cout << string(buffer, 0, bytes_received) << "\n";
}
void Server::Send() { send(client_sock, buffer, sizeof(buffer), 0);  }

void Server::CloseFD() { close(server_sock); }

void Server::Close() {
  close(client_sock);
  cout << "[+]Client disconnected.\n\n";
}