#include "BookingView.h"

#define RETURN 1
#define CHOOSEBOOK 10
#define DELETE 30


#pragma region constructor/destructor
BookingView::BookingView()
{

#pragma region WNDCLASS
	const wchar_t* CLASS_NAME = L"View Booking";
	WNDCLASS wndClass = {};
	wndClass.lpszClassName = CLASS_NAME;
	wndClass.hInstance = hInstance;
	wndClass.hIcon = LoadIcon(NULL, IDI_WINLOGO);
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndClass.lpfnWndProc = WindowProc_Internal;

	RegisterClass(&wndClass);
#pragma endregion WNDCLASS
#pragma region AdjustWindowRect
	DWORD style = WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU;

	int width = 1920;
	int height = 1080;

	//dimension window
	RECT rect;
	rect.left = 250;
	rect.top = 250;
	//Coordinate
	rect.right = rect.left + width;
	rect.bottom = rect.top + height;

	AdjustWindowRect(&rect, style, false);
#pragma endregion AdjustWindowRect
#pragma region Window
	hWnd = CreateWindowEx(0,
		CLASS_NAME,
		L"Hotel Application",
		style,
		0,
		0,
		1920,
		1080,
		NULL,
		NULL,
		hInstance,
		NULL
	);
	ShowWindow(hWnd, SW_SHOW);


	CreateWindowEx(WS_EX_TOPMOST, TEXT("Static"), TEXT("View new Booking"), BS_CENTER | BS_PUSHBUTTON | WS_CHILD | WS_VISIBLE, 400, 0, 130, 20, hWnd, (HMENU)hInstance, NULL, NULL);
	CreateWindowEx(WS_EX_TOPMOST, TEXT("Button"), TEXT("Return"), BS_CENTER | BS_PUSHBUTTON | WS_CHILD | WS_VISIBLE, 200, 40, 130, 20, hWnd, (HMENU)RETURN, NULL, NULL);
#pragma endregion Window
}
BookingView::~BookingView(){}
#pragma endregion constructor/destructor
#pragma region methods
void BookingView::DisplayViewAllBookings(const auto _name, const int _x){
	if (_x = > 1070) // Si x dépasse la largeur de la fenêtre alors le nouveau bouton se situera en dessous en modifiant y
	{
		y = y + 20;
		CreateWindowEx(WS_EX_TOPMOST, TEXT("Button"), TEXT(_name), BS_CENTER | BS_PUSHBUTTON | WS_CHILD | WS_VISIBLE, _x, _y, 130, 20, hWnd, (HMENU)CHOOSEBOOK, NULL, NULL);
	}
	else
		CreateWindowEx(WS_EX_TOPMOST, TEXT("Button"), TEXT(_name), BS_CENTER | BS_PUSHBUTTON | WS_CHILD | WS_VISIBLE, _x, 0, 130, 20, hWnd, (HMENU)CHOOSEBOOK, NULL, NULL);

}
LRESULT _stdcall BookingView::WindowProc_Internal(HWND _hWindow, UINT _msg, WPARAM _wp, LPARAM _lp)
{
	if (WM_NCCREATE == _msg)
	{
		SetWindowLongPtr(_hWindow, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(reinterpret_cast<CREATESTRUCT*>(_lp)->lpCreateParams));
		return true;
	}
	return reinterpret_cast<BookingView*>(GetWindowLongPtr(_hWindow, GWLP_USERDATA))->WindowProc(_hWindow, _msg, _wp, _lp);
}
LRESULT BookingView::WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_COMMAND:
	{
		switch (wParam)
		{
			case RETURN:
			{
				//return à Menu
			}
			case CHOOSEBOOK:
			{
				ViewBooking();
				//Affiche La réserve séléctionné
			}
			case DELETE:
			{
				RemoveBooking();
				//Supprime La réserve séléctionné
			}
		}		
	}
	case WM_CLOSE:
		DestroyWindow(hwnd);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	default:
		return DefWindowProc(hwnd, uMsg, wParam, lParam);
	}
}
void BookingView::SelectBooking()
{
	/*
	Si 'compteur de réserve' est à 0 alors
		x =100
		y = 0;
		TextBox "No Booking"
	else
		Pour i égale à 0 incrémenter de 1 jusquà 'compteur de réserve'
			Parcour du 'compteur de réserve'
			x =x + 40
			Pointeur vers 'nom réserver'
			DisplayViewAllBookings('nom réserver', x)

			*/
}
void BookingView::ViewBooking()
{
	/*Pour i égale de 0 incrémenter de i 
		Pointeur vers Nom, prénom, nombre de personne et les dates justequ'à qu'il reste
		TextBox par pointeur

	*/
	//Le bouton pour delete la réservation
	CreateWindowEx(WS_EX_TOPMOST, TEXT("Button"), TEXT("Delete"), BS_CENTER | BS_PUSHBUTTON | WS_CHILD | WS_VISIBLE, 50, 600, 130, 20, hWnd, (HMENU)DELETE, NULL, NULL);
	 
}
void BookingView::RemoveBooking()
{
	/*
		Parcourir "compteur de réserve"
		Pointer vers l'object désigner
			Pointeur vers la méthode 'Remove' de la class 'Réserve'
	*/
}
BookingView* BookingView::getInstance()
{
	if (instance == nullptr)
	{
		instance = new BookingView();

		return instance;
	}
	else
		return instance;
}
#pragma endregion methods

