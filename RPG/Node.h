class Node
{
public:
	int data;
	Node* next = nullptr;
	Node* prev = nullptr;

	Node(int _data, Node* _next = nullptr, Node* _prevt = nullptr)
	{
		data = _data;
		next = _next;
		prev = _prevt;
	}

	bool operator ==(const Node& _node);

};
