#pragma once
#include "BaseMenu.h"
#include "MenuDataBase.h"

class CalendarControl;
class TextFieldControl;
class LabelControl;

class BookingMenu :public BaseMenu
{
    DECLARE_CLASS_INFO(BaseMenu)
 private:
     CalendarControl* calendar = nullptr;
     TextFieldControl*  firstName= nullptr;
     TextFieldControl* lastName = nullptr;
     TextFieldControl* numberOfPeople= nullptr;
     LabelControl* messageControl = nullptr;
#pragma region constructor/destructor
public:
    BookingMenu() = default;
    BookingMenu(Window* _owner);
    BookingMenu(const BookingMenu& _copy) = default;
#pragma endregion constructor/destructor
#pragma region methods
    void SaveBooking();
#pragma endregion methods
#pragma region override
public:
    void Initialized() override;
#pragma endregion override

};

