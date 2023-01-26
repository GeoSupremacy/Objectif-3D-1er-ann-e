#include "ReservationRemoveMenu.h"
#include "BookingManager.h"
#include "Utils.h"

ReservationRemoveMenu::ReservationRemoveMenu() : Menu("Booking Remove", {})
{

}

void ReservationRemoveMenu::DisplayBookings()
{
	if (bookings.size() == 0)
	{

		Utils::Log("No Boooking!");
		Utils::Pause();
		OpenOldMenu();
		return;
	}
	const size_t _size = bookings.size();
	for (size_t i = 0; i < _size; i++)
	{
		Utils::LogSeparator(30);
		Utils::Log(std::to_string(i + 1) + ": " + bookings[i]->ToString());;
		Utils::LogSeparator(30);
	}
}

void ReservationRemoveMenu::ConfirmationDelete(char _choise)
{
	int _index = _choise - '0' - 1;
	
	Utils::ClearConsole();
	Utils::LogSeparator(30);
	Utils::Log(bookings[_index]);
	Utils::LogSeparator(30);

		
	_choise = Utils::UserChoise<char>("Are you sure to delete? (y/n)");
	if (std::tolower(_choise) == 'n')
	{
		OpenOldMenu();
		return;
	}
	if (std::tolower(_choise) != 'y')
		throw std::exception("[Reservation Remove Menu] => choise no valid!");

	BookingManager::Instance()->DeleteBooking(bookings[_index]);
	OpenOldMenu();
}

void ReservationRemoveMenu::Open()
{
	Menu::Open();
	bookings = BookingManager::Instance()->bookings();
	DisplayBookings();

	char _choise = Utils::UserChoise<char>("Which reservation do want to delete");
	if (std::tolower(_choise) == 'n')
	{
		OpenOldMenu();
		return;
	}
	else if (std::isalpha(_choise))
		throw std::exception("Reservation chose no valid!");
	ConfirmationDelete(_choise);
}

void ReservationRemoveMenu::ConfirmationDelete(char _choise)
{
	int _index = _choise - '0' - 1;
	Utils::ClearConsole();
	Utils::LogSeparator(30);
	Utils::Log(bookings[_index]);
	Utils::LogSeparator(30);

	_choise = Utils::UserChoise<char>("y/n");
	if (std::tolower(_choise) == 'n')
	{
		OpenOldMenu();
		return;
	}
	else if (std::tolower(_choise) == 'y')
	{
		
		return;
	}
	BookingManager::Instance()->RemoveBooking(bookings[_index]);
}
void ReservationRemoveMenu::Close()
{
	bookings.clear();
}
