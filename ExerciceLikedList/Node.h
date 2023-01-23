#pragma once

template<typename T>
class Node
{
private:
	Node* nextNode = nullptr;
	Node* prevNode = nullptr;
	T data;
public:
	Node() = default;
	T NewNode(const T& _value);
};

template<typename T>
inline T Node<T>::NewNode(const T& _value)
{
	data = _value;
}
