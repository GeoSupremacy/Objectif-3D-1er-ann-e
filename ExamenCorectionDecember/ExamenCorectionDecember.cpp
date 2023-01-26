#include "Window.h"
#include "MainMenu.h"
#include "BookingMenu.h"
#include "BookingViewMenu.h"
#include "BookingViewDataMenu.h"
#include "MenuDataBase.h"


int main()
{

	Window window = Window(L"Hotel O3D", 900, 900);
	window.RegisterMenu(new MainMenu(&window));
	window.RegisterMenu(new BookingMenu(&window));
	window.RegisterMenu(new BookingViewMenu(&window));
	window.RegisterMenu(new BookingViewDataMenu(&window));
	window.SetCurrentMenu(MAINMENU);
	window.Open();
}

