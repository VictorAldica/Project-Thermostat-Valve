#pragma once
#include "../component/component.hpp"
#include "../sensor/sensor.hpp"

class Thermostat : public Component {
public:
  Thermostat();
  Thermostat(float);
  // ~Thermostat();
  float GetCurrentTemp();
  float GetTargetTemp();
  void SetTargetTemp(float);

private:
  float m_target_temp = -1;
  Sensor m_sensor;
};