/* 2 listes d'entier de même taille
* Une cible qui est un entier
* Afficher un tableau dont les collonnes sont les entiers d'un tableau trié pareil pour les lignes  
* Le croissement des collones et lignes sont le résultat d'addition de la collonne et ligne croisé
* Affiché en bleu les nombres plus petits que la cible
* en orange les nombres plus grands que la cible
* en rose les nombres qui sens rapproches
*
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <Windows.h>

void SetColor();
int size = 10;
std::vector<int> v1 = {4,2,1,3,8,9,6,3,5,8};
std::vector<int> v2 = {3,6,2,7,9,5,3,5,9,7};
int target = 8;
int a = 0;
void SetColor()
{
	if (a == target || a == target - 1 || a == target + 1)
	{
		const HANDLE _hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(_hConsole, 5);
	}
	else if (a > target)
	{
		const HANDLE _hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(_hConsole, 6);//6
	}
	else if (a < target)
	{
		const HANDLE _hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(_hConsole, 1);
	}
}
int main()
{
	
	std::sort(v1.begin(), v1.end());
	std::sort(v2.begin(), v2.end());//*
	while (true)
	{
		std::cout <<"   ";
		for (int i = 0; i < v1.size(); i++)//*
		{
			const HANDLE _hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(_hConsole, 7);
			std::cout << v2[i]<<"  ";
		}
		std::cout << std::endl;

		for (int i = 0; i < v1.size(); i++)//*
		{
			const HANDLE _hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(_hConsole, 7);
			std::cout << v1[i] << "  ";
			

			for (int y = 0; y < v2.size(); y++)//*
			{
				a = v1[i] + v2[y];
				SetColor();
				std::cout << a <<"  ";;
				



			}
			std::cout << std::endl;
			std::cout << std::endl;
		}
		
		std::cout << "target: ";
		std::cin >> target;
		system("cls");
	}
	
}

