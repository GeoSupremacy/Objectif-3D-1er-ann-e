#pragma once
#include "Object.h"
#include <source_location>

class Exception : public Object
{
#pragma region f/p
private:
	std::string error = "";
#pragma endregion f/p
#pragma region constructor
public:
	Exception(const std::source_location& _location );
	Exception(const std::string& _error, const std::source_location& _location = std::source_location::current());
#pragma enfregion constructor

public:
	std::string ToString() const override;
#pragma endregion override
};

