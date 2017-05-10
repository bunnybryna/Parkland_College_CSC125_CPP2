#include <ncurses.h>
#include <cstdlib>
#include "letteroid.h"
#include "blinkingletteroid.h"
#include "jumpingletteroid.h"
#include "movingletteroid.h"
#include "letteroidfield.h"
/// include your derived classes here


int main()
{


  LetteroidField screen;
  screen.start();
  screen.setTitle("LETTEROIDS, press any key to move, 'x' to quit");

  
  BlinkingLetteroid one(true);
  BlinkingLetteroid two(false);
  BlinkingLetteroid three(false);
  BlinkingLetteroid four(true);


  one.setLetter('!'); /// character
  one.setCoords(5, 10); /// row, col
  two.setLetter('h');
  two.setCoords(7, 9);
  three.setLetter('@');
  three.setCoords(15, 57);
  four.setLetter('*');
  four.setCoords(10, 47);

  JumpingLetteroid a;
  JumpingLetteroid b;
  JumpingLetteroid c;
  JumpingLetteroid d;
  a.setLetter('J');
  b.setLetter('U');
  c.setLetter('M');
  d.setLetter('P');  

  MovingLetteroid alpha;
  MovingLetteroid beta;  
  MovingLetteroid gamma;  
  MovingLetteroid delta;  
  alpha.setLetter('m'); 
  alpha.setCoords(13, 78);
  alpha.setDirection(0);
  beta.setLetter('o'); 
  beta.setCoords(19, 0);
  beta.setDirection(1);
  gamma.setLetter('v'); 
  gamma.setCoords(5, 2);
  gamma.setDirection(2);
  delta.setLetter('e'); 
  delta.setCoords(1, 55);
  delta.setDirection(3);  
  
  
  while ( screen.waitForKeyPress() ) /// keep going until 'x' is pressed
    {
      one.blink();
      two.blink();
      three.blink();
      four.blink();
	  a.jump();
	  b.jump();
	  c.jump();
	  d.jump();
	  alpha.move();
	  beta.move();
	  gamma.move();
	  delta.move();
      /// call the function that draws your letteroids here

    }


  screen.end();
  return 0;
}
