// arrow operator combines a * and a .
(*head).count = 12;
head->cout = 12;

// to use NULL, need to include <cstddef> or <iostream>
// head is a pointer, a way to name the linked list
// when head = NULL, it is an empty list 
head = NULL;;

// 13.4 Funcitons to Add a Node at the Head of a Linked List
// Function declaration
struct Node
{
    int data;
    Node* link;
};

typedef Node* NodePtr;

void head_insert(NodePtr &head, int the_number);
// Function Definition
void head_insert(NodePtr &head, int the_number)
{
    NodePtr temp_ptr;
    temp_ptr = new Node;
    //Node.data = the_number same as below
    temp_ptr->data = the_number;
    // if you just do head->link, nothing pointing to the old head
    // lost nodes
    // Node.link = head,head is a pointer, so this Node points to whatever head points to
    temp_ptr->link = head;
    // then head then point to what temp_ptr points to, which is the new Node
    head = temp_ptr;
}

// here = here->link a way to iterate the whole linked list
Node_Type* iter;
for (iter = head; iter != NULL;iter = iter->link)
    cout << iter->data;

// 13.7 Function to Locate a Node in a Linked List
struct Node
{
    int data;
    Node* link;
};
typedef Node* NodePtr;

NodePtr search(NodePtr head, int target)
{
    NodePtr here = head;
    if (here == NULL)
    {
        return NULL;
    }
    else
    {
        while (here->data != target && here->link != NULL)
        {
            here = here->link;
            if (here->data == target)
                return here;
            else
                return NULL;
        }
    }
}

// 13.8 Inserting in the Middle of a Linked List
void insert(NodePtr after_me, int the_number)
temp_ptr->link = after_me->link;
after_me->link = temp_ptr;

// 13.9 Function to Add a Node in the Middle of a Linked List
struct Node
{
    int data;
    Node* link;
};
typedef Node* NodePtr;
void insert(NodePtr after_me, int the_number);
void insert(NodePtr after_me, int the_number)
{
    NodePtr temp_ptr;
    temp_ptr = new Node;
    temp_ptr->data = the_number;
    temp_ptr->link = after_me->link;
    after_me->link = temp_ptr;
}

//13.10 Removing a Node
before->link = discard->link;
delete discard;

// 13.11 A Doubly Linked List
struct Node
{
    int data;
    Node* forward_link;
    Node* back_link;
};
struct TreeNode
{
  int data;
  TreeNode* left_link;
  TreeNode* right_link;
};

// 13.13 Interface File for a Node Class
namespace linkedlistofclasses
{
    class Node
    {
        public:
            Node();
            Node(int value, Node* next);
            int getData() const;
            Node* getLink() const;
            void setData(int value);
            void setLink(Node* next);
        private:
            int data;
            Node* link;
        
    };
    typedef Node* NodePtr;
}

// 13.14 Implementation File for a Node Class
#include <iostream>
#include "Node.h"
namespace linkedlistofclasses
{
    Node::Node() :data(0),link(NULL)
    {
        
    }
    Node::Node(int value, Node* next) :data(value),link(next)
    {
        
    }
    int Node::getData() const
    {
        return data;
    }
    Node* Node::getLink() const
    {
        return link;
    }
    void Node::setData(int value)
    {
        data = value;
    }
    void Node::setLink(Node* next)
    {
        link = next;
    }
}

// 13.5 Program Using the Node Class
#include <iostream>
#include "Node.h"
using namespace std;
using namespace linkedlistofclasses;

void head_insert(NodePtr &head,int the_number)
{
    NodePtr temp_ptr;
    temp_ptr = new Node(the_number,head);
    head = temp_ptr;
}

int main()
{
    NodePtr head, tmp;
    // create a list of nodes 4->3->2->1->0
    head = new Node(0,NULL);
    for (int i=1;i<5;i++)
    {
        head_insert(head,i);
    }
    // iterate through the list and display each value
    tmp = head;
    while(tmp!=NULL)
    {
        cout << tmp->getData() << endl;
        tmp = tmp->getLink();
    }
    // delete all nodes in the list before exiting
    tmp = head;
    while(tmp!=NULL)
    {
        NodePtr nodeToDelete = tmp;
        tmp = tmp->getLink();
        delete nodeToDelete;
    }
    return 0;
}

