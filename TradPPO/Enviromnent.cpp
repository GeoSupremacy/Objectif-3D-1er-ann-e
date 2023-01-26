#include "Enviromnent.h"
#include <Windows.h>


std::string Enviromnent::CurrentDirectory()
{
	TCHAR buffer[MAX_PATH]; //TCHAR??
	GetCurrentDirectory(_MAX_PATH, buffer);//buffer?
	std::wstring _wstring = buffer;
	_wstring = _wstring.substr(0, _wstring.find_last_of(L"\\/"));//?substr
	return std::string (_wstring.begin(), _wstring.end());//
}
