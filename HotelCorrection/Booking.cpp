#include "Booking.h"
#include "Client.h"
#include "DateTime.h"
#include <format>

Booking::Booking(Client* _client, DateTime _arrival, DateTime _departeDate)
{
    client = _client;
    arrivevalDate =_arrival;
    departeDate = _departeDate;

}

Booking::Booking(Booking* _copy)
{
    client = _copy->client;
    arrivevalDate = _copy->arrivevalDate;
    departeDate = _copy->departeDate;
}

Booking::~Booking()
{
    delete client;
}

Client* Booking::GetClient() const
{
    return client;
}

DateTime Booking::Arrivate() const
{
    return arrivevalDate;
}

DateTime Booking::Departe() const
{
    return departeDate;
}

std::string Booking::ToString() const
{
    return std::format("Client:\n{} \nArrival Date:Client:\n{} \Depature Date : ", client->ToString(), arrivevalDate.ToString(), departeDate.ToString());
}
