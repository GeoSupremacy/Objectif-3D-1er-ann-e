#pragma once
#include "Window.h"
#include "Menu.h"


class CreateNewBooking : public Window
{
#pragma region f/p
private:
	static inline CreateNewBooking* instance = nullptr;
	Menu* menu = new Menu();
	/*Pointer vers 'R�serves'*/
#pragma endregion f/p
#pragma region constructor/destructor
public:
	CreateNewBooking();
	~CreateNewBooking();
#pragma endregion constructor/destructor
#pragma region method
	static LRESULT _stdcall WindowProc_Internal(HWND _hWindow, UINT _msg, WPARAM _wp, LPARAM _lp);
	LRESULT WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	void MoveMenu(); //Pour retourner  � la r�cepetion
	void CreateBooking(); //Pour cr�er booking
	static CreateNewBooking* getInstance();
#pragma endregion method
};

