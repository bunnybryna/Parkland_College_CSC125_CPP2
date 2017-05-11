// 18.2 Bidirectional and Random Access Iterator Use

#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

int main()
{
	vector<char> container;
	container.push_back('A');
	container.push_back('B');
	container.push_back('C');
	container.push_back('D');
	 for(int i=0;i<4;i++)
		 cout << "container[" << i << "]==" << container[i] << endl;
	 vector<char>::iterator p = container.begin();
	 cout << "The third entry is " << container[2] << endl;
	 // p[2] and *(p+2) are same
	 cout << "The third entry is " << p[2] << endl;
	 cout << "The third entry is " << *(p+2) << endl;	 
	 cout << "Back to container[0].\n";
	 p = container.begin();
	 cout << "which has value " << *p << endl;
	 cout << "Two steps forward and one step back:\n";
	 p++;
	 cout << *p << endl;
	 p++;
	 cout << *p << endl;
	 p--;
	 cout << *p << endl;
	 return 0;
}	 
// forward ++ < bidirectional ++ -- < random access []

// constant iterator can't be changed
std::vector<char>::const_iterator p = container.begin();
*p = 'Z';

// rbegin() and rend() rp++

// sequential containers: list, slist, vector and deque
//18.5 Using the list Template Class
#include <iostream>
#include <list>
using std::cout;
using std::endl;
using std::list;

int main()
{
	list<int> list_object;
	for(int i=0;i<=3;i++)
		list_object.push_back(i);
	cout << "List contains:\n";
	list<int>::iterator iter;
	for(iter=list_object.begin();iter!=list_object.end();iter++)
		cout << *iter<< " ";
	cout << endl;
	
	cout << "Setting all entries to 0:\n";
	for(iter=list_object.begin();iter!=list_object.end();iter++)
		*iter = 0;
	cout << "List now contains:\n";
	for(iter=list_object.begin();iter!=list_object.end();iter++)
		cout << *iter<< " ";	
	cout << endl;
	return 0;
}

// container adapters: stack and queue
// 18.10 Program Using the Stack Template Class
#include <iostream>
#include <stack>
using std::cin;
using std::cout;
using std::endl;
using std::stack;

int main()
{
	stack<char> s;
	cout << "Enter a line of text:\n";
	char next;
	cin.get(next);
	while(next!= '\n')
	{
		s.push(next);
		cin.get(next);
	};
	cout << "Written backward that is:\n";
	while (!s.empty())
	{
		cout << s.top();
		s.pop();
	}
	cout << endl;
	return 0;
}

// associative containers: set, map
// 18.12 Program Using the set Template Class
#include <iostream>
#include <set>
using std::cout;
using std::endl;
using std::set;

int main()
{
	set<char> s;
	s.insert('A');
	s.insert('D');
	s.insert('D');
	s.insert('C');
	s.insert('C');
	s.insert('B');
	cout << "The set contains:\n";
	set<char>::iterator p;
	for (p = s.begin();p!=s.end();p++)
		cout << *p << " ";
	cout << endl;
	cout << "Removing C.\n";
	s.erase('C');
	for (p = s.begin();p!=s.end();p++)
		cout << *p << " ";
	cout << endl;	
	return 0;
}	 
// 18.14 Program Using the map Template Class
#include <iostream>
#include <map>
using std::cout;
using std::endl;
using std::map;
using std::string;

int main()
{
	map<string, string> planets;
	planets["Mercury"] = "Hot planet";
	planets["Venus"] = "Atmosphere of sulfuric acid";
	planets["Earth"] = "Home";
	planets["Mars"] = "The Red Planet";
	planets["Jupiter"] = "Largest planet in our solar system";
	planets["Saturn"] = "Has rings";
	planets["Uranus"] = "Tilts on its side";
	planets["Neptune"] = "1500 mile-per-hour winds";
	planets["Pluto"] = "Dwarf planet";
	cout << "Entry for Mercury - " << planets["Mercury"] << endl << endl;
	if (planets.find("Mercury") != planets.end())
		cout << "Mercury is in the map." << endl;
	if (planets.find("Ceres") == planets.end())
		cout << "Ceres is not in the map" << endl;
	cout << "Iterating through all planets: ";
	map<string, string>::const_iterator iter;
	for (iter = planets.begin();iter!=planets.end();iter++)
		cout << iter->first << " - " << iter->second << endl;
	return 0;
}	 
