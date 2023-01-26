#pragma once
#include "BaseMenu.h"
#include "MenuDataBase.h"

class MainMenu :
    public BaseMenu
{
    DECLARE_CLASS_INFO(BaseMenu)
#pragma endregion f/p
#pragma region constructor/destructor
public:
    MainMenu() = default;
    MainMenu(Window* _owner);
    MainMenu(const MainMenu& _copy) = default;
#pragma endregion constructor/destructor
private:
    void OpenCreateBookingMenu();
    void OpenCreateBookingViewMenu();
#pragma region override
public:
    void Initialized() override;
protected:
    MainMenu CreateButton(const Rect& _rect, const wchar_t* _text);
#pragma endregion override

};

