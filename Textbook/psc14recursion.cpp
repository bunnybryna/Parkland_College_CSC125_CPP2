// 14.1 A Recursive Output Function
#include <iostream>
using namespace std;

void write_vertical(int n);

int main()
{
	cout << "write_vertical(3)"<<endl;
	write_vertical(3);

	cout << "write_vertical(12)"<<endl;
	write_vertical(12);
	cout << "write_vertical(123)"<<endl;
	write_vertical(123);

	return 0;
}

void write_vertical(int n)
{
	// base case 
	if (n<10)
	{
		cout << n << endl;
	}
	// smaller version of the task
	else
	{
		write_vertical(n/10);
		cout << (n%10) << endl;
	}
}


// 14.2 Iterartive Version of the Function in 14.1
void write_vertical (int n)
{
	int tens_in_n = 1;
	int left_end_piece = n;
	while(left_end_piece >9)
	{
		left_end_piece = left_end_piece/10;
		tens_in_n = tens_in_n * 10;
	}
	for (int power_of_10 = tens_in_n; power_of_10 > 0; power_of_10 = power_of_10/10)
	{
		cout << (n/power_of_10) << endl;
		n = n%power_of_10;
	}
}	

// 14.3 the Recursive Function Power
#include <iostream>
#include <cstdlib>
using namespace std;

int power(int x, int n);

int main()
{
	for (int n=0;n<4;n++)
	{
		cout << "3 to the power " << n << " is " << power(3,n) << endl;
	}
	return 0;
}

int power(int x, int n)
{
	if(n<0)
	{
		cout << "Illegal argument to power.\n";
		exit(1);
	}
	if(n>0)
		return (power(x,n-1)*x);
	// n == 0
	else
		return 1;
}

// 14.6 Recursive Function for Binary Search
#include <iostream>
using namespace std;
const int ARRAY_SIZE = 10;

void search(const int a[], int first, int last, int key, bool &found, int &location);

int main()
{
	int a[ARRAY_SIZE];
	const int final_index = ARRAY_SIZE - 1;
	// 15 20 35 41 57 63 75 80 85 90
    cout << "Enter " << ARRAY_SIZE << " numbers:\n";
    for (int i=0; i< ARRAY_SIZE; i++)
        cin >> a[i];
	int key, location;
	bool found;
	cout << "Enter number to be located: ";
	cin >> key;
	search(a,0,final_index, key, found, location);
	if (found)
		cout << key << " is in index location " << location << endl;
	else
		cout << key << " is not in the array" << endl;
	return 0;
}

void search(const int a[],int first, int last, int key, bool &found, int &location)
{
	int mid;
	if(first > last)
	{
		found = false;
	}
	else
	{
		mid = (first+last)/2;
		if (key == a[mid])
		{
			found = true;
			location = mid;
		}
		else if(key < a[mid])
		{
			search(a, first, mid-1, key, found, location);
		}
		else if(key > a[mid])
		{
			search(a, mid+1, last, key, found, location);
		}
	}
}

// 14.8 Iterartive Version of Binary Search
void search(const int a[], int low_end, int high_end, int key, bool &found, int &location);

void search(const int a[], int low_end, int high_end, int key, bool &found, int &location)
{
	int first = low_end;
	int last = high_end;
	int mid;
	found = false;
	while ((first <= last) && !(found))
	{
		mid = (first + last)/2;
		if(key == a[mid])
		{
			found = true;
			location = mid;
		}
		else if (key < a[mid])
		{
			last = mid-1;
		}
		else if (key > a[mid])
		{
			first = mid+1;
		}
	}
}

// 14.9 A Recursive Member Function
#include <iostream>
#include <cstdlib>
using namespace std;
class BankAccount
{
	public:
	BankAccount(int dollars, int cents, double rate);
	BankAccount(int dollars, double rate);
	BankAccount();
	void update();
	void update(int years);
	double get_balance();
	double get_rate();
	void output(ostream& outs);
	private:
	double balance;
	double interest_rate;
	double fraction(double percent);
};
int main()
{
	BankAccount your_account(100,5);
	your_account.update(10);
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);
	cout << "If you deposit $100 at 5% interest, then\n"
		 << "in ten years your account will be worth $"
		 << your_account.get_balance() << endl;
	return 0;
}

BankAccount::BankAccount(int dollars, int cents, double rate)
{
    if ((dollars < 0) || (cents < 0) || (rate < 0))
    {
        cout << "Illegal values for money or interests rate.\n";
        exit(1);
    }
    balance = dollars + 0.01*cents;
    interest_rate = rate;
}
// it will be equivalent to following
// BankAccount::BankAccount(int dollars, double rate): balance(dollars), interest_rate(rate)
// { if... }
BankAccount::BankAccount(int dollars, double rate)
{
    if ((dollars < 0) || (rate < 0))
    {
        cout << "Illegal values for money or interests rae.\n";
        exit(1);
    }
    balance = dollars;
    interest_rate = rate;
}

BankAccount::BankAccount():balance(0), interest_rate(0.0)
{
    //body intentionally empty
}


double BankAccount::fraction(double percent_value)
{
    return (percent_value/100.0);
}

void BankAccount::update()
{
	balance = balance + fraction(interest_rate)*balance;
}

void BankAccount::update(int years)
{
	if(years == 1)
	{
		// this is not
		update();
	}
	else if (years >1)
	{
		// only this one is recursion
		// only the call to the version of update with exact same function declaration is recursive
		update(years-1);
		// this is not
		update();
	}
}

double BankAccount::get_balance()
{
    return balance;
}

double BankAccount::get_rate()
{
    return interest_rate;
}
void BankAccount::output(ostream &outs)
{
    outs.setf(ios::fixed);
    outs.setf(ios::showpoint);
    outs.precision(2);
    outs << "Account balance $" << balance << endl;
    outs << "Interest rate " << interest_rate << "%" << endl;
}

