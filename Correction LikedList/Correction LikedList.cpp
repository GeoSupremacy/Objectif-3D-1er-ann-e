#include <iostream>
#include "List.h"




int main()
{
	List<int> _list = List<int>();
	_list.AddLast(0);
	_list.AddLast(1);

	_list.Addafter(0, 5);
	_list.Addafter(5, 10);

	_list.Display();

	return 0;
}

