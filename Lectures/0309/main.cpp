#include <iostream>
#include <string>
#include "linkedList.h"
#include "linkedListNode.h"

using namespace std;

int main()
{
    LinkedListNode n("string",NULL);
    LinkedListNode two("another",&n);
    LinkedList ll;
    cout << "First list:" << ll << " is the first list" << endl;
    ll.push_front("one");
    ll.push_front("two");
    ll.push_front("three");
    cout << "Here's ll after inserting 3 items: " << ll << endl;

    cout << "Hello World!" << endl;
    return 0;
}

