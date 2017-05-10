#ifndef _DISPLAY_H_
#define _DISPLAY_H_

#include <iostream>

using namespace std;

class Display 
{
 public:
  void printForm();
  void print(string);
  void print(int);
  void printline(string);
  void initialize();
  void statusLine();
  void message(string);

  void setDayCount(int data){m_dayCount = data;}
 private:
  int m_dayCount;

};

#endif


