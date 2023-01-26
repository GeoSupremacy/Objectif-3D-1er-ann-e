#include "Menu.h"
#include "Reception.h"
#include "BookingView.h"
#include "CreateNewBooking.h"


#pragma region constructor/destructor
Menu::Menu()
{
	reception = new Reception();
}
Menu::~Menu()
{
	delete reception;
	reception = nullptr;

	delete bookingView;
	bookingView = nullptr;

	delete createNewBooking;
	createNewBooking = nullptr;
}
#pragma endregion constructor/destructor
#pragma region methods
void Menu::DisplayMenu(const int _chooseMenu)
{
	ChoseMenu(_chooseMenu);
	SwitchMenu(chooseMenu);
}
void Menu::SwitchMenu(const ChooseMenu _chooseMenu)
{
	switch (_chooseMenu)
	{
	case 0:
		reception->ProcessMessage();
		break;
	case 1:
		// Ici pour Voir les réserves 
		break;
	case 2:
		createNewBooking->ProcessMessage();
	default:
		break;
	}
}
void Menu::ChoseMenu(const int _chooseMenu)
{
	switch (_chooseMenu)
	{
	case 0:
		chooseMenu = RECEPTION;
		break;
	case 1:
		chooseMenu = BOOKINGVIEW;
		break;
	case 2:
		chooseMenu = CREATENEWBOOKING;
	default:
		break;
	}
}
Menu* Menu::getInstance()
{
	if (instance == nullptr)
	{

		instance = new Menu();


		return instance;
	}
	else
		return instance;
}
#pragma endregion methods


