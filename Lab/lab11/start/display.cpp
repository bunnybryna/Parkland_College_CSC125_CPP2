#include "display.h"

void Display::printForm()
{
  cout << "<form method='POST'>\n";

  // This version just resets - Ken Urban
  //  cout << "\t<input type='hidden' name='dayCount' value='" << m_dayCount <<  "' />\n";

  // cout << "\t<input type='submit' name='submitButton' value='Click Me'  />\n";
  cout << "\t<input type='submit' name='submitButton' value='Redraw'  />\n";
  cout << "</form>\n";
}

void Display::print(string st)

{


  cout << st << "\n";
}

void Display::print(int i)
{
  cout << "<h1>" << i << "</h1>" << "\n";
}

void Display::printline(string st)
{
  cout << st << "<br />\n";
}

void Display::initialize()
{
  message( "Welcome to doodle bug version 1");
  m_dayCount = 1;
}

void Display::message(string st)
{
  cout << "\t<span style='position: absolute; bottom: 0; right: 0; display: block; "
       << "background: #ddffff; width: 200px; height: 100px;'>";
  cout << st;
  cout << "</span>\n";
}

void Display::statusLine()
{
  cout << "\t<span style='position: absolute; bottom: 0; left: 0; display: block; "
       << "background: #ffddff; width: 200px; height: 100px;'>";
  //  cout << "day count " << m_dayCount;
  printForm();
  cout << "</span>\n";
}
