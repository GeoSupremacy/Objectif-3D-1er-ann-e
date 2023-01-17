#include <iostream>
#include <vector>
#include <string>
#pragma region Problem
/*Liste donne 3 unique nombre  
//Propriéter pour en créer une à chaque fois
*/
#pragma endregion Problem

std::vector<int> list = {};
void SortNums(std::string nums);
int temp =0;
void SortNums(std::string nums)
{
    
    for (int i =0; i<list.size();i++)
    {
        for (int j = 0; j < list.size() -1; j++)
        {
           
            
            if (list[j]> list[j +1])
            {
                temp = list[j];
                list[j] = list[j+1];
                list[j+1] = temp;
              
            }
        }
        std::cout << list[i];
        
    }
    
}
int main()
{
   // SortNums("123");
   /* std::string nums = "3";
    std::vector<int> _listTemp;
    for (int i = 0; i < nums.size(); i++)
    {
        int _a = int(nums[i]);
        list.push_back(rand() % _a);
        
       
    }
    while (true)
    {
        int _b = rand() % 3;
        std::cin >> temp;
        system("cls");
        std::cout << _b << std::endl;
    }*/
    int a = 0;
    int b = 5;
    for (int i=0; i<=b ;++i)
    {
        std::cout << i << std::endl;
    }
}

