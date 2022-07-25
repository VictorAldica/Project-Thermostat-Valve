#include "client.hpp"

int main() {
  Client C;
  C.Connect();
  while (true) {
    C.Send();
    C.Receive();
  }
  C.Close();

  return 0;
}