#ifndef _DATE_H_
#define _DATE_H_

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


#endif
