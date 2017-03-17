// 11.1 Equality Function
#include <iostream>
#include <cstdlib>
using namespace std;

class DayOfYear
{
public:
    DayOfYear(int the_month, int the_day);
    DayOfYear();

    void input();
    void output();
    int get_month();
    int get_day();
private:
    void check_date();
    int month;
    int day;

};

bool equal(DayOfYear date1, DayOfYear date2);

int main()
{
    DayOfYear today, bach_birthday(3,21);
    cout << "Enter today's date:\n";
    today.input();
    cout << "Today's date is ";
    today.output();

    cout << "J.S. Bach's birthday is ";
    bach_birthday.output();
    if (equal(today, bach_birthday))
        cout << "Happy Birthday Johann Sebastian!\n";
    else
        cout << "Happy Unbirthday Johann Sebastian!\n";
    return 0;
}

bool equal(DayOfYear date1, DayOfYear date2)
{
    return (date1.get_month() == date2.get_month() && date1.get_day() == date2.get_day());
}

DayOfYear::DayOfYear(int the_month, int the_day)
    :month(the_month),day(the_day)
{
    check_date();
}

DayOfYear::DayOfYear()
{


}
void DayOfYear::check_date()
{
    if ( (month < 1) || (month > 12) || (day < 1) || (day >31))
    {
        cout << "Illegal date, Aborting program.\n";
        exit(1);
    }
}


int DayOfYear::get_month()
{
    return month;
}

int DayOfYear::get_day()
{
    return day;
}

void DayOfYear::input()
{
    cout<< "Enter the month as a number:";
    cin >> month;
    cout << "Enter the day of the month";
    cin >> day;
}

void DayOfYear::output()
{
    cout << "month = " << month << ", day = " << day << endl;
}

// 11.2 Equality Function as a Friend
#include <iostream>
#include <cstdlib>
using namespace std;

class DayOfYear
{
public:
    // friend function of a class is not a member function
    // just has access to the private members as a member function does(same access privileges)
    // normally is listed in the public section
    // non-member function involves more than one object
    friend bool equal(DayOfYear date1, DayOfYear date2);
    DayOfYear(int the_month, int the_day);
    DayOfYear();

    void input();
    void output();
    int get_month();
    int get_day();
private:
    void check_date();
    int month;
    int day;

};

int main()
{
    DayOfYear today, bach_birthday(3,21);
    cout << "Enter today's date:\n";
    today.input();
    cout << "Today's date is ";
    today.output();

    cout << "J.S. Bach's birthday is ";
    bach_birthday.output();
    if (equal(today, bach_birthday))
        cout << "Happy Birthday Johann Sebastian!\n";
    else
        cout << "Happy Unbirthday Johann Sebastian!\n";
    return 0;
}

bool equal(DayOfYear date1, DayOfYear date2)
{
    // private member variables month and day can be accessed by name
    // no () here, () is for member methods, but for member attributes
    return (date1.month == date2.month && date1.day == date2.day);
}

DayOfYear::DayOfYear(int the_month, int the_day)
    :month(the_month),day(the_day)
{
    check_date();
}

DayOfYear::DayOfYear()
{


}
void DayOfYear::check_date()
{
    if ( (month < 1) || (month > 12) || (day < 1) || (day >31))
    {
        cout << "Illegal date, Aborting program.\n";
        exit(1);
    }
}


int DayOfYear::get_month()
{
    return month;
}

int DayOfYear::get_day()
{
    return day;
}

void DayOfYear::input()
{
    cout<< "Enter the month as a number:";
    cin >> month;
    cout << "Enter the day of the month";
    cin >> day;
}

void DayOfYear::output()
{
    cout << "month = " << month << ", day = " << day << endl;
}

// 11.3 Money Class - Version 1
#include <iostream>
#include <cstdlib>
#include <cctype>

using namespace std;

class Money
{
public:
   friend Money add(Money amount1, Money amount2);
   friend bool equal(Money amout1, Money amount2);
   Money (long dollars, int cents);
   Money(long dollars);
   Money();

   double get_value();
   void input(istream& ins);
   void output(ostream& outs);
private:
    long all_cents;

};

int digit_to_int(char c);

