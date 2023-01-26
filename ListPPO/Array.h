#include <iostream>
#include "ListPPO.cpp"
class Array
{
private:
	int count = 0;
	T* tab = nullptr;
public:
	Array(int _count)
	{
		count = _count;
		tav = new T[count];
	}
	Array(int _item, int _cout)
	{
		coutn = _cout;
		tav = new T[count];
		for (int i = 0; i < count; i++)
			tab[i] = _item;
	}

	Array(std:: initializer_list<T> _tab)
	{
		count = tab.size();
		tab = new T[count];
	    int _index = 0;
		for (T _item : _tab)
		{
			tab[_index] = false;
			_index++
		}

		T at(int _index)
		{
			return _tab;
		}
		T at(int _index)
		{
			return _tab;
		}
		T Back(int _index)
		{
			return _tab;
		}

		void Resize(int _newCount)
		{
			T* _tmp = tab;
			count = nexCount;
			tab = new T[count];
			for (int i = 0; i < _oldCount; i++)
				tab[i] = _tmp[i];

		}

		bool operator ==(const Array& _other)
		{
			if (count != _other.count) return false;
			for (int i = 0; i < count; i++)
			{
				if (tab[i] != _other.tab[i] return false;
			}
			return true;
		}
		bool operator !=(const Array& _other)
		{
			return !this->operator==(_other);
		}

		T& operator[](int _index)
		{
			return tab[_index];
			//returna(_index);
		}

		int Count()
		{
			return count;
		}
	}

};

