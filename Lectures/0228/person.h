#ifndef PERSON_H
#define PERSON_H

// doesn't have to include <iostream> until you need it
#include <string>


using namespace std;

class Person
{
    public:
        Person();
// for in-line function, if it can fit in one line
        string GetName() { return m_Name; }
        void SetName(string val) { m_Name = val; }
        string GetAddress1() { return m_Address1; }
        void SetAddress1(string val) { m_Address1 = val; }
        string GetAddress2() { return m_Address2; }
        void SetAddress2(string val) { m_Address2 = val; }
        string GetCity() { return m_City; }
        void SetCity(string val) { m_City = val; }
        string GetState() { return m_State; }
        void SetState(string val) { m_State = val; }
        string GetZipcode() { return m_Zipcode; }
        void SetZipcode(string val) { m_Zipcode = val; }
        string toString();

    protected:

    private:
        string m_Name;
        string m_Address1;
        string m_Address2;
        string m_City;
        string m_State;
        string m_Zipcode;
};

#endif // PERSON_H
