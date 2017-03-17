#ifndef _DISPLAY_H_
#define _DISPLAY_H_

#include <string>

class Display {
 public:
  Display();
  void init();
  void print(std::string s);
  void show();
  void clear();
  void newline();

 private:
  char myScr[100][100];
  int myRows;
  int myCols;
  int myRow;
  int myCol;
};

#endif

