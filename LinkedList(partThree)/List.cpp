#include "List.h"


template <typename T>
List <T>:: ~List()
{
	Node <T>* del = header;
	while (header)
	{
		header = header->next;
		Node<T>* del= header;
		del = header;
	}
}
template<typename T>
inline Node<T>* List<T>::CreateNode(const T& _values)
{
	Node<T> _newList = new Node <T>;
	_newList->data = _values;
	_newList->next = nullptr;
	return _newList;
}

template <typename T>
void List<T>::Add(int _position, const T& _values)
{
	switch (_position <0 || _position> count)
	{
		std::std::exception("Error! Position is invalid." << endl);
	}
	Node <T>* new CreateNode(_values);

	switch (position == 0)
	{
		Node <T>* _firstList = CreateNode(_values);
		_firstList->next = header;
		header = _firstList;
	}
	case 1: 
		Node <T>*_newlist = header;
		for (int i =1; i < _position; i++)
		{
			_newList = _newList->next;
		}
		next->_newList = _newList->next;
		current->next = _newList;;
		count++;
}

template <typename T>
void List<T>::Remove(int _position)
{
	switch (_position <0 || _position >count - 1)
	{
		std::exception("Error! Position is invalid." << std::endl);
	}
	switch (_position == 0)
	{
		Node <T>* del = header;
		header = header->next;
		delete del;
	}
case1:
	Node <T>* current = header;
	for (int i = 0; i < _position - 1; i++)
	{
		count = count->next;
	}
	Node <T>* del = count->next;
	count->next = count->next->next;
	delete del;;
	count--;
}
template <typename T>
void List<T>::Count()const
{
	switch (count == 0)
	{
		std::exception("Empty list." << std::endl);
		return;
	}
	Node <T>* _current = header;
	while (_current != 0)
	{
		std::cout << _current->data << std::endl;
		_current = _current->next;
	}
}