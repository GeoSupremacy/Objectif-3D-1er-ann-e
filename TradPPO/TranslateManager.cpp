#include "TranslateManager.h"
#include "Utile.h"
#include "Enviromnent.h"
#include "Path.h"
#include "Directory.h"
#include <filesystem>
#include "Language.h"

TranslateManager::TranslateManager()
{
	InitLanguage();
}


void TranslateManager::InitLanguage()
{
	const::std::string& _path = Path::Combine(Enviromnent::CurrentDirectory(), "Language");
	if (!Directory::Exist(_path)) return;
	for (const std::filesystem::directory_entry& entry :std::filesystem::directory_iterator(_path.c_str()))
	{
		if (entry.is_directory()) continue;
		std::string _filePath = Path::GetPath( entry.path().string());
		std::string _fileName = _filePath.substr(_filePath.find_first_of('/') + 1);
		_fileName = _fileName.substr(0, _fileName.find_first_of('.'));
		languages.insert(std::pair(_fileName, new Language(_fileName)));
	}
}

Language* TranslateManager::GetLanguage(const std::string& _languageName)
{
	if (!languages.contains(_languageName)) return nullptr;
	return languages[_languageName];
}

Language* TranslateManager::AddLanguage(const std::string& _languageName)
{
	if (languages.contains(_languageName)) return languages[_languageName];
	Language* _newLanguage = new Language(_languageName);
	languages.insert(std::pair(_languageName, _newLanguage));
}

std::string TranslateManager::GetMessage(const std::string& _languageName, const std::string& _key)
{
	Language* _language = GetLanguage(_languageName);
	if (_language == nullptr) return "";
	return _language->GetMessage(_key);
}

