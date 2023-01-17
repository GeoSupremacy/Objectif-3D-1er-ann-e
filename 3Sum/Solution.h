#pragma once
#include<vector>

class Solution
{
#pragma region f/p
private:
	 static const int size =3;
	 int tab[size];
	 std::vector<int> tabActu;
#pragma endregion f/p
#pragma region constructor/destructor
public:
	Solution() = default;
	Solution(const Solution&_copy) = default;
#pragma endregion constructor/destructor
#pragma region methods
private:
	void StockInTabActu(const std::vector<int> _tab);
	void Browse(const std::vector<int> _tab);
	void Calculate();
public:
	void Display(std::vector<int> _tab);
#pragma endregion methods
#pragma region operator
public:

#pragma endregion operator
};

