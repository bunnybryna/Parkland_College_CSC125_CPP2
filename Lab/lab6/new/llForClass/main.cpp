#include <iostream>

#include "linkedlistnode.h"
#include "linkedlist.h"

using namespace std;

int main()
{
    /// test linkedlistnode constructor
    LinkedListNode n("string", NULL);
    LinkedListNode two("another", &n);
    cout << two << endl;

    /// test push_front
    LinkedList ll;
    cout << "First list:" << ll << " is the first list" << endl;
    ll.push_front("one");
    ll.push_front("two");
    ll.push_front("three");

    /// test push_back
    cout << "Here's ll after inserting 3 items: " << ll << endl;
    ll.push_back("end1");
    ll.push_back("end2");
    ll.push_back("end3");

    /// test pop_front()
    cout << "Here's ll after inserting 6 items: " << ll << endl;
    ll.pop_front();
    cout << "Here's ll after with 5 items: " << ll << endl;
    ll.pop_front();
    ll.pop_front();
    ll.pop_front();
    ll.pop_front();
    cout << "Here's ll after with 1 items: " << ll << endl;
    ll.pop_front();
    cout << "Here's ll after with emptying it: " << ll << endl;
///    ll.pop_front();

    /// test count
    cout << ll.count() << " Elements in the list" << endl;
    ll.push_back("end1");
    ll.push_back("end2");
    ll.push_back("end3");
    ll.push_back("end4");
    ll.push_back("end5");
    ll.push_back("end6");
    ll.push_back("end7");
    ll.push_back("end8");
    ll.push_back("end9");
    cout << ll.count() << " Elements in the list" << endl;

    /// test printBackwards
    ll.print();
    cout << endl << endl;
    ll.printBackwards();
    ll.push_front("one");
    ll.push_front("two");
    ll.push_front("three");
    ll.push_back("end4");
    ll.push_back("End5");
    ll.push_front("end6");
    ll.push_back("End7");


    /// test mergesort
    cout << endl << endl;
    ll.print();
    ll.mergeSort();
    cout << endl << "----- sorted? ------" << endl;
    ll.print();

    ll.pop_front();
    ll.pop_front();
    ll.pop_front();
    ll.pop_front();
    ll.pop_front();
    ll.pop_front();

    /// test the copy constructor
    cout << endl << "copy constructor" << endl;
    LinkedList newList(ll);
    cout <<"NEW: "<< newList << endl;
    cout <<"OLD: "<< ll << endl;

    ll.pop_front();
    cout << "NEW: " << newList << endl;
    cout << "OLD: " << ll << endl;


    /// test assignment operator
    LinkedList another;
    another = ll;
    cout <<"NEW: "<< another << endl;
    cout <<"OLD: "<< ll << endl;

    ll.pop_front();
    cout << "NEW: " << another << endl;
    cout << "OLD: " << ll << endl;
    LinkedList yetAnother;
    yetAnother = another = ll;
    ll.pop_front();
    another.pop_front();
    cout << "ANO: " << another << endl;
    cout << "OLD: " << ll << endl;
    cout << "YET: " << yetAnother << endl;

    /// test destructor
    LinkedList *llPtr;

    for (int i=0;i<100000000;i++)
    {
        llPtr = new LinkedList();
        llPtr->push_front("memory1");
        llPtr->push_front("memory2");
        llPtr->push_front("memory1");
        llPtr->push_front("memory2");
        llPtr->push_front("memory1");
        llPtr->push_front("memory2");
        delete llPtr;
    }

//    cout <<"\nMEMORY: "<< *llPtr << endl;

    return 0;
}
