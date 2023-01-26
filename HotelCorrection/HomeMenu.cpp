#include "HomeMenu.h"
#include "ReservationMenu.h"
#include "MenuItem.h"
HomeMenu::HomeMenu() : Menu("Home", {new MenuItem("Reservation", "Reservation Gestion", new ReservationMenu())})
{
	
}
