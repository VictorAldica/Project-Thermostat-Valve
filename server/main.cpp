#include "server.hpp"

int main() {
  Server S;
  S.Bind();
  S.Listen();
  S.Connect();
  S.CloseFD();
  while (true) {
    S.Receive();
    usleep(5000000);
    S.Send();
  }

  S.Close();

  return 0;
}