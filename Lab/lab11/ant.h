#ifndef _ANT_H_
#define _ANT_H_

#include <string>
#include <cstdlib>
#include "organism.h"

using namespace std;

class Ant :public Organism
{
 public:
  string toString() {return "Ant";}
  string getImageName();
  bool isEmpty() {return false;} 
  void move() {}; //do nothing
 private:

};


#endif
