#pragma once
class Quaternion
{
public:
	static inline const float epsilon = 0.0001f;
	float x = 0.0f;
	float y = 0.0f;
	float z = 0.0f;
	float w = 0.0f;
	static const Quaternion Identity;

public:
	Quaternion(const float _x, const float _y, const float _z, const float _w);
	Quaternion(const Quaternion& _copy);
private:
	static bool IsEqualUsingDot(const float _dot);
public:
	float Dot(const Quaternion& _a, const Quaternion& _b);

};

