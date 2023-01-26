#include <iostream>
/*
void DisplayArray(int* _array, int _size)
{
	for (int i = 0; i < _size; i++)
	{
		std::cout << _array[i] << std::endl;

	}
}
int main()
{
	int x = 10;
	int y = 10;
	int** grid = new int* [y];

	for (int i = 0; i < y; ++i)
	{
		grid[i] = new int[x];
	}
	for (int i = 0; i < y; ++i)
	{
		grid[i] = new int[x];
		delete[] grid[i];
	}

	int number = 0;
	std::cin >> number;

	int* array = new int[number];

	for (int i = 0; i < number; i++)
	{
		array[i] = i;
	}
	DisplayArray(array, number);
	delete [] array;
}*/

int main()
{
	
	int twoTab[4][4];
	int number = 0;
	
	std::cin >> number;
	int** array = new int* [number];
	
	for (int i = 0; i < number; ++i)
	{
		array[number] = new int[number];
		std::cout << array[number] <<std::endl;
		delete[] array[i];
	}
	
	for (int i = 0; i < number; ++i)
	{
		array[i] = new int[number];
		
	}
	
	delete[] array;
	array = nullptr;


	
	
}