int main()
{
    Money your_amount, my_amount(10,9), our_amount;
    cout << "Enter an amount of money: ";
    your_amount.input(cin);
    cout << "Your amount is ";
    your_amount.output(cout);
    cout << endl;
    cout << "My amount is ";
    my_amount.output(cout);
    cout << endl;

    if (equal(your_amount,my_amount))
        cout << "We have the same amounts.\n";

    else
        cout << "One of us is richer.\n";
    our_amount = add(your_amount, my_amount);
    your_amount.output(cout);
    cout << " + ";
    my_amount.output(cout);
    cout << " equals ";
    our_amount.output(cout);
    cout << endl;
    return 0;
}

Money add(Money amount1, Money amount2)
{
    Money temp;
    temp.all_cents = amount1.all_cents + amount2.all_cents;
    return temp;
}

bool equal(Money amount1, Money amount2)
{
    return (amount1.all_cents == amount2.all_cents);
}

Money::Money(long dollars, int cents)
{
    if (dollars * cents < 0)
    {
        cout << "Illegal values for dollars and cents.\n";
        exit(1);
    }
    all_cents = dollars * 100 + cents;
}
Money::Money(long dollars): all_cents(dollars*100)
{

}

Money::Money():all_cents(0)
{

}

double Money::get_value()
{
    return (all_cents*0.01);
}

void Money::input(istream& ins)
{
    char one_char, decimal_point, digit1, digit2;
    long dollars;
    int cents;
    bool negative;
    ins >> one_char;
    if (one_char == '-')
    {
        negative = true;
        ins >> one_char;
    }
    else
        negative = false;
    ins >> dollars >> decimal_point >> digit1 >> digit2;
    if (one_char != '$' || decimal_point != '.' || !isdigit(digit1) || !isdigit(digit2))
    {
        cout << "Error illegal form for money input.\n";
        exit(1);
    }
    cents = digit_to_int(digit1)*10 + digit_to_int(digit2);

    all_cents = dollars * 100 +cents;
    if (negative)
        all_cents = -all_cents;

}

void Money::output(ostream& outs)
{
    long positive_cents, dollars, cents;
    positive_cents = labs(all_cents);
    dollars = positive_cents / 100;
    cents = positive_cents % 100;
    if (all_cents < 0)
        outs << "-$" << dollars << '.';
    else
        outs << "$" << dollars << '.';
    // if cents only has one digit, add a zero like .90
    if (cents < 10)
        outs << '0';
    outs << cents;
}

int digit_to_int(char c)
{
    return (static_cast<int>(c) - static_cast<int>('0'));
}

//11.4 The Class Money with Constant Parameters

#include <iostream>
#include <cstdlib>
#include <cctype>

using namespace std;

class Money
{
public:
// why use call-by-reference is better? when call-by-value is called, there are two copies
// call-by-reference parameter is just a placeholder and no more copy is created
// better use with const to make sure no chance to the value, error checking 
    friend Money add(const Money& amount1, const Money& amount2);
    friend bool equal(const Money& amount1, const Money& amount2);
    Money(long dollars, int cents);
    Money(long dollars);
    Money();

    double get_value() const;
    void input(istream& ins);
    void output(ostream& outs) const;
private:
    long all_cents;
};

int digit_to_int(char c);

int main()
{
    Money your_amount, my_amount(10,9), our_amount;
    cout << "Enter an amount of money: ";
    your_amount.input(cin);
    cout << "Your amount is ";
    your_amount.output(cout);
    cout << endl;
    cout << "My amount is ";
    my_amount.output(cout);
    cout << endl;

    if (equal(your_amount,my_amount))
        cout << "We have the same amounts.\n";

    else
        cout << "One of us is richer.\n";
    our_amount = add(your_amount, my_amount);
    your_amount.output(cout);
    cout << " + ";
    my_amount.output(cout);
    cout << " equals ";
    our_amount.output(cout);
    cout << endl;
    return 0;
}

Money add(const Money& amount1, const Money& amount2)
{
    Money temp;
    temp.all_cents = amount1.all_cents + amount2.all_cents;
    return temp;
}

bool equal(const Money& amount1, const Money& amount2)
{
    return (amount1.all_cents == amount2.all_cents);
}

