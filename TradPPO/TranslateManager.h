#pragma once
#include<map>
#include<string>

class Language;

class TranslateManager
{
private:
	std::map<std::string, Language*> languages = std::map<std::string, Language*>();


public:
	 TranslateManager();

	void InitLanguage();
	Language* GetLanguage(const std::string& _languageName);
    Language* AddLanguage(const std::string& _languageName);
	std::string GetMessage(const std::string& _languageName, const std::string& _key);



};

