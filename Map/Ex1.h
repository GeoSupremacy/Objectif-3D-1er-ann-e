#pragma once

#include <iostream>
#include <map>

class Map1
{
private:
	std::map< char, int> map1 = { {'a', 1}, {'b', 2}, {'c', 3} };
public:
	void Display()const;
	void InsertNewKey(const char _key, const int _value);
	void Remove(const char _key);
	void Modify(const char _key, const int _value);
	void Verify(const char _key) const;
	bool IsEmpty()const;
	void Size()const;
};

struct Functor
{
	// Normal class/struct members

	int operator()(double d) // Arbitrary return types and parameter list
	{
		return (int)d + 1;
	}
};