// mainTogether
#include <iostream>
namespace linkedlistofclasses
{
    class Node
    {
        public:
            Node();
            Node(int value, Node* next);
            int getData() const;
            Node* getLink() const;
            void setData(int value);
            void setLink(Node* next);
        private:
            int data;
            Node* link;

    };
    typedef Node* NodePtr;
}

using namespace std;
using namespace linkedlistofclasses;

void head_insert(NodePtr &head,int the_number)
{
    NodePtr temp_ptr;
    temp_ptr = new Node(the_number,head);
    head = temp_ptr;
}

int main()
{
    NodePtr head, tmp;
    // create a list of nodes 4->3->2->1->0
    head = new Node(0,NULL);
    for (int i=1;i<5;i++)
    {
        head_insert(head,i);
    }
    // iterate through the list and display each value
    tmp = head;
    while(tmp!=NULL)
    {
        cout << tmp->getData() << endl;
        tmp = tmp->getLink();
    }
    // delete all nodes in the list before exiting
    tmp = head;
    while(tmp!=NULL)
    {
        NodePtr nodeToDelete = tmp;
        tmp = tmp->getLink();
        delete nodeToDelete;
    }
    return 0;
}

namespace linkedlistofclasses
{
    Node::Node() :data(0),link(NULL)
    {

    }
    Node::Node(int value, Node* next) :data(value),link(next)
    {

    }
    int Node::getData() const
    {
        return data;
    }
    Node* Node::getLink() const
    {
        return link;
    }
    void Node::setData(int value)
    {
        data = value;
    }
    void Node::setLink(Node* next)
    {
        link = next;
    }
}

//13.2 STACKS AND QUEUES
/* stacks: last-in/first-out LIFO
 * adding=>pushing, removing=>popping
 * queues: first-in/first-out FIFO
 * adding,removing*/
 // 13.17 Interface File for a Stack Class
 #ifndef STACK_H
 #define STACK_H
 namespace stacksavitch
 {
     struct StackFrame
     {
         char data;
         StackFrame* link;
     };
     typedef StackFrame* StackFramePtr;

     class Stack
     {
       public:
         Stack();
         // copy constructor
         Stack(const Stack &a_stack);
         ~Stack();
         void push(char the_symbol);
         char pop();
         bool empty() const;
       private:
         StackFramePtr top;
     };
  }
  #endif 
  
// 13.18 Program Using the Stack Class
#include <iostream>
#include "stack.h"
using namespace std;
using namespace stacksavitch;

int main()
{
    Stack s;
    char next, ans;
    do 
    {
        cout << "Enter a word: ";
        cin.get(next);
        while(next != '\n')
        {
            s.push(next);
            cin.get(next);
        }
        cout << "Written backward that is : ";
        while (! s.empty())
            cout <<s.pop();
            cout << endl;
        cout << "Again?(y/n)";
        cin >> ans;
        cin.ignore(10000,'\n');
        
    }while (ans != 'n' && ans != 'N');
    return 0;
}  

// 13.19 Implementation of the Stack Class
#include <iostream>
#include <cstdlib>
#include <cstddef>
#include 'stack.h'
using namespace std;
namespace stacksavitch
{
    Stack::Stack() :top(NULL)
    {
        
    }
    Stack::Stack(const Stack &a_stack)
    {
        if (a_stack.top == NULL)
        {
            top = NULL;
        }
        else
        {
            StackFramePtr temp = a_stack.top;
            StackFramePtr end;
            end = new StackFrame;
            end->data = temp->data;
            top = end;
            temp = temp->link;
            while (temp != NULL)
            {
                end->link = new StackFrame;
                end = end->link;
                end->data = temp->data;
                temp = temp->link;
            }
            end->link = NULL;
        }
    }   
    Stack::~Stack()
    {
        char next;
        while(!empty())
        {
            next = pop();
        }
    }
    
    bool Stack::empty() const
    {
        return (top==NULL);
    }
    void Stack::push(char the_symbol)
    {
        StackFramePtr temp_ptr;
        temp_ptr = new StackFrame;
        temp_ptr->data = the_symbol;
        temp_ptr->link = top;
        top = temp_ptr;
    }
    char Stack::pop()
    {
        if (empty())
        {
            cout << "Error:popping an empty stack.\n";
            exit(1);
        }
        char result = top->data;
        StackFramePtr temp_ptr;
        temp_ptr = top;
        top = top->link;
        delete temp_ptr;
        return result;
    }
}

