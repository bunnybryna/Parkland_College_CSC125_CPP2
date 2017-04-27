#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

template <class T>
class LinkedListNode
{
public:
    LinkedListNode(T str,LinkedListNode<T>* ptr);
    LinkedListNode<T>* getNext(){return m_Next;}
    void setNext(LinkedListNode<T>* ptr){m_Next = ptr;}
    void setData(T str){m_Data = str;}
    T getData(){return m_Data;}
private:
    T m_Data;
    LinkedListNode<T>* m_Next;
};

template <class T>
class LinkedList
{
    // friend function is different <T1>
template <class T1>
friend  ostream& operator<<(ostream& o, LinkedList<T1> ll);
public:
    LinkedList<T>();
    LinkedList(const LinkedList<T>& fromList);
    LinkedList& operator=(const LinkedList<T>& fromList);
    ~LinkedList();
    bool empty();
    void push_front(T str);
    void push_back(T str);
    void pop_front();
    void clear();
    int count() {return countRecursiveHelper(m_Head);}
    void print(){printRecursiveHelper(m_Head);}
    T front(){return m_Head->getData();}
private:
    int countRecursiveHelper(LinkedListNode<T>* ptr);
    void printRecursiveHelper(LinkedListNode<T>* ptr);
    LinkedListNode<T>* m_Head;
    LinkedListNode<T>* m_Tail;
};

template <class T>
ostream& operator<<(ostream& o, LinkedListNode<T> node);
template <class T>
ostream& operator<<(ostream& o, LinkedListNode<T>* nodePtr);


int main()
{
    LinkedList<string> ll;
    ll.push_front("one");
    ll.push_front("two");
    ll.push_front("three");
    ll.push_back("end1");
    ll.push_back("end2");
    ll.push_back("end3");
    cout << ll;
    /*cout << "First list:" << ll << " is the first list" << endl;
    //test copy constructor
    // when you make the copy, only copy the pointers (head, tail)
    // not copy the nodes
    // if you want to copy the nodes, need a logical copy not the physical copy
    LinkedList newList(ll);
    cout <<"NEW: " << newList << endl;
    cout <<"OLD: " << ll << endl;
    ll.pop_front();
    cout << "After pop front the old list: \n";
    cout <<"NEW: " << newList << endl;
    cout <<"OLD: "<< ll << endl;
    // test the assignment operator
    LinkedList another;
    another = ll;
    cout <<"NEW: " << another << endl;
    cout <<"OLD: " << ll << endl;
    ll.pop_front();
    cout << "After pop front the old list: \n";
    cout <<"NEW: "<< another << endl;
    cout <<"OLD: "<< ll << endl;
    LinkedList yetAnother;
    yetAnother = another = ll;
    ll.pop_front();
    another.pop_front();
    cout << "YET = NEW = OLD, After pop front the old and new list: \n";
    cout <<"NEW: "<< another << endl;
    cout <<"OLD: "<< ll << endl;
    cout <<"YET: " << yetAnother << endl;*/
    // test destructor
    /*
    LinkedList *llPtr = new LinkedList();
    for (int i=0;i<10000000;i++)
    {

        llPtr = new LinkedList;
        llPtr ->push_front("memory");
        delete llPtr;
    }*/
    //llPtr->push_front("memory");
    //cout << "\nMemeory " << *llPtr << endl;

    return 0;
}
template <class T>
ostream& operator<<(ostream& o,LinkedListNode<T> node)
{
    o<< node.getData();
    return o;
}

template <class T>
ostream& operator<<(ostream& o,LinkedListNode<T>* nodePtr)
{
    o<<nodePtr->getData();
    return o;
}

template <class T>
ostream& operator<<(ostream& o,LinkedList<T> ll)
{
    if(ll.empty())
    {
        o << "This list is empty";
    }
    LinkedListNode<T>* ptr = ll.m_Head;
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

// constructor a little different no <T> 
template <class T>
LinkedListNode<T>::LinkedListNode(T str, LinkedListNode<T>* ptr)
{
    m_Next = ptr;
    m_Data = str;
}

template <class T>
LinkedList<T>::LinkedList()
{
    m_Head = NULL;
    m_Tail = NULL;
}

template <class T>
LinkedList<T>::LinkedList(const LinkedList<T>& fromList)
{
    // make sure current list is empty
    m_Head = NULL;
    m_Tail = NULL;
    LinkedListNode<T> *ptr = fromList.m_Head;
    while (ptr!= NULL)
    {
        push_back(ptr->getData());
        ptr=ptr->getNext();
    }
}

template <class T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& fromList)
{
    clear();
    LinkedListNode<T> *ptr = fromList.m_Head;
    while (ptr!= NULL)
    {
        push_back(ptr->getData());
        ptr=ptr->getNext();
    }
    return *this;
}

template <class T>
LinkedList<T>::~LinkedList<T>()
{
    clear();
}

template <class T>
bool LinkedList<T>::empty()
{
    if(m_Head == NULL)
        return true;
    else
        return false;
}

template <class T>
void LinkedList<T>::push_front(T str)
{
    if (empty())
    {
        // = goes from the back
        // return the address of a new object node
        m_Head = m_Tail = new LinkedListNode<T>(str,NULL);
    }
    else
    {
        m_Head = new LinkedListNode<T>(str, m_Head);
    }
}

template <class T>
void LinkedList<T>::push_back(T str)
{

    if (empty())
    {
        m_Head = m_Tail = new LinkedListNode<T>(str,NULL);
    }
    else
    {

        m_Tail -> setNext(new LinkedListNode<T>(str, NULL));
        m_Tail = m_Tail->getNext();
    }
}

template <class T>
void LinkedList<T>::pop_front()
{
    if (empty())
    {
        cerr << "Error: trying to remove things from an empty list" << endl;
        exit(3);
    }
    LinkedListNode<T>* tempPtr = m_Head;
    m_Head = m_Head->getNext();
    delete tempPtr;
    // may go down from one to zero
    if (m_Head == NULL)
    {
        m_Tail = NULL;
    }
}

template <class T>
void LinkedList<T>::clear()
{
    while (!empty())
    {
        pop_front();
    }
}

template <class T>
int LinkedList<T>::countRecursiveHelper(LinkedListNode<T>* ptr)
{
    if (ptr == NULL)
    {
        return 0;
    }
    return 1 + countRecursiveHelper(ptr->getNext());
}

template <class T>
void LinkedList<T>::printRecursiveHelper(LinkedListNode<T>* ptr)
{
    if (ptr == NULL)
    {
        return;
    }
    cout << ptr->getData() << " ";
    printRecursiveHelper(ptr->getNext());
}

