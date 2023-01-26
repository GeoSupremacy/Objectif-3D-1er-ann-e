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
	Reception();// On cr�e la class fen�tre et les boutons
	Reception(const Reception& obj)= delete;
	~Reception();
#pragma endregion constructor/destructor
#pragma region method
	LRESULT WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam); //Le processus window
	static LRESULT _stdcall WindowProc_Internal(HWND _hWindow, UINT _msg, WPARAM _wp, LPARAM _lp); //Pour que la classe fen�tre utilise le WindowProc
	static Reception* getInstance(); //Savoir si il y a d�j� une instance
	void MoveCreatebooking(); //Pour aller � Createbooking
	void MoveViewBooking();// Pour aller � ViewBooking

#pragma endregion method
};

