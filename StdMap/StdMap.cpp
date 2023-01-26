#include <iostream>
#include "Map.h"
#include <vector>
int main()
{
	Map<int, std::string> tab = Map<int, std::string>
	{
		{0, "Thomas"},
		{1, "Toto"},
		{2, "Toto"}
	};

	for (KeyValuePair<int, std::string> _pair : tab)
	{
		std::cout << _pair.Value() << std::endl;
	}
	

	return 0;
}
