#include <iostream>
#include <vector>
#include <algorithm>


#pragma region Correction
bool twosum(std::vector<int> _vector, const int _targetNumber) {
	int i = 0, j = _vector.size() - 1;
	std::sort(_vector.begin(), _vector.end());
	while (i < j) {
		if (_vector[i] + _vector[j] == _targetNumber) return true;
		else if (_vector[i] + _vector[j] > _targetNumber) j--;
		else i++;
	}
	return false;
}
#pragma endregion Correction
void TwoSum(const std::vector<int> _vector, const int _targetNumber) {

	bool IsrestSzero = true;
	bool IsAdd = false;
	int _temp = 0,_tempRest = 0;
	for (size_t i = 0; i < _vector.size(); i++)
	{
		if (IsAdd)
			break;
		else
			if (IsrestSzero)
				if (_targetNumber - _vector[i] > 0)
				{
					_tempRest =  _targetNumber - _vector[i];
					_temp = _vector[i];
					IsrestSzero = false;
				}
			else
				if (_vector[i] == _tempRest)
				{
					std::cout << _temp << "+" << _tempRest << "=" << _targetNumber << std::endl;
					IsAdd = true;
				}
	}
	if (!IsAdd)
		std::cout << "No found"<< std::endl;
}

int main()
{
	std::vector<int> tab = { 3, 7, 1 , -3, 2 };
	const int targetNumber  =5;

	TwoSum(tab, targetNumber);
	std::cout<<twosum(tab, targetNumber)<<std::endl;

	return 0;
}

#pragma region comment
/*Parcourir la liste en une fois pour additionner deux nombres dont le résultat et la cible sinon rien.
* [4, 7, 1 , -3, 2] and k = 5,
* Entrer un vector et une liste
* Parcourir la liste
* si la soustration de la cible et de l'élément est strictement supérieur à 0 alors
* prendre le résultat
* Chercher dans la liste
* si oui l'afficher sinon autre
*/
#pragma endregion comment