#include "LinkedList.h"
#include "Node.h"
#include <iostream>
#include <string>
LinkedList::~LinkedList()
{
	delete head;
	head = nullptr;
}
void LinkedList::AddFirst(int _value)
{
	Node* newNode = new Node(_value);
	if (head == nullptr)
		head = newNode;
	else
	{
		newNode->next = head;
		head = newNode;

	}
}

void LinkedList::AddLast(int _value)
{
	if (head == nullptr)
		AddFirst(_value);
	else
	{
		Node* newNode = new Node(_value);
		Node* _temp = head;
		while (_temp->next != nullptr)
		{
			_temp = _temp->next;
		}
		_temp->next = newNode;
	}
}

void LinkedList::ShowList()
{
	Node* temp = head;
	while (temp != nullptr)
	{
		std::cout << temp->data << "-";
		temp = temp->next;
	}

}