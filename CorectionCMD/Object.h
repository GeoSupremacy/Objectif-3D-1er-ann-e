#pragma once
#include <string>
class Object
{
#pragma region C/D
public:
	Object() = default;
	virtual ~Object() = default;
#pragma endregion C/D

#pragma region Method
public:
	virtual std::string ToString() const;
	template<typename T>
	T* GetInterfacd() const;
#pragma endregion Method
};

template<typename T>
inline T* Object::GetInterfacd() const
{
	return dynamic_cast;
}
