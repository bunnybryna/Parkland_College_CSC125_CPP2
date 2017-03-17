#ifndef _DATE_H_
#define _DATE_H_

#include <string>

using namespace std;

class Date
{
public:
// constructor
  Date();
// setter
  void setDate(int month, int day, int year);
  void setName(string data);
// getter
  string getName();
  void print();

private:
  string m_name;
  int m_month;
  int m_day;
  int m_year;
};

#endif
