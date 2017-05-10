#ifndef _CELL_H_
#define _CELL_H_

#include "organism.h"
#include "linkedlist.h"
#include <list>

using namespace std;

class Cell
{

 public:
  /// put an organism in a cell
  void setOrganism(Organism* data) {m_Critter=data;}

  /// overwrite the organism in a cell
  void resetOrganism(Organism* data) {delete m_Critter; m_Critter=data;}

  /// get the organism in the cell
  Organism* getOrganism() {return m_Critter;}
  
  /// return a list of neighbors
  LinkedList<Cell *>& getNeighbor() {return m_Neighbors;}

  /// add a new neighbor
  void addNeighbor(Cell *data) { m_Neighbors.push_back(data); }

 private:
  Organism* m_Critter;
  LinkedList<Cell *> m_Neighbors;

};


#endif
