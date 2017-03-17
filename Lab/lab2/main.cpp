#include <iostream>
#include <string>
#include "htmlTable.h"

using namespace std;

int main()
{
    cout << "Content-type: text/html" << endl << endl;
    HTMLTable t(3,4);
    t.print();
    t.borderon();
    t.insert(2,1, "Hopefully");
    t.insert(1,2, "This");
    t.insert(2,3, "Works!");
    t.print();
    t.borderoff();
    t.insert(2,1, "Yes");
    t.insert(2,2, "More");
    t.print();

    return 0;
}
