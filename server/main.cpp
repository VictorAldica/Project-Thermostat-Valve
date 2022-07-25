#include "server.hpp"

int main() {
  Server S;
  S.Bind();
  S.Connect();
  S.Listen();
  S.CloseFD();
  while (true) {
    S.Receive();
    S.Send();
  }

  S.Close();

  return 0;
}