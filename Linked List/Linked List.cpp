#include <iostream>
#include "Node.h"
#include "List.h"

//new  allouer de la m�moire
//delete rendre la m�moire
int main()
{
	List<int> _list = List<int>();
	_list.AddLast(0);
	_list.AddLast(1);

	try
	{
		_list.At(10);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}

