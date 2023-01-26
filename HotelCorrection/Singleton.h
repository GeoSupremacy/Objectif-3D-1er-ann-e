#include "Object.h"

template<typename T>
class Singleton : public Object
{
private:
	static inline T* instance = nullptr;

public:
	Singleton() = default;
	~Singleton() override
	{
		OnDestroy();
	}

public:
	virtual void Ondestroy() { }
	static T* Instance()
	{
		if (instance == nullptr)
			instance = new T();
		return instance;
	}

};
