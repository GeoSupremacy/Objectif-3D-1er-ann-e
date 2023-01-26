#pragma once

template<typename T>
class Mathf
{
public:
	static inline const float Pi = 3.1415926535897932384;
	static inline const float Deg2Rad = Pi * 2.0f / 360.f;
	static inline const float Rad2Deg - 1.0f/ Deg2Rad;
public:
	template<typename T>
	static T Clamp(const T& _current, const T& _mib,  const T& _max);
public:
	static float Clamp01(const float _value);
	static float Sqrt(const float _value);
	static float Min(const float _a, const float _b);
	static float Max(const float _a, const float _b);
	static float Abs(const float _value);
	static float Acos(const float _value);
	static float cos(const float _value);
	static float Sin(const float _value);
};


