#include "frog.h"

string Frog::getImageName()
{
  switch (rand() % 4)
  {
     case 0:   return "frog1.jpg";
     case 1:   return "frog2.jpg";
     case 2:   return "frog3.jpg";
     case 3:   return "frog4.jpg";
     default:  return "frog.jpg";
  }
}
