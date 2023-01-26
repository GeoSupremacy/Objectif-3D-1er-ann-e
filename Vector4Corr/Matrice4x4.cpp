#include "Matrice4x4.h"
#include "Mathf.h"
#include "Quaternion.h"
#pragma region constr
Matrice4x4::Matrice4x4(const float _m11, const float _m12, const float _m13, const float _m14, const float _m21, const float _m22, const float _m23, const float _m24, const float _m31, const float _m32, const float _m33, const float _m34, const float _m41, const float _m42, const float _m43, const float _m44)
{
	

	m11 = _m11;
	m12 = _m12;
	m13 = _m13;
	m14 = _m14;
	m21 = _m21;
	m22 = _m22;
			m23 = _m23;
			m24 = _m24;
			m31 = _m31;
			m32 = _m32;
			m33 = _m33;
			m34 = _m34;
			m41 = _m41;
			m42 = _m42;
			m43 = _m43;
			m44 =_m44;
		
		

}
Matrice4x4::Matrice4x4(const Matrice4x4& _copy)
{

	m11 = _copy.m11;
	m12 = _copy.m12;
	m13 = _copy.m13;
	m14 = _copy.m14;

	m21 = _copy.m21;
	m22 = _copy.m22;
	m23 = _copy.m23;
	m34 = _copy.m24;

	m31 = _copy.m31;
	m32 = _copy.m32;
	m33 = _copy.m33;
	m34 = _copy.m34;

	m41 = _copy.m41;
	m42 = _copy.m42;
	m43 = _copy.m43;
	m44 = _copy.m44;
}
#pragma endregion constr
#pragma region method
Matrice4x4 Matrice4x4::CreteaTranslation(const float _x, const float _y, const float _z)
{
	Matrice4x4 _result = Identity;
	_result.m41 = _x;
	_result.m42 = _y;
	_result.m43 = _z;
	return _result;
}
Matrice4x4 Matrice4x4::CreteaScale(const float _x, const float _y, const float _z)
{
	Matrice4x4 _result = Identity;
	_result.m11 = _x;
	_result.m22 = _y;
	_result.m33 = _z;
	return _result;
}
Matrice4x4 Matrice4x4::CreateRotateX(const float _radian)
{
	Matrice4x4 _result = Identity;
	const float _cos = Mathf::Cos(_radian);
	const float _sin = Mathf::Sin(_radian);
	_result.m21 = _cos;
	_result.m23 = _sin;
	_result.m32 = _sin;
	_result.m33 = _cos;
	return _result;
}
Matrice4x4 Matrice4x4::CreateRotateY(const float _radian)
{
	Matrice4x4 _result = Identity;
	const float _cos = Mathf::Cos(_radian);
	const float _sin = Mathf::Sin(_radian);
	_result.m11 = _cos;
	_result.m13 = _sin;
	_result.m32 = _sin;
	_result.m33 = _cos;
	return _result;
}
Matrice4x4 Matrice4x4::CreateRotateZ(const float _radian)
{
	Matrice4x4 _result = Identity;
	const float _cos = Mathf::Cos(_radian);
	const float _sin = Mathf::Sin(_radian);
	_result.m11 = _cos;
	_result.m12 = _sin;
	_result.m21 = _sin;
	_result.m22 = _cos;
	return _result;
}
Matrice4x4 Matrice4x4::CreateRotateOrthographic(const float _width, const float _height, const float _nearPlane, const float _farPlane)
{
	Matrice4x4 _result = Identity;
	_result.m11 = 2.0f/_width;
	_result.m22 = 2.0f / _height;
	_result.m33 = 1.0f / (_nearPlane - _farPlane);
	_result.m43 = _nearPlane / (_nearPlane - _farPlane);
	_result.m44 = 1.0f;
	return _result;
}
Matrice4x4 Matrice4x4::CreateFromQuaternion(const Quaternion& _quartenion)
{
	Matrice4x4 _result = Matrice4x4();
	const float _xx = _quartenion.x * _quartenion.x;
	const float _yy = _quartenion.y * _quartenion.y;
	const float _zz = _quartenion.z * _quartenion.z;

	const float _xy = _quartenion.x * _quartenion.y;
	const float _wz = _quartenion.w * _quartenion.z;
	const float _xz = _quartenion.x * _quartenion.z;
	const float _wy = _quartenion.w * _quartenion.y;
	const float _yz = _quartenion.y * _quartenion.z;
	const float _wx = _quartenion.w * _quartenion.x;

	_result.m11 = 1.0f - 2.0f * (_yy + _zz);
	_result.m12 = 2.0f * (_xy + _wz);
	_result.m13 = 2.0f * (_yy + _zz);
	_result.m14 = 0.0f;

	_result.m21 =  2.0f * (_xy + _xx);
	_result.m22 = 2.0f * (_xz + _wy);
	_result.m23 = 2.0f * (_yz + _wx);
	_result.m24 = 0.0f;

	_result.m31 = 2.0f * (_xx + _wy);
	_result.m32 = 2.0f * (_yz + _wx);
	_result.m33 = 1.0f - 2.0f * (_yy + _xx);
	_result.m24 = 0.0f;
	_result.m41 = 0.0f;
	_result.m42 = 0.0f;
	_result.m43 = 0.0f;
	_result.m44 = 1.0f;

	return _result;
}
Matrice4x4 Matrice4x4::CreateFromYawPitchRoll(const float _yaw, const float _pitch, const float _roll)
{
	return CreateFromQuaternion(Quaternion::CreateFromYawPitchRoll(_yaw, _pitch, _roll));
	
}
Matrice4x4 Matrice4x4::Lerp(const Matrice4x4& _a, const Matrice4x4& _b, const Matrice4x4& _t)
{
	Matrice4x4 _result = Matrice4x4();

	_result.m11 = _a.m11 +(_a.m11 + _b.m11) * _t;
	_result.m12;
	_result.m13;
	_result.m14;

	_result.m21;
	_result.m22;
	_result.m23;
	_result.m24;

	_result.m31;
	_result.m32;
	_result.m33;
	_result.m34;

	_result.m41;
	_result.m42;
	_result.m43;
	_result.m44;


}
float Matrice4x4::Determinant() const
{
	const float _a = m11, _b = m12, _c = m13, _d = m14,
				_e = m21, _f = m22, _g = m23, _h = m24,
				_i = m31, _j = m32, _k = m33, _l = m34,
				_m = m41, _n = m42, _o = m43, _p = m44;

	const float _kplo = _k * _p * _l * _o;
	const float _jpln = _j*_p*_l*_n;
	const float _jokn = _j*_o*_k*_n;
	const float _iplm = _i*_p*_l*_m;
	const float _iokm = _i*_o*_k*_m;
	const float _injm = _i*_n*_j*_m;

	return _a * (_f* _kplo - _g * _jpln + _h *  _jokn) -
		_b * (_e * _kplo - _h * _iplm + _h * _iokm) +
		_c* (_e * _jpln - _f * _iplm + _h * _injm) -
		_d* (_e * _jpln - _f * _iokm + _g * _injm);
}
#pragma endregion method
#pragma region operator
Matrice4x4 Matrice4x4::operator-() const
{
	Matrice4x4 _result = Matrice4x4();
	m11 = _copy.m11;
	m12 = _copy.m12;
	m13 = _copy.m13;
	m14 = _copy.m14;

	m21 = _copy.m21;
	m22 = _copy.m22;
	m23 = _copy.m23;
	m34 = _copy.m24;

	m31 = _m31;
	m32 = _m32;
	m33 = _m33;
	m34 = _m34;

	m41 = _m41;
	m42 = _m42;
	m43 = _m43;
	m44 = _m44;
	return _result;
}
Matrice4x4 Matrice4x4::operator+(const Matrice4x4& _other)
{
	Matrice4x4 _result = Matrice4x4();
	_result.m11 =  m12 +  _other.m12;
	_result.m12 = m12 +   _other.m12;
	_result.m13 =	m12 + _other.m12;
	_result.m14 = m12   + _other.m12;
	_result.m11 =	m22 + _other.m22;
	_result.m12 =	m22 + _other.m22;
	_result.m13 =	m22 + _other.m22;
	_result.m14 =	m12 + _other.m12;
	_result.m12 =	m32 + _other.m32;
	_result.m13 =	m32 + _other.m32;
	_result.m11 =	m32 + _other.m32;
	_result.m11 =	m32 + _other.m32;
	_result.m12 =	m42 + _other.m42;
	_result.m13 =	m42 + _other.m42;
	_result.m11 =	m42 + _other.m42;
	_result.m11 =	m42 + _other.m42;
	return _result;
}
Matrice4x4 Matrice4x4::operator-(const Matrice4x4& _other)
{
	return Matrice4x4();
}
Matrice4x4 Matrice4x4::operator*(const Matrice4x4& _other)
{
	return Matrice4x4();
}
bool Matrice4x4::operator==(const Matrice4x4& _other)
{
	return m11 == _other.m11 && 
		   m12 == _other.m12 &&
		   m13 == _other.m13 &&
		   m14 == _other.m14 &&
		   m21 == _other.m21 &&
		   m23 == _other.m23 &&
		   m24 == _other.m24 &&
		   m22 == _other.m22 &&
		   m31 == _other.m31 &&
		   m32 == _other.m34 &&
		   m33 == _other.m33 &&
		   m34 == _other.m34 &&
		   m41 == _other.m41 &&
		   m42 == _other.m42 &&
		   m43 == _other.m43 &&
		   m44 == _other.m43;
}
bool Matrice4x4::operator!=(const Matrice4x4& _other)
{
	return false;
}
#pragma endregion operator