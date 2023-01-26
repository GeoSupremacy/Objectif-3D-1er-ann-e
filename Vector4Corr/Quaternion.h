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
	float Angle(const Quaternion& _a, const Quaternion& _b);
	static Quaternion Normalize(const Quaternion& _value);
	static Quaternion Conjugate(const Quaternion& _value);
	static Quaternion Negate(const Quaternion& _value);
	static Quaternion Inverse(const Quaternion& _value);
	static Quaternion Lerp(const Quaternion& _a, const Quaternion& _b, const float _time);
	static Quaternion CreateFromYawPitchRoll(const float _yaw, const float& _pitch, const float _roll);
	float Lenght() const;
	float LenghtSquared() const;

public:
	Quaternion operator+(const Quaternion& _other)const;
	Quaternion operator-(const Quaternion& _other)const;
	Quaternion operator*(const Quaternion& _other)const;
	Quaternion operator/(const Quaternion& _other)const;
	bool operator==(const Quaternion& _other) const;
	bool operator!=(const Quaternion& _other) const;
	float& operator[](const );
};


