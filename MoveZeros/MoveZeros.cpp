#include <iostream>
#include <vector>
class Solution
{
public:
	void moveZeros(std::vector<int> _nums)
	{
		
		for (int i = _nums.size()-1; i > 0; i--)
		{
			for (int j = i -1; j > 0; j--)
			{
				int _temp = 0;

				if (_nums[i] ==0)
				{
					_temp = _nums[i];
					/*std::cout << _temp << " " << _origin << " " << _lastNumber;
					std::cin >> _a;
					sizeof(_nums)
					system("CLS");*/
					_nums[i] = _nums[j];
					_nums[j] = _temp;
					_temp = 0;

				}
			}
		}

		for (int i = 0; i < _nums.size(); i++)
		{
			std::cout << _nums[i] << " ";
		}
	}
};

int main()
{
	Solution solution;
	std::vector<int> nums = { 0, 0, 0, 2, 0, 1, 3, 4, 0, 0 };
	solution.moveZeros(nums);


	
}
