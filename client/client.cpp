#include "client.hpp"

Client::Client() {
  client_sock = socket(AF_INET, SOCK_STREAM, 0);
  if (client_sock < 0) {
    cout << "[-]Socket error";
    exit(1);
  }
  cout << "[+]TCP client socket created.\n";

  memset(&client_addr, '\0', sizeof(client_addr));
  client_addr.sin_family = AF_INET;
  client_addr.sin_port = htons(port);
  inet_pton(AF_INET, ip.c_str(), &client_addr.sin_addr);
}

void Client::Connect() {
  connect(client_sock, (struct sockaddr *)&client_addr, sizeof(client_addr));
  cout << "Connected to the server.\n";
}

void Client::Send() {
  send(client_sock, message.c_str(), message.size() + 1, 0);
}

void Client::Receive() {

  recv(client_sock, buffer, sizeof(buffer), 0);
  cout << "Server: " << buffer;
}

void Client::Close() {
  close(client_sock);
  cout << "Disconnected from the server.\n";
}