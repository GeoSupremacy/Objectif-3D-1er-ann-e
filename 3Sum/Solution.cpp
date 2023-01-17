#include "Solution.h"
#include <iostream>


#pragma region methods
void Solution::StockInTabActu(const std::vector<int> _tab)
{
	for (int i = 0; i < _tab.size(); i++) {
		tabActu.push_back(i);
	}
}
void Solution::Browse(const std::vector<int> _tab)
{
	for (int i = 0; i < _tab.size(); i++) {
		std::cout<<tabActu[i]<<" ";
	}
	
}
void Solution::Calculate()
{
}
void Solution::Display(std::vector<int> _tab) 
{
	StockInTabActu(_tab);
	Browse(_tab);
}
#pragma endregion methods
#pragma region operator

#pragma endregion operator


