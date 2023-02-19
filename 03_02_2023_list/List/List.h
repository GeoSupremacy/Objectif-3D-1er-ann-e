#pragma once
template<typename T>
class List
{
private:
    int sizeArray = 0;
    T* table = nullptr;
public:
    List() = default;
    ~List(){ Clear(); }
public:
    void Add(T _value);
    void AddAt(T _value, int _position);
    void Remove(T _item);
    void ReadAll(void);
    void Clear(void);
    bool Contain(void);
    bool IsItInside(T _item);
    int SizeofTable(void);
};

template<typename T>
inline void List<T>::Add(T _value)
{
    T* tmp = table;
    sizeArray++;
    table = new T[sizeArray];
    for (size_t i = 0; i < sizeArray - 1; i++)
        table[i] = tmp[i];
    table[sizeArray - 1] = _value;
}
template<typename T>
inline void List<T>::AddAt(T _value, int _position)
{
   
    if (table == nullptr)
    {
        std::cout << "Create new table" <<std::endl;
        Add(_value);
        return;
    }
    if (_position <0 || _position> sizeArray)
        std::cout << "Error of the position!" << std::endl;
    else
    {
        T* tmp = table;
        table = new T[sizeArray];
        for (size_t i = 0; i < sizeArray; i++)
            if (_position == i)
            {
                table[i] = _value;
                std::cout << "We modify =>" << tmp[i] << " by =>" << _value << " at =>" << i << std::endl;
            }
            else
                table[i] = tmp[i];
    }
   
}
template<typename T>
inline void List<T>::Remove(T _item)
{
    
    if (table == nullptr) std::cout << "table is empty!" << std::endl;

    T* tmp = table;
    const int _sizeActualy = sizeArray;
    sizeArray--;
    table = new T[sizeArray];
    bool _exist =false;

    for (size_t i = 0; i < _sizeActualy; i++)
    {
        if (_item != tmp[i])
            table[i] = tmp[i];
        else {
            std::cout << "We delete =>" << tmp[i] << " at =>" << i << std::endl;
            _exist = true;
        }
    }
    if(!_exist)
        std::cout << "There are not "<< _item << std::endl;
}
template<typename T>
inline void List<T>::ReadAll(void)
{
    if (table == nullptr) std::cout << "table is empty!" << std::endl;
    for (size_t i = 0; i < sizeArray; i++)
        std::cout << "table " << i << " : " << table[i] << std::endl;
}
template<typename T>
inline void List<T>::Clear(void)
{
    sizeArray = 0;
    delete[] table;
    table = nullptr;
}
template<typename T>
inline bool List<T>::Contain(void)
{
    return table != nullptr;
}
template<typename T>
inline bool List<T>::IsItInside(T _item)
{
    for (size_t i = 0; i < sizeArray; i++)
        if (_item==table[i])
            return true;
    return false;
}
template<typename T>
inline int List<T>::SizeofTable(void)
{
    return sizeArray;  
}
