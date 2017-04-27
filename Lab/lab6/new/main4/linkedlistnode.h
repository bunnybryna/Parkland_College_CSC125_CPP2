
#ifndef LINKEDLISTNODE_H
#define LINKEDLISTNODE_H

#include <string>

using namespace std;

class LinkedListNode
{
    public:
        LinkedListNode(string str, LinkedListNode* ptr)
          {
              m_Next = ptr;
              m_Data = str;
          }

        void setNext(LinkedListNode* ptr) {m_Next = ptr;}
        void setData(string str) {m_Data = str;}

        LinkedListNode* getNext() {return m_Next;}
        string getData() {return m_Data;}

    protected:
    private:
        string m_Data;
        LinkedListNode* m_Next;
};

ostream& operator<<(ostream& o, LinkedListNode node);
ostream& operator<<(ostream& o, LinkedListNode* nodePtr);

#endif // LINKEDLISTNODE_H
