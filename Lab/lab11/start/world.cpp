#include "world.h"
#include <iostream>

using namespace std;

/* How the world is set up for maxRows = 2, maxCols=5
b - Border
    0123456 
0   bbbbbbb
1   b     b
2   b     b
3   bbbbbbb
*/


World::World(int maxRows, int maxCols)
{
  m_MaxRows = maxRows;
  m_MaxCols = maxCols;

  fill();         /// dynamically allocate the world with 'null'
  fillBorder();   /// init the world with a border and empty cells
  setNeighbors(); /// link up all the cells with their neighbors;

  /// add a pond here
  fillAnt();      /// add ants to random empty cells
  fillDoodleBug();/// add doodlebugs to random empty cells
  /// add frog here

  setCells(); /// linkup all the organisms with their cells
}

// show the world
void World::printHTML()
{
  int row, col;
  cout << "<table border=0 cellspacing='0' cellpadding='0' align='center'>\n";
  for (row=0;row<m_MaxRows+2;row++) 
    {
      cout << "\t<tr>\n";
      for (col=0;col<m_MaxCols+2;col++)
	{
	  cout << "\t\t<td>\n";
	  if (m_Grid[row][col] != 0)
	    {
	      //cout << m_Grid[row][col]->getOrganism()->toString();
	      cout << "\t\t\t<img src='" 
                   << m_Grid[row][col]->getOrganism()->getImageName()
		   << "' width='12' />";
	    }
          else
	    {
	      cout << "oops";
	    }
	  cout << "\t\t</td>\n";
	}
      cout << "\t</tr>\n";
    }
  cout << "</table>\n\n";
}

void World::setNeighbors()
{
  int row, col;
  
  for (row=1;row<m_MaxRows+1;row++) 
    {
      for (col=1;col<m_MaxCols+1;col++)
	{
	  /// make 4 neighbors for each non-border cell
	  m_Grid[row][col]->addNeighbor( m_Grid[row-1][col] ) ; // up
	  m_Grid[row][col]->addNeighbor( m_Grid[row+1][col] ) ; // down
	  m_Grid[row][col]->addNeighbor( m_Grid[row][col+1] ) ; // right
	  m_Grid[row][col]->addNeighbor( m_Grid[row][col-1] ) ; // left
	}
    }
}

void World::fill()
{
  vector<Cell *> tempRow;
  int col, row;
  for (col=0;col<m_MaxCols+2;col++)
    tempRow.push_back( static_cast<Cell *>(0) ); // add a null cell*

  for (row=0;row<m_MaxRows+2;row++)
    m_Grid.push_back(tempRow);   /// add a blank row
}

void World::fillBorder()
{
  int row, col;
  
  for (row=0;row<m_MaxRows+2;row++) 
    {
      for (col=0;col<m_MaxCols+2;col++)
	{
	  m_Grid[row][col] = new Cell();   /// create a new cell

          if (col == 0 || row == 0 || col == m_MaxCols+1 || row == m_MaxRows+1)
	    { 
	      m_Grid[row][col]->setOrganism( new Border() ) ;
	    }
	  else 
	    { 
	      m_Grid[row][col]->setOrganism( new Empty() ) ;
	    }
	}
    }
}

void World::fillAnt()
{
  int row, col;
  
  for (row=0;row<m_MaxRows+2;row++) 
    {
      for (col=0;col<m_MaxCols+2;col++)
	{
	  if ( m_Grid[row][col]->getOrganism()->isEmpty() 
               && rand()%20==0 ) // empty & 5%  
	    { 
	      m_Grid[row][col]->resetOrganism( new Ant() ) ;
	    }
	}
    }
}

void World::fillDoodleBug()
{
  int row, col;
  
  for (row=0;row<m_MaxRows+2;row++) 
    {
      for (col=0;col<m_MaxCols+2;col++)
	{
	  if ( m_Grid[row][col]->getOrganism()->isEmpty() 
               && rand()%40==0 ) // empty & 2.5%  
	    { 
	      m_Grid[row][col]->resetOrganism( new DoodleBug() ) ;
	    }
	}
    }
}


void World::setCells()
{

}
