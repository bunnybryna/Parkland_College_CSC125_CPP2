// 15.1 Interface for the Base Class Employee
#ifndef EMPLOYEE_H
#defind EMPLOYEE_H

#include <string>
using namespace std;
namespace employeesavitch
{
	class Employee
	{
	  public:
		Employee();
		Employee(string the_name, string the_ssn);
		string get_name() const;
		string get_ssn() const;
		double get_net_pay() const;
		void set_name(string new_name);
		void set_ssn(string new_ssn);
		void set_net_pay(double new_net_pay);
		void print_check() const;
	  private:
	    string name;
		string ssn;
		double net_pay;
	};
}
#endif

// 15.2 Implementation for the Base Class Employee
#include <string>
#include <cstdlib>
#include <iostream>
#include "employee.h"
using namespace std;
namespace employeesavitch
{
	Employee::Employee() : name("No name yet"), ssn("No number yet"), net_pay(0)
	{
	}

	Employee::Employee(string the_name, string the_number) : name(the_name),ssn(the_number), net_pay(0)
	{
	}

	string Employee::get_name() const
	{
		return name;
	}

	string Employee::get_ssn() const
	{
		return ssn;
	}

	double Employee::get_net_pay() const
	{
		return net_pay;
	}

	void Employee::set_name(string new_name)
	{
		name = new_name;
	}

	void Employee::set_ssn(string new_ssn)
	{
		ssn = new_ssn;
	}

	void Employee::set_net_pay(double new_net_pay)
	{
		net_pay = new_net_pay;
	}

	void Employee::print_check() const
	{
		cout << "\nERROR: print_check FUNCTION CALLED FOR AN \n"
			 << "UNDIFFERENTIATED EMPLOYEE. Aborting the program.\n"
			 << "Check with the anthor of the program about this bug.\n";
		exit(1);
	}
}
// 15.3 Interface for the Derived Class HourlyEmployee
#ifndef HOURLYEMPLOYEE_H
#define HOURLYEMPLOYEE_H

#include <string>
#include "employee.h"

using namespace std;
namespace employeesavitch
{
	class HourlyEmployee : public Employee
	{
	  public:
		HourlyEmployee();
		HourlyEmployee(string the_name, string the_ssn, double the_wage_rate, double the_hours);
		void set_rate(double new_wage_rate);
		double get_rate()const;
		void set_hours(double hours_worked);
		double get_hours() const;
		// only give declarations of inherited member functions you want to change		
		// it's called redefining
		void print_check();
	  private:
		double wage_rate;
		double hours;
	};
}

#endif

//15.4 Interface for the Derived Class SalariedEmployee
#ifndef SALARIEDEMPLOYEE_H
#defind SALARIEDEMPLOYEE_H
#include <string>
#include "employee.h"

using namespace std;

namespace employeesavitch
{
	class SalariedEmployee : public Employee
	{
	  public:
	    SalariedEmployee();
		SalariedEmployee(string the_name, string the_ssn, double the_weekly_salary);
		double get_salary()const;
		void set_salary(double new_salary);
		void print_check();
	  private:
		double salary;
	};
}
#endif	
	
#include <string>
#include <iostream>
#include "hourlyemployee.h"
using namespace std;

namespace employeesavitch
{
    HourlyEmployee::HourlyEmployee() : Employee(), wage_rate(0),hours(0)
	{

	}
    // constructors are not automatically inherited
	// Employee(the_name,the_number) invokes the base class constructor
	// and the wage_rate sets the value of the_wage_rate
	// you should always include an invocation of the base class constructor
	// in the initialization section of a derived class constructor
	HourlyEmployee::HourlyEmployee(string the_name, string the_number, double the_wage_rate, double the_hours)
	: Employee(the_name, the_number), wage_rate(the_wage_rate), hours(the_hours)
	{

	}

	void HourlyEmployee::set_rate(double new_wage_rate)
	{
		wage_rate = new_wage_rate;
	}

	double HourlyEmployee::get_rate() const
	{
		return wage_rate;
	}

	void HourlyEmployee::set_hours(double hours_worked)
	{
		hours = hours_worked;
	}

	double HourlyEmployee::get_hours() const
	{
		return hours;
	}

