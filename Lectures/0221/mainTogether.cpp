#include <iostream>
#include <vector>
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

class HTMLForm
{
    public:
    void debug();
    HTMLForm();

    private:
    vector<NameValuePair> m_FormData;
    string m_QueryString;
};


int main()
{
    HTMLForm sentence;
    cout << "Content-type:text/html"<< endl << endl;

    cout << "Started by the form"<< endl;
    sentence.debug();

    return 0;
}

string NameValuePair::getName()
{
    return m_Name;
}
string NameValuePair::getValue()
{
    return m_Value;
}

void NameValuePair::setName(string data)
{
    m_Name = data;
}

void NameValuePair::setValue(string data)
{
    m_Value = data;
}


void HTMLForm::debug()
{
    cout << "so far so good."<< endl;
    cout << m_QueryString << endl;
}
HTMLForm::HTMLForm()
{
    //cout << "called the constructor"<<endl;
    getline(cin,m_QueryString);
}
