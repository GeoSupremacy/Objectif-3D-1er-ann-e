#pragma once
#include "Singleton.h"
#include "Booking.h"
#include <vector>


class BookingManager : public Singleton<BookingManager>
{
	DECLARE_CLASS_INFO(Singleton<BookingManager>)
#pragma region f/p
private:
	std::vector<Booking*> bookings;
#pragma endregion f/p
#pragma region constructor/destructor
public:

#pragma endregion constructor/destructor
#pragma region methods
public:
	void RegisterBooking(Booking* _booking);
	void DeleteBooking(Booking* _booking);
	std::vector<Booking*> Booking() const;
#pragma endregion methods
#pragma region override
public:
	void OnDestroy() override;
#pragma endregion override
#pragma region operator
public:

#pragma endregion operator
	
};

