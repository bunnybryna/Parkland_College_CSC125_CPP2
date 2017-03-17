#include <iostream>
#include "date.h"

// constructor
Date::Date()
{
    m_month = 1;
    m_day = 1;
    m_year = 1970;
}

Date::Date(int month, int day, int year)
{
    m_month = month;
    m_day = day;
    m_year = year;
}

Date::Date(int month, int day, int year, string name)
{
    m_month = month;
    m_day = day;
    m_year = year;
    m_name = name;
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
int Date::getDay()
{
    return m_day;
}

int Date::getMonth()
{
    return m_month;
}
int Date::getYear()
{
    return m_year;
}

// getter
void Date::print()
{
    cout << m_month << "/" << m_day << "/" << m_year<< "[" << m_name <<
              "]";
}

ostream& operator<<(ostream& o, Date d)
{
    o << d.m_month << "/" << d.m_day << "/" << d.m_year << "[" <<d. m_name <<
      "]";
    return o;
}

bool operator==(Date d1, Date d2)
{
    if (d1.getMonth()==d2.getMonth() &&
            d1.getDay()==d2.getDay() &&
            d1.getYear()== d2.getYear() )

    {
        return true;
    }
    else
        return false;
// return !(d1==d2);
}

bool operator!=(Date d1, Date d2)
{
    return !(d1==d2);
}

