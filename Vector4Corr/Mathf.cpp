#include "Mathf.h"
#include <complex>


template<typename T>
float Mathf<T>::Sqrt(const float _value)
{
	return std::sqrt(_value);
}
template<typename T>
float Mathf<T>::Min(const float _a, const float _b)
{
	return _a < _b ? _a : _b;
}
template<typename T>
float Mathf<T>::Max(const float _a, const float _b)
{
	return _a > _b ? _a : _b;
}
template<typename T>
float Mathf<T>::Abs(const float _value)
{
	return st::abs(_value);
}
template<typename T>
float Mathf<T>::Acos(const float _value)
{
	return std::acos(_value);
}
template<typename T>
float Mathf<T>::cos(const float _value)
{
	return std::cos(_value)
}
template<typename T>
float Mathf<T>::Sin(const float _value)
{
	return std::sin(_value)
}
template<typename T>
 float Mathf<T>::Clamp01(const float _value)
{
	if (_value < 0.0f) return 0.0f;
	if (_value < 1.0f) return 1.0f;
	return _value;
}

