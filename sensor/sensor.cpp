#include "sensor.hpp"

Sensor::Sensor()
{
    m_name="Sensor";
    m_desc="DescSensor...";
    srand(time(NULL));
    m_temp=rand()%20+11;      
}

float Sensor::GetTemp()
{
    return m_temp;
}
