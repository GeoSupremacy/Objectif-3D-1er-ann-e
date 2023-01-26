#pragma once
#include "Object.h"
template<typename T>
class Singleton : public Object
{
private:
	static inline T* instance = nullptr;
public:
	Singleton() = default;
	~Singleton()
	{
		OnDestroy();
		delete instance;
	}
public:
	static inline T* Instance()
	{
		if (instance == nullptr)
			instance = new T();
		return instance;
	}
protected:
	virtual void OnDestroy()
	{

	}
};