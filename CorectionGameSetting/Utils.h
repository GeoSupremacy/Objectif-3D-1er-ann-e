#pragma once
#include "Object.h"
#include <string>
#include <windows.h>
#include <iostream>


#pragma warning(disable : 4996)

#define color_white 15
#define color_red 4
#define color_yellow 14

#define SPACE 32
#define ESCAPE 27

class Utils
{
private:
	static inline HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

	static inline COORD cursorPosition = {};
public:
	static void LogWithEffect(const std::string& _msg, const int _time = 10);
	static void Log(const std::string& _str);
	static void Log(const Object& _obj);
	static void Log(const Object* _obj);
	static void DebugLog(const std::string& _str);
	static void DebugLog(const Object& _obj);
	static void DebugLog(const Object* _obj);
	static void LogWarning(const std::string& _str);
	static void LogWarning(const Object& _obj);
	static void LogWarning(const Object* _obj);
	static void LogError(const std::string& _str);
	static void LogError(const Object& _obj);
	static void LogError(const Object* _obj);
	static void LogTitle(const std::string& _title);
	static void LoadingBar(const std::string& _msg);
public:
	static int Random(const int _min, const int _max);
	void SetWindowSize(const int _width, const int _height);
	static void Sleep(const int _milliSeconds);
	static int CinNoBlock()
	{
		if (kbhit())
		{
			return getch();
		}
		return -1;
	}
	static void SetCursor(const bool _visible, const int _size);
	static void SetCursorPosition(const int _x, const int _y);
	template<typename T>
	static T UserChoise(const std::string& _msg, const T& _defaultValue, const T& _a, const T& _b);
	template<typename T>
	static T UserChoice(const std::string& _msg );
	static std::string UserStringChoice(const std::string& _msg);
	static void LogSeparator(const int _count = 10);
	static std::string Underline(const std::string& _str);
	static void UnderlineAndDisplay(const std::string& _str);
	static void ClearConsole();
	static void Pause();
	
};


template<typename T>
inline T Utils::UserChoice(const std::string& _msg)
{
	if (_msg != "") Log(_msg);
	
		T _result = T();
		std::cin >> _result;
		std::cin.ignore(1000, '\n');
		return;
	
}

template<typename T>
inline T Utils::UserChoise(const std::string& _msg, const T& _defaultValue, const T& _a, const T& _b)
{
	T _result = T();
	T value = _defaultValue;
	while (value != _a && value != _b)
		std::cin >> _result;
	return _result;
}
