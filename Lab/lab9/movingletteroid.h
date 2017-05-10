#ifndef _MOVINGLETTEROID_H_
#define _MOVINKINGLETTEROID_H_

#include "letteroid.h"

class MovingLetteroid :public Letteroid {
 public:
  void move();
  void setDirection(int d);

 private:
  int myDirection;
  
};




#endif
