// 16.2 Same Thing Using Exception Handling
#include <iostream>
using namespace std;
int main()
{
	int donuts, milk;
	double dpg;
	try
	{
		cout << "Enter number of donuts:\n";
		cin >> donuts;
		cout << "Enter number of glasses of milk:\n";
		cin >> milk;
		
		if (milk <=0)
			throw donuts;
		dpg = donuts/static_cast<double>(milk);
		cout << donuts << " donuts.\n"
			 << milk << " glasses of milk.\n"
			 << "You have " << dpg << " donuts for each glass of milk.\n";
	}
	// catch block is not a function, but like a function
	// can do things with the thrown value that is caught
	catch(int e)
	{
		cout << e << " donuts, and No Mlik!\n"
			 << "Go buy some milk.\n";
	}
	cout << "End of program.\n";
	return 0;
}

// 16.3 Defining Your Own Exception Class

#include <iostream>
using namespace std;

class NoMilk
{
	public:
	NoMilk();
	NoMilk(int how_many);
	int get_donuts();
	private:
	int count;
};
int main()
{
	int donuts, milk;
	double dpg;
	try
	{
		cout << "Enter number of donuts:\n";
		cin >> donuts;
		cout << "Enter number of glasses of milk:\n";
		cin >> milk;
		
		if (milk <=0)
			throw NoMilk(donuts);
		dpg = donuts/static_cast<double>(milk);
		cout << donuts << " donuts.\n"
			 << milk << " glasses of milk.\n"
			 << "You have " << dpg << " donuts for each glass of milk.\n";
	}
	catch(NoMilk e)
	{
		cout << e.get_donuts() << " donuts, and No Mlik!\n"
			 << "Go buy some milk.\n";
	}
	cout << "End of program.\n";
	return 0;
}

NoMilk::NoMilk()
{
}
NoMilk::NoMilk(int how_many) : count(how_many)
{
}
int NoMilk::get_donuts()
{
	return count;
}

// 16.4 Catching Multiple Exceptions
#include <iostream>
#include <string>
using namespace std;
class NegativeNumber
{
	public:
	NegativeNumber();
	NegativeNumber(string take_me_to_your_catch_block);
	string get_message();
	private:
	string message;
};
// no member variables and no member function except the default constructor
class DivideByZero
{
};

int main()
{
	int jem_hadar,klingons;
	double portion;
	try
	{
		cout << "Enter number of JemHadar warriors:\n";
		cin >> jem_hadar;
		if (jem_hadar<0)
			throw NegativeNumber("JemHadar");
		cout << "How many Klingon warriors do you have?\n";
		cin >> klingons;
		if (klingons<0)
			throw NegativeNumber("Klingons");
		if (klingons !=0)
			portion = jem_hadar/static_cast<double>(klingons);
		else
			throw DivideByZero();
		cout << "Each Klingon must fight " << portion << " JemHadar.\n";
	}
	catch(NegativeNumber e)
	{
		cout << "Cannot have a negative number of " << e.get_message() << endl;
	}
	catch(DivideByZero)
	{
		cout << "Send for help.\n";
	}
	//catch(...) a good default catch block
	cout << "End of program.\n";
	return 0;
}

NegativeNumber::NegativeNumber()
{
}
NegativeNumber::NegativeNumber(string take_me_to_your_catch_block)
	: message(take_me_to_your_catch_block)
{
}
string NegativeNumber::get_message()
{
	return message;
}

// 16.5 Throwing an Exception Inside a Function
#include <iostream>
#include <cstdlib>
using namespace std;
class DivideByZero
{
};
double safe_divide(int top, int bottom) throw(DivideByZero);

int main()
{
	int numerator;
	int denominator;
	double quotinent;
	cout << "Enter numerator:\n";
	cin >> numerator;
	cout << "Enter denominator:\n";
	cin >> denominator;
	try
	{
		quotinent = safe_divide(numerator,denominator);
	}
	catch(DivideByZero)
	{
		cout <<"Error: Division by zero!\n"
			 <<"Program aborting.\n";
		exit(0);
	}
	cout << numerator << "/" << denominator << "=" << quotinent << endl;
	cout << "End of program.\n";
	return 0;
}

// throw() here is an exception specification, throw list
// if an exception is thrown in a function but not listed, program ends
double safe_divide(int top, int bottom) throw(DivideByZero)
{
	if (bottom==0)
		throw DivideByZero();
	return top/static_cast<double>(bottom);
}