// mainTogether
#include <iostream>
#include <cstdlib>
#include <cstddef>
namespace stacksavitch
 {
     struct StackFrame
     {
         char data;
         StackFrame* link;
     };
     typedef StackFrame* StackFramePtr;

     class Stack
     {
       public:
         Stack();
         // copy constructor
         Stack(const Stack &a_stack);
         ~Stack();
         void push(char the_symbol);
         char pop();
         bool empty() const;
       private:
         StackFramePtr top;
     };
  }

  using namespace std;
using namespace stacksavitch;

int main()
{
    Stack s;
    char next, ans;
    do
    {
        cout << "Enter a word: ";
        cin.get(next);
        while(next != '\n')
        {
            s.push(next);
            cin.get(next);
        }
        cout << "Written backward that is : ";
        while (! s.empty())
            cout <<s.pop();
            cout << endl;
        cout << "Again?(y/n)";
        cin >> ans;
        cin.ignore(10000,'\n');

    }while (ans != 'n' && ans != 'N');
    return 0;
}

using namespace std;
namespace stacksavitch
{
    Stack::Stack() :top(NULL)
    {

    }
    Stack::Stack(const Stack &a_stack)
    {
        if (a_stack.top == NULL)
        {
            top = NULL;
        }
        else
        {
            StackFramePtr temp = a_stack.top;
            StackFramePtr end;
            end = new StackFrame;
            end->data = temp->data;
            top = end;
            temp = temp->link;
            while (temp != NULL)
            {
                end->link = new StackFrame;
                end = end->link;
                end->data = temp->data;
                temp = temp->link;
            }
            end->link = NULL;
        }
    }
    Stack::~Stack()
    {
        char next;
        while(!empty())
        {
            next = pop();
        }
    }

    bool Stack::empty() const
    {
        return (top==NULL);
    }
    void Stack::push(char the_symbol)
    {
        StackFramePtr temp_ptr;
        temp_ptr = new StackFrame;
        temp_ptr->data = the_symbol;
        temp_ptr->link = top;
        top = temp_ptr;
    }
    char Stack::pop()
    {
        if (empty())
        {
            cout << "Error:popping an empty stack.\n";
            exit(1);
        }
        char result = top->data;
        StackFramePtr temp_ptr;
        temp_ptr = top;
        top = top->link;
        delete temp_ptr;
        return result;
    }
}


// Queues need a pointer at both head and the end of the linked list
// 13.21 Interface for a Queue Class
#ifndef QUEUE_H
#define QUEUE_H
namespace queuesavitch
{
    struct QueueNode
    {
        char data;
        QueueNode* link;
    };
    typedef QueueNode* QueueNodePtr;
    class Queue
    {
      public:
        Queue();
        Queue(const Queue &aQueue);
        ~Queue();
        void add(char item);      
        char remove();
        bool empty() const;
      private:
        QueueNodePtr front;
        QueueNodePtr back;
    };
    
}
#endif

//13.22 Program Uisng the Queue Class
#include <iostream>
#include "queue.h"
using namespace std;
using namespace queuesavitch;

int main()
{
    Queue q;
    char next, ans;
    
    do
    {
        cout << "Enter a word: ";
        cin.get(next);
        while(next != '\n')
        {
            q.add(next);
            cin.get(next);
        }
        cout << "You entered : ";
        while (! q.empty())
            cout <<q.remove();
        cout << endl;
        cout << "Again?(y/n)";
        cin >> ans;
        cin.ignore(10000,'\n');

    }while (ans != 'n' && ans != 'N');
    return 0;
}

