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
	List() =default;
	~List();
	void Add(int _position, const T& _values);
	void Clear();
	void Count()const;
	void Remove(int _position);
	//RemoveAll(int _ position);
	//RemoveAt(int _position);
};

			
