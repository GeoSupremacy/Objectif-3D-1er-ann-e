#include <iostream>

template <typename T>
class Node
{
	T data;
	Node <T>* next;
};