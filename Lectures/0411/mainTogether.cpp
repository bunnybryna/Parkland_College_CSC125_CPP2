//http://www.csit.parkland.edu/~kurban/csc125_archive/2016_Fall/EmployeeInheritance/employee.h

#include <iostream>
#include <vector>

using namespace std;


class Employee
{
    public:
        Employee();
        Employee(string first, string last);
        void setFirstName(string data) {m_FirstName=data;}
        void setLastName(string data) {m_LastName=data;}
        string getFullName() {return (m_FirstName + " " + m_LastName);}
		// void print();
		// once a method is virtual in a base class
		// it remains virtual in all derived class whether or not the keyword is there
		// use void print(), base class print() will always be called
		// use void virtual print(), it will start from derived class 
        void virtual print();
		// void virtual fun()=0 is a 'pure' virtual function
        void virtual fun()=0;
		// void fun();

    protected:
    private:
        string m_FirstName;
        string m_LastName;
};

class FullTimeEmployee : public Employee
{
    public:
        FullTimeEmployee();
        FullTimeEmployee(string first, string last);

        string getOffice() {return m_Office;}
        void setOffice(string data) {m_Office = data;}

        void print();



    protected:
    private:
        string m_Office;
};



class PartTimeEmployee : public Employee
{
    public:
        PartTimeEmployee();
        void print();
        void fun() {cout << "PartTime" << endl;};

    protected:
    private:
};


class HourlyEmployee : public FullTimeEmployee
{
    public:
        HourlyEmployee();
        double GetHourlyRate() { return m_HourlyRate; }
        void SetHourlyRate(double val) { m_HourlyRate = val; }
        void print();
        void fun() {cout << "Hourly" << endl;};

    protected:
    private:
        double m_HourlyRate;
};

class SalariedEmployee : public FullTimeEmployee
{
    public:
        SalariedEmployee();
        double GetYearlySalary() { return m_YearlySalary; }
        void SetYearlySalary(double val) { m_YearlySalary = val; }
        void print();
        void fun() {cout << "Salaried" << endl;};


    protected:
    private:
        double m_YearlySalary;
};


class Intern : public PartTimeEmployee
{
    public:
        Intern();
        // if Employee::fun()=0
        // void fun(); won't work, since fun()=0 is a pure virtual function
		// pure virtual functions need to be in every derived class that will be instantiated 
		// void fun();
        void fun(){};

    protected:
    private:
};

class Consultant : public PartTimeEmployee
{
    public:
        Consultant();
        void print();
        void fun() {cout << "Consultant" << endl;};



    protected:
    private:
};

int main()
{

	SalariedEmployee emp1;
	emp1.setFirstName("Ken");
	emp1.setLastName("Urban");
	cout << emp1.getFullName()<< endl;
	emp1.print();
	// emp2 won't be created because pure virtual function fun() isn't in the class
	/*FullTimeEmployee emp2;
	emp2.setFirstName("Ken");
	emp2.setLastName("Urban");
	cout << emp2.getFullName()<<endl;
	emp2.print();*/

	Employee* empPtr1;
	empPtr1 = new SalariedEmployee();
	empPtr1->print();
	vector<Employee*> staff;
	staff.push_back(new SalariedEmployee());
	staff.push_back(new HourlyEmployee());
	staff.push_back(new SalariedEmployee());
	staff.push_back(new HourlyEmployee());
	staff.push_back(new HourlyEmployee());
	staff.push_back(new HourlyEmployee());
	staff.push_back(new SalariedEmployee());
	staff.push_back(new Intern());
	// virtual means decide at runtime
	// without virtual, print() treat everyone as Employee object
	// polymorphism
    for (int i=0;i<staff.size();i++)
    {

        staff[i]->print();
    }
    cout << "Testing fun " << endl;
    for (int i=0;i<staff.size();i++)
    {
        cout << "=======================================" << endl;
        staff[i]->fun();
    }	

}


Employee::Employee()
{
    //ctor
}

Employee::Employee(string first, string last)
{
    //ctor
    m_FirstName = first;
    m_LastName = last;
}


void Employee::print()
{
    cout << "Employee" << endl;
    cout << "\tFirst Name: " << m_FirstName << endl;
    cout << "\tLast Name: " << m_LastName << endl;
}

FullTimeEmployee::FullTimeEmployee()
{
    //ctor
}

FullTimeEmployee::FullTimeEmployee(string first, string last)
: Employee(first, last)
{
    //ctor
}


void FullTimeEmployee::print()
{
    cout << "FullTimeEmployee:" << endl;
    cout << "\tOffice: " << m_Office << endl;
    Employee::print();
}

PartTimeEmployee::PartTimeEmployee()
{
    //ctor
}

void PartTimeEmployee::print()
{
    cout << "PartTimeEmployee:" << endl;

    Employee::print();
}

HourlyEmployee::HourlyEmployee()
{
    //ctor
}

void HourlyEmployee::print()
{
    cout << "HourlyEmployee:" << endl;

    FullTimeEmployee::print();
}

SalariedEmployee::SalariedEmployee()
{
    //ctor
}

void SalariedEmployee::print()
{
    cout << "SalariedEmployee:" << endl;

    FullTimeEmployee::print();
}

Intern::Intern()
{
    //ctor
}


Consultant::Consultant()
{
    //ctor
}

void Consultant::print()
{
    cout << "Consultant:" << endl;

    PartTimeEmployee::print();
}
