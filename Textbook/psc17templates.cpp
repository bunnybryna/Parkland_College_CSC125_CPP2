// template prefix
template<class T>
each template parameter must be used in your template function
template<class T1, class T2>

// 17.1 A Function Template
#include <iostream>
using namespace std;

// not use declarations, just put definition before it is used
template<class T>
void swap_values(T& variable1, T& variable2)
{
	T temp;
	temp = variable1;
	variable1 = variable2;
	variable2 = temp;
}

int main()
{
	int integer1 = 1, integer2 = 2;
	cout << "Original integer values are " << integer1 << " "<< integer2 << endl;
	// you need not do anything special when call a function with a template
	swap_values(integer1, integer2);
	cout << "Swapped integer values are " << integer1 << " "<< integer2 << endl;

	char symbol1 = 'A', symbol2 = 'B';
	cout << "Original char values are " << symbol1 << " "<< symbol2 << endl;
	swap_values(symbol1, symbol2);
	cout << "Swapped char values are " << symbol1 << " "<< symbol2 << endl;

	return 0;
}

// 17.2 A Generic Sorting Function
#include <iostream>
using namespace std;


template<class T>
void swap_values(T& variable1, T& variable2)
{
	T temp;
	temp = variable1;
	variable1 = variable2;
	variable2 = temp;
}

template<class BaseType>
int index_of_smallest(const BaseType a[], int start_index, int number_used)
{
	BaseType min = a[start_index];
	int index_of_min = start_index;
	for (int index = start_index+1;index<number_used;index++)
		if(a[index]<min)
		{
			min = a[index];
			index_of_min = index;
		}
	return index_of_min;
}

template<class BaseType>
void sort(BaseType a[],int number_used)
{
	int index_of_next_smallest;
	for(int index=0;index<number_used-1;index++)
	{
		index_of_next_smallest = index_of_smallest(a,index,number_used);
		swap_values(a[index],a[index_of_next_smallest]);
	}
}

int main()
{
	int i;
	int a[10]={9,8,7,6,5,1,2,3,0,4};
	cout << "Unsorted integers:\n";
	for(i=0;i<10;i++)
		cout << a[i]<< " ";
	cout << endl;
	sort(a,10);
	cout << "In sorted order the integers are:\n";
	for(i=0;i<10;i++)
		cout << a[i]<< " ";
	cout << endl;

	double b[5]={5.5,4.4,1.1,3.3,2.2};
	cout << "Unsorted doubles:\n";
	for(i=0;i<5;i++)
		cout << b[i]<< " ";
	cout << endl;
	sort(b,5);
	cout << "In sorted order the doubles are:\n";
	for(i=0;i<5;i++)
		cout << b[i]<< " ";
	cout << endl;

	char c[7]={'G','E','N','E','R','I','C'};
	cout << "Unsorted chars:\n";
	for(i=0;i<7;i++)
		cout << c[i]<< " ";
	cout << endl;
	sort(c,7);
	cout << "In sorted order the chars are:\n";
	for(i=0;i<7;i++)
		cout << c[i]<< " ";
	cout << endl;

	return 0;
}

// syntax for class templates
templatec<class T>
class Pair
{
public:
	Pair();
	Pair(T first_value, T second_value);
	void set_element(int position, T value);
	T get_element(int position)const;
private:
	T first;
	T second;
};

template<class T>
void Pair<T>::set_element(int position, T value)
{
	if (position == 1)
		first = value;
	else if (position == 2)
		second = value;
	else
	{
		cout << "Error: Illegal pair position.\n";
		exit(1);
	}
}

template<class T>
// note that before scope resolution operator is Pair<T>, after is simply Pair
Pair<T>::Pair(T first_value, T second_value) : first(first_value),second(second_value)
{
}

// 17.4 Interface for the Class Template GenericList
#ifndef GENERICLIST_H
#define GENERICLIST_H
#include <iostream>
using namespace std;

