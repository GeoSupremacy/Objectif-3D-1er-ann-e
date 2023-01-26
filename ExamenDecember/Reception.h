#pragma once
#include "Window.h"
#include "Menu.h"


class Reception : public Window
{
#pragma region f/p
private:
	static inline Reception* instance = nullptr; //La class Reception est un singleton, on ne veut qu'ne instance d'objet de cette classe
	Menu* menu = new Menu(); //Pour retourner vers Menu
#pragma endregion f/p
#pragma region constructor/destructor
public:
	Reception();// On crée la class fenêtre et les boutons
	Reception(const Reception& obj)= delete;
	~Reception();
#pragma endregion constructor/destructor
#pragma region method
	LRESULT WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam); //Le processus window
	static LRESULT _stdcall WindowProc_Internal(HWND _hWindow, UINT _msg, WPARAM _wp, LPARAM _lp); //Pour que la classe fenêtre utilise le WindowProc
	static Reception* getInstance(); //Savoir si il y a déjà une instance
	void MoveCreatebooking(); //Pour aller à Createbooking
	void MoveViewBooking();// Pour aller à ViewBooking

#pragma endregion method
};

