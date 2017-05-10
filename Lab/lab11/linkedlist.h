#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <cstdlib>

using namespace std;

template <class T>
class LinkedListNode
{
    public:
        /// constructors
        LinkedListNode<T>(T, LinkedListNode<T>*);

        /// getters
        T getData() {return m_Data;}
        LinkedListNode<T>* getNext() {return m_Next;}

        /// setters
        void setData(T data) {m_Data = data;}
        void setNext(LinkedListNode<T>* next) {m_Next = next;}

    protected:
    private:
        T m_Data;
        LinkedListNode<T>* m_Next;
};


//ostream& operator<<(ostream &o, LinkedListNode<T> lln);
//ostream& operator<<(ostream &o, LinkedListNode<T>* llnPtr);

template <class T>
class LinkedList
{
    ///friend ostream& operator<<(ostream &o, const LinkedList<T> &ll);

    public:
        LinkedList<T>();
        LinkedList<T>(const LinkedList<T> &ll);
        ~LinkedList<T>(); /// destructor (called on delete)

        /// overloaded operator=
        LinkedList<T> operator=(const LinkedList<T> &ll);

        bool empty() const;
        void push_front(T s);
        /// to do list
        void push_back(T s);
        T front() const;
        void remove_front();

        /// mergesort
        void mergeSort();

        void print(ostream &o) const;

    protected:
    private:
        /// split the current list into l1 and l2 'evenly'
        void split(LinkedList<T> &l1, LinkedList<T> &l2);
        /// merge the lists l1 and l2 into the current list
        void merge(LinkedList<T> &l1, LinkedList<T> &l2);


        LinkedListNode<T>* m_Head;
        LinkedListNode<T>* m_Tail;
};

template <class T>
LinkedListNode<T>::LinkedListNode(T data, LinkedListNode<T>* next)
{
    //ctor
    m_Data = data;
    m_Next = next;
}

template <class T>
ostream& operator<<(ostream &o, LinkedListNode<T> lln)
{
    o << lln.getData() << "  ";
    if (lln.getNext())
        o << "--> ";
    else
        o << endl;
    return o;
}

template <class T>
ostream& operator<<(ostream &o, LinkedListNode<T>* llnPtr)
{
    o << llnPtr->getData() << " ";
    if (llnPtr->getNext())
        o << "--> ";
    else
        o << endl;

    return o;
}

template <class T>
LinkedList<T>::LinkedList()
{
    //ctor
    m_Head = m_Tail = static_cast<LinkedListNode<T>*>(0);
}

template <class T>
LinkedList<T>::LinkedList(const LinkedList<T> &ll)
{
    /// make a logical copy of ll into the current object
    /// start with an empty list
    m_Head = m_Tail = static_cast<LinkedListNode<T>*>(0);
    /// add the data one at a time
    LinkedListNode<T>* ptr=ll.m_Head;
    while (ptr)
    {
        push_back( ptr->getData() );
        ptr = ptr->getNext();
    }
}

template <class T>
LinkedList<T> LinkedList<T>::operator=(const LinkedList<T> &ll)
{
    /// clean out the old data
    while (!empty())
    {
        remove_front();
    }
    /// make a logical copy
    LinkedListNode<T>* ptr=ll.m_Head;
    while (ptr)
    {
        push_back( ptr->getData() );
        ptr = ptr->getNext();
    }
    return *this;
}

template <class T>
LinkedList<T>::~LinkedList<T>()
{
    /// clean out the old data
    cout << "calling the destructor" << endl;

    while (!empty())
    {
       remove_front();
    }

}

template <class T>
ostream& operator<<(ostream &o, const LinkedList<T> &ll)
{
    ll.print(o);
    return o;
}

template <class T>
void LinkedList<T>::print(ostream &o) const
{
    if ( empty() )
    {
        o << "Empty List" << endl;
    }
    else
    {
        LinkedListNode<T>* ptr;
        ptr = m_Head;
        while (ptr)
        {
            cout << ptr;
            ptr = ptr->getNext();
        }
    }
}

template <class T>
bool LinkedList<T>::empty() const
{
    return m_Head == static_cast<LinkedListNode<T>*>(0);
}

template <class T>
void LinkedList<T>::push_front(T s)
{
    if (empty())
    {
        /// for adding the first item
        m_Head = m_Tail = new LinkedListNode<T>(s, NULL);
    }
    else
    {
        /// for adding all the subsequent items
        m_Head = new LinkedListNode<T>(s, m_Head);
    }
}

template <class T>
void LinkedList<T>::push_back(T s)
{
    if (empty())
    {
        /// for adding the first item ( same as puch_front() )
        m_Head = m_Tail = new LinkedListNode<T>(s, NULL);
    }
    else
    {
        /// add to the tail
        m_Tail->setNext(new LinkedListNode<T>(s, NULL));
        m_Tail=m_Tail->getNext();
    }
}

template <class T>
T LinkedList<T>::front() const
{
    if (m_Head)
    {
        return m_Head->getData();
    }
    else
    {
        /// an error has occured!!!!
        cerr << "Attempting to look at an item from an empty list" << endl;
        exit(1);
    }
}

template <class T>
void LinkedList<T>::remove_front()
{
    if (!m_Head)
    {
        cerr << "Attempting to remove an item from an empty list" << endl;
        exit(1);
    }
    LinkedListNode<T>* deleteMe = m_Head;
    m_Head=m_Head->getNext();
    delete deleteMe;
}

template <class T>
void LinkedList<T>::split(LinkedList<T> &l1, LinkedList<T> &l2)
{
    while ( !empty() )
    {
        l1.push_back( front()  );
        remove_front();

        if ( !empty() )
        {
            l2.push_back( front() );
            remove_front();
        }
    }
}

template <class T>
void LinkedList<T>::merge(LinkedList<T> &l1, LinkedList<T> &l2)
{
    while ( !l1.empty() && !l2.empty() ) /// both have something
    {
        if ( l1.front() < l2.front() )
        {
            push_back( l1.front() );
            l1.remove_front();
        }
        else
        {
            push_back( l2.front() );
            l2.remove_front();
        }
    }
    /// at this point 1 one the lists (piles) is empty
    while (!l1.empty())
    {
        push_back( l1.front() );
        l1.remove_front();
    }
    while (!l2.empty())
    {
        push_back( l2.front() );
        l2.remove_front();
    }

}

template <class T>
void LinkedList<T>::mergeSort()
{
    if (m_Head == m_Tail)  /// zero or 1 item
    {
        return;
    }
    /// multiple items
    LinkedList<T> l1, l2;
    split(l1, l2);
    l1.mergeSort();
    l2.mergeSort();
    merge(l1, l2);
}


#endif // LINKEDLIST_H
