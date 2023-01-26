#include "Utils.h"
#include <iostream>
#pragma region Log
 void Utils::Log(const std::string& _str)
{
	std::cout << _str << std::endl;
}
 void Utils::Log(const Object& _str)
 {
	 std::cout << &_str << std::endl;
 }
 void Utils::Log(const Object* _str)
 {
	 std::cout << _str << std::endl;
 }
void Utils::DebugLog(const std::string& _str)
{
#ifdef DEBUG
	std::cout << "[LOG] =>" << _str << std::endl;
#endif
}

void Utils::DebugLog(const Object& _str)
{
}

void Utils::DebugLog(const Object* _str)
{
}

void Utils::LogWarning(const std::string& _str)
{
#ifdef DEBUG
	const HANDLE handler = getStHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(_handle, color_yellow);
		std::cout << "[Warning] =>" << _str << std::endl;
	SetConsoleTextAttribute(_handle, color_white);
#endif
}

void Utils::LogWarning(const Object& _str)
{
#ifdef DEBUG
	const HANDLE handler = getStHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(_handle, color_yellow);
	std::cout << "[Warning] =>" << _str << std::endl;
	SetConsoleTextAttribute(_handle, color_white);
#endif
}

void Utils::LogWarning(const Object* _str)
{
#ifdef DEBUG
	const HANDLE handler = getStHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(_handle, color_yellow);
	std::cout << "[Warning] =>" << _str.ToString() << std::endl;
	SetConsoleTextAttribute(_handle, color_white);
#endif
}

void Utils::LogError(const std::string& _str)
{
#ifdef DEBUG
	const HANDLE handler = getStHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(_handle, color_red);
	std::cout << "[Error] =>" << _str << std::endl;
	SetConsoleTextAttribute(_handle, color_white);
#endif
}

void Utils::LogError(const Object& _str)
{
}

void Utils::LogError(const Object* _str)
{
}


void Utils::LogSeparator(const int count)
{
	Log(std::string(count, '='));


}
#pragma endregion Log
std::string Utils::UserStringChoise(const std::string& _msg)
{
	if (_msg != "") Log(_msg);
	std::string _result = "";
	std::getline(std::cin, _result);
	std::cin.ignore();
	return _result;
}
std::string Utils::UnderLine(const std::string _str)
{
	std::string _result = "";
	int _tabCount = 0, _count = 0;
	for (char _c : _str)
	{
		if (_c == '\t')
		{
			_tabCount++;
			continue;
		}
		_count++;
	}
	return std::string(_tabCount, '\t') + std::string(_count, '_');
}
void Utils::UnderLineAndDiplay(const std::string& _str)
{
	Log(_str);
	Log(UnderLine( _str));

}
void Utils::LogTitle(const std::string& _title)
{
	UnderLineAndDiplay("\t\t" + _title);
}
void Utils::ClearConsole()
{
	system("cls");

}
void Utils::Pause()
{
	system("pause");
}
