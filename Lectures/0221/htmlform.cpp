#include <iostream>
#include "htmlform.h"

using namespace std;

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

