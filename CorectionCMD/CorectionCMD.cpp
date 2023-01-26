#include <iostream>
#include "CommandManager.h"
#include "Assembly.h"
#include "Utils.h"
#include <windows.h>
int main()
{
	SetConsoleTitle(L"Command Prompt");
	
	std::string _command = "", _label ="";
	std::cout << "Microsoft Windows [version" + Utils::GetWindowsVersion()  + "]" <<std::endl;
	std::cout << "(c) Microsoft Corporation All rights reserved" << std::endl << std::endl;
	while (true)
	{
		std::cout << CdCommand ::CurrentPath<<'>';
		std::getline(std::cin, _command);
		if (_command == "") continue;
		std::vector<std::string> _arguments = Utils::GetArguments(_command, _label);
		CommandManager::Instance()->ExecutCommand(_label, _arguments);
	}
}

