#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print(vector<string> n)
{
	for(string name: n)
	{
		cout << name << " ";
	}
}

int main()
{
	vector<string> names;
	names.push_back("Lee");
	names.push_back("Bryna");
	names.push_back("Ava");
	names.push_back("Jin");
	sort(names.begin(),names.end());
	print(names);
	cout << endl;
    do
    {
        print(names);
        cout << endl;
    }while(next_permutation(names.begin(),names.end()));
	print(names);

    return 0;
}
