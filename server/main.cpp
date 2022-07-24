#include "server.cpp"

int main() {
  Server S;
  S.Bind();
  S.Connect();
  S.Listen();
  while (true) {
    S.Receive();
    S.Send();
  }
  S.Close();

  return 0;
}