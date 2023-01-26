template<typename T>

class List
{

private:
	int* index = nullptr;

public:
	List() = default;
	~List();
	void AddFirst(int _value);
	void AddLast(int _value);
	void ShowList();
};
	

