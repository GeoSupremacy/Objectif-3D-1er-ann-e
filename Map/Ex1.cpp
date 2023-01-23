#include "Ex1.h"


#pragma region methods
void Map1::Display()const
{
	for (auto it = map1.begin(); it != map1.end(); it++)
	{
		std::cout << (*it).first << "  " << (*it).second << std::endl;
	}
}
void Map1::InsertNewKey(const char _key, const int _value)
{
	map1.insert({ {_key,_value} });
}
void Map1::Remove(const char _key)
{
	auto _find = map1.find(_key);
	if (_find != map1.end())
	{
		std::cout << "Key delete" << std::endl;
		map1.erase(_key);
	}
	else
	{
		std::cout << "The key doesn't exist!" << std::endl;
	}
}
void Map1::Modify(const char _key, const int _value)
{
	auto _find = map1.find(_key);
	
	if (_find != map1.end())
	{
		std::cout << "New value in: " << _key<<std::endl;
		map1.at(_key) = _value;
	}
	else
	{
		std::cout << "The key doesn't exist!" << std::endl;
		
	}
	
}
void Map1::Verify(const char _key) const
{
	auto _tempmap = map1;
	if (map1.count(_key) > 0)
	{
		std::cout << "The key " << _key <<" exist and content: "<< _tempmap[_key] << std::endl;
	}
	else
	{
		std::cout << "The key " << _key << " doesn't exist." << std::endl;
	}
}
bool Map1::IsEmpty() const
{
	return map1.empty();
}
void Map1::Size() const
{
	std::cout << map1.size() << std::endl;
}
#pragma endregion methods
