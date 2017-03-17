#include <iostream>
#include <vector>
#include <string>

using namespace std;
class Date
{
    friend ostream& operator<<(ostream& o, Date d);
public:
// constructor
    Date();
    Date(int month, int day, int year);
    Date(int month, int day, int year, string name);
// setter
    void setDate(int month, int day, int year);
    void setName(string data);
// getter
    string getName();
    int getMonth();
    int getDay();
    int getYear();
    void print();

private:
    string m_name;
    int m_month;
    int m_day;
    int m_year;
};

// overloaded comparison operators
bool operator == (Date d1, Date d2);
bool operator!= (Date d1, Date d2);

int main()
{
    Date d;
    /*can't access private methods  from outside
    	d.m_month = 2;
    	d.m_day = 14;
    	d.m_year = 2017;
    */
    d.setDate(2,14,2017);
    d.setName("Valentine's Day");
    cout << "Today is "<< d.getName() << endl;

    d.print();
    cout << endl;

    Date e;
    e.print();
    cout << endl;
    Date today(3,2,2017);
    today.print();
    cout << endl;
    Date pi(3,14,2017,"pi day");
    pi.print();
    cout << endl;
    vector <Date *> myCalendar;
    myCalendar.push_back( new Date(1,1,2017, "New Years Day") );
    myCalendar.push_back( new Date(1,2,2017 ));
    myCalendar.push_back( new Date(3,14,2017));
    for (int i=0; i<myCalendar.size(); i++)
    {
        myCalendar[i]->print();
        cout << endl;
    }

    if (*(myCalendar[2]) == pi)
    {
        cout << "position2 is the same day as pi day" << endl;
    }

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

