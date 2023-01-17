#include <iostream>
#include <vector>


std::vector<int> arr = { 34, -50, 42, 14, -5, 86 };

int MaxSubarraySum(std::vector<int> _arr)
{
    int size = _arr.size();
    int a,_result = 0;
    int _temp = 0;
    int _temp1 = 0;
    int j = 0;
    while (size > 0)
    {
       
        for (int i = j ; i < size; i++)
        {
            
                _temp += _arr[i];
            
           
        }
       /* for (int j = size-1; j >=0; j--)
        {

            _temp1 += _arr[j];


        }
        */
        if (_temp > _result)
        {
            _result = _temp;
        }
      
        _temp = 0;
        j++;
        size--;
    }
    
    return _result;
}

int main()
{
    std::cout << MaxSubarraySum(arr);
}
