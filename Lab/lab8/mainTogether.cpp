#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;


class LinkedListNode
{
public:
    LinkedListNode(string str,LinkedListNode* ptr);
    LinkedListNode* getNext(){return m_Next;}
    void setNext(LinkedListNode* ptr){m_Next = ptr;}
    void setData(string str){m_Data = str;}
    string getData(){return m_Data;}
private:
    string m_Data;
    LinkedListNode* m_Next;
};

class LinkedList
{
friend  ostream& operator<<(ostream& o, LinkedList ll);
public:
    LinkedList();
    LinkedList(const LinkedList& fromList);
    LinkedList& operator=(const LinkedList& fromList);
    ~LinkedList();
    bool empty();
    void push_front(string str);
    void push_back(string str);
    void pop_front();
    void clear();
    int count() {return countRecursiveHelper(m_Head);}
    void print(){printRecursiveHelper(m_Head);}
    void printBackwards(){printBackwardsRecursiveHelper(m_Head);}
    void mergeSort();
    string front(){return m_Head->getData();}
private:
    int countRecursiveHelper(LinkedListNode* ptr);
    void printRecursiveHelper(LinkedListNode* ptr);
    void printBackwardsRecursiveHelper(LinkedListNode* ptr);
    void split(LinkedList &l1,LinkedList &l2);
    void merge(LinkedList &l1,LinkedList &l2);
    LinkedListNode* m_Head;
    LinkedListNode* m_Tail;
};

ostream& operator<<(ostream& o, LinkedListNode node);
ostream& operator<<(ostream& o, LinkedListNode* nodePtr);

void printProgram(string program);   /// print the program in HTML
void parseProgram(string program, LinkedList& queue);
void parse(string line, LinkedList& queue);


int main()
{

	LinkedList ll;
	string program="HOW\nNAME";
	//string program="bryna zhao";
	parseProgram(program,ll);
    return 0;
}

ostream& operator<<(ostream& o,LinkedListNode node)
{
    o<< node.getData();
    return o;
}
ostream& operator<<(ostream& o,LinkedListNode* nodePtr)
{
    o<<nodePtr->getData();
    return o;
}

ostream& operator<<(ostream& o,LinkedList ll)
{
    if(ll.empty())
    {
        o << "This list is empty";
    }
    LinkedListNode* ptr = ll.m_Head;
    while (ptr != NULL)
    {
        // note when ptr is printed, a function
        // ostream& operator<<(ostream& o, LinkedListNode* nodePtr) is called
        // so the object this ptr is pointing to got printed out
        o<< ptr << ", ";
        // move pointer through the list just like i++
        ptr = ptr->getNext();
    }
    return o;
}

LinkedListNode::LinkedListNode(string str, LinkedListNode* ptr)
{
    m_Next = ptr;
    m_Data = str;
}

LinkedList::LinkedList()
{
    m_Head = NULL;
    m_Tail = NULL;
}

LinkedList::LinkedList(const LinkedList& fromList)
{
    // make sure current list is empty
    m_Head = NULL;
    m_Tail = NULL;
    LinkedListNode *ptr = fromList.m_Head;
    while (ptr!= NULL)
    {
        push_back(ptr->getData());
        ptr=ptr->getNext();
    }
}

LinkedList& LinkedList::operator=(const LinkedList& fromList)
{
    clear();
    LinkedListNode *ptr = fromList.m_Head;
    while (ptr!= NULL)
    {
        push_back(ptr->getData());
        ptr=ptr->getNext();
    }
    return *this;
}

LinkedList::~LinkedList()
{
    clear();
}

bool LinkedList::empty()
{
    if(m_Head == NULL)
        return true;
    else
        return false;
}

void LinkedList::push_front(string str)
{
    if (empty())
    {
        // = goes from the back
        // return the address of a new object node
        m_Head = m_Tail = new LinkedListNode(str,NULL);
    }
    else
    {
        m_Head = new LinkedListNode(str, m_Head);
    }
}

void LinkedList::push_back(string str)
{

    if (empty())
    {
        m_Head = m_Tail = new LinkedListNode(str,NULL);
    }
    else
    {

        m_Tail -> setNext(new LinkedListNode(str, NULL));
        m_Tail = m_Tail->getNext();
    }
}

void LinkedList::pop_front()
{
    if (empty())
    {
        cerr << "Error: trying to remove things from an empty list" << endl;
        exit(3);
    }
    LinkedListNode* tempPtr = m_Head;
    m_Head = m_Head->getNext();
    delete tempPtr;
    // may go down from one to zero
    if (m_Head == NULL)
    {
        m_Tail = NULL;
    }
}

void LinkedList::clear()
{
    while (!empty())
    {
        pop_front();
    }
}

int LinkedList::countRecursiveHelper(LinkedListNode* ptr)
{
    if (ptr == NULL)
    {
        return 0;
    }
    return 1 + countRecursiveHelper(ptr->getNext());
}

void LinkedList::printRecursiveHelper(LinkedListNode* ptr)
{
    if (ptr == NULL)
    {
        return;
    }
    cout << ptr->getData() << " ";
    printRecursiveHelper(ptr->getNext());
}

void LinkedList::printBackwardsRecursiveHelper(LinkedListNode* ptr)
{
    if (ptr == NULL)
    {
        return;
    }
    printBackwardsRecursiveHelper(ptr->getNext());
    cout << ptr->getData() << " ";
}

void LinkedList::mergeSort()
{
    // 0 or 1 element
    if (m_Head == m_Tail)
    {
        return;
    }
    LinkedList l1,l2;
    split(l1,l2);
    l1.mergeSort();
    l2.mergeSort();
    merge(l1,l2);
}

void LinkedList::split(LinkedList &l1,LinkedList &l2)
{
    while(!empty())
    {
        l1.push_back(front());
        pop_front();
        if (!empty())
        {
            l2.push_back(front());
            pop_front();
        }
    }
}

void LinkedList::merge(LinkedList &l1,LinkedList &l2)
{
    while(!l1.empty() && !l2.empty())
    {
        if (l1.front() < l2.front())
        {
            push_back(l1.front());
            l1.pop_front();
        }
        else
        {
            push_back(l2.front());
            l2.pop_front();
        }
    }
    while (!l1.empty())
    {
        push_back(l1.front());
        l1.pop_front();
    }
    while (!l2.empty())
    {
        push_back(l2.front());
        l2.pop_front();
    }
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
	  parse(line,queue);
      //cout << ++count << ": [" << line << "] len=" << line.size()<< "<br />" << endl;
      if (line[pos] < '0')
		  line.erase(pos-1);
    }
   // in case someone forget to put \n for the last command
   if (program.size() !=0)
	   parse(program,queue);
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

