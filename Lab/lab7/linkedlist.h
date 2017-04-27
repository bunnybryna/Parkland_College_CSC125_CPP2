#ifndef LINKEDLIST_H
#define LINKEDLIST_H

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
    //void push_front(string str);
    void push_front(string str);
    void push_back(string str);
    void pop_front();
    void clear();
    int count() {return countRecursiveHelper(m_Head);}
    void print(){printRecursiveHelper(m_Head);}
    string front(){return m_Head->getData();}
private:
    int countRecursiveHelper(LinkedListNode* ptr);
    void printRecursiveHelper(LinkedListNode* ptr);
    LinkedListNode* m_Head;
    LinkedListNode* m_Tail;
};

ostream& operator<<(ostream& o, LinkedListNode node);
ostream& operator<<(ostream& o, LinkedListNode* nodePtr);

#endif // LINKEDLIST_H