#pragma once
//CreaterTranslation(x,y,z)
//CreateScule(x,y,z)
//CreateRotationX(radians)
//CreateRotationY(radians)
//CreateRotationZ(radians)
//CreateOrthographic(width, height, nearPlane, farPlane))
//CreateFromQuatenion
//Lerp
//GetDeterminant()
//operator *,+,-,-negation,[]

class Matrix4x4
{
public:
	float m11, m12, m13, m14,
		m21, m22, m23, m24,
		m31, m32, m33, m34,
		m41, m42, m43, m44;
	 static  Matrix4x4 identity;
	bool isIdentity(Matrix4x4&_identity);
public:
	Matrix4x4(float _m11, float _m12, float _m13, float _m14,
			  float _m21, float _m22, float _m23, float _m24, 
			  float _m31, float _m32, float _m33, float _m34, 
			  float _m41, float _m42, float _m43, float _m44);
	
	void Identity() const;
	 void CreateTranslation(float _xPosition, float _yPosition, float _zPosition);
	 static void CreateIdentity();
public:
	bool operator==(const Matrix4x4& other) const;
};

