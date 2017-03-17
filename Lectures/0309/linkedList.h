#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_

#include <iostream>
#include <string>
#include "linkedListNode.h"

using namespace std;

class LinkedList
{
friend  ostream& operator<<(ostream& o, LinkedList ll);
public:
    LinkedList();
    bool empty();
    void push_front(string str);
private:
    LinkedListNode* m_Head;
    LinkedListNode* m_Tail;
};

#endif