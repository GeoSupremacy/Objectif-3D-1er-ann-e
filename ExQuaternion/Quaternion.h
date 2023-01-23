#pragma once
#include <string>

class Quaternion
{
private:
	float x = 0.0f;
	float y = 0.0f;
	float z = 0.0f;
	float w = 0.0f;
	float magnitude;
public:
	static float identity;
	
#pragma region Construct
public:
	Quaternion(float _x, float _y, float _z, float _w);
	Quaternion(Quaternion&  _copy);
#pragma endregion Construct
#pragma region  method
public:
	void Set(float _x, float _y, float _z, float _w);	            //Set x, y, z and w components of an existing Quaternion.
	void ToString();
	//SetFromToRotation	Creates a rotation which rotates from fromDirection to toDirection.
	//SetLookRotation	    Creates a rotation with the specified forwardand upwards directions.
	//ToAngleAxis	        Converts a rotation to angle - axis representation(angles in degrees).
	
		
#pragma endregion  method
#pragma region  Static Methods
public:
	 
	//	Angle			Returns the angle in degrees between two rotations a and b.
	//	AngleAxis		Creates a rotation which rotates angle degrees around axis.
	//	Dot				The dot product between two rotations.
	//	Euler			Returns a rotation that rotates z degrees around the z axis, x degrees around the x axis, and y degrees around the y axis; applied in that order.
	//	FromToRotation	Creates a rotation which rotates from fromDirection to toDirection.
						//Inverse	Returns the Inverse of rotation.
	//	Lerp			Interpolates between a and b by t and normalizes the result afterwards. The parameter t is clamped to the range [0, 1].
	//	LerpUnclamped	Interpolates between a and b by t and normalizes the result afterwards. The parameter t is not clamped.
	//	LookRotation	Creates a rotation with the specified forward and upwards directions.
		void Conjugate();
		void Normalize();		//Converts this quaternion to one with the same orientation but with a magnitude of 1.
		void Lenght();
		void LenghtSquared();
		float Dot(Quaternion _quat, Quaternion _quat1);
		void Angle(Quaternion _quat, Quaternion _quat1);
		void CreateTranslation();
	//	RotateTowards	Rotates a rotation from towards to.
	//	Slerp			Spherically interpolates between quaternions a and b by ratio t. The parameter t is clamped to the range [0, 1].
	//	SlerpUnclamped
	
#pragma endregion  Static Methods
#pragma region  Operators
#pragma endregion  Operators
};

