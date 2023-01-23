#include "Vector4.h"

int main()
{
	Vector4  _vectorOne = Vector4(8, 7, 5, 4);
	Vector4  _vectorTwo = Vector4(5, 5, 5, 5);
	_vectorOne.ToString();
	_vectorTwo.ToString();
	_vectorOne.Distance(_vectorTwo);
	_vectorOne.Dot(_vectorTwo);
	 return 0;
}