Money::Money(long dollars, int cents)
{
    if (dollars * cents < 0)
    {
        cout << "Illegal values for dollars and cents.\n";
        exit(1);
    }
    all_cents = dollars * 100 + cents;
}
Money::Money(long dollars): all_cents(dollars*100)
{

}

Money::Money():all_cents(0)
{

}

double Money::get_value() const
{
    return (all_cents*0.01);
}

void Money::input(istream& ins)
{
    char one_char, decimal_point, digit1, digit2;
    long dollars;
    int cents;
    bool negative;
    ins >> one_char;
    if (one_char == '-')
    {
        negative = true;
        ins >> one_char;
    }
    else
        negative = false;
        ins >> dollars >> decimal_point >> digit1 >> digit2;
    if (one_char != '$' || decimal_point != '.' || !isdigit(digit1) || !isdigit(digit2))
    {
        cout << "Error illegal form for money input.\n";
        exit(1);
    }
    cents = digit_to_int(digit1)*10 + digit_to_int(digit2);

    all_cents = dollars * 100 +cents;
    if (negative)
        all_cents = -all_cents;

}

void Money::output(ostream& outs) const
{
    long positive_cents, dollars, cents;
    positive_cents = labs(all_cents);
    dollars = positive_cents / 100;
    cents = positive_cents % 100;
    if (all_cents < 0)
        outs << "-$" << dollars << '.';
    else
        outs << "$" << dollars << '.';
    // if cents only has one digit, add a zero like .90
    if (cents < 10)
        outs << '0';
    outs << cents;
}

int digit_to_int(char c)
{
    return (static_cast<int>(c) - static_cast<int>('0'));
}

// 11.5 Overloading Operators
#include <iostream>
#include <cstdlib>
#include <cctype>
using namespace std;

class Money
{
public:
    friend Money operator+(const Money& amount1, const Money& amount2);
    friend bool operator == (const Money& amount1, const Money& amount2);
    Money(long dollars, int cents);
    Money(long dollars);
    Money();
    double get_value() const;
    void input(istream& ins);
    void output(ostream& outs)const;
private:
    long all_cents;
};

int digit_to_int(char c);

int main()
{
    Money cost(1,50), tax(0,15),total;
    total = cost + tax;
    cost.output(cout);
    cout << endl;
    tax.output(cout);
    cout << endl;
    cout << "total bill = ";
    total.output(cout);
    cout << endl;
    if (cost == tax)
        cout << "Move to another state.\n";
    else
        cout << "Things are normal.\n";
    return 0;

}

Money operator+(const Money& amount1, const Money& amount2)
{
    Money temp;
    temp.all_cents = amount1.all_cents + amount2.all_cents;
    return temp;
}

bool operator ==(const Money& amount1, const Money& amount2)
{
    return (amount1.all_cents == amount2.all_cents);
}

Money::Money(long dollars, int cents)
{
    if (dollars * cents < 0)
    {
        cout << "Illegal values for dollars and cents.\n";
        exit(1);
    }
    all_cents = dollars * 100 + cents;
}
Money::Money(long dollars): all_cents(dollars*100)
{

}

Money::Money():all_cents(0)
{

}

double Money::get_value() const
{
    return (all_cents*0.01);
}

void Money::input(istream& ins)
{
    char one_char, decimal_point, digit1, digit2;
    long dollars;
    int cents;
    bool negative;
    ins >> one_char;
    if (one_char == '-')
    {
        negative = true;
        ins >> one_char;
    }
    else
        negative = false;
        ins >> dollars >> decimal_point >> digit1 >> digit2;
    if (one_char != '$' || decimal_point != '.' || !isdigit(digit1) || !isdigit(digit2))
    {
        cout << "Error illegal form for money input.\n";
        exit(1);
    }
    cents = digit_to_int(digit1)*10 + digit_to_int(digit2);

    all_cents = dollars * 100 +cents;
    if (negative)
        all_cents = -all_cents;

}

void Money::output(ostream& outs) const
{
    long positive_cents, dollars, cents;
    positive_cents = labs(all_cents);
    dollars = positive_cents / 100;
    cents = positive_cents % 100;
    if (all_cents < 0)
        outs << "-$" << dollars << '.';
    else
        outs << "$" << dollars << '.';
    // if cents only has one digit, add a zero like .90
    if (cents < 10)
        outs << '0';
    outs << cents;
}

