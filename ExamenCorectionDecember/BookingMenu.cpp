#include "Booking.h"
#include "BookingMenu.h"
#include "BookingManager.h"
#include "CalendarControl.h"
#include "ButtonControl.h"
#include "TextFieldControl.h"
#include "LabelControl.h"
#include "MenuDataBase.h"
#include "Windows.h"
#include "Client.h"
#include "Rect.h"


#pragma region constructor/destructor
BookingMenu::BookingMenu(Window* _owner) : super(_owner, BOOKINGMENU) {}
#pragma endregion constructor/destructor
#pragma region methods
void BookingMenu::SaveBooking()
{
	try
	{
		const int _numberPeople = std::stoi(numberOfPeople->CurrentText());
		const Client _client = Client(firstName->CurrentTextStr(), lastName->CurrentTextStr());
		Booking* _booking = new Booking(calendar->ArrivedDate(), calendar->DepartureDate(), _client, _numberPeople);
		BookingManager::Instance()->RegisterBooking(_booking);
		messageControl->SetText(TEXT("Successful booking !"));
	}
	catch (const std::exception&)
	{
		messageControl->SetText(TEXT("Error on create booking !!"));
	}
}
#pragma endregion methods
#pragma region override
void BookingMenu::Initialized()
{
	super::Initialized();
	messageControl = CreateLabel(Rect(owner->Width()/2,50,200,20),TEXT(""));
	firstName = CreateTextField(Rect(10, 50, 255, 20), L"first Name");
	lastName=CreateTextField(Rect(10, 80, 255, 20), L"last Name");
	numberOfPeople=CreateTextField(Rect(10, 110, 255, 20), L"Number of people...");

	ButtonControl* _saveControl = CreateButton(Rect(60, 360, 15, 20), L"Save Booking");
	_saveControl->Onclick->SetDynamic(this, &BookingMenu::SaveBooking);

	CalendarControl* _calendar = CreateCalendar(Rect(10, 140, 150, 150));
	_calendar->SetMaxSelected(15);

	isInitialized = true;
	Close();
}
#pragma endregion override


