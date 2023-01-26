#include <string>
#include <iostream>
#include "ScriptingSymbol.h"
class Utils
{
public:
	static void Log(const std::string& _msg)
	{
#ifdef DEBUG
		std::cout << "[LOG] =>" << _msg << std::endl;
#endif
	}
};