int digit_to_int(char c)
{
    return (static_cast<int>(c) - static_cast<int>('0'));
}


// 11.6 Overloading a Unary Operator
#include <iostream>
#include <cstdlib>
#include <cctype>

using namespace std;
class Money
{
public:
    friend Money operator+(const Money& amount1, const Money& amount2);
    friend Money operator-(const Money& amount1, const Money& amount2);
    friend Money operator-(const Money& amount);
    friend bool operator==(const Money& amount1, const Money& amount2);
    Money(long dollars, int cents);
    Money(long dollars);
    Money();
    double get_value() const;
    void input(istream& ins);
    void output(ostream& outs) const;

private:
    long all_cents;
};

int digit_to_int(char c);

int main()
{
    Money cost(1,50), tax(0,15),total;
    total = cost + tax;
    cost.output(cout);
    cout << endl;
    tax.output(cout);
    cout << endl;
    cout << "total bill = ";
    total.output(cout);
    cout << endl;
    if (cost == tax)
        cout << "Move to another state.\n";
    else
        cout << "Things are normal.\n";
    return 0;

}

Money operator-(const Money& amount1, const Money& amount2)
{
    Money temp;
    temp.all_cents = amount1.all_cents - amount2.all_cents;
    return temp;
}
// return the negative value of the object
Money operator-(const Money& amount)
{
    Money temp;
    temp.all_cents = -amount.all_cents;
    return temp;
}

Money operator+(const Money& amount1, const Money& amount2)
{
    Money temp;
    temp.all_cents = amount1.all_cents + amount2.all_cents;
    return temp;
}

bool operator==(const Money& amount1, const Money& amount2)
{
    return (amount1.all_cents == amount2.all_cents);
}

Money::Money(long dollars, int cents)
{
    if (dollars * cents < 0)
    {
        cout << "Illegal values for dollars and cents.\n";
        exit(1);
    }
    all_cents = dollars * 100 + cents;
}
Money::Money(long dollars): all_cents(dollars*100)
{

}

Money::Money():all_cents(0)
{

}

double Money::get_value() const
{
    return (all_cents*0.01);
}

void Money::input(istream& ins)
{
    char one_char, decimal_point, digit1, digit2;
    long dollars;
    int cents;
    bool negative;
    ins >> one_char;
    if (one_char == '-')
    {
        negative = true;
        ins >> one_char;
    }
    else
        negative = false;
        ins >> dollars >> decimal_point >> digit1 >> digit2;
    if (one_char != '$' || decimal_point != '.' || !isdigit(digit1) || !isdigit(digit2))
    {
        cout << "Error illegal form for money input.\n";
        exit(1);
    }
    cents = digit_to_int(digit1)*10 + digit_to_int(digit2);

    all_cents = dollars * 100 +cents;
    if (negative)
        all_cents = -all_cents;

}

void Money::output(ostream& outs) const
{
    long positive_cents, dollars, cents;
    positive_cents = labs(all_cents);
    dollars = positive_cents / 100;
    cents = positive_cents % 100;
    if (all_cents < 0)
        outs << "-$" << dollars << '.';
    else
        outs << "$" << dollars << '.';
    if (cents < 10)
        outs << '0';
    outs << cents;
}

int digit_to_int(char c)
{
    return (static_cast<int>(c) - static_cast<int>('0'));
}


//11.8 Overloading << and >>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cctype>
using namespace std;

class Money
{
public:
    friend Money operator+(const Money& amount1, const Money& amount2);
    friend Money operator-(const Money& amount1, const Money& amount2);
    friend Money operator-(const Money& amount);
    friend bool operator==(const Money& amount1, const Money& amount2);
    Money(long dollars, int cents);
    Money(long dollars);
    Money();
    double get_value() const;
    friend istream& operator>>(istream& ins, Money& amount);
    // note the const in the header, need to put it in the description too!
    friend ostream& operator<<(ostream& outs,const Money& amount);

private:
    long all_cents;
};

int digit_to_int(char c);

