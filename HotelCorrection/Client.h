#include "Object.h"
#include "DateTime.h"
class Client : public Object
{
private:
	std::string firstName = "";
	std::string lastName = "";
	int age = 0;
public:
	Client() = default;
	Client(const std::string& _first, const std::string& _last, const int _age);
	Client(const Client& _copy);
public:
	std::string FirstName() const;
	std::string LastName() const;
	int Age() const;
public:
	std::string ToString() const;
};

