#pragma once
#include "Singleton.h"
#include <SFML/Graphics.hpp>
#include <map>

class FB_TextureManager :public Singleton<FB_TextureManager>
{
#pragma region f/p
private:
	//std::map<const char* 
#pragma endregion f/p
#pragma region constructor/destructor
public:

#pragma endregion constructor/destructor
#pragma region methods
public:
	sf::Texture* Get(const char* _path);
#pragma endregion methods
#pragma region override
public:
	void OnDestroy() override;
#pragma endregion override
};

