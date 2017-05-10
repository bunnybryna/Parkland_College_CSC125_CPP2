#ifndef _FROG_H_
#define _FROG_H_

#include <string>
#include <cstdlib>
#include "organism.h"

using namespace std;

class Frog :public Organism
{
 public:
  string toString() {return "Frog";}
  string getImageName();
  bool isEmpty() {return false;} 
  void move() {}; //do nothing
 private:

};


#endif