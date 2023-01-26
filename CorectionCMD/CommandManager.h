#pragma once
#include "Singleton.h"
#include "ICommand.h"
#include <map>
class CommandManager : public Singleton<CommandManager>
{
#pragma region f/p
private:
	std::map<std::string, ICommand*> commands = std::map<std::string, ICommand*>();
#pragma endregion f/p
#pragma region C/D
public:
	CommandManager() = default;
	~CommandManager() override = default;
#pragma endregion C/D
#pragma endregion Methodes
public:
	void DisplayAllHelp() const;
	void DisplayNoRecognized(const std::string& _label);
	void DisplayHelp(const std::string& _label);
	void Register(ICommand* _command);
	void Register(const std::initializer_list<ICommand*>& _commands);
	void ExecutCommand(const std::string& _label, const std::vector<std::string>& _args);
#pragma endregion Methodes
};

