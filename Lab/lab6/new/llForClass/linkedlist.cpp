#include "linkedlist.h"
#include <cstdlib>

LinkedList::LinkedList()
{
    //ctor
    m_Head = NULL;
    m_Tail = NULL;
}


LinkedList::LinkedList( const LinkedList& fromList )
{

    /// current list is empty
    m_Head = NULL;
    m_Tail = NULL;

    LinkedListNode *ptr = fromList.m_Head;

    while ( ptr ) /// not null
    {
//        cout <<"copying:" << ptr->getData() << endl;
        push_back( ptr->getData() );
        ptr=ptr->getNext();
    }
}

LinkedList::~LinkedList()
{
    //ctor
    clear();
}

LinkedList& LinkedList::operator=(const LinkedList& fromList)
{
    /// copy opverwrites the current object
    clear();
    LinkedListNode *ptr = fromList.m_Head;

    while ( ptr ) /// not null
    {
//        cout <<"copying:" << ptr->getData() << endl;
        push_back( ptr->getData() );
        ptr=ptr->getNext();
    }
    return *this;
}

ostream& operator<<(ostream& o, LinkedList& ll)
{
    if (ll.empty())
    {
        o << "This list is empty";
    }
    LinkedListNode* ptr = ll.m_Head;   /// start at the beginning
    while (ptr != NULL)
    {
        o << ptr << ", ";
        ptr = ptr->getNext();
    }

    return o;
}

bool LinkedList::empty()
{
    if (m_Head == NULL)
        return true;
    else
        return false;
}

void LinkedList::push_front(string str)
{
    if (empty())
    {
        m_Head = m_Tail = new LinkedListNode(str, NULL);
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
        m_Head = m_Tail = new LinkedListNode(str, NULL);
    }
    else
    {
        m_Tail->setNext( new LinkedListNode(str, NULL) );
        m_Tail = m_Tail->getNext();
    }
}

void LinkedList::pop_front()
{
    /// what if the list is empty?
    if (empty())
    {
        cerr << "***Error: Trying to remove things from an empty list" << endl;
        exit(3);
    }

    LinkedListNode* tempPtr = m_Head;
    m_Head = m_Head->getNext();
    delete tempPtr;
    /// may go down to zero items
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
    /// ptr is the head of a list
    if (ptr == NULL)
    {
        return 0;
    }
    return 1 + countRecursiveHelper(ptr->getNext());
}

void LinkedList::printRecursiveHelper(LinkedListNode* ptr)
{
    if (ptr == NULL)
        return;
    cout << ptr->getData() << " ";
    printRecursiveHelper(ptr->getNext());
}

void LinkedList::printBackwardsRecursiveHelper(LinkedListNode* ptr)
{
    if (ptr == NULL)
        return;
    printBackwardsRecursiveHelper(ptr->getNext());
    cout << ptr->getData() << " ";
}

void LinkedList::mergeSort()
{
    if (m_Head == m_Tail) /// 0 or 1 element
    {
        return;
    }
    LinkedList l1, l2;
    split(l1, l2);
    l1.mergeSort();
    l2.mergeSort();
    merge(l1, l2);
}

void LinkedList::split(LinkedList &l1, LinkedList &l2)
{
    while (!empty())
    {
        l1.push_back( front() );
        pop_front();
        if (!empty())
        {
            l2.push_back( front() );
            pop_front();
        }
    }
}

void LinkedList::merge(LinkedList &l1, LinkedList &l2)
{
    while (!l1.empty() && !l2.empty() )
    {
        if (l1.front() < l2.front())
        {
            push_back( l1.front());
            l1.pop_front();
        }
        else
        {
            push_back( l2.front());
            l2.pop_front();
        }
    }
    /// at this point, l1 OR l2 is empty
    while (!l1.empty())
    {
        push_back( l1.front());
        l1.pop_front();
    }
    while (!l2.empty())
    {
        push_back( l2.front());
        l2.pop_front();
    }
}
