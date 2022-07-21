#include "thermostat.hpp"

Thermostat::Thermostat()
{
    m_name = "Thermostat";
    m_desc = "DescThermostat.....";
}

Thermostat::Thermostat(float target_temp)
{
    m_name = "Thermostat";
    m_desc = "DescThermostat.....";
    m_target_temp = target_temp;
}

float Thermostat::GetTargetTemp()
{
    return m_target_temp;
}

void Thermostat::SetTargetTemp(float target_temp)
{
    m_target_temp = target_temp;
}

float Thermostat::GetCurrentTemp()
{

    return m_sensor.GetTemp();
}
