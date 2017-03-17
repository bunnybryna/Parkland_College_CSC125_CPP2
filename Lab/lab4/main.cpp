#include <iostream>
#include "display.h"

using namespace std;

int main()
{
    Display d;
    d.print("One two three four");
    d.show();
    
    for (int i=0;i<10000000;i++);
}
