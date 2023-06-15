#pragma once
#include <SFML/Graphics/Font.hpp>
#include "../Utils//Singleton/Singleton.h"

namespace Engine::Manager
{
class FontManager : public Utils::Singleton<FontManager>
{
	//Gestions des Polices
	DECLARE_CLASS_INFO(FontManager, Singleton<FontManager>)
#pragma region f/p
private:
	std::map<std::string, sf::Font*> fonts = std::map<std::string, sf::Font*>();
#pragma endregion f/p
#pragma region constructor
public:
	FontManager() = default;
#pragma endregion constructor
#pragma region method
public:
	void Init();
	void LoadFont(const char* _path);
	sf::Font* GetFont(const std::string& _fontName);
#pragma endregion method
#pragma region override
public:
	void OnDestroy() override;
#pragma endregion override

};
}

