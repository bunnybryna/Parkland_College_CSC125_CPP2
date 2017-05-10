#include "movingletteroid.h"

void MovingLetteroid::move() {
	erase();
	int myX = getX();
	int myY = getY();
	// (row,x<20,down, col,y<80,across)
    // 0=>right, 1=>down, 2=>left,3=>up	
	if (myDirection == 0)
	{
		if (myY >= 80)
			myY = 1;
		else
			myY = myY+1;		
	}
	else if (myDirection == 1)
	{
		if (myX >= 20)
			myX = 1;
		else
			myX = myX+1;
	}
	else if (myDirection == 2)
	{
		if (myY <= 0)
			myY = 80;
		else
			myY = myY-1;		
	}	
	else if (myDirection == 3)
	{
		if (myX <= 0)
			myX = 20;
		else
			myX = myX-1;		
	}	
	setCoords(myX, myY);
	draw();
}

void MovingLetteroid::setDirection(int d)
{
	myDirection = d;
}	