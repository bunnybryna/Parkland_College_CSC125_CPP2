#include <iostream>
#include <map>

using namespace std;

int main(int argc, const char * argv[])
{
	std::cout << "Hello"<< endl;
	map<string, string>dbRecord;
	// multimap no[], have to use insert and find
	dbRecord["firstname"]="Bryna";
	dbRecord["lastname"]="Zhao";
	dbRecord["address"]="2400 W. Bradley Ave";
	dbRecord["city"]="Champaign";
	dbRecord["state"]="IL";
	dbRecord["zipcode"]="61821";
	// won't allow duplicate
	//dbRecord["name"]="Bunny";
	// case sensitive
	cout << dbRecord["zipcode"]<<endl;
	cout << dbRecord.size() << endl;
	map<string, string>::iterator itr;
	dbRecord.insert(pair<string,string>("office","B129A"));
	pair<string, string> tempPair;
	tempPair.first = "Phone";
	tempPair.second = "217 217 2170";
	dbRecord.insert(tempPair);
	itr = dbRecord.find("state");
	if (itr == dbRecord.end())
    {
        cout << "Not found!" << endl;
    }
    else
    {
        cout << itr->second << endl;
    }
    cout << "---------------------------" << endl;
	cout << "Zipcode " << dbRecord.find("Zipcode")->second<< endl;
	cout << "zipcode " << dbRecord.find("zipcode")->second<< endl;
    cout << "---------------------------" << endl;
	dbRecord.erase("state");
	for (itr = dbRecord.begin();itr != dbRecord.end();++itr)
	{
		// itr point to pair<string, string>
		// its stored using a binary tree
		cout << "key is: " << itr->first << " /value is: " <<itr->second << endl;
	}
	cout << endl << "Multimap stuff" << endl << endl;
	multimap <string, string> mmap;
	mmap.insert(pair<string, string>("key1","value1"));
	mmap.insert(pair<string, string>("key2","value2"));
	mmap.insert(pair<string, string>("key3","value3"));
	mmap.insert(pair<string, string>("key4","value4"));
	multimap<string, string>::iterator mitr;
	mmap.insert(pair<string, string>("key2","value2another"));
	mmap.insert(pair<string, string>("key3","value3again"));
	mmap.insert(pair<string, string>("key2","value3again"));
    mmap.insert(pair<string, string>("key2","value2again"));
    for (mitr = mmap.begin();mitr != mmap.end();++mitr)
	{
		cout << "[" << mitr->first << "], " <<mitr->second << endl;
	}
	cout << mmap.count("key2")<< " number of key2" << endl;
	pair<multimap<string, string>::iterator, multimap<string, string>::iterator> range;
	range = mmap.equal_range("key2");
    for (mitr = range.first;mitr != range.second;++mitr)
	{
		cout << "[" << mitr->first << "], " <<mitr->second << endl;
	}
	return 0;
}
