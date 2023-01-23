#include "Vector4.h"
#include <cmath>

#pragma region Constructor/Destructor 
Vector4::Vector4(float _X, float _Y, float _W, float _Z)
{
	X = _X;
	Y = _Y;
	W = _W;
	Z = _Z;
}
#pragma endregion Constructor/Destructor 
#pragma region Methods 
void Vector4::SetVector(float _X, float _Y, float _W, float _Z)
{
	X = _X;
	Y = _Y;
	W = _W;
	Z = _Z;
	magnitude = sqrt((X * X) + (Y * Y) + (Z * Z) + (W * W));
}
bool Vector4::Equals(Vector4 _firstVector)
{
	if (_firstVector.X == X && _firstVector.Y == Y && _firstVector.Z == Z && _firstVector.W == W)
		return true;
	return false;
}
void Vector4::ToString()
{
	
	std::cout << "X: " << X << " Y: " << Y << " Z: " << Z << " W: " << W << std::endl;

}
#pragma endregion Methods
#pragma region Static Methods
 void Vector4::Distance(Vector4 _a)
{
	float _X =X - _a.X;
	float _Y = Y - _a.Y;
	float _W = W - _a.W;
	float _Z = Z - _a.Z;
	float _magnitude = sqrt((_X*_X)+(_Y * _Y)+(_W * _W)+(_Z * _Z));
	 std::cout<< "The distance is " << _magnitude <<std::endl;
}
 float Vector4::Normalize()
{
	 X = X / sqrt( pow(X,2)  + pow(Y, 2) + pow(Z, 2) + pow(W, 2) );
	 Y = Y / sqrt( pow(X, 2) + pow(Y, 2) + pow(Z, 2) + pow(W, 2) );
	 W = W / sqrt( pow(X, 2) + pow(Y, 2) + pow(Z, 2) + pow(W, 2) );
	 Z = Z / sqrt( pow(X, 2) + pow(Y, 2) + pow(Z, 2) + pow(W, 2) );
	 return X, Y, W, Z;
}
 void Vector4::Dot(Vector4 _a)
 {
	 float _X = X * _a.X;
	 float _Y = X * _a.X;
	 float _Z = X * _a.X;
	 float _W = X * _a.X;


	 std::cout << _X+ _Y + _Z + _W << std::endl;
 }
#pragma endregion Static Methods

