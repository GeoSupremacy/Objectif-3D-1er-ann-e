#pragma once
#include "Object.h"

class IGame : public Object
{
	CLASS_INFO(Interface)
	DECLARE_CLASS_INFO(Object)
public:
	 void Test() override
	{
		 std::cout << "IGame Test" << std::endl;
	 }
};

