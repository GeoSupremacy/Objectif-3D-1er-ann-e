#pragma once
#include "HashTable.h"


class MenuMap : public HashTable
{
#pragma region f/p
private:
	bool isNotExist = true;
#pragma endregion f/p
#pragma region constructor/destructor
public:
	MenuMap() = default;
#pragma endregion constructor/destructor
#pragma region methods
private:
	void DisplayAllMap()const;
	void SwitchMenu(const std::string _word);
	void Add();
	void Remove();
	bool Check(std::string _checkElement);
public:
	bool Home();
#pragma endregion methods

};

