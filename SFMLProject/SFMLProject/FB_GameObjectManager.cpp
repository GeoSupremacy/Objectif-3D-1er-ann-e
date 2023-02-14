#include "FB_GameObjectManager.h"


#pragma region methods
void FB_GameObjectManager::DestroyAllRequest()
{
	for (GameObject* _object : objectsToDestroy)
	{
		std::erase(objectsToDestroy, _object);
		std::erase(gameobjects, _object);
		delete _object;
		_object = nullptr;
	}
	objectsToDestroy.clear();
	
}
void FB_GameObjectManager::DestroyAllObjects()
{
	for (GameObject* _object : gameobjects)
	{
		std::erase(gameobjects, _object);
		delete _object;
		_object = nullptr;
	}
	objectsToDestroy.clear();
	gameobjects.clear();
}
void FB_GameObjectManager::Register(GameObject* _gameObject)
{
	gameobjects.push_back(_gameObject);
}
void FB_GameObjectManager::UnRegister(GameObject* _gameObject)
{
	const size_t _size = gameobjects.size();
	for (size_t i = 0; i < _size; i++)
	{
		if (gameobjects[i] == _gameObject)
		{
			gameobjects.erase(gameobjects.begin() +1);
			break;
		}
	}
}
void FB_GameObjectManager::Update()
{
	const size_t _size = gameobjects.size();
	for (size_t i = 0; i < _size; i++)
	{
		gameobjects[i]->OnUpdate();
		
	}
}
void FB_GameObjectManager::Draw(Window* _window)
{
	const size_t _size = gameobjects.size();
	for (size_t i = 0; i < _size; i++)
		gameobjects[i]->OnDraw(_window);

}
void FB_GameObjectManager::CheckCollision()
{
	for (GameObject* _a : gameobjects)
	{
		for (GameObject* _b : gameobjects)
		{
			if (_a == _b || !_a->GetGlobalBounds().contains(_b->Position())) continue;
			_b->OnCollisionEnter(_a);
		}
	}
}
#pragma endregion methods
#pragma region override
void FB_GameObjectManager::OnDestroy()
{
	const size_t _size = gameobjects.size();
	for (size_t i = 0; i < _size; i++)
		delete gameobjects[i];
	gameobjects.clear();
	
}
#pragma endregion override