#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "linkedlistnode.h"
#include <iostream>

using namespace std;

class LinkedList
{
    friend ostream& operator<<(ostream& o, LinkedList& ll);

    public:
        LinkedList();
        LinkedList( const LinkedList& fromList );
        ~LinkedList();

        bool empty();
        void push_front(string str);
        void push_back(string str);
        void pop_front();
        void clear(); /// remove all contents
        string front() {return m_Head->getData();}
        string back() {return m_Tail->getData();}
        int count() {return countRecursiveHelper(m_Head);}
        void print() {printRecursiveHelper(m_Head);}
        void printBackwards() {printBackwardsRecursiveHelper(m_Head);}
        void mergeSort();


        LinkedList& operator=(const LinkedList& fromList);

    protected:
    private:
        int countRecursiveHelper(LinkedListNode* ptr);
        void printRecursiveHelper(LinkedListNode* ptr);
        void printBackwardsRecursiveHelper(LinkedListNode* ptr);
        void split(LinkedList &l1, LinkedList &l2);
        void merge(LinkedList &l1, LinkedList &l2);

        LinkedListNode* m_Head;
        LinkedListNode* m_Tail;
};


#endif // LINKEDLIST_H
