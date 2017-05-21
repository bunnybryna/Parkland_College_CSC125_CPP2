#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main()
{
	vector<string> list1, list2;
	list1.push_back("One");
	list1.push_back("Two");
	list1.push_back("Three");
	list1.push_back("Four");
	list2.push_back("A");
	list2.push_back("B");
	list2.push_back("C");
	list2.push_back("D");
	set<string> set1;
	set<string> set2;
	set1.insert("Hello");
	set1.insert("World");
	// what if there is an element in both sets
	// will be ignored, no repetition
	set1.insert("One");

	//The intersection of two sets is formed only by
	//the elements that are present in both sets.
	vector<string> intersection(10);
	vector<string>::iterator it;
	sort(list1.begin(),list1.end());
	sort(list2.begin(),list2.end());
	it = set_intersection(list1.begin(),list1.end(),list2.begin(),list2.end(),intersection.begin());
	intersection.resize(it-intersection.begin());
	cout << "The intersection has " << intersection.size() << " elements\n" ;
	for (it = intersection.begin();it!=intersection.end();++it)
    {
		cout << " " << *it;
    }
	cout << endl;
    //The union of two sets is formed by 
	// the elements that are present in 
	// either one of the sets, or in both.
	vector<string> resultunion(10);
	it = set_union(list1.begin(),list1.end(),set1.begin(),set1.end(),resultunion.begin());
	// more accurate to count the size, is to use resize first
	resultunion.resize(it-resultunion.begin());
	cout << "The union has " << resultunion.size() << " elements:\n";
	for (it = resultunion.begin();it!=resultunion.end();++it)
        cout << " " << *it;
    return 0;
}
