#include<string>
#include <iostream>
#include "Object.h"

#define color_white 15
#define color_red 4
#define color_yellow 14
class Utils
{
public:
	static void Log(const std::string& _str);
	static void Log(const Object& _str);
	static void Log(const Object* _str);
	static void DebugLog(const std::string& _str);
	static void DebugLog(const Object& _str);
	static void DebugLog(const Object* _str);
	static void LogWarning(const std::string& _str);
	static void LogWarning(const Object& _str);
	static void LogWarning(const Object* _str);
	static void LogError(const std::string& _str);
	static void LogError(const Object& _str);
	static void LogError(const Object* _str);
public:
	template<typename T>
	static T UserChoise(const std::string& _msg);
	static std::string UserStringChoise(const std::string& _msg);
	static void LogSeparator(const int count = 10);
	static std::string UnderLine(const std::string _str);
	static void UnderLineAndDiplay(const std::string& _str);
	static void LogTitle(const std::string& _title);
	static void ClearConsole();
	static void Pause();
};

