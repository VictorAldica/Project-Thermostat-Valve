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

  if (m_begin_date.GetYear() < m_end_date.GetYear())
    return true;
  else if (m_begin_date.GetYear() == m_end_date.GetYear()) {
    if (m_begin_date.GetMonth() < m_end_date.GetMonth())
      return true;
    else if (m_begin_date.GetMonth() == m_end_date.GetMonth()) {
      if (m_begin_date.GetDay() < m_end_date.GetDay())
        return true;
      else if (m_begin_date.GetDay() == m_end_date.GetDay())
        return ((m_begin_date.GetHour() * 60 + m_begin_date.GetMinute()) <
                (m_end_date.GetHour() * 60 + m_end_date.GetMinute()));
    }
  }

  return false;
}
