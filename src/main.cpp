#include "../client/client.hpp"
#include "../room/room.hpp"
#include "../scheduler/scheduler.hpp"
#include "../server/server.hpp"
using std::cout;
using std::cin;

int main(int argc, char *argv[]) {

  string room_name;
  float setpoint_temp;
  int valve_nr;

  
    cout<<"Enter a room name:"; cin>>room_name;
    cout<<"Enter the room's desired temperature (*C):"; cin>>setpoint_temp;
    cout<<"Enter the number of valves:"; cin>>valve_nr;
    Room R(room_name,setpoint_temp,valve_nr);
    cout<<"~======================~\n";
    R.whereami();
    R.GetValveInfo();
    
  

  return 0;
}
