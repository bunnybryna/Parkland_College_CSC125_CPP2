#include <cstdlib>

#include "jumpingletteroid.h"

void JumpingLetteroid::jump()
{
	erase();
	int row = rand()%20;	
	int col = rand()%80;
	setCoords(row,col);
	draw();
}


