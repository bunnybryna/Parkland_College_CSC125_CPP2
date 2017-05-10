#include <iostream>
#include <array>
#include <list>
#include <chrono>
#include <random>
#include <algorithm>
// change settings->compiler->c++11
using namespace std;

int main()
{
	array<int, 10> theNumers = {5,5,3,4,2,7,8,3,3,1};
	for (int i=0;i<theNumers.size();i++)
    {
        cout << theNumers[i] << " ";
    }
    cout << endl;
    // for each
    for (int value:theNumers)
    {
        cout << value << " ";
    }
    cout << endl;
    list<string> theWords;
    theWords.push_back("One");
    theWords.push_back("Two");
    theWords.push_back("Three");
    for (string value:theWords)
    {
        cout << value << " ";
    }
    //for (auto itr=theWords.begin();itr!=theWords.end();itr++)
    for (auto itr=theWords.rbegin();itr!=theWords.rend();itr++)
    {
        cout << *itr<< " ";
    }
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    std::uniform_int_distribution<int> distribution(100000,999999);
    cout << endl << "Random: " << endl;
    for (int &item:theNumers)
    {
        item = distribution(generator);
        cout << item << " ";
    }
    // lambda expression
    // [](parameters) {statements;};
    cout << endl << "After sorted: " << endl;
    std::sort(theNumers.begin(),theNumers.end(),[](int a,int b)
    {
        return b<a;
    } );
    for (int value:theNumers)
    {
        cout << value << " ";
    }
    return 0;
}
