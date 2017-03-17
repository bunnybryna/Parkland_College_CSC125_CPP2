#include <iostream>
#include "htmlform.h"

using namespace std;

int main()
{
    HTMLForm sentence;
    cout << "Content-type:text/html"<< endl << endl;

    cout << "Started by the form"<< endl;
    sentence.debug();

    return 0;
}
