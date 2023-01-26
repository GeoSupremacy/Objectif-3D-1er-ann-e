#pragma once
#include "ICommand.h"
class ClsCommand : public ICommand
{
public:
	ClsCommand() = default;
	~ClsCommand() override = default;
public:
	 bool Execute(const std::vector<std::string>& _args) override;
	 std::string CommandName() const;
	 std::string Help() const override;
	 std::string AdvaceHelp() const override;
};

