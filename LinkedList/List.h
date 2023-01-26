#include <iostream>
template <typename T>
class List
{
private:
	T data;
	T* next = nullptr;
	T* header;
	int count;
	T* CreateNode(const T& _item);
public:
	List();
	~List();
	void Add(const T& _item);
	void Remove(int _position);
	void Display();

};

template<typename T>
inline List<T>::~List()
{
	T* del = header;
	while (header)
	{
		header = header->next;
		delete del;
		del = header;
	}
}

template<typename T>
inline T* List<T>::CreateNode(const T& _item)
{
	T* _newItem = new T;
	_newItem->data = _item;
	_newItem->next = nullptr;
	return _newItem;
}

template<typename T>
inline void List<T>::Add(const T& _item)
{
	T* _new = CreateNode(_item);
	if (_position == 0)
	{
		_new->next = header;
		header = _new;
	}
	else
	{
		T* _current = header;
		for (int i = 1; i < _position; i++)
		{
			_current = _current->next;
		}
		_new->next = _current->next;
		_current->next = _new;
	}
	count++;
}

template<typename T>
 void List<T>::Remove(int _position)
{
	delete _position;
}
template<typename T>
void List<T>:: Display()
{
	T* _current = header;
	std::cout << _current->data << std::endl;
}