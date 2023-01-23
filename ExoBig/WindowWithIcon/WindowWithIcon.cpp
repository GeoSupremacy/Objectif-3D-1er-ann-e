#pragma region contexe
//Afficher fenètre avec icone et bouton
//Utiliser le bouton pour left fenêtre et rejoindre command cdr
#pragma endregion contexe
#include <iostream>
#include <Windows.h>


class AA;
class BB;

template <typename Base, typename Derived>
static bool  Instanceof(const Derived*)
{
	return std::is_same<Base, Derived>::value;
}
#define instanceof(a,b) Instanceof<a>(b)
#define alert(message) MessageBox(nullptr, message, L"", MN_OK)

int main()
{
	AA _b();
	AA _a();
	AA _c();

	if (instanceof(AA, _a))
	{
		std::cout << "This same";
	}
	else
	{
		std::cout << "Not the same ";
	}
	//MessageBox(nullptr, L"Comment vous aller?", L"Test", MB_OK | MB_ICONERROR);
	return 0;
}

