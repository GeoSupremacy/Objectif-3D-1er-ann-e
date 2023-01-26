#pragma once
#include "Object.h" //"../../ClassObject/Object/Object.h"
#include <algorithm>
#include <vector>
#include <sstream>
class StringUtils : public Object
{
public:
	static std::string Replace(const std::string& _str, const char _old, const char _new);
	static bool Contains(const std::string& _str, const char _value);
	static std::vector<std::string> Split(const std::string& _str, const char _c);
};

