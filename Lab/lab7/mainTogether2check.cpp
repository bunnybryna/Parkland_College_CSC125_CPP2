#include <iostream>
#include <string>
#include <cstdlib>
#include "htmlform.h"

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

bool checkOpen(string p);
bool checkClose(string p);
bool checkMatch(string p1,string p2);

ostream& operator<<(ostream& o, LinkedListNode node);
ostream& operator<<(ostream& o, LinkedListNode* nodePtr);


int main()
{
    cout << "Content-type: text/html\n\n";

    /// build a form object
    HTMLform matchParen;
    matchParen.getPostData(); 
    cout << "Bryna matched parentheses version 1" << endl;    
    LinkedList ll;
    string check = matchParen.getField("parenthesis");
    for (int i=0;i<check.length();i++)
    {
        // convert char to string
        string strP(1,check[i]);
        if (checkOpen(strP))
        {
             ll.push_front(strP);
             continue;
        }

        else if (checkClose(strP))
        {
            if (ll.empty())
            {
                cout << "Sorry, these parentheses are not matched!" << endl;
                exit(1);
            }
            else
            {
                if (checkMatch(ll.front(),strP))
                {
                    ll.pop_front();                    
                    continue;
                }
                else
                    cout << "Sorry, these parentheses are not matched!" << endl;
                    exit(1);

            }
        }
        else
        {
            //cout << "other " << ll<<endl;
            continue;
        }

    }
    if (ll.empty())
    {
        cout << "Congratulations,these parentheses are matched!" << endl;
    }
    else
        cout << "Sorry, these parentheses are not matched!" << endl;
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
        o<< ptr << ", ";
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

LinkedList::LinkedList(const LinkedList& fromList)
{
    // make sure current list is empty
    m_Head = NULL;
    m_Tail = NULL;
    LinkedListNode *ptr = fromList.m_Head;
    while (ptr!= NULL)
    {
        push_back(ptr->getData());
        ptr=ptr->getNext();
    }
}

LinkedList& LinkedList::operator=(const LinkedList& fromList)
{
    clear();
    LinkedListNode *ptr = fromList.m_Head;
    while (ptr!= NULL)
    {
        push_back(ptr->getData());
        ptr=ptr->getNext();
    }
    return *this;
}

LinkedList::~LinkedList()
{
    clear();
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


bool checkOpen(string p)
{
    if (p == "(" || p == "[" || p == "{" )
        return true;
    else
        return false;
}
bool checkClose(string p)
{
    if (p == ")" || p == "]" || p == "}" )
        return true;
    else
        return false;
}

bool checkMatch(string p1,string p2)
{
    if ((p1 == "("  && p2 == ")")
        || (p1 == "[" && p2 == "]")
        || (p1 == "{" && p2 == "}"))
        return true;
    else
        return false;
}
