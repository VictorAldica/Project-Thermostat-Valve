#include "scheduler.hpp"

Scheduler::Scheduler()
    : m_begin_date(Date(1, 1, 1900, 0, 0)),
      m_end_date(Date(1, 1, 1900, 0, 1)){};

void Scheduler::SetBeginDate(Date date) {
  if (date.IsValidDate() && date.IsValidHour())
    m_begin_date = date;
}

void Scheduler::SetEndDate(Date date) {
  if (date.IsValidDate() && date.IsValidHour())
    m_end_date = date;
}

bool Scheduler::IsValid() {

  if (m_begin_date.getYear() < m_end_date.getYear())
    return true;
  else if (m_begin_date.getYear() == m_end_date.getYear()) {
    if (m_begin_date.getMonth() < m_end_date.getMonth())
      return true;
    else if (m_begin_date.getMonth() == m_end_date.getMonth()) {
      if (m_begin_date.getDay() < m_end_date.getDay())
        return true;
      else if (m_begin_date.getDay() == m_end_date.getDay())
        return ((m_begin_date.getHour() * 60 + m_begin_date.getMinute()) <
                (m_end_date.getHour() * 60 + m_end_date.getMinute()));
    }
  }

  return false;
}
