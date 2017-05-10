#include <iostream>
#include <cstdlib>
#include "htmlform.h"
#include "display.h"
#include "world.h"
#include <ctime>

//#define DEBUG

using namespace std;

int main()
{
  srand(time(0));

  /// complete the http header
  cout << "Content-type: text/html\n\n";

  /// build a form object
  HTMLform doodleWorld;
  Display htmlscreen;

  doodleWorld.getPostData();

  /// Show the debugging

#ifdef DEBUG  
  cout << "Doodle Bug version 0.02 (3/31/16)" << endl;
  doodleWorld.debug();
#endif

  /// testing for now
  int dayCount=1; 
  
  if (doodleWorld.getField("submitButton") != "Click Me")
    {
      htmlscreen.initialize();
    }
  else 
    {
      dayCount =  atoi( doodleWorld.getField("dayCount").c_str() );
      dayCount++;
      htmlscreen.setDayCount(dayCount);
    }


  //htmlscreen.print(dayCount);
  //htmlscreen.printForm();

  htmlscreen.statusLine();

  /// create the world with 40 rows and 80 columns
  World w(40,80);
  w.printHTML();


  return 0;
}
