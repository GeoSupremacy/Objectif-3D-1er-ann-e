#include <iostream>
#include <initializer_list>

template<typename T>
class Array
{
private:
    int count = 0;
    T* tab = nullptr;
public:
    Array(int _count);
    Array(T _item, int _count);
    Array(std::initializer_list<T> _tab);
    int Resize(int _count);
    T& GetAt(int _index);
    T& GetFront();
    T& GetBack();
    void Display();
    bool operator[](int _index);
    bool operator==(const Array& _other);
    bool operator!=(const Array& _other);
};
template<typename T>
Array <T>::Array(int _count)
{
    count = _count;
    tab = new T[count];
}
template<typename T>
Array <T>::Array(T _item, int _count)
{
    count = _count;
    tab = new T[count];
    for (int i = 0; i < count; i++)
    {
        tab[i] = _item;
    }

}
template<typename T>
Array <T>::Array(std::initializer_list<T> _tab)
{
    tab = new T[_tab.size()];
    count = _tab.size();
    int index = 0;
    for (T _item : _tab)
    {
        tab[index] = _item;
        index++;
    }
}
template<typename T>
T& Array <T>::GetAt(int _index)
{
    return tab[_index];
}
template<typename T>
T& Array <T>::GetFront()
{
    return tab[count - 1];
}
template<typename T>
T& Array <T>::GetBack()
{
    return tab[0];
}
template<typename T>
 int Array <T>::Resize(int _count)
{
    T* _tempTab = tab;

    tab = new T[_count];
    for (int i = 0; i < count; i++)
    {
        tab[i] = _tempTab[i];
    }
    count = _count;
}
template<typename T>
void Array <T>::Display()
{
    for (int i = 0; i < count; i++)
    {
        std::cout << tab[i] << " " <<std::endl;
    }

}
template<typename T>
bool Array <T>::operator[](int _index)
{
    return tab[_index];
}
template<typename T>
bool Array <T>::operator==(const Array& _other)
{
    if (count != _other.count) return false;
    for (int i = 0; i < count; i++)
    {
        if (tab[i] != _other.tab[i]) return false;
    }
    return true;
}
template<typename T>
bool Array <T>::operator!=(const Array& _other)
{
    return !this->operator==(_other);
}
/*void Resize(int _newCount)
    {
        T* _tmp = tab;
        int _oldCount = count;
        count = _newCount;
        tab = new T[count];
        for (int i = 0; i < count && i < _oldCount; i++)
            tab[i] = _tmp[i];
        delete[] _tmp;
    }*/

