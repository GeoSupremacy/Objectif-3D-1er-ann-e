#pragma once
#include "Client.h"
#include "DateTime.h"

class Booking : public Object
{
	DECLARE_CLASS_INFO(Object)
#pragma region f/p
private:
	DateTime arrivedDate = DateTime();
	DateTime departureDate = DateTime();
	Client client = Client();
	int numberOfPeople = 1;
#pragma endregion f/p
#pragma region constructor/destructor
public:
	Booking() =default;
		Booking(DateTime _arrivedDate , DateTime _departureDate , Client _client,int _numberOfPeople);
		Booking(const Booking& _copy);
#pragma endregion constructor/destructor
#pragma region methods
public:
	DateTime ArrivedDate();
	DateTime DepartureDate();
	Client GetClient();
	int NumberOfPeople();
#pragma endregion methods
};