	void HourlyEmployee::print_check()
	{
		//net_pay = hours * wage_rate is illegal
		// because net_pay, ssn, name are private variables of the base class
		// can't be directly accessed by the derived class 
		// can only accessed by some public member function 
		set_net_pay(hours * wage_rate);
		cout << "\n----------------------------------------------\n";
		cout << "Pay to the order of "<< get_name() << endl;
		cout << "The sum of "<<get_net_pay() << " Dollars\n";
		cout << "\n----------------------------------------------\n";
		cout << "Check stub: NOT NEGOTIABLE\n";
		cout << "Employee Number: " << get_ssn() << endl;
		cout << "Hourly Employee.\nHours worked: "<< hours
		     << "Rate: " << wage_rate << "Pay: " << get_net_pay() << endl;
		cout << "\n----------------------------------------------\n";
	}
}	

// if net_pay is set protected instead of private
// then it can be accessed by name in a derived class
	void HourlyEmployee::print_check()
	{
		net_pay = hours * wage_rate;
		cout << "\n----------------------------------------------\n";
		cout << "Pay to the order of "<< name << endl;
		cout << "The sum of "<< net_pay << " Dollars\n";
		cout << "\n----------------------------------------------\n";
		cout << "Check stub: NOT NEGOTIABLE\n";
		cout << "Employee Number: " << ssn << endl;
		cout << "Hourly Employee.\nHours worked: "<< hours
		     << "Rate: " << wage_rate << "Pay: " << net_pay << endl;
		cout << "\n----------------------------------------------\n";
	}

// 15.6 Implementation for the Derived Class SalariedEmployee
#include <string>
#include <iostream>
#include "saleriedemployee.h"
using namespace std;

namespace employeesavitch
{
	SalariedEmployee::SalariedEmployee() : Employee(), salary(0)
	{

	}
	SalariedEmployee::SalariedEmployee(string the_name, string the_number, double the_weekly_salary)
	: Employee(the_name, the_number), salary(the_weekly_salary)
	{

	}
	double SalariedEmployee::get_salary() const
	{
		return salary;
	}
	void SalariedEmployee::set_salary(double new_salary)
	{
		salary = new_salary;
	}

	void SalariedEmployee::print_check()
	{
		set_net_pay(salary);
		cout << "\n----------------------------------------------\n";
		cout << "Pay to the order of "<< get_name() << endl;
		cout << "The sum of "<<get_net_pay() << " Dollars\n";
		cout << "\n----------------------------------------------\n";
		cout << "Check stub: NOT NEGOTIABLE\n";
		cout << "Employee Number: " << get_ssn() << endl;
		cout << "Salaried Employee.Regular Pay: "<< salary << endl;
		cout << "\n----------------------------------------------\n";
	}
}

// 15.7 Using Derived Class
#include <iostream>
#include "saleriedemployee.h"
#include "hourlyemployee.h"
using std::cout;
using std::endl;
using namespace employeesavitch;

int main()
{
	HourlyEmployee joe;
	joe.set_name("Mighty Joe");
	joe.set_ssn("123-45-6789");
	joe.set_rate(20.50);
	joe.set_hours(40);
	cout << "Check for " << joe.get_name() << " for " << joe.get_hours() << " hours.\n"'
	joe.print_check();
	cout << endl;
	
	SalariedEmployee boss("Mr Big Shot", "987-65-4321", 10500.50);
	cout << "Check for " << boss.get_name << endl;
	boss.print_check();
	
	return 0;
}

// constructors, assign operators, and destructors are not inherited
// if you don't define a copy constructor in a derived class, C++ will generate a default one
// but it won't work correctly for classes with pointers
Derived& Derived::operator=(const Derived& right_side)
{
	Base::operator=(right_side);
}

Derived::Derived(const Derived& object) : Base(obkect),<more initializations>

// Polymorphism
// 15.8 Interface for the Base Class Sale

#ifndef SALE_H
#define SALE_H
#include <iostream>
using namespace std;

namespace salesavitch
{
	class Sale
	{
	public:
		Sale();
		Sale(double the_price);
		virtual double bill() const;
		double savings(const Sale& other) const;
	protected:
		double price;
	};
	
	bool operator<(const Sale& first, const Sale& second);
}
#endif

// 15.9 Implementation of the Base Class Sale
#include "sale.h"
namespace salesavitch
{
	Sale::Sale() : price(0)
	{
	}
	Sale::Sale(double the_price) : price(the_price)
	{
	}
	double Sale::bill() const
	{
		return price;
	}
	double Sale::savings(const Sale& other) const
	{
		return (bill() - other.bill());
	}
	bool operator<(const Sale& first, const Sale& second)
	{
		return(first.bill()<second.bill());
	}
}


// 15.10 The Derived Class DiscountSale
#ifndef DISCOUNTSALE_H
#define DISCOUNTSALE_H
#include "sale.h"

