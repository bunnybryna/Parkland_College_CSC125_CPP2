#include "person.h"

Person::Person()
{
    //ctor
    m_Name = "unknown";
    m_Address1 = "unknown";
    m_Address2 = "unknown";
    m_City = "unknown";
    m_State = "unknown";
    m_Zipcode = "unknown";
}

string Person::toString()
{

    return m_Name + "\n" + m_Address1 + "\n" + m_Address2 + " \n" +  m_City + ", " + m_State + " " + m_Zipcode + " \n";
}
