#include <iostream>

using namespace std;
class Thingy
{
public:
	//static const int emptyThingys;
	static int emptyThingys;
	Thingy();
	int count() {return _CountOfThingy;}
private:
	int _Number;
	static int _CountOfThingy;
};

int main()
{

	Thingy* t;
	Thingy* t2;
	t = new Thingy;
	for (int i=0;i<1000;++i)
		t = new Thingy;
    // t and t2 shares the same count
	cout << t->count() << endl;
    cout << t2->count() << endl;

    cout << t->emptyThingys << endl;
    cout << t2->emptyThingys << endl;
    // change to t also happens to t2
    t->emptyThingys = 15;
    cout << t->emptyThingys << endl;
    cout << t2->emptyThingys << endl;
    // can be accessed by the class
    cout << Thingy::emptyThingys << endl;
	return 0;
}

Thingy::Thingy()
{
	_CountOfThingy ++;
}
// has to be initialized in the cpp
int Thingy::_CountOfThingy = 0;
// usually put const in front of it
//const int Thingy::emptyThingys = 10;
int Thingy::emptyThingys = 10;

// static often used in recursive calls, works like a global variable 

/*int myFun(bool reset)
{
	static int callcount;
	if (reset) callcount = 0;
	callcount ++;
}
*/
