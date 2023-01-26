#pragma once
template <typename T>
class List
{
	int Count() const;
	T& At(const int& _index);
};
template<typename T>
int List<T>::Count() const
{
	return count;
}
T& List<T>::At(const int& _index)
{
	if (_index <0 || _index >count) throw std::eception("");
	Node<T>* _head = head;
	for (int i = 0; i < _index && _head->Next() != nullptr; i++)
	{
		_head = _head->Next();
	}
}
