#include <iostream>
#include <string>
#include <cstdlib>
#include "htmlform.h"
#include "linkedlist.h"

using namespace std;

void printProgram(string program);   /// print the program in HTML
void parseProgram(string program, LinkedList& queue);
void parse(string line, LinkedList& queue);


int main()
{
	/// complete the http header
	cout << "Content-type: text/html\n\n";

	/// build a form object
	HTMLform steps;
	steps.getPostData();

	/// Show the debugging
	cout << "Queue Parser Lab startup" << endl;
	steps.debug();

	/// the entire programs
	string program = steps.getField("program");
	printProgram(program);
	LinkedList ll;	
	parseProgram(program,ll);
    return 0;
}


void printProgram(string program)
{
  /// a single line
  string line;
  /// for counting the lines
  int count = 0;
  /// where the newline is (for peeling off a line)
  int pos;

  while ( string::npos != (pos = program.find("\n") ) )
    {
      line = program.substr(0, pos);    /// before the newline
      program = program.substr(pos+1);  /// after the newline
      /// there might newline characters at the end of line
      if (line[pos] < '0') line.erase(pos-1);
      /// here's where you need to process 'line'
      /// this routine just prints it.
      cout << ++count << ": [" << line << "] len=" << line.size()
           << "<br />" << endl;
    }
}

void parseProgram(string program, LinkedList& queue)
{
  string line;
  int count = 0;
  int pos;
  while ( string::npos != (pos = program.find("\n") ) )
    {
      line = program.substr(0, pos);
      program = program.substr(pos+1);
      if (line[pos] < '0')
		  line.erase(pos-1);
	  parse(line,queue);
      //cout << ++count << ": [" << line << "] len=" << line.size()<< "<br />" << endl;	  
    }
   // in case someone forget to put \n for the last command
/*   if (program.size() !=0)
	   parse(program,queue);*/
}

void parse(string line, LinkedList& queue)
{
	if (line == "SHOW")
		{
			queue.print();
		}
	else if (line == "POP")
		{
			if (queue.empty())
			{
				cerr << "Error: trying to remove things from an empty queue." << endl;
				exit(1);
			}
			queue.pop_front();
		}
	else if (line == "FRONT")
		{
			if (queue.empty())
			{
				cerr << "Error: it's an empty queue." << endl;
				exit(1);
			}
			cout << queue.front()<<endl;
		}
	else if (line == "NAME")
		{
			cout << "Bryna Zhao:)"<< endl;
		}

    else if (line.substr(0,4) == "PUSH")
		{
			line = line.substr(5);
			queue.push_back(line);
		}
	else
	{
		cerr << "Error: invalid command " << line << endl;
		exit(1);
	}
        return;
}

