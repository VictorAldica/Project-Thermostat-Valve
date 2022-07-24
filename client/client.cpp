#include "client.hpp"

Client::Client() {
  sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock < 0) {
    cout<<"[-]Socket error";
    exit(1);
  }
 cout<<"[+]TCP server socket created.\n";

  memset(&addr, '\0', sizeof(addr));
  addr.sin_family = AF_INET;
  addr.sin_port = htons(port);
  inet_pton(AF_INET, ip.c_str(), &addr.sin_addr);
}

void Client::Connect() {
  connect(sock, (struct sockaddr *)&addr, sizeof(addr));
  cout<<"Connected to the server.\n";
}

void Client::Send() { send(sock, message.c_str(), message.size() + 1, 0); }

void Client::Receive() {

  recv(sock, buffer, sizeof(buffer), 0);
  cout<<"Server: "<<buffer;
}

void Client::Close() {
  close(sock);
  cout<<"Disconnected from the server.\n";
}