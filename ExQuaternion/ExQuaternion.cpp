#include <iostream>
#include "Quaternion.h"
template <typename T>
void Display(std::string _description, const T&  _quaternion)
{
	std::cout << "================================" << std::endl;
	std::cout << _description << std::endl;
	std::cout << "{X:" << _quaternion.x << " Y:" << _quaternion << " Z:" << _quaternion << " W:" << _quaternion<< " }" << std::endl;
	std::cout << "================================" << std::endl;
}

int main()
{
	
    Quaternion quat = Quaternion(50, 25, 80, 125);
    Quaternion quat1 = Quaternion(80, 30, 25, 40);
	quat.Normalize();
	quat.Conjugate();
	quat.ToString();
	quat.Dot(quat, quat1);
	quat.Angle(quat, quat1);
	quat.Lenght();
	quat.LenghtSquared();
	
}


