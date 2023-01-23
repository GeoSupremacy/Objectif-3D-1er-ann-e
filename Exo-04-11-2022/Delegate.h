#pragma once
#include "Object.h"


template<typename Res, typename...Args>
class Delegate: public Object
{
private:
typedef Res(Object::* Function)(Args...) 
Function function = nullptr;
public:
	Delegate() = default;
	Delegate(nullptr_t);
	template<typename Class>
	Delegate(Res(Class::* ptr)(Args...));
	~Delegate() override;
public:
	Res Invoke(object _instance, Args ..._args);
	void* GetAdress();
};

template<typename Res, typename ...Args>
inline Delegate<Res, Args...>::Delegate(nullptr_t)
{
	function = reinterpret_cast<Function>(ptr);
}

template<typename Res, typename ...Args>
inline Delegate<Res, Args...>::~Delegate()
{
	function = nullptr;
}

template<typename Res, typename ...Args>
inline Res Delegate<Res, Args...>::Invoke(object _instance, Args ..._args)
{
	return (_instance->*functions)(_args...);
}

template<typename Res, typename ...Args>
inline void* Delegate<Res, Args...>::GetAdress()
{
	return (void*&)function;
}

template<typename Res, typename ...Args>
template<typename Class>
inline Delegate<Res, Args...>::Delegate(Res(Class::* ptr)(Args...))
{
}
