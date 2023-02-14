#include "CircleShape.h"

#pragma region construc
Core::CircleShape::CircleShape(Position& _position, const float _radius) : Shape(_position)
{
	radius = _radius;
}
#pragma endregion construc
#pragma region override
void Core::CircleShape::Draw(HDC _hdc)
{
	Shape::Draw(_hdc);
	if (!IsValid())return;
	Gdiplus::Rect _rect = Gdiplus::Rect(position.x, position.y, radius, radius);
	graphics->FillEllipse(new Gdiplus::SolidBrush(style.backgroundColor), _rect);
}
#pragma endregion override
