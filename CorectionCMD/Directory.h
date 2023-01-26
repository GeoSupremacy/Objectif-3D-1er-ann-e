#pragma once
#include "Object.h"
class Directory : public Object
{
public:
	static bool DirectoryExist(const std::string& _path);
};

