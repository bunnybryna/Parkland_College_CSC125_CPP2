#ifndef _WORLD_H_
#define _WORLD_H_

#include "cell.h"
#include "ant.h"
#include "doodlebug.h"
#include "organism.h"
#include "border.h"
#include "empty.h"
#include <cstdlib>
#include <vector>



class World
{
 public:
  World(int maxRows=25, int maxCols=60);
  void printHTML();


 private:

  void fill();
  void fillBorder();
  void fillAnt();
  void fillDoodleBug();
  void setNeighbors();
  void setCells();

  vector< vector<Cell*> > m_Grid; /// 2D grid;
  int m_MaxRows;
  int m_MaxCols;

};


#endif