namespace salesavitch
{
	class DiscountSale : public Sale
	{
	public:
		DiscountSale();
		DiscountSale(double the_price, double the_discount);
		virtual double bill() const;
	protected:
		double discount;
	};
}
#endif 

#include "discountsale.h"
namespace salesavitch
{
	DiscountSale::DiscountSale() : Sale(),discount(0)
	{
	}
	DiscountSale::DiscountSale(double the_price, double the_discount) : Sale(the_price), discount(the_discount)
	{
	}
	double DiscountSale::bill() const
	{
		double fraction = discount/100;
		return (1-fraction)*price;
	}
}

// 15.11 Use of a Virtual Function
#include <iostream>
#include "sale.h"
#include "discountsale.h"

using namespace std;
using namespace salesavitch;

int main()
{
	Sale simple(10.00);
	DiscountSale discount(11.00, 10);
	
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);
	if (discount < simple)
	{
		cout << "Discounted item is cheaper.\n";
		cout << "Savings is $" << simple.savings(discount)<<endl;
	}
	else
		cout << "Discounted item is not cheaper.\n";
	return 0;
}

// together

#include <iostream>
namespace salesavitch
{
	class Sale
	{
	public:
		Sale();
		Sale(double the_price);
		virtual double bill() const;
		double savings(const Sale& other) const;
	protected:
		double price;
	};

	bool operator<(const Sale& first, const Sale& second);
}
namespace salesavitch
{
	class DiscountSale : public Sale
	{
	public:
		DiscountSale();
		DiscountSale(double the_price, double the_discount);
		//virtual tells compiler to use the version of the function bill that 
		// corresponds to the object of the derived class
		// late binding, dynamic binding
		// add virtual to declaration not definition 
		virtual double bill() const;
	protected:
		double discount;
	};
}


using namespace std;
using namespace salesavitch;



int main()
{
	Sale simple(10.00);
	DiscountSale discount(11.00, 10);

	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);
	if (discount < simple)
	{
		cout << "Discounted item is cheaper.\n";
		cout << "Savings is $" << simple.savings(discount)<<endl;
	}
	else
		cout << "Discounted item is not cheaper.\n";
	return 0;
}






namespace salesavitch
{
	Sale::Sale() : price(0)
	{
	}
	Sale::Sale(double the_price) : price(the_price)
	{
	}
	double Sale::bill() const
	{
		return price;
	}
	double Sale::savings(const Sale& other) const
	{
		return (bill() - other.bill());
	}
	bool operator<(const Sale& first, const Sale& second)
	{
		return(first.bill()<second.bill());
	}
}

namespace salesavitch
{
	DiscountSale::DiscountSale() : Sale(),discount(0)
	{
	}
	DiscountSale::DiscountSale(double the_price, double the_discount) : Sale(the_price), discount(the_discount)
	{
	}
	double DiscountSale::bill() const
	{
		double fraction = discount/100;
		return (1-fraction)*price;
	}
}


/* overriding vs redefining
when a virtual function is changed in the derived class=> overriding
if a funciton is not virtual, it's called redefining*/

// it's allowed, but cause a slicing problem
//derived object=> base object
Dog vdog;
Pet vpet;
vdog.name = "Tiny";
vdog.breed = "Great Dane";
vpet = vdog;
vpet.breed; // Illegal

// solve this problem by using pointer
Pet *ppet;
Dog *pdog;
pdog = new Dog;
pdog->name = "Tiny";
pdog->breed = "Great Dane";
ppet = pdog;

// 15.12 More inheritance with Virtual Functions
#include <string>
#include <iostream>

using namespace std;
class Pet
{
	public:
		virtual void print();
		string name;
};

class Dog : public Pet
{
	public:
		virtual void print();
		string breed;
};

int main()
{
	
	Dog vdog;
	Pet vpet;
	vdog.name = "Tiny";
	vdog.breed = "Great Dane";
	vpet = vdog;
	vpet.breed; // Illegal	
	
	Pet *ppet;
	Dog *pdog;
	pdog = new Dog;
	pdog->name = "Tiny";
	pdog->breed = "Great Dane";
	ppet = pdog;
	ppet->print();
	pdog->print();
	return 0;
}

void Dog::print()
{
	cout << "Name: " << name << endl;
	cout << "Breed: " << breed << endl;
}

void Pet::print()
{
	cout << "Name: " << endl;
}

// make destructors virtual
Base *pBase = new Derived;
delet pBase;
// it will only invoke the base destructors, leave some memory unfreed 