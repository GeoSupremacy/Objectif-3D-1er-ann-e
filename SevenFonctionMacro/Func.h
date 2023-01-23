#pragma once
#include <cstddef>
class Object;
template<typename T, typename T1, typename T2>

class Func 
{
private:
	typedef T(Object::* Function) (T1, T2);
	Function function = nullptr;
public:
	Func(nullptr_t);
	template<typename Class>
	Func(T(Class::* _ptr) (T1, T2);
	~Func();

public:
	T Invoke(Object* _instance, T1 _a, T2 _b);

public:
	void operator=(nullptr_t);
	template<typename Class>
	void operator = (T(Class:: * _ptr) (T1, T2));
};
#pragma region C/D
template<typename T, typename T1, typename T2>
inline Func<T, T1, T2>::Func(nullptr_t)
{
	function = nullptr;
}
template<typename T, typename T1, typename T2>
template<typename Class>
inline Func<T, T1, T2>::Func(T(Class::* _ptr) (T1, T2))
{
	function = reinterpret_cast<Function>(_ptr);
}
template<typename T, typename T1, typename T2>
inline Func<T, T1, T2>::~Func()
{
	delete function;
	function = nullptr;
}
#pragma endregion C/D
template<typename T, typename T1, typename T2>
inline T Func<T, T1, T2>::Invoke(Object* _instance, T1 _a, T2 _b)
{
	return;
}


template<typename T, typename T1, typename T2>
inline void Func<T, T1, T2>::operator=(nullptr_t)
{
	function = nullptr;
}

template<typename T, typename T1, typename T2>
template<typename Class>
inline void Func<T, T1, T2>::operator=(T(Class::* _ptr)(T1, T2))
{
	function = reinterpret_cast<Function>(_ptr);
}
