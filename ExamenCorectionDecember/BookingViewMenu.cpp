#include "Booking.h"
#include "BookingManager.h"
#include "BookingViewMenu.h"
#include "MenuDataBase.h"
#include "LabelControl.h"
#include "ButtonControl.h"

#pragma region constructor/destructor
BookingViewMenu::BookingViewMenu(Window* _owner) : super(_owner, BOOKINGVIEWMENU){}
#pragma endregion constructor/destructor
#pragma region methods
void BookingViewMenu::ReturnMainMenu()
{
	owner->SetCurentMenu(MAINMENU);
}
void BookingViewMenu::DisplayBooking(const std::vector<Booking*>& _bookings) {
	int _positionX = 10, _positionY = 30;
	int _index = 0;
	for (Booking* _booking : _bookings)
	{
		const Client _client = _booking->GetClient();
		const std::string _clientFullName = _client.FirstName() + " " + _client.LastName();
		const std::wstring _FullNameWstr = std::wstring(_clientFullName.begin(), _clientFullName.end());
		ButtonControl* _button = CreateButton(Rect(_positionX, _positionY, 250, 20), _FullNameWstr.c_str());
		_positionX += 260;
		_index++;
		if (_index % MAXNUMBER)
		{
			_positionX = 0;
			_positionY = 0;
		}
	}
}
void BookingViewMenu::SetCurrentBooking(Booking* _booking)
{
	CurrentBooking = _booking;
}
#pragma endregion methods
#pragma region override
void BookingViewMenu::Initialize()
{
	super::Initialize();
	textControl = CreateLabel(Rect(10, 30, 250, 20, L"");
	ButtonControl* _returnControl = CreateButton(Rect(10,0,100,20), TEXT("Return"));
	_returnControl->OnClick.SetDynamic(this, &BookingViewMenu::ReturnMainMenu);
	Close();
}
void BookingViewMenu::Open()
{
	std::vector<Booking*> _booking = BookingManager::Instance()->Bookings();
	if (_booking.empty())
	{
		textControl->SetText(L"No bookings...");
	}
	else
	{
		DisplayBooking(_booking);
		textControl->SetText(L"");
	}
	super::Open();
}
void BookingViewMenu::Close()
{
	const size_t _size = controls.size();
	for (size_t i = 0; i < _size; i++)
	{
		controls[1]->Hide();
		delete controls[1];
		controls.erase(controls.begin() + 1);
	}
}
#pragma endregion override