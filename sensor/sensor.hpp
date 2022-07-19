#pragma once
#include "../component/component.hpp"
#include <stdlib.h>
#include <time.h>
class Sensor : public Component {
public:
  Sensor();
  //~Sensor();
  float &getTemp();

private:
  float m_temp = -1;
};
