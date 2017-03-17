#include <iostream>
#include <vector>
#include "person.h"

using namespace std;

int main()
{
    Person ken;
    Person temp;
    string inputBuffer;
    ken.SetName("Ken Urban");
    ken.SetAddress1("2400 W.Bradley Ave.");
    ken.SetAddress2("");

    cout << ken.toString() << endl;

    vector<Person> ListOfPersons;
    ListOfPersons.push_back(ken);
    // add 3 people
    for (int i=0; i<3;i++)
    {

        cout << "Enter the name: ";
        getline(cin,inputBuffer);
        temp.SetName(inputBuffer);
        ListOfPersons.push_back(temp);
    }
    for (int i=0;i<ListOfPersons.size();i++)
    {
        cout << ListOfPersons[i].toString();
    }
    return 0;
}
