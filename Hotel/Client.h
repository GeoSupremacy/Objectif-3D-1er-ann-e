#include <iostream>
template <typename T>
struct Node
{
	T data;
	Node<T>* next = nullptr;
}; 
template <typename T>
class Client 
{
private:
	int count;
	Node<T>* header;
	T* CreateNode(const T& _value);
public:
	Client() = default;
	~Client();
	void Add(int _pos, const T& _value);
	void Delete(int _pos);
	void Display() const;
};


template<typename T>
 Client<T>::~Client()
{
	 Node <T>* del = header;
	 while (header) {
		 header = header->next;
		 delete del;
		 del = header;
	 }
}
 template<typename T>
 inline T* Client<T>::CreateNode(const T& _value)
 {
	 Node <T>* _temp = new Node <T>;
	 _temp->data = _value;
	 _temp->next = nullptr;
	 return _temp;
 }
template<typename T>
inline void Client<T>::Add(int _pos, const T& _value)
{
	Node <T>* _new = CreerNoeud(_value);
	Node <T>* _currrent = header;
	for (int i = 1; i < _pos; i++) {
		_currrent = _currrent->next;
	
		_new->next = _currrent->next;
	_currrent->next = _new;
}
count++;
}

template<typename T>
 void Client<T>::Delete(int _pos)
{
	
	Node <T>* _current = header;
	for (int i = 0; i < _pos - 1; i++) 
	{
		_current = _current->next;
	}
	Node <T>* _del = _current->next;
	_current->next = _current->next->next;
	delete _del;
	count--;
}

 template<typename T>
 void Client<T>::Display() const
 {
	 if (count == 0) {
		 std::cout << "No client!" << std::endl;
		 return;
	 }
	 Node <T>* _current = header;
	 while (_current != 0) {
		 std::cout << _current->_data << std::endl;
		 _current = _current->next;
	 }
 }


