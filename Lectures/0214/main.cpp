
#include <iostream>
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

	return 0;	
}

