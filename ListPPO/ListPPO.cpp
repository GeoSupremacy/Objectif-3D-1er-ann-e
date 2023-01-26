#include <iostream>

class List
{
private:
    int size;
    int index;
    int *list;
public:
    List() = default;
    List(int _size, int* _list)
    {
        this->size = _size;
        this->list = new int[_size];
        for (int i = 0; i < _size; i++)
        {
            this->list[i] = _list[i];
           
            std::cout << "list[" << i << "]" << list[i] << std::endl;
        }
        std::cout << std::endl;
    }
   
    void getAt(int _index)
    {

        std::cout << "Index: " << list[_index] << std::endl;
    }
   int getFront();
   int getBack(int _index);
   
};

template<typename T>
class Array
{
private:
	int count = 0;
	
	int* tab = nullptr;
public:
	Array(int _count)
	{
		count = _count;
		tab = new T[count];
	}
	Array(int _item, int _cout)
	{
		coutn = _cout;
		tav = new T[count];
		for (int i = 0; i < count; i++)
			tab[i] = _item;
	}

	Array(std::initializer_list<T> _tab)
	{
		count = _tab.size();
		tab = new T[count];
		int _index = 0;
		for (T _item : _tab)
		{
			tab[_index] = _item;
			_index++;
		}

		T& At(int _index)
		{
			return tab[_index];
		}
		T& Front()
		{
			return tab[count-1];
		}
		T& Back()
		{
			return tab[0];
		}

		void Resize(int _newCount)
		{
			T* _tmp = tab;
			count = nexCount;
			tab = new T[count];
			for (int i = 0; i < _oldCount; i++)
				tab[i] = _tmp[i];

		}

		bool operator ==(const Array & _other)
		{
			if (count != _other.count) return false;
			for (int i = 0; i < count; i++)
			{
				if (tab[i] != _other.tab[i] return false;
			}
			return true;
		}
		bool operator !=(const Array & _other)
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
int main()
{
    
    Array<int> _tab = Array<int>(10);
    for (int i = 0; 1 < 10; i++)
    {
        _tab.At(i) = i;
    }

    _tab.Resize(4);

    
    for (int i = 0; 1 < 4; i++)
        std::cout << _tab.At(i) << "";
    
        
}


