#include "MainMenu.h"

#include "ButtonControl.h"
#include "LabelControl.h"
#include "Window.h"
#include "MenuDataBase.h"

#pragma region constructor/destructor
MainMenu::MainMenu(Window* _owner) : super(_owner, MAINMENU) {}
#pragma endregion constructor/destructor
#pragma region methods
void MainMenu::OpenCreateBookingMenu()
{
	owner->SetCurrentMenu(BOOKINGMENU);
}
void MainMenu::OpenCreateBookingViewMenu()
{
	owner->SetCurrentMenu(BOOKINGVIEWMENU);
}
#pragma endregion methods
#pragma region override
void MainMenu::Initialized()
{
	super::Initialize();
	ButtonControl *_createControls =CreateButton(Rect(), TEXT("Create Booking!"));
	_createControls->OnClick.SetDynamic(this, &MainMenu::OpenCreateBookingMenu);
	ButtonControl* viewControls = CreateButton(Rect(), TEXT("Create Booking!"));
	isInitialized = true;
	Close();
}
MainMenu MainMenu::CreateButton(const Rect& _rect, const wchar_t* _text)
{
	
}
#pragma endregion override

