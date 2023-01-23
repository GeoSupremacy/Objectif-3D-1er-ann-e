#include <iostream>
#include "Matrix4x4.h"
template <typename T>
void Display(const T& _obj)
{
	std::cout << "==============================" << std::endl;
	
	std::cout << "{ {M11:" << _obj.m11 << " M12:" << _obj.m12 << "M13:" << _obj.m13 << "M14:" << _obj.m14 
			  <<"} {M21:" << _obj.m21 << " M22:" << _obj.m22 << "M23:" << _obj.m23 << "M24:" << _obj.m24 
			  << "} {M31:" << _obj.m31 << " M32:" << _obj.m32 << "M33:" << _obj.m33 << "M34:" << _obj.m34 
			  << "} {M41:" << _obj.m41 << " M42:" << _obj.m42 << "M43:" << _obj.m43 << "M44:" << _obj.m44 << "} }" << std::endl;
	std::cout << "==============================" << std::endl;
}
int main()
{
	Matrix4x4 mat4x4 = Matrix4x4(1,0,0,0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1);
	mat4x4.CreateTranslation(10,25,45);
	mat4x4.Identity();
}

