#pragma once
#include "Object.h"
#include <vector>
class ICommand : public Object
{
#pragma region C/D
public:
	ICommand() = default;
	~ICommand() override = default;
#pragma endregion C/D
#pragma region Methods
public:
	virtual bool Execute(const std::vector<std::string>& _args) = 0;
	virtual std::string CommandName() const = 0;
	virtual std::string Help() const = 0;
	virtual std::string AdvaceHelp() const = 0;
#pragma endregion Methods
};
