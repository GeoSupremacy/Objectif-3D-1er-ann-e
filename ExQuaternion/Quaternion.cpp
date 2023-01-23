#include "Quaternion.h"
#include "Mathf.h"
#include <iostream>
#include <cmath>
#include <complex>

#pragma region Construct
Quaternion::Quaternion(float _x, float _y, float _z, float _w)
{
	x = _x;
	y = _y;
	z = _z;
	w = _w;

	magnitude = sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2) + pow(w, 2));
}
Quaternion::Quaternion(Quaternion& _copy)
{
	x = _copy.x;
	y = _copy.y;
	z = _copy.z;
	w = _copy.w;

	magnitude = _copy.magnitude;
}
#pragma endregion Construct
#pragma region method
void Quaternion::Set(float _x, float _y, float _z, float _w)
{
	x = _x;
	y = _y;
	z = _z;
	w = _w;
}
void Quaternion::ToString()
{
	std::cout <<"X: "<<x << " Y: " << y << " Z: " << z << " W: " << w<<std::endl;
}
void Quaternion::Conjugate()
{
	
	//50, 25, 80, 125 || 0,315283 Y: 0.166114 Z : 0.539052 W : 0.999987
}
void Quaternion::Normalize()
{
	float _X =  x / sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2) + pow(w, 2));
	float _Y = y / sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2) + pow(w, 2));
	float _Z = z / sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2) + pow(w, 2));
	float _W =  w / sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2) + pow(w, 2));
	
	
}
void Quaternion::Lenght()
{
	std::cout << "Lenght: " << magnitude<<std::endl;
}
void Quaternion::LenghtSquared()
{
	std::cout << "LenghtSquared: " << pow(magnitude, 2) << std::endl;
}
float Quaternion::Dot(Quaternion _quat, Quaternion _quat1)
{
	float _X = _quat.x * _quat1.x;
	float _Y = _quat.y * _quat1.y;
	float _Z = _quat.z * _quat1.z;
	float _W = _quat.w * _quat1.w;


	std::cout <<"Dot: "<< _X + _Y + _Z + _W << std::endl;
	return _X + _Y + _Z + _W;
}

void Quaternion::Angle(Quaternion _quat, Quaternion _quat1)
{
	float _dot =  Dot(_quat,  _quat1);
	 
	std::cout << "Angle: " << _dot / (_quat.magnitude * _quat1.magnitude) << std::endl;
}

void Quaternion::CreateTranslation()
{
	
}

#pragma endregion method