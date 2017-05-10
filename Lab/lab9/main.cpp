#include <ncurses.h>
#include "letteroid.h"
#include "blinkingletteroid.h"
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

  /// create and initialize your letteroids here
  
  while ( screen.waitForKeyPress() ) /// keep going until 'x' is pressed
    {
      one.blink();
      two.blink();
      three.blink();
      four.blink();
      /// call the function that draws your letteroids here

    }


  screen.end();
  return 0;
}
