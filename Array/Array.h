#include <iostream>
template <typename T>
class Array
{
private:
int count = 0;
T* tab = nullptr;
public:
Array() = default;
Array(int _pItem);
~Array();
public:
	void Display();
	void GetAt(int _pItem, T _pValue);
	void DeleteAt(int _pItem);
};

template<typename T>
 Array<T>::Array(int _pItem)
{
	count = _pItem;
	tab = new T[count];
}

 template<typename T>
 inline Array<T>::~Array()
 {
	 delete[] tab;
	 count = 0;
	 tab = nullptr;
 }
#pragma region Methode
 template<typename T>
 void Array<T>::Display()
 {
	 for (int _i = 0; _i < count; _i++)
	 {
		 std::cout << tab[_i] << std::endl;
	 }
 }

 template<typename T>
 void Array<T>::GetAt(int _pItem, T _pValue)
 {
	 tab[_pItem] = _pValue;
	 
	 
 }

 template<typename T>
  void Array<T>::DeleteAt(int _pItem)
 {
	  T* _tmp = tab;
	  int _oldCount = count;
	  count = _pItem;
	  tab = new T[count];
	  for (int i = 0; i < count && i < _oldCount; i++)
		  tab[i] = _tmp[i];
	  delete[] _tmp;
 }
#pragma endregion 