#include "Language.h"
#include "Path.h"
#include "Enviromnent.h"
#include "File.h"
#include "FileStream.h"
#include <vector>
#include "FileReader.h"
#include "FileWriter.h"
#include "StringUtile.h"

Language::Language(const std::string& _languageName)
{
	languageName = _languageName;
	filePath = Path::Combine(Enviromnent::CurrentDirectory(), "Language", _languageName + ".txt");
	stream = File::Create(filePath);
	InitMessage();
}
Language::~Language()
{
	stream->Close();
	delete stream;
	stream = nullptr;
}
void Language::InitMessage()
{
	if (!stream->IsValid()) return;
	const std::vector<std::string> _allLines = stream->Reader()->GetAllLines();
	for (int i = 0; i < _allLines.size(); i++)
	{
		const std::string _line = _allLines[i];
		std::string _key = _line.substr(0, _line.find_first_of(':'));
		if (allMessages.contains(_key)) continue;
		StringUtile::Replace(_key, " ", "");
		std::string _message = _line.substr(_line.find_first_of(':') + 1);
		allMessages.insert(std::pair(_key, _message));
	}
}

std::string Language::GetMessage(const std::string& _key) const
{
	if (!allMessages.contains(_key)) return "";
	return allMessages.at(_key);
}

void Language::AddMessageToFile(const std::string& _key, const std::string& _message)
{
	if (!stream->IsValid()) return;
	stream->Writer()->Write(_key + ": " + _message);
}
std::string Language::LanguageName() const
{
	return languageName;
}

std::string Language::FilePath() const
{
	return FilePath();
}