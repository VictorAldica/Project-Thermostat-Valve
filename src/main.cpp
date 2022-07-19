#include "../room/room.hpp"
#include "../scheduler/scheduler.hpp"

int main(int argc, char *argv[]) {
/*
  Room R("Bucatarie", 21);
  R.whereami();
*/
  Scheduler S;
  S.SetBeginDate(Date(18,7,2022,10,0));
  S.SetEndDate(Date(19,7,2022,10,0));
  std::cout<<"\n"<<S.IsValid()<<"\n";

  return 0;
}


