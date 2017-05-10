#include <iostream>
#include <set>

using namespace std;

int main()
{
	set<string> partyList;
	partyList.insert("Ken");
	partyList.insert("Bryna");
	partyList.insert("Dave");
	partyList.insert("Andy");
	set<string>::iterator itr;
	// print in order
	for (itr = partyList.begin();itr!= partyList.end();itr++)
	{
		cout << *itr << endl;
	}
	// find => O(lg n), insert=> O(lg n)
	itr = partyList.find("Zhao");
	// if found, itr points to end()
	if(itr!=partyList.end())
	{
		cout << "On the list" << endl;
	}
	else
		cout << "Not on the list" << endl;
	return 0;
}
