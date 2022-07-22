#include "server.cpp"

int main() {
  Server S;
  S.Bind();
  S.Listen();
  S.Connect();
  S.Close();
  
  return 0;
}