#include <iostream>
#include "String.h"


int main()
{
	String _str = "Hello World";
	std::cout << _str.SubString(0, _str.FirstIndexof('H'));
}

