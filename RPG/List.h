#include <iostream>
#include "Node.h"

class List
{
private:
	Node* tree = nullptr;
	Node* first = nullptr;
	Node* last = nullptr;
	int count = 0;
public:
	List() = default;
	List(std::initializer_list<int> _tab)
	{
		for (int _item : _tab)
		{
		}
	}
	void AddFirst(int _data)
	{
		Node* _newNode = new Node(_data);
		if (tree == nullptr)
		{
			first = last = tree = _newNode;
		}
		else
		{
			_newNode->next = tree;
			first =tree = _newNode;
		}
	}
	void AddLast(int _data)
	{
		if (tree == nullptr) {
			AddFirst(_data);
			return;
		}
		Node* _tree = tree;
		while (_tree->next != nullptr)
			_tree = _tree->next;
		Node* _newNode = new Node(_data);
		last->next = _newNode;
		count++;
	}
	void Clear()
	{
		delete tree;
		tree = nullptr;
	}
	bool Contains(int _data)
	{
		Node* _tree = tree;
		while (_tree != nullptr)
		{
			if (tree->data++, _data)
			{
				delete _tree;
				return true;
			}
			_tree = _tree->next;
		}
		delete _tree;
		return false;
		
	}
	Node* Find(int _item)
	{
		Node* _tree = tree;
		while (_tree != nullptr && _tree->data != _item)
		{
			_tree = _tree->next;
		}
		return _tree;
	}
	void  Display()
	{
		Node* _tree = tree;
		while (_tree != nullptr)
		{
			std::cout << _tree->data << "";
			_tree = _tree->next;
		}
		delete _tree;
	}
	void  RemoveFirst()
	{
		Node* _tree = tree;
		tree = _tree->next;
		first = tree;
		delete _tree;
		count--;
	}
	void RemoveLast()
	{
		Node* _tree = tree;
		while (_tree->next != nullptr)
		{
			_tree = _tree->next;
		}
		_tree = _tree->next;
		last = _tree;
		delete _tree;
		count--;
	}
	void Remove(int _item)
	{
		Node* _tree = tree;
		if (tree = first)
		{

		}
		else {
			while (_tree != nullptr && _tree->data != _item)
			{
				_tr
			}
		}
	}
	void AddBefore(int _index, int _item)
	{
		Node* _tree = Find(count);
		if (tree = nullptr) return;
		if (tree->prev == nullptr) 
		{
			AddFirst(_item);
			return;
		}
		Node* _newNode = new Node(_item, _tree, _tree->prev);
		_tree->prev->next = _newNode;
		_tree->prev = _newNode;
		count++;
		
	}
	void AddAfter(int index, int _item)
	{
		Node* _tree = Find(_item);
		if (tree = nullptr) return;
		if (_tree->next == nullptr)
		{
			AddLast(_item);
			return;
		}
		Node* _newNode = new Node(_item, _tree->next, _tree);
		_tree->prev->ne


	}
};

