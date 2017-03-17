#include <iostream>
#include "htmlform.h"

using namespace std;

int main()
{
  cout << "Content-type: text/html\n\n";

  /// build a form object
  HTMLform crazyAd;
  crazyAd.getPostData(); 

  /// Show the debugging
  cout << "Bryna Crazy Ad version 1" << endl;
  crazyAd.debug();

  /// the output (name is in the html form that started this)
 cout << "Are you bothered by "<< crazyAd.getField("adj1") << " " << crazyAd.getField("noun1") << "?\n"
      << "Do you feel " << crazyAd.getField("adj2") << " every day?\n"
      << "Does your "<< crazyAd.getField("body") << " hurt?\n"
      << "Then " << crazyAd.getField("makeUp") << " is for you!\n"
      << "This "<< crazyAd.getField("adj3") << " " << crazyAd.getField("adj4") << " treat is chock-full of " << crazyAd.getField("food") << ". " << endl;
 cout << "Here is what " << crazyAd.getField("name") << " of " << crazyAd.getField("city") << ", " << crazyAd.getField("state") << " had to say about "<< crazyAd.getField("makeUp") << ". "
          << "I start every day with " << crazyAd.getField("makeUp") << ". It's simply " << crazyAd.getField("adj5") << "! Even my " << crazyAd.getField("noun2") << " loves it.\n";
 cout << endl;
 cout << "Don't delay! Buy " << crazyAd.getField("makeUp") << " today!\n";
 
  return 0;
}