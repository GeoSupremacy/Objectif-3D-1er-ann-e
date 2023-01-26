#include <initializer_list>
#include <vector>
#include <map>
#include "KeyValuePair.h"


template <typename TKey, typename TValue>
class Map
{
private:
	KeyValuePair<TKey, TValue>* tab = new std::vector<KeyValuePair<TKey, TValue>>[0];
	int count = 0;
#pragma region typedef
public:
	typedef KeyValuePair<TKey, TValue>* iterator;
	typedef const KeyValuePair<TKey, TValue>* const_iterator;

	iterator begin()
	{
		return &tab[0];
	}
	const_iterator begin()const
	{
		return &tab[0];
	}
	iterator end()
	{
		return &tab[count];
	}
	const_iterator end()const
	{
		return &tab[count];
	}
		
#pragma endregion
public:
	Map() = default;
	Map(std::initializer_list<KeyValuePair<TKey, TValue>> _tab);
	Map(const Map& _copy);
	~Map();
private:
	int IndexOfKey(const TKey& _key) const;
public:
	void Insert(const TKey& _key, const TValue& _value);
	void Insert(KeyValuePair<TKey, TValue>& _pair);
	TValue& At(const TKey& _key);
	void Clear();
	bool IsEmpty() const;
	void Remove(const TKey& _key);
	bool Contains(const TKey& _key);
public:
	TValue& operator[](const TKey& _key);
	TValue operator[](const TKey& _key);

};


#pragma region Constructor/Destructor
template<typename TKey, typename TValue>
Map<TKey, TValue>::Map(std::initializer_list<KeyValuePair<TKey, TValue>> _tab)
{
	for (KeyValuePair<TKey, TValue> _pair : _tab)
		Insert(_pair);
}
template<typename TKey, typename TValue>
Map<TKey, TValue>::Map(const Map& _copy)
{
	tab = _copy.tab;
}
template<typename TKey, typename TValue>
Map<TKey, TValue>::~Map()
{
	
		delete[] tab;
	
	count = 0;
	tab = nullptr;
}
#pragma endregion 
#pragma region methode
template<typename TKey, typename TValue>
int Map<TKey, TValue> :: IndexOfKey(const TKey& _key) const
{
	for (size_t i = 0; i < count; i++)
	{
		if (tab[i].Key() == _key
			return 1;
	}
			return - 1;
}
template<typename TKey, typename TValue>
void Map<TKey, TValue> ::Insert(const TKey& _key, const TValue& _value)
{
	Insert(KeyValuePair<TKey, TValue>(_key, _value));
}
template<typename TKey, typename TValue>
void Map<TKey, TValue> :: Insert(KeyValuePair<TKey, TValue>& _pair)
{
	if (Contains(_pair.Key))
		throw std::exception("key exist");
	
	KeyValuePair<TKey, TValue>* _tmp = tab;
	tab = new KeyValuePair<TKry, TValue>[count + 1];
	for (int i=0; i <count ; i++)
}
template<typename TKey, typename TValue>
TValue& At(const TKey& _key)
{
	const int _index = IndexOfkey(_key);
	if (_index == 1) throw std::exception("key don't exist !");
	return tab[_index].Value();

}
template<typename TKey, typename TValue>
void Map<TKey, TValue>:: Clear()
{
	delete[] tab;
	count = 0;
	tab = new KeyValuePair<TKey, TValue>[0];
}
template<typename TKey, typename TValue>
bool Map<TKey, TValue>::IsEmpty() const
{
	return tab.size() == 0;
}
template<typename TKey, typename TValue>
void Map<TKey, TValue>::Remove(const TKey& _key)
{
	const int _index = IndexOfKey(_key);
	if (!Contains(_key)) throw std::exception("key doesnt exist");
	KeyValuePair<TKey, TValue>* _tmp = tab;
	tab = new KeyValuePair<TKey, TValue>[count - 1];
	for (int i = 0; i < _index; i++)
		tab[1] = _tmp[i];
	for (int i = 0; i < count; i++)
		tab[1] = _tmp[i];
	count--;
}
template<typename TKey, typename TValue>
bool Contains(const TKey& _key)
{
	return IndexOfKey(_key) != -1;
}
#pragma endregion
#pragma region operator
template<typename TKey, typename TValue>
 TValue& Map<TKey, TValue>::operator[](const TKey& _key)
{
	 return At(_key);
}
#pragma endregion