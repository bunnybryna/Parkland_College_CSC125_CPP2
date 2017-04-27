#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <sstream>
#include <fstream>
#include "linkedlistnode.h"
#include "linkedlist.h"


using namespace std;

int main()
{
	ofstream outFile;
	outFile.open("sortTime.txt");
	srand((unsigned)time(0));
	for (int i=0;i<600;i++)
	{
		int n = rand();
		// cout << "n is now " << n << endl;
		int square = n*n;
		// cout << "n square is now " << square<< endl;
		LinkedList ll;
		long long int startTime;
		long long int endTime;
		startTime = GetTickCount();
		for (int j=0;j< n;j++)
		{
			int num = rand();
			stringstream ss;
			ss << num;
			string str = ss.str();
			ll.push_back(str);
		}
		ll.mergeSort();
		//ll.print();
		endTime = GetTickCount();
		long long int takes = endTime - startTime;
		outFile << square << " " << takes << endl;
		//cout << "it takes " << takes << "------------------------------------------------------------" << endl;
	}
	outFile.close();
    return 0;
}
