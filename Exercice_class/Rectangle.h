#pragma once
#include <iostream>
#include <string>

template<typename T>
class Rectangle
{
#pragma region f/p
private:
	
	 T mLenght;
	 T mHeigth;
#pragma endregion f/p
#pragma region construction
public:
	  
	 Rectangle( const T _mLenght, const T _mHeigth);
	 Rectangle(Rectangle& _copy);
#pragma endregion construction
#pragma region Setter/getter
public:
	 void Getter()const;
	 void Setter(const T _mLenght, const T _mHeigth);
#pragma endregion Setter/getter
#pragma region method
public:
	void SeePerimeter()const;
	void SeeArea()const;
	void Display(const T& _objet);
#pragma endregion method
};

#pragma region construction
template<typename T>
 Rectangle<T>::Rectangle (const T _mLenght, const T _mHeigth)
{
	 mLenght = _mLenght;
	 mHeigth = _mHeigth;
}
template<typename T>
Rectangle<T>::Rectangle(Rectangle& _copy)
{
	mLenght = _copy.mLenght;
	mHeigth = _copy.mHeigth;
}
#pragma endregion construction
#pragma region Setter/Getter
template<typename T>
inline void Rectangle<T>::Getter() const
{
	return mLenght, mHeigth;
}
template<typename T>
inline void Rectangle<T>::Setter(const T _mLenght, const T _mHeigth)
{
	mLenght = _mLenght;
	mHeigth = _mHeigth;
}
#pragma endregion Setter/Getter
#pragma region method
template<typename T>
inline void Rectangle<T>::SeePerimeter() const
{
	return mLenght * 2 + mHeigth * 2;
}
template<typename T>
inline void Rectangle<T>::SeeArea() const
{
	return mLenght *mHeigth;
}

template<typename T>
inline void Rectangle<T>::Display(const T& _objet)
{
	std::string ob = _objet;
	std::cout << ob << std::endl;
	std::cout << "======================"<< std::endl;
	std::cout <<"Lenght: " << _objet.mLenght <<"Lenght: " << _objet._mHeigth << std::endl;
	std::cout << "======================" << std::endl;
}

#pragma endregion method