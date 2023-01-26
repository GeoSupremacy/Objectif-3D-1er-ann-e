#include "BookingManager.h"





#pragma region methods
void BookingManager::RegisterBooking(Booking* _booking)
{
}

void BookingManager::DeleteBooking(Booking* _booking)
{
}
std::vector<Booking*> BookingManager::Booking() const
{
    return bookings;
}
#pragma endregion methods
#pragma region override
void BookingManager::OnDestroy()
{
    const size_t size = bookings.size();
	for (size_t i = 0; i < size; i++)
	{

	}
}
#pragma endregion override
