#include <iostream>
#include <string>
#include <cstdlib>
#include "htmlform.h"
#include "linkedlist.h"

using namespace std;


bool checkOpen(string p);
bool checkClose(string p);
bool checkMatch(string p1,string p2);



int main()
{
    cout << "Content-type: text/html\n\n";

    /// build a form object
    HTMLform matchParen;
    matchParen.getPostData(); 
    cout << "Bryna matched parentheses version 1" << endl;    
    LinkedList ll;
    string check = matchParen.getField("parenthesis");
    for (int i=0;i<check.length();i++)
    {
        // convert char to string
        string strP(1,check[i]);
        if (checkOpen(strP))
        {
             ll.push_front(strP);
             continue;
        }

        else if (checkClose(strP))
        {
            if (ll.empty())
            {
                cout << "Sorry, these parentheses are not matched!" << endl;
                exit(1);
            }
            else
            {
                if (checkMatch(ll.front(),strP))
                {
                    ll.pop_front();                    
                    continue;
                }
                else
                    cout << "Sorry, these parentheses are not matched!" << endl;
                    exit(1);

            }
        }
        else
        {
            //cout << "other " << ll<<endl;
            continue;
        }

    }
    if (ll.empty())
    {
        cout << "Congratulations,these parentheses are matched!" << endl;
    }
    else
        cout << "Sorry, these parentheses are not matched!" << endl;
    return 0;
}


bool checkOpen(string p)
{
    if (p == "(" || p == "[" || p == "{" )
        return true;
    else
        return false;
}
bool checkClose(string p)
{
    if (p == ")" || p == "]" || p == "}" )
        return true;
    else
        return false;
}

bool checkMatch(string p1,string p2)
{
    if ((p1 == "("  && p2 == ")")
        || (p1 == "[" && p2 == "]")
        || (p1 == "{" && p2 == "}"))
        return true;
    else
        return false;
}
