#pragma once
#include "../component/component.hpp"
#include <stdlib.h>
#include <time.h>
class Sensor : public Component
{
private:
    float m_temp=-1;

public:
    Sensor();
    //~Sensor();
    float &getTemp();
};
