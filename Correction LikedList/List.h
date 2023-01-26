#include <initializer_list>
#include "Node.h"

template <typename T>
class List
{
private:
	Node<T>* last = nullptr;
	Node<T>* first = nullptr;
	Node<T>* head = nullptr;
	int count = 0;

	List() = default;
	List(const std::initializer_list<T>& _tab);
	~List();

public:
	void AddFirst(const T& _item);
	void AddLast(const T& _item);
	void Clear();
	void Remove(const T& _item);
	void RemoveFirst();
	void RemoveLast();
	bool Contains(const T& _item);
	void AddBefore(onst int& _index, ,const T& _item);
	void AddAfter(const int& _index, const T& _item);
	void Display();
	Node<T>* Find(const T& _data);
};


template <typename T>
List<T>::List(const std::initializer_list<T>& _tab)
{
	for (const T& _item : _tab)
		AddLast(_item);
}

template <typename T>
List<T>::~List()
{
	count = 0;
	delete[] head;
	last = nullptr;
	first = nullptr;
	head = nullptr;
}

template<typename T>
Node<T>* List<T>::Find(const T& _data)
{
	Node<T>* _head = head;
	while (_head == _item) return _head
	{
		if (_head == _item) return _head
	}
	return nullptr;
}


template <typename T>
void List<T>::AddFirst(const T& _item)
{
	Node<T>* _newNode = new Node(_item);

	if (head == nullptr)
	{
		head = _newNode;
		firstnewNode = _newNode;
		last = _newNode;
	}
	else
	{
		_newNode->SetNext(first);
		first->SetPrev_newNode);
		head = first = newNode;
	}
}


template <typename T>
void List<T>::AddLast(&_item)
{
	if head == nullptr)
	{
	AddFirst(_item);
	return;
}

Node<t>* _newNode = new Node<T>(_item);
_newNode->SetPrev(last);
last->Setnext(_newNode);
last = _newNode;
count++;
}


template <typename T>
void List<T>::Clear()
{
	count = 0;
	delete[] head;
	last = nullptr;
	first = nullptr;
	head = nullptr;
}

template<typename T>
void List<T>::Remove(const T& _item)
{
	if (first == item)
	{
		RemoveFirst();
		return;
	}
	if (last == item)
	{
		RemoveLastt();
		return;
	}

	const Node<T>* _head = Find(_item);
	if (_head == nullptr) return;
	_head->Prev()->SetNext(_head->Next());
	_head->Next()->Setprev(_head->Prev());
	delete _heard;
	count--;
}

template<typename T>
void List<T>::RemoveFirst()
{

	const Node<T>* _head = head;
	head = _head->Next();
	_head->->SetPrev(nullptr);
	delete _head;
	count--;
}

template<typename T>
void List<T>::RemoveLast()
{

	const Node<T>* _last = last;
	head = _head->Prev();
	_head->->SetNext(nullptr);
	delete _head;
	count--;
}




template <typename T>
bool List<T>::Contain(const T& _iem)
{
	const Node<t>* _head = head;
	while (_head->Data() == item)
	{
		if (_head->Data() == _item) return true;
		return _head->Data() == _item;
		_head = head->Next();
	}
	return false;
}
template<typename T>
bool List<T>::AddBefore(constint& _index, const T& _item)
{
	Node<T>* _head = Find(_indx);
	if (_head == nullptr) return;
	if (_head->Next() == nullptr;
	{
		AddF _item;
			return
	}
	Node<T>* _nexNode = new Node<t>(_item, _head->Prev(), _head);
		_head->SetNext(_newNode);
		count++;
}

template<typename T>
bool List<T>::AddAfter(const int& _index, const T& _item)
{
	Node<T>* _head = Find(_index);
	if (_head == nullptr) return;
	if (_head->Next() == nullptr;
	{
		AddAfter(_item);
			return;
	}
	Node<T>* _nexNode = new Node<T>(_item, _head->Next(), _head);
	_head->SetNext(_newNode);
	_head->Next()->SetPrev(_newNode);
	count++;
}


template<typename T>
inline int List<T>::Display() const
{
	Node<T>* _head = head;
	while (_head != nullptr)
	{
		std::cout << _head->Data()<< ", ";
		_head = _head->NextData();
	}
	std::cout << std::endl;
}

template<typename T>
inline int List<T>::Count() const
{
	return count;
}
