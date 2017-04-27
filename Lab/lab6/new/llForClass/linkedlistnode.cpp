#include "linkedlistnode.h"

ostream& operator<<(ostream& o, LinkedListNode node)
{
    o << node.getData();
    return o;
}

ostream& operator<<(ostream& o, LinkedListNode* nodePtr)
{
    o << nodePtr->getData();
    return o;
}

