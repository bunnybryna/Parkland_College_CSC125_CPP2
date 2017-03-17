#include <iostream>

using namespace std;

int main()
{
	string queryString;
	// Read in post data
	getline(cin,queryString);
	cout << "Content-type: text/html\n\n";
	
	cout << "handleBasicForm.cpp version 1"<< endl;
	// use fixed space font
	cout << "<text>";
    // here you will see sth like name=Bryna&address=savoy
	cout << queryString;
	cout << "</text>";
	return 0;
}

