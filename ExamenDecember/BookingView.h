#pragma once
#include "Window.h"
#include <string>


class BookingView : public Window
{
#pragma region f/p
private:
	static inline BookingView* instance = nullptr;

	// Pour placer les boutons qui repr�sente les r�servations
	int x = 100;
	int y = 0;

	/*Pointer vers 'R�serves'*/
#pragma endregion f/p
#pragma region constructor/destructor
public:
	BookingView();
	~BookingView();
#pragma endregion constructor/destructor
#pragma region methods
public:
	void DisplayViewAllBookings(const auto _name, const int _x);//V�rifie si il y une r�servation par la class R�serve(non cr�e) sinon, cr�e des boutons par r�serves
	static LRESULT _stdcall WindowProc_Internal(HWND _hWindow, UINT _msg, WPARAM _wp, LPARAM _lp);
	LRESULT WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	void SelectBooking(); //Affiche les boutons de la r�serves par leur nom atitr�
	void ViewBooking(); //Regarde la r�serve s�lectionn�e
	void RemoveBooking(); //Pour supprimer une r�serve existante
	static BookingView* getInstance();
#pragma endregion methods

};

