#include "room.hpp"

Room::Room() { m_room_name = "<Room name not defined>"; }

Room::Room(string room_name, float temp, int valve_nr) {
  m_room_name = room_name;
  m_thermostat.setTargetTemp(temp);
  for (int i = 0; i < valve_nr; i++)
    m_valves.push_back(Valve());
SetFlowRate();
}

void Room::whereami() {
  std::cout << m_room_name << "\n"
            << "Setpoint to:" << m_thermostat.getTargetTemp() << "\n"
            << "Current temp:" << m_thermostat.getCurrentTemp() << "\n";
}

void Room::DefineSetPoint(float set_point) {
  m_thermostat.setTargetTemp(set_point);
}

float Room::GetRoomTemp() { return m_thermostat.getCurrentTemp(); }

void Room::SetFlowRate() {
  int diff = m_thermostat.getCurrentTemp() - m_thermostat.getTargetTemp();
  if (diff < 0)
    for (Valve v : m_valves)
      v.setFlowLevel(0.0);
  else if (diff >= 0 && diff < 2)
    for (Valve v : m_valves)
      v.setFlowLevel(diff / 10.0);
  else if (diff >= 2 && diff < 4)
    for (Valve v : m_valves)
      v.setFlowLevel(diff / 7.5);
  else if (diff >= 4 && diff < 5)
    for (Valve v : m_valves)
      v.setFlowLevel(diff / 5);
  else if(diff>=5)
    for (Valve v : m_valves)
      v.setFlowLevel(1.0);
}

void Room::GetValveInfo() {
  std::cout << "All " << m_valves.size() << " valves set to "
            << m_valves[0].getFlowLevel() << " flow level\n";
}