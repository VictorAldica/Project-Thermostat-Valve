#pragma once
#include <iostream>

class Date {
public:
  Date();
  Date(int);
  Date(int, int);
  Date(int, int, int);
  Date(int, int, int, int);
  Date(int, int, int, int, int);
  //~Date();
  bool IsValidDate();
  bool IsValidHour();
  bool IsLeapYear(int);
  int GetDay();
  int GetMonth();
  int GetYear();
  int GetHour();
  int GetMinute();

private:
  int m_day;
  int m_month;
  int m_year;
  int m_hour;
  int m_minute;
};