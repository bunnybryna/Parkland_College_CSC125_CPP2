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
    bool empty();
    void push_front(string str);
    void push_back(string str);
    void pop_front();
    void clear();
    int count() {return countRecursiveHelper(m_Head);}
    void print(){printRecursiveHelper(m_Head);}
    void printBackwards(){printBackwardsRecursiveHelper(m_Head);}
    void mergeSort();
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
    ll.push_back("end1");
    ll.push_back("end2");
    ll.push_back("end3");
    cout << "Here's ll after inserting 3 items: " << ll << endl;
    ll.pop_front();
    ll.pop_front();
    ll.pop_front();
    cout << "Here's ll after popping 3 items: " << ll << endl;
    cout << ll.count() << " elements in the list" << endl;
    ll.print();
    ll.printBackwards();
    cout << "Hello World!" << endl;

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

}

void LinkedList::merge(LinkedList &l1,LinkedList &l2)
{

}
