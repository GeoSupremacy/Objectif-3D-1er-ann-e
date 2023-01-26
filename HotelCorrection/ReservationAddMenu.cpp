#include "ReservationAddMenu.h"
#include "Utils.h"
#include "DateTime.h"
#include "Client.h"
#include "BookingManager.h"
#include "Booking.h"

ReservationAddMenu::ReservationAddMenu() : Menu("Reservation Add", {})
{
}

void ReservationAddMenu::Open()
{
	Utils::ClearConsole();
	Utils::LogTitle(title);

	const std::string _firstname = Utils::UserStringChoise("client first name: ");
	const std::string _lastName = Utils::UserStringChoise("client last name: ");
	const int _age = Utils::UserChoise<int>("client age: ");


	try
	{
		const DateTime _arrival = DateTime::Parse(Utils::UserStringChoise(""));
		const DateTime _depart = DateTime::Parse(Utils::UserStringChoise(""));
		Client* _client = new Client(_firstname, _lastName, _age);
		BookingManager::Instance()->AddBooking(new Booking(_client, _arrival, _depart));
	}
	catch (const std::exception())
	{
		Utils::Pause();
	}
	Utils::ClearConsole();
	Utils::Log("");
	Utils::Pause();
	OpenOldMenu();
}