#include<string>
#include<map>

class FileStream;
class Language
{
private:
	std:: string languageName
		FileStream* stream = nullptr;

public:
	Language() = default;
	Language(const std::string& _language);
	void InitMessage();
	std::string GetMessage(const std::string& _key) const;
	std::string Language::GetMessge(const std::string& _key) const
	{
		if (!allMessage.contain(_key)) return
	}
};

