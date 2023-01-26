#pragma once
#include "Window.h"
#include <string>


class BookingView : public Window
{
#pragma region f/p
private:
	static inline BookingView* instance = nullptr;

	// Pour placer les boutons qui représente les réservations
	int x = 100;
	int y = 0;

	/*Pointer vers 'Réserves'*/
#pragma endregion f/p
#pragma region constructor/destructor
public:
	BookingView();
	~BookingView();
#pragma endregion constructor/destructor
#pragma region methods
public:
	void DisplayViewAllBookings(const auto _name, const int _x);//Vérifie si il y une réservation par la class Réserve(non crée) sinon, crée des boutons par réserves
	static LRESULT _stdcall WindowProc_Internal(HWND _hWindow, UINT _msg, WPARAM _wp, LPARAM _lp);
	LRESULT WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	void SelectBooking(); //Affiche les boutons de la réserves par leur nom atitré
	void ViewBooking(); //Regarde la réserve sélectionnée
	void RemoveBooking(); //Pour supprimer une réserve existante
	static BookingView* getInstance();
#pragma endregion methods

};

