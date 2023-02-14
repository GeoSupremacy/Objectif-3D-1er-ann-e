#pragma once
#include "Singleton.h"
#include "GameObject.h"
#include <vector>


class FB_GameObjectManager :public Singleton<FB_GameObjectManager>
{
#pragma region f/p
private:
	std::vector<GameObject*>gameobjects = std::vector<GameObject*>();
	std::vector<GameObject*>objectsToDestroy = std::vector<GameObject*>();
#pragma endregion f/p
#pragma region constructor/destructor
public:
	FB_GameObjectManager() = default;
#pragma endregion constructor/destructor
#pragma region methods
public:
	void DestroyAllRequest();
	void DestroyAllObjects();
	void Register(GameObject* _gameObject);
	void UnRegister(GameObject* _gameObject);
	void Update();
	void Draw(class Window* _window);
	void CheckCollision();
#pragma endregion methods
#pragma region override
public:
	void OnDestroy() override;
#pragma endregion override
};

