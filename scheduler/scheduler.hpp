#pragma once
#include "../date/date.hpp"
#include <iostream>

class Scheduler {
public:
  Scheduler();
  void SetBeginDate(Date);
  void SetEndDate(Date);
  //~Scheduler();
  bool IsValid();

private:
  Date m_begin_date;
  Date m_end_date;
};