#include <iostream>
#include <vector>
#include <string>
#include "date.h"

using namespace std;

int main()
{

    cout << "----------counting with ++ ------------" << endl;
    // return the value and then increment
    int var1 = 10;
    cout << var1++ << endl;
    // increment first then return the value
    int var2 = 10;
    cout << ++var2 << endl;

    Date today(3,7,2017);
    Date tomorrow(3,8,2017);
    cout << "Preincrement: should be 3/9=>" << ++tomorrow<<endl;
    cout << "Afterwards: should be 3/9=>" << tomorrow << endl;
    cout << "Preincrement: should be 3/7=>" << today++<<endl;
    cout << "Afterwards: should be 3/8=>" << today << endl;
    // >(today, tomorrow) is wrong, use > just like the normal >
    if(today>tomorrow)
        cout << today;
    else
        cout << tomorrow;
    return 0;
}
