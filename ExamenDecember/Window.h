#pragma once
#include <windows.h>

//Vu que les classe "BookingView", "CreateNewBooking","Reception" ne doit y avoir qu'ne seul instance la class Window devrait être un Singleton
class Window 
{
#pragma region f/p
protected:
	 HINSTANCE hInstance;
	 HWND hWnd;  //window
	
#pragma endregion f/p
#pragma region constructor/destructor
public:
	 Window();
	 Window(const Window&) = delete;
	~Window();
#pragma endregion constructor/destructor
#pragma region methods
public:
	 bool ProcessMessage();// Le traitement des messages
#pragma endregion methods
#pragma region operator
public:
	Window& operator = (const Window&) = delete;
#pragma endregion operator
};
