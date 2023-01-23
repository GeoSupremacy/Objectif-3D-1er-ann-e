#include <iostream>
#include <string>

#define color_white 15
#define color_red 4
#define color_yellow 14
class Object;
class Utils
{
public:
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

	template<typename T>
	static T UserChoise(const std::string& _msg, const T& _defaultValue, const T& _a, const T& _b);
	template<typename T>
	static T UserChoice(const std::string& _msg);
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
	//std::cin.ignore(1000, '\n');
	return;

}

template<typename T>
inline T Utils::UserChoise(const std::string& _msg, const T& _defaultValue, const T& _a, const T& _b)
{
	T _value = _defaultValue;
	T _result;
	while (_value != _a && _value != _b)
	{
		std::cin >> _result;
	}
	return _result;
}
