#include "client.hpp"

int main() {
  Client C;
  C.Connect();
  while (true) {
    C.Send();
    usleep(5000000);
    C.Receive();
  }
  C.Close();

  return 0;
}