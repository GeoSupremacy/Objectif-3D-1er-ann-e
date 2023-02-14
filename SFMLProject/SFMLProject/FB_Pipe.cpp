#include "FB_Pipe.h"
#include "Time.h"
#include "FB_TextureManager.h"
#include "FB_GameObjectManager.h"


#pragma region constructor/destructor
FB_Pipe::FB_Pipe()
{
	sprite = new sf::Sprite();
	texture = new sf::Texture();
	if (texture->loadFromFile(""))
	{
		sprite->setTexture(*texture);
	}
	sprite->setTexture(*texture);
	sprite->scale(0.01f, 0.01f);
	//draw = sprite;
}
FB_Pipe::~FB_Pipe()
{
	delete sprite;
	sprite = nullptr;
	delete texture;
	texture = nullptr;
}
#pragma endregion constructor/destructor
#pragma region methods
void FB_Pipe::Rotate()
{
	sprite->rotate(180);
}
void FB_Pipe::Move()
{
	SetPosition(sprite->getPosition() - sf::Vector2f(1, 0) * SPEED_PIPE * Time::deltaTime);
	if (!passeBird && sprite->getPosition().x <= -0.5f)
	{
		OnBirdPosition.Invoke();
		passeBird = true;
	}
	if (sprite->getPosition().x < (0 - GetGlobalBounds().width))
		FB_GameObjectManager::Instance()->OnDestroy();
}
void FB_Pipe::SetPosition(const sf::Vector2f& _position)
{
	sprite->setPosition(_position);
}
#pragma endregion methods
#pragma region override
sf::FloatRect FB_Pipe::GetGlobalBounds() const
{
	return sprite->getGlobalBounds();
}
sf::Vector2f FB_Pipe::Position() const
{
	return sprite->getPosition();
}
void FB_Pipe::OnUpdate()
{
	Move();
}
#pragma endregion override

