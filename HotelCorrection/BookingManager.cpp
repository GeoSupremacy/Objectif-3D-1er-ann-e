#include "BookingManager.h"
#include "Booking.h"
#include "Utils.h"

void BookingManager::Display()
{
    Utils::LogTitle("All Booking");
    for (Booking* _booking : bookings)
    {
        Utils::LogSeparator(20);
        Utils::Log(_booking);
        Utils::LogSeparator(20);
    }
}

void BookingManager::AddBooking(Booking* _booking)
{
    bookings.push_back(_booking);
}

void BookingManager::DeleteBooking(Booking* _booking)
{
    const size_t _size = bookings.size();
    for (size_t i = 0; i < _size; i++)
    {
        if (bookings[i] == _booking)
        {
            bookings.erase(bookings.begin() + i);
            delete _booking;
            break;
        }
    }
}

std::vector<Booking*> BookingManager::Booking() const
{
    return bookings;
}