int main()
{
    Money amount;
    ifstream in_stream;
    ofstream out_stream;
    in_stream.open("infile.dat");
    if(in_stream.fail())
    {
        cout << "Input file opening failed.\n";
        exit(1);
    }
    out_stream.open("outfile.dat");
    if(out_stream.fail())
    {
        cout << "Output file opening failed.\n";
        exit(1);
    }
    in_stream>>amount;
    out_stream << amount << " copied from the file infile.dat.\n";
    cout << amount << " copied from the file infile.dat.\n";

    in_stream.close();
    out_stream.close();
    return 0;
}

Money operator-(const Money& amount1, const Money& amount2)
{
    Money temp;
    temp.all_cents = amount1.all_cents - amount2.all_cents;
    return temp;
}

Money operator-(const Money& amount)
{
    Money temp;
    temp.all_cents = -amount.all_cents;
    return temp;
}

Money operator+(const Money& amount1, const Money& amount2)
{
    Money temp;
    temp.all_cents = amount1.all_cents + amount2.all_cents;
    return temp;
}

bool operator==(const Money& amount1, const Money& amount2)
{
    return (amount1.all_cents == amount2.all_cents);
}

Money::Money(long dollars, int cents)
{
    if (dollars * cents < 0)
    {
        cout << "Illegal values for dollars and cents.\n";
        exit(1);
    }
    all_cents = dollars * 100 + cents;
}
Money::Money(long dollars): all_cents(dollars*100)
{

}

Money::Money():all_cents(0)
{

}

double Money::get_value() const
{
    return (all_cents*0.01);
}

istream& operator>>(istream& ins, Money& amount)
{
    char one_char, decimal_point,digit1,digit2;
    long dollars;
    int cents;
    bool negative;
    ins >> one_char;
    if (one_char == '-')
    {
        negative = true;
        ins >> one_char;
    }
    else
        negative = false;
    ins >> dollars >> decimal_point >> digit1 >> digit2;
    if(one_char!= '$'||decimal_point!='.'||!isdigit(digit1)||!isdigit(digit2))
    {
        cout << "Error illegal form for money input.\n";
        exit(1);
    }
    cents = digit_to_int(digit1)*10+digit_to_int(digit2);
    amount.all_cents = dollars * 100 + cents;
    if (negative)
    {
        amount.all_cents = -amount.all_cents;
    }
    return ins;
}

int digit_to_int(char c)
{
    return (static_cast<int>(c) - static_cast<int>('0'));
}

ostream& operator<<(ostream& outs, const Money& amount)
{
    long positive_cents, dollars, cents;
    positive_cents = labs(amount.all_cents);
    dollars = positive_cents/100;
    cents = positive_cents%100;
    if(amount.all_cents < 0)
    {
        outs << "-$" << dollars << ".";
    }
    else
        outs << "$" << dollars << ".";
    if (cents <10)
        outs << '0';
    outs<<cents;

    return outs;
}

//array of classes
struct WindInfo
{
    double velocity;
    char direction;
};
WindInfo data_point[10];
int i;
for (i=0;i<10;i++)
{
    cout << "Enter velocity for " << i << " number data point";
    cin >> data_point[i].velocity;
    cout << "Enter direction for that data point" << "(N,S,E,or W):";
    cin >> data_point[i].direction;
}

//11.9 Program Using an Array of Money Obejcts
#include <iostream>
#include <cstdlib>
using namespace std;
class Money
{
public:
    friend Money operator+(const Money &amount1,const Money &amount2);
    friend Money operator-(const Money &amoutn1,const Money &amount2);
    friend Money operator-(const Money& amount);
    friend bool operator==(const Money &amount1, const Money &amount2);
    friend bool operator <(const Money &amount1,const Money &amount2);
    Money(long dollars, int cents);
    Money(long dollars);
    Money();
    double get_value()const;
    friend istream& operator>>(istream& ins,Money &amount);
    friend ostream& operator<<(ostream& outs, const Money &amount);
private:
    long all_cents;
};
int digit_to_int(char c);

int main()
{
    Money amount[5], max;
    int i;
    cout << "Enter 5 amounts of money:\n";
    cin >> amount[0];
    max = amount[0];
    for (i=1;i<5;i++)
    {
        cin >> amount[i];
        if (max < amount[i])
        {
            max = amount[i];
        }
    }
    Money different[5];
    for (i=0;i<5;i++)
    {
        different[i] = max - amount[i];
    }
    cout << "The highest amount is " << max << endl;
    cout << "The amounts and their\n" << "differences from the largest are: \n";
    for(i=0;i<5;i++)
    {
        cout << amount[i] << " off by " << different[i] << endl;
    }
    return 0;
}

