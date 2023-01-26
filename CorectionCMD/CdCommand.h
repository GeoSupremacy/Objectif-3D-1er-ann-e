#pragma once
#include "ICommand.h"
class CdCommand : public ICommand
{
#pragma region Methods
private:
	static std::string GetProfileFolder();
#pragma endregion Methods
#pragma region f
public:
	static inline std::string CurrentPath = GetProfileFolder();
#pragma endregion f
#pragma region c/D
public:
	CdCommand() = default;
	~CdCommand() override = default;
#pragma endregion  c/D
#pragma region override
public:
	virtual bool Execute(const std::vector<std::string>& _args) override;
	virtual std::string CommandName() const override;
	virtual std::string Help()const override;
	virtual std::string AdvaceHelp() const override;
#pragma endregion override
};

