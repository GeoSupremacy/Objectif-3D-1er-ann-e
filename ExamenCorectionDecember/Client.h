#pragma once
#include "Object.h"


class Client :public Object
{
	DECLARE_CLASS_INFO(Object)
#pragma region f/p
private:
	std::string firstName = "";
	std::string lastName = "";
#pragma endregion f/p
#pragma region constructor/destructor
public:
	Client() = default;
	Client(const std::string& _firstName, const std::string& _lastName);
	Client(Client& _copy);
#pragma endregion constructor/destructor
#pragma region methods
public:
	std::string FirstName() const;
	std::string LastName() const;
#pragma endregion methods

};

