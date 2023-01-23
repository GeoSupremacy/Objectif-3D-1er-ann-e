#include "Matrix4x4.h"
#include <iostream>
Matrix4x4::Matrix4x4(float _m11, float _m12, float _m13, float _m14,
					 float _m21, float _m22, float _m23, float _m24,
					 float _m31, float _m32, float _m33, float _m34,
					 float _m41, float _m42, float _m43, float _m44)
{
	    m11=_m11, m12=_m12, m13=_m13, m14=_m14,
		m21=_m21,m22=_m22,m23=_m23, m24=_m24,
		m31=_m31,m32=_m32, m33=_m33, m34=_m34,
		m41=_m41, m42=_m42, m43=_m43, m44=_m44;

		identity.m11 = 1, identity.m12 = 0, identity.m13 = 0, identity.m14 = 0,
		identity.m21 = 0, identity.m22 = 1, identity.m23 = 0, identity.m24 = 0,
		identity.m31 = 0, identity.m32 = 0,identity.m33 = 1, identity.m34 = 0,
		identity.m41 = 0, identity.m42 = 0, identity.m43 = 0, identity.m44 = 1;
		
}


void Matrix4x4::Identity() const
{
	std::cout << "{ {M11:" << identity.m11 << " M12:" << identity.m12 << "M13:" << identity.m13 << "M14:" << identity.m14
		<< "} {M21:" << identity.m21 << " M22:" << identity.m22 << "M23:" << identity.m23 << "M24:" << identity.m24
		<< "} {M31:" << identity.m31 << " M32:" << identity.m32 << "M33:" << identity.m33 << "M34:" << identity.m34
		<< "} {M41:" << identity.m41 << " M42:" << identity.m42 << "M43:" << identity.m43 << "M44:" << identity.m44 << "} }" << std::endl;
}

void Matrix4x4::CreateIdentity()
{
}

void Matrix4x4::CreateTranslation(float _xPosition, float _yPosition, float _zPosition)
{
		    m11 = m11*identity.m11, m12 = m12* identity.m11, m13 = m13* identity.m11, m14 = m14*identity.m11,
			m21 = m21*identity.m11, m22 = m22*identity.m11, m23 = m23*identity.m11, m24 = m24*identity.m11,
			m31 = m31* identity.m11, m32 = m32*identity.m11, m33 = m33*identity.m11, m34 = m34*identity.m11,
			m41 = m41* _xPosition, m42 = m42* _yPosition, m43 = m43* _zPosition, m44 = m44* identity.m11;
	
}
 

#pragma region operator
bool Matrix4x4::operator==(const Matrix4x4& _other) const
{
	return false;
}
bool Matrix4x4::isIdentity(Matrix4x4& _identity)
{

	return false;
}
#pragma endregion operator