// 13.23 Implementation of the Queue Class
#include <iostream>
#include <cstdlib>
#include <cstddef>
#include "queue.h"
using namespace std;
namespace queuesavitch
{
    Queue::Queue() :front(NULL), back(NULL)
    {
        
    }
    Queue::Queue(const Queue &aQueue)
    {
        if(aQueue.empty())
        {
            front=back=NULL;
        }
        else
        {
            // create the first node pointing both front and back to it
            // temp_ptr_old is the pointer iterating through the whole aQueue
            QueueNodePtr temp_ptr_old = aQueue.front;
            QueueNodePtr temp_ptr_new;
            back = new QueueNode;
            back->data = temp_ptr_old->data;
            back->link = NULL;
            front = back;
            temp_ptr_old = temp_ptr_old->link;
            while(temp_ptr_old != NULL)
            {
                // create the followed ones
                // temp_ptr_new iterating the new queue
                temp_ptr_new = new QueueNode;
                temp_ptr_new->data = temp_ptr_old->data;
                temp_ptr_new->link = NULL;
                // make the 1 pointing to the newly-created 2
                back->link = temp_ptr_new;
                // then point back to 2
                back = temp_ptr_new;
                temp_ptr_old = temp_ptr_old->link;
            }
        }
    }
    Queue::~Queue()
    {
        char next;
        while(!empty())
        {
            next = remove();
        }
    }
    bool Queue::empty() const
    {
        //front == NULL also works
        return (back==NULL);
    }
    void Queue::add(char item)
    {
        if(empty())
        {
            front = new QueueNode;
            front->data = item;
            front->link = NULL;
            back = front;
        }
        else
        {
            QueueNodePtr temp_ptr;
            temp_ptr = new QueueNode;
            temp_ptr->data = item;
            temp_ptr->link = NULL;
            // adding at the end/back
            back->link = temp_ptr;
            back = temp_ptr;
        }
    }
    char Queue::remove()
    {
        if(empty())
        {
            cout << "Error: Removing an item from an empty queue.\n";
            exit(1);
        }
        // FIFO, take out the front one
        char result = front->data;
        QueueNodePtr discard;
        discard = front;
        front = front->link;
        if(front == NULL)
            back = NULL;;
        delete discard;
        return result;
    }   
}

//mainTogether
#include <iostream>
#include <cstdlib>
#include <cstddef>
namespace queuesavitch
{
    struct QueueNode
    {
        char data;
        QueueNode* link;
    };
    typedef QueueNode* QueueNodePtr;
    class Queue
    {
      public:
        Queue();
        Queue(const Queue &aQueue);
        ~Queue();
        void add(char item);
        char remove();
        bool empty() const;
      private:
        QueueNodePtr front;
        QueueNodePtr back;
    };

}

using namespace std;
using namespace queuesavitch;

int main()
{
    Queue q;
    char next, ans;

    do
    {
        cout << "Enter a word: ";
        cin.get(next);
        while(next != '\n')
        {
            q.add(next);
            cin.get(next);
        }
        cout << "You entered : ";
        while (! q.empty())
            cout <<q.remove();
        cout << endl;
        cout << "Again?(y/n)";
        cin >> ans;
        cin.ignore(10000,'\n');

    }while (ans != 'n' && ans != 'N');
    return 0;
}

using namespace std;
namespace queuesavitch
{
    Queue::Queue() :front(NULL), back(NULL)
    {

    }
    Queue::Queue(const Queue &aQueue)
    {
        if(aQueue.empty())
        {
            front=back=NULL;
        }
        else
        {
            // create the first node pointing both front and back to it
            // temp_ptr_old is the pointer iterating through the whole aQueue
            QueueNodePtr temp_ptr_old = aQueue.front;
            QueueNodePtr temp_ptr_new;
            back = new QueueNode;
            back->data = temp_ptr_old->data;
            back->link = NULL;
            front = back;
            temp_ptr_old = temp_ptr_old->link;
            while(temp_ptr_old != NULL)
            {
                // create the followed ones
                // temp_ptr_new iterating the new queue
                temp_ptr_new = new QueueNode;
                temp_ptr_new->data = temp_ptr_old->data;
                temp_ptr_new->link = NULL;
                // make the 1 pointing to the newly-created 2
                back->link = temp_ptr_new;
                // then point back to 2
                back = temp_ptr_new;
                temp_ptr_old = temp_ptr_old->link;
            }
        }
    }
    Queue::~Queue()
    {
        char next;
        while(!empty())
        {
            next = remove();
        }
    }
    bool Queue::empty() const
    {
        //front == NULL also works
        return (back==NULL);
    }

    void Queue::add(char item)
    {
        if(empty())
        {
            front = new QueueNode;
            front->data = item;
            front->link = NULL;
            back = front;
        }
        else
        {
            QueueNodePtr temp_ptr;
            temp_ptr = new QueueNode;
            temp_ptr->data = item;
            temp_ptr->link = NULL;
            // adding at the end/back
            back->link = temp_ptr;
            back = temp_ptr;
        }
    }
    char Queue::remove()
    {
        if(empty())
        {
            cout << "Error: Removing an item from an empty queue.\n";
            exit(1);
        }
        // FIFO, take out the front one
        char result = front->data;
        QueueNodePtr discard;
        discard = front;
        front = front->link;
        if(front == NULL)
            back = NULL;;
        delete discard;
        return result;
    }

}
