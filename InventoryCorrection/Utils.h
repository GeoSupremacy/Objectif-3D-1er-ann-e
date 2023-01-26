#include <iostream>
class Utils
{
#pragma region methods
public:
	template<typename T>
	static T Clamp(const T& _value, const T& _min, const T& _max);
	template<typename T>
	static T UserChoise(const std::string& _msg);


	static void Log(const std::string& _msg);
#pragma endregion methods
};

template<typename T>
T Utils::Clamp(const T& _value, const T& _min, const T& _max)
{
	if (_value < _min) return _min;
	if (_value > _max) return _max;
	return _value;
}

template<typename T>
inline T Utils::UserChoise(const std::string& _msg)
{
	if (_msg != "") Log(_msg) ;
	T _result = T();
	std::cin >> _result;
	return _result;
	
}


