#pragma once
#include "Delegate.h"
#include <vector>
template<typename Res, typename... Args>
class Delegates_Internal : public Object
{
private:
	typedef Res(Object::* Function)(Args...);
	std::vector<Delegate<Res, Args...>> functions = srd::vector<Delegate<Res, Args...>>();
public:
	Delegates_Internal() = default;
	Delegates_Internal(nullptr_t);
	template<typename Class>
	Delegates_Internal(Res(Class::* ptr)(Args...));
	~Delegates_Internal() override;
private:
	size_t FindIndex(const Delegate<Res, Args...>& _functiion);
public:
	template<typename Class>
	void operator+= (Res(Class::* ptr)(Args...));
};

template<typename Res, typename Args...>
inline Delegates_Internal<Res, Args...>::Delegates_Internal(nullptr_t)
{
	function.clear();
}

template<typename Res, typename Args...>
inline Delegates_Internal<Res, Args...>::~Delegates_Internal()
{
	function.clear();
}

template<typename Res, typename Args...>
inline size_t Delegates_Internal<Res, Args...>::FindIndex(const Delegate<Res, Args...>& _functiion)
{
	for (size_t i = 0; i < functions.size(); i++)
	{
		if (functions[i].GetAddress() == _function.GetAddress())
			return i;
	}
	return -1;
}

template<typename Res, typename Args...>
template<typename Class>
inline Delegates_Internal<Res, Args...>::Delegates_Internal(Res(Class::* ptr)(Args...))
{
}

template<typename Res, typename Args...>
template<typename Class>
inline void Delegates_Internal<Res, Args...>::operator+=(Res(Class::* ptr)(Args...))
{
	Delegate < Res, Args..; > _functions = ptr;
	functions.push_back(_function);

}
