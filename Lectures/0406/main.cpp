// inheritance
int main
{
	// base class references and pointers can be set to instancse of derived classes
    Employee* empPtr = new SalariedEmployee();
    
    vector<Employee *> staff;
    staff.push_back(new SalariedEmployee());
}

// protected only matters when you use inheritance
// protected can be accessed by derived class
// constructors are called from base to derived, destructors from derived to base
// properties are search for from derived to base 

// inheritance types: 
class Stack :private LinkedList
{
    public:
        void pop(pop_front();)
        void push(int data){push_front(int data);}
        int top(){return front();}
        // put :: scope resolutioto specify which class 
        bool empty(){return LinkedList::empty();}
}

template <class T>
class Stack<T> :private LinkedList<T>
{
	public:
		void pop() {pop_front();}
		void push(T data) {push_front(T data);}
		T top() {return front();}
		bool empty() {return LinkedList<T>::empty();}
}


class Queue :private LinkedList
{
	public:
		void dequeue() {pop_front();}
		void enqueue(int data){push_back(int data);}
		int front() {return LinkedList::front();}
		bool empty() {return LinkedList::empty();}
}
