#ifndef _DOODLEBUG_H_
#define _DOODLEBUG_H_

#include <string>
#include "organism.h"

using namespace std;

class DoodleBug :public Organism
{
 public:
  string toString() {return "DoodleBug";}
  string getImageName();
  bool isEmpty() {return false;}
  void move() {}; //do nothing

 private:

};


#endif
