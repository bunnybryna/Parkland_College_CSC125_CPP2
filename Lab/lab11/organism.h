#ifndef _ORGANISM_H_
#define _ORGANISM_H_

#include <string>

using namespace std;

class Organism
{
 public:
  Organism() {}
  virtual string toString()=0;
  virtual string getImageName()=0;
  virtual bool isEmpty()=0;
  virtual void move()=0;

 private:
};


#endif
