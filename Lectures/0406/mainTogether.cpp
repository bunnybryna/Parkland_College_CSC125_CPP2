#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;
template <class T>
class Stack<T> :private LinkedList<T>
{
public:
        void pop(pop_front();)
        void push(T data){push_front(T data);}
        T top(){return front();}
        // put :: scope resolutioto specify which class 
        bool empty(){return LinkedList<T>::empty();}

}; 

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
    Stack s<int>;
    s.push(10);
    s.push(20);
    cout << s.top << endl;

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

