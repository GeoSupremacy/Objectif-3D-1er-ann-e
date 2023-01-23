#pragma once
#include <vector>
#include "Exception.h"
class Object;

template<typename ... T>
class Action
{

private:
	typedef void (Object::* Function)(...T);
	std::vector<Function> functions = std::vector<Function>();
public:
	Action(nullptr_t);
	template<typename Class>
	Action(void(Class::* _ptr)(...T));
	~Action();
public:
	void Invoke(Object* _instance, ...T _value);
public:
	template<typename Class>
	void operator+=(void(Class::* _ptr)(...T));
	template<typename Class>
	void operator-=(void(Class::* _ptr)(...T));
	template<typename Class>
	void operator=(void(Class:: *_ptr)(...T));
	void operator=(nullptr_t);
};
#pragma region C/D
template<typename ... T>
template<typename Class>
inline Action<...T>::Action(void(Class::* _ptr)(T))
{
	functions.push_back(reinterpret_cast<Function>(_ptr));
}
template<typename T>
inline Action<...T>::Action(nullptr_t)
{
	functions.clear();
}
template<typename ...T>
inline Action<...T>::~Action()
{
	functions.clear();
}
#pragma endregion C/D
#pragma region Methode
template<typename T>
inline void Action<T>::Invoke(Object* _instance, T _value)
{
	for (size_t i = 0; i < functions.size(); i++)
	{
		(_instance->*functions[i])(_value);
	}
}

#pragma endregion Methode
#pragma region Operator
template<typename ...T>
template<typename Class>
inline void Action<...T>:: operator-=(void(Class::* _ptr)(...T))
{
	Function _function = reinterpret_cast<Function>(_ptr);
	for (size_t i = 0; i < functions.size(); i++)
	{
		if (functions[i] == _function)
		{
			functions.erase(functions.begin() + i);
			return;
		}
		
	}
}
template<typename ...T>
template<typename Class>
inline void Action<...T>:: operator+=(void(Class::* _ptr)(...T))
{
	
	
	functions.push_back(reinterpret_cast<Function>(_ptr));
			
	
}
template<typename ...T>
template<typename Class>
inline void Action<...T>:: operator=(void(Class::* _ptr)(...T))
{
	functions.clear();
	functions.push_back(reinterpret_cast<Function>(_ptr));

}
template<typename ...T>
inline void Action<T...>::operator=(nullptr_t)
{
	functions.clear();
}
#pragma endregion Operator