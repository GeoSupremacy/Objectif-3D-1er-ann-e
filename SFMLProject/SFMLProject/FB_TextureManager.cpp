#include "FB_TextureManager.h"
#include <format>

#pragma region constructor/destructor

#pragma endregion constructor/destructor
#pragma region methods
sf::Texture* FB_TextureManager::Get(const char* _path)
{
	if (!textures.contains(_path))
	{
		sf::Texture* _texture = new sf::Texture();
		if (!_texture->loadFromFile(_path))
			throw std::exception(std::format("[Texture Manager] => can't load texture at path : {}", _path.c_str())
				return _texture;
	}
	return textures[_path];
	
}

#pragma endregion methods
#pragma region override
void FB_TextureManager::OnDestroy()
{
	for (size_t i = 0; i < length; i++)
	{
		delete _pair.scecond;
	}

}

#pragma endregion override

