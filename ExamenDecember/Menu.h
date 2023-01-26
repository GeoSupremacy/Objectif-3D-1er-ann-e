#pragma once
#include <iostream>


class Reception;
class BookingView;
class CreateNewBooking;


class Menu
{
#pragma region f/p
private:
	//Les pointeurs vers chaques fenêtres
	Reception* reception = nullptr;
	BookingView* bookingView = nullptr;
	CreateNewBooking* createNewBooking = nullptr;
	
	static inline Menu* instance = nullptr; //La class Menu est un singleton, on ne veut qu'ne instance d'objet de cette classe pareil pur les autres class 'BOOKINGVIEW', 'RECEPTION'
	//et 'CREATENEWBOOKING'

	//Pour switch chaque fenêtre donc chaque class
	enum  ChooseMenu{ RECEPTION = 0, BOOKINGVIEW = 1, CREATENEWBOOKING = 2};

	ChooseMenu chooseMenu = RECEPTION; //Choix par défaut
#pragma endregion f/p
#pragma region constructor/destructor
public:
	Menu();
	~Menu();
#pragma endregion constructor/destructor
#pragma region methods
public:
	void DisplayMenu(const int _chooseMenu); //L'affichage
	void SwitchMenu(const ChooseMenu _chooseMenu);  //Pour changer chooseMenu
	void ChoseMenu(const int _chooseMenu);//Lorqu'on change de menu
	static Menu* getInstance();
#pragma endregion methods
};

