#include "Array.h"

void Array::Size(std::string _pHelloWorld)
{
	int _size = _pHelloWorld.size();
	int _size2 = _pHelloWorld.size()-1;
	for (int i = 0,  y = _size2; i < _size, y > -1; i++, y--)
	{
		
		std::cout << _pHelloWorld[i] <<"  "<<  _pHelloWorld[y] << std::endl;;
		
		

		
	}
	
	
}
