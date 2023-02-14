#include "GameObject.h"
#include "FB_GameObjectManager.h"
#include "Window.h"


#pragma region constructor/destructor
GameObject::GameObject()
{
	FB_GameObjectManager::Instance()->Register(this);
}
GameObject::GameObject(const GameObject& _copy)
{
	drawable = _copy.drawable;
}
GameObject::~GameObject()
{
	
}
#pragma endregion constructor/destructor
#pragma region methods
void GameObject::OnUpdate() {}
void GameObject::OnDraw(Window* _window)
{
	_window->Draw(drawable);
}
void GameObject::OnCollisionEnter(GameObject* _other)
{
	_other->OnCollisionEnter(drawable);
}
#pragma endregion methods

