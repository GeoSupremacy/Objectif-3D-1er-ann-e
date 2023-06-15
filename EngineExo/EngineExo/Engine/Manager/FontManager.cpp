#include "FontManager.h"
#include "../Utils/DebugMacro.h"
#include <filesystem>
#include <ranges>


namespace fs = std::filesystem;

#pragma region method
Engine::Manager::FontManager::FontManager(const FontManager& _copy) : super (_copy)
{
    fonts = _copy.fonts;
}
void Engine::Manager::FontManager::Init()
{
    LoadFont("../Fonts");
}
void Engine::Manager::FontManager::LoadFont(const char* _path)
{
    for (const fs::directory_entry& _entry : fs::recursive_directory_iterator(_path))
    {
        if (!_entry.is_regular_file()) continue;
        const fs::path _filePath = _entry.path();
        if (_filePath.extension() != ".ttf" && _filePath.extension() != ".otf") continue;
        sf::Font* _font = new sf::Font();
        if (!_font->loadFromFile(_entry.path().string()))
        {
            LOG_ERROR(_filePath.string() + "can't load font [FontManager]!")
            continue;
        }
        PrimaryType::String _name = _filePath.string().c_str();
        _name = _name.Replace('\\', '/');
        _name = _name.SubString(_name.FindLastOf('/') + 1);
        _name = _name.SubString(0, _name.FindFirstOf('.')).Trim();
        fonts.insert(std::pair<std::string, sf::Font*>(_name.ToCstr(), _font));
    }
}
sf::Font* Engine::Manager::FontManager::GetFont(const std::string& _fontName) 
{
    check((fonts.contains(_fontName)), _fontName +" doesn't exit ! [FontManager]", nullptr)
    return fonts[_fontName];
}
#pragma endregion method
#pragma region override
void Engine::Manager::FontManager::OnDestroy()
{
    for (sf::Font*& _font : fonts | std::ranges::views::values)
    {
        delete _font;
        _font = nullptr;
    }
    fonts.clear();
}
#pragma endregion override
