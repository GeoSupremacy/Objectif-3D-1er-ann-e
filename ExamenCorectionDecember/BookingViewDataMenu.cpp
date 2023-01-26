#include "BookingViewDataMenu.h"
#include "MenuDataBase.h"
#include "Window.h"
#include "BookingManager.h"

#pragma region constructor/destructor
BookingViewDataMenu::BookingViewDataMenu(Window& _owner) : super(_owner, BOOKINGVIEWMENU) {}
#pragma endregion constructor/destructor
#pragma region methods
std::string BookingViewDataMenu::TextStr()
{
    return std::string();
}

std::wstring BookingViewDataMenu::Text()
{
    return std::wstring();
}

void BookingViewDataMenu::SetText(const wchar_t* _newText)
{
    text = _newText;
    SetText(text.c_str());
}
void BookingViewDataMenu::SetText(const std::string& _str)
{
    const std::wstring _wstr(_str.begin(), _str.end());
    SetText(_wstr.c_str());
}
#pragma endregion methods
#pragma region override
void BookingViewDataMenu::Open()
{
    const Booking* _current = BookingViewMenu::CurrentBooking;
    const Client* _client = _current->GetClient();
    firstName->SetText("First Name" + _client.FirstName());
    lastName->SetText("Last Name" + _client.LastName());
    numberOfPeople->SetText("Number of people" + std::to_string(_current->NumberOfPeople()));
    calendar->SetValue((_current->ArrivedDate()),(_current->DepartureDate()));
    super::Open();
}
void BookingViewDataMenu::Close()
{
}
void BookingViewDataMenu::Initialize()
{
    super::Initialize();
    ButtonControl* _returnControl = CreateButton(Rect(10, 0, 100, 20), TEXT("Return"));
    _returnControl->Onclick->SetDynamic(this, &BookingViewDataMenu::ReturnToBookingView);

    firstName = CreateLabel(Rect(10,60,250,20),L"");
    lastName = CreateLabel(Rect(10,60,250,20),L"");
    numberOfPeople = CreateLabel(Rect(10,60,250,20),L"");
    calendar = CreateLabel(Rect(10, 60, 250, 20), L"");

    ButtonControl* _deleteControl = CreateButton(Rect(10, 360, 100, 20), L"Delete");
    _deleteControl->Onclick->SetDynamic(this, &BookingViewDataMenu::Delete);

    isInitialized = true;
    Close();
}
#pragma endregion override