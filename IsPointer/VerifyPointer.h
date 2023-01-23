#pragma once
template <typename T>
class VerifyPointer
{
	//isPointer<int> //false
	//isPointer<int*> //true

private:
	T * t;
	isPointer = true;

public:
	VerifyPointer() = default;
public:
	void IsPointer(T _value)
	{
		if (_value == t)
			return isPointer;
		else
			return isPointer = false;
	}
};