namespace listsavitch
{
	template<class ItemType>
	class GenericList
	{
	  public:
		GenericList(int max);
		~GenericList();
		int length()const;
		void add(ItemType new_item);
		bool full() const;
		void erase();
		friend ostream& operator<<(ostream& outs, const GenericList<ItemType>& the_list);
	  private:
		ItemType *item;
		int max_length;
		int current_length;
	};
}
#endif	

#include<iostream>
#include "genericlist.h"
#include "genericlist.cpp"
using namespace std;
using namespace listsavitch;

int main()
{
	GenericList<int> first_list(2);
	first_list.add(1);
	first_list.add(2);
	cout << "first_list = \n"
		<<first_list;
	GenericList<char> second_list(10);
	second_list.add('A');
	second_list.add('B');
	second_list.add('C');
	cout << "second_list =\n"
		<<second_list;
	return 0;	
}

#ifndef GENERICLIST_H
#define GENERICLIST_H
#include <iostream>
#include <cstdlib>
#include "genericlist.h"

using namespace std;
namespace listsavitch
{
	template<class ItemType>
	GenericList<ItemType>::GenericList(int max): max_length(max), current_length(0)
	{
		item = new ItemType[max];
	}

	template<class ItemType>
	GenericList<ItemType>::~GenericList()
	{
		delete []item;
	}
	template<class ItemType>
	int GenericList<ItemType>::length() const
	{
		return (current_length);
	}
	template<class ItemType>
	void GenericList<ItemType>::add(ItemType new_item)
	{
		if(full())
		{
			cout << "Error:adding to a full list.\n";
			exit(1);
		}
		else
		{
			item[current_length]=new_item;
			current_length = current_length+1;
		}
	}
	template<class ItemType>
	bool GenericList<ItemType>::full()const
	{
		return (current_length==max_length);
	}
	template<class ItemType>
	void GenericList<ItemType>::erase()
	{
		current_length=0;
	}
	template<class ItemType>
	ostream& operator<<(ostream& outs, const GenericList<ItemType>& the_list)
	{
		for(int i=0;i<the_list.current_length;i++)
			outs<<the_list.item[i]<<endl;
		return outs;
	}
}
#endif	

// complete program 
#include<iostream>
#include <cstdlib>

using namespace std;

namespace listsavitch
{
	template<class ItemType>
	class GenericList
	{
	  public:
		GenericList(int max);
		~GenericList();
		int length()const;
		void add(ItemType new_item);
		bool full() const;
		void erase();
		// codeBlock compiler needs different template class for friend function
		template <class T1>
		friend ostream& operator<<(ostream& outs, const GenericList<T1>& the_list);
	  private:
		ItemType *item;
		int max_length;
		int current_length;
	};
}



int main()
{
    using namespace listsavitch;
	GenericList<int> first_list(2);
	first_list.add(1);
	first_list.add(2);
	cout << "first_list = \n"
		<<first_list;
	GenericList<char> second_list(10);
	second_list.add('A');
	second_list.add('B');
	second_list.add('C');
	cout << "second_list =\n"
		<<second_list;
	return 0;
}

namespace listsavitch
{
	template<class ItemType>
	GenericList<ItemType>::GenericList(int max): max_length(max), current_length(0)
	{
		item = new ItemType[max];
	}

	template<class ItemType>
	GenericList<ItemType>::~GenericList()
	{
		delete []item;
	}

	template<class ItemType>
	int GenericList<ItemType>::length() const
	{
		return (current_length);
	}

	template<class ItemType>
	void GenericList<ItemType>::add(ItemType new_item)
	{
		if(full())
		{
			cout << "Error:adding to a full list.\n";
			exit(1);
		}
		else
		{
			item[current_length]=new_item;
			current_length = current_length+1;
		}
	}

	template<class ItemType>
	bool GenericList<ItemType>::full()const
	{
		return (current_length==max_length);
	}

	template<class ItemType>
	void GenericList<ItemType>::erase()
	{
		current_length=0;
	}

	template <class T1>
    ostream& operator<<(ostream& outs, const GenericList<T1>& the_list)
	{
		for(int i=0;i<the_list.current_length;i++)
			outs<<the_list.item[i]<<endl;
		return outs;
	}
}

		