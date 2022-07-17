#pragma once
#include "../component/component.hpp"
#include "../sensor/sensor.hpp"

class Thermostat : public Component
{
private:
    float m_target_temp=-1;
    Sensor m_sensor;

public:
    Thermostat();
    Thermostat(float);
   // ~Thermostat();
    float getCurrentTemp();
    float getTargetTemp();
    void setTargetTemp(float);
};