#pragma once
#include "../thermostat/thermostat.hpp"
#include "../valve/valve.hpp"
#include <iostream>
#include <vector>
using std::string;
using std::vector;

class Room {
public:
  Room();
  Room(string, float, int);
  //~Room();
  void DefineSetPoint(float);
  float GetRoomTemp();
  void whereami();
  void SetFlowRate();
  void GetValveInfo();

private:
  string m_room_name;
  Thermostat m_thermostat;
  vector<Valve> m_valves;
};