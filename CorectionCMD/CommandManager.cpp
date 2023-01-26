#include "CommandManager.h"
#include "ICommand.h"
#include <iostream>
#include <format>
#include <iomanip>
void CommandManager::DisplayAllHelp() const
{
	std::cout << "-------HELP-------" << std::endl;
	for (std::pair<const std::string, ICommand*> _command : commands)
	{
		if (_command.first == "" || _command.second == nullptr) continue;
		std::cout << std::setw(10) << st
	}
	std::cout << "------------------" << std::endl;
}

void CommandManager::DisplayHelp(const std::string& _label)
{
	if (!commands.contains(_label)
	{
		DisplayNoRecognized(_label);
			return;
	}
	std::cout<<commands[_label]->AdvancedHelp()<<std::endl;
}
void CommandManager::Register(ICommand* _command)
{
	const std::string& _commandName = _command->CommandName();
	if (commands.contains(_command->CommandName()))
		throw std::exception(std::format("[Command Manager] => {} already exist !", _command->CommandName()).c_str());
	commands.insert(std::pair(_command->CommandName(), _command));
}
void CommandManager::Register(const std::initializer_list<ICommand*>& _commands)
{
	for (ICommand* _command : _commands)
		Register(_command);
}
void CommandManager::ExecutCommand(const std::string& _label, const std::vector<std::string>& _args)
{
	if (!commands.contains(_label))
	{
		DisplayNoRecognized(_label);
		return;

	}
	ICommand* _command = commands[_label];
	if (!_command->Execute(_args)) std::cout << _command->Help() << std::endl;
	else std::cout << std::endl << std::endl;
}
void CommandManager::DisplayNoRecognized(const std::string& _label)
{
	std::cout << "\'" << _label << "\'" << "is not recognized as an internal command" << std::endl;
}