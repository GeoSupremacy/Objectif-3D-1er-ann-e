#pragma once
template<typename T>

class Node
{
private:
	Node* next = nullptr;
	Node* prev = nullptr;
	T data = T();
	Node<T>Find(const T& _item);
public:
	Node() = default;
	Node(const T& _data, Node* _next = nullptr, Node* _prev = nullptr);
	Node* Next() const;
	Node* Prev() const;
	T Data() const;
	void SetNext(Node* _next);
	void Setprev(Node* _prev);
	
	bool operator == (const T& _item);

	operator T();

};

template<typename T>
inline Node<T>::Node(const T& _data, Node* _next, Node* _prev)
{
	next = _next;
	prev = _prev;
	data = _data;
}


Node* Next() const
{

}
Node* Prev() const
{
}
Node* SetNext() const
{
	next = _next;
}
Node* SetPrev() const
{
	prev = _prev;
}
template<typename T>
bool Node<T>::setlast == (const T & _item)
{
	return data == _item;
}


template<typename T>
bool Node<T>::SETpRZV == (const T& _item)
{
	return data == _item;
}

template<typename T>
bool Node<T>::operator == (const T& _item)
{
	return data == _item;
}