Money operator-(const Money& amount1, const Money& amount2)
{
    Money temp;
    temp.all_cents = amount1.all_cents - amount2.all_cents;
    return temp;
}

Money operator-(const Money& amount)
{
    Money temp;
    temp.all_cents = -amount.all_cents;
    return temp;
}

Money operator+(const Money& amount1, const Money& amount2)
{
    Money temp;
    temp.all_cents = amount1.all_cents + amount2.all_cents;
    return temp;
}
bool operator <(const Money &amount1,const Money &amount2)
{
    return (amount1.all_cents < amount2.all_cents);
}

bool operator==(const Money& amount1, const Money& amount2)
{
    return (amount1.all_cents == amount2.all_cents);
}

Money::Money(long dollars, int cents)
{
    if (dollars * cents < 0)
    {
        cout << "Illegal values for dollars and cents.\n";
        exit(1);
    }
    all_cents = dollars * 100 + cents;
}
Money::Money(long dollars): all_cents(dollars*100)
{

}

Money::Money():all_cents(0)
{

}

double Money::get_value() const
{
    return (all_cents*0.01);
}

istream& operator>>(istream& ins, Money& amount)
{
    char one_char, decimal_point,digit1,digit2;
    long dollars;
    int cents;
    bool negative;
    ins >> one_char;
    if (one_char == '-')
    {
        negative = true;
        ins >> one_char;
    }
    else
        negative = false;
    ins >> dollars >> decimal_point >> digit1 >> digit2;
    if(one_char!= '$'||decimal_point!='.'||!isdigit(digit1)||!isdigit(digit2))
    {
        cout << "Error illegal form for money input.\n";
        exit(1);
    }
    cents = digit_to_int(digit1)*10+digit_to_int(digit2);
    amount.all_cents = dollars * 100 + cents;
    if (negative)
    {
        amount.all_cents = -amount.all_cents;
    }
    return ins;
}

int digit_to_int(char c)
{
    return (static_cast<int>(c) - static_cast<int>('0'));
}

ostream& operator<<(ostream& outs, const Money& amount)
{
    long positive_cents, dollars, cents;
    positive_cents = labs(amount.all_cents);
    dollars = positive_cents/100;
    cents = positive_cents%100;
    if(amount.all_cents < 0)
    {
        outs << "-$" << dollars << ".";
    }
    else
        outs << "$" << dollars << ".";
    if (cents <10)
        outs << '0';
    outs<<cents;

    return outs;
}

//11.10 Program for a Class with an Array Member
#include <iostream>
#include <cstdlib>
using namespace std;
const int MAX_LIST_SIZE = 50;

class TemperatureList
{
public:
    TemperatureList();
    void add_temperature(double temperature);
    bool full()const;
    friend ostream& operator<<(ostream& outs, const TemperatureList &the_object);
private:
    double list[MAX_LIST_SIZE];
    int size;
};

TemperatureList::TemperatureList() :size(0)
{

}
void TemperatureList::add_temperature(double temperature)
{
    if(full())
    {
        cout << "Error: adding to a full list.\n";
        exit(1);
    }
    else
    {
        list[size] = temperature;
        size = size + 1;
    }

}

bool TemperatureList::full() const
{
    return (size == MAX_LIST_SIZE);
}

ostream& operator<<(ostream& outs, const TemperatureList &the_object)
{
    for (int i=0;i<the_object.size;i++)
    {
        outs << the_object.list[i] << "F\n";
    }
    return outs;
}

// 11.11 Program Using the StringVar Class
// 11.12 Inplementation of StringVar
#include <iostream>
#include <cstdlib>
#include <cstddef>
#include <cstring>

