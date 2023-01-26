#include "Menu.h"
class ReservationRemoveMenu : public Menu
{
private:
	std::vector<Booking*> bookings = std::vector<Booking*>();
public:
	ReservationRemoveMenu();
public:
	void DisplayBookings();
	void ConfirmationDelete(char _choise );
public:
	void Open() override;
	void Close() override;
};

