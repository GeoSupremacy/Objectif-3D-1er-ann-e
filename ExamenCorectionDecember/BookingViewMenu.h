#pragma once
#include "BaseMenu.h"

class Booking;

#define MAXNUMBER 3;

class BookingViewMenu : public BaseMenu
{
	DECLARE_CLASS_INFO(BaseMenu)
#pragma region f/p
public:
	static Booking* currentBooking;
private:
	class LabelControl* textControl = nullptr;
#pragma endregion f/p
#pragma region constructor/destructor
public:
	BookingViewMenu() = default;
	BookingViewMenu(Window* _owner);
	BookingViewMenu(const BookingViewMenu& _copy) = default;
#pragma endregion constructor/destructor
#pragma region methods
public:
	void ReturnMainMenu();
	void DisplayBooking(const std::vector<Booking*>& _bookings);
	void SetCurrentBooking(Booking* _booking);
#pragma endregion methods
#pragma region override
public:
	void Initialize() override;
	void Open() override;
	void Close() override;
#pragma endregion override

};

