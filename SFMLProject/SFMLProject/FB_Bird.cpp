#include "FB_Bird.h"
#include "Mathf.h"
#include "Time.h"


#pragma region constructor/destructor
FB_Bird::FB_Bird()
{
	 sprite = new sf::Sprite();
	 texture = new sf::Texture();
	 if (texture->loadFromFile(""))
	 {
		 sprite->setTexture(*texture);
	 }
	 sprite->setOrigin(sf::Vector2f(0, 0));
	 sprite->setScale(sf::Vector2f(BIRD_SCALE, BIRD_SCALE));
	 drawable = sprite;
}
FB_Bird::~FB_Bird()
{
	Die();
}
#pragma endregion constructor/destructor
#pragma region override
void FB_Bird::Die()
{
	if (isDead) return;
	isDead = true;
	OnDie.Invoke();
}
void FB_Bird::OnUpdate()
{
	sprite->setPosition(Mathf::Lerp(sprite->getPosition(), sprite->getPosition() + 
		sf::Vector2f(0, GRAVITY), BIRD_SPEED_GRAVITY * Time::deltaTime));
}
void FB_Bird::OnCollissionEnter(GameObject* _other)
{
	if (isDead) return;
	isDead = true;
	Ondie.Invoke();
}
sf::FloatRect FB_Bird::GetGlobalBounds() const
{
	return sprite->getGlobalBounds();
}
sf::Vector2f FB_Bird::Position() const
{
	return sprite->getPosition();
}
#pragma endregion override
