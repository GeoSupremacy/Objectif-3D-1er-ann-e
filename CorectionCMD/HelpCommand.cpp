#include "HelpCommand.h"
#include "CommandManager.h"
bool HelpCommand::Execute(const std::vector<std::string>& _args)
{
    
         CommandManager::Instance()->DisplayAllHelp();
       
    
    CommandManager::Instance()->DisplayHelp(_args[0]);
    return true;
}

std::string HelpCommand::CommandName() const
{
    return "help";
}

std::string HelpCommand::Help() const
{
    return "Provides help information for windows commands.";
}

std::string HelpCommand::AdvaceHelp() const
{
    return std::string();
}
