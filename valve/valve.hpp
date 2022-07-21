#pragma once
#include "../component/component.hpp"

class Valve : public Component {
public:
  Valve();
  Valve(float);
  // ~Valve();
  float GetFlowLevel();
  void SetFlowLevel(float);

private:
  float m_flow_level; // 0-1 range
};