using namespace std;
class StringVar
{
public:
    StringVar(int size);
    StringVar();
    StringVar(const char a[]);
    // below is the copy constructor
    // Classes do not involve pointers or dynamically allocated memory do not need a copy constructor
    //copy constructor, =operator and destructor are big three, need one you will need all of three
    StringVar(const StringVar& string_object);
    ~StringVar();
    int length()const;
    void input_line(istream& ins);
    friend ostream& operator<<(ostream& outs, const StringVar& the_string);
private:
    // pointer to dynamic array that holds the string value
    char* value;
    int max_length;
};

void conversation(int max_name_size);
void show_string(StringVar the_string);

int main()
{
    using namespace std;
    conversation(30);
    cout << "End of demonstration.\n";
    // demonstrated three ways of initialization
    // 1. line with constructor(int size)
    // 2. motto with constructor(const char a[])
    // 3. temp with copy constructor (const StringVar&)
    // any change made to temp has no effect on line
    StringVar line(20), motto("Constructors can help.");
    cout << "Enter a string of length 20 or less:\n";
    line.input_line(cin);
    StringVar temp(line);
    cout << line << motto << temp;
    StringVar greeting("Hello");
    // after the call of show_string, delete [] the_string.value will executed
    // without a copy constructor, greeting.value will be undefined
    show_string(greeting);
    cout << "After call " << greeting << endl;

    return 0;
}

StringVar::StringVar(int size) :max_length(size)
{
    // 1 is for '\0'
    value = new char[max_length+1];
    // because now value is an empty array
    value[0]='\0';
}

// :max_length(100) is an initialization list, faster than assignment
// just like max_length = 100;
/* member initialization
Foo(int num):bar(num)
{}
member assignment
Foo(int num)
{bar = num;}
*/
StringVar::StringVar() :max_length(100)
{

}

/*remember array is a pointer that points to the first indexed variable of the array
int a[10];
typedef int* IntPtr;
IntPtr p;
// a can be assigned to p
p=a;
*/

StringVar::StringVar(const char a[]) :max_length(strlen(a))
{
    value = new char[max_length+1];
    strcpy(value,a);
}

StringVar::StringVar(const StringVar& string_object) :max_length(string_object.length())
{
    value = new char[max_length+1];
    strcpy(value,string_object.value);
}

// a destructor is called automatically when an object goes out of scope
StringVar::~StringVar()
{
    delete [] value;
}

StringVar::length() const
{
    return strlen(value);
}

void StringVar::input_line(istream& ins)
{
    ins.getline(value, max_length+1);
}

ostream& operator<<(ostream& outs, const StringVar& the_string)
{
    outs << the_string.value;
    return outs;
}

void conversation(int max_name_size)
{
    using namespace std;
    StringVar your_name(max_name_size), our_name("Borg");
    cout << "What is your name?\n";
    your_name.input_line(cin);
    cout << "We are " << our_name << endl;
    cout << "We will meet again " << your_name << endl;
}

void show_string(StringVar the_string)
{
    cout << "The string is " << the_string << endl;
}

// 11.13 A Cally-by-Value Pointer Parameter
#include <iostream>
using namespace std;
typedef int *IntPointer;
void sneaky(IntPointer temp);

int main()
{
    IntPointer p;
    p = new int;
    *p = 77;
    // 77
    cout << "Before call to funciton *p == " << *p << endl;
    // 99
    sneaky(p);
    // 99
    cout << "After call to funciton *p == " << *p << endl;
    return 0;
}

/* sneaky is a call-by-value function, how come it changed p's value?
 or did it?
 it didn't. P has two things associated with it: 
 1.p's pointer value, which is the address
 2.the value stored where p points 
 function chanced 2 the value of the variable pointed to by p
 but didn't change the value of p itself*/

void sneaky(IntPointer temp){
    *temp = 99;
    cout << "Inside function call *temp == " << *temp << endl;
}

// overloading assignment operator
// !! overloading the assignment operator has to be a member of the class, can't be a friend of the class
class StringVar
{
    public:
    void operator=(const StringVar& right_side);
}

void StringVar::operator=(const StringVar& right_side)
{
    int new_length = strlen(right_side.value);
    if ((new_length>max_length))
    {
        // delete the array only if extra space is needed
        delete []value;
        max_length = new_length;
        value = new char[max_length+1];
    }
    for (int i=0;i<new_length;i++)
    {
        value[i] = right_side.value[i];
    }
    value[new_length] = '\0';
}
