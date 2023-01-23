#include "Rectangle.h"


template<typename T>
void Display(const T& _objet)
{
	std::string ob = _objet;
	std::cout << ob << std::endl;
	std::cout << "======================" << std::endl;
	std::cout << "Lenght: " << _objet.mLenght << "Lenght: " << _objet._mHeigth << std::endl;
	std::cout << "======================" << std::endl;
}
int main()
{
	Rectangle<int> rectangle(7,3);
	rectangle.Display<rectangle>(rectangle.SeePerimeter());
}

