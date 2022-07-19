#include "date.hpp"

Date::Date() : m_day(1), m_month(1), m_year(1900), m_hour(0), m_minute(0) {}

Date::Date(int day)
    : m_day(day), m_month(1), m_year(1900), m_hour(0), m_minute(0) {}

Date::Date(int day, int month)
    : m_day(day), m_month(month), m_year(1900), m_hour(0), m_minute(0) {}

Date::Date(int day, int month, int m_year)
    : m_day(day), m_month(month), m_year(m_year), m_hour(0), m_minute(0) {}

Date::Date(int day, int month, int m_year, int hour)
    : m_day(day), m_month(month), m_year(m_year), m_hour(hour), m_minute(0) {}

Date::Date(int day, int month, int m_year, int hour, int minute)
    : m_day(day), m_month(month), m_year(m_year), m_hour(hour),
      m_minute(minute) {}

bool Date::IsLeapYear(int year) {

  return (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
}

bool Date::IsValidDate() {

  if (m_year > 9999 || m_year < 1900)
    return false;
  if (m_month < 1 || m_month > 12)
    return false;
  if (m_day < 1 || m_day > 31)
    return false;

  if (m_month == 2) {
    if (IsLeapYear(m_year))
      return (m_day <= 29);
    else
      return (m_day <= 28);
  }

  if (m_month == 4 || m_month == 6 || m_month == 9 || m_month == 11)
    return (m_day <= 30);

  return true;
}

bool Date::IsValidHour() {
  if (m_hour > 23 || m_hour < 0)
    return false;
  if (m_minute > 59 || m_hour < 0)
    return false;

  return true;
}

int Date::getDay() { return m_day; }

int Date::getMonth() { return m_month; }

int Date::getYear() { return m_year; }

int Date::getHour() { return m_hour; }

int Date::getMinute() { return m_minute; }
