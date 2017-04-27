#ifndef _STACK_H_
#define _STACK_H_

#include "linkedlist.h"
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

#endif