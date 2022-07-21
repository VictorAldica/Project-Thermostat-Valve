#include "room.hpp"

Room::Room() { m_room_name = "<Room name not defined>"; }

Room::Room(string room_name, float temp, int valve_nr) {
  m_room_name = room_name;
  m_thermostat.SetTargetTemp(temp);
  for (int i = 0; i < valve_nr; i++)
    m_valves.push_back(Valve());
}

void Room::whereami() {
  std::cout << m_room_name << "\n"
            << "Setpoint to:" << m_thermostat.GetTargetTemp() << "\n"
            << "Current temp:" << m_thermostat.GetCurrentTemp() << "\n";
}

void Room::DefineSetPoint(float set_point) {
  m_thermostat.SetTargetTemp(set_point);
}

float Room::GetRoomTemp() { return m_thermostat.GetCurrentTemp(); }

void Room::SetFlowRate() {
  int diff = m_thermostat.GetTargetTemp() - m_thermostat.GetCurrentTemp();
  if (diff < 0)
    for (int i = 0; i < m_valves.size(); i++)
      m_valves[i].SetFlowLevel(0.0);
  else if (diff >= 0 && diff < 2)
    for (int i = 0; i < m_valves.size(); i++)
      m_valves[i].SetFlowLevel(diff / 10.0);
  else if (diff >= 2 && diff < 4)
    for (int i = 0; i < m_valves.size(); i++)
      m_valves[i].SetFlowLevel(diff / 7.5);
  else if (diff >= 4 && diff < 5)
    for (int i = 0; i < m_valves.size(); i++)
      m_valves[i].SetFlowLevel(diff / 5);
  else if(diff>=5)
    for (int i = 0; i < m_valves.size(); i++)
      m_valves[i].SetFlowLevel(1.0);
}

void Room::GetValveInfo() {
  std::cout << "All " << m_valves.size() << " valves set to "
           << m_valves[0].GetFlowLevel() << " flow level\n";

}