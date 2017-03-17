
#include <iostream>
#include <vector>
#include "date.h"

using namespace std;


int main()
{
    Date d;
    /*can't access private methods  from outside
    	d.m_month = 2;
    	d.m_day = 14;
    	d.m_year = 2017;
    */
    d.setDate(2,14,2017);
    d.setName("Valentine's Day");
    cout << "Today is "<< d.getName() << endl;

    d.print();
    cout << endl;

    Date e;
    e.print();
    cout << endl;
    Date today(3,2,2017);
    today.print();
    cout << endl;
    Date pi(3,14,2017,"pi day");
    pi.print();
    cout << endl;
    vector <Date *> myCalendar;
    myCalendar.push_back( new Date(1,1,2017, "New Years Day") );
    myCalendar.push_back( new Date(1,2,2017 ));
    myCalendar.push_back( new Date(3,14,2017));
    for (int i=0; i<myCalendar.size(); i++)
    {
        myCalendar[i]->print();
        cout << endl;
    }

    if (*(myCalendar[2]) == pi)
    {
        cout << "position2 is the same day as pi day" << endl;
    }

    return 0;
}

