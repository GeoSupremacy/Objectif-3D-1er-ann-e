#pragma once
#include "Node.h"

template<typename T>
class List
{
private:
	Node<T>* header = nullptr;
	int position;
	Node<T> CreateNode(const int _position, const T&_data);
public:
	List() = default;
};

template<typename T>
inline Node<T> List<T>::CreateNode(const int _position, const T& _data)
{
	if (_position <0 || _position > position +2)
		stc::cout <<"Position is invalid" <<std::endl;
	if (_position == 0)

		header = new Node;
	NewList.NewNode();
}
