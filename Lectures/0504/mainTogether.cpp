#include <iostream>
#include <exception>

using namespace std;

int main()
{
	try
	{
		// it will go to standard exception
		//int* myarray = new int[100000000000];
		// it will go to integer exception
		/*throw(20);
		int a=2/0;*/
		// it will go to ...
		throw("Bork");
		// a null pointer isn't catchable
        /*int* temp = NULL;
		*temp = 57;*/
	}
    catch(exception& e)
	{
		cout << "Standard exception: " << e.what() << endl;
	}
	catch(int e)
	{
	    cout << "Error number " << e << " has occured" << endl;
	}
	// if the above two didn't catch it, it will go here
	catch(...)
	{
		cout << "Something bad happened" << endl;
	}

	return 0;
}
