#include "sensor.hpp"

Sensor::Sensor()
{
    m_name="Sensor";
    m_desc="DescSensor...";
    srand(time(NULL));
    m_temp=rand()%29+1;      
}

float Sensor::GetTemp()
{
    return m_temp;
}
