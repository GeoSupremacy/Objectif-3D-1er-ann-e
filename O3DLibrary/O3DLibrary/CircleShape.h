#pragma once
#include "Shape.h"

namespace Core
{
	class CircleShape : public Shape
	{
#pragma region f/p
	private:
		float radius = 10.0f;
#pragma endregion f/p
#pragma region construc
	public:
		O3DLIBRARY_API CircleShape(Position& _position, const float _radius);
#pragma endregion construc
#pragma region override
	public:
		O3DLIBRARY_API void Draw(HDC _hdc) override;
#pragma endregion override
	};
}

