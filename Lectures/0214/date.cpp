#include <iostream>
#include "date.h"
// constructor
Date::Date()
{
  m_month = 1;
  m_day = 1;
  m_year = 1970;
}

// setter
void Date::setDate(int month, int day, int year)
{
  m_month = month;
  m_day = day;
  m_year = year;
}
// setter
void Date::setName(string data)
{
   m_name = data;
}
// getter
string Date::getName()
{
  return m_name;
}
// getter
void Date::print()
{
  std::cout << m_month << "/" << m_day << "/" << m_year;
}

