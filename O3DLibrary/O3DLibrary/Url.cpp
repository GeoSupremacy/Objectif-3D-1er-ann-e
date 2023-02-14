#include "Url.h"

#pragma region constructor/destructor
Core::Net::Url::Url(PrimitiveType::FString& _path)
{
	path = _path;
}
Core::Net::Url::Url(const Url& _copy)
{
	path = _copy.path;
}
#pragma endregion constructor/destructor
#pragma region methods

#pragma endregion methods
#pragma region override
Core::PrimitiveType::FString Core::Net::Url::ToString() const
{
	return PrimitiveType::FString::Format("Path");
}
Core::PrimitiveType::FString Core::Net::Url::Path() const
{
	return path;
}
int Core::Net::Url::GetHashCode() const
{
	return path.GetHashCode();
}
#pragma endregion override
#pragma region operator
Core::Net::Url::operator LPCWSTR() const
{
	const std::wstring _path = path.ToWString();
	return _path.c_str();
}
#pragma endregion operator

