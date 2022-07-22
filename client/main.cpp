#include "client.cpp"

int main() {
  Client C;
  C.Connect();
  C.Send();
  C.Receive();
  C.Close();

  return 0;
}