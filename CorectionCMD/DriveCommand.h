#pragma once
#include "ICommand.h"
class DriveCommand : public ICommand
{
public:
	DriveCommand() = default;
	~DriveCommand() = default;
public:
	virtual bool Execute(const std::vector<std::string>& _args) override;
	virtual std::string CommandName() const override;
	virtual std::string Help() const override;
	virtual std::string AdvaceHelp() const override;
};

