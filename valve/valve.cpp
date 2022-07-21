#include "valve.hpp"

Valve::Valve() {
  m_name = "Valve";
  m_desc = "DescValve.....";
  m_flow_level = -1.0;
}

Valve::Valve(float flow) {
  m_name = "Valve";
  m_desc = "DescValve.....";
  m_flow_level = flow;
}

float Valve::GetFlowLevel() { return m_flow_level; }

void Valve::SetFlowLevel(float lvl) { m_flow_level = lvl; }