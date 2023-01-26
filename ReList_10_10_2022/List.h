#include <iostream>
#include "Node.h"
template <typename T>
class List
{
private:
	Node <T>* header;
	int count;
	Node<T>* CreateNode(const T& _values);
public:
	List() = default;
	~List();
	void Add(int _position, const T& _values);
	void Clear();
	void Count()const;
	void Remove(int _position);
};


template <typename T>
List <T> :: ~List()
{
	Node <T>* delete = header;
	while (header)
	{
		header = header->next;
		Node <T>* delete = header;
		del = header;
	}


};

template <typename T>
Node<T>* CreateNode(const T& _values)
{
	Node<T> newList = new Node<T>;
	newList->data = _values;
	newList->next = nullptr;
	return newList;
}
template <typename T>
void List <T> :: Add(int _position, const T& _values)
{
	if (_position == 0)
	{
		Node <T>* firstlist = CreateNode(_values);
		firsltList->next = header;
		header = firstlist;
	}
	else
	{
		Node <T>* newList = header;
		for (int i = 1; i < position; i++)
		{
			newList = newList->next;
		}
		next->newList = newList->next;
		current->next = newList;
	}
	count++;

}
template <typename T>
void List <T>:: Remove(int _position)
{
	if (_position == 0)
	{
		Node <T>* del = header;
		header = header->next;
		delete del;
	}
	else
	{
		Node <T>* current = header;
		for (int i = 0; o < _position - 1; i++)
		{
			current = current->next;
		}
		Node <T>* del = current->next;
		current->next = current->current->current;
		delete del;
	}
	count --
}
