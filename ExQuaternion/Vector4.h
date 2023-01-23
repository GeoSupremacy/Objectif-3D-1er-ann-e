#pragma once
#include "Mathf.h"


#define Epsilon 0.00001f;

class Vector4
{
#pragma region f/p
private:
	float x = 0.0f;
	float y = 0.0f;
	float z = 0.0f;
	float w = 0.0f;

public:
	static const Vector4 Zero;
	static const Vector4 One;
	const float magnitude = Magnitude(*this);
#pragma region f/p
public:
#pragma region constructor
	Vector4(const float _value);
	Vector4(const float _x, const float _y, const float _z, const float _w);
	Vector4(const float _x, const float _y, const float _z);
	Vector4(const float _x, const float _y);
	Vector4(const Vector4& _copy);
#pragma region constructor
#pragma region methods
public:
	/// <summary>
	/// Return a vector that is made from the absolute component
	/// </summary>
	/// <param name="_a">vector</param>
	/// <returns>Vector4</returns>
	static Vector4 Abs(const Vector4& _value);
	/// <summary>
	/// Return a vector that is made from the smallest components of two vectors
	/// </summary>
	/// <param name="_a">vector</param>
	/// <param name="_b">vector</param>
	/// <param name="_t">vector</param>
	/// <returns>Vector4</returns>
	static Vector4 Min(const Vector4& _a, const Vector4& _b);
	/// <summary>
	/// Return a vector that is made from the larget comonents of two vectors
	/// </summary>
	/// <param name="_a">vector</param>
	/// <param name="_b">vector</param>
	/// <param name="_t">vector</param>
	/// <returns>Vector4</returns>
	static Vector4 Max(const Vector4& _a, const Vector4& _b);
	/// <summary>
	/// Return a vector that is made from the larget comonents of two vectors
	/// </summary>
	/// <param name="_a">vector</param>
	/// <param name="_b">vector</param>
	/// <param name="_t">vector</param>
	/// <returns>Vector4</returns>
	static Vector4 Lerp(const Vector4& _a, const Vector4& _b, const float _t);
	/// <summary>
	/// <summary>
	/// </summary>
	/// <param name="_a"></param>
	/// <param name="_b"></param>
	/// <param name="_t"></param>
	/// <returns></returns>
	static Vector4 LerpUnclamped(const Vector4& _a, const Vector4& _b, const float _t);
	/// <summary>
	/// Dot product of two vectors
	/// </summary>
	/// <param name="_a"></param>
	/// <param name="_b"></param>
	/// <returns>Vector4</returns>
	static float Dot(const Vector4& _a, const Vector4& _b);
	/// <summary>
	/// returns the lenght of vector
	/// </summary>
	/// <param name="_a"></param>
	/// <param name="_b"></param>
	/// <returns>Vector4</returns>
	static float Magnitude(const Vector4& _value);
	/// <summary>
	/// returns the distance betwweend a and b
	/// </summary>
	/// <param name="_a"></param>
	/// <param name="_b"></param>
	/// <returns>Vector4</returns>
	static float Distance(const Vector4& _a, const Vector4& _b);
	/// <summary>
	/// returns the lenght betwweend a and b
	/// </summary>
	/// <param name="_a"></param>
	/// <param name="_b"></param>
	/// <returns>Vector4</returns>
	float Lenght() const;
	/// <summary>
	/// returns the distance betwweend a and b
	/// </summary>
	/// <param name="_a"></param>
	/// <param name="_b"></param>
	/// <returns>Vector4</returns>
	float LenghtSquared() const;
	/// <summary>
	/// returns the distance betwweend a and b
	/// </summary>
	/// <param name="_a"></param>
	/// <param name="_b"></param>
	/// <returns>Vector4</returns>
	void Set(const float _x, const float _y, const float _z, const float _w);
	void Normalize();
#pragma endregion methods
#pragma region operator
public:
	float& operator[](const int _index);
	bool operator>(const Vector4& _other);
	bool operator>=(const Vector4& _other);
	bool operator<(const Vector4& _other);
	bool operator<=(const Vector4& _other);
	Vector4 operator+(const Vector4& _other) const;
	Vector4 operator+=(const Vector4& _other);
	Vector4 operator-(const Vector4& _other)const;
	Vector4 operator-=(const Vector4& _other);
	Vector4 operator*(const Vector4& _other)const;
	Vector4 operator*=(const Vector4& _other);
	Vector4 operator/(const Vector4& _other)const;
	Vector4 operator/=(const Vector4& _other);
	bool operator ==(const Vector4& _other) const;
	bool operator !=(const Vector4& _other) const;
	//Vector4 operator-() const;
	Vector4 operator=(const Vector4& _other);
	operator const char* () const;
#pragma endregion operator
};



