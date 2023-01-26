#include "Booking.h"


#pragma region constructor/destructor
Booking::Booking(DateTime _arrivedDate, DateTime _departureDate, Client _client, int _numberOfPeople)
{
	arrivedDate = _arrivedDate;
	departureDate = _departureDate;
	client = _client;
	numberOfPeople = _numberOfPeople;
}

Booking::Booking(const Booking& _copy)
{
	arrivedDate = _copy.arrivedDate;
	departureDate = _copy.departureDate;
	client = _copy.client;
	numberOfPeople = _copy.numberOfPeople;
}
#pragma endregion constructor/destructor
#pragma region methods
DateTime Booking::ArrivedDate()
{

	return arrivedDate;
}
DateTime Booking::DepartureDate()
{
	return departureDate;
}
Client Booking::GetClient()
{
	return client;
}
int Booking::NumberOfPeople()
{
	return numberOfPeople;
}
#pragma endregion methods
#pragma region override

#pragma endregion override