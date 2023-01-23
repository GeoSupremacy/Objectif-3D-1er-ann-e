#pragma once
#include <iostream>
#include <string>

class Vector4
{
private:
	float W, X, Y, Z;

	float magnitude;
	int acc[4];
#pragma region Constructor/Destructor 
public:
	 Vector4(float _X, float _Y, float _W, float _Z);
#pragma endregion Constructor/Destructor 
#pragma region Methods
public:
	void ToString();
	void SetVector(float _X, float _Y, float _W, float _Z);
	bool Equals(Vector4 _firstVector);
#pragma endregion Methods
#pragma region Static Methods
	 void Distance(Vector4 _a);
	 void Dot(Vector4 _a);
	 float Normalize();
#pragma endregion Static Methods
#pragma region Operators
	
#pragma endregion Operators
};


