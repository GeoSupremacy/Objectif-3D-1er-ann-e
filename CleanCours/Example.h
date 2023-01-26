#include <string>
class Example
{
#pragma region f/p
private:
	std::string name = "";
	Example* next = new Example();
#pragma endregion f/p


public:
	
#pragma region constructeur/destructeur
	 Example(){
		 name = "Thomas";
		 Test();
	 };

	 Example(const Example& _copy) {
		 name = _copy.name;
		 next = _copy.next;
	 };
	 ~Example() {
		 delete next;
		 next = nullptr;
	 };
#pragma endregion

#pragma region methode
	virtual void Test()
	 {};
#pragma endregion
#pragma region override
#pragma endregion

#pragma region operator
	Example operator = (const Example & _other)
	{
		name = _other.name;
		next = _other.next;
		return *this;
	}
	bool operator ==(std::string _name)
	{
		return name == _name;
	}
	bool operator ==(const Example& _otherame)
	{
	}
	bool operator ==(std::string _name)
	{}
	bool operator !=(std::string _name)
	{}
#pragma endregion 
};

