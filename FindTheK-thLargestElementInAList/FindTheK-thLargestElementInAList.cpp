#include <iostream>
#include <algorithm>
#include <vector>


void findKthLargest(std::vector<int> _list, int _k)
{
    std::sort(_list.begin(), _list.end());
    std::cout << _list[_k] << std::endl;
}

int main()
{
   std::vector<int> list = { 3, 5, 2, 4, 6, 8 };

    

    findKthLargest(list, 3);
}

