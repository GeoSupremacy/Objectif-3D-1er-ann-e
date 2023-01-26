#include "ReservationMenu.h"
#include "ReservationDisplayMenu.h"
#include "ReservationRemoveMenu.h"

ReservationMenu::ReservationMenu() : Menu("Reservation", 

	new MenuItem("Add", "Add new booking", new ReservationMenu()), 
	new MenuItem("Dispaly", " booking", new ReservationDisplayMenu()),
	new MenuItem("Remove", " remove", new ReservationRemoveMenu()),

{
	
}

void ReservationMenu::Open()
{
	Menu::Open();
	Update();
}
