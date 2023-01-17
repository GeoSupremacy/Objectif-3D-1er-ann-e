#include <iostream>
#include <vector>
#include <stdlib.h>
void Sorted();
void Vector(int _value);
void ToString();
std::vector<int>sorted;

void ToString()
{
    std::cout << "List: " << std::endl;
   
    for (int i = 0; i < sorted.size(); i++)
    {
        std::cout << sorted[i] << " ";
    }
    std::cout << std::endl;
}
void Vector(int _value) {
    srand(time(0));
  
    for (int i = 0; i <= _value; i++)
    {

        int number = rand() % 100;
        sorted.push_back(number);
        
    }
   

}
void Sorted()
{
    /*

         for (int i = sorted.size() - 1; i > -1; i--)
     {
         for (int j = sorted.size(); j > 0; j--)
         {
             if (sorted[i] > sorted[j])
             {
                 int _a = sorted[i];
                 sorted[i] = sorted[j];
                 sorted[j] = _a;
             }
         }
     }
     }*/
    for (int i = 0; i < sorted.size(); i++)
    {
        for (int j = 1; j < sorted.size() - 1; j++)
        {
            if (sorted[i] > sorted[j])
            {
                int _a = sorted[i];
                sorted[i] = sorted[j];
                sorted[j] = _a;
            }
        }
    }
    for (int i = 0; i < sorted.size()-1; i++)
    {
        for (int j = sorted.size(); j > 0; j--)
        {
            int _a = sorted[i];
            sorted[i] = sorted[j];
            sorted[j] = _a;
        }
    }
}
int main()
{
   
    Vector(20);
    ToString();
    Sorted();
    ToString();
    std::cout << sorted[3] << " " << sorted[4] << " " << sorted[5] << " ";
}
 

