#ifndef _NAMEVALUEPAIR_H_
#define _NAMEVALUEPAIR_H_

#include <string>

using namespace std;

class NameValuePair
{
    public:
    //getters
    string getName();
    string getValue();
    string getID();

    //setters
    void setName(string data);
    void setValue(string data);

    private:
    string m_Name;
    string m_Value;
};
#endif
