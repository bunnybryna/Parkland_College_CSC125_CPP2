#include <iostream>
#include <vector>
#include <string>

using namespace std;
class Date
{
    friend ostream& operator<<(ostream& o, Date d);
    // can't do the following
    // friend Date operator=(const Date &d);

public:
// constructor
    Date();
    Date(int month, int day, int year);
    Date(int month, int day, int year, string name);
    // copy constructor
    Date(const Date &d);
// setter
    void setDate(int month, int day, int year);
    void setName(string data);
// getter
    string getName();
    int getMonth();
    int getDay();
    int getYear();
    void print();

    int maxDaysInMonth();
    void nextDay();
    bool leapYear();

private:
    string m_name;
    int m_month;
    int m_day;
    int m_year;
};

// overloaded comparison operators
bool operator == (Date d1, Date d2);
bool operator!= (Date d1, Date d2);
// prefix
Date operator++(Date &d);
// postfix
Date operator++(Date &d, int dummy);
bool operator>(Date d1,Date d2);


int main()
{

    cout << "----------counting with ++ ------------" << endl;
    // return the value and then increment
    int var1 = 10;
    cout << var1++ << endl;
    // increment first then return the value
    int var2 = 10;
    cout << ++var2 << endl;

    Date today(3,7,2017);
    Date tomorrow(3,8,2017);
    cout << "Preincrement: should be 3/9=>" << ++tomorrow<<endl;
    cout << "Afterwards: should be 3/9=>" << tomorrow << endl;
    cout << "Preincrement: should be 3/7=>" << today++<<endl;
    cout << "Afterwards: should be 3/8=>" << today << endl;
    // >(today, tomorrow) is wrong, use > just like the normal >
    if(today>tomorrow)
        cout << "today is bigger";
    else
        cout << "tomorrow is bigger";
    Date newDate(today);
    cout << newDate;
    Date secondDate=today;
    cout << secondDate;
    return 0;
}

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
// const is an all-or-nothing thing
Date::Date(const Date &d)
{
    m_month = d.m_month;
    m_day = d.m_day;
    m_year = d.m_year;
    m_name = d.m_name;
    // if you call getName here
    // you need to label getName const
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
    std::cout << m_month << "/" << m_day << "/" << m_year<< "[" << m_name <<
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

void Date::nextDay()
{
    if (m_day < maxDaysInMonth())
    {
        m_day++;
    }
    else if(m_month < 12)
    {
        m_day = 1;
        m_month++;
    }
    else
    {
        m_day = 1;
        m_month = 1;
        m_year++;
    }
}

int Date::maxDaysInMonth()
{
    switch(m_month)
    {
        case 9:
        case 4:
        case 6:
        case 11:
            return 30;
        case 2:
            if(leapYear()) return 29;
            return 28;
        default:
            return 31;
    }


}

bool Date::leapYear()
{
    return (m_year%4 == 0 && m_year % 100 == 0)
    || m_year%400 == 0;
}

// prefix ++i
// more often used, don't have to create temp
Date operator++(Date &d)
{
    d.nextDay();
    return d;

}
// postfix i++
Date operator++(Date &d, int dummy)
{
    Date temp=d;
    d.nextDay();
    return temp;
}

bool operator>(Date d1,Date d2)
{
    if (d1.getMonth() == d2.getMonth())
    {
        if(d1.getDay() > d2.getDay())
            return true;
        else
            return false;
    }
}

// it is wrong, overload assignment can only be done in member form
/*Date operator=(const Date &d)
{
    Date temp;
    temp.m_month = d.m_month;
    temp.m_day = d.m_day;
    temp.m_year = d.m_year;
    temp.m_name = d.m_name;
}*/
