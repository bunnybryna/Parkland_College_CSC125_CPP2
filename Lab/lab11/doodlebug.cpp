#include "doodlebug.h"
#include <cstdlib>

string DoodleBug::getImageName()
{
  switch (rand() % 4)
  {
     case 0:   return "doodlebug1.jpg";
     case 1:   return "doodlebug2.jpg";
     case 2:   return "doodlebug3.jpg";
     case 3:   return "doodlebug4.jpg";
     default:  return "doodlebug.jpg";
  }
}
