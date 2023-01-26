#include "Singleton.h"
#include <vector>

class Booking;

class BookingManager : public Singleton< BookingManager>
{
private:
	std::vector<Booking*> bookings = std::vector<Booking*>();
public:
	BookingManager() = default;
public:
	void Display();
	void AddBooking(Booking* _booking);
	void DeleteBooking(Booking* _booking);
	std::vector< Booking*> Booking() const;
};

