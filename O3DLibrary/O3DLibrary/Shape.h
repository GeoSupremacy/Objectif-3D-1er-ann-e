#pragma once
#include "Object.h"
#include <Windows.h>
#include <gdiplus.h>
//

namespace Core
{
	struct Position
	{
		float x = 0;
		float y = 0;
	};
	struct Style
	{
		Gdiplus::Color backgroundColor = Gdiplus::Color::White;
	};

	class Shape : public Object
	{
#pragma region f/p
	protected:
		Gdiplus::Pen* pen = nullptr;
		Gdiplus::Graphics* graphics = nullptr;
		Style style = Style();
		Position position = Position();
#pragma endregion f/p
#pragma region construction/destruction
	public:
		O3DLIBRARY_API Shape() = default;
		O3DLIBRARY_API Shape(Position _position);
		O3DLIBRARY_API Shape(const Shape&) = default;
		O3DLIBRARY_API ~Shape();
#pragma endregion construction/destruction
#pragma region method
	public:
		O3DLIBRARY_API Style& GetStyle();
		O3DLIBRARY_API Position& GetPosition();
		O3DLIBRARY_API bool IsValid() const;
		O3DLIBRARY_API void Init(HDC _hdc);
		O3DLIBRARY_API virtual void Draw(HDC _hdc);
#pragma endregion method
	};
}

