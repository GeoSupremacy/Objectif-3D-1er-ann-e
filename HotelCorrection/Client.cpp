#include "Client.h"
#include <format>
Client::Client(const std::string& _first, const std::string& _last, const int _age)
{
    firstName = _first;
    lastName = _last;
    age = _age;
}

Client::Client(const Client& _copy)
{
    firstName = _copy.firstName;
    lastName = _copy.lastName;
    age = _copy.age;
}

std::string Client::FirstName() const
{
    return firstName;
}

std::string Client::LastName() const
{
    return lastName;
}

int Client::Age() const
{
    return age;
}

std::string Client::ToString() const
{
    return std::format("first name: {}\last name: {}\ age: {}\n", firstName, lastName, age);
}
